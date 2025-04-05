---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: General Matching
    links: []
  bundledCode: "#line 2 \"Graph/general.hpp\"\n\nstruct GeneralMatch {\n    struct\
    \ edge {\n        int u, v;\n    };\n    int n, res;\n    const vector<vector<int>>\
    \ &g;\n    vector<int> mate, idx, p;\n    vector<edge> es;\n    void rematch(int\
    \ u, int v) {\n        int w = mate[u];\n        mate[u] = v;\n        if (w ==\
    \ -1 or mate[w] != u)\n            return;\n        if (es[u].v == -1) {\n   \
    \         mate[w] = es[u].u;\n            rematch(es[u].u, w);\n        } else\
    \ {\n            rematch(es[u].u, es[u].v);\n            rematch(es[u].v, es[u].u);\n\
    \        }\n    }\n    bool check(int rt) {\n        function<int(int)> f = [&](int\
    \ x) {\n            return (idx[x] != res or p[x] == -1) ? x : (p[x] = f(p[x]));\n\
    \        };\n        queue<int> que;\n        que.push(rt);\n        p[rt] = -1;\n\
    \        idx[rt] = res;\n        es[rt] = {-1, -1};\n        while (!que.empty())\
    \ {\n            int x = que.front();\n            que.pop();\n            for\
    \ (int y : g[x])\n                if (y != rt) {\n                    if (mate[y]\
    \ == -1) {\n                        mate[y] = x;\n                        rematch(x,\
    \ y);\n                        return true;\n                    } else if (idx[y]\
    \ == res) {\n                        int u = f(x), v = f(y), w = rt;\n       \
    \                 if (u == v)\n                            continue;\n       \
    \                 while (u != rt or v != rt) {\n                            if\
    \ (v != rt)\n                                swap(u, v);\n                   \
    \         if (es[u].u == x and es[u].v == y) {\n                             \
    \   w = u;\n                                break;\n                         \
    \   }\n                            es[u] = {x, y};\n                         \
    \   u = f(es[mate[u]].u);\n                        }\n                       \
    \ int t = f(x);\n                        while (t != w) {\n                  \
    \          idx[t] = res;\n                            p[t] = w;\n            \
    \                que.push(t);\n                            t = f(es[mate[t]].u);\n\
    \                        }\n                        t = f(y);\n              \
    \          while (t != w) {\n                            idx[t] = res;\n     \
    \                       p[t] = w;\n                            que.push(t);\n\
    \                            t = f(es[mate[t]].u);\n                        }\n\
    \                    } else if (idx[mate[y]] != res) {\n                     \
    \   es[y] = {-1, -1};\n                        idx[mate[y]] = res;\n         \
    \               p[mate[y]] = y;\n                        es[mate[y]] = {x, -1};\n\
    \                        que.push(mate[y]);\n                    }\n         \
    \       }\n        }\n        return false;\n    }\n    GeneralMatch(const vector<vector<int>>\
    \ &h)\n        : g(h), n(h.size()), res(0), mate(h.size(), -1), idx(h.size(),\
    \ -1),\n          p(h.size()), es(h.size()) {\n        rep(i, 0, n) if (mate[i]\
    \ == -1) res += check(i);\n    }\n};\n\n/**\n * @brief General Matching\n */\n"
  code: "#pragma once\n\nstruct GeneralMatch {\n    struct edge {\n        int u,\
    \ v;\n    };\n    int n, res;\n    const vector<vector<int>> &g;\n    vector<int>\
    \ mate, idx, p;\n    vector<edge> es;\n    void rematch(int u, int v) {\n    \
    \    int w = mate[u];\n        mate[u] = v;\n        if (w == -1 or mate[w] !=\
    \ u)\n            return;\n        if (es[u].v == -1) {\n            mate[w] =\
    \ es[u].u;\n            rematch(es[u].u, w);\n        } else {\n            rematch(es[u].u,\
    \ es[u].v);\n            rematch(es[u].v, es[u].u);\n        }\n    }\n    bool\
    \ check(int rt) {\n        function<int(int)> f = [&](int x) {\n            return\
    \ (idx[x] != res or p[x] == -1) ? x : (p[x] = f(p[x]));\n        };\n        queue<int>\
    \ que;\n        que.push(rt);\n        p[rt] = -1;\n        idx[rt] = res;\n \
    \       es[rt] = {-1, -1};\n        while (!que.empty()) {\n            int x\
    \ = que.front();\n            que.pop();\n            for (int y : g[x])\n   \
    \             if (y != rt) {\n                    if (mate[y] == -1) {\n     \
    \                   mate[y] = x;\n                        rematch(x, y);\n   \
    \                     return true;\n                    } else if (idx[y] == res)\
    \ {\n                        int u = f(x), v = f(y), w = rt;\n               \
    \         if (u == v)\n                            continue;\n               \
    \         while (u != rt or v != rt) {\n                            if (v != rt)\n\
    \                                swap(u, v);\n                            if (es[u].u\
    \ == x and es[u].v == y) {\n                                w = u;\n         \
    \                       break;\n                            }\n              \
    \              es[u] = {x, y};\n                            u = f(es[mate[u]].u);\n\
    \                        }\n                        int t = f(x);\n          \
    \              while (t != w) {\n                            idx[t] = res;\n \
    \                           p[t] = w;\n                            que.push(t);\n\
    \                            t = f(es[mate[t]].u);\n                        }\n\
    \                        t = f(y);\n                        while (t != w) {\n\
    \                            idx[t] = res;\n                            p[t] =\
    \ w;\n                            que.push(t);\n                            t\
    \ = f(es[mate[t]].u);\n                        }\n                    } else if\
    \ (idx[mate[y]] != res) {\n                        es[y] = {-1, -1};\n       \
    \                 idx[mate[y]] = res;\n                        p[mate[y]] = y;\n\
    \                        es[mate[y]] = {x, -1};\n                        que.push(mate[y]);\n\
    \                    }\n                }\n        }\n        return false;\n\
    \    }\n    GeneralMatch(const vector<vector<int>> &h)\n        : g(h), n(h.size()),\
    \ res(0), mate(h.size(), -1), idx(h.size(), -1),\n          p(h.size()), es(h.size())\
    \ {\n        rep(i, 0, n) if (mate[i] == -1) res += check(i);\n    }\n};\n\n/**\n\
    \ * @brief General Matching\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/general.hpp
  requiredBy: []
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/general.hpp
layout: document
redirect_from:
- /library/Graph/general.hpp
- /library/Graph/general.hpp.html
title: General Matching
---
