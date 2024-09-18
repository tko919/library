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
  bundledCode: "#line 2 \"Math/enumquotient.hpp\"\n\r\ntemplate <typename T> vector<pair<T,\
    \ T>> EnumQuotients(T n) {\r\n    T SQ = sqrtl(n);\r\n    while (SQ * SQ + SQ\
    \ <= n)\r\n        SQ++;\r\n    T m = n / SQ;\r\n    vector<pair<T, T>> ret;\r\
    \n    rep(i, 1, m + 1) ret.emplace_back(n / (i + 1) + 1, n / i + 1);\r\n    rrep(i,\
    \ 1, SQ) ret.emplace_back(i, i + 1);\r\n    return ret;\r\n}\r\n\r\n/**\r\n *\
    \ @brief Enumerate Quotients\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <typename T> vector<pair<T, T>> EnumQuotients(T\
    \ n) {\r\n    T SQ = sqrtl(n);\r\n    while (SQ * SQ + SQ <= n)\r\n        SQ++;\r\
    \n    T m = n / SQ;\r\n    vector<pair<T, T>> ret;\r\n    rep(i, 1, m + 1) ret.emplace_back(n\
    \ / (i + 1) + 1, n / i + 1);\r\n    rrep(i, 1, SQ) ret.emplace_back(i, i + 1);\r\
    \n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Enumerate Quotients\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/enumquotient.hpp
  requiredBy: []
  timestamp: '2024-09-19 03:09:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/enumquotient.hpp
layout: document
redirect_from:
- /library/Math/enumquotient.hpp
- /library/Math/enumquotient.hpp.html
title: Enumerate Quotients
---
