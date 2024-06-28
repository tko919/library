---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Verify/LC_staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define\
    \ ALL(v) (v).begin(), (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\r\n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\
    \n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v),\
    \ (x)) - (v).begin())\r\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\
    \n\r\nusing uint = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned\
    \ long long;\r\nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst\
    \ int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate\
    \ <typename T> inline bool chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a\
    \ = b;\r\n        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename\
    \ T> inline bool chmin(T &a, T b) {\r\n    if (a > b) {\r\n        a = b;\r\n\
    \        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T, typename\
    \ U> T ceil(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x\
    \ = -x, y = -y;\r\n    return (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate\
    \ <typename T, typename U> T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if\
    \ (y < 0)\r\n        x = -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1)\
    \ / y);\r\n}\r\ntemplate <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\
    \n}\r\ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63\
    \ - __builtin_clzll(x));\r\n}\r\ntemplate <typename T> int lowbit(T x) {\r\n \
    \   return (x == 0 ? -1 : __builtin_ctzll(x));\r\n}\r\n\r\ntemplate <class T,\
    \ class U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p) {\r\n    os\
    \ << \"P(\" << p.first << \", \" << p.second << \")\";\r\n    return os;\r\n}\r\
    \ntemplate <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)\
    \ {\r\n    os << \"{\";\r\n    for (int i = 0; i < vec.size(); i++) {\r\n    \
    \    os << vec[i] << (i + 1 == vec.size() ? \"\" : \", \");\r\n    }\r\n    os\
    \ << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename T, typename U>\r\nostream\
    \ &operator<<(ostream &os, const map<T, U> &map_var) {\r\n    os << \"{\";\r\n\
    \    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\r\n     \
    \   os << \"(\" << itr->first << \", \" << itr->second << \")\";\r\n        itr++;\r\
    \n        if (itr != map_var.end())\r\n            os << \", \";\r\n        itr--;\r\
    \n    }\r\n    os << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename T> ostream\
    \ &operator<<(ostream &os, const set<T> &set_var) {\r\n    os << \"{\";\r\n  \
    \  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\r\n       \
    \ os << *itr;\r\n        ++itr;\r\n        if (itr != set_var.end())\r\n     \
    \       os << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n    return\
    \ os;\r\n}\r\n#ifdef LOCAL\r\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define show(...) true\r\n#endif\r\ntemplate <typename T> void _show(int\
    \ i, T name) {\r\n    cerr << '\\n';\r\n}\r\ntemplate <typename T1, typename T2,\
    \ typename... T3>\r\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c)\
    \ {\r\n    for (; a[i] != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\
    \n    cerr << \":\" << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2\
    \ \"DataStructure/segtree.hpp\"\n\r\ntemplate <typename M, typename N, M (*f)(M,\
    \ M), M (*g)(M, N), M (*m1)()>\r\nstruct SegmentTree {\r\n    int n;\r\n    vector<M>\
    \ data;\r\n    SegmentTree(int _n = 0) {\r\n        n = 1;\r\n        while (n\
    \ < _n)\r\n            n <<= 1;\r\n        data.assign(2 * n, m1());\r\n    }\r\
    \n    void run(vector<M> &v) {\r\n        for (int i = 0; i < (int)v.size(); i++)\r\
    \n            data[i + n] = v[i];\r\n        for (int k = n - 1; k > 0; k--)\r\
    \n            data[k] = f(data[2 * k], data[2 * k + 1]);\r\n    }\r\n    void\
    \ set(int k, const M &x) {\r\n        k += n;\r\n        data[k] = x;\r\n    \
    \    while (k >>= 1)\r\n            data[k] = f(data[2 * k], data[2 * k + 1]);\r\
    \n    }\r\n    void update(int k, const N &x) {\r\n        k += n;\r\n       \
    \ data[k] = g(data[k], x);\r\n        while (k >>= 1)\r\n            data[k] =\
    \ f(data[2 * k], data[2 * k + 1]);\r\n    }\r\n    M query(int a, int b) {\r\n\
    \        M L = m1(), R = m1();\r\n        for (a += n, b += n; a < b; a >>= 1,\
    \ b >>= 1) {\r\n            if (a & 1)\r\n                L = f(L, data[a++]);\r\
    \n            if (b & 1)\r\n                R = f(data[--b], R);\r\n        }\r\
    \n        return f(L, R);\r\n    }\r\n    M operator[](const int &k) const {\r\
    \n        return data[k + n];\r\n    }\r\n\r\n    template <class F> int max_right(int\
    \ L, F ch) const {\r\n        int l = n + L, w = 1;\r\n        M ansL = m1();\r\
    \n        for (; L + w <= n; l >>= 1, w <<= 1)\r\n            if (l & 1) {\r\n\
    \                if (not ch(f(ansL, data[l])))\r\n                    break;\r\
    \n                ansL = f(ansL, data[l++]);\r\n                L += w;\r\n  \
    \          }\r\n        while (l <<= 1, w >>= 1) {\r\n            if (L + w <=\
    \ n && ch(f(ansL, data[l]))) {\r\n                ansL = f(ansL, data[l++]);\r\
    \n                L += w;\r\n            }\r\n        }\r\n        return L;\r\
    \n    }\r\n\r\n    template <class F> int min_left(int R, F ch) const {\r\n  \
    \      int r = n + R, w = 1;\r\n        M ansR = m1();\r\n        for (; R - w\
    \ >= 0; r >>= 1, w <<= 1)\r\n            if (r & 1) {\r\n                if (not\
    \ ch(f(data[r - 1], ansR)))\r\n                    break;\r\n                ansR\
    \ = f(data[--r], ansR);\r\n                R -= w;\r\n            }\r\n      \
    \  while (r <<= 1, w >>= 1) {\r\n            if (R - w >= 0 && ch(f(data[r - 1],\
    \ ansR))) {\r\n                ansR = f(data[--r], ansR);\r\n                R\
    \ -= w;\r\n            }\r\n        }\r\n        return R;\r\n    }\r\n};\r\n\r\
    \n/**\r\n * @brief Segment Tree\r\n */\n#line 5 \"Verify/LC_staticrmq.test.cpp\"\
    \n\r\nint f(int a,int b){return min(a,b);}\r\nint g(int a,int b){return b;}\r\n\
    int e(){return inf;}\r\n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n\
    \    vector<int> a(N);\r\n    rep(i,0,N)cin>>a[i];\r\n\r\n    SegmentTree<int,int,f,g,e>\
    \ seg(N);\r\n    seg.run(a);\r\n    while(Q--){\r\n        int L,R;\r\n      \
    \  cin>>L>>R;\r\n        cout<<seg.query(L,R)<<'\\n';\r\n    }\r\n    return 0;\r\
    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"DataStructure/segtree.hpp\"\r\n\r\n\
    int f(int a,int b){return min(a,b);}\r\nint g(int a,int b){return b;}\r\nint e(){return\
    \ inf;}\r\n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<int>\
    \ a(N);\r\n    rep(i,0,N)cin>>a[i];\r\n\r\n    SegmentTree<int,int,f,g,e> seg(N);\r\
    \n    seg.run(a);\r\n    while(Q--){\r\n        int L,R;\r\n        cin>>L>>R;\r\
    \n        cout<<seg.query(L,R)<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Verify/LC_staticrmq.test.cpp
  requiredBy: []
  timestamp: '2024-06-23 06:04:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_staticrmq.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_staticrmq.test.cpp
- /verify/Verify/LC_staticrmq.test.cpp.html
title: Verify/LC_staticrmq.test.cpp
---
