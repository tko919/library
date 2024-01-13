---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/hashmap.hpp
    title: Hash Map
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"Verify/LC_associative_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/associative_array\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\n#define\
    \ UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define SZ(v)\
    \ (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\n#define UB(v,x)\
    \ int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long long int;\r\n\
    using ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing u128=__uint128_t;\r\
    \nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate<typename\
    \ T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename\
    \ T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}\r\ntemplate<typename\
    \ T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\
    \ntemplate<typename T,typename U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\
    \ntemplate<typename T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\
    \ntemplate<typename T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n\
    #line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\n\r\nclass FastIO {\r\n\
    \    static constexpr int L = 1 << 16;\r\n    char rdbuf[L];\r\n    int rdLeft\
    \ = 0, rdRight = 0;\r\n    inline void reload() {\r\n        int len = rdRight\
    \ - rdLeft;\r\n        memmove(rdbuf, rdbuf + rdLeft, len);\r\n        rdLeft\
    \ = 0, rdRight = len;\r\n        rdRight += fread(rdbuf + len, 1, L - len, stdin);\r\
    \n    }\r\n    inline bool skip() {\r\n        for (;;) {\r\n            while\
    \ (rdLeft != rdRight and rdbuf[rdLeft] <= ' ')\r\n                rdLeft++;\r\n\
    \            if (rdLeft == rdRight) {\r\n                reload();\r\n       \
    \         if (rdLeft == rdRight)\r\n                    return false;\r\n    \
    \        } else\r\n                break;\r\n        }\r\n        return true;\r\
    \n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n            return\
    \ false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\n \
    \       bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n         \
    \   neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n  \
    \      while (rdbuf[rdLeft] >= '0' and rdLeft < rdRight) {\r\n            x =\
    \ x * 10 +\r\n                (neg ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++]\
    \ ^ 48));\r\n        }\r\n        return true;\r\n    }\r\n    inline bool _read(__int128_t\
    \ &x) {\r\n        if (!skip())\r\n            return false;\r\n        if (rdLeft\
    \ + 40 >= rdRight)\r\n            reload();\r\n        bool neg = false;\r\n \
    \       if (rdbuf[rdLeft] == '-') {\r\n            neg = true;\r\n           \
    \ rdLeft++;\r\n        }\r\n        x = 0;\r\n        while (rdbuf[rdLeft] >=\
    \ '0' and rdLeft < rdRight) {\r\n            x = x * 10 +\r\n                (neg\
    \ ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++] ^ 48));\r\n        }\r\n      \
    \  return true;\r\n    }\r\n    inline bool _read(__uint128_t &x) {\r\n      \
    \  if (!skip())\r\n            return false;\r\n        if (rdLeft + 40 >= rdRight)\r\
    \n            reload();\r\n        x = 0;\r\n        while (rdbuf[rdLeft] >= '0'\
    \ and rdLeft < rdRight) {\r\n            x = x * 10 + (rdbuf[rdLeft++] ^ 48);\r\
    \n        }\r\n        return true;\r\n    }\r\n    template <typename T, enable_if_t<is_floating_point<T>::value,\
    \ int> = 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n     \
    \       return false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\
    \n        bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n       \
    \     neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n\
    \        while (rdbuf[rdLeft] >= '0' and rdbuf[rdLeft] <= '9' and\r\n        \
    \       rdLeft < rdRight) {\r\n            x = x * 10 + (rdbuf[rdLeft++] ^ 48);\r\
    \n        }\r\n        if (rdbuf[rdLeft] != '.')\r\n            return true;\r\
    \n        rdLeft++;\r\n        T base = .1;\r\n        while (rdbuf[rdLeft] >=\
    \ '0' and rdbuf[rdLeft] <= '9' and\r\n               rdLeft < rdRight) {\r\n \
    \           x += base * (rdbuf[rdLeft++] ^ 48);\r\n            base *= .1;\r\n\
    \        }\r\n        if (neg)\r\n            x = -x;\r\n        return true;\r\
    \n    }\r\n    inline bool _read(char &x) {\r\n        if (!skip())\r\n      \
    \      return false;\r\n        if (rdLeft + 1 >= rdRight)\r\n            reload();\r\
    \n        x = rdbuf[rdLeft++];\r\n        return true;\r\n    }\r\n    inline\
    \ bool _read(string &x) {\r\n        if (!skip())\r\n            return false;\r\
    \n        for (;;) {\r\n            int pos = rdLeft;\r\n            while (pos\
    \ < rdRight and rdbuf[pos] > ' ')\r\n                pos++;\r\n            x.append(rdbuf\
    \ + rdLeft, pos - rdLeft);\r\n            if (rdLeft == pos)\r\n             \
    \   break;\r\n            rdLeft = pos;\r\n            if (rdLeft == rdRight)\r\
    \n                reload();\r\n            else\r\n                break;\r\n\
    \        }\r\n        return true;\r\n    }\r\n    template <typename T> inline\
    \ bool _read(vector<T> &v) {\r\n        for (auto &x : v) {\r\n            if\
    \ (!_read(x))\r\n                return false;\r\n        }\r\n        return\
    \ true;\r\n    }\r\n\r\n    char wtbuf[L], tmp[50];\r\n    int wtRight = 0;\r\n\
    \    inline void _write(const char &x) {\r\n        if (wtRight > L - 32)\r\n\
    \            flush();\r\n        wtbuf[wtRight++] = x;\r\n    }\r\n    inline\
    \ void _write(const string &x) {\r\n        for (auto &c : x)\r\n            _write(c);\r\
    \n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\r\n    inline void _write(T x) {\r\n        if (wtRight > L - 32)\r\n   \
    \         flush();\r\n        if (x == 0) {\r\n            _write('0');\r\n  \
    \          return;\r\n        } else if (x < 0) {\r\n            _write('-');\r\
    \n            if (__builtin_expect(x == std::numeric_limits<T>::min(), 0)) {\r\
    \n                switch (sizeof(x)) {\r\n                case 2:\r\n        \
    \            _write(\"32768\");\r\n                    return;\r\n           \
    \     case 4:\r\n                    _write(\"2147483648\");\r\n             \
    \       return;\r\n                case 8:\r\n                    _write(\"9223372036854775808\"\
    );\r\n                    return;\r\n                }\r\n            }\r\n  \
    \          x = -x;\r\n        }\r\n        int pos = 0;\r\n        while (x !=\
    \ 0) {\r\n            tmp[pos++] = char((x % 10) | 48);\r\n            x /= 10;\r\
    \n        }\r\n        rep(i, 0, pos) wtbuf[wtRight + i] = tmp[pos - 1 - i];\r\
    \n        wtRight += pos;\r\n    }\r\n    inline void _write(__int128_t x) {\r\
    \n        if (wtRight > L - 40)\r\n            flush();\r\n        if (x == 0)\
    \ {\r\n            _write('0');\r\n            return;\r\n        } else if (x\
    \ < 0) {\r\n            _write('-');\r\n            x = -x;\r\n        }\r\n \
    \       int pos = 0;\r\n        while (x != 0) {\r\n            tmp[pos++] = char((x\
    \ % 10) | 48);\r\n            x /= 10;\r\n        }\r\n        rep(i, 0, pos)\
    \ wtbuf[wtRight + i] = tmp[pos - 1 - i];\r\n        wtRight += pos;\r\n    }\r\
    \n    inline void _write(__uint128_t x) {\r\n        if (wtRight > L - 40)\r\n\
    \            flush();\r\n        if (x == 0) {\r\n            _write('0');\r\n\
    \            return;\r\n        }\r\n        int pos = 0;\r\n        while (x\
    \ != 0) {\r\n            tmp[pos++] = char((x % 10) | 48);\r\n            x /=\
    \ 10;\r\n        }\r\n        rep(i, 0, pos) wtbuf[wtRight + i] = tmp[pos - 1\
    \ - i];\r\n        wtRight += pos;\r\n    }\r\n    inline void _write(double x)\
    \ {\r\n        ostringstream oss;\r\n        oss << fixed << setprecision(15)\
    \ << double(x);\r\n        string s = oss.str();\r\n        _write(s);\r\n   \
    \ }\r\n    template <typename T> inline void _write(const vector<T> &v) {\r\n\
    \        rep(i, 0, v.size()) {\r\n            if (i)\r\n                _write('\
    \ ');\r\n            _write(v[i]);\r\n        }\r\n    }\r\n\r\n  public:\r\n\
    \    FastIO() {}\r\n    ~FastIO() { flush(); }\r\n    inline void read() {}\r\n\
    \    template <typename Head, typename... Tail>\r\n    inline void read(Head &head,\
    \ Tail &...tail) {\r\n        assert(_read(head));\r\n        read(tail...);\r\
    \n    }\r\n    template <bool ln = true, bool space = false> inline void write()\
    \ {\r\n        if (ln)\r\n            _write('\\n');\r\n    }\r\n    template\
    \ <bool ln = true, bool space = false, typename Head,\r\n              typename...\
    \ Tail>\r\n    inline void write(const Head &head, const Tail &...tail) {\r\n\
    \        if (space)\r\n            _write(' ');\r\n        _write(head);\r\n \
    \       write<ln, true>(tail...);\r\n    }\r\n    inline void flush() {\r\n  \
    \      fwrite(wtbuf, 1, wtRight, stdout);\r\n        wtRight = 0;\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 2 \"DataStructure/hashmap.hpp\"\
    \n\r\ntemplate<typename Key,typename Val,int N=1<<20>struct HashMap{\r\n    using\
    \ u64 = uint64_t;\r\nprivate:\r\n    array<Key,N> keys;\r\n    array<Val,N> vals;\r\
    \n    bitset<N> used;\r\n    const int shift;\r\n    static constexpr u64 RNG()\
    \ {\r\n        mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n        return gen();\r\n    }\r\npublic:\r\n    HashMap():shift(64-__lg(N)){\r\
    \n        static_assert((N & (N - 1)) == 0 && N > 0);\r\n    }\r\n    Val& operator[](const\
    \ Key& x){\r\n        static u64 r=RNG();\r\n        int hash=(u64(x)*r)>>shift;\r\
    \n        for(;;){\r\n            if(!used[hash]){\r\n                keys[hash]=x;\r\
    \n                used[hash]=1;\r\n                return vals[hash]=Val();\r\n\
    \            }\r\n            if(keys[hash]==x)return vals[hash];\r\n        \
    \    hash++;\r\n            hash=(hash+1)&(N-1);\r\n        }\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Hash Map\r\n */\n#line 6 \"Verify/LC_associative_array.test.cpp\"\
    \n\r\nint main(){\r\n    FastIO io;\r\n    int q,t;\r\n    ll k,v;\r\n    io.read(q);\r\
    \n    HashMap<ll,ll> mp;\r\n    while(q--){\r\n        io.read(t,k);\r\n     \
    \   if(t==0){\r\n            io.read(v);\r\n            mp[k]=v;\r\n        }\r\
    \n        else{\r\n            io.write(mp[k]);\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\r\n\
    \r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\
    #include \"DataStructure/hashmap.hpp\"\r\n\r\nint main(){\r\n    FastIO io;\r\n\
    \    int q,t;\r\n    ll k,v;\r\n    io.read(q);\r\n    HashMap<ll,ll> mp;\r\n\
    \    while(q--){\r\n        io.read(t,k);\r\n        if(t==0){\r\n           \
    \ io.read(v);\r\n            mp[k]=v;\r\n        }\r\n        else{\r\n      \
    \      io.write(mp[k]);\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/hashmap.hpp
  isVerificationFile: true
  path: Verify/LC_associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 04:46:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_associative_array.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_associative_array.test.cpp
- /verify/Verify/LC_associative_array.test.cpp.html
title: Verify/LC_associative_array.test.cpp
---
