// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ripple_like_wallet.djinni

#ifndef DJINNI_GENERATED_RIPPLELIKETRANSACTION_HPP
#define DJINNI_GENERATED_RIPPLELIKETRANSACTION_HPP

#include "../utils/optional.hpp"
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class Amount;
class BigInt;
class RippleLikeAddress;
struct RippleLikeMemo;

/**
 * TODO: to be more accurate, all RippleLikeBlock classes should be renamed as RippleLikeLedger,
 * since there is an analogy between block and ledger concepts it's ok for the moment ...
 *Class representing a Ripple transaction
 */
class LIBCORE_EXPORT RippleLikeTransaction {
public:
    virtual ~RippleLikeTransaction() {}

    /** Get the hash of the transaction. */
    virtual std::string getHash() = 0;

    /** Get Fees (in drop) */
    virtual std::shared_ptr<Amount> getFees() = 0;

    /** Get destination XRP address */
    virtual std::shared_ptr<RippleLikeAddress> getReceiver() = 0;

    /** Get XRP sender address */
    virtual std::shared_ptr<RippleLikeAddress> getSender() = 0;

    /** Get amount of XRP to send */
    virtual std::shared_ptr<Amount> getValue() = 0;

    /** Serialize the transaction to its raw format. */
    virtual std::vector<uint8_t> serialize() = 0;

    /** Set signature of transaction, when a signature is set serialize method gives back serialized Tx */
    virtual void setSignature(const std::vector<uint8_t> & rSignature, const std::vector<uint8_t> & sSignature) = 0;

    virtual void setDERSignature(const std::vector<uint8_t> & signature) = 0;

    /**
     * Get the time when the transaction was issued or the time of the block including
     * this transaction
     */
    virtual std::chrono::system_clock::time_point getDate() = 0;

    /**
     * Get block to which transaction belongs (was mined in)
     *getBlock(): optional<RippleLikeBlock>;
     * Get sequence of an account when tx was built (number of sent transactions from an account)
     */
    virtual std::shared_ptr<BigInt> getSequence() = 0;

    /** Get Ledger's sequence in which the tx was included */
    virtual std::shared_ptr<BigInt> getLedgerSequence() = 0;

    /** Get Signing public Key */
    virtual std::vector<uint8_t> getSigningPubKey() = 0;

    /** Get all memos associated with the transaction. */
    virtual std::vector<RippleLikeMemo> getMemos() = 0;

    /** Add a memo to a transaction. */
    virtual void addMemo(const RippleLikeMemo & memo) = 0;

    /** An arbitrary unsigned 32-bit integer that identifies a reason for payment or a non-Ripple account */
    virtual std::experimental::optional<int64_t> getDestinationTag() = 0;

    /** Status of the transaction. */
    virtual std::string getStatus() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_RIPPLELIKETRANSACTION_HPP
