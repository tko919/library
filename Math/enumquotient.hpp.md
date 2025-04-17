---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate Quotients
    links: []
  bundledCode: "#line 2 \"Math/enumquotient.hpp\"\n\r\ntemplate <typename T, typename\
    \ F> void EnumQuotients(T n, F f) {\r\n    T SQ = sqrtl(n);\r\n    while (SQ *\
    \ SQ + SQ <= n)\r\n        SQ++;\r\n    T m = n / SQ;\r\n    rep(i, 1, m + 1)\
    \ f(n / (i + 1) + 1, n / i + 1);\r\n    rrep(i, 1, SQ) f(i, i + 1);\r\n}\r\n\r\
    \n/**\r\n * @brief Enumerate Quotients\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, typename F> void EnumQuotients(T\
    \ n, F f) {\r\n    T SQ = sqrtl(n);\r\n    while (SQ * SQ + SQ <= n)\r\n     \
    \   SQ++;\r\n    T m = n / SQ;\r\n    rep(i, 1, m + 1) f(n / (i + 1) + 1, n /\
    \ i + 1);\r\n    rrep(i, 1, SQ) f(i, i + 1);\r\n}\r\n\r\n/**\r\n * @brief Enumerate\
    \ Quotients\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/enumquotient.hpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/enumquotient.hpp
layout: document
redirect_from:
- /library/Math/enumquotient.hpp
- /library/Math/enumquotient.hpp.html
title: Enumerate Quotients
---
