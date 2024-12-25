#pragma once

struct FastDiv {
    using u64 = uint64_t;
    using u128 = __uint128_t;
    constexpr FastDiv() : m(), s(), x() {}
    constexpr FastDiv(int _m)
        : m(_m), s(__lg(m - 1)), x(((u128(1) << (s + 64)) + m - 1) / m) {}
    constexpr int get() {
        return m;
    }
    constexpr friend u64 operator/(u64 n, const FastDiv &d) {
        return (u128(n) * d.x >> d.s) >> 64;
    }
    constexpr friend int operator%(u64 n, const FastDiv &d) {
        return n - n / d * d.m;
    }
    constexpr pair<u64, int> divmod(u64 n) const {
        u64 q = n / (*this);
        return {q, n - q * m};
    }
    int m, s;
    u64 x;
};

struct FastDiv64 {
    using u64 = uint64_t;
    using u128 = __uint128_t;
    u128 mod, mh, ml;
    explicit FastDiv64(u64 mod = 1) : mod(mod) {
        u128 m = u128(-1) / mod;
        if (m * mod + mod == u128(0))
            ++m;
        mh = m >> 64;
        ml = m & u64(-1);
    }
    u64 umod() const {
        return mod;
    }
    u64 modulo(u128 x) {
        u128 z = (x & u64(-1)) * ml;
        z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);
        z = (x >> 64) * mh + (z >> 64);
        x -= z * mod;
        return x < mod ? x : x - mod;
    }
    u64 mul(u64 a, u64 b) {
        return modulo(u128(a) * b);
    }
};

/**
 * @brief Fast Division
 */