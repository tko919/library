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
  bundledCode: "#line 2 \"String/palindromictree.hpp\"\n\nstruct PalindromicTree {\n\
    \    struct Node {\n        map<char, int> nxt;\n        int link, len, id, cnt;\n\
    \        Node() {\n        }\n        Node(int link, int len, int id, int cnt)\n\
    \            : link(link), len(len), id(id), cnt(cnt) {\n        }\n    };\n \
    \   vector<char> S;\n    int cur;\n    vector<Node> nodes;\n    PalindromicTree()\
    \ {\n        nodes.push_back(Node(0, -1, -1, 0));\n        nodes.push_back(Node(0,\
    \ 0, -1, 0));\n        cur = 0;\n    }\n    void push(char c) {\n        S.push_back(c);\n\
    \        int k = find(SZ(S) - 1, cur, S);\n        if (nodes[k].nxt.count(c))\
    \ {\n            cur = nodes[k].nxt[c];\n            nodes[cur].cnt++;\n     \
    \       return;\n        }\n        nodes[k].nxt[c] = SZ(nodes);\n        cur\
    \ = SZ(nodes);\n        nodes.push_back(\n            Node(-1, nodes[k].len +\
    \ 2, (SZ(S) - 1) - nodes[k].len - 1, 1));\n        if (nodes.back().len == 1)\n\
    \            nodes.back().link = 1;\n        else {\n            int n = find(SZ(S)\
    \ - 1, nodes[k].link, S);\n            nodes.back().link = nodes[n].nxt[c];\n\
    \        }\n    }\n    vector<array<int, 3>> get_freq() {\n        vector<array<int,\
    \ 3>> ret;\n        for (int i = SZ(nodes) - 1; i >= 2; i--) {\n            ret.push_back({nodes[i].len,\
    \ nodes[i].id, nodes[i].cnt});\n            nodes[nodes[i].link].cnt += nodes[i].cnt;\n\
    \        }\n        return ret;\n    }\n\n  private:\n    template <typename T>\
    \ int find(int last, int k, const T &S) const {\n        for (;;) {\n        \
    \    int i = last - 1 - nodes[k].len;\n            if (i >= 0 and S[i] == S[last])\n\
    \                break;\n            k = nodes[k].link;\n        }\n        return\
    \ k;\n    }\n};\n\n/**\n * @brief Palindromic Tree\n */\n"
  code: "#pragma once\n\nstruct PalindromicTree {\n    struct Node {\n        map<char,\
    \ int> nxt;\n        int link, len, id, cnt;\n        Node() {\n        }\n  \
    \      Node(int link, int len, int id, int cnt)\n            : link(link), len(len),\
    \ id(id), cnt(cnt) {\n        }\n    };\n    vector<char> S;\n    int cur;\n \
    \   vector<Node> nodes;\n    PalindromicTree() {\n        nodes.push_back(Node(0,\
    \ -1, -1, 0));\n        nodes.push_back(Node(0, 0, -1, 0));\n        cur = 0;\n\
    \    }\n    void push(char c) {\n        S.push_back(c);\n        int k = find(SZ(S)\
    \ - 1, cur, S);\n        if (nodes[k].nxt.count(c)) {\n            cur = nodes[k].nxt[c];\n\
    \            nodes[cur].cnt++;\n            return;\n        }\n        nodes[k].nxt[c]\
    \ = SZ(nodes);\n        cur = SZ(nodes);\n        nodes.push_back(\n         \
    \   Node(-1, nodes[k].len + 2, (SZ(S) - 1) - nodes[k].len - 1, 1));\n        if\
    \ (nodes.back().len == 1)\n            nodes.back().link = 1;\n        else {\n\
    \            int n = find(SZ(S) - 1, nodes[k].link, S);\n            nodes.back().link\
    \ = nodes[n].nxt[c];\n        }\n    }\n    vector<array<int, 3>> get_freq() {\n\
    \        vector<array<int, 3>> ret;\n        for (int i = SZ(nodes) - 1; i >=\
    \ 2; i--) {\n            ret.push_back({nodes[i].len, nodes[i].id, nodes[i].cnt});\n\
    \            nodes[nodes[i].link].cnt += nodes[i].cnt;\n        }\n        return\
    \ ret;\n    }\n\n  private:\n    template <typename T> int find(int last, int\
    \ k, const T &S) const {\n        for (;;) {\n            int i = last - 1 - nodes[k].len;\n\
    \            if (i >= 0 and S[i] == S[last])\n                break;\n       \
    \     k = nodes[k].link;\n        }\n        return k;\n    }\n};\n\n/**\n * @brief\
    \ Palindromic Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: String/palindromictree.hpp
  requiredBy: []
  timestamp: '2024-01-18 04:47:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/palindromictree.hpp
layout: document
redirect_from:
- /library/String/palindromictree.hpp
- /library/String/palindromictree.hpp.html
title: Palindromic Tree
---
