#pragma once

#include "hash/IHash.hpp"

namespace hash {

class CrcHash : public IHash {
public:
    CrcHash() = default;
    
    std::string hash(app::StringPtr stringPtr) override;

    std::string hash(const std::string& string) override;
};

} // namespace hash
