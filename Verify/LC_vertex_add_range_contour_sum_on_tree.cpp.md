---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Graph/centroid.hpp
    title: Centroid Decomposition
  - icon: ':warning:'
    path: Graph/contour.hpp
    title: Contour Sum Query
  - icon: ':heavy_check_mark:'
    path: Graph/hld.hpp
    title: Heavy Light Decomposition
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
    - https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree
  bundledCode: "#line 1 \"Verify/LC_vertex_add_range_contour_sum_on_tree.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Utility/fastio.hpp\"\n#include\
    \ <unistd.h>\r\n\r\nclass FastIO{\r\n    static constexpr int L=1<<16;\r\n   \
    \ char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_vertex_add_range_contour_sum_on_tree.cpp\"\
    \n\r\n#line 2 \"Graph/contour.hpp\"\n\r\n#line 2 \"Graph/centroid.hpp\"\n\r\n\
    class CentroidDecomposition{\r\n    void get(int v,int p){\r\n        sz[v]=1;\r\
    \n        for(auto& to:g[v])if(to!=p and !used[to]){\r\n            get(to,v);\r\
    \n            sz[v]+=sz[to];\r\n        }\r\n    }\r\n    int dfs(int v,int p,int\
    \ rt){\r\n        for(auto& to:g[v])if(to!=p and !used[to]){\r\n            if(sz[to]>(sz[rt]>>1))return\
    \ dfs(to,v,rt);\r\n        }\r\n        return v;\r\n    }\r\npublic:\r\n    int\
    \ n;\r\n    vector<vector<int>> g;\r\n    vector<int> sz,used;\r\n    CentroidDecomposition(int\
    \ n_):n(n_),g(n),sz(n),used(n){}\r\n    void add_edge(int u,int v){\r\n      \
    \  g[u].push_back(v);\r\n        g[v].push_back(u);\r\n    }\r\n    int find(int\
    \ rt){\r\n        get(rt,-1);\r\n        int res=dfs(rt,-1,rt);\r\n        used[res]=1;\r\
    \n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Centroid Decomposition\r\
    \n */\n#line 2 \"DataStructure/segtree.hpp\"\n\r\ntemplate<typename M,typename\
    \ N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree{\r\n    int n; vector<M>\
    \ data;\r\n    SegmentTree(int _n=0){\r\n        n=1; while(n<_n)n<<=1; data.assign(2*n,m1());\r\
    \n    }\r\n    void run(vector<M>& v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\r\
    \n        for(int k=n-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int k,const M &x){\r\n        k+=n; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=n; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=n,b+=n;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n        }\r\n        return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n#line 2 \"Graph/hld.hpp\"\
    \n\r\nstruct HLD{\r\n    using P=pair<int,int>;\r\n    vector<vector<int>> g;\
    \ vector<int> sz,in,out,rev,hs,par,dist;\r\n    void dfs(int v,int p){\r\n   \
    \     par[v]=p; sz[v]=1; dist[v]=dist[p]+1;\r\n        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());\r\
    \n        for(auto& to:g[v])if(to!=p){\r\n           dfs(to,v); sz[v]+=sz[to];\r\
    \n           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);\r\n        }\r\n    }\r\n\
    \    void dfs2(int v,int p,int& k){\r\n        in[v]=k++; rev[in[v]]=v;\r\n  \
    \      for(auto& to:g[v])if(to!=p){\r\n            hs[to]=(g[v][0]==to?hs[v]:to);\r\
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
    \ 6 \"Graph/contour.hpp\"\n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M\
    \ (*m1)()>struct ContourQuery{\r\n    using P=pair<int,int>;\r\n    ContourQuery(int\
    \ _n):n(_n),m(_n),cd(_n),hld(_n),\r\n        seg(_n*3),tree(_n*3),depth(_n*3),\r\
    \n        base(_n*3),parent(_n*3,-1),SZ(_n*3),width(_n*3,1){}\r\n    void add_edge(int\
    \ u,int v){\r\n        cd.add_edge(u,v);\r\n        hld.add_edge(u,v);\r\n   \
    \ }\r\n    void run(){\r\n        hld.run();\r\n        root=rec(0);\r\n     \
    \   depth[0]=0;\r\n        dfs(0,-1);\r\n        rep(v,0,m)if(v!=root){\r\n  \
    \          seg[v]=SegmentTree<M,N,f,g,m1>(width[v]);\r\n        }\r\n    }\r\n\
    \    void update(int v,N x){\r\n        int cur=v;\r\n        while(cur!=root){\r\
    \n            int D=depth[v]+depth[base[cur]]-2*depth[hld.lca(v,base[cur])];\r\
    \n            seg[cur].update(D,x);\r\n            cur=parent[cur];\r\n      \
    \  }\r\n    }\r\n    M query(int v,int L,int R){\r\n        M res=m1();\r\n  \
    \      if(L<=0 and 0<R)res=seg[v].query(0,1);\r\n        int cur=parent[v],pre=v;\r\
    \n        while(pre!=root){\r\n            int bro=-1;\r\n            for(auto&\
    \ to:tree[cur])if(to!=parent[cur] and to!=pre){\r\n                bro=to;\r\n\
    \                break;\r\n            }\r\n            if(bro!=-1){\r\n     \
    \           int D=depth[v]+depth[base[bro]]-2*depth[hld.lca(v,base[bro])];\r\n\
    \                res=f(res,seg[bro].query(clamp(L-D,0,seg[bro].n),clamp(R-D,0,seg[bro].n)));\r\
    \n            }\r\n            pre=cur;\r\n            cur=parent[cur];\r\n  \
    \      }\r\n        return res;\r\n    }\r\nprivate:\r\n    int n,m,root;\r\n\
    \    CentroidDecomposition cd;\r\n    HLD hld;\r\n    vector<SegmentTree<M,N,f,g,m1>>\
    \ seg;\r\n    vector<vector<int>> tree;\r\n    vector<int> depth,base,parent,SZ,width;\r\
    \n    int rec(int rt){\r\n        int cen=cd.find(rt);\r\n        SZ[cen]=1;\r\
    \n        queue<P> que;\r\n        auto cmp=[&](int u,int v){return SZ[u]>SZ[v];};\r\
    \n        priority_queue<int,vector<int>,decltype(cmp)> pq{cmp};\r\n        pq.push(cen);\r\
    \n        depth[cen]=0;\r\n        base[cen]=cen;\r\n        for(auto& to:cd.g[cen])if(!cd.used[to]){\r\
    \n            int v=rec(to);\r\n            que.push({to,cen});\r\n          \
    \  depth[to]=1;\r\n            while(!que.empty()){\r\n                auto [cur,par]=que.front();\r\
    \n                que.pop();\r\n                width[v]=depth[cur]+1;\r\n   \
    \             for(auto& nxt:cd.g[cur])if(nxt!=par and !cd.used[nxt]){\r\n    \
    \                depth[nxt]=depth[cur]+1;\r\n                    que.push({nxt,cur});\r\
    \n                }\r\n            }\r\n            pq.push(v);\r\n          \
    \  base[v]=cen;\r\n        }\r\n        cd.used[cen]=0;\r\n        if(pq.size()>1){\r\
    \n            for(;;){\r\n                int v1=pq.top();\r\n               \
    \ pq.pop();\r\n                int v2=pq.top();\r\n                pq.pop();\r\
    \n                int extra=m++;\r\n                tree[extra].push_back(v1);\r\
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
    #line 7 \"Verify/LC_vertex_add_range_contour_sum_on_tree.cpp\"\n\r\nll f(ll a,ll\
    \ b){return a+b;}\r\nll g(ll a,ll b){return a+b;}\r\nll m1(){return 0;}\r\n\r\n\
    FastIO io;\r\nint main(){\r\n    int n,q;\r\n    io.read(n,q);\r\n    vector<ll>\
    \ a(n);\r\n    io.read(a);\r\n    ContourQuery<ll,ll,f,g,m1> buf(n);\r\n    rep(_,0,n-1){\r\
    \n        int u,v;\r\n        io.read(u,v);\r\n        buf.add_edge(u,v);\r\n\
    \    }\r\n    buf.run();\r\n    rep(i,0,n)buf.update(i,a[i]);\r\n    while(q--){\r\
    \n        int t;\r\n        io.read(t);\r\n        if(t==0){\r\n            int\
    \ v,x;\r\n            io.read(v,x);\r\n            buf.update(v,x);\r\n      \
    \  }\r\n        else{\r\n            int v,L,R;\r\n            io.read(v,L,R);\r\
    \n            io.write(buf.query(v,L,R));\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n\r\n#include \"Graph/contour.hpp\"\r\n\r\nll f(ll a,ll b){return a+b;}\r\nll\
    \ g(ll a,ll b){return a+b;}\r\nll m1(){return 0;}\r\n\r\nFastIO io;\r\nint main(){\r\
    \n    int n,q;\r\n    io.read(n,q);\r\n    vector<ll> a(n);\r\n    io.read(a);\r\
    \n    ContourQuery<ll,ll,f,g,m1> buf(n);\r\n    rep(_,0,n-1){\r\n        int u,v;\r\
    \n        io.read(u,v);\r\n        buf.add_edge(u,v);\r\n    }\r\n    buf.run();\r\
    \n    rep(i,0,n)buf.update(i,a[i]);\r\n    while(q--){\r\n        int t;\r\n \
    \       io.read(t);\r\n        if(t==0){\r\n            int v,x;\r\n         \
    \   io.read(v,x);\r\n            buf.update(v,x);\r\n        }\r\n        else{\r\
    \n            int v,L,R;\r\n            io.read(v,L,R);\r\n            io.write(buf.query(v,L,R));\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/contour.hpp
  - Graph/centroid.hpp
  - DataStructure/segtree.hpp
  - Graph/hld.hpp
  isVerificationFile: false
  path: Verify/LC_vertex_add_range_contour_sum_on_tree.cpp
  requiredBy: []
  timestamp: '2022-10-18 18:02:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Verify/LC_vertex_add_range_contour_sum_on_tree.cpp
layout: document
redirect_from:
- /library/Verify/LC_vertex_add_range_contour_sum_on_tree.cpp
- /library/Verify/LC_vertex_add_range_contour_sum_on_tree.cpp.html
title: Verify/LC_vertex_add_range_contour_sum_on_tree.cpp
---
