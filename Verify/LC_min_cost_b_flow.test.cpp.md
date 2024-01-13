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
    #line 2 \"Graph/maxflow.hpp\"\n\r\nstruct MaxFlow {\r\n    struct Edge {\r\n \
    \       int to, rev;\r\n        ll cap;\r\n    };\r\n    int V;\r\n    vector<vector<Edge>>\
    \ G;\r\n    vector<int> itr, level;\r\n    using P = pair<int, int>;\r\n    vector<P>\
    \ es;\r\n\r\n  public:\r\n    MaxFlow() {}\r\n    MaxFlow(int V) : V(V) { G.assign(V,\
    \ vector<Edge>()); }\r\n    int add_vertex() {\r\n        G.push_back(vector<Edge>());\r\
    \n        return V++;\r\n    }\r\n    void add_edge(int from, int to, ll cap)\
    \ {\r\n        int fid = SZ(G[from]), tid = SZ(G[to]);\r\n        if (from ==\
    \ to)\r\n            tid++;\r\n        es.push_back({from, fid});\r\n        G[from].push_back({to,\
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
    \ f;\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Maximum Flow\r\n */\n#line 3 \"Graph/mincostflow.hpp\"\n\r\n// yosupo orz\r\n\
    template <class Cap, class Cost> struct MinCostFlow {\r\n    struct X {\r\n  \
    \      int from, to;\r\n        Cap lb, ub, flow;\r\n        Cost cost;\r\n  \
    \  };\r\n    struct Edge {\r\n        int to, rev;\r\n        Cap cap;\r\n   \
    \     Cost cost;\r\n    };\r\n    using P = pair<int, int>;\r\n    int n, m;\r\
    \n    vector<X> es;\r\n    vector<Cap> exc;\r\n    vector<Cost> dual;\r\n    vector<vector<Edge>>\
    \ g;\r\n    Cost MX;\r\n    MinCostFlow(int _n) : n(_n), m(0), exc(n), dual(n),\
    \ g(n), MX(0) {}\r\n    void add_edge(int from, int to, Cap lb, Cap ub, Cost cost)\
    \ {\r\n        m++;\r\n        chmax(MX, cost);\r\n        chmax(MX, -cost);\r\
    \n        es.push_back({from, to, lb, ub, 0, cost});\r\n    }\r\n    void add_excess(int\
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
    \ Cost b-flow\r\n */\n#line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\n\r\
    \nclass FastIO {\r\n    static constexpr int L = 1 << 16;\r\n    char rdbuf[L];\r\
    \n    int rdLeft = 0, rdRight = 0;\r\n    inline void reload() {\r\n        int\
    \ len = rdRight - rdLeft;\r\n        memmove(rdbuf, rdbuf + rdLeft, len);\r\n\
    \        rdLeft = 0, rdRight = len;\r\n        rdRight += fread(rdbuf + len, 1,\
    \ L - len, stdin);\r\n    }\r\n    inline bool skip() {\r\n        for (;;) {\r\
    \n            while (rdLeft != rdRight and rdbuf[rdLeft] <= ' ')\r\n         \
    \       rdLeft++;\r\n            if (rdLeft == rdRight) {\r\n                reload();\r\
    \n                if (rdLeft == rdRight)\r\n                    return false;\r\
    \n            } else\r\n                break;\r\n        }\r\n        return\
    \ true;\r\n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value,\
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
    };\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 6 \"Verify/LC_min_cost_b_flow.test.cpp\"\
    \n\r\nnamespace std {\r\nstring to_string(__int128_t x) {\r\n    if (x == 0)\r\
    \n        return \"0\";\r\n    __uint128_t k = x;\r\n    if (k == (((__uint128_t)1)\
    \ << 127))\r\n        return \"-170141183460469231731687303715884105728\";\r\n\
    \    string result;\r\n    if (x < 0) {\r\n        result += \"-\";\r\n      \
    \  x *= -1;\r\n    }\r\n    string t;\r\n    while (x) {\r\n        t.push_back('0'\
    \ + x % 10);\r\n        x /= 10;\r\n    }\r\n    reverse(t.begin(), t.end());\r\
    \n    return result + t;\r\n}\r\n} // namespace std\r\n\r\nint main() {\r\n  \
    \  FastIO io;\r\n    int n, m;\r\n    io.read(n, m);\r\n    MinCostFlow<ll, i128>\
    \ mcf(n);\r\n    rep(i, 0, n) {\r\n        int b;\r\n        io.read(b);\r\n \
    \       mcf.add_excess(i, b);\r\n    }\r\n    rep(i, 0, m) {\r\n        int s,\
    \ t, l, u, c;\r\n        io.read(s, t, l, u, c);\r\n        mcf.add_edge(s, t,\
    \ l, u, c);\r\n    }\r\n    auto [ok, ret] = mcf.run();\r\n    if (!ok) {\r\n\
    \        io.write(\"infeasible\");\r\n        return 0;\r\n    }\r\n    io.write(to_string(ret));\r\
    \n    rep(i, 0, n) io.write(to_string(mcf.dual[i]));\r\n    rep(i, 0, m) io.write(mcf.get_flow(i));\r\
    \n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Graph/mincostflow.hpp\"\r\n\
    #include \"Utility/fastio.hpp\"\r\n\r\nnamespace std {\r\nstring to_string(__int128_t\
    \ x) {\r\n    if (x == 0)\r\n        return \"0\";\r\n    __uint128_t k = x;\r\
    \n    if (k == (((__uint128_t)1) << 127))\r\n        return \"-170141183460469231731687303715884105728\"\
    ;\r\n    string result;\r\n    if (x < 0) {\r\n        result += \"-\";\r\n  \
    \      x *= -1;\r\n    }\r\n    string t;\r\n    while (x) {\r\n        t.push_back('0'\
    \ + x % 10);\r\n        x /= 10;\r\n    }\r\n    reverse(t.begin(), t.end());\r\
    \n    return result + t;\r\n}\r\n} // namespace std\r\n\r\nint main() {\r\n  \
    \  FastIO io;\r\n    int n, m;\r\n    io.read(n, m);\r\n    MinCostFlow<ll, i128>\
    \ mcf(n);\r\n    rep(i, 0, n) {\r\n        int b;\r\n        io.read(b);\r\n \
    \       mcf.add_excess(i, b);\r\n    }\r\n    rep(i, 0, m) {\r\n        int s,\
    \ t, l, u, c;\r\n        io.read(s, t, l, u, c);\r\n        mcf.add_edge(s, t,\
    \ l, u, c);\r\n    }\r\n    auto [ok, ret] = mcf.run();\r\n    if (!ok) {\r\n\
    \        io.write(\"infeasible\");\r\n        return 0;\r\n    }\r\n    io.write(to_string(ret));\r\
    \n    rep(i, 0, n) io.write(to_string(mcf.dual[i]));\r\n    rep(i, 0, m) io.write(mcf.get_flow(i));\r\
    \n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/mincostflow.hpp
  - Graph/maxflow.hpp
  - Utility/fastio.hpp
  isVerificationFile: true
  path: Verify/LC_min_cost_b_flow.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 05:39:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_min_cost_b_flow.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_min_cost_b_flow.test.cpp
- /verify/Verify/LC_min_cost_b_flow.test.cpp.html
title: Verify/LC_min_cost_b_flow.test.cpp
---
