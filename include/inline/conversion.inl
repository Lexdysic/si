namespace si {


template <typename Value>
Value<Value, degree_space_tag, 0, 0, 0, 0, 0, 0, 0> ConvertTo (const Value<Value, radian_space_tag, 0, 0, 0, 0, 0, 0, 0> & value) {
    return Value<Value, degree_space_tag, 0, 0, 0, 0, 0, 0, 0>{ value.m_value * 180 / M_PI };
}


template <typename Value>
Value<Value, radian_space_tag, 0, 0, 0, 0, 0, 0, 0> ConvertTo (const Value<Value, degree_space_tag, 0, 0, 0, 0, 0, 0, 0> & value) {
    return Value<Value, radian_space_tag, 0, 0, 0, 0, 0, 0, 0>{ value.m_value * M_PI / 180 };
}


} // namespace si