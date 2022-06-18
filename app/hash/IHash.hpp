#pragma once

#include "Prototypes.hpp"

namespace hash {

/**
 * @brief An interface to hash data.
 */
class IHash {
public:
    IHash() = default;
    virtual ~IHash() = default;

   /**
     * @brief Get the hash value of provided string pointer
     *
     * @return The hashed data
     */
    virtual std::string hash(app::StringPtr stringPtr) = 0;

   /**
     * @brief Get the hash value of provided string object
     *
     * @return The hashed data
     */
    virtual std::string hash(std::string string) = 0;
};

} // namespace hash
