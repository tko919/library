---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/lowlink.hpp
    title: Lowlink
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"Verify/LC_two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\r\n\
    \r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Graph/lowlink.hpp\"\
    \n\r\nstruct LowLink{\r\n    const int n; vector<vector<int>> g;\r\n    vector<int>\
    \ used,ord,low,id;\r\n    LowLink(const int& _n=0):n(_n),g(n),\r\n        used(n,0),ord(n,0),low(n,0),id(n,-1){\r\
    \n    }\r\n    void add_edge(int u,int v){\r\n        g[u].emplace_back(v); g[v].emplace_back(u);\r\
    \n     }\r\n    void dfs(int v,int p,int& k){\r\n        used[v]=1; low[v]=ord[v]=k++;\r\
    \n        int cnt=0,sub=0;\r\n        for(auto& to:g[v]){\r\n            if(to==p\
    \ and (++sub)<=1)continue;\r\n            if(!used[to]){\r\n                cnt++;\
    \ dfs(to,v,k);\r\n                chmin(low[v],low[to]);\r\n            }\r\n\
    \            else chmin(low[v],ord[to]);\r\n        }\r\n    }\r\n    void dfs2(int\
    \ v,int p,int& k){\r\n        if(p!=-1 and ord[p]>=low[v])id[v]=id[p];\r\n   \
    \     else id[v]=k++;\r\n        for(auto& to:g[v])if(id[to]==-1)dfs2(to,v,k);\r\
    \n    }\r\n    int run(){\r\n        int k=0; rep(i,0,n)if(!used[i])dfs(i,-1,k);\r\
    \n        k=0; rep(i,0,n)if(id[i]==-1)dfs2(i,-1,k);\r\n        return k;\r\n \
    \   }\r\n};\r\n\r\n/**\r\n * @brief Lowlink\r\n */\n#line 5 \"Verify/LC_two_edge_connected_components.test.cpp\"\
    \n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n    LowLink low(n);\r\n\
    \    rep(_,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        low.add_edge(x,y);\r\
    \n    }\r\n    int ret=low.run();\r\n    vector g(ret,vector<int>());\r\n    rep(i,0,n)g[low.id[i]].push_back(i);\r\
    \n\r\n    cout<<ret<<'\\n';\r\n    rep(i,0,g.size()){\r\n        cout<<g[i].size()<<'\
    \ ';\r\n        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\\\
    n':' ');\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Graph/lowlink.hpp\"\r\
    \n\r\nint main(){\r\n    int n,m;\r\n    cin>>n>>m;\r\n    LowLink low(n);\r\n\
    \    rep(_,0,m){\r\n        int x,y;\r\n        cin>>x>>y;\r\n        low.add_edge(x,y);\r\
    \n    }\r\n    int ret=low.run();\r\n    vector g(ret,vector<int>());\r\n    rep(i,0,n)g[low.id[i]].push_back(i);\r\
    \n\r\n    cout<<ret<<'\\n';\r\n    rep(i,0,g.size()){\r\n        cout<<g[i].size()<<'\
    \ ';\r\n        rep(j,0,g[i].size())cout<<g[i][j]<<(j==(int)g[i].size()-1?'\\\
    n':' ');\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/lowlink.hpp
  isVerificationFile: true
  path: Verify/LC_two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_two_edge_connected_components.test.cpp
- /verify/Verify/LC_two_edge_connected_components.test.cpp.html
title: Verify/LC_two_edge_connected_components.test.cpp
---
