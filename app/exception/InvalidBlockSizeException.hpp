#pragma once

#include "exception/Exception.hpp"

namespace exception {

class InvalidBlockSizeException : public Exception {
public:
    InvalidBlockSizeException() = default;
    InvalidBlockSizeException(std::string_view error_msg);

    const char* what() const noexcept override;

private:
    std::string _message;
};

} // namespace exception
