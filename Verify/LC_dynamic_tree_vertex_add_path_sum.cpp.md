---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/linkcut.hpp
    title: Link-Cut Tree
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"Verify/LC_dynamic_tree_vertex_add_path_sum.cpp\"\n#define\
    \ PROBLEM                                                                \\\n\
    \    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\n\n\
    #line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b-1); i >= (int)(a); i--)\r\n#define\
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
    \   return (x == 0 ? -1 : __builtin_ctzll(x));\r\n}\r\n\r\n#ifdef LOCAL\r\n#define\
    \ show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\n#else\r\n#define show(...)\
    \ true\r\n#endif\r\ntemplate <typename T> void _show(int i, T name) {\r\n    cerr\
    \ << '\\n';\r\n}\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid\
    \ _show(int i, const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i]\
    \ != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\"\
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\r\ntemplate <class T, class\
    \ U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p) {\r\n    os << \"\
    P(\" << p.first << \", \" << p.second << \")\";\r\n    return os;\r\n}\r\ntemplate\
    \ <typename T, template <class> class C>\r\nostream &operator<<(ostream &os, const\
    \ C<T> &v) {\r\n    os << \"[\";\r\n    for (auto d : v)\r\n        os << d <<\
    \ \", \";\r\n    os << \"]\";\r\n    return os;\r\n}\n#line 2 \"Utility/fastio.hpp\"\
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
    \ Fast IO\r\n */\n#line 6 \"Verify/LC_dynamic_tree_vertex_add_path_sum.cpp\"\n\
    \n#line 2 \"Graph/linkcut.hpp\"\n\ntemplate <typename M, typename N, N (*f)(N,\
    \ N)> struct LCT {\n    struct Node {\n        Node *lp = nullptr, *rp = nullptr,\
    \ *par = nullptr;\n        N val;\n        M sum;\n        int idx, sz = 1;\n\
    \        bool rev = 0;\n        Node() {}\n        Node(int idx, N val) : idx(idx),\
    \ val(val) {}\n        void inverse() {\n            swap(lp, rp);\n         \
    \   sum.inverse();\n            rev ^= 1;\n        }\n        void eval() {\n\
    \            if (rev) {\n                if (lp)\n                    lp->inverse();\n\
    \                if (rp)\n                    rp->inverse();\n               \
    \ rev = 0;\n            }\n        }\n        void update() {\n            sz\
    \ = 1;\n            if (lp)\n                sz += lp->sz;\n            if (rp)\n\
    \                sz += rp->sz;\n            sum.merge(val, lp ? lp->sum : M(),\
    \ rp ? rp->sum : M());\n        }\n        bool is_root() {\n            return\
    \ !par || (par->lp != this && par->rp != this);\n        }\n        void rotate()\
    \ {\n            Node *pp, *p, *c;\n            p = par, pp = p->par;\n      \
    \      if (p->lp == this) {\n                c = rp;\n                rp = p;\n\
    \                p->lp = c;\n            } else {\n                c = lp;\n \
    \               lp = p;\n                p->rp = c;\n            }\n         \
    \   if (pp) {\n                if (pp->lp == p)\n                    pp->lp =\
    \ this;\n                if (pp->rp == p)\n                    pp->rp = this;\n\
    \            }\n            par = pp;\n            p->par = this;\n          \
    \  if (c)\n                c->par = p;\n            p->update();\n           \
    \ update();\n        }\n        void splay() {\n            eval();\n        \
    \    while (!is_root()) {\n                Node *q = par;\n                if\
    \ (q->is_root()) {\n                    q->eval();\n                    eval();\n\
    \                    if (q->lp == this)\n                        rotate();\n \
    \                   else\n                        rotate();\n                }\
    \ else {\n                    Node *r = q->par;\n                    r->eval();\n\
    \                    q->eval();\n                    eval();\n               \
    \     if (r->lp == q) {\n                        if (q->lp == this) {\n      \
    \                      q->rotate();\n                            rotate();\n \
    \                       } else {\n                            rotate();\n    \
    \                        rotate();\n                        }\n              \
    \      } else {\n                        if (q->rp == this) {\n              \
    \              q->rotate();\n                            rotate();\n         \
    \               } else {\n                            rotate();\n            \
    \                rotate();\n                        }\n                    }\n\
    \                }\n            }\n        }\n    };\n    LCT() {}\n    Node *make(int\
    \ idx, N val) {\n        return new Node(idx, val);\n    }\n    Node *expose(Node\
    \ *v) {\n        Node *pre = nullptr;\n        for (Node *cur = v; cur; cur =\
    \ cur->par) {\n            cur->splay();\n            if (cur->rp)\n         \
    \       cur->sum.add(cur->rp->sum);\n            cur->rp = pre;\n            if\
    \ (cur->rp)\n                cur->sum.sub(cur->rp->sum);\n            cur->update();\n\
    \            pre = cur;\n        }\n        v->splay();\n        return pre;\n\
    \    }\n    void link(Node *c, Node *p) {\n        evert(c);\n        expose(p);\n\
    \        c->par = p;\n        p->rp = c;\n        p->update();\n    }\n    void\
    \ cut(Node *c, Node *p) {\n        evert(p);\n        expose(c);\n        c->lp->par\
    \ = nullptr;\n        c->lp = nullptr;\n        c->update();\n    }\n    void\
    \ evert(Node *v) {\n        expose(v);\n        v->inverse();\n        v->eval();\n\
    \    }\n    Node *lca(Node *u, Node *v) {\n        expose(u);\n        return\
    \ expose(v);\n    }\n    Node *root(Node *v) {\n        expose(v);\n        while\
    \ (v->lp)\n            v->eval(), v = v->lp;\n        return v;\n    }\n    void\
    \ update(Node *v, N x) {\n        expose(v);\n        v->val = f(v->val, x);\n\
    \        v->update();\n    }\n    M &query(Node *u, Node *v) { // root = u ->\
    \ v\n        evert(u);\n        expose(v);\n        return v->sum;\n    }\n};\n\
    \n/**\n * @brief Link-Cut Tree\n */\n#line 8 \"Verify/LC_dynamic_tree_vertex_add_path_sum.cpp\"\
    \n\nusing Key = ll;\nstruct Monoid {\n    ll sum;\n    Monoid() : sum(0) {}\n\
    \    void inverse() {}\n    void merge(Key val, Monoid p, Monoid c) {\n      \
    \  sum = p.sum + c.sum + val;\n    }\n    void add(Monoid v) {}\n    void sub(Monoid\
    \ v) {}\n};\nll f(ll x, ll y) {\n    return x + y;\n}\nusing V = LCT<Monoid, Key,\
    \ f>::Node *;\n\nint main() {\n    int n, q;\n    read(n, q);\n    LCT<Monoid,\
    \ Key, f> tree;\n    vector<V> vs(n);\n    rep(i, 0, n) {\n        ll x;\n   \
    \     read(x);\n        vs[i] = tree.make(i, x);\n    }\n    rep(i, 0, n - 1)\
    \ {\n        int x, y;\n        read(x, y);\n        tree.link(vs[x], vs[y]);\n\
    \    }\n    while (q--) {\n        int t;\n        read(t);\n        if (t ==\
    \ 0) {\n            int x, y;\n            read(x, y);\n            tree.cut(vs[x],\
    \ vs[y]);\n            read(x, y);\n            tree.link(vs[x], vs[y]);\n   \
    \     }\n        if (t == 1) {\n            int v, x;\n            read(v, x);\n\
    \            tree.update(vs[v], x);\n        }\n        if (t == 2) {\n      \
    \      int v, p;\n            read(v, p);\n            auto ret = tree.query(vs[p],\
    \ vs[v]);\n            print(ret.sum);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Graph/linkcut.hpp\"\n\nusing Key = ll;\nstruct Monoid {\n    ll sum;\n   \
    \ Monoid() : sum(0) {}\n    void inverse() {}\n    void merge(Key val, Monoid\
    \ p, Monoid c) {\n        sum = p.sum + c.sum + val;\n    }\n    void add(Monoid\
    \ v) {}\n    void sub(Monoid v) {}\n};\nll f(ll x, ll y) {\n    return x + y;\n\
    }\nusing V = LCT<Monoid, Key, f>::Node *;\n\nint main() {\n    int n, q;\n   \
    \ read(n, q);\n    LCT<Monoid, Key, f> tree;\n    vector<V> vs(n);\n    rep(i,\
    \ 0, n) {\n        ll x;\n        read(x);\n        vs[i] = tree.make(i, x);\n\
    \    }\n    rep(i, 0, n - 1) {\n        int x, y;\n        read(x, y);\n     \
    \   tree.link(vs[x], vs[y]);\n    }\n    while (q--) {\n        int t;\n     \
    \   read(t);\n        if (t == 0) {\n            int x, y;\n            read(x,\
    \ y);\n            tree.cut(vs[x], vs[y]);\n            read(x, y);\n        \
    \    tree.link(vs[x], vs[y]);\n        }\n        if (t == 1) {\n            int\
    \ v, x;\n            read(v, x);\n            tree.update(vs[v], x);\n       \
    \ }\n        if (t == 2) {\n            int v, p;\n            read(v, p);\n \
    \           auto ret = tree.query(vs[p], vs[v]);\n            print(ret.sum);\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/linkcut.hpp
  isVerificationFile: false
  path: Verify/LC_dynamic_tree_vertex_add_path_sum.cpp
  requiredBy: []
  timestamp: '2024-04-26 03:32:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Verify/LC_dynamic_tree_vertex_add_path_sum.cpp
layout: document
redirect_from:
- /library/Verify/LC_dynamic_tree_vertex_add_path_sum.cpp
- /library/Verify/LC_dynamic_tree_vertex_add_path_sum.cpp.html
title: Verify/LC_dynamic_tree_vertex_add_path_sum.cpp
---
