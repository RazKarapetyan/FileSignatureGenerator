#include "CommandLineUtils.hpp"

namespace commandLineUtils {

std::tuple<std::string, std::string, int> CommandLineUtils::parse(int argc, const char* argv[])  {

    std::string inputFilePath;
    std::string outputFilePath;
    unsigned int blockSize{};

    try
    {
        namespace po = boost::program_options;
        po::options_description description("App Usage");
        description.add_options()
            ("help,h", "Display help message")
            ("input-file", po::value<std::string>(&inputFilePath)->required(), "Input file path [required]")
            ("output-file",po::value<std::string>(&outputFilePath)->required(),  "Output file path [required]")
            ("block-size", po::value<unsigned int>()->default_value(1), "File block size");

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).options(description).run(), vm);

        if(vm.count("help")){
            std::cout << description;
            return {};
        }

        if(vm.count("block-size")){
            blockSize = vm["block-size"].as<unsigned int>();
        }

        po::notify(vm);
    }
    catch(std::exception& e)
    {
        std::cerr << "Command line arguments parsing error: " << e.what() << "\n";
        return {};
    }
    catch(...)
    {
        std::cerr << "Unknown error!" << "\n";
        return {};
    }
    return {inputFilePath, outputFilePath, blockSize};
}

}; // namespace commandLineUtils
