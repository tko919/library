---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution_cyclic.test.cpp
    title: Verify/LC_multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1080.test.cpp
    title: Verify/YUKI_1080.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Formal Power Series (Arbitrary mod)
    links: []
  bundledCode: "#line 2 \"FPS/arbitraryfps.hpp\"\n\r\ntemplate <typename T> struct\
    \ Poly : vector<T> {\r\n    Poly(int n = 0) {\r\n        this->assign(n, T());\r\
    \n    }\r\n    Poly(const initializer_list<T> f) : vector<T>::vector(f) {}\r\n\
    \    Poly(const vector<T> &f) {\r\n        this->assign(ALL(f));\r\n    }\r\n\
    \    int deg() const {\r\n        return this->size() - 1;\r\n    }\r\n    T eval(const\
    \ T &x) {\r\n        T res;\r\n        for (int i = this->size() - 1; i >= 0;\
    \ i--)\r\n            res *= x, res += this->at(i);\r\n        return res;\r\n\
    \    }\r\n    Poly rev() const {\r\n        Poly res = *this;\r\n        reverse(ALL(res));\r\
    \n        return res;\r\n    }\r\n    void shrink() {\r\n        while (!this->empty()\
    \ and this->back() == 0)\r\n            this->pop_back();\r\n    }\r\n    Poly\
    \ operator>>(ll sz) const {\r\n        if ((int)this->size() <= sz)\r\n      \
    \      return {};\r\n        Poly ret(*this);\r\n        ret.erase(ret.begin(),\
    \ ret.begin() + sz);\r\n        return ret;\r\n    }\r\n    Poly operator<<(ll\
    \ sz) const {\r\n        Poly ret(*this);\r\n        ret.insert(ret.begin(), sz,\
    \ T(0));\r\n        return ret;\r\n    }\r\n    Poly inv() const {\r\n       \
    \ assert(this->front() != 0);\r\n        const int n = this->size();\r\n     \
    \   Poly res(1);\r\n        res.front() = T(1) / this->front();\r\n        for\
    \ (int k = 1; k < n; k <<= 1) {\r\n            Poly g = res, h = *this;\r\n  \
    \          h.resize(k * 2);\r\n            res.resize(k * 2);\r\n            g\
    \ = (g.square() * h);\r\n            g.resize(k * 2);\r\n            rep(i, k,\
    \ min(k * 2, n)) res[i] -= g[i];\r\n        }\r\n        res.resize(n);\r\n  \
    \      return res;\r\n    }\r\n    Poly square() const {\r\n        return Poly(mult(*this,\
    \ *this));\r\n    }\r\n    Poly operator-() const {\r\n        return Poly() -\
    \ *this;\r\n    }\r\n    Poly operator+(const Poly &g) const {\r\n        return\
    \ Poly(*this) += g;\r\n    }\r\n    Poly operator+(const T &g) const {\r\n   \
    \     return Poly(*this) += g;\r\n    }\r\n    Poly operator-(const Poly &g) const\
    \ {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator-(const T\
    \ &g) const {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator*(const\
    \ Poly &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator*(const\
    \ T &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator/(const\
    \ Poly &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator%(const\
    \ Poly &g) const {\r\n        return Poly(*this) %= g;\r\n    }\r\n    pair<Poly,\
    \ Poly> divmod(const Poly &g) const {\r\n        Poly q = *this / g, r = *this\
    \ - g * q;\r\n        r.shrink();\r\n        return {q, r};\r\n    }\r\n    Poly\
    \ &operator+=(const Poly &g) {\r\n        if (g.size() > this->size())\r\n   \
    \         this->resize(g.size());\r\n        rep(i, 0, g.size()) {\r\n       \
    \     (*this)[i] += g[i];\r\n        }\r\n        return *this;\r\n    }\r\n \
    \   Poly &operator+=(const T &g) {\r\n        if (this->empty())\r\n         \
    \   this->push_back(0);\r\n        (*this)[0] += g;\r\n        return *this;\r\
    \n    }\r\n    Poly &operator-=(const Poly &g) {\r\n        if (g.size() > this->size())\r\
    \n            this->resize(g.size());\r\n        rep(i, 0, g.size()) {\r\n   \
    \         (*this)[i] -= g[i];\r\n        }\r\n        return *this;\r\n    }\r\
    \n    Poly &operator-=(const T &g) {\r\n        if (this->empty())\r\n       \
    \     this->push_back(0);\r\n        (*this)[0] -= g;\r\n        return *this;\r\
    \n    }\r\n    Poly &operator*=(const Poly &g) {\r\n        *this = mult(*this,\
    \ g);\r\n        return *this;\r\n    }\r\n    Poly &operator*=(const T &g) {\r\
    \n        rep(i, 0, this->size())(*this)[i] *= g;\r\n        return *this;\r\n\
    \    }\r\n    Poly &operator/=(const Poly &g) {\r\n        if (g.size() > this->size())\
    \ {\r\n            this->clear();\r\n            return *this;\r\n        }\r\n\
    \        Poly g2 = g;\r\n        reverse(ALL(*this));\r\n        reverse(ALL(g2));\r\
    \n        int n = this->size() - g2.size() + 1;\r\n        this->resize(n);\r\n\
    \        g2.resize(n);\r\n        *this *= g2.inv();\r\n        this->resize(n);\r\
    \n        reverse(ALL(*this));\r\n        shrink();\r\n        return *this;\r\
    \n    }\r\n    Poly &operator%=(const Poly &g) {\r\n        *this -= *this / g\
    \ * g;\r\n        shrink();\r\n        return *this;\r\n    }\r\n    Poly diff()\
    \ const {\r\n        Poly res(this->size() - 1);\r\n        rep(i, 0, res.size())\
    \ res[i] = (*this)[i + 1] * (i + 1);\r\n        return res;\r\n    }\r\n    Poly\
    \ inte() const {\r\n        Poly res(this->size() + 1);\r\n        for (int i\
    \ = res.size() - 1; i; i--)\r\n            res[i] = (*this)[i - 1] / i;\r\n  \
    \      return res;\r\n    }\r\n    Poly log() const {\r\n        assert(this->front()\
    \ == 1);\r\n        const int n = this->size();\r\n        Poly res = diff() *\
    \ inv();\r\n        res = res.inte();\r\n        res.resize(n);\r\n        return\
    \ res;\r\n    }\r\n    Poly exp() const {\r\n        assert(this->front() == 0);\r\
    \n        const int n = this->size();\r\n        Poly res(1), g(1);\r\n      \
    \  res.front() = g.front() = 1;\r\n        for (int k = 1; k < n; k <<= 1) {\r\
    \n            g = (g + g - g.square() * res);\r\n            g.resize(k);\r\n\
    \            Poly q = *this;\r\n            q.resize(k);\r\n            q = q.diff();\r\
    \n            Poly w = (q + g * (res.diff() - res * q)), t = *this;\r\n      \
    \      w.resize(k * 2 - 1);\r\n            t.resize(k * 2);\r\n            res\
    \ = (res + res * (t - w.inte()));\r\n            res.resize(k * 2);\r\n      \
    \  }\r\n        res.resize(n);\r\n        return res;\r\n    }\r\n    Poly shift(const\
    \ int &c) const {\r\n        const int n = this->size();\r\n        Poly res =\
    \ *this, g(n);\r\n        g[0] = 1;\r\n        rep(i, 1, n) g[i] = g[i - 1] *\
    \ c / i;\r\n        vector<T> fact(n, 1);\r\n        rep(i, 0, n) {\r\n      \
    \      if (i)\r\n                fact[i] = fact[i - 1] * i;\r\n            res[i]\
    \ *= fact[i];\r\n        }\r\n        res = res.rev();\r\n        res *= g;\r\n\
    \        res.resize(n);\r\n        res = res.rev();\r\n        rep(i, 0, n) res[i]\
    \ /= fact[i];\r\n        return res;\r\n    }\r\n    Poly pow(ll t) {\r\n    \
    \    if (t == 0) {\r\n            Poly res(this->size());\r\n            res[0]\
    \ = 1;\r\n            return res;\r\n        }\r\n        int n = this->size(),\
    \ k = 0;\r\n        while (k < n and (*this)[k] == 0)\r\n            k++;\r\n\
    \        Poly res(n);\r\n        if (__int128_t(t) * k >= n)\r\n            return\
    \ res;\r\n        n -= t * k;\r\n        Poly g(n);\r\n        T c = (*this)[k],\
    \ ic = c.inv();\r\n        rep(i, 0, n) g[i] = (*this)[i + k] * ic;\r\n      \
    \  g = g.log();\r\n        for (auto &x : g)\r\n            x *= t;\r\n      \
    \  g = g.exp();\r\n        c = c.pow(t);\r\n        rep(i, 0, n) res[i + t * k]\
    \ = g[i] * c;\r\n        return res;\r\n    }\r\n    vector<T> mult(const vector<T>\
    \ &a, const vector<T> &b) const;\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series\
    \ (Arbitrary mod)\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> struct Poly : vector<T> {\r\n \
    \   Poly(int n = 0) {\r\n        this->assign(n, T());\r\n    }\r\n    Poly(const\
    \ initializer_list<T> f) : vector<T>::vector(f) {}\r\n    Poly(const vector<T>\
    \ &f) {\r\n        this->assign(ALL(f));\r\n    }\r\n    int deg() const {\r\n\
    \        return this->size() - 1;\r\n    }\r\n    T eval(const T &x) {\r\n   \
    \     T res;\r\n        for (int i = this->size() - 1; i >= 0; i--)\r\n      \
    \      res *= x, res += this->at(i);\r\n        return res;\r\n    }\r\n    Poly\
    \ rev() const {\r\n        Poly res = *this;\r\n        reverse(ALL(res));\r\n\
    \        return res;\r\n    }\r\n    void shrink() {\r\n        while (!this->empty()\
    \ and this->back() == 0)\r\n            this->pop_back();\r\n    }\r\n    Poly\
    \ operator>>(ll sz) const {\r\n        if ((int)this->size() <= sz)\r\n      \
    \      return {};\r\n        Poly ret(*this);\r\n        ret.erase(ret.begin(),\
    \ ret.begin() + sz);\r\n        return ret;\r\n    }\r\n    Poly operator<<(ll\
    \ sz) const {\r\n        Poly ret(*this);\r\n        ret.insert(ret.begin(), sz,\
    \ T(0));\r\n        return ret;\r\n    }\r\n    Poly inv() const {\r\n       \
    \ assert(this->front() != 0);\r\n        const int n = this->size();\r\n     \
    \   Poly res(1);\r\n        res.front() = T(1) / this->front();\r\n        for\
    \ (int k = 1; k < n; k <<= 1) {\r\n            Poly g = res, h = *this;\r\n  \
    \          h.resize(k * 2);\r\n            res.resize(k * 2);\r\n            g\
    \ = (g.square() * h);\r\n            g.resize(k * 2);\r\n            rep(i, k,\
    \ min(k * 2, n)) res[i] -= g[i];\r\n        }\r\n        res.resize(n);\r\n  \
    \      return res;\r\n    }\r\n    Poly square() const {\r\n        return Poly(mult(*this,\
    \ *this));\r\n    }\r\n    Poly operator-() const {\r\n        return Poly() -\
    \ *this;\r\n    }\r\n    Poly operator+(const Poly &g) const {\r\n        return\
    \ Poly(*this) += g;\r\n    }\r\n    Poly operator+(const T &g) const {\r\n   \
    \     return Poly(*this) += g;\r\n    }\r\n    Poly operator-(const Poly &g) const\
    \ {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator-(const T\
    \ &g) const {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator*(const\
    \ Poly &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator*(const\
    \ T &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator/(const\
    \ Poly &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator%(const\
    \ Poly &g) const {\r\n        return Poly(*this) %= g;\r\n    }\r\n    pair<Poly,\
    \ Poly> divmod(const Poly &g) const {\r\n        Poly q = *this / g, r = *this\
    \ - g * q;\r\n        r.shrink();\r\n        return {q, r};\r\n    }\r\n    Poly\
    \ &operator+=(const Poly &g) {\r\n        if (g.size() > this->size())\r\n   \
    \         this->resize(g.size());\r\n        rep(i, 0, g.size()) {\r\n       \
    \     (*this)[i] += g[i];\r\n        }\r\n        return *this;\r\n    }\r\n \
    \   Poly &operator+=(const T &g) {\r\n        if (this->empty())\r\n         \
    \   this->push_back(0);\r\n        (*this)[0] += g;\r\n        return *this;\r\
    \n    }\r\n    Poly &operator-=(const Poly &g) {\r\n        if (g.size() > this->size())\r\
    \n            this->resize(g.size());\r\n        rep(i, 0, g.size()) {\r\n   \
    \         (*this)[i] -= g[i];\r\n        }\r\n        return *this;\r\n    }\r\
    \n    Poly &operator-=(const T &g) {\r\n        if (this->empty())\r\n       \
    \     this->push_back(0);\r\n        (*this)[0] -= g;\r\n        return *this;\r\
    \n    }\r\n    Poly &operator*=(const Poly &g) {\r\n        *this = mult(*this,\
    \ g);\r\n        return *this;\r\n    }\r\n    Poly &operator*=(const T &g) {\r\
    \n        rep(i, 0, this->size())(*this)[i] *= g;\r\n        return *this;\r\n\
    \    }\r\n    Poly &operator/=(const Poly &g) {\r\n        if (g.size() > this->size())\
    \ {\r\n            this->clear();\r\n            return *this;\r\n        }\r\n\
    \        Poly g2 = g;\r\n        reverse(ALL(*this));\r\n        reverse(ALL(g2));\r\
    \n        int n = this->size() - g2.size() + 1;\r\n        this->resize(n);\r\n\
    \        g2.resize(n);\r\n        *this *= g2.inv();\r\n        this->resize(n);\r\
    \n        reverse(ALL(*this));\r\n        shrink();\r\n        return *this;\r\
    \n    }\r\n    Poly &operator%=(const Poly &g) {\r\n        *this -= *this / g\
    \ * g;\r\n        shrink();\r\n        return *this;\r\n    }\r\n    Poly diff()\
    \ const {\r\n        Poly res(this->size() - 1);\r\n        rep(i, 0, res.size())\
    \ res[i] = (*this)[i + 1] * (i + 1);\r\n        return res;\r\n    }\r\n    Poly\
    \ inte() const {\r\n        Poly res(this->size() + 1);\r\n        for (int i\
    \ = res.size() - 1; i; i--)\r\n            res[i] = (*this)[i - 1] / i;\r\n  \
    \      return res;\r\n    }\r\n    Poly log() const {\r\n        assert(this->front()\
    \ == 1);\r\n        const int n = this->size();\r\n        Poly res = diff() *\
    \ inv();\r\n        res = res.inte();\r\n        res.resize(n);\r\n        return\
    \ res;\r\n    }\r\n    Poly exp() const {\r\n        assert(this->front() == 0);\r\
    \n        const int n = this->size();\r\n        Poly res(1), g(1);\r\n      \
    \  res.front() = g.front() = 1;\r\n        for (int k = 1; k < n; k <<= 1) {\r\
    \n            g = (g + g - g.square() * res);\r\n            g.resize(k);\r\n\
    \            Poly q = *this;\r\n            q.resize(k);\r\n            q = q.diff();\r\
    \n            Poly w = (q + g * (res.diff() - res * q)), t = *this;\r\n      \
    \      w.resize(k * 2 - 1);\r\n            t.resize(k * 2);\r\n            res\
    \ = (res + res * (t - w.inte()));\r\n            res.resize(k * 2);\r\n      \
    \  }\r\n        res.resize(n);\r\n        return res;\r\n    }\r\n    Poly shift(const\
    \ int &c) const {\r\n        const int n = this->size();\r\n        Poly res =\
    \ *this, g(n);\r\n        g[0] = 1;\r\n        rep(i, 1, n) g[i] = g[i - 1] *\
    \ c / i;\r\n        vector<T> fact(n, 1);\r\n        rep(i, 0, n) {\r\n      \
    \      if (i)\r\n                fact[i] = fact[i - 1] * i;\r\n            res[i]\
    \ *= fact[i];\r\n        }\r\n        res = res.rev();\r\n        res *= g;\r\n\
    \        res.resize(n);\r\n        res = res.rev();\r\n        rep(i, 0, n) res[i]\
    \ /= fact[i];\r\n        return res;\r\n    }\r\n    Poly pow(ll t) {\r\n    \
    \    if (t == 0) {\r\n            Poly res(this->size());\r\n            res[0]\
    \ = 1;\r\n            return res;\r\n        }\r\n        int n = this->size(),\
    \ k = 0;\r\n        while (k < n and (*this)[k] == 0)\r\n            k++;\r\n\
    \        Poly res(n);\r\n        if (__int128_t(t) * k >= n)\r\n            return\
    \ res;\r\n        n -= t * k;\r\n        Poly g(n);\r\n        T c = (*this)[k],\
    \ ic = c.inv();\r\n        rep(i, 0, n) g[i] = (*this)[i + k] * ic;\r\n      \
    \  g = g.log();\r\n        for (auto &x : g)\r\n            x *= t;\r\n      \
    \  g = g.exp();\r\n        c = c.pow(t);\r\n        rep(i, 0, n) res[i + t * k]\
    \ = g[i] * c;\r\n        return res;\r\n    }\r\n    vector<T> mult(const vector<T>\
    \ &a, const vector<T> &b) const;\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series\
    \ (Arbitrary mod)\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/arbitraryfps.hpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/YUKI_1112.test.cpp
  - Verify/LC_multivariate_convolution_cyclic.test.cpp
  - Verify/YUKI_1080.test.cpp
  - Verify/YUKI_310.test.cpp
documentation_of: FPS/arbitraryfps.hpp
layout: document
redirect_from:
- /library/FPS/arbitraryfps.hpp
- /library/FPS/arbitraryfps.hpp.html
title: Formal Power Series (Arbitrary mod)
---
