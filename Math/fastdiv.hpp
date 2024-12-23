#pragma once

struct FastDiv {
    using u64 = unsigned ll;
    using u128 = __uint128_t;
    u128 mod, mh, ml;
    explicit FastDiv(u64 mod = 1) : mod(mod) {
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