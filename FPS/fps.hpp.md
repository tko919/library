---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bernoulli_number.test.cpp
    title: Verify/LC_bernoulli_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  - icon: ':x:'
    path: Verify/LC_exp_of_formal_power_series.test.cpp
    title: Verify/LC_exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: Verify/LC_inv_of_formal_power_series.test.cpp
    title: Verify/LC_inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: Verify/LC_log_of_formal_power_series.test.cpp
    title: Verify/LC_log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: Verify/LC_many_factorials.test.cpp
    title: Verify/LC_many_factorials.test.cpp
  - icon: ':x:'
    path: Verify/LC_multipoint_evaluation.test.cpp
    title: Verify/LC_multipoint_evaluation.test.cpp
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
    path: Verify/YUKI_2097.test.cpp
    title: Verify/YUKI_2097.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Formal Power Series (NTT-friendly mod)
    links: []
  bundledCode: "#line 2 \"FPS/fps.hpp\"\n\r\ntemplate <typename T> struct Poly : vector<T>\
    \ {\r\n    Poly(int n = 0) {\r\n        this->assign(n, T());\r\n    }\r\n   \
    \ Poly(const initializer_list<T> f) : vector<T>::vector(f) {}\r\n    Poly(const\
    \ vector<T> &f) {\r\n        this->assign(ALL(f));\r\n    }\r\n    int deg() const\
    \ {\r\n        return this->size() - 1;\r\n    }\r\n    T eval(const T &x) {\r\
    \n        T res;\r\n        for (int i = this->size() - 1; i >= 0; i--)\r\n  \
    \          res *= x, res += this->at(i);\r\n        return res;\r\n    }\r\n \
    \   Poly rev() const {\r\n        Poly res = *this;\r\n        reverse(ALL(res));\r\
    \n        return res;\r\n    }\r\n    void shrink() {\r\n        while (!this->empty()\
    \ and this->back() == 0)\r\n            this->pop_back();\r\n    }\r\n    Poly\
    \ operator>>(ll sz) const {\r\n        if ((int)this->size() <= sz)\r\n      \
    \      return {};\r\n        Poly ret(*this);\r\n        ret.erase(ret.begin(),\
    \ ret.begin() + sz);\r\n        return ret;\r\n    }\r\n    Poly operator<<(ll\
    \ sz) const {\r\n        Poly ret(*this);\r\n        ret.insert(ret.begin(), sz,\
    \ T(0));\r\n        return ret;\r\n    }\r\n    Poly<T> mult(const Poly<T> &a,\
    \ const Poly<T> &b) {\r\n        if (a.empty() or b.empty())\r\n            return\
    \ {};\r\n        int as = a.size(), bs = b.size();\r\n        int n = as + bs\
    \ - 1;\r\n        if (as <= 30 or bs <= 30) {\r\n            if (as > 30)\r\n\
    \                return mult(b, a);\r\n            Poly<T> res(n);\r\n       \
    \     rep(i, 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];\r\n            return\
    \ res;\r\n        }\r\n        int m = 1;\r\n        while (m < n)\r\n       \
    \     m <<= 1;\r\n        Poly<T> res(m);\r\n        rep(i, 0, as) res[i] = a[i];\r\
    \n        res.NTT(0);\r\n        if (a == b)\r\n            rep(i, 0, m) res[i]\
    \ *= res[i];\r\n        else {\r\n            Poly<T> c(m);\r\n            rep(i,\
    \ 0, bs) c[i] = b[i];\r\n            c.NTT(0);\r\n            rep(i, 0, m) res[i]\
    \ *= c[i];\r\n        }\r\n        res.NTT(1);\r\n        res.resize(n);\r\n \
    \       return res;\r\n    }\r\n    Poly square() const {\r\n        return Poly(mult(*this,\
    \ *this));\r\n    }\r\n    Poly operator-() const {\r\n        return Poly() -\
    \ *this;\r\n    }\r\n    Poly operator+(const Poly &g) const {\r\n        return\
    \ Poly(*this) += g;\r\n    }\r\n    Poly operator+(const T &g) const {\r\n   \
    \     return Poly(*this) += g;\r\n    }\r\n    Poly operator-(const Poly &g) const\
    \ {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator-(const T\
    \ &g) const {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator*(const\
    \ Poly &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator*(const\
    \ T &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator/(const\
    \ Poly &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator/(const\
    \ T &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator%(const\
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
    \n    }\r\n    Poly &operator/=(const T &g) {\r\n        rep(i, 0, this->size())(*this)[i]\
    \ /= g;\r\n        return *this;\r\n    }\r\n    Poly &operator%=(const Poly &g)\
    \ {\r\n        *this -= *this / g * g;\r\n        shrink();\r\n        return\
    \ *this;\r\n    }\r\n    Poly diff() const {\r\n        Poly res(this->size()\
    \ - 1);\r\n        rep(i, 0, res.size()) res[i] = (*this)[i + 1] * (i + 1);\r\n\
    \        return res;\r\n    }\r\n    Poly inte() const {\r\n        Poly res(this->size()\
    \ + 1);\r\n        for (int i = res.size() - 1; i; i--)\r\n            res[i]\
    \ = (*this)[i - 1] / i;\r\n        return res;\r\n    }\r\n    Poly log() const\
    \ {\r\n        assert(this->front() == 1);\r\n        const int n = this->size();\r\
    \n        Poly res = diff() * inv();\r\n        res = res.inte();\r\n        res.resize(n);\r\
    \n        return res;\r\n    }\r\n    Poly shift(const int &c) const {\r\n   \
    \     const int n = this->size();\r\n        Poly res = *this, g(n);\r\n     \
    \   g[0] = 1;\r\n        rep(i, 1, n) g[i] = g[i - 1] * c / i;\r\n        vector<T>\
    \ fact(n, 1);\r\n        rep(i, 0, n) {\r\n            if (i)\r\n            \
    \    fact[i] = fact[i - 1] * i;\r\n            res[i] *= fact[i];\r\n        }\r\
    \n        res = res.rev();\r\n        res *= g;\r\n        res.resize(n);\r\n\
    \        res = res.rev();\r\n        rep(i, 0, n) res[i] /= fact[i];\r\n     \
    \   return res;\r\n    }\r\n    Poly inv() const {\r\n        const int n = this->size();\r\
    \n        Poly res(1);\r\n        res.front() = T(1) / this->front();\r\n    \
    \    for (int k = 1; k < n; k <<= 1) {\r\n            Poly f(k * 2), g(k * 2);\r\
    \n            rep(i, 0, min(n, k * 2)) f[i] = (*this)[i];\r\n            rep(i,\
    \ 0, k) g[i] = res[i];\r\n            f.NTT(0);\r\n            g.NTT(0);\r\n \
    \           rep(i, 0, k * 2) f[i] *= g[i];\r\n            f.NTT(1);\r\n      \
    \      rep(i, 0, k) {\r\n                f[i] = 0;\r\n                f[i + k]\
    \ = -f[i + k];\r\n            }\r\n            f.NTT(0);\r\n            rep(i,\
    \ 0, k * 2) f[i] *= g[i];\r\n            f.NTT(1);\r\n            rep(i, 0, k)\
    \ f[i] = res[i];\r\n            swap(res, f);\r\n        }\r\n        res.resize(n);\r\
    \n        return res;\r\n    }\r\n    Poly exp() const {\r\n        const int\
    \ n = this->size();\r\n        if (n == 1)\r\n            return Poly({T(1)});\r\
    \n        Poly b(2), c(1), z1, z2(2);\r\n        b[0] = c[0] = z2[0] = z2[1] =\
    \ 1;\r\n        b[1] = (*this)[1];\r\n        for (int k = 2; k < n; k <<= 1)\
    \ {\r\n            Poly y = b;\r\n            y.resize(k * 2);\r\n           \
    \ y.NTT(0);\r\n            z1 = z2;\r\n            Poly z(k);\r\n            rep(i,\
    \ 0, k) z[i] = y[i] * z1[i];\r\n            z.NTT(1);\r\n            rep(i, 0,\
    \ k >> 1) z[i] = 0;\r\n            z.NTT(0);\r\n            rep(i, 0, k) z[i]\
    \ *= -z1[i];\r\n            z.NTT(1);\r\n            c.insert(c.end(), z.begin()\
    \ + (k >> 1), z.end());\r\n            z2 = c;\r\n            z2.resize(k * 2);\r\
    \n            z2.NTT(0);\r\n            Poly x = *this;\r\n            x.resize(k);\r\
    \n            x = x.diff();\r\n            x.resize(k);\r\n            x.NTT(0);\r\
    \n            rep(i, 0, k) x[i] *= y[i];\r\n            x.NTT(1);\r\n        \
    \    Poly bb = b.diff();\r\n            rep(i, 0, k - 1) x[i] -= bb[i];\r\n  \
    \          x.resize(k * 2);\r\n            rep(i, 0, k - 1) {\r\n            \
    \    x[k + i] = x[i];\r\n                x[i] = 0;\r\n            }\r\n      \
    \      x.NTT(0);\r\n            rep(i, 0, k * 2) x[i] *= z2[i];\r\n          \
    \  x.NTT(1);\r\n            x.pop_back();\r\n            x = x.inte();\r\n   \
    \         rep(i, k, min(n, k * 2)) x[i] += (*this)[i];\r\n            rep(i, 0,\
    \ k) x[i] = 0;\r\n            x.NTT(0);\r\n            rep(i, 0, k * 2) x[i] *=\
    \ y[i];\r\n            x.NTT(1);\r\n            b.insert(b.end(), x.begin() +\
    \ k, x.end());\r\n        }\r\n        b.resize(n);\r\n        return b;\r\n \
    \   }\r\n    Poly pow(ll t) {\r\n        if (t == 0) {\r\n            Poly res(this->size());\r\
    \n            res[0] = 1;\r\n            return res;\r\n        }\r\n        int\
    \ n = this->size(), k = 0;\r\n        while (k < n and (*this)[k] == 0)\r\n  \
    \          k++;\r\n        Poly res(n);\r\n        if (__int128_t(t) * k >= n)\r\
    \n            return res;\r\n        n -= t * k;\r\n        Poly g(n);\r\n   \
    \     T c = (*this)[k], ic = c.inv();\r\n        rep(i, 0, n) g[i] = (*this)[i\
    \ + k] * ic;\r\n        g = g.log();\r\n        for (auto &x : g)\r\n        \
    \    x *= t;\r\n        g = g.exp();\r\n        c = c.pow(t);\r\n        rep(i,\
    \ 0, n) res[i + t * k] = g[i] * c;\r\n        return res;\r\n    }\r\n    void\
    \ NTT(bool inv);\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series (NTT-friendly\
    \ mod)\r\n */\n"
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
    \ T(0));\r\n        return ret;\r\n    }\r\n    Poly<T> mult(const Poly<T> &a,\
    \ const Poly<T> &b) {\r\n        if (a.empty() or b.empty())\r\n            return\
    \ {};\r\n        int as = a.size(), bs = b.size();\r\n        int n = as + bs\
    \ - 1;\r\n        if (as <= 30 or bs <= 30) {\r\n            if (as > 30)\r\n\
    \                return mult(b, a);\r\n            Poly<T> res(n);\r\n       \
    \     rep(i, 0, as) rep(j, 0, bs) res[i + j] += a[i] * b[j];\r\n            return\
    \ res;\r\n        }\r\n        int m = 1;\r\n        while (m < n)\r\n       \
    \     m <<= 1;\r\n        Poly<T> res(m);\r\n        rep(i, 0, as) res[i] = a[i];\r\
    \n        res.NTT(0);\r\n        if (a == b)\r\n            rep(i, 0, m) res[i]\
    \ *= res[i];\r\n        else {\r\n            Poly<T> c(m);\r\n            rep(i,\
    \ 0, bs) c[i] = b[i];\r\n            c.NTT(0);\r\n            rep(i, 0, m) res[i]\
    \ *= c[i];\r\n        }\r\n        res.NTT(1);\r\n        res.resize(n);\r\n \
    \       return res;\r\n    }\r\n    Poly square() const {\r\n        return Poly(mult(*this,\
    \ *this));\r\n    }\r\n    Poly operator-() const {\r\n        return Poly() -\
    \ *this;\r\n    }\r\n    Poly operator+(const Poly &g) const {\r\n        return\
    \ Poly(*this) += g;\r\n    }\r\n    Poly operator+(const T &g) const {\r\n   \
    \     return Poly(*this) += g;\r\n    }\r\n    Poly operator-(const Poly &g) const\
    \ {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator-(const T\
    \ &g) const {\r\n        return Poly(*this) -= g;\r\n    }\r\n    Poly operator*(const\
    \ Poly &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator*(const\
    \ T &g) const {\r\n        return Poly(*this) *= g;\r\n    }\r\n    Poly operator/(const\
    \ Poly &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator/(const\
    \ T &g) const {\r\n        return Poly(*this) /= g;\r\n    }\r\n    Poly operator%(const\
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
    \n    }\r\n    Poly &operator/=(const T &g) {\r\n        rep(i, 0, this->size())(*this)[i]\
    \ /= g;\r\n        return *this;\r\n    }\r\n    Poly &operator%=(const Poly &g)\
    \ {\r\n        *this -= *this / g * g;\r\n        shrink();\r\n        return\
    \ *this;\r\n    }\r\n    Poly diff() const {\r\n        Poly res(this->size()\
    \ - 1);\r\n        rep(i, 0, res.size()) res[i] = (*this)[i + 1] * (i + 1);\r\n\
    \        return res;\r\n    }\r\n    Poly inte() const {\r\n        Poly res(this->size()\
    \ + 1);\r\n        for (int i = res.size() - 1; i; i--)\r\n            res[i]\
    \ = (*this)[i - 1] / i;\r\n        return res;\r\n    }\r\n    Poly log() const\
    \ {\r\n        assert(this->front() == 1);\r\n        const int n = this->size();\r\
    \n        Poly res = diff() * inv();\r\n        res = res.inte();\r\n        res.resize(n);\r\
    \n        return res;\r\n    }\r\n    Poly shift(const int &c) const {\r\n   \
    \     const int n = this->size();\r\n        Poly res = *this, g(n);\r\n     \
    \   g[0] = 1;\r\n        rep(i, 1, n) g[i] = g[i - 1] * c / i;\r\n        vector<T>\
    \ fact(n, 1);\r\n        rep(i, 0, n) {\r\n            if (i)\r\n            \
    \    fact[i] = fact[i - 1] * i;\r\n            res[i] *= fact[i];\r\n        }\r\
    \n        res = res.rev();\r\n        res *= g;\r\n        res.resize(n);\r\n\
    \        res = res.rev();\r\n        rep(i, 0, n) res[i] /= fact[i];\r\n     \
    \   return res;\r\n    }\r\n    Poly inv() const {\r\n        const int n = this->size();\r\
    \n        Poly res(1);\r\n        res.front() = T(1) / this->front();\r\n    \
    \    for (int k = 1; k < n; k <<= 1) {\r\n            Poly f(k * 2), g(k * 2);\r\
    \n            rep(i, 0, min(n, k * 2)) f[i] = (*this)[i];\r\n            rep(i,\
    \ 0, k) g[i] = res[i];\r\n            f.NTT(0);\r\n            g.NTT(0);\r\n \
    \           rep(i, 0, k * 2) f[i] *= g[i];\r\n            f.NTT(1);\r\n      \
    \      rep(i, 0, k) {\r\n                f[i] = 0;\r\n                f[i + k]\
    \ = -f[i + k];\r\n            }\r\n            f.NTT(0);\r\n            rep(i,\
    \ 0, k * 2) f[i] *= g[i];\r\n            f.NTT(1);\r\n            rep(i, 0, k)\
    \ f[i] = res[i];\r\n            swap(res, f);\r\n        }\r\n        res.resize(n);\r\
    \n        return res;\r\n    }\r\n    Poly exp() const {\r\n        const int\
    \ n = this->size();\r\n        if (n == 1)\r\n            return Poly({T(1)});\r\
    \n        Poly b(2), c(1), z1, z2(2);\r\n        b[0] = c[0] = z2[0] = z2[1] =\
    \ 1;\r\n        b[1] = (*this)[1];\r\n        for (int k = 2; k < n; k <<= 1)\
    \ {\r\n            Poly y = b;\r\n            y.resize(k * 2);\r\n           \
    \ y.NTT(0);\r\n            z1 = z2;\r\n            Poly z(k);\r\n            rep(i,\
    \ 0, k) z[i] = y[i] * z1[i];\r\n            z.NTT(1);\r\n            rep(i, 0,\
    \ k >> 1) z[i] = 0;\r\n            z.NTT(0);\r\n            rep(i, 0, k) z[i]\
    \ *= -z1[i];\r\n            z.NTT(1);\r\n            c.insert(c.end(), z.begin()\
    \ + (k >> 1), z.end());\r\n            z2 = c;\r\n            z2.resize(k * 2);\r\
    \n            z2.NTT(0);\r\n            Poly x = *this;\r\n            x.resize(k);\r\
    \n            x = x.diff();\r\n            x.resize(k);\r\n            x.NTT(0);\r\
    \n            rep(i, 0, k) x[i] *= y[i];\r\n            x.NTT(1);\r\n        \
    \    Poly bb = b.diff();\r\n            rep(i, 0, k - 1) x[i] -= bb[i];\r\n  \
    \          x.resize(k * 2);\r\n            rep(i, 0, k - 1) {\r\n            \
    \    x[k + i] = x[i];\r\n                x[i] = 0;\r\n            }\r\n      \
    \      x.NTT(0);\r\n            rep(i, 0, k * 2) x[i] *= z2[i];\r\n          \
    \  x.NTT(1);\r\n            x.pop_back();\r\n            x = x.inte();\r\n   \
    \         rep(i, k, min(n, k * 2)) x[i] += (*this)[i];\r\n            rep(i, 0,\
    \ k) x[i] = 0;\r\n            x.NTT(0);\r\n            rep(i, 0, k * 2) x[i] *=\
    \ y[i];\r\n            x.NTT(1);\r\n            b.insert(b.end(), x.begin() +\
    \ k, x.end());\r\n        }\r\n        b.resize(n);\r\n        return b;\r\n \
    \   }\r\n    Poly pow(ll t) {\r\n        if (t == 0) {\r\n            Poly res(this->size());\r\
    \n            res[0] = 1;\r\n            return res;\r\n        }\r\n        int\
    \ n = this->size(), k = 0;\r\n        while (k < n and (*this)[k] == 0)\r\n  \
    \          k++;\r\n        Poly res(n);\r\n        if (__int128_t(t) * k >= n)\r\
    \n            return res;\r\n        n -= t * k;\r\n        Poly g(n);\r\n   \
    \     T c = (*this)[k], ic = c.inv();\r\n        rep(i, 0, n) g[i] = (*this)[i\
    \ + k] * ic;\r\n        g = g.log();\r\n        for (auto &x : g)\r\n        \
    \    x *= t;\r\n        g = g.exp();\r\n        c = c.pow(t);\r\n        rep(i,\
    \ 0, n) res[i + t * k] = g[i] * c;\r\n        return res;\r\n    }\r\n    void\
    \ NTT(bool inv);\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series (NTT-friendly\
    \ mod)\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/fps.hpp
  requiredBy: []
  timestamp: '2024-04-30 04:21:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_polynomial_interpolation.test.cpp
  - Verify/LC_multipoint_evaluation.test.cpp
  - Verify/LC_shift_of_sampling_points_of_polynomial.test.cpp
  - Verify/LC_bernoulli_number.test.cpp
  - Verify/LC_sparse_matrix_det.test.cpp
  - Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - Verify/LC_product_of_polynomial_sequence.test.cpp
  - Verify/LC_partition_function.test.cpp
  - Verify/LC_exp_of_formal_power_series.test.cpp
  - Verify/YUKI_2097.test.cpp
  - Verify/LC_many_factorials.test.cpp
  - Verify/LC_log_of_formal_power_series.test.cpp
  - Verify/LC_stirling_number_of_the_second_kind.test.cpp
  - Verify/LC_pow_of_formal_power_series.test.cpp
  - Verify/LC_inv_of_formal_power_series.test.cpp
  - Verify/LC_polynomial_taylor_shift.test.cpp
  - Verify/LC_stirling_number_of_the_first_kind.test.cpp
  - Verify/LC_convolution_mod_2.test.cpp
documentation_of: FPS/fps.hpp
layout: document
redirect_from:
- /library/FPS/fps.hpp
- /library/FPS/fps.hpp.html
title: Formal Power Series (NTT-friendly mod)
---
