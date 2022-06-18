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
    try
    {
        generator.generate();
    }
    catch(std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return -1;
    }
    catch(...)
    {
        std::cerr << "Unknown error!" << "\n";
        return -1;
    }
    
    return 0;
}
