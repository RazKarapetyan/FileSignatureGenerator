#include "FileSignatureGenerator.hpp"

namespace app {
    
FileSignatureGenerator::FileSignatureGenerator(const std::string& inputFilePath,
                                               const std::string& outputFilePath,
                                               unsigned int blockSize) 
                                               : _inputFilePath(inputFilePath),
                                                 _outputFilePath(outputFilePath), 
                                                 _blockSize(blockSize) {}

void FileSignatureGenerator::generate() {
    (void)_blockSize;
}

}; // namespace app
