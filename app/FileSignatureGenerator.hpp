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

private:
    std::string _inputFilePath;
    std::string _outputFilePath;
    app::SizeInMBytes _blockSizeInMb{};
    hash::IHashPtr _hash;
};

}; // namespace app
