// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from dynamic.djinni

#pragma once

#include "../../api/DynamicArray.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class DynamicArray final : ::djinni::JniInterface<::ledger::core::api::DynamicArray, DynamicArray> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::DynamicArray>;
    using CppOptType = std::shared_ptr<::ledger::core::api::DynamicArray>;
    using JniType = jobject;

    using Boxed = DynamicArray;

    ~DynamicArray();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<DynamicArray>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<DynamicArray>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    DynamicArray();
    friend ::djinni::JniClass<DynamicArray>;
    friend ::djinni::JniInterface<::ledger::core::api::DynamicArray, DynamicArray>;

};

}  // namespace djinni_generated
