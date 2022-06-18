#include "stdafx.hpp"

#include "FileSignatureGenerator.hpp"

#include "exception/InvalidBlockSizeException.hpp"

#include "fileUtils/FileUtils.hpp"

#include "hash/CrcHash.hpp"

namespace app {
    
FileSignatureGenerator::FileSignatureGenerator(const std::string& inputFilePath,
                                               const std::string& outputFilePath,
                                               app::SizeInMBytes blockSizeInMb) 
                                               : _inputFilePath(inputFilePath),
                                                 _outputFilePath(outputFilePath), 
                                                 _blockSizeInMb(blockSizeInMb),
                                                 _hash(std::make_shared<hash::CrcHash>()) {}

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
    boost::filesystem::ifstream file;
    file.open(_inputFilePath);
    while(fileSizeInBytes > chunkSizeInBytes) {
      StringPtr chunk = std::make_shared<std::string>();
      chunk->resize(chunkSizeInBytes, '\0');
      file.read(chunk->data(), chunkSizeInBytes); 
      fileSizeInBytes -= chunkSizeInBytes;
      auto hashValue = _hash->hash(chunk);
      (void)hashValue;
    }

    // If the file size is not a multiple of the block size,
    // we must populate also the last fragment
    if(fileSizeInBytes > 0) {
      StringPtr lastChunk = std::make_shared<std::string>();
      lastChunk->resize(fileSizeInBytes, '\0');
      file.read(lastChunk->data(), fileSizeInBytes); 
      auto hashValue = _hash->hash(lastChunk);
      (void)hashValue;
    }
}

}; // namespace app
