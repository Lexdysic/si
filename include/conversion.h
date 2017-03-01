namespace si {

template <
    typename SpaceTo,
    typename SpaceFrom,
    typename Value,
    int64_t L,  // meter
    int64_t M,  // kilogram
    int64_t T,  // second
    int64_t I,  // ampere
    int64_t K,  // kelvin
    int64_t N,  // mole
    int64_t J   // candela
>
Value<Value, SpaceTo, L, M, T, I, K, N, J> ConvertTo (const Value<Value, SpaceFrom, L, M, T, I, K, N, J> & value);

} // namespace si

#include "inline/conversion.inl"