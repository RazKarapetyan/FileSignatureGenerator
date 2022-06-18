#include "InvalidBlockSizeException.hpp"

namespace exception {

InvalidBlockSizeException::InvalidBlockSizeException(std::string_view error_msg)
    : _message {std::string("Block reading exception: ") + std::string(error_msg)} {}

const char* InvalidBlockSizeException::what() const noexcept { return _message.c_str(); }

} // namespace exception
