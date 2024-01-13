---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/auxiliarytree.hpp
    title: Auxiliary Tree(Virtual Tree)
  - icon: ':heavy_check_mark:'
    path: Graph/lca.hpp
    title: Lowest Common Ancestor
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
    PROBLEM: https://yukicoder.me/problems/no/901
    links:
    - https://yukicoder.me/problems/no/901
  bundledCode: "#line 1 \"Verify/YUKI_901.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/901\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
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
    };\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 5 \"Verify/YUKI_901.test.cpp\"\
    \n\r\n#line 2 \"Graph/lca.hpp\"\n\r\nstruct LCA{\r\n    LCA(int _n=0):n(_n),g(_n),depth(_n+1,inf),start(_n){}\r\
    \n    void add_edge(int u,int v){\r\n        g[u].push_back(v);\r\n        g[v].push_back(u);\r\
    \n    }\r\n    void run(int root=0){\r\n        depth[root]=0;\r\n        dfs(root,-1);\r\
    \n        N=1;\r\n        while(N<int(euler.size()))N<<=1;\r\n        tree.resize(N*2,n);\r\
    \n        rep(i,0,euler.size())tree[N+i]=euler[i];\r\n        for(int i=N-1;i>0;i--)tree[i]=op(tree[i*2],tree[i*2+1]);\r\
    \n    }\r\n    int lca(int u,int v){\r\n        int a=start[u],b=start[v];\r\n\
    \        if(a>b)swap(a,b);\r\n        b++;\r\n        int res=n;\r\n        for(int\
    \ T=b-a;T>=1;T=b-a){\r\n            int x=a|((1U<<31)>>__builtin_clz(T));\r\n\
    \            int y=x&-x,k=__builtin_ctz(x);\r\n            res=op(res,tree[(N|a)>>k]);\r\
    \n            a+=y;\r\n        }\r\n        return res;\r\n    }\r\nprivate:\r\
    \n    int n,N;\r\n    vector<vector<int>> g;\r\n    vector<int> depth,start,euler,tree;\r\
    \n    void dfs(int v,int p){\r\n        start[v]=euler.size();\r\n        euler.push_back(v);\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n            depth[to]=depth[v]+1;\r\n\
    \            dfs(to,v);\r\n            euler.push_back(v);\r\n        }\r\n  \
    \  }\r\n    int op(int u,int v){\r\n        if(depth[u]<depth[v])return u;\r\n\
    \        else return v;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Lowest Common Ancestor\r\
    \n */\n#line 2 \"Graph/auxiliarytree.hpp\"\n\r\n#line 4 \"Graph/auxiliarytree.hpp\"\
    \nstruct AuxiliaryTree{\r\n    int n,pos;\r\n    LCA lca;\r\n    vector<int> in,dep;\r\
    \n    vector<vector<int>> _g,g;\r\n    AuxiliaryTree(int _n):n(_n),pos(0),lca(n),in(n),dep(n),_g(n),g(n){}\r\
    \n    void add_edge(int u,int v){\r\n        lca.add_edge(u,v);\r\n        _g[u].push_back(v);\r\
    \n        _g[v].push_back(u);\r\n    }\r\n    void run(int root=0){\r\n      \
    \  lca.run(root);\r\n        dfs(root,-1);\r\n    }\r\n    void query(vector<int>&\
    \ vs){\r\n        sort(ALL(vs),[&](int u,int v){return in[u]<in[v];});\r\n   \
    \     vs.erase(unique(ALL(vs)),vs.end());\r\n        int m=vs.size();\r\n    \
    \    stack<int> st;\r\n        st.push(vs[0]);\r\n        rep(i,0,m-1){\r\n  \
    \          int w=lca.lca(vs[i],vs[i+1]);\r\n            if(w!=vs[i]){\r\n    \
    \            int cur=st.top();\r\n                st.pop();\r\n              \
    \  while(!st.empty() and dep[w]<dep[st.top()]){\r\n                    add(st.top(),cur);\r\
    \n                    cur=st.top();\r\n                    st.pop();\r\n     \
    \           }\r\n                if(st.empty() or st.top()!=w){\r\n          \
    \          st.push(w);\r\n                    vs.push_back(w);\r\n           \
    \     }\r\n                add(w,cur);\r\n            }\r\n            st.push(vs[i+1]);\r\
    \n        }\r\n        while(st.size()>1){\r\n            int c=st.top();\r\n\
    \            st.pop();\r\n            add(st.top(),c);\r\n        }\r\n    }\r\
    \n    void clear(vector<int>& vs){\r\n        for(auto& w:vs)g[w].clear();\r\n\
    \    }\r\nprivate:\r\n    void dfs(int v,int p){\r\n        in[v]=pos++;\r\n \
    \       for(auto& to:_g[v])if(to!=p){\r\n            dep[to]=dep[v]+1;\r\n   \
    \         dfs(to,v);\r\n        }\r\n    }\r\n    void add(int u,int v){\r\n \
    \       g[u].push_back(v);\r\n        g[v].push_back(u);\r\n    }\r\n};\r\n\r\n\
    /**\r\n * @brief Auxiliary Tree(Virtual Tree)\r\n */\n#line 8 \"Verify/YUKI_901.test.cpp\"\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n;\r\n    io.read(n);\r\n    AuxiliaryTree\
    \ g(n);\r\n    LCA lca(n);\r\n    using P=pair<int,int>;\r\n    vector tree(n,vector<P>());\r\
    \n    rep(_,0,n-1){\r\n        int u,v,w;\r\n        io.read(u,v,w);\r\n     \
    \   g.add_edge(u,v);\r\n        lca.add_edge(u,v);\r\n        tree[u].push_back({v,w});\r\
    \n        tree[v].push_back({u,w});\r\n    }\r\n    g.run();\r\n    lca.run();\r\
    \n\r\n    vector<ll> dep(n);\r\n    auto dfs=[&](auto& dfs,int v,int p)->void{\r\
    \n        for(auto& [to,w]:tree[v])if(to!=p){\r\n            dep[to]=dep[v]+w;\r\
    \n            dfs(dfs,to,v);\r\n        }\r\n    };\r\n    dfs(dfs,0,-1);\r\n\
    \    auto dist=[&](int u,int v)->ll{\r\n        return dep[u]+dep[v]-2*dep[lca.lca(u,v)];\r\
    \n    };\r\n\r\n    int q;\r\n    io.read(q);\r\n    while(q--){\r\n        int\
    \ k;\r\n        io.read(k);\r\n        vector<int> vs(k);\r\n        io.read(vs);\r\
    \n        g.query(vs);\r\n        ll ret=0;\r\n        for(auto& v:vs)for(auto&\
    \ to:g.g[v])ret+=dist(v,to);\r\n        ret/=2;\r\n        io.write(ret);\r\n\
    \        g.clear(vs);\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/901\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\r\n#include\
    \ \"Graph/lca.hpp\"\r\n#include \"Graph/auxiliarytree.hpp\"\r\n\r\nFastIO io;\r\
    \nint main(){\r\n    int n;\r\n    io.read(n);\r\n    AuxiliaryTree g(n);\r\n\
    \    LCA lca(n);\r\n    using P=pair<int,int>;\r\n    vector tree(n,vector<P>());\r\
    \n    rep(_,0,n-1){\r\n        int u,v,w;\r\n        io.read(u,v,w);\r\n     \
    \   g.add_edge(u,v);\r\n        lca.add_edge(u,v);\r\n        tree[u].push_back({v,w});\r\
    \n        tree[v].push_back({u,w});\r\n    }\r\n    g.run();\r\n    lca.run();\r\
    \n\r\n    vector<ll> dep(n);\r\n    auto dfs=[&](auto& dfs,int v,int p)->void{\r\
    \n        for(auto& [to,w]:tree[v])if(to!=p){\r\n            dep[to]=dep[v]+w;\r\
    \n            dfs(dfs,to,v);\r\n        }\r\n    };\r\n    dfs(dfs,0,-1);\r\n\
    \    auto dist=[&](int u,int v)->ll{\r\n        return dep[u]+dep[v]-2*dep[lca.lca(u,v)];\r\
    \n    };\r\n\r\n    int q;\r\n    io.read(q);\r\n    while(q--){\r\n        int\
    \ k;\r\n        io.read(k);\r\n        vector<int> vs(k);\r\n        io.read(vs);\r\
    \n        g.query(vs);\r\n        ll ret=0;\r\n        for(auto& v:vs)for(auto&\
    \ to:g.g[v])ret+=dist(v,to);\r\n        ret/=2;\r\n        io.write(ret);\r\n\
    \        g.clear(vs);\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/lca.hpp
  - Graph/auxiliarytree.hpp
  isVerificationFile: true
  path: Verify/YUKI_901.test.cpp
  requiredBy: []
  timestamp: '2024-01-12 04:46:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/YUKI_901.test.cpp
layout: document
redirect_from:
- /verify/Verify/YUKI_901.test.cpp
- /verify/Verify/YUKI_901.test.cpp.html
title: Verify/YUKI_901.test.cpp
---
