#include "stdafx.hpp"

#include "FileUtils.hpp"

namespace fileUtils {

app::SizeInBytes FileUtils::getFileSizeInBytes(std::string_view filePath) {
    return boost::filesystem::file_size(std::string(filePath));
}

app::SizeInMBytes FileUtils::getFileSizeInMBytes(std::string_view filePath) {
    return (getFileSizeInBytes(filePath) / 1000000.0);
}

}; // namespace fileUtils
