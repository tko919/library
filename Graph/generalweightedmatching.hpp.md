---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_general_weighted_matching.test.cpp
    title: Verify/LC_general_weighted_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: General Weighted Matching
    links:
    - http://www.cs.kent.edu/~dragan/GraphAn/p23-galil.pdf
  bundledCode: "#line 2 \"Graph/generalweightedmatching.hpp\"\n\n// reference: http://www.cs.kent.edu/~dragan/GraphAn/p23-galil.pdf\n\
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
    */\n"
  code: "#pragma once\n\n// reference: http://www.cs.kent.edu/~dragan/GraphAn/p23-galil.pdf\n\
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
    */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/generalweightedmatching.hpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_general_weighted_matching.test.cpp
documentation_of: Graph/generalweightedmatching.hpp
layout: document
redirect_from:
- /library/Graph/generalweightedmatching.hpp
- /library/Graph/generalweightedmatching.hpp.html
title: General Weighted Matching
---
