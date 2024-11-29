---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: Graph/centroid.hpp
    title: Centroid Decomposition
  - icon: ':heavy_check_mark:'
    path: Graph/contour.hpp
    title: Contour Sum Query
  - icon: ':heavy_check_mark:'
    path: Graph/hld.hpp
    title: Heavy Light Decomposition
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
  bundledCode: "#line 1 \"Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\r\n    \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define\
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
    \ os;\r\n}\r\n#ifdef LOCAL\r\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define show(...) true\r\n#endif\r\ntemplate <typename T> void _show(int\
    \ i, T name) {\r\n    cerr << '\\n';\r\n}\r\ntemplate <typename T1, typename T2,\
    \ typename... T3>\r\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c)\
    \ {\r\n    for (; a[i] != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\
    \n    cerr << \":\" << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2\
    \ \"Utility/fastio.hpp\"\n#include <unistd.h>\r\nnamespace fastio {\r\nstatic\
    \ constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\nchar\
    \ out[100];\r\n// pointer of ibuf, obuf\r\n\r\nuint32_t pil = 0, pir = 0, por\
    \ = 0;\r\n\r\nstruct Pre {\r\n    char num[10000][4];\r\n    constexpr Pre() :\
    \ num() {\r\n        for (int i = 0; i < 10000; i++) {\r\n            int n =\
    \ i;\r\n            for (int j = 3; j >= 0; j--) {\r\n                num[i][j]\
    \ = n % 10 | '0';\r\n                n /= 10;\r\n            }\r\n        }\r\n\
    \    }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n    memmove(ibuf, ibuf\
    \ + pil, pir - pil);\r\n    pir = pir - pil + fread(ibuf + pir - pil, 1, SZ -\
    \ pir + pil, stdin);\r\n    pil = 0;\r\n    if (pir < SZ)\r\n        ibuf[pir++]\
    \ = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n    fwrite(obuf, 1, por, stdout);\r\
    \n    por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n    do {\r\n        if (pil +\
    \ 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\
    \n}\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\n    char c;\r\n    do {\r\
    \n        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
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
    \n * @brief Fast IO\r\n */\n#line 6 \"Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp\"\
    \n\r\n#line 2 \"Graph/centroid.hpp\"\n\r\nclass CentroidDecomposition {\r\n  \
    \  void get(int v, int p) {\r\n        sz[v] = 1;\r\n        for (auto &to : g[v])\r\
    \n            if (to != p and !used[to]) {\r\n                get(to, v);\r\n\
    \                sz[v] += sz[to];\r\n            }\r\n    }\r\n    int dfs(int\
    \ v, int p, int rt) {\r\n        for (auto &to : g[v])\r\n            if (to !=\
    \ p and !used[to]) {\r\n                if (sz[to] > (sz[rt] >> 1))\r\n      \
    \              return dfs(to, v, rt);\r\n            }\r\n        return v;\r\n\
    \    }\r\n\r\n  public:\r\n    int n, all;\r\n    vector<vector<int>> g;\r\n \
    \   vector<int> sz, used;\r\n    CentroidDecomposition(int n_) : n(n_), g(n),\
    \ sz(n), used(n) {}\r\n    void add_edge(int u, int v) {\r\n        g[u].push_back(v);\r\
    \n        g[v].push_back(u);\r\n    }\r\n    int size(int rt) {\r\n        get(rt,\
    \ -1);\r\n        return sz[rt];\r\n    }\r\n    int find(int rt) {\r\n      \
    \  get(rt, -1);\r\n        all = sz[rt];\r\n        int res = dfs(rt, -1, rt);\r\
    \n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Centroid Decomposition\r\
    \n */\n#line 2 \"Graph/hld.hpp\"\n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\
    \n    vector<vector<int>> g; vector<int> sz,in,out,rev,hs,par,dist;\r\n    void\
    \ dfs(int v,int p){\r\n        par[v]=p; sz[v]=1;\r\n        if(p!=-1)dist[v]=dist[p]+1;\r\
    \n        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());\r\n     \
    \   for(auto& to:g[v])if(to!=p){\r\n           dfs(to,v); sz[v]+=sz[to];\r\n \
    \          if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\n        }\r\n    }\r\n \
    \   void dfs2(int v,int p,int& k){\r\n        in[v]=k++; rev[in[v]]=v;\r\n   \
    \     for(auto& to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\
    \n            dfs2(to,v,k);\r\n        }\r\n        out[v]=k;\r\n    }\r\n   \
    \ HLD(int _n):g(_n),sz(_n),in(_n),out(_n),rev(_n),hs(_n),par(_n),dist(_n){}\r\n\
    \    void add_edge(int u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\
    \n    }\r\n    void run(int rt=0){dfs(rt,-1); hs[rt]=rt; int k=0; dfs2(rt,-1,k);}\r\
    \n    int lca(int u,int v){\r\n        for(;;v=par[hs[v]]){\r\n            if(in[u]>in[v])swap(u,v);\r\
    \n            if(hs[u]==hs[v])return u;\r\n        }\r\n    }\r\n    vector<P>\
    \ get(int u,int p,bool es=0){\r\n        assert(in[p]<=in[u] and out[u]<=out[p]);\r\
    \n        vector<P> res;\r\n        while(hs[u]!=hs[p]){\r\n            res.push_back({in[hs[u]],in[u]+1});\r\
    \n            u=par[hs[u]];\r\n        }\r\n        res.push_back({in[p]+es,in[u]+1});\r\
    \n        return res;\r\n    }\r\n    int jump(int u,int v,int k){\r\n       \
    \ if(k<0)return -1;\r\n        int g=lca(u,v);\r\n        int d0=dist[u]+dist[v]-dist[g]*2;\r\
    \n        if(d0<k)return -1;\r\n        int st=u;\r\n        if(dist[u]-dist[g]<k)st=v,k=d0-k;\r\
    \n        for(;;){\r\n            int to=hs[st];\r\n            if(in[st]-k>=in[to])return\
    \ rev[in[st]-k];\r\n            k-=in[st]-in[to]+1; st=par[to];\r\n        }\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Heavy Light Decomposition\r\n */\n#line\
    \ 4 \"Graph/contour.hpp\"\n\r\nstruct ContourQuery {\r\n    using P = pair<int,\
    \ int>;\r\n    using T = pair<int, P>;\r\n    ContourQuery(int _n = 0)\r\n   \
    \     : n(_n), m(_n), cd(_n), hld(_n), tree(_n * 3), depth(_n * 3),\r\n      \
    \    base(_n * 3), parent(_n * 3, -1), buf(_n * 3), width(_n * 3, 1),\r\n    \
    \      seg(_n * 3) {}\r\n    void add_edge(int u, int v) {\r\n        cd.add_edge(u,\
    \ v);\r\n        hld.add_edge(u, v);\r\n    }\r\n    vector<int> run() {\r\n \
    \       hld.run();\r\n        root = rec(0);\r\n        depth[0] = 0;\r\n    \
    \    dfs(0, -1);\r\n        rep(v, 0, m) if (v != root) {\r\n            seg[v]\
    \ = width[v];\r\n        }\r\n        return seg;\r\n    }\r\n    vector<P> point(int\
    \ v) {\r\n        vector<P> ret;\r\n        int cur = v;\r\n        while (cur\
    \ != root) {\r\n            int D =\r\n                depth[v] + depth[base[cur]]\
    \ - 2 * depth[hld.lca(v, base[cur])];\r\n            ret.push_back({cur, D});\r\
    \n            cur = parent[cur];\r\n        }\r\n        return ret;\r\n    }\r\
    \n    vector<T> range(int v, int L, int R) {\r\n        vector<T> ret;\r\n   \
    \     if (L <= 0 and 0 < R)\r\n            ret.push_back({v, {0, 1}});\r\n   \
    \     int cur = parent[v], pre = v;\r\n        while (pre != root) {\r\n     \
    \       int bro = -1;\r\n            for (auto &to : tree[cur])\r\n          \
    \      if (to != parent[cur] and to != pre) {\r\n                    bro = to;\r\
    \n                    break;\r\n                }\r\n            if (bro != -1)\
    \ {\r\n                int D = depth[v] + depth[base[bro]] -\r\n             \
    \           2 * depth[hld.lca(v, base[bro])];\r\n                ret.push_back(\r\
    \n                    {bro,\r\n                     {clamp(L - D, 0, seg[bro]),\
    \ clamp(R - D, 0, seg[bro])}});\r\n            }\r\n            pre = cur;\r\n\
    \            cur = parent[cur];\r\n        }\r\n        return ret;\r\n    }\r\
    \n\r\n  private:\r\n    int n, m, root;\r\n    CentroidDecomposition cd;\r\n \
    \   HLD hld;\r\n    vector<vector<int>> tree;\r\n    vector<int> depth, base,\
    \ parent, buf, width, seg;\r\n    int rec(int rt) {\r\n        int cen = cd.find(rt);\r\
    \n        cd.used[cen] = 1;\r\n        buf[cen] = 1;\r\n        queue<P> que;\r\
    \n        auto cmp = [&](int u, int v) { return buf[u] > buf[v]; };\r\n      \
    \  priority_queue<int, vector<int>, decltype(cmp)> pq{cmp};\r\n        pq.push(cen);\r\
    \n        depth[cen] = 0;\r\n        base[cen] = cen;\r\n        for (auto &to\
    \ : cd.g[cen])\r\n            if (!cd.used[to]) {\r\n                int v = rec(to);\r\
    \n                que.push({to, cen});\r\n                depth[to] = 1;\r\n \
    \               while (!que.empty()) {\r\n                    auto [cur, par]\
    \ = que.front();\r\n                    que.pop();\r\n                    width[v]\
    \ = depth[cur] + 1;\r\n                    for (auto &nxt : cd.g[cur])\r\n   \
    \                     if (nxt != par and !cd.used[nxt]) {\r\n                \
    \            depth[nxt] = depth[cur] + 1;\r\n                            que.push({nxt,\
    \ cur});\r\n                        }\r\n                }\r\n               \
    \ pq.push(v);\r\n                base[v] = cen;\r\n            }\r\n        cd.used[cen]\
    \ = 0;\r\n        if (pq.size() > 1) {\r\n            for (;;) {\r\n         \
    \       int v1 = pq.top();\r\n                pq.pop();\r\n                int\
    \ v2 = pq.top();\r\n                pq.pop();\r\n                int extra = m++;\r\
    \n                tree[extra].push_back(v1);\r\n                tree[extra].push_back(v2);\r\
    \n                tree[v1].push_back(extra);\r\n                tree[v2].push_back(extra);\r\
    \n                buf[extra] = buf[v1] + buf[v2];\r\n                parent[v1]\
    \ = parent[v2] = extra;\r\n                if (pq.empty()) {\r\n             \
    \       return extra;\r\n                }\r\n                pq.push(extra);\r\
    \n                base[extra] = cen;\r\n                width[extra] = max(width[v1],\
    \ width[v2]);\r\n            }\r\n        } else {\r\n            int extra =\
    \ m++;\r\n            tree[extra].push_back(cen);\r\n            tree[cen].push_back(extra);\r\
    \n            buf[extra] = 1;\r\n            parent[cen] = extra;\r\n        \
    \    return extra;\r\n        }\r\n    }\r\n    void dfs(int v, int p) {\r\n \
    \       for (auto &to : cd.g[v])\r\n            if (to != p) {\r\n           \
    \     depth[to] = depth[v] + 1;\r\n                dfs(to, v);\r\n           \
    \ }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Contour Sum Query\r\n */\n#line 2 \"\
    DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct BIT{\r\n    int n; T all=0;\
    \ vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\n    void clear(){val.assign(n+10,0);\
    \ all=T();}\r\n    void add(int i,T x){\r\n        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\
    \n        all+=x;\r\n    }\r\n    T sum(int i){\r\n        T res=0;\r\n      \
    \  for(;i;i-=(i&-i))res+=val[i];\r\n        return res;\r\n    }\r\n    T sum(int\
    \ L,int R){return sum(R)-sum(L);} // [L,R)\r\n    int lower_bound(T x){\r\n  \
    \      int ret=0,len=1;\r\n        while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\
    \n            if(ret+len<=n and val[ret+len]<x){\r\n                ret+=len;\r\
    \n                x-=val[ret];\r\n            }\r\n        }\r\n        return\
    \ ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Binary Indexed Tree\r\n */\n#line\
    \ 9 \"Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp\"\n\r\nint main()\
    \ {\r\n    int n, q;\r\n    read(n, q);\r\n    vector<ll> a(n);\r\n    read(a);\r\
    \n    ContourQuery buf(n);\r\n    rep(_, 0, n - 1) {\r\n        int u, v;\r\n\
    \        read(u, v);\r\n        buf.add_edge(u, v);\r\n    }\r\n    auto len =\
    \ buf.run();\r\n    vector<BIT<ll>> seg(len.size());\r\n    rep(i, 0, len.size())\
    \ seg[i] = BIT<ll>(len[i]);\r\n    rep(v, 0, n) {\r\n        for (auto &[i, p]\
    \ : buf.point(v))\r\n            seg[i].add(p, a[v]);\r\n    }\r\n\r\n    while\
    \ (q--) {\r\n        int t;\r\n        read(t);\r\n        if (t == 0) {\r\n \
    \           int v, x;\r\n            read(v, x);\r\n            for (auto &[i,\
    \ p] : buf.point(v))\r\n                seg[i].add(p, x);\r\n        } else {\r\
    \n            int v, L, R;\r\n            read(v, L, R);\r\n            ll ret\
    \ = 0;\r\n            for (auto &[i, LR] : buf.range(v, L, R)) {\r\n         \
    \       auto [lb, rb] = LR;\r\n                ret += seg[i].sum(lb, rb);\r\n\
    \            }\r\n            print(ret);\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\r\n    \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n\r\n#include \"Graph/contour.hpp\"\r\n#include \"DataStructure/bit.hpp\"\r\n\
    \r\nint main() {\r\n    int n, q;\r\n    read(n, q);\r\n    vector<ll> a(n);\r\
    \n    read(a);\r\n    ContourQuery buf(n);\r\n    rep(_, 0, n - 1) {\r\n     \
    \   int u, v;\r\n        read(u, v);\r\n        buf.add_edge(u, v);\r\n    }\r\
    \n    auto len = buf.run();\r\n    vector<BIT<ll>> seg(len.size());\r\n    rep(i,\
    \ 0, len.size()) seg[i] = BIT<ll>(len[i]);\r\n    rep(v, 0, n) {\r\n        for\
    \ (auto &[i, p] : buf.point(v))\r\n            seg[i].add(p, a[v]);\r\n    }\r\
    \n\r\n    while (q--) {\r\n        int t;\r\n        read(t);\r\n        if (t\
    \ == 0) {\r\n            int v, x;\r\n            read(v, x);\r\n            for\
    \ (auto &[i, p] : buf.point(v))\r\n                seg[i].add(p, x);\r\n     \
    \   } else {\r\n            int v, L, R;\r\n            read(v, L, R);\r\n   \
    \         ll ret = 0;\r\n            for (auto &[i, LR] : buf.range(v, L, R))\
    \ {\r\n                auto [lb, rb] = LR;\r\n                ret += seg[i].sum(lb,\
    \ rb);\r\n            }\r\n            print(ret);\r\n        }\r\n    }\r\n \
    \   return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/contour.hpp
  - Graph/centroid.hpp
  - Graph/hld.hpp
  - DataStructure/bit.hpp
  isVerificationFile: true
  path: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
  requiredBy: []
  timestamp: '2024-11-30 06:30:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
- /verify/Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp.html
title: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
---
