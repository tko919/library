---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/linkcut.hpp
    title: Link-Cut Tree
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
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
  bundledCode: "#line 1 \"Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp\"\n#define\
    \ PROBLEM                                                                \\\n\
    \    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\n\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define\
    \ MAX(v) *max_element(ALL(v))\r\n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\
    \n#define UB(v,x) int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long\
    \ long int;\r\nusing ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing\
    \ u128=__uint128_t;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename U>T floor(T x,U\
    \ y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename\
    \ T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename T>int\
    \ topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename T>int\
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\n\r\nclass FastIO {\r\n    static constexpr int L = 1\
    \ << 16;\r\n    char rdbuf[L];\r\n    int rdLeft = 0, rdRight = 0;\r\n    inline\
    \ void reload() {\r\n        int len = rdRight - rdLeft;\r\n        memmove(rdbuf,\
    \ rdbuf + rdLeft, len);\r\n        rdLeft = 0, rdRight = len;\r\n        rdRight\
    \ += fread(rdbuf + len, 1, L - len, stdin);\r\n    }\r\n    inline bool skip()\
    \ {\r\n        for (;;) {\r\n            while (rdLeft != rdRight and rdbuf[rdLeft]\
    \ <= ' ')\r\n                rdLeft++;\r\n            if (rdLeft == rdRight) {\r\
    \n                reload();\r\n                if (rdLeft == rdRight)\r\n    \
    \                return false;\r\n            } else\r\n                break;\r\
    \n        }\r\n        return true;\r\n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n     \
    \       return false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\
    \n        bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n       \
    \     neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n\
    \        while (rdbuf[rdLeft] >= '0' and rdLeft < rdRight) {\r\n            x\
    \ = x * 10 +\r\n                (neg ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++]\
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
    };\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 6 \"Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp\"\
    \n\n#line 2 \"Graph/linkcut.hpp\"\n\ntemplate <typename M, typename N, N (*f)(N,\
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
    \n/**\n * @brief Link-Cut Tree\n */\n#line 8 \"Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp\"\
    \n\nusing Key = ll;\nstruct Monoid {\n    ll sum, psum, csum, light;\n    Monoid()\
    \ : sum(0), psum(0), csum(0), light(0) {}\n    void inverse() {\n        swap(psum,\
    \ csum);\n    }\n    void merge(Key val, Monoid p, Monoid c) {\n        sum =\
    \ p.sum + c.sum + val + light;\n        psum = p.psum + val + light;\n       \
    \ csum = c.csum + val + light;\n    }\n    void add(Monoid v) {\n        light\
    \ += v.sum;\n    }\n    void sub(Monoid v) {\n        light -= v.sum;\n    }\n\
    };\nll f(ll x, ll y) {\n    return x + y;\n}\nusing V = LCT<Monoid, Key, f>::Node\
    \ *;\n\nFastIO io;\nint main() {\n    int n, q;\n    io.read(n, q);\n    LCT<Monoid,\
    \ Key, f> tree;\n    vector<V> vs(n);\n    rep(i, 0, n) {\n        ll x;\n   \
    \     io.read(x);\n        vs[i] = tree.make(i, x);\n    }\n    rep(i, 0, n -\
    \ 1) {\n        int x, y;\n        io.read(x, y);\n        tree.link(vs[x], vs[y]);\n\
    \    }\n    while (q--) {\n        int t;\n        io.read(t);\n        if (t\
    \ == 0) {\n            int x, y;\n            io.read(x, y);\n            tree.cut(vs[x],\
    \ vs[y]);\n            io.read(x, y);\n            tree.link(vs[x], vs[y]);\n\
    \        }\n        if (t == 1) {\n            int v, x;\n            io.read(v,\
    \ x);\n            tree.update(vs[v], x);\n        }\n        if (t == 2) {\n\
    \            int v, p;\n            io.read(v, p);\n            auto ret = tree.query(vs[p],\
    \ vs[v]);\n            io.write(ret.csum);\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Graph/linkcut.hpp\"\n\nusing Key = ll;\nstruct Monoid {\n    ll sum, psum,\
    \ csum, light;\n    Monoid() : sum(0), psum(0), csum(0), light(0) {}\n    void\
    \ inverse() {\n        swap(psum, csum);\n    }\n    void merge(Key val, Monoid\
    \ p, Monoid c) {\n        sum = p.sum + c.sum + val + light;\n        psum = p.psum\
    \ + val + light;\n        csum = c.csum + val + light;\n    }\n    void add(Monoid\
    \ v) {\n        light += v.sum;\n    }\n    void sub(Monoid v) {\n        light\
    \ -= v.sum;\n    }\n};\nll f(ll x, ll y) {\n    return x + y;\n}\nusing V = LCT<Monoid,\
    \ Key, f>::Node *;\n\nFastIO io;\nint main() {\n    int n, q;\n    io.read(n,\
    \ q);\n    LCT<Monoid, Key, f> tree;\n    vector<V> vs(n);\n    rep(i, 0, n) {\n\
    \        ll x;\n        io.read(x);\n        vs[i] = tree.make(i, x);\n    }\n\
    \    rep(i, 0, n - 1) {\n        int x, y;\n        io.read(x, y);\n        tree.link(vs[x],\
    \ vs[y]);\n    }\n    while (q--) {\n        int t;\n        io.read(t);\n   \
    \     if (t == 0) {\n            int x, y;\n            io.read(x, y);\n     \
    \       tree.cut(vs[x], vs[y]);\n            io.read(x, y);\n            tree.link(vs[x],\
    \ vs[y]);\n        }\n        if (t == 1) {\n            int v, x;\n         \
    \   io.read(v, x);\n            tree.update(vs[v], x);\n        }\n        if\
    \ (t == 2) {\n            int v, p;\n            io.read(v, p);\n            auto\
    \ ret = tree.query(vs[p], vs[v]);\n            io.write(ret.csum);\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/linkcut.hpp
  isVerificationFile: false
  path: Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp
  requiredBy: []
  timestamp: '2024-01-18 04:47:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp
layout: document
redirect_from:
- /library/Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp
- /library/Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp.html
title: Verify/LC_dynamic_tree_vertex_add_subtree_sum.cpp
---
