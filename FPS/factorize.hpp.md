---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: FPS/halfgcd.hpp
    title: Half GCD
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Factorize Polynomial
    links: []
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nnamespace Random {\r\nmt19937_64\
    \ randgen(chrono::steady_clock::now().time_since_epoch().count());\r\nusing u64\
    \ = unsigned long long;\r\nu64 get() {\r\n    return randgen();\r\n}\r\ntemplate\
    \ <typename T> T get(T L) { // [0,L]\r\n    return get() % (L + 1);\r\n}\r\ntemplate\
    \ <typename T> T get(T L, T R) { // [L,R]\r\n    return get(R - L) + L;\r\n}\r\
    \ndouble uniform() {\r\n    return double(get(1000000000)) / 1000000000;\r\n}\r\
    \nstring str(int n) {\r\n    string ret;\r\n    rep(i, 0, n) ret += get('a', 'z');\r\
    \n    return ret;\r\n}\r\ntemplate <typename Iter> void shuffle(Iter first, Iter\
    \ last) {\r\n    if (first == last)\r\n        return;\r\n    int len = 1;\r\n\
    \    for (auto it = first + 1; it != last; it++) {\r\n        len++;\r\n     \
    \   int j = get(0, len - 1);\r\n        if (j != len - 1)\r\n            iter_swap(it,\
    \ first + j);\r\n    }\r\n}\r\ntemplate <typename T> vector<T> select(int n, T\
    \ L, T R) { // [L,R]\r\n    if (n * 2 >= R - L + 1) {\r\n        vector<T> ret(R\
    \ - L + 1);\r\n        iota(ALL(ret), L);\r\n        shuffle(ALL(ret));\r\n  \
    \      ret.resize(n);\r\n        return ret;\r\n    } else {\r\n        unordered_set<T>\
    \ used;\r\n        vector<T> ret;\r\n        while (SZ(used) < n) {\r\n      \
    \      T x = get(L, R);\r\n            if (!used.count(x)) {\r\n             \
    \   used.insert(x);\r\n                ret.push_back(x);\r\n            }\r\n\
    \        }\r\n        return ret;\r\n    }\r\n}\r\n\r\nvoid relabel(int n, vector<pair<int,\
    \ int>> &es) {\r\n    shuffle(ALL(es));\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),\
    \ 0);\r\n    shuffle(ALL(ord));\r\n    for (auto &[u, v] : es)\r\n        u =\
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool multi, bool self>\r\
    \nvector<pair<int, int>> genGraph(int n, int m) {\r\n    vector<pair<int, int>>\
    \ cand, es;\r\n    rep(u, 0, n) rep(v, 0, n) {\r\n        if (!self and u == v)\r\
    \n            continue;\r\n        if (!directed and u > v)\r\n            continue;\r\
    \n        cand.push_back({u, v});\r\n    }\r\n    if (m == -1)\r\n        m =\
    \ get(SZ(cand));\r\n    // chmin(m, SZ(cand));\r\n    vector<int> ord;\r\n   \
    \ if (multi)\r\n        rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n   \
    \ else {\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    }\r\n    for (auto\
    \ &i : ord)\r\n        es.push_back(cand[i]);\r\n    relabel(n, es);\r\n    return\
    \ es;\r\n}\r\nvector<pair<int, int>> genTree(int n) {\r\n    vector<pair<int,\
    \ int>> es;\r\n    rep(i, 1, n) es.push_back({get(i - 1), i});\r\n    relabel(n,\
    \ es);\r\n    return es;\r\n}\r\n}; // namespace Random\r\n\r\n/**\r\n * @brief\
    \ Random\r\n */\n#line 2 \"FPS/halfgcd.hpp\"\n\nnamespace HalfGCD{\n    template<typename\
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
    \ * @brief Half GCD\n*/\n#line 4 \"FPS/factorize.hpp\"\n\n#include <boost/multiprecision/cpp_int.hpp>\n\
    namespace mp = boost::multiprecision;\nusing Bint = mp::cpp_int;\n\nnamespace\
    \ FactorizePoly {\ntemplate <typename T> Poly<T> powmod(Poly<T> &f, Bint &n, Poly<T>\
    \ &g) {\n    Poly<T> ret({1}), base = f;\n    while (n != 0) {\n        if (n\
    \ & 1) {\n            ret *= base;\n            ret %= g;\n        }\n       \
    \ base *= base;\n        base %= g;\n        n >>= 1;\n    }\n    return ret;\n\
    }\ntemplate <typename T> vector<Poly<T>> EDF(Poly<T> &f, int d) {\n    if (f.deg()\
    \ < d)\n        return {};\n    if (f.deg() == d)\n        return {f};\n    Poly<T>\
    \ base(SZ(f));\n    rep(i, 0, SZ(f)) base[i] = Random::get(T::get_mod() - 1);\n\
    \    auto g = HalfGCD::gcd(base, f);\n    if (g.deg() != 0) {\n        auto ret\
    \ = EDF(g, d);\n        auto fg = f / g;\n        auto add = EDF(fg, d);\n   \
    \     ret.insert(ret.end(), ALL(add));\n        return ret;\n    } else {\n  \
    \      Bint pw = 1;\n        rep(_, 0, d) pw *= T::get_mod();\n        pw = (pw\
    \ - 1) / 2;\n        auto rem = powmod(base, pw, f);\n        rem[0] -= 1;\n \
    \       g = HalfGCD::gcd(rem, f);\n        if (g.deg() != 0 and g != f) {\n  \
    \          auto ret = EDF(g, d);\n            auto fg = f / g;\n            auto\
    \ add = EDF(fg, d);\n            ret.insert(ret.end(), ALL(add));\n          \
    \  return ret;\n        } else {\n            return EDF(f, d);\n        }\n \
    \   }\n}\ntemplate <typename T> vector<Poly<T>> CantorZassenhaus(Poly<T> &f) {\n\
    \    auto base = Poly<T>({0, 1});\n    auto cur = f;\n    vector<Poly<T>> ret;\n\
    \    int d = 1;\n    Bint k = 1, md = T::get_mod();\n    for (;;) {\n        if\
    \ (cur.deg() < d * 2) {\n            if (cur.deg())\n                ret.push_back(cur);\n\
    \            break;\n        }\n        k *= md;\n        auto rem = powmod(base,\
    \ k, cur);\n        rem -= base;\n        auto g = HalfGCD::gcd(rem, cur);\n \
    \       auto add = EDF(g, d);\n        ret.insert(ret.end(), ALL(add));\n    \
    \    cur /= g;\n        d++;\n    }\n    return ret;\n}\ntemplate <typename T>\
    \ vector<Poly<T>> SquarefreeDecomposition(Poly<T> f) {\n    if (f.deg() == 0)\n\
    \        return {f};\n    auto g = HalfGCD::gcd(f, f.diff());\n    auto base =\
    \ SquarefreeDecomposition(g);\n    for (auto &b : base)\n        g *= b;\n   \
    \ f /= g;\n    base.insert(base.begin(), f);\n    return base;\n}\ntemplate <typename\
    \ T> vector<Poly<T>> run(Poly<T> &f) { // f: monic\n    auto dec = SquarefreeDecomposition(f);\n\
    \    vector<Poly<T>> ret;\n    rep(i, 0, SZ(dec)) {\n        auto add = CantorZassenhaus(dec[i]);\n\
    \        rep(_, 0, i + 1) ret.insert(ret.end(), ALL(add));\n    }\n    return\
    \ ret;\n}\n}; // namespace FactorizePoly\n\n/**\n * @brief Factorize Polynomial\n\
    \ */\n"
  code: "#pragma once\n#include \"Utility/random.hpp\"\n#include \"FPS/halfgcd.hpp\"\
    \n\n#include <boost/multiprecision/cpp_int.hpp>\nnamespace mp = boost::multiprecision;\n\
    using Bint = mp::cpp_int;\n\nnamespace FactorizePoly {\ntemplate <typename T>\
    \ Poly<T> powmod(Poly<T> &f, Bint &n, Poly<T> &g) {\n    Poly<T> ret({1}), base\
    \ = f;\n    while (n != 0) {\n        if (n & 1) {\n            ret *= base;\n\
    \            ret %= g;\n        }\n        base *= base;\n        base %= g;\n\
    \        n >>= 1;\n    }\n    return ret;\n}\ntemplate <typename T> vector<Poly<T>>\
    \ EDF(Poly<T> &f, int d) {\n    if (f.deg() < d)\n        return {};\n    if (f.deg()\
    \ == d)\n        return {f};\n    Poly<T> base(SZ(f));\n    rep(i, 0, SZ(f)) base[i]\
    \ = Random::get(T::get_mod() - 1);\n    auto g = HalfGCD::gcd(base, f);\n    if\
    \ (g.deg() != 0) {\n        auto ret = EDF(g, d);\n        auto fg = f / g;\n\
    \        auto add = EDF(fg, d);\n        ret.insert(ret.end(), ALL(add));\n  \
    \      return ret;\n    } else {\n        Bint pw = 1;\n        rep(_, 0, d) pw\
    \ *= T::get_mod();\n        pw = (pw - 1) / 2;\n        auto rem = powmod(base,\
    \ pw, f);\n        rem[0] -= 1;\n        g = HalfGCD::gcd(rem, f);\n        if\
    \ (g.deg() != 0 and g != f) {\n            auto ret = EDF(g, d);\n           \
    \ auto fg = f / g;\n            auto add = EDF(fg, d);\n            ret.insert(ret.end(),\
    \ ALL(add));\n            return ret;\n        } else {\n            return EDF(f,\
    \ d);\n        }\n    }\n}\ntemplate <typename T> vector<Poly<T>> CantorZassenhaus(Poly<T>\
    \ &f) {\n    auto base = Poly<T>({0, 1});\n    auto cur = f;\n    vector<Poly<T>>\
    \ ret;\n    int d = 1;\n    Bint k = 1, md = T::get_mod();\n    for (;;) {\n \
    \       if (cur.deg() < d * 2) {\n            if (cur.deg())\n               \
    \ ret.push_back(cur);\n            break;\n        }\n        k *= md;\n     \
    \   auto rem = powmod(base, k, cur);\n        rem -= base;\n        auto g = HalfGCD::gcd(rem,\
    \ cur);\n        auto add = EDF(g, d);\n        ret.insert(ret.end(), ALL(add));\n\
    \        cur /= g;\n        d++;\n    }\n    return ret;\n}\ntemplate <typename\
    \ T> vector<Poly<T>> SquarefreeDecomposition(Poly<T> f) {\n    if (f.deg() ==\
    \ 0)\n        return {f};\n    auto g = HalfGCD::gcd(f, f.diff());\n    auto base\
    \ = SquarefreeDecomposition(g);\n    for (auto &b : base)\n        g *= b;\n \
    \   f /= g;\n    base.insert(base.begin(), f);\n    return base;\n}\ntemplate\
    \ <typename T> vector<Poly<T>> run(Poly<T> &f) { // f: monic\n    auto dec = SquarefreeDecomposition(f);\n\
    \    vector<Poly<T>> ret;\n    rep(i, 0, SZ(dec)) {\n        auto add = CantorZassenhaus(dec[i]);\n\
    \        rep(_, 0, i + 1) ret.insert(ret.end(), ALL(add));\n    }\n    return\
    \ ret;\n}\n}; // namespace FactorizePoly\n\n/**\n * @brief Factorize Polynomial\n\
    \ */"
  dependsOn:
  - Utility/random.hpp
  - FPS/halfgcd.hpp
  isVerificationFile: false
  path: FPS/factorize.hpp
  requiredBy: []
  timestamp: '2025-05-25 16:11:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/factorize.hpp
layout: document
redirect_from:
- /library/FPS/factorize.hpp
- /library/FPS/factorize.hpp.html
title: Factorize Polynomial
---
