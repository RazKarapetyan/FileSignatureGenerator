#include "InvalidBlockSizeException.hpp"

namespace exception {

InvalidBlockSizeException::InvalidBlockSizeException(std::string_view errorMsg)
    : _message {std::string("Block reading exception: ") + std::string(errorMsg)} {}

const char* InvalidBlockSizeException::what() const noexcept { return _message.c_str(); }

} // namespace exception
