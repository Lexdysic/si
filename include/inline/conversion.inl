namespace si {


template <typename V>
Value<V, degree_space_tag, 0, 0, 0, 0, 0, 0, 0> ConvertTo (const Value<V, radian_space_tag, 0, 0, 0, 0, 0, 0, 0> & value) {
    return Value<V, degree_space_tag, 0, 0, 0, 0, 0, 0, 0>{ value.m_value * 180 / M_PI };
}


template <typename V>
Value<V, radian_space_tag, 0, 0, 0, 0, 0, 0, 0> ConvertTo (const Value<V, degree_space_tag, 0, 0, 0, 0, 0, 0, 0> & value) {
    return Value<V, radian_space_tag, 0, 0, 0, 0, 0, 0, 0>{ value.m_value * M_PI / 180 };
}


} // namespace si