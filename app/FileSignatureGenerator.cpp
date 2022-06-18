#include "FileSignatureGenerator.hpp"

#include "exception/InvalidBlockSizeException.hpp"

namespace app {
    
FileSignatureGenerator::FileSignatureGenerator(const std::string& inputFilePath,
                                               const std::string& outputFilePath,
                                               unsigned int blockSize) 
                                               : _inputFilePath(inputFilePath),
                                                 _outputFilePath(outputFilePath), 
                                                 _blockSize(blockSize) {}

void FileSignatureGenerator::generate() {
    (void)_blockSize;
    copy_file1_to_file2();
}

void FileSignatureGenerator::copy_file1_to_file2()
{
    using boost::iostreams::file_sink;
    using boost::iostreams::file_source;
    using boost::iostreams::position_to_offset;
    using boost::iostreams::seek;
    using boost::iostreams::stream_offset;
    
    file_source in(_inputFilePath, BOOST_IOS::binary);
    file_sink out(_outputFilePath, BOOST_IOS::binary);
    stream_offset off;

    off = position_to_offset(seek(in, -5, BOOST_IOS::end));

    for (int i = 0; i < 3; i++) {
        char buf[6];
        std::memset(buf, '\0', sizeof buf);

        in.read(buf, 5);
        out.write(buf, 5);

        position_to_offset(seek(in, -(7*1 + 10), BOOST_IOS::cur));
        off = position_to_offset(seek(out, 7*1, BOOST_IOS::cur));
        std::cout << "out: seek " << off << std::endl;
    }
}

}; // namespace app
