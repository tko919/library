#pragma once

template <typename T> struct NTT {
    static constexpr int rank2 = __builtin_ctzll(T::get_mod() - 1);
    std::array<T, rank2 + 1> root;  // root[i]^(2^i) == 1
    std::array<T, rank2 + 1> iroot; // root[i] * iroot[i] == 1

    std::array<T, std::max(0, rank2 - 2 + 1)> rate2;
    std::array<T, std::max(0, rank2 - 2 + 1)> irate2;

    std::array<T, std::max(0, rank2 - 3 + 1)> rate3;
    std::array<T, std::max(0, rank2 - 3 + 1)> irate3;

    NTT() {
        T g = 2;
        while (g.pow((T::get_mod() - 1) >> 1) == 1) {
            g += 1;
        }
        root[rank2] = g.pow((T::get_mod() - 1) >> rank2);
        iroot[rank2] = root[rank2].inv();
        for (int i = rank2 - 1; i >= 0; i--) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }

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
                            auto l = a[i + offset];
                            auto r = a[i + offset + p];
                            a[i + offset] = l + r;
                            a[i + offset + p] =
                                (unsigned long long)(T::get_mod() + l.v - r.v) *
                                irot.v;
                            ;
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
                                1ULL * T((T::get_mod() + a2 - a3) * iimag.v).v;

                            a[i + offset] = a0 + a1 + a2 + a3;
                            a[i + offset + 1 * p] =
                                (a0 + (T::get_mod() - a1) + a2na3iimag) *
                                irot.v;
                            a[i + offset + 2 * p] =
                                (a0 + a1 + (T::get_mod() - a2) +
                                 (T::get_mod() - a3)) *
                                irot2.v;
                            a[i + offset + 3 * p] =
                                (a0 + (T::get_mod() - a1) +
                                 (T::get_mod() - a2na3iimag)) *
                                irot3.v;
                        }
                        if (s + 1 != (1 << (len - 2)))
                            irot *= irate3[__builtin_ctzll(~(unsigned int)(s))];
                    }
                    len -= 2;
                }
            }
            T e = T(n).inv();
            for (auto &x : a)
                x *= e;
        } else {
            int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed
            while (len < h) {
                if (h - len == 1) {
                    int p = 1 << (h - len - 1);
                    T rot = 1;
                    for (int s = 0; s < (1 << len); s++) {
                        int offset = s << (h - len);
                        for (int i = 0; i < p; i++) {
                            auto l = a[i + offset];
                            auto r = a[i + offset + p] * rot;
                            a[i + offset] = l + r;
                            a[i + offset + p] = l - r;
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
                            auto mod2 = 1ULL * T::get_mod() * T::get_mod();
                            auto a0 = 1ULL * a[i + offset].v;
                            auto a1 = 1ULL * a[i + offset + p].v * rot.v;
                            auto a2 = 1ULL * a[i + offset + 2 * p].v * rot2.v;
                            auto a3 = 1ULL * a[i + offset + 3 * p].v * rot3.v;
                            auto a1na3imag =
                                1ULL * T(a1 + mod2 - a3).v * imag.v;
                            auto na2 = mod2 - a2;
                            a[i + offset] = a0 + a2 + a1 + a3;
                            a[i + offset + 1 * p] =
                                a0 + a2 + (2 * mod2 - (a1 + a3));
                            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;
                            a[i + offset + 3 * p] =
                                a0 + na2 + (mod2 - a1na3imag);
                        }
                        if (s + 1 != (1 << len))
                            rot *= rate3[__builtin_ctzll(~(unsigned int)(s))];
                    }
                    len += 2;
                }
            }
        }
    }
    vector<T> mult(const vector<T> &a, const vector<T> &b) {
        if (a.empty() or b.empty())
            return vector<T>();
        int as = a.size(), bs = b.size();
        int n = as + bs - 1;
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