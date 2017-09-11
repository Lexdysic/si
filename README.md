# What is it?

This library provides a single type that can be used to represent any physical SI unit. It provides
automatic type safety by ensuring values of differing types can not be operaterated on in illegal ways. For instance, `distance + velocity` would generate an compile-time error; where as `distance + velocity * time` is a legal expression.

# Example

```cpp
auto position = Meter<float>(15);
auto velocity = Velocity<float>(10);
auto time     = Second<float>(2);

auto fubar  = position + velocity; //<-- Compilation error
auto result = position + velocity * time;

std::cout << float(result); // "45"
```
