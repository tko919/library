---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/rbstset.hpp
    title: Randomized Binary Search Tree (set)
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"Verify/LC_predecessor_problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\n\r\n#line 1 \"Template/template.hpp\"\
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
    \  os << d << \", \";\r\n    os << \"]\";\r\n    return os;\r\n}\n#line 2 \"Utility/fastio.hpp\"\
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
    Bob\");\r\n}\r\ninline void yes(bool i = true) {\r\n    print(i ? \"yes\" : \"\
    no\");\r\n}\r\ninline void Yes(bool i = true) {\r\n    print(i ? \"Yes\" : \"\
    No\");\r\n}\r\ninline void No() {\r\n    print(\"No\");\r\n}\r\ninline void YES(bool\
    \ i = true) {\r\n    print(i ? \"YES\" : \"NO\");\r\n}\r\ninline void NO() {\r\
    \n    print(\"NO\");\r\n}\r\ninline void Yay(bool i = true) {\r\n    print(i ?\
    \ \"Yay!\" : \":(\");\r\n}\r\ninline void Possible(bool i = true) {\r\n    print(i\
    \ ? \"Possible\" : \"Impossible\");\r\n}\r\ninline void POSSIBLE(bool i = true)\
    \ {\r\n    print(i ? \"POSSIBLE\" : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\n * @brief\
    \ Fast IO\r\n */\n#line 2 \"DataStructure/rbstset.hpp\"\n\r\n#line 2 \"Utility/random.hpp\"\
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
    \ Random\r\n */\n#line 4 \"DataStructure/rbstset.hpp\"\n\r\ntemplate <typename\
    \ T> class RBSTset {\r\n    struct Node {\r\n        Node *lp = nullptr, *rp =\
    \ nullptr;\r\n        int size = 1;\r\n        T key;\r\n        Node(T _k = 0)\
    \ : key(_k) {}\r\n        void apply() {\r\n            size = 1;\r\n        \
    \    if (lp)\r\n                size += lp->size;\r\n            if (rp)\r\n \
    \               size += rp->size;\r\n        }\r\n    };\r\n    int size(Node\
    \ *x) {\r\n        return x ? x->size : 0;\r\n    }\r\n    Node *merge(Node *L,\
    \ Node *R) {\r\n        if (!L)\r\n            return R;\r\n        if (!R)\r\n\
    \            return L;\r\n        if ((int)Random::get(size(L) + size(R) - 1)\
    \ < size(L)) {\r\n            L->rp = merge(L->rp, R);\r\n            L->apply();\r\
    \n            return L;\r\n        } else {\r\n            R->lp = merge(L, R->lp);\r\
    \n            R->apply();\r\n            return R;\r\n        }\r\n    }\r\n \
    \   array<Node *, 2> split(Node *x, int k) {\r\n        if (!x)\r\n          \
    \  return {nullptr, nullptr};\r\n        if (k == size(x))\r\n            return\
    \ {x, nullptr};\r\n        if (k <= size(x->lp)) {\r\n            auto [lb, rb]\
    \ = split(x->lp, k);\r\n            Node *L = lb, *R = x;\r\n            x->lp\
    \ = rb;\r\n            x->apply();\r\n            return {L, R};\r\n        }\
    \ else {\r\n            auto [lb, rb] = split(x->rp, k - size(x->lp) - 1);\r\n\
    \            Node *L = x, *R = rb;\r\n            x->rp = lb;\r\n            x->apply();\r\
    \n            return {L, R};\r\n        }\r\n    }\r\n    int lower_bound(Node\
    \ *x, T v) {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key\
    \ >= v)\r\n            return lower_bound(x->lp, v);\r\n        else\r\n     \
    \       return size(x->lp) + 1 + lower_bound(x->rp, v);\r\n    }\r\n    int upper_bound(Node\
    \ *x, T v) {\r\n        if (!x)\r\n            return 0;\r\n        if (x->key\
    \ > v)\r\n            return upper_bound(x->lp, v);\r\n        else\r\n      \
    \      return size(x->lp) + 1 + upper_bound(x->rp, v);\r\n    }\r\n    void _dump(Node\
    \ *cur, int depth) {\r\n        if (!cur)\r\n            return;\r\n        _dump(cur->lp,\
    \ depth + 1);\r\n        rep(_, 0, depth) cerr << ' ';\r\n        cerr << cur->key\
    \ << '\\n';\r\n        _dump(cur->rp, depth + 1);\r\n    }\r\n\r\n  public:\r\n\
    \    Node *root;\r\n    RBSTset(Node *_r = nullptr) : root(_r) {}\r\n    int size()\
    \ {\r\n        return size(root);\r\n    }\r\n    void merge(RBSTset &a) {\r\n\
    \        root = merge(root, a.root);\r\n    }\r\n    RBSTset split(int k) {\r\n\
    \        auto [L, R] = split(root, k);\r\n        root = L;\r\n        return\
    \ RBSTset(R);\r\n    }\r\n    bool find(T x) {\r\n        Node *cur = root;\r\n\
    \        for (;;) {\r\n            if (!cur)\r\n                break;\r\n   \
    \         if (cur->key == x)\r\n                return true;\r\n            else\
    \ if (x < cur->key)\r\n                cur = cur->lp;\r\n            else\r\n\
    \                cur = cur->rp;\r\n        }\r\n        return false;\r\n    }\r\
    \n    void insert(T x) {\r\n        int k = lower_bound(root, x);\r\n        auto\
    \ [L, R] = split(root, k);\r\n        root = merge(merge(L, new Node(x)), R);\r\
    \n    }\r\n    void erase(T x) {\r\n        assert(find(x));\r\n        int k\
    \ = lower_bound(root, x);\r\n        auto [L, t] = split(root, k);\r\n       \
    \ auto [tmp, R] = split(t, 1);\r\n        root = merge(L, R);\r\n    }\r\n   \
    \ T kth_element(int k) {\r\n        if (k >= size(root) or k < 0)\r\n        \
    \    return -1;\r\n        auto [L, R] = split(root, k);\r\n        Node *cur\
    \ = R;\r\n        while (cur->lp)\r\n            cur = cur->lp;\r\n        root\
    \ = merge(L, R);\r\n        return cur->key;\r\n    }\r\n    int lower_bound(T\
    \ v) {\r\n        return lower_bound(root, v);\r\n    }\r\n    int upper_bound(T\
    \ v) {\r\n        return upper_bound(root, v);\r\n    }\r\n    void dump() {\r\
    \n        _dump(root, 1);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Randomized Binary\
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
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 04:30:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_predecessor_problem.test.cpp
- /verify/Verify/LC_predecessor_problem.test.cpp.html
title: Verify/LC_predecessor_problem.test.cpp
---
