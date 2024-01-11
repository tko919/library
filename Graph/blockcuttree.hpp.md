---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/bc.hpp
    title: Biconnected Components
  - icon: ':question:'
    path: Graph/lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Block Cut Tree
    links: []
  bundledCode: "#line 2 \"Graph/lowlink.hpp\"\n\r\nstruct LowLink{\r\n    const int\
    \ n; vector<vector<int>> g;\r\n    vector<int> used,ord,low,id,arti;\r\n    LowLink(const\
    \ int& _n=0):n(_n),g(n),\r\n        used(n,0),ord(n,0),low(n,0),id(n,-1){\r\n\
    \    }\r\n    void add_edge(int u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\
    \n     }\r\n    void dfs(int v,int p,int& k){\r\n        used[v]=1; low[v]=ord[v]=k++;\r\
    \n        bool isarti=0;\r\n        int cnt=0,sub=0;\r\n        for(auto& to:g[v]){\r\
    \n            if(to==p and (++sub)<=1)continue;\r\n            if(!used[to]){\r\
    \n                cnt++; dfs(to,v,k);\r\n                chmin(low[v],low[to]);\r\
    \n                isarti|=(p>=0&&low[to]>=ord[v]);\r\n            }\r\n      \
    \      else chmin(low[v],ord[to]);\r\n        }\r\n        isarti|=(p==-1&&cnt>1);\r\
    \n        if(isarti)arti.push_back(v);\r\n    }\r\n    void dfs2(int v,int p,int&\
    \ k){\r\n        if(p!=-1 and ord[p]>=low[v])id[v]=id[p];\r\n        else id[v]=k++;\r\
    \n        for(auto& to:g[v])if(id[to]==-1)dfs2(to,v,k);\r\n    }\r\n    int run(){\r\
    \n        int k=0; rep(i,0,n)if(!used[i])dfs(i,-1,k);\r\n        k=0; rep(i,0,n)if(id[i]==-1)dfs2(i,-1,k);\r\
    \n        return k;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Lowlink\r\n */\n#line\
    \ 3 \"Graph/bc.hpp\"\n\r\nstruct BiconnectedComponents{\r\n    using P=pair<int,int>;\r\
    \n    LowLink base;\r\n    vector<vector<P>> g;\r\n    vector<int> used;\r\n \
    \   int eidx;\r\n    vector<vector<int>> bc;\r\n    BiconnectedComponents(){}\r\
    \n    BiconnectedComponents(const int& n):base(n),g(n),used(n),eidx(0){}\r\n \
    \   void add_edge(int u,int v){\r\n        base.add_edge(u,v);\r\n        g[u].push_back({v,eidx});\r\
    \n        g[v].push_back({u,eidx++});\r\n    }\r\n    void run(){\r\n        base.run();\r\
    \n        rep(i,0,g.size())if(!used[i])dfs(i,-1);\r\n    }\r\nprivate:\r\n   \
    \ vector<int> buf;\r\n    void dfs(int v,int p){\r\n        used[v]=1;\r\n   \
    \     int cnt=0;\r\n        for(auto& [to,id]:g[v]){\r\n            if(to==p){\r\
    \n                cnt++;\r\n                if(cnt<=1)continue;\r\n          \
    \  }\r\n            if(!used[to] or base.ord[to]<base.ord[v]){\r\n           \
    \     buf.push_back(id);\r\n            }\r\n            if(!used[to]){\r\n  \
    \              dfs(to,v);\r\n                if(base.low[to]>=base.ord[v]){\r\n\
    \                    vector<int> add;\r\n                    for(;;){\r\n    \
    \                    add.push_back(buf.back());\r\n                        buf.pop_back();\r\
    \n                        if(add.back()==id)break;\r\n                    }\r\n\
    \                    bc.push_back(add);\r\n                }\r\n            }\r\
    \n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Biconnected Components\r\n\
    \ */\n#line 3 \"Graph/blockcuttree.hpp\"\n\nstruct BlockCutTree{\n    using P=pair<int,int>;\n\
    \    int n;\n    BiconnectedComponents bc;\n    vector<P> es;\n    \n    vector<int>\
    \ rev;\n    vector<vector<int>> tree;\n    BlockCutTree(int _n):n(_n),bc(_n),rev(_n,-1){}\n\
    \    void add_edge(int u,int v){\n        es.push_back({u,v});\n        bc.add_edge(u,v);\n\
    \    }\n    void run(){\n        bc.run();\n        int B=bc.bc.size();\n    \
    \    int ptr=B;\n        for(auto& v:bc.base.arti)rev[v]=ptr++;\n        vector<int>\
    \ last(ptr,-1);\n        tree.resize(n+ptr);\n        rep(i,0,B){\n          \
    \  for(auto& e:bc.bc[i]){\n                for(auto& v:{es[e].first,es[e].second}){\n\
    \                    if(rev[v]>=B){\n                        if(exchange(last[rev[v]],i)!=i){\n\
    \                            tree[n+rev[v]].push_back(n+i);\n                \
    \            tree[n+i].push_back(n+rev[v]);\n                        }\n     \
    \               }\n                    else rev[v]=i;\n                }\n   \
    \         }\n        }\n        rep(i,0,n){\n            tree[i].push_back(n+rev[i]);\n\
    \            tree[n+rev[i]].push_back(i);\n        }\n    }\n};\n\n/**\n * @brief\
    \ Block Cut Tree\n */\n"
  code: "#pragma once\n#include \"Graph/bc.hpp\"\n\nstruct BlockCutTree{\n    using\
    \ P=pair<int,int>;\n    int n;\n    BiconnectedComponents bc;\n    vector<P> es;\n\
    \    \n    vector<int> rev;\n    vector<vector<int>> tree;\n    BlockCutTree(int\
    \ _n):n(_n),bc(_n),rev(_n,-1){}\n    void add_edge(int u,int v){\n        es.push_back({u,v});\n\
    \        bc.add_edge(u,v);\n    }\n    void run(){\n        bc.run();\n      \
    \  int B=bc.bc.size();\n        int ptr=B;\n        for(auto& v:bc.base.arti)rev[v]=ptr++;\n\
    \        vector<int> last(ptr,-1);\n        tree.resize(n+ptr);\n        rep(i,0,B){\n\
    \            for(auto& e:bc.bc[i]){\n                for(auto& v:{es[e].first,es[e].second}){\n\
    \                    if(rev[v]>=B){\n                        if(exchange(last[rev[v]],i)!=i){\n\
    \                            tree[n+rev[v]].push_back(n+i);\n                \
    \            tree[n+i].push_back(n+rev[v]);\n                        }\n     \
    \               }\n                    else rev[v]=i;\n                }\n   \
    \         }\n        }\n        rep(i,0,n){\n            tree[i].push_back(n+rev[i]);\n\
    \            tree[n+rev[i]].push_back(i);\n        }\n    }\n};\n\n/**\n * @brief\
    \ Block Cut Tree\n */"
  dependsOn:
  - Graph/bc.hpp
  - Graph/lowlink.hpp
  isVerificationFile: false
  path: Graph/blockcuttree.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/blockcuttree.hpp
layout: document
redirect_from:
- /library/Graph/blockcuttree.hpp
- /library/Graph/blockcuttree.hpp.html
title: Block Cut Tree
---
