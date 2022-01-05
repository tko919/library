---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Maximum Flow
    links: []
  bundledCode: "#line 2 \"Graph/maxflow.hpp\"\n\r\nstruct MaxFlow{\r\n    struct Edge\
    \ { ll to,cap,rev; };\r\n    int V; vector<vector<Edge>> G; vector<int> itr,level;\r\
    \npublic:\r\n    MaxFlow(int V):V(V){G.assign(V,vector<Edge>()); }\r\n    void\
    \ add_edge(int from,int to,ll cap){\r\n        G[from].push_back({to,cap,(int)G[to].size()});\r\
    \n        G[to].push_back({from,0,(int)G[from].size()-1});\r\n    }\r\n    void\
    \ bfs(int s){\r\n        level.assign(V,-1); queue<int> q;\r\n        level[s]=0;\
    \ q.push(s);\r\n        while(!q.empty()){\r\n            int v=q.front(); q.pop();\r\
    \n            for(auto& e:G[v]){\r\n                if(e.cap>0&&level[e.to]<0)\
    \ {\r\n                   level[e.to]=level[v]+1;\r\n                   q.push(e.to);\r\
    \n                }\r\n            }\r\n        }\r\n    }\r\n    ll dfs(int v,int\
    \ t,ll f){\r\n        if(v==t)return f;\r\n        for(int& i=itr[v];i<(int)G[v].size();i++){\r\
    \n            Edge& e=G[v][i];\r\n            if(e.cap>0&&level[v]<level[e.to]){\r\
    \n                ll d=dfs(e.to,t,min(f,e.cap));\r\n                if(d>0){\r\
    \n                    e.cap-=d,G[e.to][e.rev].cap+=d;\r\n                    return\
    \ d;\r\n                }\r\n            }\r\n        } return 0;\r\n    }\r\n\
    \    ll run(int s,int t){\r\n        ll ret=0,f;\r\n        while(bfs(s),level[t]>=0){\r\
    \n            itr.assign(V,0);\r\n            while((f=dfs(s,t,INF))>0)ret+=f;\r\
    \n        } return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Flow\r\n\
    \ */\n"
  code: "#pragma once\r\n\r\nstruct MaxFlow{\r\n    struct Edge { ll to,cap,rev; };\r\
    \n    int V; vector<vector<Edge>> G; vector<int> itr,level;\r\npublic:\r\n   \
    \ MaxFlow(int V):V(V){G.assign(V,vector<Edge>()); }\r\n    void add_edge(int from,int\
    \ to,ll cap){\r\n        G[from].push_back({to,cap,(int)G[to].size()});\r\n  \
    \      G[to].push_back({from,0,(int)G[from].size()-1});\r\n    }\r\n    void bfs(int\
    \ s){\r\n        level.assign(V,-1); queue<int> q;\r\n        level[s]=0; q.push(s);\r\
    \n        while(!q.empty()){\r\n            int v=q.front(); q.pop();\r\n    \
    \        for(auto& e:G[v]){\r\n                if(e.cap>0&&level[e.to]<0) {\r\n\
    \                   level[e.to]=level[v]+1;\r\n                   q.push(e.to);\r\
    \n                }\r\n            }\r\n        }\r\n    }\r\n    ll dfs(int v,int\
    \ t,ll f){\r\n        if(v==t)return f;\r\n        for(int& i=itr[v];i<(int)G[v].size();i++){\r\
    \n            Edge& e=G[v][i];\r\n            if(e.cap>0&&level[v]<level[e.to]){\r\
    \n                ll d=dfs(e.to,t,min(f,e.cap));\r\n                if(d>0){\r\
    \n                    e.cap-=d,G[e.to][e.rev].cap+=d;\r\n                    return\
    \ d;\r\n                }\r\n            }\r\n        } return 0;\r\n    }\r\n\
    \    ll run(int s,int t){\r\n        ll ret=0,f;\r\n        while(bfs(s),level[t]>=0){\r\
    \n            itr.assign(V,0);\r\n            while((f=dfs(s,t,INF))>0)ret+=f;\r\
    \n        } return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Maximum Flow\r\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/maxflow.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/maxflow.hpp
layout: document
redirect_from:
- /library/Graph/maxflow.hpp
- /library/Graph/maxflow.hpp.html
title: Maximum Flow
---
