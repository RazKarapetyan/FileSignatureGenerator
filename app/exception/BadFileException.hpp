#pragma once

#include "exception/Exception.hpp"

namespace exception {

class BadFileException : public Exception {
public:
    BadFileException() = default;
    BadFileException(std::string_view errorMsg);

    const char* what() const noexcept override;

private:
    std::string _message;
};

} // namespace exception
