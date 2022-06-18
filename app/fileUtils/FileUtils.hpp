#pragma once

#include "Prototypes.hpp"

namespace fileUtils {

class FileUtils {
public:
    static app::SizeInBytes getFileSizeInBytes(std::string_view filePath);
    static app::SizeInMBytes getFileSizeInMBytes(std::string_view filePath);
};

} // namespace fileUtils
