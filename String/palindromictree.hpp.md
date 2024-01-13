---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Palindromic Tree
    links: []
  bundledCode: "#line 2 \"String/palindromictree.hpp\"\n\ntemplate <typename T> struct\
    \ PalindromicTree {\n    struct Node {\n        map<char, int> nxt;\n        int\
    \ link, len, id, cnt;\n        Node() {}\n        Node(int link, int len, int\
    \ id, int cnt)\n            : link(link), len(len), id(id), cnt(cnt) {}\n    };\n\
    \    T S;\n    vector<Node> nodes;\n    PalindromicTree() {}\n    PalindromicTree(const\
    \ T &S) : S(S) {\n        nodes.push_back(Node(0, -1, -1, 0));\n        nodes.push_back(Node(0,\
    \ 0, -1, 0));\n        int cur = 0;\n\n        rep(i, 0, SZ(S)) {\n          \
    \  int k = find(i, cur);\n            char c = S[i];\n            if (nodes[k].nxt.count(c))\
    \ {\n                cur = nodes[k].nxt[c];\n                nodes[cur].cnt++;\n\
    \                continue;\n            }\n            nodes[k].nxt[c] = SZ(nodes);\n\
    \            cur = SZ(nodes);\n            nodes.push_back(\n                Node(-1,\
    \ nodes[k].len + 2, i - nodes[k].len - 1, 1));\n            if (nodes.back().len\
    \ == 1)\n                nodes.back().link = 1;\n            else {\n        \
    \        int n = find(i, nodes[k].link);\n                nodes.back().link =\
    \ nodes[n].nxt[c];\n            }\n        }\n    }\n    vector<array<int, 3>>\
    \ get_freq() {\n        vector<array<int, 3>> ret;\n        for (int i = SZ(nodes)\
    \ - 1; i >= 2; i--) {\n            ret.push_back({nodes[i].len, nodes[i].id, nodes[i].cnt});\n\
    \            nodes[nodes[i].link].cnt += nodes[i].cnt;\n        }\n        return\
    \ ret;\n    }\n\n  private:\n    int find(int last, int k) const {\n        for\
    \ (;;) {\n            int i = last - 1 - nodes[k].len;\n            if (i >= 0\
    \ and S[i] == S[last])\n                break;\n            k = nodes[k].link;\n\
    \        }\n        return k;\n    }\n};\n\n/**\n * @brief Palindromic Tree\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T> struct PalindromicTree {\n    struct\
    \ Node {\n        map<char, int> nxt;\n        int link, len, id, cnt;\n     \
    \   Node() {}\n        Node(int link, int len, int id, int cnt)\n            :\
    \ link(link), len(len), id(id), cnt(cnt) {}\n    };\n    T S;\n    vector<Node>\
    \ nodes;\n    PalindromicTree() {}\n    PalindromicTree(const T &S) : S(S) {\n\
    \        nodes.push_back(Node(0, -1, -1, 0));\n        nodes.push_back(Node(0,\
    \ 0, -1, 0));\n        int cur = 0;\n\n        rep(i, 0, SZ(S)) {\n          \
    \  int k = find(i, cur);\n            char c = S[i];\n            if (nodes[k].nxt.count(c))\
    \ {\n                cur = nodes[k].nxt[c];\n                nodes[cur].cnt++;\n\
    \                continue;\n            }\n            nodes[k].nxt[c] = SZ(nodes);\n\
    \            cur = SZ(nodes);\n            nodes.push_back(\n                Node(-1,\
    \ nodes[k].len + 2, i - nodes[k].len - 1, 1));\n            if (nodes.back().len\
    \ == 1)\n                nodes.back().link = 1;\n            else {\n        \
    \        int n = find(i, nodes[k].link);\n                nodes.back().link =\
    \ nodes[n].nxt[c];\n            }\n        }\n    }\n    vector<array<int, 3>>\
    \ get_freq() {\n        vector<array<int, 3>> ret;\n        for (int i = SZ(nodes)\
    \ - 1; i >= 2; i--) {\n            ret.push_back({nodes[i].len, nodes[i].id, nodes[i].cnt});\n\
    \            nodes[nodes[i].link].cnt += nodes[i].cnt;\n        }\n        return\
    \ ret;\n    }\n\n  private:\n    int find(int last, int k) const {\n        for\
    \ (;;) {\n            int i = last - 1 - nodes[k].len;\n            if (i >= 0\
    \ and S[i] == S[last])\n                break;\n            k = nodes[k].link;\n\
    \        }\n        return k;\n    }\n};\n\n/**\n * @brief Palindromic Tree\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: String/palindromictree.hpp
  requiredBy: []
  timestamp: '2024-01-14 01:35:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/palindromictree.hpp
layout: document
redirect_from:
- /library/String/palindromictree.hpp
- /library/String/palindromictree.hpp.html
title: Palindromic Tree
---