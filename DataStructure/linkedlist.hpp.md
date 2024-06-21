---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/bipolar.hpp
    title: Bipolar Orientation
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Linked List
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
    \        return ret;\n    }\n};  \n\n/**\n * @brief Linked List\n */\n"
  code: "#pragma once\n\ntemplate<typename T>struct LinkedList{\n    struct Node{\n\
    \        T val;\n        Node* head,*tail;\n        Node(){}\n        Node(T v):val(v),head(nullptr),tail(nullptr){}\n\
    \    };\n    Node* front;\n    LinkedList():front(nullptr){}\n    Node* insert_back(Node*\
    \ v,T x){\n        if(v==nullptr){\n            return front=new Node(x);\n  \
    \      }\n        auto to=v->tail;\n        auto add=new Node(x);\n        v->tail=add;\n\
    \        add->head=v;\n        add->tail=to;\n        if(to)to->head=add;\n  \
    \      return add;\n    }\n    Node* insert_front(Node* v,T x){\n        if(v==nullptr){\n\
    \            return front=new Node(x);\n        }\n        auto to=v->head;\n\
    \        auto add=new Node(x);\n        if(to)to->tail=add;\n        add->head=to;\n\
    \        add->tail=v;\n        v->head=add;\n        return add;\n    }\n    vector<T>\
    \ dump(){\n        vector<T> ret;\n        Node* cur=front;\n        while(cur){\n\
    \            ret.push_back(cur->val);\n            cur=cur->tail;\n        }\n\
    \        return ret;\n    }\n};  \n\n/**\n * @brief Linked List\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/linkedlist.hpp
  requiredBy:
  - Graph/bipolar.hpp
  timestamp: '2024-06-22 00:56:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/linkedlist.hpp
layout: document
redirect_from:
- /library/DataStructure/linkedlist.hpp
- /library/DataStructure/linkedlist.hpp.html
title: Linked List
---
