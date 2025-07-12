---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: FPS/sumofRationals.hpp
    title: Sum of Rationals
  - icon: ':heavy_check_mark:'
    path: Math/comb.hpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: $f(\exp(x))$
    links: []
  bundledCode: "#line 2 \"FPS/sumofRationals.hpp\"\n\ntemplate<typename T>pair<Poly<T>,Poly<T>>\
    \ SumOfRationals(vector<pair<Poly<T>,Poly<T>>>& fs){\n    using Ratio=pair<Poly<T>,Poly<T>>;\n\
    \    if(fs.empty())return {Poly<T>({T(1)}),Poly<T>({T(1)})};\n    sort(ALL(fs),[&](Ratio&\
    \ a,Ratio& b){return a.first.size()+a.second.size()<b.first.size()+b.second.size();});\n\
    \    deque<Ratio> deq;\n    for(auto& f:fs)deq.push_back(f);\n    while(deq.size()>1){\n\
    \        auto [f,g]=deq[0];\n        auto [p,q]=deq[1];\n        deq.push_back({f*q+g*p,g*q});\n\
    \        deq.pop_front();\n        deq.pop_front();\n    }\n    return deq[0];\n\
    }\n\n/**\n * @brief Sum of Rationals\n*/\n#line 2 \"Math/comb.hpp\"\n\ntemplate\
    \ <typename T> T Inv(ll n) {\n    static int md;\n    static vector<T> buf({0,\
    \ 1});\n    if (md != T::get_mod()) {\n        md = T::get_mod();\n        buf\
    \ = vector<T>({0, 1});\n    }\n    assert(n > 0);\n    n %= md;\n    while (SZ(buf)\
    \ <= n) {\n        int k = SZ(buf), q = (md + k - 1) / k;\n        buf.push_back(buf[k\
    \ * q - md] * q);\n    }\n    return buf[n];\n}\n\ntemplate <typename T> T Fact(ll\
    \ n, bool inv = 0) {\n    static int md;\n    static vector<T> buf({1, 1}), ibuf({1,\
    \ 1});\n    if (md != T::get_mod()) {\n        md = T::get_mod();\n        buf\
    \ = ibuf = vector<T>({1, 1});\n    }\n    assert(n >= 0 and n < md);\n    while\
    \ (SZ(buf) <= n) {\n        buf.push_back(buf.back() * SZ(buf));\n        ibuf.push_back(ibuf.back()\
    \ * Inv<T>(SZ(ibuf)));\n    }\n    return inv ? ibuf[n] : buf[n];\n}\n\ntemplate\
    \ <typename T> T nPr(int n, int r, bool inv = 0) {\n    if (n < 0 || n < r ||\
    \ r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^\
    \ 1);\n}\ntemplate <typename T> T nCr(int n, int r, bool inv = 0) {\n    if (n\
    \ < 0 || n < r || r < 0)\n        return 0;\n    return Fact<T>(n, inv) * Fact<T>(r,\
    \ inv ^ 1) * Fact<T>(n - r, inv ^ 1);\n}\n// sum = n, r tuples\ntemplate <typename\
    \ T> T nHr(int n, int r, bool inv = 0) {\n    return nCr<T>(n + r - 1, r - 1,\
    \ inv);\n}\n// sum = n, a nonzero tuples and b tuples\ntemplate <typename T> T\
    \ choose(int n, int a, int b) {\n    if (n == 0)\n        return !a;\n    return\
    \ nCr<T>(n + b - 1, a + b - 1);\n}\n\n/**\n * @brief Combination\n */\n#line 4\
    \ \"FPS/compexp.hpp\"\n\ntemplate <typename T> Poly<T> CompExp(Poly<T> &f, int\
    \ m) {\n    int n = f.size();\n    vector<pair<Poly<T>, Poly<T>>> fs;\n    rep(i,\
    \ 0, n) {\n        Poly<T> p({Fp(f[i])});\n        Poly<T> q({Fp(1), Fp(-i)});\n\
    \        fs.push_back({p, q});\n    }\n    auto [p, q] = SumOfRationals(fs);\n\
    \    q.resize(m);\n    p *= q.inv();\n    p.resize(m);\n    rep(i, 0, m) p[i]\
    \ *= Fact<T>(i, 1);\n    return p;\n}\n\n/**\n * @brief $f(\\exp(x))$\n */\n"
  code: "#pragma once\n#include \"FPS/sumofRationals.hpp\"\n#include \"Math/comb.hpp\"\
    \n\ntemplate <typename T> Poly<T> CompExp(Poly<T> &f, int m) {\n    int n = f.size();\n\
    \    vector<pair<Poly<T>, Poly<T>>> fs;\n    rep(i, 0, n) {\n        Poly<T> p({Fp(f[i])});\n\
    \        Poly<T> q({Fp(1), Fp(-i)});\n        fs.push_back({p, q});\n    }\n \
    \   auto [p, q] = SumOfRationals(fs);\n    q.resize(m);\n    p *= q.inv();\n \
    \   p.resize(m);\n    rep(i, 0, m) p[i] *= Fact<T>(i, 1);\n    return p;\n}\n\n\
    /**\n * @brief $f(\\exp(x))$\n */"
  dependsOn:
  - FPS/sumofRationals.hpp
  - Math/comb.hpp
  isVerificationFile: false
  path: FPS/compexp.hpp
  requiredBy: []
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/compexp.hpp
layout: document
redirect_from:
- /library/FPS/compexp.hpp
- /library/FPS/compexp.hpp.html
title: $f(\exp(x))$
---
