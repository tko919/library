---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/maxflow.hpp
    title: Maximum Flow
  - icon: ':heavy_check_mark:'
    path: Graph/mincostflow.hpp
    title: Minimum Cost b-flow
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
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#line 1 \"Verify/LC_min_cost_b_flow.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/min_cost_b_flow\"\r\n\r\n#line 1 \"Template/template.hpp\"\
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
    \  os << d << \", \";\r\n    os << \"]\";\r\n    return os;\r\n}\n#line 2 \"Graph/maxflow.hpp\"\
    \n\r\nstruct MaxFlow {\r\n    struct Edge {\r\n        int to, rev;\r\n      \
    \  ll cap;\r\n    };\r\n    int V;\r\n    vector<vector<Edge>> G;\r\n    vector<int>\
    \ itr, level;\r\n    using P = pair<int, int>;\r\n    vector<P> es;\r\n\r\n  public:\r\
    \n    MaxFlow() {}\r\n    MaxFlow(int V) : V(V) {\r\n        G.assign(V, vector<Edge>());\r\
    \n    }\r\n    int add_vertex() {\r\n        G.push_back(vector<Edge>());\r\n\
    \        return V++;\r\n    }\r\n    void add_edge(int from, int to, ll cap) {\r\
    \n        int fid = SZ(G[from]), tid = SZ(G[to]);\r\n        if (from == to)\r\
    \n            tid++;\r\n        es.push_back({from, fid});\r\n        G[from].push_back({to,\
    \ tid, cap});\r\n        G[to].push_back({from, fid, 0});\r\n    }\r\n    struct\
    \ Type {\r\n        int from, to;\r\n        ll cap, recap;\r\n    };\r\n    Type\
    \ get_edge(int i) {\r\n        auto [from, pos] = es[i];\r\n        auto e = G[from][pos];\r\
    \n        auto re = G[e.to][e.rev];\r\n        return Type{from, e.to, e.cap,\
    \ re.cap};\r\n    }\r\n    void bfs(int s) {\r\n        level.assign(V, -1);\r\
    \n        queue<int> q;\r\n        level[s] = 0;\r\n        q.push(s);\r\n   \
    \     while (!q.empty()) {\r\n            int v = q.front();\r\n            q.pop();\r\
    \n            for (auto &e : G[v]) {\r\n                if (e.cap > 0 && level[e.to]\
    \ < 0) {\r\n                    level[e.to] = level[v] + 1;\r\n              \
    \      q.push(e.to);\r\n                }\r\n            }\r\n        }\r\n  \
    \  }\r\n    ll dfs(int v, int t, ll f) {\r\n        if (v == t)\r\n          \
    \  return f;\r\n        for (int &i = itr[v]; i < (int)G[v].size(); i++) {\r\n\
    \            Edge &e = G[v][i];\r\n            if (e.cap > 0 && level[v] < level[e.to])\
    \ {\r\n                ll d = dfs(e.to, t, min(f, e.cap));\r\n               \
    \ if (d > 0) {\r\n                    e.cap -= d, G[e.to][e.rev].cap += d;\r\n\
    \                    return d;\r\n                }\r\n            }\r\n     \
    \   }\r\n        return 0;\r\n    }\r\n    ll run(int s, int t) {\r\n        ll\
    \ ret = 0, f;\r\n        while (bfs(s), level[t] >= 0) {\r\n            itr.assign(V,\
    \ 0);\r\n            while ((f = dfs(s, t, INF)) > 0)\r\n                ret +=\
    \ f;\r\n        }\r\n        return ret;\r\n    }\r\n    vector<int> cut() {\r\
    \n        vector<int> ret(V);\r\n        rep(v, 0, V) if (level[v] < 0) ret[v]\
    \ = 1;\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Flow\r\
    \n */\n#line 3 \"Graph/mincostflow.hpp\"\n\r\n// yosupo orz\r\ntemplate <class\
    \ Cap, class Cost> struct MinCostFlow {\r\n    struct X {\r\n        int from,\
    \ to;\r\n        Cap lb, ub, flow;\r\n        Cost cost;\r\n    };\r\n    struct\
    \ Edge {\r\n        int to, rev;\r\n        Cap cap;\r\n        Cost cost;\r\n\
    \    };\r\n    using P = pair<int, int>;\r\n    int n, m;\r\n    vector<X> es;\r\
    \n    vector<Cap> exc;\r\n    vector<Cost> dual;\r\n    vector<vector<Edge>> g;\r\
    \n    Cost MX;\r\n    MinCostFlow(int _n) : n(_n), m(0), exc(n), dual(n), g(n),\
    \ MX(0) {}\r\n    void add_edge(int from, int to, Cap lb, Cap ub, Cost cost) {\r\
    \n        m++;\r\n        chmax(MX, cost);\r\n        chmax(MX, -cost);\r\n  \
    \      es.push_back({from, to, lb, ub, 0, cost});\r\n    }\r\n    void add_excess(int\
    \ v, Cap c) { exc[v] += c; }\r\n    pair<bool, Cost> run() {\r\n        MaxFlow\
    \ mf(n + 2);\r\n        int S = n, T = n + 1;\r\n        Cap psum = 0, nsum =\
    \ 0;\r\n        for (auto &e : es) {\r\n            exc[e.to] += e.lb;\r\n   \
    \         exc[e.from] -= e.lb;\r\n            mf.add_edge(e.from, e.to, e.ub -\
    \ e.lb);\r\n        }\r\n        rep(i, 0, n) {\r\n            if (exc[i] > 0)\
    \ {\r\n                psum += exc[i];\r\n                mf.add_edge(S, i, exc[i]);\r\
    \n            }\r\n            if (exc[i] < 0) {\r\n                nsum += -exc[i];\r\
    \n                mf.add_edge(i, T, -exc[i]);\r\n            }\r\n        }\r\n\
    \r\n        if (psum != nsum or mf.run(S, T) != psum)\r\n            return {false,\
    \ 0};\r\n\r\n        using P = pair<int, int>;\r\n        vector<P> pos;\r\n \
    \       rep(i, 0, m) {\r\n            auto e = mf.get_edge(i);\r\n           \
    \ Cost cost = es[i].cost * n;\r\n            int fid = SZ(g[e.from]), tid = SZ(g[e.to]);\r\
    \n            if (e.from == e.to)\r\n                tid++;\r\n            pos.push_back({e.from,\
    \ fid});\r\n            g[e.from].push_back({e.to, tid, e.cap, cost});\r\n   \
    \         g[e.to].push_back({e.from, fid, e.recap, -cost});\r\n        }\r\n\r\
    \n        // solve\r\n        Cost eps = MX * n + 1;\r\n        while (eps > 1)\
    \ {\r\n            eps = max<Cost>(eps >> 2, 1);\r\n            refine(eps);\r\
    \n        }\r\n\r\n        Cost ret = 0;\r\n        rep(i, 0, m) {\r\n       \
    \     auto [from, fid] = pos[i];\r\n            es[i].flow = es[i].ub - g[from][fid].cap;\r\
    \n            ret += es[i].flow * es[i].cost;\r\n        }\r\n        dual.assign(n,\
    \ 0);\r\n        for (;;) {\r\n            bool upd = 0;\r\n            rep(i,\
    \ 0, n) {\r\n                for (auto &e : g[i])\r\n                    if (e.cap)\
    \ {\r\n                        auto cost = dual[i] + e.cost / n;\r\n         \
    \               if (chmin(dual[e.to], cost)) {\r\n                           \
    \ upd = 1;\r\n                        }\r\n                    }\r\n         \
    \   }\r\n            if (!upd)\r\n                break;\r\n        }\r\n    \
    \    return {true, ret};\r\n    }\r\n    Cap get_flow(int i) const { return es[i].flow;\
    \ }\r\n\r\n  private:\r\n    void refine(Cost &eps) {\r\n        exc.assign(n,\
    \ 0);\r\n        vector<int> used(n);\r\n        queue<int> que;\r\n        vector<int>\
    \ iter(n);\r\n\r\n        auto cost = [&](int from, const Edge &e) {\r\n     \
    \       return e.cost + dual[from] - dual[e.to];\r\n        };\r\n        auto\
    \ push = [&](int from, Edge &e, Cap cap) {\r\n            exc[from] -= cap;\r\n\
    \            exc[e.to] += cap;\r\n            g[e.to][e.rev].cap += cap;\r\n \
    \           e.cap -= cap;\r\n        };\r\n        auto relabel = [&](int v) {\r\
    \n            iter[v] = 0;\r\n            Cost down = MX * (n + 1);\r\n      \
    \      for (auto &e : g[v])\r\n                if (e.cap) {\r\n              \
    \      chmin(down, eps + cost(v, e));\r\n                }\r\n            dual[v]\
    \ -= down;\r\n            que.push(v);\r\n            used[v] = 1;\r\n       \
    \ };\r\n\r\n        rep(i, 0, n) {\r\n            for (auto &e : g[i])\r\n   \
    \             if (e.cap and cost(i, e) < 0) {\r\n                    push(i, e,\
    \ e.cap);\r\n                }\r\n        }\r\n        rep(i, 0, n) if (exc[i]\
    \ > 0) {\r\n            used[i] = 1;\r\n            que.push(i);\r\n        }\r\
    \n        while (!que.empty()) {\r\n            auto v = que.front();\r\n    \
    \        que.pop();\r\n            used[v] = 0;\r\n            for (int &i = iter[v];\
    \ i < SZ(g[v]); i++) {\r\n                auto &e = g[v][i];\r\n             \
    \   if (e.cap and cost(v, e) < 0) {\r\n                    push(v, e, min(exc[v],\
    \ e.cap));\r\n                    if (!used[e.to] and exc[e.to] > 0) {\r\n   \
    \                     used[e.to] = 1;\r\n                        que.push(e.to);\r\
    \n                    }\r\n                    if (exc[v] == 0)\r\n          \
    \              break;\r\n                }\r\n            }\r\n            if\
    \ (exc[v] > 0) {\r\n                relabel(v);\r\n            }\r\n        }\r\
    \n        eps = 0;\r\n        rep(i, 0, n) {\r\n            for (auto &e : g[i])\r\
    \n                if (e.cap) {\r\n                    chmax(eps, -cost(i, e));\r\
    \n                }\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Minimum\
    \ Cost b-flow\r\n */\n#line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\n\
    namespace fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\
    \nchar obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\n\r\nuint32_t\
    \ pil = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n    char num[10000][4];\r\n\
    \    constexpr Pre() : num() {\r\n        for (int i = 0; i < 10000; i++) {\r\n\
    \            int n = i;\r\n            for (int j = 3; j >= 0; j--) {\r\n    \
    \            num[i][j] = n % 10 | '0';\r\n                n /= 10;\r\n       \
    \     }\r\n        }\r\n    }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\
    \n    memmove(ibuf, ibuf + pil, pir - pil);\r\n    pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\r\n    pil = 0;\r\n    if (pir < SZ)\r\
    \n        ibuf[pir++] = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n    fwrite(obuf,\
    \ 1, por, stdout);\r\n    por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n    do {\r\
    \n        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (isspace(c));\r\n}\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\
    \n    char c;\r\n    do {\r\n        if (pil + 1 > pir)\r\n            load();\r\
    \n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\n    do {\r\n      \
    \  x += c;\r\n        if (pil == pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (!isspace(c));\r\n}\r\n\r\ntemplate <typename T> void rd_real(T\
    \ &x) {\r\n    string s;\r\n    rd(s);\r\n    x = stod(s);\r\n}\r\n\r\ntemplate\
    \ <typename T> void rd_integer(T &x) {\r\n    if (pil + 100 > pir)\r\n       \
    \ load();\r\n    char c;\r\n    do\r\n        c = ibuf[pil++];\r\n    while (c\
    \ < '-');\r\n    bool minus = 0;\r\n    if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\r\n        if (c == '-') {\r\n            minus = 1, c = ibuf[pil++];\r\
    \n        }\r\n    }\r\n    x = 0;\r\n    while ('0' <= c) {\r\n        x = x\
    \ * 10 + (c & 15), c = ibuf[pil++];\r\n    }\r\n    if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n        if (minus)\r\n            x = -x;\r\n  \
    \  }\r\n}\r\n\r\nvoid rd(int &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ll &x)\
    \ {\r\n    rd_integer(x);\r\n}\r\nvoid rd(i128 &x) {\r\n    rd_integer(x);\r\n\
    }\r\nvoid rd(uint &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ull &x) {\r\n  \
    \  rd_integer(x);\r\n}\r\nvoid rd(u128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid\
    \ rd(double &x) {\r\n    rd_real(x);\r\n}\r\nvoid rd(long double &x) {\r\n   \
    \ rd_real(x);\r\n}\r\n\r\ntemplate <class T, class U> void rd(pair<T, U> &p) {\r\
    \n    return rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t N = 0, typename\
    \ T> void rd_tuple(T &t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n        auto &x = std::get<N>(t);\r\n        rd(x);\r\n        rd_tuple<N\
    \ + 1>(t);\r\n    }\r\n}\r\ntemplate <class... T> void rd(tuple<T...> &tpl) {\r\
    \n    rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t N = 0, typename T> void rd(array<T,\
    \ N> &x) {\r\n    for (auto &d : x)\r\n        rd(d);\r\n}\r\ntemplate <class\
    \ T> void rd(vector<T> &x) {\r\n    for (auto &d : x)\r\n        rd(d);\r\n}\r\
    \n\r\nvoid read() {}\r\ntemplate <class H, class... T> void read(H &h, T &...t)\
    \ {\r\n    rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const char c) {\r\n    if (por\
    \ == SZ)\r\n        flush();\r\n    obuf[por++] = c;\r\n}\r\nvoid wt(const string\
    \ s) {\r\n    for (char c : s)\r\n        wt(c);\r\n}\r\nvoid wt(const char *s)\
    \ {\r\n    size_t len = strlen(s);\r\n    for (size_t i = 0; i < len; i++)\r\n\
    \        wt(s[i]);\r\n}\r\n\r\ntemplate <typename T> void wt_integer(T x) {\r\n\
    \    if (por > SZ - 100)\r\n        flush();\r\n    if (x < 0) {\r\n        obuf[por++]\
    \ = '-', x = -x;\r\n    }\r\n    int outi;\r\n    for (outi = 96; x >= 10000;\
    \ outi -= 4) {\r\n        memcpy(out + outi, pre.num[x % 10000], 4);\r\n     \
    \   x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n        memcpy(obuf + por,\
    \ pre.num[x], 4);\r\n        por += 4;\r\n    } else if (x >= 100) {\r\n     \
    \   memcpy(obuf + por, pre.num[x] + 1, 3);\r\n        por += 3;\r\n    } else\
    \ if (x >= 10) {\r\n        int q = (x * 103) >> 10;\r\n        obuf[por] = q\
    \ | '0';\r\n        obuf[por + 1] = (x - q * 10) | '0';\r\n        por += 2;\r\
    \n    } else\r\n        obuf[por++] = x | '0';\r\n    memcpy(obuf + por, out +\
    \ outi + 4, 96 - outi);\r\n    por += 96 - outi;\r\n}\r\n\r\ntemplate <typename\
    \ T> void wt_real(T x) {\r\n    ostringstream oss;\r\n    oss << fixed << setprecision(15)\
    \ << double(x);\r\n    string s = oss.str();\r\n    wt(s);\r\n}\r\n\r\nvoid wt(int\
    \ x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ll x) {\r\n    wt_integer(x);\r\n\
    }\r\nvoid wt(i128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(uint x) {\r\n   \
    \ wt_integer(x);\r\n}\r\nvoid wt(ull x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(u128\
    \ x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(double x) {\r\n    wt_real(x);\r\n\
    }\r\nvoid wt(long double x) {\r\n    wt_real(x);\r\n}\r\n\r\ntemplate <class T,\
    \ class U> void wt(const pair<T, U> val) {\r\n    wt(val.first);\r\n    wt(' ');\r\
    \n    wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename T> void wt_tuple(const\
    \ T t) {\r\n    if constexpr (N < std::tuple_size<T>::value) {\r\n        if constexpr\
    \ (N > 0) {\r\n            wt(' ');\r\n        }\r\n        const auto x = std::get<N>(t);\r\
    \n        wt(x);\r\n        wt_tuple<N + 1>(t);\r\n    }\r\n}\r\ntemplate <class...\
    \ T> void wt(tuple<T...> tpl) {\r\n    wt_tuple(tpl);\r\n}\r\ntemplate <class\
    \ T, size_t S> void wt(const array<T, S> val) {\r\n    auto n = val.size();\r\n\
    \    for (size_t i = 0; i < n; i++) {\r\n        if (i)\r\n            wt(' ');\r\
    \n        wt(val[i]);\r\n    }\r\n}\r\ntemplate <class T> void wt(const vector<T>\
    \ val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++) {\r\
    \n        if (i)\r\n            wt(' ');\r\n        wt(val[i]);\r\n    }\r\n}\r\
    \n\r\nvoid print() {\r\n    wt('\\n');\r\n}\r\ntemplate <class Head, class...\
    \ Tail> void print(Head &&head, Tail &&...tail) {\r\n    wt(head);\r\n    if (sizeof...(Tail))\r\
    \n        wt(' ');\r\n    print(forward<Tail>(tail)...);\r\n}\r\nvoid __attribute__((destructor))\
    \ _d() {\r\n    flush();\r\n}\r\n} // namespace fastio\r\n\r\nusing fastio::flush;\r\
    \nusing fastio::print;\r\nusing fastio::read;\r\n\r\ninline void first(bool i\
    \ = true) {\r\n    print(i ? \"first\" : \"second\");\r\n}\r\ninline void Alice(bool\
    \ i = true) {\r\n    print(i ? \"Alice\" : \"Bob\");\r\n}\r\ninline void yes(bool\
    \ i = true) {\r\n    print(i ? \"yes\" : \"no\");\r\n}\r\ninline void Yes(bool\
    \ i = true) {\r\n    print(i ? \"Yes\" : \"No\");\r\n}\r\ninline void No() {\r\
    \n    print(\"No\");\r\n}\r\ninline void YES(bool i = true) {\r\n    print(i ?\
    \ \"YES\" : \"NO\");\r\n}\r\ninline void NO() {\r\n    print(\"NO\");\r\n}\r\n\
    inline void Yay(bool i = true) {\r\n    print(i ? \"Yay!\" : \":(\");\r\n}\r\n\
    inline void Possible(bool i = true) {\r\n    print(i ? \"Possible\" : \"Impossible\"\
    );\r\n}\r\ninline void POSSIBLE(bool i = true) {\r\n    print(i ? \"POSSIBLE\"\
    \ : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 6 \"Verify/LC_min_cost_b_flow.test.cpp\"\
    \n\r\nnamespace std {\r\nstring to_string(__int128_t x) {\r\n    if (x == 0)\r\
    \n        return \"0\";\r\n    __uint128_t k = x;\r\n    if (k == (((__uint128_t)1)\
    \ << 127))\r\n        return \"-170141183460469231731687303715884105728\";\r\n\
    \    string result;\r\n    if (x < 0) {\r\n        result += \"-\";\r\n      \
    \  x *= -1;\r\n    }\r\n    string t;\r\n    while (x) {\r\n        t.push_back('0'\
    \ + x % 10);\r\n        x /= 10;\r\n    }\r\n    reverse(t.begin(), t.end());\r\
    \n    return result + t;\r\n}\r\n} // namespace std\r\n\r\nint main() {\r\n  \
    \  int n, m;\r\n    read(n, m);\r\n    MinCostFlow<ll, i128> mcf(n);\r\n    rep(i,\
    \ 0, n) {\r\n        int b;\r\n        read(b);\r\n        mcf.add_excess(i, b);\r\
    \n    }\r\n    rep(i, 0, m) {\r\n        int s, t, l, u, c;\r\n        read(s,\
    \ t, l, u, c);\r\n        mcf.add_edge(s, t, l, u, c);\r\n    }\r\n    auto [ok,\
    \ ret] = mcf.run();\r\n    if (!ok) {\r\n        print(\"infeasible\");\r\n  \
    \      return 0;\r\n    }\r\n    print(to_string(ret));\r\n    rep(i, 0, n) print(to_string(mcf.dual[i]));\r\
    \n    rep(i, 0, m) print(mcf.get_flow(i));\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Graph/mincostflow.hpp\"\r\n\
    #include \"Utility/fastio.hpp\"\r\n\r\nnamespace std {\r\nstring to_string(__int128_t\
    \ x) {\r\n    if (x == 0)\r\n        return \"0\";\r\n    __uint128_t k = x;\r\
    \n    if (k == (((__uint128_t)1) << 127))\r\n        return \"-170141183460469231731687303715884105728\"\
    ;\r\n    string result;\r\n    if (x < 0) {\r\n        result += \"-\";\r\n  \
    \      x *= -1;\r\n    }\r\n    string t;\r\n    while (x) {\r\n        t.push_back('0'\
    \ + x % 10);\r\n        x /= 10;\r\n    }\r\n    reverse(t.begin(), t.end());\r\
    \n    return result + t;\r\n}\r\n} // namespace std\r\n\r\nint main() {\r\n  \
    \  int n, m;\r\n    read(n, m);\r\n    MinCostFlow<ll, i128> mcf(n);\r\n    rep(i,\
    \ 0, n) {\r\n        int b;\r\n        read(b);\r\n        mcf.add_excess(i, b);\r\
    \n    }\r\n    rep(i, 0, m) {\r\n        int s, t, l, u, c;\r\n        read(s,\
    \ t, l, u, c);\r\n        mcf.add_edge(s, t, l, u, c);\r\n    }\r\n    auto [ok,\
    \ ret] = mcf.run();\r\n    if (!ok) {\r\n        print(\"infeasible\");\r\n  \
    \      return 0;\r\n    }\r\n    print(to_string(ret));\r\n    rep(i, 0, n) print(to_string(mcf.dual[i]));\r\
    \n    rep(i, 0, m) print(mcf.get_flow(i));\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/mincostflow.hpp
  - Graph/maxflow.hpp
  - Utility/fastio.hpp
  isVerificationFile: true
  path: Verify/LC_min_cost_b_flow.test.cpp
  requiredBy: []
  timestamp: '2024-04-29 14:20:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_min_cost_b_flow.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_min_cost_b_flow.test.cpp
- /verify/Verify/LC_min_cost_b_flow.test.cpp.html
title: Verify/LC_min_cost_b_flow.test.cpp
---
