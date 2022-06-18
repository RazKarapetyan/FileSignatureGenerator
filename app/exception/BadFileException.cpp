#include "BadFileException.hpp"

namespace exception {

BadFileException::BadFileException(std::string_view errorMsg)
    : _message {std::string("Bad file exception: ") + std::string(errorMsg)} {}

const char* BadFileException::what() const noexcept { return _message.c_str(); }

} // namespace exception
