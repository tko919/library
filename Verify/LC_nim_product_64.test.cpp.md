---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/nimber.hpp
    title: Nimber
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
    PROBLEM: https://judge.yosupo.jp/problem/nim_product_64
    links:
    - https://judge.yosupo.jp/problem/nim_product_64
  bundledCode: "#line 1 \"Verify/LC_nim_product_64.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/nim_product_64\"\r\n\r\n#line 1 \"Template/template.hpp\"\
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
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2 \"Math/nimber.hpp\"\
    \n\r\nusing ull = unsigned long long;\r\nnamespace NimberManager {\r\nunsigned\
    \ short E[65536 * 2 + 7], L[65536];\r\ninline void __attribute__((constructor))\
    \ init() {\r\n    unsigned short c[] = {10279, 15417, 35722, 52687, 44124, 62628,\r\
    \n                          15661, 5686,  3862,  1323,  334,   647,\r\n      \
    \                    61560, 20636, 4267,  8445};\r\n    unsigned short d[65536];\r\
    \n    for (int i = 0; i < 16; ++i)\r\n        for (int j = 1 << i; j--;)\r\n \
    \           d[1 << i | j] = d[j] ^ c[i];\r\n    E[0] = 1;\r\n    for (int i =\
    \ 0; i < 65534; ++i)\r\n        E[i + 1] = d[E[i]];\r\n    memcpy(E + 65535, E,\
    \ 131070), memcpy(E + 131070, E, 14);\r\n    for (int i = 0; i < 65535; ++i)\r\
    \n        L[E[i]] = i;\r\n}\r\ninline uint mul16(const uint &x, const uint &y)\
    \ {\r\n    return x && y ? E[uint(L[x]) + L[y]] : 0;\r\n}\r\ninline uint mul16_15(const\
    \ uint &x, const uint &y) {\r\n    return x && y ? E[uint(L[x]) + L[y] + 3] :\
    \ 0;\r\n}\r\ninline uint mul15_15(const uint &x, const uint &y) {\r\n    return\
    \ x && y ? E[uint(L[x]) + L[y] + 6] : 0;\r\n}\r\ninline uint mul15(const uint\
    \ &x) {\r\n    return x ? E[L[x] + 3] : 0;\r\n}\r\ninline uint mul(const uint\
    \ &x, const uint &y) {\r\n    const uint xh = x >> 16, xl = x & 65535, yh = y\
    \ >> 16, yl = y & 65535,\r\n               c = mul16(xl, yl);\r\n    return (ull)(mul16(xl\
    \ ^ xh, yl ^ yh) ^ c) << 16 | (mul16_15(xh, yh) ^ c);\r\n}\r\ninline uint mul32_31(const\
    \ uint &x, const uint &y) {\r\n    const uint xh = x >> 16, xl = x & 65535, yh\
    \ = y >> 16, yl = y & 65535,\r\n               c = mul16_15(xl ^ xh, yl ^ yh);\r\
    \n    return (ull)(c ^ mul15_15(xh, yh)) << 16 | mul15(mul16_15(xl, yl) ^ c);\r\
    \n}\r\ninline ull mul(const ull &x, const ull &y) {\r\n    const uint xh = x >>\
    \ 32, xl = x & UINT_MAX, yh = y >> 32, yl = y & UINT_MAX,\r\n               c\
    \ = mul(xl, yl);\r\n    return (ull)(mul(xl ^ xh, yl ^ yh) ^ c) << 32 | (mul32_31(xh,\
    \ yh) ^ c);\r\n}\r\n}; // namespace NimberManager\r\nstruct Nimber {\r\n    ull\
    \ v;\r\n    Nimber(ull _v = 0) : v(_v) {}\r\n    Nimber &operator+=(const Nimber\
    \ &x) {\r\n        v ^= x.v;\r\n        return *this;\r\n    }\r\n    Nimber &operator-=(const\
    \ Nimber &x) {\r\n        v ^= x.v;\r\n        return *this;\r\n    }\r\n    Nimber\
    \ &operator*=(const Nimber &x) {\r\n        v = NimberManager::mul(v, x.v);\r\n\
    \        return *this;\r\n    }\r\n    Nimber operator+(const Nimber &x) const\
    \ {\r\n        return Nimber(*this) += x;\r\n    }\r\n    Nimber operator-(const\
    \ Nimber &x) const {\r\n        return Nimber(*this) -= x;\r\n    }\r\n    Nimber\
    \ operator*(const Nimber &x) const {\r\n        return Nimber(*this) *= x;\r\n\
    \    }\r\n    bool operator==(const Nimber &x) const {\r\n        return v ==\
    \ x.v;\r\n    }\r\n    bool operator!=(const Nimber &x) const {\r\n        return\
    \ v != x.v;\r\n    }\r\n    Nimber pow(ull t) {\r\n        Nimber res = 1, b =\
    \ *this;\r\n        while (t) {\r\n            if (t & 1)\r\n                res\
    \ *= b;\r\n            b *= b;\r\n            t >>= 1;\r\n        }\r\n      \
    \  return res;\r\n    }\r\n    Nimber inv() { // \u66AB\u5B9A\r\n        return\
    \ pow(ull(-2));\r\n    }\r\n    friend istream &operator>>(istream &is, Nimber\
    \ &x) {\r\n        return is >> x.v;\r\n    }\r\n    friend ostream &operator<<(ostream\
    \ &os, const Nimber &x) {\r\n        return os << x.v;\r\n    }\r\n};\r\n\r\n\
    /**\r\n * @brief Nimber\r\n */\n#line 5 \"Verify/LC_nim_product_64.test.cpp\"\n\
    \r\nint main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        Nimber\
    \ a,b;\r\n        cin>>a>>b;\r\n        cout<<a*b<<'\\n';\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\r\n\r\n\
    #include \"Template/template.hpp\"\r\n#include \"Math/nimber.hpp\"\r\n\r\nint\
    \ main(){\r\n    int t;\r\n    cin>>t;\r\n    while(t--){\r\n        Nimber a,b;\r\
    \n        cin>>a>>b;\r\n        cout<<a*b<<'\\n';\r\n    }\r\n    return 0;\r\n\
    }"
  dependsOn:
  - Template/template.hpp
  - Math/nimber.hpp
  isVerificationFile: true
  path: Verify/LC_nim_product_64.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_nim_product_64.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_nim_product_64.test.cpp
- /verify/Verify/LC_nim_product_64.test.cpp.html
title: Verify/LC_nim_product_64.test.cpp
---
