#pragma once

namespace commandLineUtils {

class CommandLineUtils {
public:
    static std::tuple<std::string, std::string, int> parse(int argc, const char* argv[]);
};

} // namespace fileUtils
