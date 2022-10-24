---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Steiner Tree
    links: []
  bundledCode: "#line 2 \"Graph/steiner.hpp\"\n\r\nstruct SteinerTree{\r\n    using\
    \ P=pair<ll,ll>;\r\n    int n;\r\n    vector<vector<P>> g;\r\n    SteinerTree(int\
    \ _n):n(_n),g(n){}\r\n    void add_edge(int u,int v,ll c){\r\n        g[u].push_back({v,c});\r\
    \n        g[v].push_back({u,c});\r\n    }\r\n    ll run(vector<int>& term){\r\n\
    \        int k=term.size();\r\n        if(k<=1)return 0;\r\n        vector dp(1<<k,vector<ll>(n,INF));\r\
    \n        rep(i,0,k)dp[1<<i][term[i]]=0;\r\n        using P=pair<ll,int>;\r\n\
    \        rep(mask,1,1<<k){\r\n            for(ll sub=mask;;sub=(sub-1)&mask){\r\
    \n                rep(v,0,n)chmin(dp[mask][v],dp[sub][v]+dp[mask^sub][v]);\r\n\
    \                if(sub==0)break;\r\n            }\r\n            priority_queue<P,vector<P>,greater<P>>\
    \ pq;\r\n            rep(v,0,n)pq.push({dp[mask][v],v});\r\n            while(!pq.empty()){\r\
    \n                auto [d,v]=pq.top();\r\n                pq.pop();\r\n      \
    \          if(dp[mask][v]<d)continue;\r\n                for(auto& [nxt,c]:g[v])if(chmin(dp[mask][nxt],d+c)){\r\
    \n                    pq.push({dp[mask][nxt],nxt});\r\n                }\r\n \
    \           }\r\n        }\r\n        ll ret=INF;\r\n        rep(j,0,n)chmin(ret,dp[(1<<k)-1][j]);\r\
    \n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Steiner Tree\r\n\
    \ */\n"
  code: "#pragma once\r\n\r\nstruct SteinerTree{\r\n    using P=pair<ll,ll>;\r\n \
    \   int n;\r\n    vector<vector<P>> g;\r\n    SteinerTree(int _n):n(_n),g(n){}\r\
    \n    void add_edge(int u,int v,ll c){\r\n        g[u].push_back({v,c});\r\n \
    \       g[v].push_back({u,c});\r\n    }\r\n    ll run(vector<int>& term){\r\n\
    \        int k=term.size();\r\n        if(k<=1)return 0;\r\n        vector dp(1<<k,vector<ll>(n,INF));\r\
    \n        rep(i,0,k)dp[1<<i][term[i]]=0;\r\n        using P=pair<ll,int>;\r\n\
    \        rep(mask,1,1<<k){\r\n            for(ll sub=mask;;sub=(sub-1)&mask){\r\
    \n                rep(v,0,n)chmin(dp[mask][v],dp[sub][v]+dp[mask^sub][v]);\r\n\
    \                if(sub==0)break;\r\n            }\r\n            priority_queue<P,vector<P>,greater<P>>\
    \ pq;\r\n            rep(v,0,n)pq.push({dp[mask][v],v});\r\n            while(!pq.empty()){\r\
    \n                auto [d,v]=pq.top();\r\n                pq.pop();\r\n      \
    \          if(dp[mask][v]<d)continue;\r\n                for(auto& [nxt,c]:g[v])if(chmin(dp[mask][nxt],d+c)){\r\
    \n                    pq.push({dp[mask][nxt],nxt});\r\n                }\r\n \
    \           }\r\n        }\r\n        ll ret=INF;\r\n        rep(j,0,n)chmin(ret,dp[(1<<k)-1][j]);\r\
    \n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Steiner Tree\r\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/steiner.hpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/steiner.hpp
layout: document
redirect_from:
- /library/Graph/steiner.hpp
- /library/Graph/steiner.hpp.html
title: Steiner Tree
---
