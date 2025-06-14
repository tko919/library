---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/rbstset.hpp
    title: Randomized Binary Search Tree (set)
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"Verify/LC_predecessor_problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\n\r\n#line 1 \"Template/template.hpp\"\
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
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\nnamespace fastio {\r\nstatic constexpr uint32_t SZ =\
    \ 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\nchar out[100];\r\n// pointer\
    \ of ibuf, obuf\r\n\r\nuint32_t pil = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\
    \n    char num[10000][4];\r\n    constexpr Pre() : num() {\r\n        for (int\
    \ i = 0; i < 10000; i++) {\r\n            int n = i;\r\n            for (int j\
    \ = 3; j >= 0; j--) {\r\n                num[i][j] = n % 10 | '0';\r\n       \
    \         n /= 10;\r\n            }\r\n        }\r\n    }\r\n} constexpr pre;\r\
    \n\r\ninline void load() {\r\n    memmove(ibuf, ibuf + pil, pir - pil);\r\n  \
    \  pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\r\n  \
    \  pil = 0;\r\n    if (pir < SZ)\r\n        ibuf[pir++] = '\\n';\r\n}\r\n\r\n\
    inline void flush() {\r\n    fwrite(obuf, 1, por, stdout);\r\n    por = 0;\r\n\
    }\r\n\r\nvoid rd(char &c) {\r\n    do {\r\n        if (pil + 1 > pir)\r\n    \
    \        load();\r\n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\n\
    }\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\n    char c;\r\n    do {\r\n\
    \        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (isspace(c));\r\n    do {\r\n        x += c;\r\n        if (pil\
    \ == pir)\r\n            load();\r\n        c = ibuf[pil++];\r\n    } while (!isspace(c));\r\
    \n}\r\n\r\ntemplate <typename T> void rd_real(T &x) {\r\n    string s;\r\n   \
    \ rd(s);\r\n    x = stod(s);\r\n}\r\n\r\ntemplate <typename T> void rd_integer(T\
    \ &x) {\r\n    if (pil + 100 > pir)\r\n        load();\r\n    char c;\r\n    do\r\
    \n        c = ibuf[pil++];\r\n    while (c < '-');\r\n    bool minus = 0;\r\n\
    \    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n        if\
    \ (c == '-') {\r\n            minus = 1, c = ibuf[pil++];\r\n        }\r\n   \
    \ }\r\n    x = 0;\r\n    while ('0' <= c) {\r\n        x = x * 10 + (c & 15),\
    \ c = ibuf[pil++];\r\n    }\r\n    if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\r\n        if (minus)\r\n            x = -x;\r\n    }\r\n}\r\n\r\n\
    void rd(int &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ll &x) {\r\n    rd_integer(x);\r\
    \n}\r\nvoid rd(i128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(uint &x) {\r\n\
    \    rd_integer(x);\r\n}\r\nvoid rd(ull &x) {\r\n    rd_integer(x);\r\n}\r\nvoid\
    \ rd(u128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(double &x) {\r\n    rd_real(x);\r\
    \n}\r\nvoid rd(long double &x) {\r\n    rd_real(x);\r\n}\r\n\r\ntemplate <class\
    \ T, class U> void rd(pair<T, U> &p) {\r\n    return rd(p.first), rd(p.second);\r\
    \n}\r\ntemplate <size_t N = 0, typename T> void rd_tuple(T &t) {\r\n    if constexpr\
    \ (N < std::tuple_size<T>::value) {\r\n        auto &x = std::get<N>(t);\r\n \
    \       rd(x);\r\n        rd_tuple<N + 1>(t);\r\n    }\r\n}\r\ntemplate <class...\
    \ T> void rd(tuple<T...> &tpl) {\r\n    rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t\
    \ N = 0, typename T> void rd(array<T, N> &x) {\r\n    for (auto &d : x)\r\n  \
    \      rd(d);\r\n}\r\ntemplate <class T> void rd(vector<T> &x) {\r\n    for (auto\
    \ &d : x)\r\n        rd(d);\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class...\
    \ T> void read(H &h, T &...t) {\r\n    rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const\
    \ char c) {\r\n    if (por == SZ)\r\n        flush();\r\n    obuf[por++] = c;\r\
    \n}\r\nvoid wt(const string s) {\r\n    for (char c : s)\r\n        wt(c);\r\n\
    }\r\nvoid wt(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t\
    \ i = 0; i < len; i++)\r\n        wt(s[i]);\r\n}\r\n\r\ntemplate <typename T>\
    \ void wt_integer(T x) {\r\n    if (por > SZ - 100)\r\n        flush();\r\n  \
    \  if (x < 0) {\r\n        obuf[por++] = '-', x = -x;\r\n    }\r\n    int outi;\r\
    \n    for (outi = 96; x >= 10000; outi -= 4) {\r\n        memcpy(out + outi, pre.num[x\
    \ % 10000], 4);\r\n        x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n  \
    \      memcpy(obuf + por, pre.num[x], 4);\r\n        por += 4;\r\n    } else if\
    \ (x >= 100) {\r\n        memcpy(obuf + por, pre.num[x] + 1, 3);\r\n        por\
    \ += 3;\r\n    } else if (x >= 10) {\r\n        int q = (x * 103) >> 10;\r\n \
    \       obuf[por] = q | '0';\r\n        obuf[por + 1] = (x - q * 10) | '0';\r\n\
    \        por += 2;\r\n    } else\r\n        obuf[por++] = x | '0';\r\n    memcpy(obuf\
    \ + por, out + outi + 4, 96 - outi);\r\n    por += 96 - outi;\r\n}\r\n\r\ntemplate\
    \ <typename T> void wt_real(T x) {\r\n    ostringstream oss;\r\n    oss << fixed\
    \ << setprecision(15) << double(x);\r\n    string s = oss.str();\r\n    wt(s);\r\
    \n}\r\n\r\nvoid wt(int x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ll x) {\r\n\
    \    wt_integer(x);\r\n}\r\nvoid wt(i128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid\
    \ wt(uint x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ull x) {\r\n    wt_integer(x);\r\
    \n}\r\nvoid wt(u128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(double x) {\r\n\
    \    wt_real(x);\r\n}\r\nvoid wt(long double x) {\r\n    wt_real(x);\r\n}\r\n\r\
    \ntemplate <class T, class U> void wt(const pair<T, U> val) {\r\n    wt(val.first);\r\
    \n    wt(' ');\r\n    wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename\
    \ T> void wt_tuple(const T t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n        if constexpr (N > 0) {\r\n            wt(' ');\r\n        }\r\n\
    \        const auto x = std::get<N>(t);\r\n        wt(x);\r\n        wt_tuple<N\
    \ + 1>(t);\r\n    }\r\n}\r\ntemplate <class... T> void wt(tuple<T...> tpl) {\r\
    \n    wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t S> void wt(const array<T,\
    \ S> val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++)\
    \ {\r\n        if (i)\r\n            wt(' ');\r\n        wt(val[i]);\r\n    }\r\
    \n}\r\ntemplate <class T> void wt(const vector<T> val) {\r\n    auto n = val.size();\r\
    \n    for (size_t i = 0; i < n; i++) {\r\n        if (i)\r\n            wt(' ');\r\
    \n        wt(val[i]);\r\n    }\r\n}\r\n\r\nvoid print() {\r\n    wt('\\n');\r\n\
    }\r\ntemplate <class Head, class... Tail> void print(Head &&head, Tail &&...tail)\
    \ {\r\n    wt(head);\r\n    if (sizeof...(Tail))\r\n        wt(' ');\r\n    print(forward<Tail>(tail)...);\r\
    \n}\r\nvoid __attribute__((destructor)) _d() {\r\n    flush();\r\n}\r\n} // namespace\
    \ fastio\r\n\r\nusing fastio::flush;\r\nusing fastio::print;\r\nusing fastio::read;\r\
    \n\r\ninline void first(bool i = true) {\r\n    print(i ? \"first\" : \"second\"\
    );\r\n}\r\ninline void Alice(bool i = true) {\r\n    print(i ? \"Alice\" : \"\
    Bob\");\r\n}\r\ninline void Takahashi(bool i = true) {\r\n    print(i ? \"Takahashi\"\
    \ : \"Aoki\");\r\n}\r\ninline void yes(bool i = true) {\r\n    print(i ? \"yes\"\
    \ : \"no\");\r\n}\r\ninline void Yes(bool i = true) {\r\n    print(i ? \"Yes\"\
    \ : \"No\");\r\n}\r\ninline void No() {\r\n    print(\"No\");\r\n}\r\ninline void\
    \ YES(bool i = true) {\r\n    print(i ? \"YES\" : \"NO\");\r\n}\r\ninline void\
    \ NO() {\r\n    print(\"NO\");\r\n}\r\ninline void Yay(bool i = true) {\r\n  \
    \  print(i ? \"Yay!\" : \":(\");\r\n}\r\ninline void Possible(bool i = true) {\r\
    \n    print(i ? \"Possible\" : \"Impossible\");\r\n}\r\ninline void POSSIBLE(bool\
    \ i = true) {\r\n    print(i ? \"POSSIBLE\" : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\
    \n * @brief Fast IO\r\n */\n#line 2 \"DataStructure/rbstset.hpp\"\n\r\ntemplate\
    \ <typename T> class RBSTset {\r\n    struct Node {\r\n        Node *lp = nullptr,\
    \ *rp = nullptr;\r\n        int size = 1;\r\n        T key;\r\n        Node(T\
    \ _k) : key(_k) {}\r\n        void apply() {\r\n            size = 1;\r\n    \
    \        if (lp)\r\n                size += lp->size;\r\n            if (rp)\r\
    \n                size += rp->size;\r\n        }\r\n    };\r\n\r\n    Node *root\
    \ = nullptr;\r\n\r\n    // subtree \u306E\u30B5\u30A4\u30BA\u53D6\u5F97\r\n  \
    \  int size(Node *x) const {\r\n        return x ? x->size : 0;\r\n    }\r\n\r\
    \n    // \u518D\u5E30\u7684\u306B subtree \u3092 delete \u3059\u308B\r\n    void\
    \ clear(Node *x) {\r\n        if (!x)\r\n            return;\r\n        clear(x->lp);\r\
    \n        clear(x->rp);\r\n        delete x;\r\n    }\r\n\r\n    // \u30DE\u30FC\
    \u30B8 (\u30E9\u30F3\u30C0\u30E0\u5316\u6728\u306E\u30DE\u30FC\u30B8)\u3002L,\
    \ R \u306F\u6728\u3067\u3001\u5168\u3066\u306E\u30AD\u30FC(L) < \u5168\u3066\u306E\
    \u30AD\u30FC(R)\r\n    // \u3068\u306F\u9650\u3089\u306A\u3044\u304C\r\n    //\
    \ \u672C\u5B9F\u88C5\u3067\u306F\u300C\u9806\u5E8F\u4ED8\u304D\u96C6\u5408\u300D\
    \u3067\u306A\u304F\u300C\u9806\u5E8F\u4ED8\u304D\u30B7\u30FC\u30B1\u30F3\u30B9\
    \u300D\u7684\u6271\u3044\u306A\u306E\u3067\u3001merge\r\n    // / split \u306F\
    \u30B5\u30A4\u30BA\u30D9\u30FC\u30B9\u3002\r\n    Node *mergeNode(Node *L, Node\
    \ *R) {\r\n        if (!L)\r\n            return R;\r\n        if (!R)\r\n   \
    \         return L;\r\n        // \u30E9\u30F3\u30C0\u30E0\u9078\u629E: L \u5074\
    \u306E\u6839\u306B\u3059\u308B\u304B R \u5074\u306E\u6839\u306B\u3059\u308B\u304B\
    \r\n        // L \u306E\u8981\u7D20\u6570 + R \u306E\u8981\u7D20\u6570 - 1 \u3092\
    \u4E0A\u9650\u3068\u3057\u3066\u4E71\u629E\u3002\u5143\u5B9F\u88C5\u306B\u5408\
    \u308F\u305B\u308B\u3002\r\n        unsigned total = size(L) + size(R) - 1;\r\n\
    \        if (Random::get(total) < (unsigned)size(L)) {\r\n            L->rp =\
    \ mergeNode(L->rp, R);\r\n            L->apply();\r\n            return L;\r\n\
    \        } else {\r\n            R->lp = mergeNode(L, R->lp);\r\n            R->apply();\r\
    \n            return R;\r\n        }\r\n    }\r\n\r\n    // split by size: \u5148\
    \u982D k \u8981\u7D20\u3092 L\u3001\u6B8B\u308A\u3092 R \u306B\u5206\u5272\r\n\
    \    std::array<Node *, 2> splitNode(Node *x, int k) {\r\n        if (!x)\r\n\
    \            return {nullptr, nullptr};\r\n        if (k == size(x)) {\r\n   \
    \         return {x, nullptr};\r\n        }\r\n        if (k <= size(x->lp)) {\r\
    \n            // \u5168\u90E8\u5DE6\u5074\u306B\u884C\u304F\u304B\u3001\u5DE6\u90E8\
    \u5206\u6728\u3067\u5B8C\u7D50\r\n            auto sp = splitNode(x->lp, k);\r\
    \n            Node *L = sp[0], *R = x;\r\n            x->lp = sp[1];\r\n     \
    \       x->apply();\r\n            return {L, R};\r\n        } else {\r\n    \
    \        // \u30EB\u30FC\u30C8\u8981\u7D20\u306F\u5DE6\u5074\u306B\u5165\u308A\
    \u3001\u53F3\u90E8\u5206\u6728\u3082\u5206\u5272\r\n            auto sp = splitNode(x->rp,\
    \ k - size(x->lp) - 1);\r\n            Node *L = x, *R = sp[1];\r\n          \
    \  x->rp = sp[0];\r\n            x->apply();\r\n            return {L, R};\r\n\
    \        }\r\n    }\r\n\r\n    // key \u672A\u6E80\u306E\u8981\u7D20\u6570 (lower_bound\
    \ \u306E\u5185\u90E8)\r\n    int lower_boundNode(Node *x, T v) const {\r\n   \
    \     if (!x)\r\n            return 0;\r\n        if (x->key >= v) {\r\n     \
    \       return lower_boundNode(x->lp, v);\r\n        } else {\r\n            return\
    \ size(x->lp) + 1 + lower_boundNode(x->rp, v);\r\n        }\r\n    }\r\n\r\n \
    \   // key \u3088\u308A\u5927\u304D\u3044\u8981\u7D20\u6570? \u3067\u306F\u306A\
    \u304F\u3001upper_bound: key <= v\r\n    // \u306E\u500B\u6570\u3092\u8FD4\u3059\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\r\n    int upper_boundNode(Node *x, T v)\
    \ const {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key >\
    \ v) {\r\n            return upper_boundNode(x->lp, v);\r\n        } else {\r\n\
    \            return size(x->lp) + 1 + upper_boundNode(x->rp, v);\r\n        }\r\
    \n    }\r\n\r\n    // \u4E2D\u9593\u8D70\u67FB\u3067\u8981\u7D20\u3092\u5217\u6319\
    \r\n    void _dump(Node *cur, std::vector<T> &a) const {\r\n        if (!cur)\r\
    \n            return;\r\n        _dump(cur->lp, a);\r\n        a.push_back(cur->key);\r\
    \n        _dump(cur->rp, a);\r\n    }\r\n\r\n  public:\r\n    RBSTset() : root(nullptr)\
    \ {}\r\n    // \u7981\u6B62: \u6D45\u3044\u30B3\u30D4\u30FC\u306B\u3088\u308B\u4E8C\
    \u91CD\u958B\u653E\u3092\u907F\u3051\u308B\r\n    RBSTset(const RBSTset &) = delete;\r\
    \n    RBSTset &operator=(const RBSTset &) = delete;\r\n\r\n    // \u30E0\u30FC\
    \u30D6\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\r\n    RBSTset(RBSTset &&other)\
    \ noexcept : root(other.root) {\r\n        other.root = nullptr;\r\n    }\r\n\
    \    RBSTset &operator=(RBSTset &&other) noexcept {\r\n        if (this != &other)\
    \ {\r\n            clear(root);\r\n            root = other.root;\r\n        \
    \    other.root = nullptr;\r\n        }\r\n        return *this;\r\n    }\r\n\r\
    \n    ~RBSTset() {\r\n        clear(root);\r\n        root = nullptr;\r\n    }\r\
    \n\r\n    int size() const {\r\n        return size(root);\r\n    }\r\n\r\n  \
    \  // merge: this \u3068 a \u3092\u7D50\u5408\u3002a \u306E\u6240\u6709\u6A29\u3092\
    \u53D7\u3051\u53D6\u308A\u3001a \u306F\u7A7A\u306B\u306A\u308B\u3002\r\n    void\
    \ merge(RBSTset &a) {\r\n        root = mergeNode(root, a.root);\r\n        //\
    \ a \u306F\u3082\u3046\u30CE\u30FC\u30C9\u3092\u6301\u305F\u306A\u3044\r\n   \
    \     a.root = nullptr;\r\n    }\r\n\r\n    // split: \u5148\u982D k \u8981\u7D20\
    \u3092 this \u306B\u6B8B\u3057\u3001\u6B8B\u308A\u3092\u65B0\u3057\u3044 RBSTset\
    \ \u3068\u3057\u3066\u8FD4\u3059\r\n    RBSTset split(int k) {\r\n        auto\
    \ sp = splitNode(root, k);\r\n        root = sp[0];\r\n        RBSTset other;\r\
    \n        other.root = sp[1];\r\n        return other;\r\n    }\r\n\r\n    bool\
    \ find(T x) const {\r\n        Node *cur = root;\r\n        while (cur) {\r\n\
    \            if (cur->key == x)\r\n                return true;\r\n          \
    \  else if (x < cur->key)\r\n                cur = cur->lp;\r\n            else\r\
    \n                cur = cur->rp;\r\n        }\r\n        return false;\r\n   \
    \ }\r\n\r\n    void insert(T x) {\r\n        int k = lower_boundNode(root, x);\r\
    \n        auto sp = splitNode(root, k);\r\n        Node *newNode = new Node(x);\r\
    \n        // merge\u9806: (\u5DE6\u5074) + newNode + (\u53F3\u5074)\r\n      \
    \  Node *m = mergeNode(sp[0], newNode);\r\n        root = mergeNode(m, sp[1]);\r\
    \n    }\r\n\r\n    void erase(T x) {\r\n        // \u5B58\u5728\u524D\u63D0\u306A\
    \u3089 assert \u304B if-check\r\n        assert(find(x));\r\n        int k = lower_boundNode(root,\
    \ x);\r\n        // \u5148\u982D k \u8981\u7D20\u3092 L, \u6B8B\u308A\u3092 t\r\
    \n        auto sp1 = splitNode(root, k);\r\n        // t \u306E\u5148\u982D 1\
    \ \u8981\u7D20\u3092 tmp\uFF08\u524A\u9664\u5BFE\u8C61\u30CE\u30FC\u30C9\uFF09\
    \u3001\u6B8B\u308A\u3092 R\r\n        auto sp2 = splitNode(sp1[1], 1);\r\n   \
    \     Node *tmp = sp2[0]; // isolated node\r\n        Node *R = sp2[1];\r\n  \
    \      // tmp \u306E\u5B50\u306F splitNode \u5185\u3067\u5916\u3055\u308C\u3066\
    \u3001tmp->lp=tmp->rp=nullptr\r\n        // \u306B\u306A\u3063\u3066\u3044\u308B\
    \u306F\u305A\r\n        delete tmp;\r\n        // L \u3068 R \u3092\u518D\u7D50\
    \u5408\r\n        root = mergeNode(sp1[0], R);\r\n    }\r\n\r\n    // k-th element:\
    \ 0-based index\r\n    T kth_element(int k) {\r\n        if (k < 0 || k >= size(root))\
    \ {\r\n            // \u30A8\u30E9\u30FC\u6307\u793A\u306A\u3089\u4F8B\u5916\u3084\
    \u7279\u5225\u5024\u3002\u3053\u3053\u3067\u306F\u4F8B\u3068\u3057\u3066 T() \u3092\
    \u8FD4\u3059\u304B\r\n            // assert\u3002 assert(false && \"kth_element:\
    \ index out of range\");\r\n            return T(); // or throw\r\n        }\r\
    \n        // split \u3057\u3066 k \u756A\u76EE\u3092\u5148\u982D\u306B\u6301\u3063\
    \u3066\u304F\u308B\r\n        auto sp = splitNode(root, k);\r\n        Node *R\
    \ = sp[1];\r\n        Node *cur = R;\r\n        // R \u306E\u6700\u5C0F\uFF08\u4E2D\
    \u9593\u8D70\u67FB\u306E\u5148\u982D\uFF09\u3092\u63A2\u3059\r\n        while\
    \ (cur->lp)\r\n            cur = cur->lp;\r\n        T res = cur->key;\r\n   \
    \     // \u5143\u306B\u623B\u3059\r\n        root = mergeNode(sp[0], sp[1]);\r\
    \n        return res;\r\n    }\r\n\r\n    int lower_bound(T v) const {\r\n   \
    \     return lower_boundNode(root, v);\r\n    }\r\n    int upper_bound(T v) const\
    \ {\r\n        return upper_boundNode(root, v);\r\n    }\r\n\r\n    std::vector<T>\
    \ dump() const {\r\n        std::vector<T> ret;\r\n        _dump(root, ret);\r\
    \n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Randomized Binary\
    \ Search Tree (set)\r\n */\n#line 6 \"Verify/LC_predecessor_problem.test.cpp\"\
    \n\r\nint main(){\r\n    int n,q;\r\n    string s;\r\n    read(n,q,s);\r\n   \
    \ RBSTset<int> tree;\r\n    rep(i,0,n)if(s[i]=='1'){\r\n        tree.insert(i);\r\
    \n    }\r\n    while(q--){\r\n        //tree.dump();\r\n        int t,x;\r\n \
    \       read(t,x);\r\n        if(t==0){\r\n            if(!tree.find(x))tree.insert(x);\r\
    \n        }\r\n        if(t==1){\r\n            if(tree.find(x))tree.erase(x);\r\
    \n        }\r\n        if(t==2){\r\n            print((int)tree.find(x));\r\n\
    \        }\r\n        if(t==3){\r\n            print(tree.kth_element(tree.lower_bound(x)));\r\
    \n        }\r\n        if(t==4){\r\n            print(tree.kth_element(tree.upper_bound(x)-1));\r\
    \n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\
    \n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\
    #include \"DataStructure/rbstset.hpp\"\r\n\r\nint main(){\r\n    int n,q;\r\n\
    \    string s;\r\n    read(n,q,s);\r\n    RBSTset<int> tree;\r\n    rep(i,0,n)if(s[i]=='1'){\r\
    \n        tree.insert(i);\r\n    }\r\n    while(q--){\r\n        //tree.dump();\r\
    \n        int t,x;\r\n        read(t,x);\r\n        if(t==0){\r\n            if(!tree.find(x))tree.insert(x);\r\
    \n        }\r\n        if(t==1){\r\n            if(tree.find(x))tree.erase(x);\r\
    \n        }\r\n        if(t==2){\r\n            print((int)tree.find(x));\r\n\
    \        }\r\n        if(t==3){\r\n            print(tree.kth_element(tree.lower_bound(x)));\r\
    \n        }\r\n        if(t==4){\r\n            print(tree.kth_element(tree.upper_bound(x)-1));\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/rbstset.hpp
  isVerificationFile: true
  path: Verify/LC_predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2025-06-14 21:49:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_predecessor_problem.test.cpp
- /verify/Verify/LC_predecessor_problem.test.cpp.html
title: Verify/LC_predecessor_problem.test.cpp
---
