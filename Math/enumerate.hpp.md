---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate function
    links: []
  bundledCode: "#line 1 \"Math/enumerate.hpp\"\n// len=K,sum=N\ntemplate <typename\
    \ F> void enumerate_multiset(int N, int K, F query) {\n    vector<int> A(K);\n\
    \    auto dfs = [&](auto &dfs, int p, int s) -> void {\n        if (p == K) {\n\
    \            if (s == 0)\n                query(A);\n            return;\n   \
    \     }\n        rep(x, 0, s + 1) {\n            A[p] = x;\n            dfs(dfs,\
    \ p + 1, s - x);\n        }\n    };\n    dfs(dfs, 0, N);\n}\n// sum=N\ntemplate\
    \ <typename F>\nvoid enumerate_partition(int N, F query, int LIM_len = -1, int\
    \ LIM_val = -1) {\n    assert(N >= 0);\n    auto dfs = [&](auto self, vector<int>\
    \ &p, int sum) -> void {\n        if (sum == N) {\n            query(p);\n   \
    \         return;\n        }\n        if (LIM_len != -1 && SZ(p) == LIM_len)\n\
    \            return;\n        int nxt = (SZ(p) == 0 ? N : p.back());\n       \
    \ if (LIM_val != -1)\n            chmin(nxt, LIM_val);\n        chmin(nxt, N -\
    \ sum);\n        p.push_back(0);\n        rep(x, 1, nxt + 1) {\n            p.back()\
    \ = x;\n            self(self, p, sum + x);\n        }\n        p.pop_back();\n\
    \    };\n    vector<int> p;\n    dfs(dfs, p, 0);\n}\n// [0,A[i])^n\ntemplate <typename\
    \ F, bool inc = 0>\nvoid enumerate_product(vector<int> A, F query) {\n    int\
    \ N = SZ(A);\n    auto dfs = [&](auto &dfs, vector<int> &p) -> void {\n      \
    \  int n = SZ(p);\n        if (n == N)\n            return query(p);\n       \
    \ int LIM = A[n];\n        if (SZ(p) > 0 and inc)\n            chmin(LIM, p.back()\
    \ + 1);\n        rep(x, 0, LIM) {\n            p.push_back(x);\n            dfs(dfs,\
    \ p);\n            p.pop_back();\n        }\n    };\n    vector<int> p;\n    dfs(dfs,\
    \ p);\n}\n\n/**\n * @brief Enumerate function\n */\n"
  code: "// len=K,sum=N\ntemplate <typename F> void enumerate_multiset(int N, int\
    \ K, F query) {\n    vector<int> A(K);\n    auto dfs = [&](auto &dfs, int p, int\
    \ s) -> void {\n        if (p == K) {\n            if (s == 0)\n             \
    \   query(A);\n            return;\n        }\n        rep(x, 0, s + 1) {\n  \
    \          A[p] = x;\n            dfs(dfs, p + 1, s - x);\n        }\n    };\n\
    \    dfs(dfs, 0, N);\n}\n// sum=N\ntemplate <typename F>\nvoid enumerate_partition(int\
    \ N, F query, int LIM_len = -1, int LIM_val = -1) {\n    assert(N >= 0);\n   \
    \ auto dfs = [&](auto self, vector<int> &p, int sum) -> void {\n        if (sum\
    \ == N) {\n            query(p);\n            return;\n        }\n        if (LIM_len\
    \ != -1 && SZ(p) == LIM_len)\n            return;\n        int nxt = (SZ(p) ==\
    \ 0 ? N : p.back());\n        if (LIM_val != -1)\n            chmin(nxt, LIM_val);\n\
    \        chmin(nxt, N - sum);\n        p.push_back(0);\n        rep(x, 1, nxt\
    \ + 1) {\n            p.back() = x;\n            self(self, p, sum + x);\n   \
    \     }\n        p.pop_back();\n    };\n    vector<int> p;\n    dfs(dfs, p, 0);\n\
    }\n// [0,A[i])^n\ntemplate <typename F, bool inc = 0>\nvoid enumerate_product(vector<int>\
    \ A, F query) {\n    int N = SZ(A);\n    auto dfs = [&](auto &dfs, vector<int>\
    \ &p) -> void {\n        int n = SZ(p);\n        if (n == N)\n            return\
    \ query(p);\n        int LIM = A[n];\n        if (SZ(p) > 0 and inc)\n       \
    \     chmin(LIM, p.back() + 1);\n        rep(x, 0, LIM) {\n            p.push_back(x);\n\
    \            dfs(dfs, p);\n            p.pop_back();\n        }\n    };\n    vector<int>\
    \ p;\n    dfs(dfs, p);\n}\n\n/**\n * @brief Enumerate function\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/enumerate.hpp
  requiredBy: []
  timestamp: '2026-11-06 05:35:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/enumerate.hpp
layout: document
redirect_from:
- /library/Math/enumerate.hpp
- /library/Math/enumerate.hpp.html
title: Enumerate function
---
