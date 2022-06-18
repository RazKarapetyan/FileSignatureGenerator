#include "stdafx.hpp"

#include "CrcHash.hpp"

namespace hash {

std::string CrcHash::hash(app::StringPtr stringPtr) {
    return hash(*stringPtr);
}

std::string CrcHash::hash(std::string string) {
    boost::crc_32_type result;
    result.process_bytes(string.data(), string.length());
    return std::to_string(result.checksum());
}

} // namespace exception
