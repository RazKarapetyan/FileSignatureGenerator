#include "BadFileException.hpp"

namespace exception {

BadFileException::BadFileException(std::string_view error_msg)
    : _message {std::string("Bad file exception: ") + std::string(error_msg)} {}

const char* BadFileException::what() const noexcept { return _message.c_str(); }

} // namespace exception
