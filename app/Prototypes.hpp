namespace app {
    using SizeInBytes = boost::uintmax_t;
    using SizeInMBytes = double;

    using StringPtr = std::shared_ptr<std::string>;
}; // namespace app

namespace hash {
    class IHash;
    using IHashPtr = std::shared_ptr<IHash>;
}; // namespace hash
