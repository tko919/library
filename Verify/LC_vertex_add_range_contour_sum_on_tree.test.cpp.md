---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  - icon: ':question:'
    path: Graph/centroid.hpp
    title: Centroid Decomposition
  - icon: ':x:'
    path: Graph/contour.hpp
    title: Contour Sum Query
  - icon: ':question:'
    path: Graph/hld.hpp
    title: Heavy Light Decomposition
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
    links:
    - https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
  bundledCode: "#line 1 \"Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\n\r\nclass FastIO{\r\n    static constexpr int L=1<<16;\r\
    \n    char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\
    \n        int len=rdRight-rdLeft;\r\n        memmove(rdbuf,rdbuf+rdLeft,len);\r\
    \n        rdLeft=0,rdRight=len;\r\n        rdRight+=fread(rdbuf+len,1,L-len,stdin);\r\
    \n    }\r\n    inline bool skip(){\r\n        for(;;){\r\n            while(rdLeft!=rdRight\
    \ and rdbuf[rdLeft]<=' ')rdLeft++;\r\n            if(rdLeft==rdRight){\r\n   \
    \             reload();\r\n                if(rdLeft==rdRight)return false;\r\n\
    \            }\r\n            else break;\r\n        }\r\n        return true;\r\
    \n    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdLeft<rdRight){\r\n            x=x*10+(neg?-(rdbuf[rdLeft++]^48):(rdbuf[rdLeft++]^48));\r\
    \n        }\r\n        return true;\r\n    }\r\n    template<typename T,enable_if_t<is_floating_point<T>::value,int>\
    \ =0>inline bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9' and rdLeft<rdRight){\r\n            x=x*10+(rdbuf[rdLeft++]^48);\r\
    \n        }\r\n        if(rdbuf[rdLeft]!='.')return true;\r\n        rdLeft++;\r\
    \n        T base=.1;\r\n        while(rdbuf[rdLeft]>='0' and rdbuf[rdLeft]<='9'\
    \ and rdLeft<rdRight){\r\n            x+=base*(rdbuf[rdLeft++]^48);\r\n      \
    \      base*=.1;\r\n        }\r\n        if(neg)x=-x;\r\n        return true;\r\
    \n    }\r\n    inline bool _read(char& x){\r\n        if(!skip())return false;\r\
    \n        if(rdLeft+1>=rdRight)reload();\r\n        x=rdbuf[rdLeft++];\r\n   \
    \     return true;\r\n    }\r\n    inline bool _read(string& x){\r\n        if(!skip())return\
    \ false;\r\n        for(;;){\r\n            int pos=rdLeft;\r\n            while(pos<rdRight\
    \ and rdbuf[pos]>' ')pos++;\r\n            x.append(rdbuf+rdLeft,pos-rdLeft);\r\
    \n            if(rdLeft==pos)break;\r\n            rdLeft=pos;\r\n           \
    \ if(rdLeft==rdRight)reload();\r\n            else break;\r\n        }\r\n   \
    \     return true;\r\n    }\r\n    template<typename T>inline bool _read(vector<T>&\
    \ v){\r\n        for(auto& x:v){\r\n            if(!_read(x))return false;\r\n\
    \        }\r\n        return true;\r\n    }\r\n\r\n    char wtbuf[L],tmp[50];\r\
    \n    int wtRight=0;\r\n    inline void flush(){\r\n        fwrite(wtbuf,1,wtRight,stdout);\r\
    \n        wtRight=0;\r\n    }\r\n    inline void _write(const char& x){\r\n  \
    \      if(wtRight>L-32)flush();\r\n        wtbuf[wtRight++]=x;\r\n    }\r\n  \
    \  inline void _write(const string& x){\r\n        for(auto& c:x)_write(c);\r\n\
    \    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ void _write(T x){\r\n        if(wtRight>L-32)flush();\r\n        if(x==0){\r\
    \n            _write('0');\r\n            return;\r\n        }\r\n        else\
    \ if(x<0){\r\n            _write('-');\r\n            if (__builtin_expect(x ==\
    \ std::numeric_limits<T>::min(), 0)) {\r\n                switch (sizeof(x)) {\r\
    \n                case 2: _write(\"32768\"); return;\r\n                case 4:\
    \ _write(\"2147483648\"); return;\r\n                case 8: _write(\"9223372036854775808\"\
    ); return;\r\n                }\r\n            }\r\n            x=-x;\r\n    \
    \    }\r\n        int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
    \n            x/=10;\r\n        }\r\n        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];\r\
    \n        wtRight+=pos;\r\n    }\r\n    template<typename T>inline void _write(const\
    \ vector<T>& v){\r\n        rep(i,0,v.size()){\r\n            if(i)_write(' ');\r\
    \n            _write(v[i]);\r\n        }\r\n    }\r\npublic:\r\n    FastIO(){}\r\
    \n    ~FastIO(){flush();}\r\n    inline void read(){}\r\n    template <typename\
    \ Head, typename... Tail>inline void read(Head& head,Tail&... tail){\r\n     \
    \   assert(_read(head));\r\n        read(tail...); \r\n    }\r\n    template<bool\
    \ ln=true,bool space=false>inline void write(){if(ln)_write('\\n');}\r\n    template\
    \ <bool ln=true,bool space=false,typename Head, typename... Tail>inline void write(const\
    \ Head& head,const Tail&... tail){\r\n        if(space)_write(' ');\r\n      \
    \  _write(head);\r\n        write<ln,true>(tail...); \r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp\"\
    \n\r\n#line 2 \"Graph/centroid.hpp\"\n\r\nclass CentroidDecomposition{\r\n   \
    \ void get(int v,int p){\r\n        sz[v]=1;\r\n        for(auto& to:g[v])if(to!=p\
    \ and !used[to]){\r\n            get(to,v);\r\n            sz[v]+=sz[to];\r\n\
    \        }\r\n    }\r\n    int dfs(int v,int p,int rt){\r\n        for(auto& to:g[v])if(to!=p\
    \ and !used[to]){\r\n            if(sz[to]>(sz[rt]>>1))return dfs(to,v,rt);\r\n\
    \        }\r\n        return v;\r\n    }\r\npublic:\r\n    int n;\r\n    vector<vector<int>>\
    \ g;\r\n    vector<int> sz,used;\r\n    CentroidDecomposition(int n_):n(n_),g(n),sz(n),used(n){}\r\
    \n    void add_edge(int u,int v){\r\n        g[u].push_back(v);\r\n        g[v].push_back(u);\r\
    \n    }\r\n    int find(int rt){\r\n        get(rt,-1);\r\n        int res=dfs(rt,-1,rt);\r\
    \n        used[res]=1;\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n *\
    \ @brief Centroid Decomposition\r\n */\n#line 2 \"Graph/hld.hpp\"\n\r\nstruct\
    \ HLD{\r\n    using P=pair<int,int>;\r\n    vector<vector<int>> g; vector<int>\
    \ sz,in,out,rev,hs,par,dist;\r\n    void dfs(int v,int p){\r\n        par[v]=p;\
    \ sz[v]=1;\r\n        if(p!=-1)dist[v]=dist[p]+1;\r\n        if(!g[v].empty()\
    \ and g[v][0]==p)swap(g[v][0],g[v].back());\r\n        for(auto& to:g[v])if(to!=p){\r\
    \n           dfs(to,v); sz[v]+=sz[to];\r\n           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\
    \n        }\r\n    }\r\n    void dfs2(int v,int p,int& k){\r\n        in[v]=k++;\
    \ rev[in[v]]=v;\r\n        for(auto& to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\
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
    \ 4 \"Graph/contour.hpp\"\n\r\nstruct ContourQuery{\r\n    using P=pair<int,int>;\r\
    \n    using T=pair<int,P>;\r\n    ContourQuery(int _n=0):n(_n),m(_n),cd(_n),\r\
    \n        hld(_n),tree(_n*3),depth(_n*3),\r\n        base(_n*3),parent(_n*3,-1),SZ(_n*3),width(_n*3,1),seg(_n*3){}\r\
    \n    void add_edge(int u,int v){\r\n        cd.add_edge(u,v);\r\n        hld.add_edge(u,v);\r\
    \n    }\r\n    vector<int> run(){\r\n        hld.run();\r\n        root=rec(0);\r\
    \n        depth[0]=0;\r\n        dfs(0,-1);\r\n        rep(v,0,m)if(v!=root){\r\
    \n            seg[v]=width[v];\r\n        }\r\n        return seg;\r\n    }\r\n\
    \    vector<P> point(int v){\r\n        vector<P> ret;\r\n        int cur=v;\r\
    \n        while(cur!=root){\r\n            int D=depth[v]+depth[base[cur]]-2*depth[hld.lca(v,base[cur])];\r\
    \n            ret.push_back({cur,D});\r\n            cur=parent[cur];\r\n    \
    \    }\r\n        return ret;\r\n    }\r\n    vector<T> range(int v,int L,int\
    \ R){\r\n        vector<T> ret;\r\n        if(L<=0 and 0<R)ret.push_back({v,{0,1}});\r\
    \n        int cur=parent[v],pre=v;\r\n        while(pre!=root){\r\n          \
    \  int bro=-1;\r\n            for(auto& to:tree[cur])if(to!=parent[cur] and to!=pre){\r\
    \n                bro=to;\r\n                break;\r\n            }\r\n     \
    \       if(bro!=-1){\r\n                int D=depth[v]+depth[base[bro]]-2*depth[hld.lca(v,base[bro])];\r\
    \n                ret.push_back({bro,{clamp(L-D,0,seg[bro]),clamp(R-D,0,seg[bro])}});\r\
    \n            }\r\n            pre=cur;\r\n            cur=parent[cur];\r\n  \
    \      }\r\n        return ret;\r\n    }\r\nprivate:\r\n    int n,m,root;\r\n\
    \    CentroidDecomposition cd;\r\n    HLD hld;\r\n    vector<vector<int>> tree;\r\
    \n    vector<int> depth,base,parent,SZ,width,seg;\r\n    int rec(int rt){\r\n\
    \        int cen=cd.find(rt);\r\n        SZ[cen]=1;\r\n        queue<P> que;\r\
    \n        auto cmp=[&](int u,int v){return SZ[u]>SZ[v];};\r\n        priority_queue<int,vector<int>,decltype(cmp)>\
    \ pq{cmp};\r\n        pq.push(cen);\r\n        depth[cen]=0;\r\n        base[cen]=cen;\r\
    \n        for(auto& to:cd.g[cen])if(!cd.used[to]){\r\n            int v=rec(to);\r\
    \n            que.push({to,cen});\r\n            depth[to]=1;\r\n            while(!que.empty()){\r\
    \n                auto [cur,par]=que.front();\r\n                que.pop();\r\n\
    \                width[v]=depth[cur]+1;\r\n                for(auto& nxt:cd.g[cur])if(nxt!=par\
    \ and !cd.used[nxt]){\r\n                    depth[nxt]=depth[cur]+1;\r\n    \
    \                que.push({nxt,cur});\r\n                }\r\n            }\r\n\
    \            pq.push(v);\r\n            base[v]=cen;\r\n        }\r\n        cd.used[cen]=0;\r\
    \n        if(pq.size()>1){\r\n            for(;;){\r\n                int v1=pq.top();\r\
    \n                pq.pop();\r\n                int v2=pq.top();\r\n          \
    \      pq.pop();\r\n                int extra=m++;\r\n                tree[extra].push_back(v1);\r\
    \n                tree[extra].push_back(v2);\r\n                tree[v1].push_back(extra);\r\
    \n                tree[v2].push_back(extra);\r\n                SZ[extra]=SZ[v1]+SZ[v2];\r\
    \n                parent[v1]=parent[v2]=extra;\r\n                if(pq.empty()){\r\
    \n                    return extra;\r\n                }\r\n                pq.push(extra);\r\
    \n                base[extra]=cen;\r\n                width[extra]=max(width[v1],width[v2]);\r\
    \n            }\r\n        }\r\n        else{\r\n            int extra=m++;\r\n\
    \            tree[extra].push_back(cen);\r\n            tree[cen].push_back(extra);\r\
    \n            SZ[extra]=1;\r\n            parent[cen]=extra;\r\n            return\
    \ extra;\r\n        }\r\n    }\r\n    void dfs(int v,int p){\r\n        for(auto&\
    \ to:cd.g[v])if(to!=p){\r\n            depth[to]=depth[v]+1;\r\n            dfs(to,v);\r\
    \n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Contour Sum Query\r\n */\n\
    #line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct BIT{\r\n   \
    \ int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\n \
    \   void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\n\
    \        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\n        all+=x;\r\n    }\r\
    \n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 8 \"Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp\"\
    \n\r\n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\n    io.read(n,q);\r\n \
    \   vector<ll> a(n);\r\n    io.read(a);\r\n    ContourQuery buf(n);\r\n    rep(_,0,n-1){\r\
    \n        int u,v;\r\n        io.read(u,v);\r\n        buf.add_edge(u,v);\r\n\
    \    }\r\n    auto len=buf.run();\r\n    vector<BIT<ll>> seg(len.size());\r\n\
    \    rep(i,0,len.size())seg[i]=BIT<ll>(len[i]);\r\n    rep(v,0,n){\r\n       \
    \ for(auto& [i,p]:buf.point(v))seg[i].add(p,a[v]);\r\n    }\r\n\r\n    while(q--){\r\
    \n        int t;\r\n        io.read(t);\r\n        if(t==0){\r\n            int\
    \ v,x;\r\n            io.read(v,x);\r\n            for(auto& [i,p]:buf.point(v))seg[i].add(p,x);\r\
    \n        }\r\n        else{\r\n            int v,L,R;\r\n            io.read(v,L,R);\r\
    \n            ll ret=0;\r\n            for(auto& [i,LR]:buf.range(v,L,R)){\r\n\
    \                auto [lb,rb]=LR;\r\n                ret+=seg[i].sum(lb,rb);\r\
    \n            }\r\n            io.write(ret);\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n\r\n#include \"Graph/contour.hpp\"\r\n#include \"DataStructure/bit.hpp\"\r\n\
    \r\n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\n    io.read(n,q);\r\n   \
    \ vector<ll> a(n);\r\n    io.read(a);\r\n    ContourQuery buf(n);\r\n    rep(_,0,n-1){\r\
    \n        int u,v;\r\n        io.read(u,v);\r\n        buf.add_edge(u,v);\r\n\
    \    }\r\n    auto len=buf.run();\r\n    vector<BIT<ll>> seg(len.size());\r\n\
    \    rep(i,0,len.size())seg[i]=BIT<ll>(len[i]);\r\n    rep(v,0,n){\r\n       \
    \ for(auto& [i,p]:buf.point(v))seg[i].add(p,a[v]);\r\n    }\r\n\r\n    while(q--){\r\
    \n        int t;\r\n        io.read(t);\r\n        if(t==0){\r\n            int\
    \ v,x;\r\n            io.read(v,x);\r\n            for(auto& [i,p]:buf.point(v))seg[i].add(p,x);\r\
    \n        }\r\n        else{\r\n            int v,L,R;\r\n            io.read(v,L,R);\r\
    \n            ll ret=0;\r\n            for(auto& [i,LR]:buf.range(v,L,R)){\r\n\
    \                auto [lb,rb]=LR;\r\n                ret+=seg[i].sum(lb,rb);\r\
    \n            }\r\n            io.write(ret);\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}"
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
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
- /verify/Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp.html
title: Verify/LC_vertex_add_range_contour_sum_on_tree.test.cpp
---
