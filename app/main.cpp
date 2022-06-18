#include "stdafx.hpp"

#include "FileSignatureGenerator.hpp"

#include "commandLineUtils/CommandLineUtils.hpp"

int main(int argc, const char* argv[]){

    auto [ inputFilePath, outputFilePath, blockSize ] = commandLineUtils::CommandLineUtils::parse(argc, argv);
    if(inputFilePath.empty() || outputFilePath.empty()) {
        std::cerr << "One of the file paths is empty!" << std::endl;
        return -1;
    }
    
    app::FileSignatureGenerator generator(inputFilePath, outputFilePath, blockSize);
    generator.generate();
    
    return 0;
}
