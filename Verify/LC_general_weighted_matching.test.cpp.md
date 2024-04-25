---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/generalweightedmatching.hpp
    title: General Weighted Matching
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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_weighted_matching
    links:
    - https://judge.yosupo.jp/problem/general_weighted_matching
  bundledCode: "#line 1 \"Verify/LC_general_weighted_matching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\n\n#line\
    \ 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\n#define\
    \ rrep(i, a, b) for (int i = (int)(b-1); i >= (int)(a); i--)\r\n#define ALL(v)\
    \ (v).begin(), (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
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
    \ Fast IO\r\n */\n#line 5 \"Verify/LC_general_weighted_matching.test.cpp\"\n\n\
    #line 2 \"Graph/generalweightedmatching.hpp\"\n\n// reference: http://www.cs.kent.edu/~dragan/GraphAn/p23-galil.pdf\n\
    class GeneralWeightedMatching{\n    struct E{int u,v; ll w;};\n    int n,m,in;\n\
    \    vector<vector<E>> G;\n    vector<int> mate,slack,root,par,isS,used;\n   \
    \ vector<vector<int>> flower,belong;\n    vector<ll> dual;\n    queue<int> que;\n\
    \    \n    ll dist(const E& e){return dual[e.u]+dual[e.v]-e.w;}\n    void update(int\
    \ u,int v){\n        if(!slack[v] or dist(G[u][v])<dist(G[slack[v]][v]))slack[v]=u;\n\
    \    }\n    void recalc(int v){\n        slack[v]=0;\n        rep(i,1,n+1)if(G[i][v].w\
    \ and root[i]!=v and isS[root[i]]==1)update(i,v);\n    }\n    void push(int v){\n\
    \        if(v<=n)que.push(v);\n        else for(auto& nxt:flower[v])push(nxt);\n\
    \    }\n    void set(int v,int rt){\n        root[v]=rt;\n        if(v>n)for(auto&\
    \ nxt:flower[v])set(nxt,rt);\n    }\n    int findeven(int b,int v){\n        int\
    \ pos=find(ALL(flower[b]),v)-flower[b].begin();\n        if(pos&1){\n        \
    \    reverse(flower[b].begin()+1,flower[b].end());\n            pos=flower[b].size()-pos;\n\
    \        }\n        return pos;\n    }\n    void match(int u,int v){\n       \
    \ mate[u]=G[u][v].v;\n        if(u>n){\n            int x=belong[u][G[u][v].u];\n\
    \            int pos=findeven(u,x);\n            rep(i,0,pos)match(flower[u][i],flower[u][i^1]);\n\
    \            match(x,v);\n            rotate(flower[u].begin(),flower[u].begin()+pos,flower[u].end());\n\
    \        }\n    }\n    void link(int u,int v){\n        for(;;){\n           \
    \ int nv=root[mate[u]];\n            match(u,v);\n            if(!nv)break;\n\
    \            v=nv,u=root[par[nv]];\n            match(v,u);\n        }\n    }\n\
    \    void make(int u,int v,int lca){\n        int id=n+1;\n        while(id<=m\
    \ and root[id])id++;\n        if(id>m)m++;\n        flower[id].clear();\n    \
    \    rep(i,1,m+1)G[id][i].w=G[i][id].w=0;\n        rep(i,1,n+1)belong[id][i]=0;\n\
    \        isS[id]=1,dual[id]=0,mate[id]=mate[lca];\n        while(u!=lca){\n  \
    \          flower[id].push_back(u);\n            u=root[mate[u]];\n          \
    \  push(u);\n            flower[id].push_back(u);\n            u=root[par[u]];\n\
    \        }\n        flower[id].push_back(lca);\n        reverse(ALL(flower[id]));\n\
    \        while(v!=lca){\n            flower[id].push_back(v);\n            v=root[mate[v]];\n\
    \            push(v);\n            flower[id].push_back(v);\n            v=root[par[v]];\n\
    \        }\n        set(id,id);\n        for(auto& c:flower[id]){\n          \
    \  rep(i,1,m+1)if(!G[id][i].w or dist(G[c][i])<dist(G[id][i])){\n            \
    \    G[id][i]=G[c][i],G[i][id]=G[i][c];\n            }\n            rep(i,1,n+1)if(belong[c][i])belong[id][i]=c;\n\
    \        }\n        recalc(id);\n    }\n    void expand(int b){\n        for(auto&\
    \ c:flower[b])set(c,c);\n        int x=belong[b][G[b][par[b]].u];\n        isS[x]=2,par[x]=par[b];\n\
    \        int pos=findeven(b,x);\n        for(int i=0;i<pos;i+=2){\n          \
    \  int T=flower[b][i],S=flower[b][i+1];\n            isS[S]=1,isS[T]=2;\n    \
    \        par[T]=G[S][T].u;\n            slack[S]=slack[T]=0;\n            push(S);\n\
    \        }\n        rep(i,pos+1,flower[b].size()){\n            isS[flower[b][i]]=0;\n\
    \            recalc(flower[b][i]);\n        }\n        flower[b].clear();\n  \
    \      root[b]=0;\n    }\n    bool path(const E& e){\n        int u=root[e.u],v=root[e.v];\n\
    \        if(!isS[v]){\n            par[v]=e.u;\n            isS[v]=2;\n      \
    \      int nu=root[mate[v]];\n            slack[v]=slack[nu]=0;\n            isS[nu]=1;\n\
    \            push(nu);\n        }\n        else if(isS[v]==1){\n            int\
    \ lca=0,bu=u,bv=v;\n            in++;\n            while(bu){\n              \
    \  used[bu]=in;\n                bu=root[mate[bu]];\n                if(bu)bu=root[par[bu]];\n\
    \            }\n            while(bv){\n                if(used[bv]==in){\n  \
    \                  lca=bv;\n                    break;\n                }\n  \
    \              bv=root[mate[bv]];\n                if(bv)bv=root[par[bv]];\n \
    \           }\n            if(lca)make(u,v,lca);\n            else{\n        \
    \        link(u,v),link(v,u);\n                return true;\n            }\n \
    \       }\n        return false;\n    }\n    bool augment(){\n        isS=slack=par=vector<int>(n*2);\n\
    \        que=queue<int>();\n        rep(i,1,m+1)if(root[i]==i and !mate[i]){\n\
    \            isS[i]=1;\n            push(i);\n        }\n        if(que.empty())return\
    \ false;\n        for(;;){\n            while(!que.empty()){\n               \
    \ int v=que.front();\n                que.pop();\n                rep(i,1,n+1)if(G[v][i].w\
    \ and root[i]!=root[v]){\n                    if(!dist(G[v][i])){\n          \
    \              if(path(G[v][i]))return true;\n                    }\n        \
    \            else if(isS[root[i]]!=2)update(v,root[i]);\n                }\n \
    \           }\n            ll delta=INF;\n            rep(i,n+1,m+1)if(root[i]==i\
    \ and isS[i]==2)chmin(delta,dual[i]/2);\n            rep(i,1,m+1)if(root[i]==i\
    \ and slack[i] and isS[i]!=2){\n                if(!isS[i])chmin(delta,dist(G[slack[i]][i]));\n\
    \                else chmin(delta,dist(G[slack[i]][i])/2);\n            }\n  \
    \          rep(i,1,n+1){\n                if(isS[root[i]]==1){\n             \
    \       dual[i]-=delta;\n                    if(dual[i]<=0)return false;\n   \
    \             }\n                else if(isS[root[i]]==2)dual[i]+=delta;\n   \
    \         }\n            rep(i,n+1,m+1)if(root[i]==i and isS[i]){\n          \
    \      if(isS[i]==1)dual[i]+=delta*2;\n                else dual[i]-=delta*2;\n\
    \            }\n            rep(i,1,m+1)if(root[i]==i and slack[i] and root[slack[i]]!=i){\n\
    \                if(dist(G[slack[i]][i])==0 and path(G[slack[i]][i]))return true;\n\
    \            }\n            rep(i,n+1,m+1)if(root[i]==i and isS[i]==2 and dual[i]==0)expand(i);\n\
    \        }\n    }\npublic:\n    GeneralWeightedMatching(int _n):n(_n),m(n),in(0),G(n*2,vector<E>(n*2)),\n\
    \        mate(n*2),root(n*2),used(n*2),flower(n*2),belong(n*2,vector<int>(n*2)),dual(n*2){\n\
    \        rep(i,0,n+1){\n            root[i]=i;\n            belong[i][i]=i;\n\
    \            if(i)dual[i]=INF;\n            rep(j,0,n+1)G[i][j]=E{i,j,0};\n  \
    \      }\n    }\n    void add_edge(int u,int v,ll w){\n        u++,v++;\n    \
    \    chmax(G[u][v].w,w*2);\n        chmax(G[v][u].w,w*2);\n    }\n    vector<int>\
    \ run(){\n        while(augment());\n        vector<int> res(n,-1);\n        rep(i,1,n+1)if(mate[i])res[i-1]=mate[i]-1;\n\
    \        return res;\n    }\n};\n\n/**\n * @brief General Weighted Matching\n\
    */\n#line 7 \"Verify/LC_general_weighted_matching.test.cpp\"\n\n\nint main(){\n\
    \    int n,m;\n    read(n,m);\n    GeneralWeightedMatching solver(n);\n    vector\
    \ g(n,vector<ll>(n));\n    rep(_,0,m){\n        int u,v,w;\n        read(u,v,w);\n\
    \        g[u][v]=g[v][u]=w;\n        solver.add_edge(u,v,w);\n    }\n    auto\
    \ res=solver.run();\n    ll r1=0,r2=0;\n    rep(i,0,n)if(res[i]>i){\n        r1++;\n\
    \        r2+=g[res[i]][i];\n    }\n    print(r1,r2);\n    rep(i,0,n)if(res[i]>i)print(res[i],i);\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Graph/generalweightedmatching.hpp\"\n\n\nint main(){\n    int n,m;\n    read(n,m);\n\
    \    GeneralWeightedMatching solver(n);\n    vector g(n,vector<ll>(n));\n    rep(_,0,m){\n\
    \        int u,v,w;\n        read(u,v,w);\n        g[u][v]=g[v][u]=w;\n      \
    \  solver.add_edge(u,v,w);\n    }\n    auto res=solver.run();\n    ll r1=0,r2=0;\n\
    \    rep(i,0,n)if(res[i]>i){\n        r1++;\n        r2+=g[res[i]][i];\n    }\n\
    \    print(r1,r2);\n    rep(i,0,n)if(res[i]>i)print(res[i],i);\n    return 0;\n\
    }"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/generalweightedmatching.hpp
  isVerificationFile: true
  path: Verify/LC_general_weighted_matching.test.cpp
  requiredBy: []
  timestamp: '2024-04-26 03:32:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_general_weighted_matching.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_general_weighted_matching.test.cpp
- /verify/Verify/LC_general_weighted_matching.test.cpp.html
title: Verify/LC_general_weighted_matching.test.cpp
---
