// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_public_key_provider.djinni

#include "BitcoinLikeBase58ExtendedPublicKeyProvider.hpp"  // my header
#include "BitcoinLikeNetworkParameters.hpp"
#include "Marshal.hpp"
#include "StringCompletionBlock.hpp"

namespace djinni_generated {

BitcoinLikeBase58ExtendedPublicKeyProvider::BitcoinLikeBase58ExtendedPublicKeyProvider() : ::djinni::JniInterface<::ledger::core::api::BitcoinLikeBase58ExtendedPublicKeyProvider, BitcoinLikeBase58ExtendedPublicKeyProvider>() {}

BitcoinLikeBase58ExtendedPublicKeyProvider::~BitcoinLikeBase58ExtendedPublicKeyProvider() = default;

BitcoinLikeBase58ExtendedPublicKeyProvider::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

BitcoinLikeBase58ExtendedPublicKeyProvider::JavaProxy::~JavaProxy() = default;

void BitcoinLikeBase58ExtendedPublicKeyProvider::JavaProxy::get(const std::string & c_deviceId, const std::string & c_path, const ::ledger::core::api::BitcoinLikeNetworkParameters & c_params, const std::shared_ptr<::ledger::core::api::StringCompletionBlock> & c_completion) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::BitcoinLikeBase58ExtendedPublicKeyProvider>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_get,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_deviceId)),
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_path)),
                           ::djinni::get(::djinni_generated::BitcoinLikeNetworkParameters::fromCpp(jniEnv, c_params)),
                           ::djinni::get(::djinni_generated::StringCompletionBlock::fromCpp(jniEnv, c_completion)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
