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
    void copy_file1_to_file2();

private:
    std::string _inputFilePath;
    std::string _outputFilePath;
    unsigned int _blockSize{};
};

}; // namespace app
