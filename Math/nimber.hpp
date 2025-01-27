#pragma once

using ull = unsigned long long;
namespace NimberManager {
unsigned short E[65536 * 2 + 7], L[65536];
inline void __attribute__((constructor)) init() {
    unsigned short c[] = {10279, 15417, 35722, 52687, 44124, 62628,
                          15661, 5686,  3862,  1323,  334,   647,
                          61560, 20636, 4267,  8445};
    unsigned short d[65536];
    for (int i = 0; i < 16; ++i)
        for (int j = 1 << i; j--;)
            d[1 << i | j] = d[j] ^ c[i];
    E[0] = 1;
    for (int i = 0; i < 65534; ++i)
        E[i + 1] = d[E[i]];
    memcpy(E + 65535, E, 131070), memcpy(E + 131070, E, 14);
    for (int i = 0; i < 65535; ++i)
        L[E[i]] = i;
}
inline uint mul16(const uint &x, const uint &y) {
    return x && y ? E[uint(L[x]) + L[y]] : 0;
}
inline uint mul16_15(const uint &x, const uint &y) {
    return x && y ? E[uint(L[x]) + L[y] + 3] : 0;
}
inline uint mul15_15(const uint &x, const uint &y) {
    return x && y ? E[uint(L[x]) + L[y] + 6] : 0;
}
inline uint mul15(const uint &x) {
    return x ? E[L[x] + 3] : 0;
}
inline uint mul(const uint &x, const uint &y) {
    const uint xh = x >> 16, xl = x & 65535, yh = y >> 16, yl = y & 65535,
               c = mul16(xl, yl);
    return (ull)(mul16(xl ^ xh, yl ^ yh) ^ c) << 16 | (mul16_15(xh, yh) ^ c);
}
inline uint mul32_31(const uint &x, const uint &y) {
    const uint xh = x >> 16, xl = x & 65535, yh = y >> 16, yl = y & 65535,
               c = mul16_15(xl ^ xh, yl ^ yh);
    return (ull)(c ^ mul15_15(xh, yh)) << 16 | mul15(mul16_15(xl, yl) ^ c);
}
inline ull mul(const ull &x, const ull &y) {
    const uint xh = x >> 32, xl = x & UINT_MAX, yh = y >> 32, yl = y & UINT_MAX,
               c = mul(xl, yl);
    return (ull)(mul(xl ^ xh, yl ^ yh) ^ c) << 32 | (mul32_31(xh, yh) ^ c);
}
}; // namespace NimberManager
struct Nimber {
    ull v;
    Nimber(ull _v = 0) : v(_v) {}
    Nimber &operator+=(const Nimber &x) {
        v ^= x.v;
        return *this;
    }
    Nimber &operator-=(const Nimber &x) {
        v ^= x.v;
        return *this;
    }
    Nimber &operator*=(const Nimber &x) {
        v = NimberManager::mul(v, x.v);
        return *this;
    }
    Nimber operator+(const Nimber &x) const {
        return Nimber(*this) += x;
    }
    Nimber operator-(const Nimber &x) const {
        return Nimber(*this) -= x;
    }
    Nimber operator*(const Nimber &x) const {
        return Nimber(*this) *= x;
    }
    bool operator==(const Nimber &x) const {
        return v == x.v;
    }
    bool operator!=(const Nimber &x) const {
        return v != x.v;
    }
    Nimber pow(ull t) {
        Nimber res = 1, b = *this;
        while (t) {
            if (t & 1)
                res *= b;
            b *= b;
            t >>= 1;
        }
        return res;
    }
    Nimber inv() { // 暫定
        return pow(ull(-2));
    }
    friend istream &operator>>(istream &is, Nimber &x) {
        return is >> x.v;
    }
    friend ostream &operator<<(ostream &os, const Nimber &x) {
        return os << x.v;
    }
};

/**
 * @brief Nimber
 */