---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/floorsum.hpp
    title: Floor Sum
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"Verify/LC_sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\n#define rrep(i,\
    \ a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define ALL(v) (v).begin(),\
    \ (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\r\
    \n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define\
    \ MAX(v) *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v), (x))\
    \ - (v).begin())\r\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\
    \n\r\nusing uint = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned\
    \ long long;\r\nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst\
    \ int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate\
    \ <typename T, typename S = T> S SUM(const vector<T> &a) {\r\n    return accumulate(ALL(a),\
    \ S(0));\r\n}\r\ntemplate <typename S, typename T = S> S POW(S a, T b) {\r\n \
    \   S ret = 1, base = a;\r\n    for (;;) {\r\n        if (b & 1)\r\n         \
    \   ret *= base;\r\n        b >>= 1;\r\n        if (b == 0)\r\n            break;\r\
    \n        base *= base;\r\n    }\r\n    return ret;\r\n}\r\ntemplate <typename\
    \ T> inline bool chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a = b;\r\n\
    \        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T> inline\
    \ bool chmin(T &a, T b) {\r\n    if (a > b) {\r\n        a = b;\r\n        return\
    \ 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T, typename U> T ceil(T\
    \ x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x = -x, y = -y;\r\
    \n    return (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate <typename T,\
    \ typename U> T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n\
    \        x = -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1) / y);\r\n\
    }\r\ntemplate <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\
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
    \ os;\r\n}\r\n#ifdef LOCAL\r\n#define debug 1\r\n#define show(...) _show(0, #__VA_ARGS__,\
    \ __VA_ARGS__)\r\n#else\r\n#define debug 0\r\n#define show(...) true\r\n#endif\r\
    \ntemplate <typename T> void _show(int i, T name) {\r\n    cerr << '\\n';\r\n\
    }\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid _show(int i,\
    \ const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i] != ',' && a[i]\
    \ != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\" << b << \" \";\r\
    \n    _show(i + 1, a, c...);\r\n}\n#line 2 \"Math/floorsum.hpp\"\n\r\n// sum_{k=0}^{n-1}\
    \ [(a*k+b)/m]\r\ntemplate <typename T = ll> T FloorSum(ll n, ll a, ll b, ll m)\
    \ {\r\n    T res = 0;\r\n    if (a >= m)\r\n        res += T(a / m) * n * (n -\
    \ 1) / 2, a -= a / m * m;\r\n    else if (a < 0)\r\n        res -= T((-a + m -\
    \ 1) / m) * n * (n - 1) / 2,\r\n            a += ((-a + m - 1) / m) * m;\r\n \
    \   if (b >= m)\r\n        res += (b / m) * n, b -= b / m * m;\r\n    else if\
    \ (b < 0)\r\n        res -= ((-b + m - 1) / m) * n, b += ((-b + m - 1) / m) *\
    \ m;\r\n\r\n    while (1) {\r\n        ll y_max = a * n + b;\r\n        if (y_max\
    \ < m)\r\n            break;\r\n        n = y_max / m;\r\n        b = y_max %\
    \ m;\r\n        res += (n * (n - 1) / 2) * (m / a) + n * (b / a);\r\n        swap(m,\
    \ a);\r\n        a = a % m;\r\n        b = b % m;\r\n    }\r\n    return res;\r\
    \n}\r\n\r\n/**\r\n * @brief Floor Sum\r\n * @docs docs/floorsum.md\r\n */\n#line\
    \ 5 \"Verify/LC_sum_of_floor_of_linear.test.cpp\"\n\r\nint main(){\r\n    int\
    \ t;\r\n    cin>>t;\r\n    while(t--){\r\n        int n,m,a,b;\r\n        cin>>n>>m>>a>>b;\r\
    \n        cout<<FloorSum(n,a,b,m)<<'\\n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/floorsum.hpp\"\r\
    \n\r\nint main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        int\
    \ n,m,a,b;\r\n        cin>>n>>m>>a>>b;\r\n        cout<<FloorSum(n,a,b,m)<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/floorsum.hpp
  isVerificationFile: true
  path: Verify/LC_sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2025-06-29 11:23:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_sum_of_floor_of_linear.test.cpp
- /verify/Verify/LC_sum_of_floor_of_linear.test.cpp.html
title: Verify/LC_sum_of_floor_of_linear.test.cpp
---
