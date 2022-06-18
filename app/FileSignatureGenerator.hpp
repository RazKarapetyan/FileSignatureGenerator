#pragma once

#include "Prototypes.hpp"

namespace app {

class FileSignatureGenerator {
public:
    FileSignatureGenerator(const std::string& inputFilePath,
                           const std::string& outputFilePath,
                           app::SizeInMBytes blockSize);

    virtual ~FileSignatureGenerator();

    void generate() noexcept(false);

private:
    void generateHelper();

    void hashAndWrite(app::StringPtr chunk);

private:
    boost::filesystem::ifstream _inputStream;
    std::string _inputFilePath;
    boost::filesystem::ofstream _outputStream;
    app::SizeInMBytes _blockSizeInMb{};
    std::mutex _outStreamLock;
    hash::IHashPtr _hash;
};

}; // namespace app
