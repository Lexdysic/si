#include "si.h"

#pragma once

namespace si {

//=============================================================================
// 
// Named Types
//
//=============================================================================

// Base Units                                                                 m, kg,  s,  A,  K,mol, cd
template <typename T, typename S = space::World> using Unitless = Unit<T, S,  0,  0,  0,  0,  0,  0,  0>;
template <typename T, typename S = space::World> using Meter    = Unit<T, S,  1,  0,  0,  0,  0,  0,  0>;
template <typename T, typename S = space::World> using Kilogram = Unit<T, S,  0,  1,  0,  0,  0,  0,  0>;
template <typename T, typename S = space::World> using Second   = Unit<T, S,  0,  0,  1,  0,  0,  0,  0>;
template <typename T, typename S = space::World> using Ampere   = Unit<T, S,  0,  0,  0,  1,  0,  0,  0>;
template <typename T, typename S = space::World> using Kelvin   = Unit<T, S,  0,  0,  0,  0,  1,  0,  0>;
template <typename T, typename S = space::World> using Mole     = Unit<T, S,  0,  0,  0,  0,  0,  1,  0>;
template <typename T, typename S = space::World> using Candela  = Unit<T, S,  0,  0,  0,  0,  0,  0,  1>;

// Derived SI Units                                                            m, kg,  s,  A,  K,mol, cd
template <typename T, typename S = space::World> using Hertz     = Unit<T, S,  0,  0, -1,  0,  0,  0,  0>;   // Hz = 1/s
template <typename T, typename S = space::World> using Newton    = Unit<T, S,  1,  1, -2,  0,  0,  0,  0>;   // N = kg * m / s**2
template <typename T, typename S = space::World> using Pascal    = Unit<T, S, -1,  1, -2,  0,  0,  0,  0>;   // Pa = N/m**2 = kg * m / s**2
template <typename T, typename S = space::World> using Joule     = Unit<T, S,  2,  1, -2,  0,  0,  0,  0>;   // J = N * m = kg * m**2 / s**2
template <typename T, typename S = space::World> using Watt      = Unit<T, S,  2,  1, -3,  0,  0,  0,  0>;   // W = J/s = kg * m**2 * s**-3
template <typename T, typename S = space::World> using Coulomb   = Unit<T, S,  0,  0,  1,  1,  0,  0,  0>;   // C = s * A
template <typename T, typename S = space::World> using Volt      = Unit<T, S,  2,  1, -3, -1,  0,  0,  0>;   // V = W/A = kg * m**2 * s**-3 * A**-1
template <typename T, typename S = space::World> using Farad     = Unit<T, S, -2, -1,  4,  2,  0,  0,  0>;   // F = C/V = kg**-1 * m**-2 * S**4 * A**2
template <typename T, typename S = space::World> using Ohm       = Unit<T, S,  1,  0,  0,  0,  0,  0,  0>;   // Ohm = V/A = kg * m**2 * s**?3 * A**2
template <typename T, typename S = space::World> using Siemens   = Unit<T, S, -2, -1,  3,  2,  0,  0,  0>;   // S = A/V = kg**1 * m**2 * s**3 * A**2
template <typename T, typename S = space::World> using Weber     = Unit<T, S,  2,  1, -2, -1,  0,  0,  0>;   // Wb = V * s = kg * m**2 * s**?2* A**1
template <typename T, typename S = space::World> using Tesla     = Unit<T, S,  0,  1, -2, -1,  0,  0,  0>;   // T =  Wb / m**2 = kg * s**?2 * A**1
template <typename T, typename S = space::World> using Henry     = Unit<T, S,  2,  1, -2, -2,  0,  0,  0>;   // H = Wb/A = kg * m**2 * s**-2 * A**-2
template <typename T, typename S = space::World> using Celsius   = Unit<T, S,  0,  0,  0,  0,  1,  0,  0>;   // C = K
template <typename T, typename S = space::World> using Lumen     = Unit<T, S,  0,  0,  0,  0,  0,  0,  1>;   // lm = cd * sr = cd
template <typename T, typename S = space::World> using Lux       = Unit<T, S, -2,  0,  0,  0,  0,  0,  1>;   // lx = lm / m**2 = cd / m**2
template <typename T, typename S = space::World> using Bacquerel = Unit<T, S,  0,  0, -1,  0,  0,  0,  0>;   // Bq = 1/s
template <typename T, typename S = space::World> using Gray      = Unit<T, S,  2,  0, -2,  0,  0,  0,  0>;   // Gy = J/kg = m**2 / s**2
template <typename T, typename S = space::World> using Sievert   = Unit<T, S,  2,  0, -2,  0,  0,  0,  0>;   // Sv = J/kg = m**2 / s**2
template <typename T, typename S = space::World> using Katal     = Unit<T, S,  0,  0, -1,  0,  0,  1,  0>;   // kat = mol / s

// Physical Units                                                                 m, kg,  s,  A,  K,mol, cd
template <typename T, typename S = space::World> using Velocity     = Unit<T, S,  1,  0, -1,  0,  0,  0,  0>;   // m / s
template <typename T, typename S = space::World> using Acceleration = Unit<T, S,  1,  0, -2,  0,  0,  0,  0>;   // m / s**2
template <typename T, typename S = space::World> using Jerk         = Unit<T, S,  1,  0, -3,  0,  0,  0,  0>;   // m / s**3
template <typename T, typename S = space::World> using Snap         = Unit<T, S,  1,  0, -4,  0,  0,  0,  0>;   // m / s**4
template <typename T, typename S = space::World> using Area         = Unit<T, S,  2,  0,  0,  0,  0,  0,  0>;   // m**2
template <typename T, typename S = space::World> using Volume       = Unit<T, S,  3,  0,  0,  0,  0,  0,  0>;   // m**3
template <typename T, typename S = space::World> using Density      = Unit<T, S, -3,  1,  0,  0,  0,  0,  0>;   // kg / m**3
template <typename T, typename S = space::World> using AreaDensity  = Unit<T, S, -2,  1,  0,  0,  0,  0,  0>;   // kg / m**2
template <typename T, typename S = space::World> using Flow         = Unit<T, S,  3,  0, -1,  0,  0,  0,  0>;   // m**3 / s
template <typename T, typename S = space::World> using Torque       = Unit<T, S,  2,  1, -2,  0,  0,  0,  0>;   // m**2 * kg / s**2
template <typename T, typename S = space::World> using Momentum     = Unit<T, S,  1,  1, -1,  0,  0,  0,  0>;   // m * kg / s

// Specialized Spaces                                        m, kg,  s,  A,  K,mol, cd
template <typename T> using Degree = Unit<T, space::Degree,  0,  0,  0,  0,  0,  0,  0>;
template <typename T> using Radian = Unit<T, space::Radian,  0,  0,  0,  0,  0,  0,  0>;

} // namespace si