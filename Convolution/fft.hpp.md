---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_frequency_table_of_tree_distance.test.cpp
    title: Verify/LC_frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Fast Fourier Transform
    links: []
  bundledCode: "#line 2 \"Convolution/fft.hpp\"\n\r\nnamespace FFT {\r\nstruct C {\r\
    \n    double x, y;\r\n    C(double _x = 0, double _y = 0) : x(_x), y(_y) {}\r\n\
    \    C operator~() const {\r\n        return C(x, -y);\r\n    }\r\n    C operator*(const\
    \ C &c) const {\r\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n\
    \    }\r\n    C operator+(const C &c) const {\r\n        return C(x + c.x, y +\
    \ c.y);\r\n    }\r\n    C operator-(const C &c) const {\r\n        return C(x\
    \ - c.x, y - c.y);\r\n    }\r\n};\r\nvector<vector<C>> w(1, vector<C>(1, 1));\r\
    \nvoid init(int lg) {\r\n    for (int d = 1, m = 1; d <= lg; d++, m <<= 1)\r\n\
    \        if (d >= (int)w.size()) {\r\n            w.emplace_back(m);\r\n     \
    \       const double th = M_PI / m;\r\n            for (int i = 0; i < m; i++)\r\
    \n                w[d][i] =\r\n                    (i & 1 ? C(cos(th * i), sin(th\
    \ * i)) : w[d - 1][i >> 1]);\r\n        }\r\n}\r\nvoid fft(vector<C> &f, bool\
    \ inv) {\r\n    const int n = f.size();\r\n    const int lg = __lg(n);\r\n   \
    \ if (lg >= (int)w.size())\r\n        init(lg);\r\n    if (inv) {\r\n        for\
    \ (int k = 1; k <= lg; k++) {\r\n            const int d = 1 << (k - 1);\r\n \
    \           for (int s = 0; s < n; s += 2 * d) {\r\n                for (int i\
    \ = s; i < s + d; i++) {\r\n                    C x = f[i], y = ~w[k][i - s] *\
    \ f[d + i];\r\n                    f[i] = x + y;\r\n                    f[d +\
    \ i] = x - y;\r\n                }\r\n            }\r\n        }\r\n    } else\
    \ {\r\n        for (int k = lg; k; k--) {\r\n            const int d = 1 << (k\
    \ - 1);\r\n            for (int s = 0; s < n; s += 2 * d) {\r\n              \
    \  for (int i = s; i < s + d; i++) {\r\n                    C x = f[i], y = f[d\
    \ + i];\r\n                    f[i] = x + y;\r\n                    f[d + i] =\
    \ w[k][i - s] * (x - y);\r\n                }\r\n            }\r\n        }\r\n\
    \    }\r\n}\r\ntemplate <typename T> vector<T> mult(const vector<T> &a, const\
    \ vector<T> &b) {\r\n    const int as = a.size();\r\n    const int bs = b.size();\r\
    \n    if (!as or !bs)\r\n        return {};\r\n    const int cs = as + bs - 1;\r\
    \n    vector<T> c(cs);\r\n    if (max(as, bs) < 16) {\r\n        for (int i =\
    \ 0; i < as; i++)\r\n            for (int j = 0; j < bs; j++) {\r\n          \
    \      c[i + j] += T(a[i]) * b[j];\r\n            }\r\n        return c;\r\n \
    \   }\r\n    const int n = 1 << __lg(2 * cs - 1);\r\n    vector<C> f(n);\r\n \
    \   for (int i = 0; i < as; i++)\r\n        f[i].x = a[i];\r\n    for (int i =\
    \ 0; i < bs; i++)\r\n        f[i].y = b[i];\r\n    fft(f, 0);\r\n    static const\
    \ C rad(0, -.25);\r\n    for (int i = 0; i < n; i++) {\r\n        int j = i ?\
    \ i ^ ((1 << __lg(i)) - 1) : 0;\r\n        if (i > j)\r\n            continue;\r\
    \n        C x = f[i] + ~f[j], y = f[i] - ~f[j];\r\n        f[i] = x * y * rad;\r\
    \n        f[j] = ~f[i];\r\n    }\r\n    fft(f, 1);\r\n    for (int i = 0; i <\
    \ cs; i++)\r\n        c[i] = T(f[i].x / n);\r\n    return c;\r\n}\r\ntemplate\
    \ <typename T> vector<T> square(const vector<T> &a) {\r\n    const int as = a.size();\r\
    \n    if (!as)\r\n        return {};\r\n    const int cs = as * 2 - 1;\r\n   \
    \ vector<T> c(cs);\r\n    if (as < 16) {\r\n        for (int i = 0; i < as; i++)\r\
    \n            for (int j = 0; j < as; j++) {\r\n                c[i + j] += (int)a[i]\
    \ * a[j];\r\n            }\r\n        return c;\r\n    }\r\n    const int n =\
    \ 1 << __lg(cs * 2 - 1);\r\n    vector<C> f(n);\r\n    for (int i = 0; i < as;\
    \ i++)\r\n        f[i].x = a[i];\r\n    fft(f, 0);\r\n    for (int i = 0; i <\
    \ n; i++)\r\n        f[i] = f[i] * f[i];\r\n    fft(f, 1);\r\n    for (int i =\
    \ 0; i < cs; i++)\r\n        c[i] = T(f[i].x / n);\r\n    return c;\r\n}\r\n}\
    \ // namespace FFT\r\n\r\n/**\r\n * @brief Fast Fourier Transform\r\n */\n"
  code: "#pragma once\r\n\r\nnamespace FFT {\r\nstruct C {\r\n    double x, y;\r\n\
    \    C(double _x = 0, double _y = 0) : x(_x), y(_y) {}\r\n    C operator~() const\
    \ {\r\n        return C(x, -y);\r\n    }\r\n    C operator*(const C &c) const\
    \ {\r\n        return C(x * c.x - y * c.y, x * c.y + y * c.x);\r\n    }\r\n  \
    \  C operator+(const C &c) const {\r\n        return C(x + c.x, y + c.y);\r\n\
    \    }\r\n    C operator-(const C &c) const {\r\n        return C(x - c.x, y -\
    \ c.y);\r\n    }\r\n};\r\nvector<vector<C>> w(1, vector<C>(1, 1));\r\nvoid init(int\
    \ lg) {\r\n    for (int d = 1, m = 1; d <= lg; d++, m <<= 1)\r\n        if (d\
    \ >= (int)w.size()) {\r\n            w.emplace_back(m);\r\n            const double\
    \ th = M_PI / m;\r\n            for (int i = 0; i < m; i++)\r\n              \
    \  w[d][i] =\r\n                    (i & 1 ? C(cos(th * i), sin(th * i)) : w[d\
    \ - 1][i >> 1]);\r\n        }\r\n}\r\nvoid fft(vector<C> &f, bool inv) {\r\n \
    \   const int n = f.size();\r\n    const int lg = __lg(n);\r\n    if (lg >= (int)w.size())\r\
    \n        init(lg);\r\n    if (inv) {\r\n        for (int k = 1; k <= lg; k++)\
    \ {\r\n            const int d = 1 << (k - 1);\r\n            for (int s = 0;\
    \ s < n; s += 2 * d) {\r\n                for (int i = s; i < s + d; i++) {\r\n\
    \                    C x = f[i], y = ~w[k][i - s] * f[d + i];\r\n            \
    \        f[i] = x + y;\r\n                    f[d + i] = x - y;\r\n          \
    \      }\r\n            }\r\n        }\r\n    } else {\r\n        for (int k =\
    \ lg; k; k--) {\r\n            const int d = 1 << (k - 1);\r\n            for\
    \ (int s = 0; s < n; s += 2 * d) {\r\n                for (int i = s; i < s +\
    \ d; i++) {\r\n                    C x = f[i], y = f[d + i];\r\n             \
    \       f[i] = x + y;\r\n                    f[d + i] = w[k][i - s] * (x - y);\r\
    \n                }\r\n            }\r\n        }\r\n    }\r\n}\r\ntemplate <typename\
    \ T> vector<T> mult(const vector<T> &a, const vector<T> &b) {\r\n    const int\
    \ as = a.size();\r\n    const int bs = b.size();\r\n    if (!as or !bs)\r\n  \
    \      return {};\r\n    const int cs = as + bs - 1;\r\n    vector<T> c(cs);\r\
    \n    if (max(as, bs) < 16) {\r\n        for (int i = 0; i < as; i++)\r\n    \
    \        for (int j = 0; j < bs; j++) {\r\n                c[i + j] += T(a[i])\
    \ * b[j];\r\n            }\r\n        return c;\r\n    }\r\n    const int n =\
    \ 1 << __lg(2 * cs - 1);\r\n    vector<C> f(n);\r\n    for (int i = 0; i < as;\
    \ i++)\r\n        f[i].x = a[i];\r\n    for (int i = 0; i < bs; i++)\r\n     \
    \   f[i].y = b[i];\r\n    fft(f, 0);\r\n    static const C rad(0, -.25);\r\n \
    \   for (int i = 0; i < n; i++) {\r\n        int j = i ? i ^ ((1 << __lg(i)) -\
    \ 1) : 0;\r\n        if (i > j)\r\n            continue;\r\n        C x = f[i]\
    \ + ~f[j], y = f[i] - ~f[j];\r\n        f[i] = x * y * rad;\r\n        f[j] =\
    \ ~f[i];\r\n    }\r\n    fft(f, 1);\r\n    for (int i = 0; i < cs; i++)\r\n  \
    \      c[i] = T(f[i].x / n);\r\n    return c;\r\n}\r\ntemplate <typename T> vector<T>\
    \ square(const vector<T> &a) {\r\n    const int as = a.size();\r\n    if (!as)\r\
    \n        return {};\r\n    const int cs = as * 2 - 1;\r\n    vector<T> c(cs);\r\
    \n    if (as < 16) {\r\n        for (int i = 0; i < as; i++)\r\n            for\
    \ (int j = 0; j < as; j++) {\r\n                c[i + j] += (int)a[i] * a[j];\r\
    \n            }\r\n        return c;\r\n    }\r\n    const int n = 1 << __lg(cs\
    \ * 2 - 1);\r\n    vector<C> f(n);\r\n    for (int i = 0; i < as; i++)\r\n   \
    \     f[i].x = a[i];\r\n    fft(f, 0);\r\n    for (int i = 0; i < n; i++)\r\n\
    \        f[i] = f[i] * f[i];\r\n    fft(f, 1);\r\n    for (int i = 0; i < cs;\
    \ i++)\r\n        c[i] = T(f[i].x / n);\r\n    return c;\r\n}\r\n} // namespace\
    \ FFT\r\n\r\n/**\r\n * @brief Fast Fourier Transform\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/fft.hpp
  requiredBy: []
  timestamp: '2025-05-11 13:37:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_frequency_table_of_tree_distance.test.cpp
documentation_of: Convolution/fft.hpp
layout: document
redirect_from:
- /library/Convolution/fft.hpp
- /library/Convolution/fft.hpp.html
title: Fast Fourier Transform
---
