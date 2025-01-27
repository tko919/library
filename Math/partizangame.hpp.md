---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/fraction.hpp
    title: Fraction
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Math/partizangame.hpp\"\n\n#line 2 \"Math/fraction.hpp\"\
    \n\r\ntemplate <typename T> struct Frac {\r\n    T a, b;\r\n    Frac(T _a = 0)\
    \ {\r\n        init(_a, 1);\r\n    }\r\n    Frac(T _a, T _b) {\r\n        init(_a,\
    \ _b);\r\n    }\r\n    Frac &init(T _a, T _b) {\r\n        T g = gcd(_a, _b);\r\
    \n        a = _a / g, b = _b / g;\r\n        if (b < 0)\r\n            a = -a,\
    \ b = -b;\r\n        return *this;\r\n    }\r\n    Frac inv() const {\r\n    \
    \    return Frac(b, a);\r\n    }\r\n    Frac operator-() const {\r\n        return\
    \ Frac(-a, b);\r\n    }\r\n    Frac &operator+=(const Frac &x) {\r\n        return\
    \ init(a * x.b + x.a * b, b * x.b);\r\n    }\r\n    Frac &operator-=(const Frac\
    \ &x) {\r\n        return init(a * x.b - x.a * b, b * x.b);\r\n    }\r\n    Frac\
    \ &operator*=(const Frac &x) {\r\n        return init(a * x.a, b * x.b);\r\n \
    \   }\r\n    Frac &operator/=(const Frac &x) {\r\n        return init(a * x.b,\
    \ b * x.a);\r\n    }\r\n    Frac operator+(const Frac &x) const {\r\n        return\
    \ Frac(*this) += x;\r\n    }\r\n    Frac operator-(const Frac &x) const {\r\n\
    \        return Frac(*this) -= x;\r\n    }\r\n    Frac operator*(const Frac &x)\
    \ const {\r\n        return Frac(*this) *= x;\r\n    }\r\n    Frac operator/(const\
    \ Frac &x) const {\r\n        return Frac(*this) /= x;\r\n    }\r\n    bool operator<(const\
    \ Frac &x) const {\r\n        return a * x.b < b * x.a;\r\n    }\r\n    bool operator>(const\
    \ Frac &x) const {\r\n        return x < *this;\r\n    }\r\n    bool operator<=(const\
    \ Frac &x) const {\r\n        return !(x < *this);\r\n    }\r\n    bool operator>=(const\
    \ Frac &x) const {\r\n        return !(*this < x);\r\n    }\r\n    bool operator==(const\
    \ Frac &x) const {\r\n        return (*this <= x and x <= *this);\r\n    }\r\n\
    \    bool operator!=(const Frac &x) const {\r\n        return !(*this == x);\r\
    \n    }\r\n\r\n    friend istream &operator>>(istream &is, Frac &x) {\r\n    \
    \    return is >> x.a >> x.b;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Frac &x) {\r\n        return os << x.a << '/' << x.b;\r\n    }\r\n\
    };\r\ntemplate <typename T> Frac<T> between(const Frac<T> &x, const Frac<T> &y)\
    \ {\r\n    if (x.a < x.b and y.b < y.a)\r\n        return Frac(1);\r\n    else\
    \ if (x.b <= x.a) {\r\n        T add = floor(x.a / x.b);\r\n        return between(x\
    \ - add, y - add) + add;\r\n    } else\r\n        return between(y.inv(), x.inv()).inv();\r\
    \n}\r\n\r\n/**\r\n * @brief Fraction\r\n * @docs docs/fraction.md\r\n */\n#line\
    \ 4 \"Math/partizangame.hpp\"\ntemplate <typename T> struct Surreal {\n    static\
    \ constexpr int LG = std::numeric_limits<T>::digits - 2;\n    Frac<T> a;\n   \
    \ Surreal(T a = 0) : a(a, 1) {}\n    Surreal(T a, T b) : a(a, b) {}\n    Surreal(Frac<T>\
    \ a) : a(a) {}\n    static constexpr Surreal infty() {\n        return Surreal(INF,\
    \ 1);\n    }\n    bool operator==(Surreal const &rhs) const {\n        return\
    \ (a == rhs.a);\n    }\n    bool operator!=(Surreal const &rhs) const {\n    \
    \    return !(a == rhs);\n    }\n    bool operator<(Surreal const &rhs) const\
    \ {\n        return (a < rhs.a);\n    }\n    bool operator<=(Surreal const &rhs)\
    \ const {\n        return (a <= rhs.a);\n    }\n    bool operator>(Surreal const\
    \ &rhs) const {\n        return (a > rhs.a);\n    }\n    bool operator>=(Surreal\
    \ const &rhs) const {\n        return (a >= rhs.a);\n    }\n    friend Surreal\
    \ operator+(const Surreal &x, const Surreal &y) {\n        return x.a + y.a;\n\
    \    }\n    friend Surreal operator-(const Surreal &x, const Surreal &y) {\n \
    \       return x.a - y.a;\n    }\n    friend Surreal operator-(const Surreal &x)\
    \ {\n        return -x.a;\n    }\n    Surreal &operator+=(const Surreal &x) {\n\
    \        return (*this) = (*this) + x;\n    }\n    Surreal &operator-=(const Surreal\
    \ &x) {\n        return (*this) = (*this) - x;\n    }\n\n    static Surreal between(Surreal\
    \ L, Surreal R, bool incL = 0, bool incR = 0) {\n        Surreal ret(0);\n   \
    \     if (L < ret or (incL and L == ret)) {\n            if (ret < R or (incR\
    \ and R == ret)) {\n                return ret;\n            }\n        }\n  \
    \      bool sign = 0;\n        if (R <= 0) {\n            sign = 1;\n        \
    \    swap(L, R);\n            swap(incL, incR);\n            L = -L, R = -R;\n\
    \        }\n        rep(lg, 0, LG + 1) {\n            ll num = ceil(L.a.a << lg,\
    \ L.a.b);\n            if ((i128(L.a.a) << lg) == i128(L.a.b) * num and !incL)\n\
    \                num++;\n            ret = Surreal(num, 1LL << lg);\n        \
    \    if (ret < R or (incR and R == ret)) {\n                if (sign)\n      \
    \              ret = -ret;\n                return ret;\n            }\n     \
    \   }\n        assert(0);\n    }\n    friend ostream &operator<<(ostream &os,\
    \ const Surreal &x) {\n        return os << x.a;\n    }\n};\n\nstruct NumStar\
    \ {\n    using A = Surreal<ll>;\n    A a;\n    int b;\n    NumStar(A a = 0, int\
    \ b = 0) : a(a), b(b) {}\n    NumStar &operator+=(const NumStar &rhs) {\n    \
    \    a += rhs.a, b ^= rhs.b;\n        return *this;\n    }\n    NumStar &operator-=(const\
    \ NumStar &rhs) {\n        a -= rhs.a, b ^= rhs.b;\n        return *this;\n  \
    \  }\n    NumStar operator-() const {\n        return NumStar(-a, b);\n    }\n\
    \    bool operator==(const NumStar &rhs) const {\n        return (a == rhs.a &&\
    \ b == rhs.b);\n    }\n    static int mex(vector<int> &a) {\n        vector<int>\
    \ exi(SZ(a) + 1);\n        for (auto &x : a)\n            exi[x] = 1;\n      \
    \  int ret = 0;\n        while (exi[ret])\n            ret++;\n        return\
    \ ret;\n    }\n    static pair<bool, NumStar> calc(vector<NumStar> lb, vector<NumStar>\
    \ rb) {\n        A L = -A::infty(), R = A::infty();\n        vector<int> ls, rs;\n\
    \        for (auto &num : lb) {\n            if (chmax(L, num.a))\n          \
    \      ls.clear();\n            if (L == num.a)\n                ls.push_back(num.b);\n\
    \        }\n        for (auto &num : rb) {\n            if (chmin(R, num.a))\n\
    \                rs.clear();\n            if (R == num.a)\n                rs.push_back(num.b);\n\
    \        }\n        int lm = mex(ls), rm = mex(rs);\n        if (L < R) {\n  \
    \          return {true, NumStar(A::between(L, R, lm == 0, rm == 0), 0)};\n  \
    \      } else if (L == R) {\n            if (lm == rm)\n                return\
    \ {true, NumStar(L, lm)};\n        }\n        return {false, NumStar()};\n   \
    \ }\n    friend ostream &operator<<(ostream &os, const NumStar &x) {\n       \
    \ return os << x.a << \"+*\" << x.b;\n    }\n    pair<bool, bool> outcome() {\n\
    \        if (a > 0)\n            return {1, 0};\n        if (a < 0)\n        \
    \    return {0, 1};\n        if (b == 0)\n            return {0, 0};\n       \
    \ return {1, 1};\n    }\n};\n\n// F(G):= {G_L,G_R} (pair)\ntemplate <typename\
    \ State, typename F>\nmap<State, NumStar> SolvePartizanGame(const vector<State>\
    \ &states, F option) {\n    map<State, NumStar> ret;\n    auto dfs = [&](auto\
    \ &dfs, const State &current) -> pair<bool, NumStar> {\n        if (ret.count(current))\n\
    \            return {true, ret[current]};\n        auto [gl, gr] = option(current);\n\
    \        vector<NumStar> ls, rs;\n        for (auto &to : gl) {\n            auto\
    \ [ch, lv] = dfs(dfs, to);\n            if (!ch)\n                return {false,\
    \ NumStar()};\n            ls.push_back(lv);\n        }\n        for (auto &to\
    \ : gr) {\n            auto [ch, rv] = dfs(dfs, to);\n            if (!ch)\n \
    \               return {false, NumStar()};\n            rs.push_back(rv);\n  \
    \      }\n        auto [ch, val] = NumStar::calc(ls, rs);\n        if (!ch)\n\
    \            return {false, NumStar()};\n        return {true, ret[current] =\
    \ val};\n    };\n    for (auto &s : states) {\n        if (!dfs(dfs, s).first)\n\
    \            return map<State, NumStar>();\n    }\n    return ret;\n}\n\n/**\n\
    \ * @ Partizan Game Solver\n */\n"
  code: "#pragma once\n\n#include \"Math/fraction.hpp\"\ntemplate <typename T> struct\
    \ Surreal {\n    static constexpr int LG = std::numeric_limits<T>::digits - 2;\n\
    \    Frac<T> a;\n    Surreal(T a = 0) : a(a, 1) {}\n    Surreal(T a, T b) : a(a,\
    \ b) {}\n    Surreal(Frac<T> a) : a(a) {}\n    static constexpr Surreal infty()\
    \ {\n        return Surreal(INF, 1);\n    }\n    bool operator==(Surreal const\
    \ &rhs) const {\n        return (a == rhs.a);\n    }\n    bool operator!=(Surreal\
    \ const &rhs) const {\n        return !(a == rhs);\n    }\n    bool operator<(Surreal\
    \ const &rhs) const {\n        return (a < rhs.a);\n    }\n    bool operator<=(Surreal\
    \ const &rhs) const {\n        return (a <= rhs.a);\n    }\n    bool operator>(Surreal\
    \ const &rhs) const {\n        return (a > rhs.a);\n    }\n    bool operator>=(Surreal\
    \ const &rhs) const {\n        return (a >= rhs.a);\n    }\n    friend Surreal\
    \ operator+(const Surreal &x, const Surreal &y) {\n        return x.a + y.a;\n\
    \    }\n    friend Surreal operator-(const Surreal &x, const Surreal &y) {\n \
    \       return x.a - y.a;\n    }\n    friend Surreal operator-(const Surreal &x)\
    \ {\n        return -x.a;\n    }\n    Surreal &operator+=(const Surreal &x) {\n\
    \        return (*this) = (*this) + x;\n    }\n    Surreal &operator-=(const Surreal\
    \ &x) {\n        return (*this) = (*this) - x;\n    }\n\n    static Surreal between(Surreal\
    \ L, Surreal R, bool incL = 0, bool incR = 0) {\n        Surreal ret(0);\n   \
    \     if (L < ret or (incL and L == ret)) {\n            if (ret < R or (incR\
    \ and R == ret)) {\n                return ret;\n            }\n        }\n  \
    \      bool sign = 0;\n        if (R <= 0) {\n            sign = 1;\n        \
    \    swap(L, R);\n            swap(incL, incR);\n            L = -L, R = -R;\n\
    \        }\n        rep(lg, 0, LG + 1) {\n            ll num = ceil(L.a.a << lg,\
    \ L.a.b);\n            if ((i128(L.a.a) << lg) == i128(L.a.b) * num and !incL)\n\
    \                num++;\n            ret = Surreal(num, 1LL << lg);\n        \
    \    if (ret < R or (incR and R == ret)) {\n                if (sign)\n      \
    \              ret = -ret;\n                return ret;\n            }\n     \
    \   }\n        assert(0);\n    }\n    friend ostream &operator<<(ostream &os,\
    \ const Surreal &x) {\n        return os << x.a;\n    }\n};\n\nstruct NumStar\
    \ {\n    using A = Surreal<ll>;\n    A a;\n    int b;\n    NumStar(A a = 0, int\
    \ b = 0) : a(a), b(b) {}\n    NumStar &operator+=(const NumStar &rhs) {\n    \
    \    a += rhs.a, b ^= rhs.b;\n        return *this;\n    }\n    NumStar &operator-=(const\
    \ NumStar &rhs) {\n        a -= rhs.a, b ^= rhs.b;\n        return *this;\n  \
    \  }\n    NumStar operator-() const {\n        return NumStar(-a, b);\n    }\n\
    \    bool operator==(const NumStar &rhs) const {\n        return (a == rhs.a &&\
    \ b == rhs.b);\n    }\n    static int mex(vector<int> &a) {\n        vector<int>\
    \ exi(SZ(a) + 1);\n        for (auto &x : a)\n            exi[x] = 1;\n      \
    \  int ret = 0;\n        while (exi[ret])\n            ret++;\n        return\
    \ ret;\n    }\n    static pair<bool, NumStar> calc(vector<NumStar> lb, vector<NumStar>\
    \ rb) {\n        A L = -A::infty(), R = A::infty();\n        vector<int> ls, rs;\n\
    \        for (auto &num : lb) {\n            if (chmax(L, num.a))\n          \
    \      ls.clear();\n            if (L == num.a)\n                ls.push_back(num.b);\n\
    \        }\n        for (auto &num : rb) {\n            if (chmin(R, num.a))\n\
    \                rs.clear();\n            if (R == num.a)\n                rs.push_back(num.b);\n\
    \        }\n        int lm = mex(ls), rm = mex(rs);\n        if (L < R) {\n  \
    \          return {true, NumStar(A::between(L, R, lm == 0, rm == 0), 0)};\n  \
    \      } else if (L == R) {\n            if (lm == rm)\n                return\
    \ {true, NumStar(L, lm)};\n        }\n        return {false, NumStar()};\n   \
    \ }\n    friend ostream &operator<<(ostream &os, const NumStar &x) {\n       \
    \ return os << x.a << \"+*\" << x.b;\n    }\n    pair<bool, bool> outcome() {\n\
    \        if (a > 0)\n            return {1, 0};\n        if (a < 0)\n        \
    \    return {0, 1};\n        if (b == 0)\n            return {0, 0};\n       \
    \ return {1, 1};\n    }\n};\n\n// F(G):= {G_L,G_R} (pair)\ntemplate <typename\
    \ State, typename F>\nmap<State, NumStar> SolvePartizanGame(const vector<State>\
    \ &states, F option) {\n    map<State, NumStar> ret;\n    auto dfs = [&](auto\
    \ &dfs, const State &current) -> pair<bool, NumStar> {\n        if (ret.count(current))\n\
    \            return {true, ret[current]};\n        auto [gl, gr] = option(current);\n\
    \        vector<NumStar> ls, rs;\n        for (auto &to : gl) {\n            auto\
    \ [ch, lv] = dfs(dfs, to);\n            if (!ch)\n                return {false,\
    \ NumStar()};\n            ls.push_back(lv);\n        }\n        for (auto &to\
    \ : gr) {\n            auto [ch, rv] = dfs(dfs, to);\n            if (!ch)\n \
    \               return {false, NumStar()};\n            rs.push_back(rv);\n  \
    \      }\n        auto [ch, val] = NumStar::calc(ls, rs);\n        if (!ch)\n\
    \            return {false, NumStar()};\n        return {true, ret[current] =\
    \ val};\n    };\n    for (auto &s : states) {\n        if (!dfs(dfs, s).first)\n\
    \            return map<State, NumStar>();\n    }\n    return ret;\n}\n\n/**\n\
    \ * @ Partizan Game Solver\n */"
  dependsOn:
  - Math/fraction.hpp
  isVerificationFile: false
  path: Math/partizangame.hpp
  requiredBy: []
  timestamp: '2025-01-28 06:32:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/partizangame.hpp
layout: document
redirect_from:
- /library/Math/partizangame.hpp
- /library/Math/partizangame.hpp.html
title: Math/partizangame.hpp
---
