---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Convex Hull Trick Monotone
    links: []
  bundledCode: "#line 2 \"DataStructure/chtmonotone.hpp\"\n\ntemplate <typename T,\
    \ bool isMin> struct ConvexHullTrickAddMonotone {\n#define F first\n#define S\
    \ second\n    using P = pair<T, T>;\n    deque<P> H;\n\n    ConvexHullTrickAddMonotone()\
    \ = default;\n\n    bool empty() const {\n        return H.empty();\n    }\n\n\
    \    void clear() {\n        H.clear();\n    }\n\n    inline int sgn(T x) {\n\
    \        return x == 0 ? 0 : (x < 0 ? -1 : 1);\n    }\n\n    using D = long double;\n\
    \n    inline bool check(const P &a, const P &b, const P &c) {\n        if (b.S\
    \ == a.S || c.S == b.S)\n            return sgn(b.F - a.F) * sgn(c.S - b.S) >=\n\
    \                   sgn(c.F - b.F) * sgn(b.S - a.S);\n\n        // return (b.F-a.F)*(c.S-b.S)\
    \ >= (b.S-a.S)*(c.F-b.F);\n        return D(b.F - a.F) * sgn(c.S - b.S) / D(abs(b.S\
    \ - a.S)) >=\n               D(c.F - b.F) * sgn(b.S - a.S) / D(abs(c.S - b.S));\n\
    \    }\n\n    void add(T a, T b) {\n        if (!isMin)\n            a *= -1,\
    \ b *= -1;\n        P line(a, b);\n        if (empty()) {\n            H.emplace_front(line);\n\
    \            return;\n        }\n        if (H.front().F <= a) {\n           \
    \ if (H.front().F == a) {\n                if (H.front().S <= b)\n           \
    \         return;\n                H.pop_front();\n            }\n           \
    \ while (H.size() >= 2 && check(line, H.front(), H[1]))\n                H.pop_front();\n\
    \            H.emplace_front(line);\n        } else {\n            assert(a <=\
    \ H.back().F);\n            if (H.back().F == a) {\n                if (H.back().S\
    \ <= b)\n                    return;\n                H.pop_back();\n        \
    \    }\n            while (H.size() >= 2 && check(H[H.size() - 2], H.back(), line))\n\
    \                H.pop_back();\n            H.emplace_back(line);\n        }\n\
    \    }\n\n    inline T get_y(const P &a, const T &x) {\n        return a.F * x\
    \ + a.S;\n    }\n\n    T query(T x) {\n        assert(!empty());\n        int\
    \ l = -1, r = H.size() - 1;\n        while (l + 1 < r) {\n            int m =\
    \ (l + r) >> 1;\n            if (get_y(H[m], x) >= get_y(H[m + 1], x))\n     \
    \           l = m;\n            else\n                r = m;\n        }\n    \
    \    if (isMin)\n            return get_y(H[r], x);\n        return -get_y(H[r],\
    \ x);\n    }\n\n    T query_monotone_inc(T x) {\n        assert(!empty());\n \
    \       while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))\n     \
    \       H.pop_front();\n        if (isMin)\n            return get_y(H.front(),\
    \ x);\n        return -get_y(H.front(), x);\n    }\n\n    T query_monotone_dec(T\
    \ x) {\n        assert(!empty());\n        while (H.size() >= 2 && get_y(H.back(),\
    \ x) >= get_y(H[H.size() - 2], x))\n            H.pop_back();\n        if (isMin)\n\
    \            return get_y(H.back(), x);\n        return -get_y(H.back(), x);\n\
    \    }\n\n#undef F\n#undef S\n};\n\n/**\n * @brief Convex Hull Trick Monotone\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T, bool isMin> struct ConvexHullTrickAddMonotone\
    \ {\n#define F first\n#define S second\n    using P = pair<T, T>;\n    deque<P>\
    \ H;\n\n    ConvexHullTrickAddMonotone() = default;\n\n    bool empty() const\
    \ {\n        return H.empty();\n    }\n\n    void clear() {\n        H.clear();\n\
    \    }\n\n    inline int sgn(T x) {\n        return x == 0 ? 0 : (x < 0 ? -1 :\
    \ 1);\n    }\n\n    using D = long double;\n\n    inline bool check(const P &a,\
    \ const P &b, const P &c) {\n        if (b.S == a.S || c.S == b.S)\n         \
    \   return sgn(b.F - a.F) * sgn(c.S - b.S) >=\n                   sgn(c.F - b.F)\
    \ * sgn(b.S - a.S);\n\n        // return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);\n\
    \        return D(b.F - a.F) * sgn(c.S - b.S) / D(abs(b.S - a.S)) >=\n       \
    \        D(c.F - b.F) * sgn(b.S - a.S) / D(abs(c.S - b.S));\n    }\n\n    void\
    \ add(T a, T b) {\n        if (!isMin)\n            a *= -1, b *= -1;\n      \
    \  P line(a, b);\n        if (empty()) {\n            H.emplace_front(line);\n\
    \            return;\n        }\n        if (H.front().F <= a) {\n           \
    \ if (H.front().F == a) {\n                if (H.front().S <= b)\n           \
    \         return;\n                H.pop_front();\n            }\n           \
    \ while (H.size() >= 2 && check(line, H.front(), H[1]))\n                H.pop_front();\n\
    \            H.emplace_front(line);\n        } else {\n            assert(a <=\
    \ H.back().F);\n            if (H.back().F == a) {\n                if (H.back().S\
    \ <= b)\n                    return;\n                H.pop_back();\n        \
    \    }\n            while (H.size() >= 2 && check(H[H.size() - 2], H.back(), line))\n\
    \                H.pop_back();\n            H.emplace_back(line);\n        }\n\
    \    }\n\n    inline T get_y(const P &a, const T &x) {\n        return a.F * x\
    \ + a.S;\n    }\n\n    T query(T x) {\n        assert(!empty());\n        int\
    \ l = -1, r = H.size() - 1;\n        while (l + 1 < r) {\n            int m =\
    \ (l + r) >> 1;\n            if (get_y(H[m], x) >= get_y(H[m + 1], x))\n     \
    \           l = m;\n            else\n                r = m;\n        }\n    \
    \    if (isMin)\n            return get_y(H[r], x);\n        return -get_y(H[r],\
    \ x);\n    }\n\n    T query_monotone_inc(T x) {\n        assert(!empty());\n \
    \       while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))\n     \
    \       H.pop_front();\n        if (isMin)\n            return get_y(H.front(),\
    \ x);\n        return -get_y(H.front(), x);\n    }\n\n    T query_monotone_dec(T\
    \ x) {\n        assert(!empty());\n        while (H.size() >= 2 && get_y(H.back(),\
    \ x) >= get_y(H[H.size() - 2], x))\n            H.pop_back();\n        if (isMin)\n\
    \            return get_y(H.back(), x);\n        return -get_y(H.back(), x);\n\
    \    }\n\n#undef F\n#undef S\n};\n\n/**\n * @brief Convex Hull Trick Monotone\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/chtmonotone.hpp
  requiredBy: []
  timestamp: '2024-10-22 03:59:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/chtmonotone.hpp
layout: document
redirect_from:
- /library/DataStructure/chtmonotone.hpp
- /library/DataStructure/chtmonotone.hpp.html
title: Convex Hull Trick Monotone
---
