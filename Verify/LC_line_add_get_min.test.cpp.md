---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/lichaotree.hpp
    title: Convex Hull Trick (Li Chao Tree)
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"Verify/LC_line_add_get_min.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i, a, b)\
    \ for (int i = (int)(a); i < (int)(b); i++)\r\n#define rrep(i, a, b) for (int\
    \ i = (int)(b)-1; i >= (int)(a); i--)\r\n#define ALL(v) (v).begin(), (v).end()\r\
    \n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\r\n#define\
    \ SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v)\
    \ *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v), (x)) - (v).begin())\r\
    \n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\n\r\nusing uint\
    \ = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned long long;\r\
    \nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate <typename T, typename S =\
    \ T> S SUM(const vector<T> &a) {\r\n    return accumulate(ALL(a), S(0));\r\n}\r\
    \ntemplate <typename S, typename T = S> S POW(S a, T b) {\r\n    S ret = 1, base\
    \ = a;\r\n    for (;;) {\r\n        if (b & 1)\r\n            ret *= base;\r\n\
    \        b >>= 1;\r\n        if (b == 0)\r\n            break;\r\n        base\
    \ *= base;\r\n    }\r\n    return ret;\r\n}\r\ntemplate <typename T> inline bool\
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
    \n}\r\n\r\ntemplate <class T, class U>\r\nostream &operator<<(ostream &os, const\
    \ pair<T, U> &p) {\r\n    os << \"P(\" << p.first << \", \" << p.second << \"\
    )\";\r\n    return os;\r\n}\r\ntemplate <typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &vec) {\r\n    os << \"{\";\r\n    for (int i = 0; i <\
    \ vec.size(); i++) {\r\n        os << vec[i] << (i + 1 == vec.size() ? \"\" :\
    \ \", \");\r\n    }\r\n    os << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename\
    \ T, typename U>\r\nostream &operator<<(ostream &os, const map<T, U> &map_var)\
    \ {\r\n    os << \"{\";\r\n    for (auto itr = map_var.begin(); itr != map_var.end();\
    \ itr++) {\r\n        os << \"(\" << itr->first << \", \" << itr->second << \"\
    )\";\r\n        itr++;\r\n        if (itr != map_var.end())\r\n            os\
    \ << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n    return os;\r\
    \n}\r\ntemplate <typename T> ostream &operator<<(ostream &os, const set<T> &set_var)\
    \ {\r\n    os << \"{\";\r\n    for (auto itr = set_var.begin(); itr != set_var.end();\
    \ itr++) {\r\n        os << *itr;\r\n        ++itr;\r\n        if (itr != set_var.end())\r\
    \n            os << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n\
    \    return os;\r\n}\r\n#ifdef LOCAL\r\n#define debug 1\r\n#define show(...) _show(0,\
    \ #__VA_ARGS__, __VA_ARGS__)\r\n#else\r\n#define debug 0\r\n#define show(...)\
    \ true\r\n#endif\r\ntemplate <typename T> void _show(int i, T name) {\r\n    cerr\
    \ << '\\n';\r\n}\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid\
    \ _show(int i, const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i]\
    \ != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\"\
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2 \"DataStructure/lichaotree.hpp\"\
    \n\r\ntemplate <typename T, T MX> struct CHT {\r\n    using Line = pair<T, T>;\r\
    \n    int n;\r\n    vector<T> xs;\r\n    vector<Line> ls;\r\n    CHT() {}\r\n\
    \    CHT(vector<T> &ps) {\r\n        xs = ps;\r\n        UNIQUE(xs);\r\n     \
    \   n = 1;\r\n        while (n < (int)xs.size())\r\n            n <<= 1;\r\n \
    \       xs.resize(n, inf);\r\n        ls.resize(2 * n - 1, Line(0, MX));\r\n \
    \   }\r\n    T eval(Line &f, T x) {\r\n        return f.first * x + f.second;\r\
    \n    }\r\n    void add(T a, T b, int k = 0, int L = 0, int R = -1) {\r\n    \
    \    if (R == -1)\r\n            R = n;\r\n        Line f = {a, b};\r\n      \
    \  while (L != R) {\r\n            int mid = (L + R) >> 1;\r\n            T lx\
    \ = xs[L], mx = xs[mid], rx = xs[R - 1];\r\n            Line &g = ls[k];\r\n \
    \           if (eval(f, lx) < eval(g, lx) and eval(f, rx) < eval(g, rx)) {\r\n\
    \                g = f;\r\n                return;\r\n            }\r\n      \
    \      if (eval(f, lx) >= eval(g, lx) and eval(f, rx) >= eval(g, rx))\r\n    \
    \            return;\r\n            if (eval(f, mx) < eval(g, mx))\r\n       \
    \         swap(f, g);\r\n            if (eval(f, lx) < eval(g, lx)) {\r\n    \
    \            k = k * 2 + 1;\r\n                R = mid;\r\n            } else\
    \ {\r\n                k = k * 2 + 2;\r\n                L = mid;\r\n        \
    \    }\r\n        }\r\n    }\r\n    void add_segment(T a, T b, T L, T R) {\r\n\
    \        int l = lower_bound(ALL(xs), L) - xs.begin(),\r\n            r = lower_bound(ALL(xs),\
    \ R) - xs.begin();\r\n        int a0 = l, b0 = r;\r\n        l += n, r += n;\r\
    \n        int sz = 1;\r\n        while (l < r) {\r\n            if (r & 1) {\r\
    \n                r--;\r\n                b0 -= sz;\r\n                add(a,\
    \ b, r - 1, b0, b0 + sz);\r\n            }\r\n            if (l & 1) {\r\n   \
    \             add(a, b, l - 1, a0, a0 + sz);\r\n                l++;\r\n     \
    \           a0 += sz;\r\n            }\r\n            l >>= 1;\r\n           \
    \ r >>= 1;\r\n            sz <<= 1;\r\n        }\r\n    }\r\n    T getmin(T x)\
    \ {\r\n        int k = lower_bound(ALL(xs), x) - xs.begin() + n - 1;\r\n     \
    \   T res = eval(ls[k], x);\r\n        while (k) {\r\n            k = (k - 1)\
    \ >> 1;\r\n            chmin(res, eval(ls[k], x));\r\n        }\r\n        return\
    \ res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Convex Hull Trick (Li Chao Tree)\r\
    \n * @docs docs/lichaotree.md\r\n */\n#line 5 \"Verify/LC_line_add_get_min.test.cpp\"\
    \n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<ll> a(N),b(N);\r\
    \n    rep(i,0,N)cin>>a[i]>>b[i];\r\n    vector<ll> t(Q),c(Q),d(Q);\r\n    vector<ll>\
    \ xs;\r\n    rep(i,0,Q){\r\n        cin>>t[i];\r\n        if(t[i]==0)cin>>c[i]>>d[i];\r\
    \n        else{\r\n            cin>>c[i];\r\n            xs.push_back(c[i]);\r\
    \n        }\r\n    }\r\n    sort(ALL(xs));\r\n    xs.erase(unique(ALL(xs)),xs.end());\r\
    \n\r\n    CHT<ll,INF> cht(xs);\r\n    rep(i,0,N)cht.add(a[i],b[i]);\r\n    rep(i,0,Q){\r\
    \n        if(t[i]==0)cht.add(c[i],d[i]);\r\n        else cout<<cht.getmin(c[i])<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"DataStructure/lichaotree.hpp\"\
    \r\n\r\nint main(){\r\n    int N,Q;\r\n    cin>>N>>Q;\r\n    vector<ll> a(N),b(N);\r\
    \n    rep(i,0,N)cin>>a[i]>>b[i];\r\n    vector<ll> t(Q),c(Q),d(Q);\r\n    vector<ll>\
    \ xs;\r\n    rep(i,0,Q){\r\n        cin>>t[i];\r\n        if(t[i]==0)cin>>c[i]>>d[i];\r\
    \n        else{\r\n            cin>>c[i];\r\n            xs.push_back(c[i]);\r\
    \n        }\r\n    }\r\n    sort(ALL(xs));\r\n    xs.erase(unique(ALL(xs)),xs.end());\r\
    \n\r\n    CHT<ll,INF> cht(xs);\r\n    rep(i,0,N)cht.add(a[i],b[i]);\r\n    rep(i,0,Q){\r\
    \n        if(t[i]==0)cht.add(c[i],d[i]);\r\n        else cout<<cht.getmin(c[i])<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/lichaotree.hpp
  isVerificationFile: true
  path: Verify/LC_line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_line_add_get_min.test.cpp
- /verify/Verify/LC_line_add_get_min.test.cpp.html
title: Verify/LC_line_add_get_min.test.cpp
---
