#pragma once

namespace fileUtils {

class FileUtils {
public:
    static unsigned int getFileSize(std::string_view filePath);
};

} // namespace fileUtils
