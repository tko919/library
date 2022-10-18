---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: Graph/centroid.hpp
    title: Centroid Decomposition
  - icon: ':heavy_check_mark:'
    path: Graph/hld.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Verify/LC_vertex_add_range_contour_sum_on_tree.cpp
    title: Verify/LC_vertex_add_range_contour_sum_on_tree.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Contour Sum Query
    links: []
  bundledCode: "#line 2 \"Graph/contour.hpp\"\n\r\n#line 2 \"Graph/centroid.hpp\"\n\
    \r\nclass CentroidDecomposition{\r\n    void get(int v,int p){\r\n        sz[v]=1;\r\
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
    \n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Contour Sum Query\r\n */\n"
  code: "#pragma once\r\n\r\n#include \"Graph/centroid.hpp\"\r\n#include \"DataStructure/segtree.hpp\"\
    \r\n#include \"Graph/hld.hpp\"\r\n\r\ntemplate<typename M,typename N,M (*f)(M,M),M\
    \ (*g)(M,N),M (*m1)()>struct ContourQuery{\r\n    using P=pair<int,int>;\r\n \
    \   ContourQuery(int _n):n(_n),m(_n),cd(_n),hld(_n),\r\n        seg(_n*3),tree(_n*3),depth(_n*3),\r\
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
    \n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Contour Sum Query\r\n */"
  dependsOn:
  - Graph/centroid.hpp
  - DataStructure/segtree.hpp
  - Graph/hld.hpp
  isVerificationFile: false
  path: Graph/contour.hpp
  requiredBy:
  - Verify/LC_vertex_add_range_contour_sum_on_tree.cpp
  timestamp: '2022-10-16 23:53:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/contour.hpp
layout: document
redirect_from:
- /library/Graph/contour.hpp
- /library/Graph/contour.hpp.html
title: Contour Sum Query
---
