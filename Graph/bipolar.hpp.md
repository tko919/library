---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/linkedlist.hpp
    title: Linked List
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Bipolar Orientation
    links: []
  bundledCode: "#line 2 \"DataStructure/linkedlist.hpp\"\n\ntemplate<typename T>struct\
    \ LinkedList{\n    struct Node{\n        T val;\n        Node* head,*tail;\n \
    \       Node(){}\n        Node(T v):val(v),head(nullptr),tail(nullptr){}\n   \
    \ };\n    Node* front;\n    LinkedList():front(nullptr){}\n    Node* insert_back(Node*\
    \ v,T x){\n        if(v==nullptr){\n            return front=new Node(x);\n  \
    \      }\n        auto to=v->tail;\n        auto add=new Node(x);\n        v->tail=add;\n\
    \        add->head=v;\n        add->tail=to;\n        if(to)to->head=add;\n  \
    \      return add;\n    }\n    Node* insert_front(Node* v,T x){\n        if(v==nullptr){\n\
    \            return front=new Node(x);\n        }\n        auto to=v->head;\n\
    \        auto add=new Node(x);\n        if(to)to->tail=add;\n        add->head=to;\n\
    \        add->tail=v;\n        v->head=add;\n        return add;\n    }\n    vector<T>\
    \ dump(){\n        vector<T> ret;\n        Node* cur=front;\n        while(cur){\n\
    \            ret.push_back(cur->val);\n            cur=cur->tail;\n        }\n\
    \        return ret;\n    }\n};  \n\n/**\n * @brief Linked List\n */\n#line 3\
    \ \"Graph/bipolar.hpp\"\n\nvector<int> BipolarOrientation(int n,vector<vector<int>>&\
    \ g,int s,int t){\n    int cur=1;\n    vector<int> par(n),ord(n,-1),low(n),path;\n\
    \    auto dfs=[&](auto& dfs,int v)->void{\n        ord[v]=cur++;\n        low[v]=v;\n\
    \        path.push_back(v);\n        for(auto& to:g[v]){\n            if(ord[to]==-1){\n\
    \                dfs(dfs,to);\n                par[to]=v;\n                if(ord[low[to]]<ord[low[v]]){\n\
    \                    low[v]=low[to];\n                }\n            }\n     \
    \       else if(ord[to]<ord[low[v]])low[v]=to;\n        }\n    };\n    ord[s]=0;\n\
    \    dfs(dfs,t);\n    if(SZ(path)!=n-1)return {};\n    path.erase(path.begin());\n\
    \    \n    const bool plus=1,minus=0;\n    vector<int> sign(n);\n    LinkedList<int>\
    \ LL;\n    vector<LinkedList<int>::Node*> nodes(n);\n    nodes[s]=LL.insert_front(nullptr,s);\n\
    \    nodes[t]=LL.insert_back(nodes[s],t);\n    \n    for(auto& v:path){\n    \
    \    if(sign[low[v]]==minus){\n            nodes[v]=LL.insert_front(nodes[par[v]],v);\n\
    \            sign[par[v]]=plus;\n        }\n        else{\n            nodes[v]=LL.insert_back(nodes[par[v]],v);\n\
    \            sign[par[v]]=minus;\n        }\n    }\n    auto perm=LL.dump(); //\
    \ index:vertices\n    vector<int> ret(n);\n    rep(i,0,n)ret[perm[i]]=i;\n\n \
    \   // check\n    vector<int> FROM(n),TO(n);\n    FROM[s]=TO[t]=1;\n    for(auto&\
    \ v:perm){\n        if(!FROM[v])return {};\n        for(auto& to:g[v])if(ret[v]<ret[to]){\n\
    \            FROM[to]=1;\n        }\n    }\n    reverse(ALL(perm));\n    for(auto&\
    \ v:perm){\n        if(!TO[v])return {};\n        for(auto& to:g[v])if(ret[v]>ret[to]){\n\
    \            TO[to]=1;\n        }\n    }\n\n    return ret;\n}\n\n/**\n * @brief\
    \ Bipolar Orientation\n */\n"
  code: "#pragma once\n#include \"DataStructure/linkedlist.hpp\"\n\nvector<int> BipolarOrientation(int\
    \ n,vector<vector<int>>& g,int s,int t){\n    int cur=1;\n    vector<int> par(n),ord(n,-1),low(n),path;\n\
    \    auto dfs=[&](auto& dfs,int v)->void{\n        ord[v]=cur++;\n        low[v]=v;\n\
    \        path.push_back(v);\n        for(auto& to:g[v]){\n            if(ord[to]==-1){\n\
    \                dfs(dfs,to);\n                par[to]=v;\n                if(ord[low[to]]<ord[low[v]]){\n\
    \                    low[v]=low[to];\n                }\n            }\n     \
    \       else if(ord[to]<ord[low[v]])low[v]=to;\n        }\n    };\n    ord[s]=0;\n\
    \    dfs(dfs,t);\n    if(SZ(path)!=n-1)return {};\n    path.erase(path.begin());\n\
    \    \n    const bool plus=1,minus=0;\n    vector<int> sign(n);\n    LinkedList<int>\
    \ LL;\n    vector<LinkedList<int>::Node*> nodes(n);\n    nodes[s]=LL.insert_front(nullptr,s);\n\
    \    nodes[t]=LL.insert_back(nodes[s],t);\n    \n    for(auto& v:path){\n    \
    \    if(sign[low[v]]==minus){\n            nodes[v]=LL.insert_front(nodes[par[v]],v);\n\
    \            sign[par[v]]=plus;\n        }\n        else{\n            nodes[v]=LL.insert_back(nodes[par[v]],v);\n\
    \            sign[par[v]]=minus;\n        }\n    }\n    auto perm=LL.dump(); //\
    \ index:vertices\n    vector<int> ret(n);\n    rep(i,0,n)ret[perm[i]]=i;\n\n \
    \   // check\n    vector<int> FROM(n),TO(n);\n    FROM[s]=TO[t]=1;\n    for(auto&\
    \ v:perm){\n        if(!FROM[v])return {};\n        for(auto& to:g[v])if(ret[v]<ret[to]){\n\
    \            FROM[to]=1;\n        }\n    }\n    reverse(ALL(perm));\n    for(auto&\
    \ v:perm){\n        if(!TO[v])return {};\n        for(auto& to:g[v])if(ret[v]>ret[to]){\n\
    \            TO[to]=1;\n        }\n    }\n\n    return ret;\n}\n\n/**\n * @brief\
    \ Bipolar Orientation\n */"
  dependsOn:
  - DataStructure/linkedlist.hpp
  isVerificationFile: false
  path: Graph/bipolar.hpp
  requiredBy: []
  timestamp: '2024-06-22 00:56:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bipolar.hpp
layout: document
redirect_from:
- /library/Graph/bipolar.hpp
- /library/Graph/bipolar.hpp.html
title: Bipolar Orientation
---
