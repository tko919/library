---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/lucydp.hpp
    title: Prime Sum
  - icon: ':question:'
    path: Math/sieve.hpp
    title: Prime Sieve
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"Verify/LC_counting_primes.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/counting_primes\"\r\n\r\n#line 1 \"Template/template.hpp\"\
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
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2 \"Math/sieve.hpp\"\
    \n\r\ntemplate <int L = 101010101> vector<int> sieve(int N) {\r\n    bitset<L>\
    \ isp;\r\n    int n, sq = ceil(sqrt(N));\r\n    for (int z = 1; z <= 5; z += 4)\
    \ {\r\n        for (int y = z; y <= sq; y += 6) {\r\n            for (int x =\
    \ 1; x <= sq and (n = 4 * x * x + y * y) <= N; ++x) {\r\n                isp[n].flip();\r\
    \n            }\r\n            for (int x = y + 1; x <= sq and (n = 3 * x * x\
    \ - y * y) <= N;\r\n                 x += 2) {\r\n                isp[n].flip();\r\
    \n            }\r\n        }\r\n    }\r\n    for (int z = 2; z <= 4; z += 2) {\r\
    \n        for (int y = z; y <= sq; y += 6) {\r\n            for (int x = 1; x\
    \ <= sq and (n = 3 * x * x + y * y) <= N; x += 2) {\r\n                isp[n].flip();\r\
    \n            }\r\n            for (int x = y + 1; x <= sq and (n = 3 * x * x\
    \ - y * y) <= N;\r\n                 x += 2) {\r\n                isp[n].flip();\r\
    \n            }\r\n        }\r\n    }\r\n    for (int y = 3; y <= sq; y += 6)\
    \ {\r\n        for (int z = 1; z <= 2; ++z) {\r\n            for (int x = z; x\
    \ <= sq and (n = 4 * x * x + y * y) <= N; x += 3) {\r\n                isp[n].flip();\r\
    \n            }\r\n        }\r\n    }\r\n    for (int n = 5; n <= sq; ++n)\r\n\
    \        if (isp[n]) {\r\n            for (int k = n * n; k <= N; k += n * n)\
    \ {\r\n                isp[k] = false;\r\n            }\r\n        }\r\n    isp[2]\
    \ = isp[3] = true;\r\n\r\n    vector<int> ret;\r\n    for (int i = 2; i <= N;\
    \ i++)\r\n        if (isp[i]) {\r\n            ret.push_back(i);\r\n        }\r\
    \n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n#line 3 \"\
    Math/lucydp.hpp\"\n\r\ntemplate <typename T, T (*F)(ll)> struct LucyDP {\r\n \
    \   ll N, SQ, sz;\r\n    vector<ll> quo;\r\n    vector<T> dat;\r\n    LucyDP(ll\
    \ n = 0)\r\n        : N(n), SQ(sqrtl(N)), sz(SQ + n / (SQ + 1)), quo(sz), dat(sz)\
    \ {\r\n        iota(ALL(quo), 1);\r\n        for (ll i = SQ, x = N / (SQ + 1);\
    \ x; x--, i++)\r\n            quo[i] = n / x;\r\n        rep(i, 0, sz) dat[i]\
    \ = F(quo[i]) - 1;\r\n        auto ps = sieve(SQ);\r\n        for (auto &p : ps)\
    \ {\r\n            T coe = dat[p - 1] - dat[p - 2];\r\n            for (int i\
    \ = sz - 1;; i--) {\r\n                if (quo[i] < ll(p) * p)\r\n           \
    \         break;\r\n                dat[i] -= (dat[idx(quo[i] / p)] - dat[p -\
    \ 2]) * coe;\r\n            }\r\n        }\r\n    }\r\n    T operator[](ll x)\
    \ {\r\n        return dat[idx(x)];\r\n    }\r\n\r\n  private:\r\n    int idx(ll\
    \ x) const {\r\n        if (x <= SQ)\r\n            return x - 1;\r\n        else\r\
    \n            return sz - N / x;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Prime\
    \ Sum\r\n * @docs docs/primesum.md\r\n */\n#line 5 \"Verify/LC_counting_primes.test.cpp\"\
    \n\r\nll F(ll x) {\r\n    return x;\r\n}\r\n\r\nint main() {\r\n    ll n;\r\n\
    \    cin >> n;\r\n    LucyDP<ll, F> pc(n);\r\n    cout << pc[n] << '\\n';\r\n\
    \    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Math/lucydp.hpp\"\r\n\r\nll\
    \ F(ll x) {\r\n    return x;\r\n}\r\n\r\nint main() {\r\n    ll n;\r\n    cin\
    \ >> n;\r\n    LucyDP<ll, F> pc(n);\r\n    cout << pc[n] << '\\n';\r\n    return\
    \ 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/lucydp.hpp
  - Math/sieve.hpp
  isVerificationFile: true
  path: Verify/LC_counting_primes.test.cpp
  requiredBy: []
  timestamp: '2025-06-29 11:23:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_counting_primes.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_counting_primes.test.cpp
- /verify/Verify/LC_counting_primes.test.cpp.html
title: Verify/LC_counting_primes.test.cpp
---
