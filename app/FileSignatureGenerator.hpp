#pragma once

namespace app {

class FileSignatureGenerator {
public:
    FileSignatureGenerator(const std::string& inputFilePath,
                           const std::string& outputFilePath,
                           unsigned int blockSize);

    virtual ~FileSignatureGenerator() = default;

    void generate();

private:
    std::string _inputFilePath;
    std::string _outputFilePath;
    unsigned int _blockSize{};
};

}; // namespace app
