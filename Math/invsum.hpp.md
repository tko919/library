---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Inverse Sum
    links: []
  bundledCode: "#line 2 \"Math/invsum.hpp\"\n\ndouble digamma(double x) {\n    double\
    \ res = 0;\n    while (x < 50)\n        res -= 1. / x, x += 1;\n    double xx\
    \ = 1. / x;\n    double xx2 = xx * xx;\n    double xx4 = xx2 * xx2;\n    res +=\
    \ log(x) - 0.5 * xx - xx2 / 12.0 + xx4 / 120 - xx4 * xx2 / 252;\n    return res;\n\
    }\n// 1/l + 1/(l + 1) + ... + 1/(r - 1)\ndouble inv_sum(double l, double r) {\n\
    \    return digamma(r) - digamma(l);\n}\n\n/**\n * @brief Inverse Sum\n */\n"
  code: "#pragma once\n\ndouble digamma(double x) {\n    double res = 0;\n    while\
    \ (x < 50)\n        res -= 1. / x, x += 1;\n    double xx = 1. / x;\n    double\
    \ xx2 = xx * xx;\n    double xx4 = xx2 * xx2;\n    res += log(x) - 0.5 * xx -\
    \ xx2 / 12.0 + xx4 / 120 - xx4 * xx2 / 252;\n    return res;\n}\n// 1/l + 1/(l\
    \ + 1) + ... + 1/(r - 1)\ndouble inv_sum(double l, double r) {\n    return digamma(r)\
    \ - digamma(l);\n}\n\n/**\n * @brief Inverse Sum\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/invsum.hpp
  requiredBy: []
  timestamp: '2025-06-13 01:50:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/invsum.hpp
layout: document
redirect_from:
- /library/Math/invsum.hpp
- /library/Math/invsum.hpp.html
title: Inverse Sum
---
