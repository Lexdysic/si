#include <type_traits>

#include "../include/si.h"
#include "../include/types.h"

#define EXPECT_TYPES_EQ(Lhs, Rhs) static_assert(std::is_same<decltype(Lhs), decltype(Rhs)>::value, "Failed Test")

int main () {
    using namespace si;

    EXPECT_TYPES_EQ(Newton<float>(), Kilogram<float>() * Acceleration<float>());
    
    return 0;
}