---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Algorithm/wildcardpatternmatching.hpp
    title: Wildcard Pattern Matching
  - icon: ':question:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariate.hpp
    title: Multivariate Convolution
  - icon: ':warning:'
    path: Math/bigint.hpp
    title: Big Integer(Float)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod.test.cpp
    title: Verify/LC_convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_1000000007.test.cpp
    title: Verify/LC_convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_exp_of_formal_power_series.test.cpp
    title: Verify/LC_exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_inv_of_formal_power_series.test.cpp
    title: Verify/LC_inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_log_of_formal_power_series.test.cpp
    title: Verify/LC_log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_many_factorials.test.cpp
    title: Verify/LC_many_factorials.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multipoint_evaluation.test.cpp
    title: Verify/LC_multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution.test.cpp
    title: Verify/LC_multivariate_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  - icon: ':x:'
    path: Verify/LC_partition_function.test.cpp
    title: Verify/LC_partition_function.test.cpp
  - icon: ':x:'
    path: Verify/LC_polynomial_interpolation.test.cpp
    title: Verify/LC_polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: Verify/LC_polynomial_taylor_shift.test.cpp
    title: Verify/LC_polynomial_taylor_shift.test.cpp
  - icon: ':x:'
    path: Verify/LC_pow_of_formal_power_series.test.cpp
    title: Verify/LC_pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: Verify/LC_product_of_polynomial_sequence.test.cpp
    title: Verify/LC_product_of_polynomial_sequence.test.cpp
  - icon: ':x:'
    path: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
    title: Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: Verify/LC_sparse_matrix_det.test.cpp
    title: Verify/LC_sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_first_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - icon: ':x:'
    path: Verify/LC_stirling_number_of_the_second_kind.test.cpp
    title: Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1080.test.cpp
    title: Verify/YUKI_1080.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_2097.test.cpp
    title: Verify/YUKI_2097.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Number Theoretic Transform
    links: []
  bundledCode: "#line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate <typename T> struct\
    \ NTT {\r\n    static constexpr int rank2 = __builtin_ctzll(T::get_mod() - 1);\r\
    \n    std::array<T, rank2 + 1> root;  // root[i]^(2^i) == 1\r\n    std::array<T,\
    \ rank2 + 1> iroot; // root[i] * iroot[i] == 1\r\n\r\n    std::array<T, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\r\n    std::array<T, std::max(0, rank2 - 2 + 1)> irate2;\r\
    \n\r\n    std::array<T, std::max(0, rank2 - 3 + 1)> rate3;\r\n    std::array<T,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\r\n\r\n    NTT() {\r\n        T g = 2;\r\
    \n        while (g.pow((T::get_mod() - 1) >> 1) == 1) {\r\n            g += 1;\r\
    \n        }\r\n        root[rank2] = g.pow((T::get_mod() - 1) >> rank2);\r\n \
    \       iroot[rank2] = root[rank2].inv();\r\n        for (int i = rank2 - 1; i\
    \ >= 0; i--) {\r\n            root[i] = root[i + 1] * root[i + 1];\r\n       \
    \     iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n        }\r\n\r\n        {\r\n\
    \            T prod = 1, iprod = 1;\r\n            for (int i = 0; i <= rank2\
    \ - 2; i++) {\r\n                rate2[i] = root[i + 2] * prod;\r\n          \
    \      irate2[i] = iroot[i + 2] * iprod;\r\n                prod *= iroot[i +\
    \ 2];\r\n                iprod *= root[i + 2];\r\n            }\r\n        }\r\
    \n        {\r\n            T prod = 1, iprod = 1;\r\n            for (int i =\
    \ 0; i <= rank2 - 3; i++) {\r\n                rate3[i] = root[i + 3] * prod;\r\
    \n                irate3[i] = iroot[i + 3] * iprod;\r\n                prod *=\
    \ iroot[i + 3];\r\n                iprod *= root[i + 3];\r\n            }\r\n\
    \        }\r\n    }\r\n\r\n    void ntt(std::vector<T> &a, bool type = 0) {\r\n\
    \        int n = int(a.size());\r\n        int h = __builtin_ctzll((unsigned int)n);\r\
    \n        a.resize(1 << h);\r\n\r\n        if (type) {\r\n            int len\
    \ = h; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n            while\
    \ (len) {\r\n                if (len == 1) {\r\n                    int p = 1\
    \ << (h - len);\r\n                    T irot = 1;\r\n                    for\
    \ (int s = 0; s < (1 << (len - 1)); s++) {\r\n                        int offset\
    \ = s << (h - len + 1);\r\n                        for (int i = 0; i < p; i++)\
    \ {\r\n                            auto l = a[i + offset];\r\n               \
    \             auto r = a[i + offset + p];\r\n                            a[i +\
    \ offset] = l + r;\r\n                            a[i + offset + p] =\r\n    \
    \                            (unsigned long long)(T::get_mod() + l.v - r.v) *\r\
    \n                                irot.v;\r\n                            ;\r\n\
    \                        }\r\n                        if (s + 1 != (1 << (len\
    \ - 1)))\r\n                            irot *= irate2[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len--;\r\n      \
    \          } else {\r\n                    // 4-base\r\n                    int\
    \ p = 1 << (h - len);\r\n                    T irot = 1, iimag = iroot[2];\r\n\
    \                    for (int s = 0; s < (1 << (len - 2)); s++) {\r\n        \
    \                T irot2 = irot * irot;\r\n                        T irot3 = irot2\
    \ * irot;\r\n                        int offset = s << (h - len + 2);\r\n    \
    \                    for (int i = 0; i < p; i++) {\r\n                       \
    \     auto a0 = 1ULL * a[i + offset + 0 * p].v;\r\n                          \
    \  auto a1 = 1ULL * a[i + offset + 1 * p].v;\r\n                            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].v;\r\n                            auto a3\
    \ = 1ULL * a[i + offset + 3 * p].v;\r\n\r\n                            auto a2na3iimag\
    \ =\r\n                                1ULL * T((T::get_mod() + a2 - a3) * iimag.v).v;\r\
    \n\r\n                            a[i + offset] = a0 + a1 + a2 + a3;\r\n     \
    \                       a[i + offset + 1 * p] =\r\n                          \
    \      (a0 + (T::get_mod() - a1) + a2na3iimag) *\r\n                         \
    \       irot.v;\r\n                            a[i + offset + 2 * p] =\r\n   \
    \                             (a0 + a1 + (T::get_mod() - a2) +\r\n           \
    \                      (T::get_mod() - a3)) *\r\n                            \
    \    irot2.v;\r\n                            a[i + offset + 3 * p] =\r\n     \
    \                           (a0 + (T::get_mod() - a1) +\r\n                  \
    \               (T::get_mod() - a2na3iimag)) *\r\n                           \
    \     irot3.v;\r\n                        }\r\n                        if (s +\
    \ 1 != (1 << (len - 2)))\r\n                            irot *= irate3[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len -= 2;\r\n   \
    \             }\r\n            }\r\n            T e = T(n).inv();\r\n        \
    \    for (auto &x : a)\r\n                x *= e;\r\n        } else {\r\n    \
    \        int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n\
    \            while (len < h) {\r\n                if (h - len == 1) {\r\n    \
    \                int p = 1 << (h - len - 1);\r\n                    T rot = 1;\r\
    \n                    for (int s = 0; s < (1 << len); s++) {\r\n             \
    \           int offset = s << (h - len);\r\n                        for (int i\
    \ = 0; i < p; i++) {\r\n                            auto l = a[i + offset];\r\n\
    \                            auto r = a[i + offset + p] * rot;\r\n           \
    \                 a[i + offset] = l + r;\r\n                            a[i +\
    \ offset + p] = l - r;\r\n                        }\r\n                      \
    \  if (s + 1 != (1 << len))\r\n                            rot *= rate2[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len++;\r\n      \
    \          } else {\r\n                    // 4-base\r\n                    int\
    \ p = 1 << (h - len - 2);\r\n                    T rot = 1, imag = root[2];\r\n\
    \                    for (int s = 0; s < (1 << len); s++) {\r\n              \
    \          T rot2 = rot * rot;\r\n                        T rot3 = rot2 * rot;\r\
    \n                        int offset = s << (h - len);\r\n                   \
    \     for (int i = 0; i < p; i++) {\r\n                            auto mod2 =\
    \ 1ULL * T::get_mod() * T::get_mod();\r\n                            auto a0 =\
    \ 1ULL * a[i + offset].v;\r\n                            auto a1 = 1ULL * a[i\
    \ + offset + p].v * rot.v;\r\n                            auto a2 = 1ULL * a[i\
    \ + offset + 2 * p].v * rot2.v;\r\n                            auto a3 = 1ULL\
    \ * a[i + offset + 3 * p].v * rot3.v;\r\n                            auto a1na3imag\
    \ =\r\n                                1ULL * T(a1 + mod2 - a3).v * imag.v;\r\n\
    \                            auto na2 = mod2 - a2;\r\n                       \
    \     a[i + offset] = a0 + a2 + a1 + a3;\r\n                            a[i +\
    \ offset + 1 * p] =\r\n                                a0 + a2 + (2 * mod2 - (a1\
    \ + a3));\r\n                            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n                            a[i + offset + 3 * p] =\r\n                    \
    \            a0 + na2 + (mod2 - a1na3imag);\r\n                        }\r\n \
    \                       if (s + 1 != (1 << len))\r\n                         \
    \   rot *= rate3[__builtin_ctzll(~(unsigned int)(s))];\r\n                   \
    \ }\r\n                    len += 2;\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n    vector<T> mult(const vector<T> &a, const vector<T>\
    \ &b) {\r\n        if (a.empty() or b.empty())\r\n            return vector<T>();\r\
    \n        int as = a.size(), bs = b.size();\r\n        int n = as + bs - 1;\r\n\
    \        if (as <= 30 or bs <= 30) {\r\n            if (as > 30)\r\n         \
    \       return mult(b, a);\r\n            vector<T> res(n);\r\n            rep(i,\
    \ 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];\r\n            return res;\r\
    \n        }\r\n        int m = 1;\r\n        while (m < n)\r\n            m <<=\
    \ 1;\r\n        vector<T> res(m);\r\n        rep(i, 0, as) res[i] = a[i];\r\n\
    \        ntt(res);\r\n        if (a == b)\r\n            rep(i, 0, m) res[i] *=\
    \ res[i];\r\n        else {\r\n            vector<T> c(m);\r\n            rep(i,\
    \ 0, bs) c[i] = b[i];\r\n            ntt(c);\r\n            rep(i, 0, m) res[i]\
    \ *= c[i];\r\n        }\r\n        ntt(res, 1);\r\n        res.resize(n);\r\n\
    \        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> struct NTT {\r\n    static constexpr\
    \ int rank2 = __builtin_ctzll(T::get_mod() - 1);\r\n    std::array<T, rank2 +\
    \ 1> root;  // root[i]^(2^i) == 1\r\n    std::array<T, rank2 + 1> iroot; // root[i]\
    \ * iroot[i] == 1\r\n\r\n    std::array<T, std::max(0, rank2 - 2 + 1)> rate2;\r\
    \n    std::array<T, std::max(0, rank2 - 2 + 1)> irate2;\r\n\r\n    std::array<T,\
    \ std::max(0, rank2 - 3 + 1)> rate3;\r\n    std::array<T, std::max(0, rank2 -\
    \ 3 + 1)> irate3;\r\n\r\n    NTT() {\r\n        T g = 2;\r\n        while (g.pow((T::get_mod()\
    \ - 1) >> 1) == 1) {\r\n            g += 1;\r\n        }\r\n        root[rank2]\
    \ = g.pow((T::get_mod() - 1) >> rank2);\r\n        iroot[rank2] = root[rank2].inv();\r\
    \n        for (int i = rank2 - 1; i >= 0; i--) {\r\n            root[i] = root[i\
    \ + 1] * root[i + 1];\r\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\r\
    \n        }\r\n\r\n        {\r\n            T prod = 1, iprod = 1;\r\n       \
    \     for (int i = 0; i <= rank2 - 2; i++) {\r\n                rate2[i] = root[i\
    \ + 2] * prod;\r\n                irate2[i] = iroot[i + 2] * iprod;\r\n      \
    \          prod *= iroot[i + 2];\r\n                iprod *= root[i + 2];\r\n\
    \            }\r\n        }\r\n        {\r\n            T prod = 1, iprod = 1;\r\
    \n            for (int i = 0; i <= rank2 - 3; i++) {\r\n                rate3[i]\
    \ = root[i + 3] * prod;\r\n                irate3[i] = iroot[i + 3] * iprod;\r\
    \n                prod *= iroot[i + 3];\r\n                iprod *= root[i + 3];\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    void ntt(std::vector<T> &a, bool\
    \ type = 0) {\r\n        int n = int(a.size());\r\n        int h = __builtin_ctzll((unsigned\
    \ int)n);\r\n        a.resize(1 << h);\r\n\r\n        if (type) {\r\n        \
    \    int len = h; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n   \
    \         while (len) {\r\n                if (len == 1) {\r\n               \
    \     int p = 1 << (h - len);\r\n                    T irot = 1;\r\n         \
    \           for (int s = 0; s < (1 << (len - 1)); s++) {\r\n                 \
    \       int offset = s << (h - len + 1);\r\n                        for (int i\
    \ = 0; i < p; i++) {\r\n                            auto l = a[i + offset];\r\n\
    \                            auto r = a[i + offset + p];\r\n                 \
    \           a[i + offset] = l + r;\r\n                            a[i + offset\
    \ + p] =\r\n                                (unsigned long long)(T::get_mod()\
    \ + l.v - r.v) *\r\n                                irot.v;\r\n              \
    \              ;\r\n                        }\r\n                        if (s\
    \ + 1 != (1 << (len - 1)))\r\n                            irot *= irate2[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len--;\r\n      \
    \          } else {\r\n                    // 4-base\r\n                    int\
    \ p = 1 << (h - len);\r\n                    T irot = 1, iimag = iroot[2];\r\n\
    \                    for (int s = 0; s < (1 << (len - 2)); s++) {\r\n        \
    \                T irot2 = irot * irot;\r\n                        T irot3 = irot2\
    \ * irot;\r\n                        int offset = s << (h - len + 2);\r\n    \
    \                    for (int i = 0; i < p; i++) {\r\n                       \
    \     auto a0 = 1ULL * a[i + offset + 0 * p].v;\r\n                          \
    \  auto a1 = 1ULL * a[i + offset + 1 * p].v;\r\n                            auto\
    \ a2 = 1ULL * a[i + offset + 2 * p].v;\r\n                            auto a3\
    \ = 1ULL * a[i + offset + 3 * p].v;\r\n\r\n                            auto a2na3iimag\
    \ =\r\n                                1ULL * T((T::get_mod() + a2 - a3) * iimag.v).v;\r\
    \n\r\n                            a[i + offset] = a0 + a1 + a2 + a3;\r\n     \
    \                       a[i + offset + 1 * p] =\r\n                          \
    \      (a0 + (T::get_mod() - a1) + a2na3iimag) *\r\n                         \
    \       irot.v;\r\n                            a[i + offset + 2 * p] =\r\n   \
    \                             (a0 + a1 + (T::get_mod() - a2) +\r\n           \
    \                      (T::get_mod() - a3)) *\r\n                            \
    \    irot2.v;\r\n                            a[i + offset + 3 * p] =\r\n     \
    \                           (a0 + (T::get_mod() - a1) +\r\n                  \
    \               (T::get_mod() - a2na3iimag)) *\r\n                           \
    \     irot3.v;\r\n                        }\r\n                        if (s +\
    \ 1 != (1 << (len - 2)))\r\n                            irot *= irate3[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len -= 2;\r\n   \
    \             }\r\n            }\r\n            T e = T(n).inv();\r\n        \
    \    for (auto &x : a)\r\n                x *= e;\r\n        } else {\r\n    \
    \        int len = 0; // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\r\n\
    \            while (len < h) {\r\n                if (h - len == 1) {\r\n    \
    \                int p = 1 << (h - len - 1);\r\n                    T rot = 1;\r\
    \n                    for (int s = 0; s < (1 << len); s++) {\r\n             \
    \           int offset = s << (h - len);\r\n                        for (int i\
    \ = 0; i < p; i++) {\r\n                            auto l = a[i + offset];\r\n\
    \                            auto r = a[i + offset + p] * rot;\r\n           \
    \                 a[i + offset] = l + r;\r\n                            a[i +\
    \ offset + p] = l - r;\r\n                        }\r\n                      \
    \  if (s + 1 != (1 << len))\r\n                            rot *= rate2[__builtin_ctzll(~(unsigned\
    \ int)(s))];\r\n                    }\r\n                    len++;\r\n      \
    \          } else {\r\n                    // 4-base\r\n                    int\
    \ p = 1 << (h - len - 2);\r\n                    T rot = 1, imag = root[2];\r\n\
    \                    for (int s = 0; s < (1 << len); s++) {\r\n              \
    \          T rot2 = rot * rot;\r\n                        T rot3 = rot2 * rot;\r\
    \n                        int offset = s << (h - len);\r\n                   \
    \     for (int i = 0; i < p; i++) {\r\n                            auto mod2 =\
    \ 1ULL * T::get_mod() * T::get_mod();\r\n                            auto a0 =\
    \ 1ULL * a[i + offset].v;\r\n                            auto a1 = 1ULL * a[i\
    \ + offset + p].v * rot.v;\r\n                            auto a2 = 1ULL * a[i\
    \ + offset + 2 * p].v * rot2.v;\r\n                            auto a3 = 1ULL\
    \ * a[i + offset + 3 * p].v * rot3.v;\r\n                            auto a1na3imag\
    \ =\r\n                                1ULL * T(a1 + mod2 - a3).v * imag.v;\r\n\
    \                            auto na2 = mod2 - a2;\r\n                       \
    \     a[i + offset] = a0 + a2 + a1 + a3;\r\n                            a[i +\
    \ offset + 1 * p] =\r\n                                a0 + a2 + (2 * mod2 - (a1\
    \ + a3));\r\n                            a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\r\
    \n                            a[i + offset + 3 * p] =\r\n                    \
    \            a0 + na2 + (mod2 - a1na3imag);\r\n                        }\r\n \
    \                       if (s + 1 != (1 << len))\r\n                         \
    \   rot *= rate3[__builtin_ctzll(~(unsigned int)(s))];\r\n                   \
    \ }\r\n                    len += 2;\r\n                }\r\n            }\r\n\
    \        }\r\n    }\r\n    vector<T> mult(const vector<T> &a, const vector<T>\
    \ &b) {\r\n        if (a.empty() or b.empty())\r\n            return vector<T>();\r\
    \n        int as = a.size(), bs = b.size();\r\n        int n = as + bs - 1;\r\n\
    \        if (as <= 30 or bs <= 30) {\r\n            if (as > 30)\r\n         \
    \       return mult(b, a);\r\n            vector<T> res(n);\r\n            rep(i,\
    \ 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];\r\n            return res;\r\
    \n        }\r\n        int m = 1;\r\n        while (m < n)\r\n            m <<=\
    \ 1;\r\n        vector<T> res(m);\r\n        rep(i, 0, as) res[i] = a[i];\r\n\
    \        ntt(res);\r\n        if (a == b)\r\n            rep(i, 0, m) res[i] *=\
    \ res[i];\r\n        else {\r\n            vector<T> c(m);\r\n            rep(i,\
    \ 0, bs) c[i] = b[i];\r\n            ntt(c);\r\n            rep(i, 0, m) res[i]\
    \ *= c[i];\r\n        }\r\n        ntt(res, 1);\r\n        res.resize(n);\r\n\
    \        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/ntt.hpp
  requiredBy:
  - Convolution/arbitrary.hpp
  - Convolution/multivariate.hpp
  - Algorithm/wildcardpatternmatching.hpp
  - Math/bigint.hpp
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_product_of_polynomial_sequence.test.cpp
  - Verify/LC_log_of_formal_power_series.test.cpp
  - Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/LC_multivariate_convolution.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/YUKI_2097.test.cpp
  - Verify/LC_exp_of_formal_power_series.test.cpp
  - Verify/LC_convolution_mod_1000000007.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - Verify/LC_multipoint_evaluation.test.cpp
  - Verify/LC_polynomial_interpolation.test.cpp
  - Verify/LC_polynomial_taylor_shift.test.cpp
  - Verify/LC_pow_of_formal_power_series.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/LC_convolution_mod.test.cpp
  - Verify/LC_many_factorials.test.cpp
  - Verify/YUKI_1112.test.cpp
  - Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - Verify/YUKI_1080.test.cpp
  - Verify/LC_bernoulli_number.test.cpp
  - Verify/LC_sparse_matrix_det.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_convolution_mod_2.test.cpp
  - Verify/LC_inv_of_formal_power_series.test.cpp
documentation_of: Convolution/ntt.hpp
layout: document
redirect_from:
- /library/Convolution/ntt.hpp
- /library/Convolution/ntt.hpp.html
title: Number Theoretic Transform
---
