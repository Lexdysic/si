#include <cstdint>

namespace si {


//=============================================================================
// 
// Value
//
//=============================================================================

template <
    typename V, // value
    typename S, // space
    int64_t L,  // meter
    int64_t M,  // kilogram
    int64_t T,  // second
    int64_t I,  // ampere
    int64_t K,  // kelvin
    int64_t N,  // mole
    int64_t J   // candela
>
class Value {
public:
    Value () = default;
    Value (const Value & si) = default;
    explicit Value (V value) : m_value(value) {}

    template <
        typename V,
        typename S,
        int64_t L, int64_t M, int64_t T, int64_t I, int64_t K, int64_t N, int64_t J
    >
    friend inline Value<V, S, L, M, T, I, K, N, J>
    operator+ (const Value<V, S, L, M, T, I, K, N, J> &, const Value<V, S, L, M, T, I, K, N, J> &);

    template <
        typename V,
        typename S,
        int64_t L, int64_t M, int64_t T, int64_t I, int64_t K, int64_t N, int64_t J
    >
    friend inline Value<V, S, L, M, T, I, K, N, J>
    operator- (const Value<V, S, L, M, T, I, K, N, J> &, const Value<V, S, L, M, T, I, K, N, J> &);

    template <
        typename V,
        typename S,
        int64_t Ll, int64_t Ml, int64_t Tl, int64_t Il, int64_t Kl, int64_t Nl, int64_t Jl,
        int64_t Lr, int64_t Mr, int64_t Tr, int64_t Ir, int64_t Kr, int64_t Nr, int64_t Jr
    >
    friend inline Value<Ll+Lr, Ml+Mr, Tl+Tr, Il+Ir, Kl+Kr, Nl+Nr, Jl+Jr>
    operator* (const Value<V, S, Ll, Ml, Tl, Il, Kl, Nl, Jl> & lhs, const Value<V, S, Lr, Mr, Tr, Ir, Kr, Nr, Jr> & rhs);

    template <
        typename V,
        typename S,
        int64_t Ll, int64_t Ml, int64_t Tl, int64_t Il, int64_t Kl, int64_t Nl, int64_t Jl,
        int64_t Lr, int64_t Mr, int64_t Tr, int64_t Ir, int64_t Kr, int64_t Nr, int64_t Jr
    >
    friend inline Value<V, S, Ll-Lr, Ml-Mr, Tl-Tr, Il-Ir, Kl-Kr, Nl-Nr, Jl-Jr>
    operator/ (const Value<V, S, Ll, Ml, Tl, Il, Kl, Nl, Jl> & lhs, const Value<V, S, Lr, Mr, Tr, Ir, Kr, Nr, Jr> & rhs);

    V m_value;
};


//=============================================================================
// 
// Tags
//
//=============================================================================

struct world_space_tag {};
struct local_space_tag {};

struct radian_space_tag {};
struct degree_space_tag {};


//=============================================================================
// 
// Named Types
//
//=============================================================================

// Base Units                                                   m, kg,  s,  A,  K,mol, cd
template <typename T, typename S> using Unitless = Value<T, S,  0,  0,  0,  0,  0,  0,  0>;
template <typename T, typename S> using Meter    = Value<T, S,  1,  0,  0,  0,  0,  0,  0>;
template <typename T, typename S> using Kilogram = Value<T, S,  0,  1,  0,  0,  0,  0,  0>;
template <typename T, typename S> using Second   = Value<T, S,  0,  0,  1,  0,  0,  0,  0>;
template <typename T, typename S> using Ampere   = Value<T, S,  0,  0,  0,  1,  0,  0,  0>;
template <typename T, typename S> using Kelvin   = Value<T, S,  0,  0,  0,  0,  1,  0,  0>;
template <typename T, typename S> using Mole     = Value<T, S,  0,  0,  0,  0,  0,  1,  0>;
template <typename T, typename S> using Candela  = Value<T, S,  0,  0,  0,  0,  0,  0,  1>;

// Derived SI Units                                              m, kg,  s,  A,  K,mol, cd
template <typename T, typename S> using Hertz     = Value<T, S,  0,  0, -1,  0,  0,  0,  0>;   // Hz = 1/s
template <typename T, typename S> using Newton    = Value<T, S,  1,  1, -2,  0,  0,  0,  0>;   // N = kg * m / s**2
template <typename T, typename S> using Pascal    = Value<T, S, -1,  1, -2,  0,  0,  0,  0>;   // Pa = N/m**2 = kg * m / s**2
template <typename T, typename S> using Joule     = Value<T, S,  2,  1, -2,  0,  0,  0,  0>;   // J = N * m = kg * m**2 / s**2
template <typename T, typename S> using Watt      = Value<T, S,  2,  1, -3,  0,  0,  0,  0>;   // W = J/s = kg * m**2 * s**-3
template <typename T, typename S> using Coulomb   = Value<T, S,  0,  0,  1,  1,  0,  0,  0>;   // C = s * A
template <typename T, typename S> using Volt      = Value<T, S,  2,  1, -3, -1,  0,  0,  0>;   // V = W/A = kg * m**2 * s**-3 * A**-1
template <typename T, typename S> using Farad     = Value<T, S, -2, -1,  4,  2,  0,  0,  0>;   // F = C/V = kg**-1 * m**-2 * S**4 * A**2
template <typename T, typename S> using Ohm       = Value<T, S,  1,  0,  0,  0,  0,  0,  0>;   // Ohm = V/A = kg * m**2 * s**?3 * A**2
template <typename T, typename S> using Siemens   = Value<T, S, -2, -1,  3,  2,  0,  0,  0>;   // S = A/V = kg**1 * m**2 * s**3 * A**2
template <typename T, typename S> using Weber     = Value<T, S,  2,  1, -2, -1,  0,  0,  0>;   // Wb = V * s = kg * m**2 * s**?2* A**1
template <typename T, typename S> using Tesla     = Value<T, S,  0,  1, -2, -1,  0,  0,  0>;   // T =  Wb / m**2 = kg * s**?2 * A**1
template <typename T, typename S> using Henry     = Value<T, S,  2,  1, -2, -2,  0,  0,  0>;   // H = Wb/A = kg * m**2 * s**-2 * A**-2
template <typename T, typename S> using Celsius   = Value<T, S,  0,  0,  0,  0,  1,  0,  0>;   // C = K
template <typename T, typename S> using Lumen     = Value<T, S,  0,  0,  0,  0,  0,  0,  1>;   // lm = cd * sr = cd
template <typename T, typename S> using Lux       = Value<T, S, -2,  0,  0,  0,  0,  0,  1>;   // lx = lm / m**2 = cd / m**2
template <typename T, typename S> using Bacquerel = Value<T, S,  0,  0, -1,  0,  0,  0,  0>;   // Bq = 1/s
template <typename T, typename S> using Gray      = Value<T, S,  2,  0, -2,  0,  0,  0,  0>;   // Gy = J/kg = m**2 / s**2
template <typename T, typename S> using Sievert   = Value<T, S,  2,  0, -2,  0,  0,  0,  0>;   // Sv = J/kg = m**2 / s**2
template <typename T, typename S> using Katal     = Value<T, S,  0,  0, -1,  0,  0,  1,  0>;   // kat = mol / s

// Physical Units                                                   m, kg,  s,  A,  K,mol, cd
template <typename T, typename S> using Velocity     = Value<T, S,  1,  0, -1,  0,  0,  0,  0>;   // m / s
template <typename T, typename S> using Acceleration = Value<T, S,  1,  0, -2,  0,  0,  0,  0>;   // m / s**2
template <typename T, typename S> using Jerk         = Value<T, S,  1,  0, -3,  0,  0,  0,  0>;   // m / s**3
template <typename T, typename S> using Snap         = Value<T, S,  1,  0, -4,  0,  0,  0,  0>;   // m / s**4
template <typename T, typename S> using Area         = Value<T, S,  2,  0,  0,  0,  0,  0,  0>;   // m**2
template <typename T, typename S> using Volume       = Value<T, S,  3,  0,  0,  0,  0,  0,  0>;   // m**3
template <typename T, typename S> using Density      = Value<T, S, -3,  1,  0,  0,  0,  0,  0>;   // kg / m**3
template <typename T, typename S> using AreaDensity  = Value<T, S, -2,  1,  0,  0,  0,  0,  0>;   // kg / m**2
template <typename T, typename S> using Flow         = Value<T, S,  3,  0, -1,  0,  0,  0,  0>;   // m**3 / s
template <typename T, typename S> using Torque       = Value<T, S,  2,  1, -2,  0,  0,  0,  0>;   // m**2 * kg / s**2
template <typename T, typename S> using Momentum     = Value<T, S,  1,  1, -1,  0,  0,  0,  0>;   // m * kg / s

// Specialized Spaces                                            m, kg,  s,  A,  K,mol, cd
template <typename T> using Degree = Value<T, degree_space_tag,  0,  0,  0,  0,  0,  0,  0>;
template <typename T> using Radian = Value<T, radian_space_tag,  0,  0,  0,  0,  0,  0,  0>;

} // namespace si

#include "inline/si.inl"