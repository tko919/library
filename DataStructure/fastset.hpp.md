---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fast Set
    links: []
  bundledCode: "#line 2 \"DataStructure/fastset.hpp\"\n\nstruct FastSet {\n    static\
    \ constexpr int B = 64;\n    int n, lg;\n    vector<vector<ull>> seg;\n    FastSet(int\
    \ m) : n(m) {\n        do {\n            seg.push_back(vector<ull>((m + B - 1)\
    \ / B));\n            m = (m + B - 1) / B;\n        } while (m > 1);\n       \
    \ lg = seg.size();\n    }\n    bool operator[](int i) const {\n        return\
    \ (seg[0][i / B] >> (i % B) & 1);\n    }\n    void insert(int i) {\n        rep(h,\
    \ 0, lg) {\n            seg[h][i / B] |= 1ull << (i % B);\n            i /= B;\n\
    \        }\n    }\n    void erase(int i) {\n        rep(h, 0, lg) {\n        \
    \    seg[h][i / B] &= ~(1ull << (i % B));\n            if (seg[h][i / B])\n  \
    \              break;\n            i /= B;\n        }\n    }\n    // smallest\
    \ >= i\n    int next(int i) {\n        rep(h, 0, lg) {\n            if (i / B\
    \ == seg[h].size())\n                break;\n            ull d = seg[h][i / B]\
    \ >> (i % B);\n            if (!d) {\n                i = i / B + 1;\n       \
    \         continue;\n            }\n            i += lowbit(d);\n            for\
    \ (int g = h - 1; g >= 0; g--) {\n                i *= B;\n                i +=\
    \ lowbit(seg[g][i / B]);\n            }\n            return i;\n        }\n  \
    \      return -1;\n    }\n    // largest <= i\n    int prev(int i) {\n       \
    \ rep(h, 0, lg) {\n            if (i == -1)\n                break;\n        \
    \    ull d = seg[h][i / B] << (63 - i % 64);\n            if (!d) {\n        \
    \        i = i / B - 1;\n                continue;\n            }\n          \
    \  i += topbit(d) - (B - 1);\n            for (int g = h - 1; g >= 0; g--) {\n\
    \                i *= B;\n                i += topbit(seg[g][i / B]);\n      \
    \      }\n            return i;\n        }\n        return -1;\n    }\n};\n\n\
    /**\n * @brief Fast Set\n */\n"
  code: "#pragma once\n\nstruct FastSet {\n    static constexpr int B = 64;\n    int\
    \ n, lg;\n    vector<vector<ull>> seg;\n    FastSet(int m) : n(m) {\n        do\
    \ {\n            seg.push_back(vector<ull>((m + B - 1) / B));\n            m =\
    \ (m + B - 1) / B;\n        } while (m > 1);\n        lg = seg.size();\n    }\n\
    \    bool operator[](int i) const {\n        return (seg[0][i / B] >> (i % B)\
    \ & 1);\n    }\n    void insert(int i) {\n        rep(h, 0, lg) {\n          \
    \  seg[h][i / B] |= 1ull << (i % B);\n            i /= B;\n        }\n    }\n\
    \    void erase(int i) {\n        rep(h, 0, lg) {\n            seg[h][i / B] &=\
    \ ~(1ull << (i % B));\n            if (seg[h][i / B])\n                break;\n\
    \            i /= B;\n        }\n    }\n    // smallest >= i\n    int next(int\
    \ i) {\n        rep(h, 0, lg) {\n            if (i / B == seg[h].size())\n   \
    \             break;\n            ull d = seg[h][i / B] >> (i % B);\n        \
    \    if (!d) {\n                i = i / B + 1;\n                continue;\n  \
    \          }\n            i += lowbit(d);\n            for (int g = h - 1; g >=\
    \ 0; g--) {\n                i *= B;\n                i += lowbit(seg[g][i / B]);\n\
    \            }\n            return i;\n        }\n        return -1;\n    }\n\
    \    // largest <= i\n    int prev(int i) {\n        rep(h, 0, lg) {\n       \
    \     if (i == -1)\n                break;\n            ull d = seg[h][i / B]\
    \ << (63 - i % 64);\n            if (!d) {\n                i = i / B - 1;\n \
    \               continue;\n            }\n            i += topbit(d) - (B - 1);\n\
    \            for (int g = h - 1; g >= 0; g--) {\n                i *= B;\n   \
    \             i += topbit(seg[g][i / B]);\n            }\n            return i;\n\
    \        }\n        return -1;\n    }\n};\n\n/**\n * @brief Fast Set\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/fastset.hpp
  requiredBy: []
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/fastset.hpp
layout: document
redirect_from:
- /library/DataStructure/fastset.hpp
- /library/DataStructure/fastset.hpp.html
title: Fast Set
---
