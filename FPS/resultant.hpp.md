---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Resultant
    links: []
  bundledCode: "#line 2 \"FPS/resultant.hpp\"\n\ntemplate <typename T> T Resultant(Poly<T>\
    \ f, Poly<T> g) {\n    if (g.empty()) {\n        if (SZ(f) == 1)\n           \
    \ return 1;\n        else\n            return 0;\n    }\n    bool sign = 0;\n\
    \    T ret = 1;\n    for (;;) {\n        auto [q, r] = f.divmod(g);\n        if\
    \ (r.empty()) {\n            if (SZ(g) == 1)\n                ret *= g[0].pow(f.deg());\n\
    \            else\n                ret = 0;\n            break;\n        } else\
    \ {\n            if (f.deg() & 1 and g.deg() & 1)\n                sign ^= 1;\n\
    \            ret *= g.back().pow(f.deg() - r.deg());\n            swap(f, g);\n\
    \            g = r;\n        }\n    }\n    if (sign)\n        ret = -ret;\n  \
    \  return ret;\n}\n\n/**\n * @brief Resultant\n */\n"
  code: "#pragma once\n\ntemplate <typename T> T Resultant(Poly<T> f, Poly<T> g) {\n\
    \    if (g.empty()) {\n        if (SZ(f) == 1)\n            return 1;\n      \
    \  else\n            return 0;\n    }\n    bool sign = 0;\n    T ret = 1;\n  \
    \  for (;;) {\n        auto [q, r] = f.divmod(g);\n        if (r.empty()) {\n\
    \            if (SZ(g) == 1)\n                ret *= g[0].pow(f.deg());\n    \
    \        else\n                ret = 0;\n            break;\n        } else {\n\
    \            if (f.deg() & 1 and g.deg() & 1)\n                sign ^= 1;\n  \
    \          ret *= g.back().pow(f.deg() - r.deg());\n            swap(f, g);\n\
    \            g = r;\n        }\n    }\n    if (sign)\n        ret = -ret;\n  \
    \  return ret;\n}\n\n/**\n * @brief Resultant\n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/resultant.hpp
  requiredBy: []
  timestamp: '2025-05-11 13:37:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/resultant.hpp
layout: document
redirect_from:
- /library/FPS/resultant.hpp
- /library/FPS/resultant.hpp.html
title: Resultant
---
