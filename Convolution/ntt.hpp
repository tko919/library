#pragma once
#include "Math/primitive.hpp"

template <typename T> struct NTT {
    static constexpr unsigned mod = T::get_mod();
    static constexpr unsigned long long mod2 = 1ULL * mod * mod;
    static constexpr int rank2 = __builtin_ctzll(T::get_mod() - 1);
    std::array<T, rank2 + 1> root;  // root[i]^(2^i) == 1
    std::array<T, rank2 + 1> iroot; // root[i] * iroot[i] == 1
    std::array<T, rank2 + 1> inv_size; // inv_size[i] == 1 / 2^i

    std::array<T, std::max(0, rank2 - 2 + 1)> rate2;
    std::array<T, std::max(0, rank2 - 2 + 1)> irate2;

    std::array<T, std::max(0, rank2 - 3 + 1)> rate3;
    std::array<T, std::max(0, rank2 - 3 + 1)> irate3;

    NTT() {
        static const ll primitive_root = getPrimitiveRoot(T::get_mod());
        T g = primitive_root;
        root[rank2] = g.pow((T::get_mod() - 1) >> rank2);
        iroot[rank2] = root[rank2].inv();
        for (int i = rank2 - 1; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }
        inv_size[0] = 1;
        const T inv2 = T(2).inv();
        for (int i = 1; i <= rank2; i++)
            inv_size[i] = inv_size[i - 1] * inv2;

        {
            T prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 2; i++) {
                rate2[i] = root[i + 2] * prod;
                irate2[i] = iroot[i + 2] * iprod;
                prod *= iroot[i + 2];
                iprod *= root[i + 2];
            }
        }
        {
            T prod = 1, iprod = 1;
            for (int i = 0; i <= rank2 - 3; i++) {
                rate3[i] = root[i + 3] * prod;
                irate3[i] = iroot[i + 3] * iprod;
                prod *= iroot[i + 3];
                iprod *= root[i + 3];
            }
        }
    }

    void ntt(std::vector<T> &a, bool type = 0) {
        int n = int(a.size());
        int h = __builtin_ctzll((unsigned int)n);
        a.resize(1 << h);

        if (type) {
            int len = h; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
            while (len) {
                if (len == 1) {
                    int p = 1 << (h - len);
                    T irot = 1;
                    for (int s = 0; s < (1 << (len - 1)); s++) {
                        int offset = s << (h - len + 1);
                        for (int i = 0; i < p; i++) {
                            unsigned l = a[i + offset].v;
                            unsigned r = a[i + offset + p].v;
                            unsigned sum = l + r;
                            a[i + offset].v = sum >= mod ? sum - mod : sum;
                            a[i + offset + p].v =
                                1ULL * (mod + l - r) * irot.v % mod;
                        }
                        if (s + 1 != (1 << (len - 1)))
                            irot *= irate2[__builtin_ctzll(~(unsigned int)(s))];
                    }
                    len--;
                } else {
                    // 4-base
                    int p = 1 << (h - len);
                    T irot = 1, iimag = iroot[2];
                    for (int s = 0; s < (1 << (len - 2)); s++) {
                        T irot2 = irot * irot;
                        T irot3 = irot2 * irot;
                        int offset = s << (h - len + 2);
                        for (int i = 0; i < p; i++) {
                            auto a0 = 1ULL * a[i + offset + 0 * p].v;
                            auto a1 = 1ULL * a[i + offset + 1 * p].v;
                            auto a2 = 1ULL * a[i + offset + 2 * p].v;
                            auto a3 = 1ULL * a[i + offset + 3 * p].v;

                            auto a2na3iimag =
                                (mod + a2 - a3) * iimag.v % mod;

                            a[i + offset].v = (a0 + a1 + a2 + a3) % mod;
                            a[i + offset + 1 * p].v =
                                (a0 + mod - a1 + a2na3iimag) * irot.v % mod;
                            a[i + offset + 2 * p].v =
                                (a0 + a1 + 2ULL * mod - a2 - a3) * irot2.v %
                                mod;
                            a[i + offset + 3 * p].v =
                                (a0 + mod - a1 + mod - a2na3iimag) * irot3.v %
                                mod;
                        }
                        if (s + 1 != (1 << (len - 2)))
                            irot *= irate3[__builtin_ctzll(~(unsigned int)(s))];
                    }
                    len -= 2;
                }
            }
            const T e = inv_size[h];
            for (auto &x : a)
                x.v = 1ULL * x.v * e.v % mod;
        } else {
            int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
            while (len < h) {
                if (h - len == 1) {
                    int p = 1 << (h - len - 1);
                    T rot = 1;
                    for (int s = 0; s < (1 << len); s++) {
                        int offset = s << (h - len);
                        for (int i = 0; i < p; i++) {
                            unsigned l = a[i + offset].v;
                            unsigned r =
                                1ULL * a[i + offset + p].v * rot.v % mod;
                            unsigned sum = l + r;
                            a[i + offset].v = sum >= mod ? sum - mod : sum;
                            a[i + offset + p].v =
                                l >= r ? l - r : l + mod - r;
                        }
                        if (s + 1 != (1 << len))
                            rot *= rate2[__builtin_ctzll(~(unsigned int)(s))];
                    }
                    len++;
                } else {
                    // 4-base
                    int p = 1 << (h - len - 2);
                    T rot = 1, imag = root[2];
                    for (int s = 0; s < (1 << len); s++) {
                        T rot2 = rot * rot;
                        T rot3 = rot2 * rot;
                        int offset = s << (h - len);
                        for (int i = 0; i < p; i++) {
                            auto a0 = 1ULL * a[i + offset].v;
                            auto a1 = 1ULL * a[i + offset + p].v * rot.v;
                            auto a2 = 1ULL * a[i + offset + 2 * p].v * rot2.v;
                            auto a3 = 1ULL * a[i + offset + 3 * p].v * rot3.v;
                            auto a1na3imag =
                                ((a1 + mod2 - a3) % mod) * imag.v;
                            auto na2 = mod2 - a2;
                            a[i + offset].v = (a0 + a2 + a1 + a3) % mod;
                            a[i + offset + 1 * p].v =
                                (a0 + a2 + 2 * mod2 - a1 - a3) % mod;
                            a[i + offset + 2 * p].v =
                                (a0 + na2 + a1na3imag) % mod;
                            a[i + offset + 3 * p].v =
                                (a0 + na2 + mod2 - a1na3imag) % mod;
                        }
                        if (s + 1 != (1 << len))
                            rot *= rate3[__builtin_ctzll(~(unsigned int)(s))];
                    }
                    len += 2;
                }
            }
        }
    }
    // a contains the NTT of a polynomial at the n-th roots of unity.
    // Extend it to the NTT at the 2n-th roots while preserving the first half.
    void doubling(std::vector<T> &a) {
        const int n = int(a.size());
        assert(n and (n & (n - 1)) == 0);
        assert(2LL * n <= (1LL << rank2));

        std::vector<T> b(a);
        ntt(b, 1);

        // b(x) -> b(root[log2(2n)] * x) gives the values at odd powers
        // of the primitive 2n-th root.  The original values are the even
        // powers and occupy the first half in this NTT's ordering.
        T zeta = root[__builtin_ctzll((unsigned int)n) + 1], pw = 1;
        for (auto &x : b) {
            x *= pw;
            pw *= zeta;
        }
        ntt(b, 0);
        a.insert(a.end(), b.begin(), b.end());
    }
    vector<T> mult(const vector<T> &a, const vector<T> &b) {
        if (a.empty() or b.empty())
            return vector<T>();
        int as = a.size(), bs = b.size();
        int n = as + bs - 1;
        assert(n <= (1 << rank2));
        if (as <= 30 or bs <= 30) {
            if (as > 30)
                return mult(b, a);
            vector<T> res(n);
            rep(i, 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];
            return res;
        }
        int m = 1;
        while (m < n)
            m <<= 1;
        vector<T> res(m);
        rep(i, 0, as) res[i] = a[i];
        ntt(res);
        if (a == b)
            rep(i, 0, m) res[i] *= res[i];
        else {
            vector<T> c(m);
            rep(i, 0, bs) c[i] = b[i];
            ntt(c);
            rep(i, 0, m) res[i] *= c[i];
        }
        ntt(res, 1);
        res.resize(n);
        return res;
    }
};

/**
 * @brief Number Theoretic Transform
 */
