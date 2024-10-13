---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution.test.cpp
    title: Verify/LC_multivariate_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Multivariate Convolution
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
    \n */\n#line 3 \"Convolution/multivariate.hpp\"\n\r\ntemplate<typename T,void\
    \ (*ntt)(vector<T>&,bool)>vector<T> MultivariateConvolution\r\n    (const vector<T>&\
    \ f,const vector<T>& g,vector<int>& a){\r\n    int n=f.size(),k=a.size(),m=1<<__lg(4*n-1);\r\
    \n    if(k==0)return vector<T>({f[0]*g[0]});\r\n    \r\n    vector<int> chi(n);\r\
    \n    rep(x,0,n){\r\n        int t=x;\r\n        rep(i,0,k-1){\r\n           \
    \ t/=a[i];\r\n            chi[x]+=t;\r\n        }\r\n        chi[x]%=k;\r\n  \
    \  }\r\n\r\n    vector F(k,vector<T>(m)),G(k,vector<T>(m));\r\n    rep(i,0,n){\r\
    \n        F[chi[i]][i]=f[i];\r\n        G[chi[i]][i]=g[i];\r\n    }\r\n\r\n  \
    \  for(auto& v:F)ntt(v,0);\r\n    for(auto& v:G)ntt(v,0);\r\n    rep(x,0,m){\r\
    \n        vector<T> tmp(k);\r\n        rep(i,0,k)rep(j,0,k){\r\n            tmp[(i+j)%k]+=F[i][x]*G[j][x];\r\
    \n        }\r\n        rep(i,0,k)F[i][x]=tmp[i];\r\n    }\r\n    for(auto& v:F)ntt(v,1);\r\
    \n    vector<T> res(n);\r\n    rep(i,0,n)res[i]=F[chi[i]][i];\r\n    return res;\r\
    \n}\r\n\r\n/**\r\n * @brief Multivariate Convolution\r\n */\n"
  code: "#pragma once\r\n#include \"Convolution/ntt.hpp\"\r\n\r\ntemplate<typename\
    \ T,void (*ntt)(vector<T>&,bool)>vector<T> MultivariateConvolution\r\n    (const\
    \ vector<T>& f,const vector<T>& g,vector<int>& a){\r\n    int n=f.size(),k=a.size(),m=1<<__lg(4*n-1);\r\
    \n    if(k==0)return vector<T>({f[0]*g[0]});\r\n    \r\n    vector<int> chi(n);\r\
    \n    rep(x,0,n){\r\n        int t=x;\r\n        rep(i,0,k-1){\r\n           \
    \ t/=a[i];\r\n            chi[x]+=t;\r\n        }\r\n        chi[x]%=k;\r\n  \
    \  }\r\n\r\n    vector F(k,vector<T>(m)),G(k,vector<T>(m));\r\n    rep(i,0,n){\r\
    \n        F[chi[i]][i]=f[i];\r\n        G[chi[i]][i]=g[i];\r\n    }\r\n\r\n  \
    \  for(auto& v:F)ntt(v,0);\r\n    for(auto& v:G)ntt(v,0);\r\n    rep(x,0,m){\r\
    \n        vector<T> tmp(k);\r\n        rep(i,0,k)rep(j,0,k){\r\n            tmp[(i+j)%k]+=F[i][x]*G[j][x];\r\
    \n        }\r\n        rep(i,0,k)F[i][x]=tmp[i];\r\n    }\r\n    for(auto& v:F)ntt(v,1);\r\
    \n    vector<T> res(n);\r\n    rep(i,0,n)res[i]=F[chi[i]][i];\r\n    return res;\r\
    \n}\r\n\r\n/**\r\n * @brief Multivariate Convolution\r\n */"
  dependsOn:
  - Convolution/ntt.hpp
  isVerificationFile: false
  path: Convolution/multivariate.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_multivariate_convolution.test.cpp
documentation_of: Convolution/multivariate.hpp
layout: document
redirect_from:
- /library/Convolution/multivariate.hpp
- /library/Convolution/multivariate.hpp.html
title: Multivariate Convolution
---
