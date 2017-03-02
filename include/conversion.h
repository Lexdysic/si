#include "si.h"

#pragma once

namespace si {

template <
    typename SpaceTo,
    typename SpaceFrom,
    typename Value,
    int64_t M,
    int64_t Kg,
    int64_t S,
    int64_t A,
    int64_t K,
    int64_t Mol,
    int64_t Cd
>
Value<Value, SpaceTo, M, Kg, S, A, K, Mol, Cd> ConvertTo (const Value<Value, SpaceFrom, M, Kg, S, A, K, Mol, Cd> & value);

} // namespace si

#include "inline/conversion.inl"