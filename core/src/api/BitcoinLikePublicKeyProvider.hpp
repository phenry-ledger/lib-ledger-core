// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_public_key_provider.djinni

#pragma once

#include <memory>
#include <string>

namespace ledger { namespace core { namespace api {

class BitcoinLikePublicKeyCompletionBlock;
struct BitcoinLikeNetworkParameters;

class BitcoinLikePublicKeyProvider {
public:
    virtual ~BitcoinLikePublicKeyProvider() {}

    virtual void get(const std::string & deviceId, const std::string & path, const BitcoinLikeNetworkParameters & params, const std::shared_ptr<BitcoinLikePublicKeyCompletionBlock> & callback) = 0;
};

} } }  // namespace ledger::core::api
