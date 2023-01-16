---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/persistentarray.hpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_persistent_unionfind.test.cpp
    title: Verify/LC_persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Persistent Union Find
    links: []
  bundledCode: "#line 2 \"DataStructure/persistentarray.hpp\"\n\r\ntemplate<typename\
    \ T,int B=4>class PersistentArray{\r\n    const int M=(1<<B)-1;\r\n    struct\
    \ Node{\r\n        Node *cp[1<<B]={};\r\n        T val;\r\n    };\r\n    Node*\
    \ set(int i,T x,Node* a){\r\n        Node *ret=new Node();\r\n        if(a){\r\
    \n            memcpy(ret->cp,a->cp,sizeof(a->cp));\r\n            ret->val=a->val;\r\
    \n        }\r\n        if(i)ret->cp[i&M]=set(i>>B,x,ret->cp[i&M]);\r\n       \
    \ else ret->val=x;\r\n        return ret;\r\n    }\r\n    T get(int i,Node* a){\r\
    \n        if(i)return get(i>>B,a->cp[i&M]);\r\n        else return a->val;\r\n\
    \    }\r\npublic:\r\n    Node *root;\r\n    PersistentArray(Node* _r=nullptr):root(_r){}\r\
    \n    void set(int i,T x){\r\n        root=set(i,x,root);\r\n    }\r\n    T get(int\
    \ i){\r\n        return get(i,root);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Persistent\
    \ Array\r\n */\n#line 3 \"DataStructure/persistentunionfind.hpp\"\n\r\nstruct\
    \ PersistentUnionFind{\r\n    PersistentArray<int> dat;\r\n    PersistentUnionFind(int\
    \ n){\r\n        rep(i,0,n)dat.set(i,-1);\r\n    }\r\n    int root(int x){\r\n\
    \        if(dat.get(x)<0)return x;\r\n        else return root(dat.get(x));\r\n\
    \    }\r\n    bool unite(int x,int y){\r\n        x=root(x),y=root(y);\r\n   \
    \     if(x==y)return false;\r\n        int p=dat.get(x),q=dat.get(y);\r\n    \
    \    if(p>q)swap(x,y);\r\n        dat.set(x,p+q);\r\n        dat.set(y,x);\r\n\
    \        return true;\r\n    }\r\n    bool same(int x,int y){return root(x)==root(y);}\r\
    \n    int size(int a){return -dat.get(root(a));}\r\n};\r\n\r\n/**\r\n * @brief\
    \ Persistent Union Find\r\n */\n"
  code: "#pragma once\r\n#include \"DataStructure/persistentarray.hpp\"\r\n\r\nstruct\
    \ PersistentUnionFind{\r\n    PersistentArray<int> dat;\r\n    PersistentUnionFind(int\
    \ n){\r\n        rep(i,0,n)dat.set(i,-1);\r\n    }\r\n    int root(int x){\r\n\
    \        if(dat.get(x)<0)return x;\r\n        else return root(dat.get(x));\r\n\
    \    }\r\n    bool unite(int x,int y){\r\n        x=root(x),y=root(y);\r\n   \
    \     if(x==y)return false;\r\n        int p=dat.get(x),q=dat.get(y);\r\n    \
    \    if(p>q)swap(x,y);\r\n        dat.set(x,p+q);\r\n        dat.set(y,x);\r\n\
    \        return true;\r\n    }\r\n    bool same(int x,int y){return root(x)==root(y);}\r\
    \n    int size(int a){return -dat.get(root(a));}\r\n};\r\n\r\n/**\r\n * @brief\
    \ Persistent Union Find\r\n */"
  dependsOn:
  - DataStructure/persistentarray.hpp
  isVerificationFile: false
  path: DataStructure/persistentunionfind.hpp
  requiredBy: []
  timestamp: '2022-01-16 22:20:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_persistent_unionfind.test.cpp
documentation_of: DataStructure/persistentunionfind.hpp
layout: document
redirect_from:
- /library/DataStructure/persistentunionfind.hpp
- /library/DataStructure/persistentunionfind.hpp.html
title: Persistent Union Find
---
