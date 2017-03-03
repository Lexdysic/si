#include <cmath>

#include "../si.h"

namespace si {

namespace detail {

constexpr double kPi = 3.141592653589793238;

} // namespace detail

template <
    typename SpaceTo,
    typename SpaceFrom,
    typename Value,
    int64_t M, int64_t Kg, int64_t S, int64_t A, int64_t K, int64_t Mol, int64_t Cd
>
Unit<Value, SpaceTo, M, Kg, S, A, K, Mol, Cd> ConvertTo (const Unit<Value, SpaceFrom, M, Kg, S, A, K, Mol, Cd> & value) {
    return Unit<Value, SpaceTo, M, Kg, S, A, K, Mol, Cd>{ Value(value) };
}


template <typename Value>
Unit<Value, space::Degree, 0, 0, 0, 0, 0, 0, 0> ConvertTo (const Unit<Value, space::Radian, 0, 0, 0, 0, 0, 0, 0> & value) {
    return Unit<Value, space::Degree, 0, 0, 0, 0, 0, 0, 0>{ Value(value) * 180 / detail::kPi };
}


template <typename Value>
Unit<Value, space::Radian, 0, 0, 0, 0, 0, 0, 0> ConvertTo (const Unit<Value, space::Degree, 0, 0, 0, 0, 0, 0, 0> & value) {
    return Unit<Value, space::Radian, 0, 0, 0, 0, 0, 0, 0>{ Value(value) * detail::kPi / 180 };
}


} // namespace si