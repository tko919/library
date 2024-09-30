---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: FPS/halfgcd.hpp
    title: Half GCD
  - icon: ':heavy_check_mark:'
    path: FPS/prodofpolys.hpp
    title: Product of Polynomials
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Find roots
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
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool simple> vector<pair<int,\
    \ int>> genGraph(int n) {\r\n    vector<pair<int, int>> cand, es;\r\n    rep(u,\
    \ 0, n) rep(v, 0, n) {\r\n        if (simple and u == v)\r\n            continue;\r\
    \n        if (!directed and u > v)\r\n            continue;\r\n        cand.push_back({u,\
    \ v});\r\n    }\r\n    int m = get(SZ(cand));\r\n    vector<int> ord;\r\n    if\
    \ (simple)\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    else {\r\n    \
    \    rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n    }\r\n    for (auto\
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
    \ * @brief Half GCD\n*/\n#line 2 \"FPS/prodofpolys.hpp\"\n\ntemplate<typename\
    \ T>Poly<T> ProdOfPolys(vector<Poly<T>>& fs){\n    if(fs.empty())return Poly<T>({T(1)});\n\
    \    sort(ALL(fs),[&](Poly<T>& a,Poly<T>& b){return a.size()<b.size();});\n  \
    \  deque<Poly<T>> deq;\n    for(auto& f:fs)deq.push_back(f);\n    while(deq.size()>1){\n\
    \        deq.push_back(deq[0]*deq[1]);\n        deq.pop_front();\n        deq.pop_front();\n\
    \    }\n    return deq[0];\n}\n\n/**\n * @brief Product of Polynomials\n*/\n#line\
    \ 5 \"FPS/findroots.hpp\"\n\nnamespace FindRoots {\ntemplate <typename T> Poly<T>\
    \ powmod(Poly<T> &f, ll n, Poly<T> &g) {\n    Poly<T> ret({1}), base = f;\n  \
    \  while (n != 0) {\n        if (n & 1) {\n            ret *= base;\n        \
    \    ret %= g;\n        }\n        base *= base;\n        base %= g;\n       \
    \ n /= 2;\n    }\n    return ret;\n}\ntemplate <typename T> vector<Poly<T>> EDF(Poly<T>\
    \ &f) {\n    if (f.deg() < 1)\n        return {};\n    if (f.deg() == 1)\n   \
    \     return {f};\n    Poly<T> base(2);\n    base[0] = Random::get(T::get_mod()\
    \ - 1);\n    base[1] = 1;\n    ll pw = (T::get_mod() - 1) / 2;\n    auto rem =\
    \ powmod(base, pw, f);\n    if (rem.empty())\n        return EDF(f);\n    rem\
    \ -= Poly<T>({1});\n    auto h = HalfGCD::gcd(rem, f);\n    auto ret = EDF(h);\n\
    \    auto fh = f / h;\n    auto add = EDF(fh);\n    ret.insert(ret.end(), ALL(add));\n\
    \    return ret;\n}\ntemplate <typename T> vector<Poly<T>> SquarefreeDecomposition(Poly<T>\
    \ f) {\n    if (f.deg() == 0)\n        return {f};\n    auto g = HalfGCD::gcd(f,\
    \ f.diff());\n    auto base = SquarefreeDecomposition(g);\n    g *= ProdOfPolys(base);\n\
    \    f /= g;\n    base.insert(base.begin(), f);\n    return base;\n}\ntemplate\
    \ <typename T> Poly<T> select(Poly<T> &f) {\n    Poly<T> X({0, 1});\n    auto\
    \ xpmf = powmod(X, T::get_mod(), f);\n    xpmf -= X;\n    return HalfGCD::gcd(xpmf,\
    \ f);\n}\ntemplate <typename T> vector<T> run(Poly<T> &f) {\n    auto dec = SquarefreeDecomposition(f);\n\
    \    vector<T> ret;\n    rep(i, 0, SZ(dec)) {\n        auto g = select(dec[i]);\n\
    \        auto add = EDF(g);\n        for (auto &h : add) {\n            assert(h.deg()\
    \ == 1);\n            rep(_, 0, i + 1) ret.push_back(-h[0]);\n        }\n    }\n\
    \    return ret;\n}\n}; // namespace FindRoots\n\n/**\n * @brief Find roots\n\
    \ */\n"
  code: "#pragma once\n#include \"Utility/random.hpp\"\n#include \"FPS/halfgcd.hpp\"\
    \n#include \"FPS/prodofpolys.hpp\"\n\nnamespace FindRoots {\ntemplate <typename\
    \ T> Poly<T> powmod(Poly<T> &f, ll n, Poly<T> &g) {\n    Poly<T> ret({1}), base\
    \ = f;\n    while (n != 0) {\n        if (n & 1) {\n            ret *= base;\n\
    \            ret %= g;\n        }\n        base *= base;\n        base %= g;\n\
    \        n /= 2;\n    }\n    return ret;\n}\ntemplate <typename T> vector<Poly<T>>\
    \ EDF(Poly<T> &f) {\n    if (f.deg() < 1)\n        return {};\n    if (f.deg()\
    \ == 1)\n        return {f};\n    Poly<T> base(2);\n    base[0] = Random::get(T::get_mod()\
    \ - 1);\n    base[1] = 1;\n    ll pw = (T::get_mod() - 1) / 2;\n    auto rem =\
    \ powmod(base, pw, f);\n    if (rem.empty())\n        return EDF(f);\n    rem\
    \ -= Poly<T>({1});\n    auto h = HalfGCD::gcd(rem, f);\n    auto ret = EDF(h);\n\
    \    auto fh = f / h;\n    auto add = EDF(fh);\n    ret.insert(ret.end(), ALL(add));\n\
    \    return ret;\n}\ntemplate <typename T> vector<Poly<T>> SquarefreeDecomposition(Poly<T>\
    \ f) {\n    if (f.deg() == 0)\n        return {f};\n    auto g = HalfGCD::gcd(f,\
    \ f.diff());\n    auto base = SquarefreeDecomposition(g);\n    g *= ProdOfPolys(base);\n\
    \    f /= g;\n    base.insert(base.begin(), f);\n    return base;\n}\ntemplate\
    \ <typename T> Poly<T> select(Poly<T> &f) {\n    Poly<T> X({0, 1});\n    auto\
    \ xpmf = powmod(X, T::get_mod(), f);\n    xpmf -= X;\n    return HalfGCD::gcd(xpmf,\
    \ f);\n}\ntemplate <typename T> vector<T> run(Poly<T> &f) {\n    auto dec = SquarefreeDecomposition(f);\n\
    \    vector<T> ret;\n    rep(i, 0, SZ(dec)) {\n        auto g = select(dec[i]);\n\
    \        auto add = EDF(g);\n        for (auto &h : add) {\n            assert(h.deg()\
    \ == 1);\n            rep(_, 0, i + 1) ret.push_back(-h[0]);\n        }\n    }\n\
    \    return ret;\n}\n}; // namespace FindRoots\n\n/**\n * @brief Find roots\n\
    \ */"
  dependsOn:
  - Utility/random.hpp
  - FPS/halfgcd.hpp
  - FPS/prodofpolys.hpp
  isVerificationFile: false
  path: FPS/findroots.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/findroots.hpp
layout: document
redirect_from:
- /library/FPS/findroots.hpp
- /library/FPS/findroots.hpp.html
title: Find roots
---
