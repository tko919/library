---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: FPS/halfgcd.hpp
    title: Half GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Factorize Polynomial
    links: []
  bundledCode: "#line 2 \"FPS/halfgcd.hpp\"\n\nnamespace HalfGCD{\n    template<typename\
    \ T>using P=array<T,2>;\n    template<typename T>using Mat=array<T,4>;\n    template<typename\
    \ T>P<T> operator*(const Mat<T>& a,const P<T>& b){\n        P<T> ret={a[0]*b[0]+a[1]*b[1],a[2]*b[0]+a[3]*b[1]};\n\
    \        rep(i,0,2)ret[i].shrink();\n        return ret;\n    }\n    template<typename\
    \ T>Mat<T> operator*(const Mat<T>& a,const Mat<T>& b){\n        Mat<T> ret={a[0]*b[0]+a[1]*b[2],a[0]*b[1]+a[1]*b[3],\n\
    \            a[2]*b[0]+a[3]*b[2],a[2]*b[1]+a[3]*b[3]};\n        rep(i,0,4)ret[i].shrink();\n\
    \        return ret;\n    }\n    \n    template<typename T>Mat<T> HGCD(P<T> a){\n\
    \        int m=(SZ(a[0])+1)>>1;\n        if(SZ(a[1])<=m){\n            Mat<T>\
    \ ret;\n            ret[0]={1},ret[3]={1};\n            return ret;\n        }\n\
    \        auto R=HGCD(P<T>{a[0]>>m,a[1]>>m});\n        a=R*a;\n        if(SZ(a[1])<=m)return\
    \ R;\n        Mat<T> Q;\n        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);\n      \
    \  R=Q*R,a=Q*a;\n        if(SZ(a[1])<=m)return R;\n        int k=2*m+1-SZ(a[0]);\n\
    \        auto H=HGCD(P<T>{a[0]>>k,a[1]>>k});\n        return H*R;\n    }\n   \
    \ template<typename T>Mat<T> InnerGCD(P<T> a){\n        if(SZ(a[0])<SZ(a[1])){\n\
    \            auto M=InnerGCD(P<T>{a[1],a[0]});\n            swap(M[0],M[1]);\n\
    \            swap(M[2],M[3]);\n            return M;\n        }\n        auto\
    \ m0=HGCD(a);\n        a=m0*a;\n        if(a[1].empty())return m0;\n        Mat<T>\
    \ Q;\n        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);\n        m0=Q*m0,a=Q*a;\n \
    \       if(a[1].empty())return m0;\n        return InnerGCD(a)*m0;\n    }\n  \
    \  template<typename T>T gcd(const T& a,const T& b){\n        P<T> p({a,b});\n\
    \        auto M=InnerGCD(p);\n        p=M*p;\n        if(!p[0].empty()){\n   \
    \         auto coeff=p[0].back().inv();\n            for(auto& x:p[0])x*=coeff;\n\
    \        }\n        return p[0];\n    }\n    template<typename T>pair<bool,T>\
    \ PolyInv(const T& a,const T& b){\n        P<T> p({a,b});\n        auto M=InnerGCD(p);\n\
    \        T g=(M*p)[0];\n        if(g.size()!=1)return {false,{}};\n        P<T>\
    \ x({T({1}),b});\n        auto ret=(M*x)[0]%b;\n        auto coeff=g[0].inv();\n\
    \        for(auto& x:ret)x*=coeff;\n        return {true,ret};\n    }\n}\n\n/**\n\
    \ * @brief Half GCD\n*/\n#line 3 \"FPS/factorize.hpp\"\n\nnamespace FactorizePoly\
    \ {\ntemplate <typename T> Poly<T> powmod(Poly<T> &f, ll n, Poly<T> &g) {\n  \
    \  Poly<T> ret({1}), base = f;\n    while (n) {\n        if (n & 1) {\n      \
    \      ret *= base;\n            ret %= g;\n        }\n        base *= base;\n\
    \        base %= g;\n        n >>= 1;\n    }\n    return ret;\n}\ntemplate <typename\
    \ T> vector<Poly<T>> EDF(Poly<T> &f, int d) {\n    int p = T::get_mod(), half\
    \ = (p - 1) / 2;\n    if (f.deg() < d)\n        return {};\n    if (f.deg() ==\
    \ d)\n        return {f};\n    Poly<T> base(SZ(f));\n    rep(i, 0, SZ(f)) base[i]\
    \ = Random::get(T::get_mod() - 1);\n    auto g = HalfGCD::gcd(base, f);\n    if\
    \ (g.deg() != 0) {\n        auto ret = EDF(g, d);\n        auto fg = f / g;\n\
    \        auto add = EDF(fg, d);\n        ret.insert(ret.end(), ALL(add));\n  \
    \      return ret;\n    } else {\n        Poly<T> b = base, rem;\n        if (p\
    \ == 2) {\n            rep(_, 0, d) {\n                rem += b;\n           \
    \     rem %= f;\n                b = powmod(b, p, f);\n            }\n       \
    \ } else {\n            rem = Poly<T>({1});\n            rep(_, 0, d) {\n    \
    \            auto t = powmod(b, half, f);\n                rem *= t;\n       \
    \         rem %= f;\n                b = powmod(b, p, f);\n            }\n   \
    \         rem[0] -= 1;\n        }\n        g = HalfGCD::gcd(rem, f);\n       \
    \ if (g.deg() != 0 and g != f) {\n            auto ret = EDF(g, d);\n        \
    \    auto fg = f / g;\n            auto add = EDF(fg, d);\n            ret.insert(ret.end(),\
    \ ALL(add));\n            return ret;\n        } else {\n            return EDF(f,\
    \ d);\n        }\n    }\n}\ntemplate <typename T> vector<Poly<T>> CantorZassenhaus(Poly<T>\
    \ &f) {\n    auto cur = f;\n    vector<Poly<T>> ret;\n    ll p = T::get_mod(),\
    \ d = 1;\n    Poly<T> x({0, 1}), xp = x;\n    for (;;) {\n        if (cur.deg()\
    \ < d * 2) {\n            if (cur.deg())\n                ret.push_back(cur);\n\
    \            break;\n        }\n        xp = powmod(xp, p, cur);\n        auto\
    \ rem = xp - x;\n        auto g = HalfGCD::gcd(rem, cur);\n        auto add =\
    \ EDF(g, d);\n        ret.insert(ret.end(), ALL(add));\n        cur /= g;\n  \
    \      d++;\n    }\n    return ret;\n}\ntemplate <typename T>\nvector<Poly<T>>\
    \ SquarefreeDecomposition(const Poly<T> &f) {\n    int p = T::get_mod();\n   \
    \ vector<Poly<T>> ret(SZ(f), Poly<T>({1}));\n    auto c = HalfGCD::gcd(f, f.diff());\n\
    \    auto w = f / c;\n    int ptr = 0;\n    while (w.deg() > 0) {\n        auto\
    \ y = HalfGCD::gcd(w, c);\n        auto z = w / y;\n        ret[ptr] *= z;\n \
    \       w = y;\n        c /= y;\n        ptr++;\n    }\n\n    if (c.deg() > 0)\
    \ {\n        Poly<T> h(c.deg() / p + 1);\n        rep(i, 0, SZ(c)) if (i % p ==\
    \ 0) {\n            h[i / p] = c[i];\n        }\n        auto sub = SquarefreeDecomposition(h);\n\
    \        rep(i, 0, SZ(sub)) ret[(i + 1) * p - 1] *= sub[i];\n    }\n    return\
    \ ret;\n}\ntemplate <typename T> vector<Poly<T>> run(Poly<T> &f) { // f: monic\n\
    \    auto dec = SquarefreeDecomposition(f);\n    vector<Poly<T>> ret;\n    rep(i,\
    \ 0, SZ(dec)) {\n        auto add = CantorZassenhaus(dec[i]);\n        rep(_,\
    \ 0, i + 1) ret.insert(ret.end(), ALL(add));\n    }\n    return ret;\n}\n}; //\
    \ namespace FactorizePoly\n\n/**\n * @brief Factorize Polynomial\n */\n"
  code: "#pragma once\n#include \"FPS/halfgcd.hpp\"\n\nnamespace FactorizePoly {\n\
    template <typename T> Poly<T> powmod(Poly<T> &f, ll n, Poly<T> &g) {\n    Poly<T>\
    \ ret({1}), base = f;\n    while (n) {\n        if (n & 1) {\n            ret\
    \ *= base;\n            ret %= g;\n        }\n        base *= base;\n        base\
    \ %= g;\n        n >>= 1;\n    }\n    return ret;\n}\ntemplate <typename T> vector<Poly<T>>\
    \ EDF(Poly<T> &f, int d) {\n    int p = T::get_mod(), half = (p - 1) / 2;\n  \
    \  if (f.deg() < d)\n        return {};\n    if (f.deg() == d)\n        return\
    \ {f};\n    Poly<T> base(SZ(f));\n    rep(i, 0, SZ(f)) base[i] = Random::get(T::get_mod()\
    \ - 1);\n    auto g = HalfGCD::gcd(base, f);\n    if (g.deg() != 0) {\n      \
    \  auto ret = EDF(g, d);\n        auto fg = f / g;\n        auto add = EDF(fg,\
    \ d);\n        ret.insert(ret.end(), ALL(add));\n        return ret;\n    } else\
    \ {\n        Poly<T> b = base, rem;\n        if (p == 2) {\n            rep(_,\
    \ 0, d) {\n                rem += b;\n                rem %= f;\n            \
    \    b = powmod(b, p, f);\n            }\n        } else {\n            rem =\
    \ Poly<T>({1});\n            rep(_, 0, d) {\n                auto t = powmod(b,\
    \ half, f);\n                rem *= t;\n                rem %= f;\n          \
    \      b = powmod(b, p, f);\n            }\n            rem[0] -= 1;\n       \
    \ }\n        g = HalfGCD::gcd(rem, f);\n        if (g.deg() != 0 and g != f) {\n\
    \            auto ret = EDF(g, d);\n            auto fg = f / g;\n           \
    \ auto add = EDF(fg, d);\n            ret.insert(ret.end(), ALL(add));\n     \
    \       return ret;\n        } else {\n            return EDF(f, d);\n       \
    \ }\n    }\n}\ntemplate <typename T> vector<Poly<T>> CantorZassenhaus(Poly<T>\
    \ &f) {\n    auto cur = f;\n    vector<Poly<T>> ret;\n    ll p = T::get_mod(),\
    \ d = 1;\n    Poly<T> x({0, 1}), xp = x;\n    for (;;) {\n        if (cur.deg()\
    \ < d * 2) {\n            if (cur.deg())\n                ret.push_back(cur);\n\
    \            break;\n        }\n        xp = powmod(xp, p, cur);\n        auto\
    \ rem = xp - x;\n        auto g = HalfGCD::gcd(rem, cur);\n        auto add =\
    \ EDF(g, d);\n        ret.insert(ret.end(), ALL(add));\n        cur /= g;\n  \
    \      d++;\n    }\n    return ret;\n}\ntemplate <typename T>\nvector<Poly<T>>\
    \ SquarefreeDecomposition(const Poly<T> &f) {\n    int p = T::get_mod();\n   \
    \ vector<Poly<T>> ret(SZ(f), Poly<T>({1}));\n    auto c = HalfGCD::gcd(f, f.diff());\n\
    \    auto w = f / c;\n    int ptr = 0;\n    while (w.deg() > 0) {\n        auto\
    \ y = HalfGCD::gcd(w, c);\n        auto z = w / y;\n        ret[ptr] *= z;\n \
    \       w = y;\n        c /= y;\n        ptr++;\n    }\n\n    if (c.deg() > 0)\
    \ {\n        Poly<T> h(c.deg() / p + 1);\n        rep(i, 0, SZ(c)) if (i % p ==\
    \ 0) {\n            h[i / p] = c[i];\n        }\n        auto sub = SquarefreeDecomposition(h);\n\
    \        rep(i, 0, SZ(sub)) ret[(i + 1) * p - 1] *= sub[i];\n    }\n    return\
    \ ret;\n}\ntemplate <typename T> vector<Poly<T>> run(Poly<T> &f) { // f: monic\n\
    \    auto dec = SquarefreeDecomposition(f);\n    vector<Poly<T>> ret;\n    rep(i,\
    \ 0, SZ(dec)) {\n        auto add = CantorZassenhaus(dec[i]);\n        rep(_,\
    \ 0, i + 1) ret.insert(ret.end(), ALL(add));\n    }\n    return ret;\n}\n}; //\
    \ namespace FactorizePoly\n\n/**\n * @brief Factorize Polynomial\n */"
  dependsOn:
  - FPS/halfgcd.hpp
  isVerificationFile: false
  path: FPS/factorize.hpp
  requiredBy: []
  timestamp: '2026-10-15 23:15:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/factorize.hpp
layout: document
redirect_from:
- /library/FPS/factorize.hpp
- /library/FPS/factorize.hpp.html
title: Factorize Polynomial
---
