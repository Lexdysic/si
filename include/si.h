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

    template <
        typename xValue,
        typename xSpace,
        int64_t M_, int64_t Kg_, int64_t S_, int64_t A_, int64_t K_, int64_t Mol_, int64_t Cd_
    >
    friend Unit<xValue, xSpace, M_, Kg_, S_, A_, K_, Mol_, Cd_> operator+ (
        const Unit<xValue, xSpace, M_, Kg_, S_, A_, K_, Mol_, Cd_> & lhs, 
        const Unit<xValue, xSpace, M_, Kg_, S_, A_, K_, Mol_, Cd_> & rhs
    );

    template <
        typename xValue,
        typename xSpace,
        int64_t M_, int64_t Kg_, int64_t S_, int64_t A_, int64_t K_, int64_t Mol_, int64_t Cd_
    >
    friend Unit<xValue, xSpace, M_, Kg_, S_, A_, K_, Mol_, Cd_> operator- (
        const Unit<xValue, xSpace, M_, Kg_, S_, A_, K_, Mol_, Cd_> & lhs, 
        const Unit<xValue, xSpace, M_, Kg_, S_, A_, K_, Mol_, Cd_> & rhs
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
// Tags
//
//=============================================================================

struct world_space_tag {};
struct local_space_tag {};

struct radian_space_tag {};
struct degree_space_tag {};

} // namespace si

#include "inline/si.inl"