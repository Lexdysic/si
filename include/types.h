#include "si.h"

#pragma once

namespace si {

//=============================================================================
// 
// Named Types
//
//=============================================================================

// Base Units                                                   m, kg,  s,  A,  K,mol, cd
template <typename T, typename S = world_space_tag> using Unitless = Unit<T, S,  0,  0,  0,  0,  0,  0,  0>;
template <typename T, typename S = world_space_tag> using Meter    = Unit<T, S,  1,  0,  0,  0,  0,  0,  0>;
template <typename T, typename S = world_space_tag> using Kilogram = Unit<T, S,  0,  1,  0,  0,  0,  0,  0>;
template <typename T, typename S = world_space_tag> using Second   = Unit<T, S,  0,  0,  1,  0,  0,  0,  0>;
template <typename T, typename S = world_space_tag> using Ampere   = Unit<T, S,  0,  0,  0,  1,  0,  0,  0>;
template <typename T, typename S = world_space_tag> using Kelvin   = Unit<T, S,  0,  0,  0,  0,  1,  0,  0>;
template <typename T, typename S = world_space_tag> using Mole     = Unit<T, S,  0,  0,  0,  0,  0,  1,  0>;
template <typename T, typename S = world_space_tag> using Candela  = Unit<T, S,  0,  0,  0,  0,  0,  0,  1>;

// Derived SI Units                                              m, kg,  s,  A,  K,mol, cd
template <typename T, typename S = world_space_tag> using Hertz     = Unit<T, S,  0,  0, -1,  0,  0,  0,  0>;   // Hz = 1/s
template <typename T, typename S = world_space_tag> using Newton    = Unit<T, S,  1,  1, -2,  0,  0,  0,  0>;   // N = kg * m / s**2
template <typename T, typename S = world_space_tag> using Pascal    = Unit<T, S, -1,  1, -2,  0,  0,  0,  0>;   // Pa = N/m**2 = kg * m / s**2
template <typename T, typename S = world_space_tag> using Joule     = Unit<T, S,  2,  1, -2,  0,  0,  0,  0>;   // J = N * m = kg * m**2 / s**2
template <typename T, typename S = world_space_tag> using Watt      = Unit<T, S,  2,  1, -3,  0,  0,  0,  0>;   // W = J/s = kg * m**2 * s**-3
template <typename T, typename S = world_space_tag> using Coulomb   = Unit<T, S,  0,  0,  1,  1,  0,  0,  0>;   // C = s * A
template <typename T, typename S = world_space_tag> using Volt      = Unit<T, S,  2,  1, -3, -1,  0,  0,  0>;   // V = W/A = kg * m**2 * s**-3 * A**-1
template <typename T, typename S = world_space_tag> using Farad     = Unit<T, S, -2, -1,  4,  2,  0,  0,  0>;   // F = C/V = kg**-1 * m**-2 * S**4 * A**2
template <typename T, typename S = world_space_tag> using Ohm       = Unit<T, S,  1,  0,  0,  0,  0,  0,  0>;   // Ohm = V/A = kg * m**2 * s**?3 * A**2
template <typename T, typename S = world_space_tag> using Siemens   = Unit<T, S, -2, -1,  3,  2,  0,  0,  0>;   // S = A/V = kg**1 * m**2 * s**3 * A**2
template <typename T, typename S = world_space_tag> using Weber     = Unit<T, S,  2,  1, -2, -1,  0,  0,  0>;   // Wb = V * s = kg * m**2 * s**?2* A**1
template <typename T, typename S = world_space_tag> using Tesla     = Unit<T, S,  0,  1, -2, -1,  0,  0,  0>;   // T =  Wb / m**2 = kg * s**?2 * A**1
template <typename T, typename S = world_space_tag> using Henry     = Unit<T, S,  2,  1, -2, -2,  0,  0,  0>;   // H = Wb/A = kg * m**2 * s**-2 * A**-2
template <typename T, typename S = world_space_tag> using Celsius   = Unit<T, S,  0,  0,  0,  0,  1,  0,  0>;   // C = K
template <typename T, typename S = world_space_tag> using Lumen     = Unit<T, S,  0,  0,  0,  0,  0,  0,  1>;   // lm = cd * sr = cd
template <typename T, typename S = world_space_tag> using Lux       = Unit<T, S, -2,  0,  0,  0,  0,  0,  1>;   // lx = lm / m**2 = cd / m**2
template <typename T, typename S = world_space_tag> using Bacquerel = Unit<T, S,  0,  0, -1,  0,  0,  0,  0>;   // Bq = 1/s
template <typename T, typename S = world_space_tag> using Gray      = Unit<T, S,  2,  0, -2,  0,  0,  0,  0>;   // Gy = J/kg = m**2 / s**2
template <typename T, typename S = world_space_tag> using Sievert   = Unit<T, S,  2,  0, -2,  0,  0,  0,  0>;   // Sv = J/kg = m**2 / s**2
template <typename T, typename S = world_space_tag> using Katal     = Unit<T, S,  0,  0, -1,  0,  0,  1,  0>;   // kat = mol / s

// Physical Units                                                   m, kg,  s,  A,  K,mol, cd
template <typename T, typename S = world_space_tag> using Velocity     = Unit<T, S,  1,  0, -1,  0,  0,  0,  0>;   // m / s
template <typename T, typename S = world_space_tag> using Acceleration = Unit<T, S,  1,  0, -2,  0,  0,  0,  0>;   // m / s**2
template <typename T, typename S = world_space_tag> using Jerk         = Unit<T, S,  1,  0, -3,  0,  0,  0,  0>;   // m / s**3
template <typename T, typename S = world_space_tag> using Snap         = Unit<T, S,  1,  0, -4,  0,  0,  0,  0>;   // m / s**4
template <typename T, typename S = world_space_tag> using Area         = Unit<T, S,  2,  0,  0,  0,  0,  0,  0>;   // m**2
template <typename T, typename S = world_space_tag> using Volume       = Unit<T, S,  3,  0,  0,  0,  0,  0,  0>;   // m**3
template <typename T, typename S = world_space_tag> using Density      = Unit<T, S, -3,  1,  0,  0,  0,  0,  0>;   // kg / m**3
template <typename T, typename S = world_space_tag> using AreaDensity  = Unit<T, S, -2,  1,  0,  0,  0,  0,  0>;   // kg / m**2
template <typename T, typename S = world_space_tag> using Flow         = Unit<T, S,  3,  0, -1,  0,  0,  0,  0>;   // m**3 / s
template <typename T, typename S = world_space_tag> using Torque       = Unit<T, S,  2,  1, -2,  0,  0,  0,  0>;   // m**2 * kg / s**2
template <typename T, typename S = world_space_tag> using Momentum     = Unit<T, S,  1,  1, -1,  0,  0,  0,  0>;   // m * kg / s

// Specialized Spaces                                            m, kg,  s,  A,  K,mol, cd
template <typename T> using Degree = Unit<T, degree_space_tag,  0,  0,  0,  0,  0,  0,  0>;
template <typename T> using Radian = Unit<T, radian_space_tag,  0,  0,  0,  0,  0,  0,  0>;

} // namespace si