---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: DataStructure/persistentunionfind.hpp
    title: Persistent Union Find
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_persistent_unionfind.test.cpp
    title: Verify/LC_persistent_unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Persistent Array
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
    \ Array\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,int B=4>class PersistentArray{\r\n\
    \    const int M=(1<<B)-1;\r\n    struct Node{\r\n        Node *cp[1<<B]={};\r\
    \n        T val;\r\n    };\r\n    Node* set(int i,T x,Node* a){\r\n        Node\
    \ *ret=new Node();\r\n        if(a){\r\n            memcpy(ret->cp,a->cp,sizeof(a->cp));\r\
    \n            ret->val=a->val;\r\n        }\r\n        if(i)ret->cp[i&M]=set(i>>B,x,ret->cp[i&M]);\r\
    \n        else ret->val=x;\r\n        return ret;\r\n    }\r\n    T get(int i,Node*\
    \ a){\r\n        if(i)return get(i>>B,a->cp[i&M]);\r\n        else return a->val;\r\
    \n    }\r\npublic:\r\n    Node *root;\r\n    PersistentArray(Node* _r=nullptr):root(_r){}\r\
    \n    void set(int i,T x){\r\n        root=set(i,x,root);\r\n    }\r\n    T get(int\
    \ i){\r\n        return get(i,root);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Persistent\
    \ Array\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/persistentarray.hpp
  requiredBy:
  - DataStructure/persistentunionfind.hpp
  timestamp: '2022-01-16 22:20:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_persistent_unionfind.test.cpp
documentation_of: DataStructure/persistentarray.hpp
layout: document
redirect_from:
- /library/DataStructure/persistentarray.hpp
- /library/DataStructure/persistentarray.hpp.html
title: Persistent Array
---
