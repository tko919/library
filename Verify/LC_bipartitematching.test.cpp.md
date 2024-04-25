---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/bimatching.hpp
    title: Bipartite Matching
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"Verify/LC_bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i, a, b)\
    \ for (int i = (int)(a); i < (int)(b); i++)\r\n#define rrep(i, a, b) for (int\
    \ i = (int)(b-1); i >= (int)(a); i--)\r\n#define ALL(v) (v).begin(), (v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\r\n#define\
    \ SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v)\
    \ *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())\r\
    \n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\n\r\nusing uint\
    \ = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned long long;\r\
    \nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate <typename T> inline bool\
    \ chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a = b;\r\n        return 1;\r\
    \n    }\r\n    return 0;\r\n}\r\ntemplate <typename T> inline bool chmin(T &a,\
    \ T b) {\r\n    if (a > b) {\r\n        a = b;\r\n        return 1;\r\n    }\r\
    \n    return 0;\r\n}\r\ntemplate <typename T, typename U> T ceil(T x, U y) {\r\
    \n    assert(y != 0);\r\n    if (y < 0)\r\n        x = -x, y = -y;\r\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate <typename T, typename U>\
    \ T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x =\
    \ -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1) / y);\r\n}\r\ntemplate\
    \ <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\n}\r\
    \ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63 - __builtin_clzll(x));\r\
    \n}\r\ntemplate <typename T> int lowbit(T x) {\r\n    return (x == 0 ? -1 : __builtin_ctzll(x));\r\
    \n}\r\n\r\n#ifdef LOCAL\r\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define show(...) true\r\n#endif\r\ntemplate <typename T> void _show(int\
    \ i, T name) {\r\n    cerr << '\\n';\r\n}\r\ntemplate <typename T1, typename T2,\
    \ typename... T3>\r\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c)\
    \ {\r\n    for (; a[i] != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\
    \n    cerr << \":\" << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\r\ntemplate\
    \ <class T, class U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p)\
    \ {\r\n    os << \"P(\" << p.first << \", \" << p.second << \")\";\r\n    return\
    \ os;\r\n}\r\ntemplate <typename T, template <class> class C>\r\nostream &operator<<(ostream\
    \ &os, const C<T> &v) {\r\n    os << \"[\";\r\n    for (auto d : v)\r\n      \
    \  os << d << \", \";\r\n    os << \"]\";\r\n    return os;\r\n}\n#line 2 \"Utility/random.hpp\"\
    \n\r\nnamespace Random {\r\nmt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());\r\
    \nusing u64 = unsigned long long;\r\nu64 get() {\r\n    return randgen();\r\n\
    }\r\ntemplate <typename T> T get(T L) { // [0,L]\r\n    return get() % (L + 1);\r\
    \n}\r\ntemplate <typename T> T get(T L, T R) { // [L,R]\r\n    return get(R -\
    \ L) + L;\r\n}\r\ndouble uniform() {\r\n    return double(get(1000000000)) / 1000000000;\r\
    \n}\r\nstring str(int n) {\r\n    string ret;\r\n    rep(i, 0, n) ret += get('a',\
    \ 'z');\r\n    return ret;\r\n}\r\ntemplate <typename Iter> void shuffle(Iter\
    \ first, Iter last) {\r\n    if (first == last)\r\n        return;\r\n    int\
    \ len = 1;\r\n    for (auto it = first + 1; it != last; it++) {\r\n        len++;\r\
    \n        int j = get(0, len - 1);\r\n        if (j != len - 1)\r\n          \
    \  iter_swap(it, first + j);\r\n    }\r\n}\r\ntemplate <typename T> vector<T>\
    \ select(int n, T L, T R) { // [L,R]\r\n    if (n * 2 >= R - L + 1) {\r\n    \
    \    vector<T> ret(R - L + 1);\r\n        iota(ALL(ret), L);\r\n        shuffle(ALL(ret));\r\
    \n        ret.resize(n);\r\n        return ret;\r\n    } else {\r\n        unordered_set<T>\
    \ used;\r\n        vector<T> ret;\r\n        while (SZ(used) < n) {\r\n      \
    \      T x = get(L, R);\r\n            if (!used.count(x)) {\r\n             \
    \   used.insert(x);\r\n                ret.push_back(x);\r\n            }\r\n\
    \        }\r\n        return ret;\r\n    }\r\n}\r\n\r\nvoid relabel(int n, vector<pair<int,\
    \ int>> &es) {\r\n    shuffle(ALL(es));\r\n    vector<int> ord(n);\r\n    iota(ALL(ord),\
    \ 0);\r\n    shuffle(ALL(ord));\r\n    for (auto &[u, v] : es)\r\n        u =\
    \ ord[u], v = ord[v];\r\n}\r\ntemplate <bool directed, bool simple> vector<pair<int,\
    \ int>> genGraph(int n) {\r\n    vector<pair<int, int>> cand, es;\r\n    rep(u,\
    \ 0, n) rep(v, 0, n) {\r\n        if (simple and u == v)\r\n            continue;\r\
    \n        if (!directed and u > v)\r\n            continue;\r\n        cand.push_back({u,\
    \ v});\r\n    }\r\n    int m = get(SZ(cand));\r\n    vector<int> ord;\r\n    if\
    \ (simple)\r\n        ord = select(m, 0, SZ(cand) - 1);\r\n    else {\r\n    \
    \    rep(_, 0, m) ord.push_back(get(SZ(cand) - 1));\r\n    }\r\n    for (auto\
    \ &i : ord)\r\n        es.push_back(cand[i]);\r\n    relabel(n, es);\r\n    return\
    \ es;\r\n}\r\nvector<pair<int, int>> genTree(int n) {\r\n    vector<pair<int,\
    \ int>> es;\r\n    rep(i, 1, n) es.push_back({get(i - 1), i});\r\n    relabel(n,\
    \ es);\r\n    return es;\r\n}\r\n}; // namespace Random\r\n\r\n/**\r\n * @brief\
    \ Random\r\n */\n#line 3 \"Graph/bimatching.hpp\"\n\r\nvector<int> BiMatching(int\
    \ n, int m, vector<vector<int>> &g) {\r\n    rep(v, 0, n) Random::shuffle(ALL(g[v]));\r\
    \n    vector<int> L(n, -1), R(m, -1);\r\n    for (;;) {\r\n        vector<int>\
    \ par(n, -1), root(n, -1);\r\n        queue<int> que;\r\n        rep(i, 0, n)\
    \ if (L[i] == -1) {\r\n            que.push(i);\r\n            root[i] = i;\r\n\
    \        }\r\n        bool upd = 0;\r\n        while (!que.empty()) {\r\n    \
    \        int v = que.front();\r\n            que.pop();\r\n            if (L[root[v]]\
    \ != -1)\r\n                continue;\r\n            for (auto u : g[v]) {\r\n\
    \                if (R[u] == -1) {\r\n                    while (u != -1) {\r\n\
    \                        R[u] = v;\r\n                        swap(L[v], u);\r\
    \n                        v = par[v];\r\n                    }\r\n           \
    \         upd = 1;\r\n                    break;\r\n                }\r\n    \
    \            int to = R[u];\r\n                if (par[to] == -1) {\r\n      \
    \              root[to] = root[v];\r\n                    par[to] = v;\r\n   \
    \                 que.push(to);\r\n                }\r\n            }\r\n    \
    \    }\r\n        if (!upd)\r\n            break;\r\n    }\r\n    return L;\r\n\
    }\r\n\r\n/**\r\n * @brief Bipartite Matching\r\n */\n#line 5 \"Verify/LC_bipartitematching.test.cpp\"\
    \n\r\nint main(){\r\n    int L,R,m;\r\n    cin>>L>>R>>m;\r\n    BiMatching buf(L,R);\r\
    \n    rep(_,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        buf.add_edge(x,y);\r\
    \n    }\r\n    int ret=buf.run();\r\n    \r\n    cout<<ret<<'\\n';\r\n    rep(i,0,L)if(buf.nxt[i]!=-1){\r\
    \n        cout<<i<<' '<<buf.nxt[i]<<'\\n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\r\n\
    \r\n#include \"Template/template.hpp\"\r\n#include \"Graph/bimatching.hpp\"\r\n\
    \r\nint main(){\r\n    int L,R,m;\r\n    cin>>L>>R>>m;\r\n    BiMatching buf(L,R);\r\
    \n    rep(_,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        buf.add_edge(x,y);\r\
    \n    }\r\n    int ret=buf.run();\r\n    \r\n    cout<<ret<<'\\n';\r\n    rep(i,0,L)if(buf.nxt[i]!=-1){\r\
    \n        cout<<i<<' '<<buf.nxt[i]<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/bimatching.hpp
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 03:18:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_bipartitematching.test.cpp
- /verify/Verify/LC_bipartitematching.test.cpp.html
title: Verify/LC_bipartitematching.test.cpp
---
