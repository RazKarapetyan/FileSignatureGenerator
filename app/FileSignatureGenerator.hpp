#pragma once

#include "Prototypes.hpp"

namespace app {

class FileSignatureGenerator {
public:
    FileSignatureGenerator(const std::string& inputFilePath,
                           const std::string& outputFilePath,
                           app::SizeInMBytes blockSize);

    virtual ~FileSignatureGenerator() = default;

    void generate() noexcept(false);

private:
    void generateHelper();

    void hashAndWrite(app::StringPtr chunk);

private:
    std::string _inputFilePath;
    app::SizeInMBytes _blockSizeInMb{};
    hash::IHashPtr _hash;
    boost::filesystem::ofstream _outputStream;
    std::mutex _outStreamLock;
};

}; // namespace app
