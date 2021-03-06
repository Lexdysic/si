#include <cstdint>

#pragma once

namespace si {


//=============================================================================
// 
// Unit
//
//=============================================================================

template <
    typename Value,
    typename Space,
    int64_t M,
    int64_t Kg,
    int64_t S,
    int64_t A,
    int64_t K,
    int64_t Mol,
    int64_t Cd
>
class Unit {
public:
    Unit () = default;
    Unit (const Unit & si) = default;
    explicit Unit (Value value);

    explicit operator Value () const;

    template <
        typename xValue,
        typename xSpace,
        int64_t xM, int64_t xKg, int64_t xS, int64_t xA, int64_t xK, int64_t xMol, int64_t xCd
    >
    friend Unit<xValue, xSpace, xM, xKg, xS, xA, xK, xMol, xCd> operator+ (
        const Unit<xValue, xSpace, xM, xKg, xS, xA, xK, xMol, xCd> & lhs, 
        const Unit<xValue, xSpace, xM, xKg, xS, xA, xK, xMol, xCd> & rhs
    );

    template <
        typename xValue,
        typename xSpace,
        int64_t xM, int64_t xKg, int64_t xS, int64_t xA, int64_t xK, int64_t xMol, int64_t xCd
    >
    friend Unit<xValue, xSpace, xM, xKg, xS, xA, xK, xMol, xCd> operator- (
        const Unit<xValue, xSpace, xM, xKg, xS, xA, xK, xMol, xCd> & lhs, 
        const Unit<xValue, xSpace, xM, xKg, xS, xA, xK, xMol, xCd> & rhs
    );

    template <
        typename xValue,
        typename xSpace,
        int64_t lM, int64_t lKg, int64_t lS, int64_t lA, int64_t lK, int64_t lMol, int64_t lCd,
        int64_t rM, int64_t rKg, int64_t rS, int64_t rA, int64_t rK, int64_t rMol, int64_t rCd
    >
    friend Unit<xValue, xSpace, lM+rM, lKg+rKg, lS+rS, lA+rA, lK+rK, lMol+rMol, lCd+rCd> operator* (
        const Unit<xValue, xSpace, lM, lKg, lS, lA, lK, lMol, lCd> & lhs,
        const Unit<xValue, xSpace, rM, rKg, rS, rA, rK, rMol, rCd> & rhs
    );

    template <
        typename xValue,
        typename xSpace,
        int64_t lM, int64_t lKg, int64_t lS, int64_t lA, int64_t lK, int64_t lMol, int64_t lCd,
        int64_t rM, int64_t rKg, int64_t rS, int64_t rA, int64_t rK, int64_t rMol, int64_t rCd
    >
    friend Unit<xValue, xSpace, lM-rM, lKg-rKg, lS-rS, lA-rA, lK-rK, lMol-rMol, lCd-rCd> operator/ (
        const Unit<xValue, xSpace, lM, lKg, lS, lA, lK, lMol, lCd> & lhs,
        const Unit<xValue, xSpace, rM, rKg, rS, rA, rK, rMol, rCd> & rhs
    );

private:
    Value m_value;
};


//=============================================================================
// 
// Space tags
//
//=============================================================================

namespace space {

struct World {};
struct Local {};

struct Radian {};
struct Degree {};

} // namespace space

} // namespace si

#include "inline/si.inl"