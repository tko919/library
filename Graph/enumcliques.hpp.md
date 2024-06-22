---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_enumerate_cliques.test.cpp
    title: Verify/LC_enumerate_cliques.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Enumerate Cliques
    links: []
  bundledCode: "#line 2 \"Graph/enumcliques.hpp\"\n\r\nstruct EnumCliques{\r\n   \
    \ const int n;\r\n    int m;\r\n    vector<vector<int>> g;\r\n    vector<int>\
    \ deg;\r\n    EnumCliques(int _n):n(_n),m(0),g(n,vector<int>(n)),deg(n){}\r\n\
    \    void add_edge(int u,int v){\r\n        g[u][v]=g[v][u]=1;\r\n        deg[u]++;\
    \ deg[v]++;\r\n        m++;\r\n    }\r\n    vector<vector<int>> run(){\r\n   \
    \     int L=sqrt(m);\r\n        vector<vector<int>> res;\r\n        auto process=[&](vector<int>&\
    \ vs,bool fix=true)->void{\r\n            vector<int> nbhd(vs.size());\r\n   \
    \         rep(i,0,vs.size())rep(j,0,vs.size())if(i!=j){\r\n                nbhd[i]|=(!g[vs[i]][vs[j]])<<j;\r\
    \n            }\r\n            rep(mask,1,1<<vs.size()){\r\n                if(fix\
    \ and (mask&1)==0)continue;;\r\n                bool check=1;\r\n            \
    \    rep(i,0,vs.size())if(mask>>i&1){\r\n                    if(mask&nbhd[i]){\r\
    \n                        check=0;\r\n                        break;\r\n     \
    \               }\r\n                }\r\n                if(check){\r\n     \
    \               vector<int> add;\r\n                    rep(i,0,vs.size())if(mask>>i&1){\r\
    \n                        add.push_back(vs[i]);\r\n                    }\r\n \
    \                   res.push_back(add);\r\n                }\r\n            }\r\
    \n        };\r\n\r\n        vector<int> used(n);\r\n        queue<int> que;\r\n\
    \        rep(v,0,n)if(deg[v]<L){\r\n            que.push(v);\r\n            used[v]=1;\r\
    \n        }\r\n        while(!que.empty()){\r\n            int v=que.front();\r\
    \n            que.pop();\r\n            vector<int> vs;\r\n            vs.push_back(v);\r\
    \n            rep(u,0,n)if(g[v][u])vs.push_back(u);\r\n            process(vs);\r\
    \n            rep(u,0,n)if(g[v][u]){\r\n                g[v][u]=g[u][v]=0;\r\n\
    \                deg[u]--;\r\n                if(!used[u] and deg[u]<L){\r\n \
    \                   que.push(u);\r\n                    used[u]=1;\r\n       \
    \         }\r\n            }\r\n        }\r\n        vector<int> vs;\r\n     \
    \   rep(v,0,n)if(!used[v])vs.push_back(v);\r\n        process(vs,false);\r\n \
    \       return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Enumerate Cliques\r\
    \n */\n"
  code: "#pragma once\r\n\r\nstruct EnumCliques{\r\n    const int n;\r\n    int m;\r\
    \n    vector<vector<int>> g;\r\n    vector<int> deg;\r\n    EnumCliques(int _n):n(_n),m(0),g(n,vector<int>(n)),deg(n){}\r\
    \n    void add_edge(int u,int v){\r\n        g[u][v]=g[v][u]=1;\r\n        deg[u]++;\
    \ deg[v]++;\r\n        m++;\r\n    }\r\n    vector<vector<int>> run(){\r\n   \
    \     int L=sqrt(m);\r\n        vector<vector<int>> res;\r\n        auto process=[&](vector<int>&\
    \ vs,bool fix=true)->void{\r\n            vector<int> nbhd(vs.size());\r\n   \
    \         rep(i,0,vs.size())rep(j,0,vs.size())if(i!=j){\r\n                nbhd[i]|=(!g[vs[i]][vs[j]])<<j;\r\
    \n            }\r\n            rep(mask,1,1<<vs.size()){\r\n                if(fix\
    \ and (mask&1)==0)continue;;\r\n                bool check=1;\r\n            \
    \    rep(i,0,vs.size())if(mask>>i&1){\r\n                    if(mask&nbhd[i]){\r\
    \n                        check=0;\r\n                        break;\r\n     \
    \               }\r\n                }\r\n                if(check){\r\n     \
    \               vector<int> add;\r\n                    rep(i,0,vs.size())if(mask>>i&1){\r\
    \n                        add.push_back(vs[i]);\r\n                    }\r\n \
    \                   res.push_back(add);\r\n                }\r\n            }\r\
    \n        };\r\n\r\n        vector<int> used(n);\r\n        queue<int> que;\r\n\
    \        rep(v,0,n)if(deg[v]<L){\r\n            que.push(v);\r\n            used[v]=1;\r\
    \n        }\r\n        while(!que.empty()){\r\n            int v=que.front();\r\
    \n            que.pop();\r\n            vector<int> vs;\r\n            vs.push_back(v);\r\
    \n            rep(u,0,n)if(g[v][u])vs.push_back(u);\r\n            process(vs);\r\
    \n            rep(u,0,n)if(g[v][u]){\r\n                g[v][u]=g[u][v]=0;\r\n\
    \                deg[u]--;\r\n                if(!used[u] and deg[u]<L){\r\n \
    \                   que.push(u);\r\n                    used[u]=1;\r\n       \
    \         }\r\n            }\r\n        }\r\n        vector<int> vs;\r\n     \
    \   rep(v,0,n)if(!used[v])vs.push_back(v);\r\n        process(vs,false);\r\n \
    \       return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Enumerate Cliques\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/enumcliques.hpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_enumerate_cliques.test.cpp
documentation_of: Graph/enumcliques.hpp
layout: document
redirect_from:
- /library/Graph/enumcliques.hpp
- /library/Graph/enumcliques.hpp.html
title: Enumerate Cliques
---
