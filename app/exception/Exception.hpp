#pragma once

namespace exception {
class Exception : public std::exception {
public:
    Exception() : std::exception {} {}
    const char* what() const _NOEXCEPT override { return "Unknown exception."; }
};
} // namespace exception
