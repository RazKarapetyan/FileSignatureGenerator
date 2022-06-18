#include "stdafx.hpp"

#include "FileSignatureGenerator.hpp"

#include "exception/InvalidBlockSizeException.hpp"
#include "exception/BadFileException.hpp"

#include "fileUtils/FileUtils.hpp"

#include "hash/CrcHash.hpp"

namespace app {
    
FileSignatureGenerator::FileSignatureGenerator(const std::string& inputFilePath,
                                               const std::string& outputFilePath,
                                               app::SizeInMBytes blockSizeInMb) 
                                               : _inputStream(),
                                                 _inputFilePath(inputFilePath),
                                                 _outputStream(outputFilePath),
                                                 _blockSizeInMb(blockSizeInMb),
                                                 _hash(std::make_shared<hash::CrcHash>()) {

  if(!boost::filesystem::exists(inputFilePath)) {
    throw exception::BadFileException("File with name: " + inputFilePath + " does not exist");
  }

  if(!boost::filesystem::exists(outputFilePath)) {
    throw exception::BadFileException("File with name: " + outputFilePath + " does not exist");
  }

  _inputStream.open(inputFilePath);
}

FileSignatureGenerator::~FileSignatureGenerator() {
  _inputStream.close();
  _outputStream.close();
}

void FileSignatureGenerator::generate() noexcept(false) {
    app::SizeInMBytes inputFileSizeInMBytes = fileUtils::FileUtils::getFileSizeInMBytes(_inputFilePath);
    if(inputFileSizeInMBytes < _blockSizeInMb) {
      throw exception::InvalidBlockSizeException {"Input file size is less then specified block size!!!"};
    }

    generateHelper();
}

void FileSignatureGenerator::generateHelper() {
    auto fileSizeInBytes =  fileUtils::FileUtils::getFileSizeInBytes(_inputFilePath);
    auto chunkSizeInBytes = _blockSizeInMb * 1024 * 1024;

    // start reading the chunks with specified block size
    while(fileSizeInBytes > chunkSizeInBytes) {
      StringPtr chunk = std::make_shared<std::string>(chunkSizeInBytes, '\0');
      _inputStream.read(chunk->data(), chunkSizeInBytes);
      std::async(std::launch::async, 
         [chunk, this]() {
          hashAndWrite(chunk);}
      );
      fileSizeInBytes -= chunkSizeInBytes;
    }

    // If the file size is not a multiple of the block size,
    // we must populate also the last fragment
    if(fileSizeInBytes > 0) {
      StringPtr lastChunk = std::make_shared<std::string>(fileSizeInBytes, '\0');
      _inputStream.read(lastChunk->data(), fileSizeInBytes);
      std::async(std::launch::async, 
         [lastChunk, this]() {
          hashAndWrite(lastChunk);}
      );
    }
}

void FileSignatureGenerator::hashAndWrite(app::StringPtr chunk) {
    auto hashValue = _hash->hash(chunk);
    std::lock_guard<std::mutex> lock(_outStreamLock);
    _outputStream << hashValue;
}


}; // namespace app
