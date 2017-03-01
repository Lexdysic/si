namespace si {

template <
    typename V,
    typename S,
    int64_t L, int64_t M, int64_t T, int64_t I, int64_t K, int64_t N, int64_t J
>
inline Value<V, S, L, M, T, I, K, N, J> operator+ (
    const Value<V, S, L, M, T, I, K, N, J> & lhs,
    const Value<V, S, L, M, T, I, K, N, J> & rhs
) {
    return Value<V, S, L, M, T, I, K, N, J>(lhs.m_value + rhs.m_value);
}

template <
    typename V,
    typename S,
    int64_t L, int64_t M, int64_t T, int64_t I, int64_t K, int64_t N, int64_t J
>
inline Value<V, S, L, M, T, I, K, N, J> operator- (
    const Value<V, S, L, M, T, I, K, N, J> & lhs,
    const Value<V, S, L, M, T, I, K, N, J> & rhs
) {
    return Value<V, S, L, M, T, I, K, N, J>(lhs.m_value - rhs.m_value);
}

template <
    typename V,
    typename S,
    int64_t Ll, int64_t Ml, int64_t Tl, int64_t Il, int64_t Kl, int64_t Nl, int64_t Jl,
    int64_t Lr, int64_t Mr, int64_t Tr, int64_t Ir, int64_t Kr, int64_t Nr, int64_t Jr
>
inline Value<V, S, Ll+Lr, Ml+Mr, Tl+Tr, Il+Ir, Kl+Kr, Nl+Nr, Jl+Jr> operator* (
    const Value<V, S, Ll, Ml, Tl, Il, Kl, Nl, Jl> & lhs,
    const Value<V, S, Lr, Mr, Tr, Ir, Kr, Nr, Jr> & rhs
) {
    return Value<V, S, Ll+Lr, Ml+Mr, Tl+Tr, Il+Ir, Kl+Kr, Nl+Nr, Jl+Jr>(lhs.m_value * rhs.m_value);
}

template <
    typename V,
    typename S,
    int64_t Ll, int64_t Ml, int64_t Tl, int64_t Il, int64_t Kl, int64_t Nl, int64_t Jl,
    int64_t Lr, int64_t Mr, int64_t Tr, int64_t Ir, int64_t Kr, int64_t Nr, int64_t Jr
>
inline Value<V, S, Ll+Lr, Ml+Mr, Tl+Tr, Il+Ir, Kl+Kr, Nl+Nr, Jl+Jr> operator/ (
    const Value<V, S, Ll, Ml, Tl, Il, Kl, Nl, Jl> & lhs,
    const Value<V, S, Lr, Mr, Tr, Ir, Kr, Nr, Jr> & rhs
) {
    return Value<V, S, Ll-Lr, Ml-Mr, Tl-Tr, Il-Ir, Kl-Kr, Nl-Nr, Jl-Jr>(lhs.m_value / rhs.m_value);
}

} // namespace