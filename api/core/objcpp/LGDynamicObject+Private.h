// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from dynamic.djinni

#include "DynamicObject.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class LGDynamicObject;

namespace djinni_generated {

class DynamicObject
{
public:
    using CppType = std::shared_ptr<::ledger::core::api::DynamicObject>;
    using CppOptType = std::shared_ptr<::ledger::core::api::DynamicObject>;
    using ObjcType = LGDynamicObject*;

    using Boxed = DynamicObject;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated
