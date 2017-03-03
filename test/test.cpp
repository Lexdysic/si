#include <type_traits>
#include <cassert>
#include <cmath>

#include "../include/si.h"
#include "../include/types.h"
#include "../include/conversion.h"

#define EXPECT_TYPES_EQ(lhs, rhs) static_assert(std::is_same<decltype(lhs), decltype(rhs)>::value, "Types do not match.")
#define EXPECT_EQ(lhs, rhs) assert((lhs) == (rhs))
#define EXPECT_FLOAT_EQ(lhs, rhs) assert(std::abs((lhs) - (rhs)) < 0.000001)

int main () {
    using namespace si;

    EXPECT_TYPES_EQ(Velocity<float>(), Velocity<float>() + Velocity<float>());
    EXPECT_TYPES_EQ(Velocity<float>(), Velocity<float>() - Velocity<float>());
    EXPECT_TYPES_EQ(Newton<float>(), Kilogram<float>() * Acceleration<float>());
    EXPECT_TYPES_EQ(Velocity<float>(),  Meter<float>() / Second<float>());
    EXPECT_TYPES_EQ((Velocity<float, space::World>()), (ConvertTo<space::World>(Velocity<float, space::Local>())));
    
    {
        auto rad = ConvertTo<space::Radian>(Degree<float>{90.0f});
        EXPECT_FLOAT_EQ(float(rad), detail::kPi / 2.0f);
    }
    return 0;
}