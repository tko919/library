---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_predecessor_problem.test.cpp
    title: Verify/LC_predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Randomized Binary Search Tree (set)
    links: []
  bundledCode: "#line 2 \"DataStructure/rbstset.hpp\"\n\r\n#line 2 \"Utility/random.hpp\"\
    \n\r\nstruct Random{\r\n    random_device rnd;\r\n    unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\
    \n    Random(){}\r\n    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n \
    \       x=y,y=z,z=w;\r\n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n\
    \    unsigned get(unsigned L){\r\n        return get()%(L+1);\r\n    }\r\n   \
    \ template<typename T>T get(T L,T R){\r\n        return get(R-L)+L;\r\n    }\r\
    \n    double uniform(){\r\n        return double(get())/UINT_MAX;\r\n    }\r\n\
    \    string str(int n){\r\n        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\
    \n        return ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter\
    \ first,Iter last){\r\n        if(first==last)return;\r\n        int len=1;\r\n\
    \        for(auto it=first+1;it!=last;it++){\r\n            len++;\r\n       \
    \     int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\n\
    \        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 4 \"DataStructure/rbstset.hpp\"\n\r\nRandom genRBSTset;\r\ntemplate<typename\
    \ T>class RBSTset{\r\n    struct Node{\r\n        Node *lp=nullptr,*rp=nullptr;\r\
    \n        int size=1;\r\n        T key;\r\n        Node(T _k=0):key(_k){}\r\n\
    \        void apply(){\r\n            size=1;\r\n            if(lp)size+=lp->size;\r\
    \n            if(rp)size+=rp->size;\r\n        }\r\n    };\r\n    Node *root=nullptr;\r\
    \n    int size(Node* x){return x?x->size:0;}\r\n    Node* merge(Node* L,Node*\
    \ R){\r\n        if(!L)return R;\r\n        if(!R)return L;\r\n        if((int)genRBSTset.get(size(L)+size(R)-1)<size(L)){\r\
    \n            L->rp=merge(L->rp,R);\r\n            L->apply();\r\n           \
    \ return L;\r\n        }\r\n        else{\r\n            R->lp=merge(L,R->lp);\r\
    \n            R->apply();\r\n            return R;\r\n        }\r\n    }\r\n \
    \   array<Node*,2> split(Node* x,int k){\r\n        if(!x)return {nullptr,nullptr};\r\
    \n        if(k==size(x))return {x,nullptr};\r\n        if(k<=size(x->lp)){\r\n\
    \            auto [lb,rb]=split(x->lp,k);\r\n            Node *L=lb,*R=x;\r\n\
    \            x->lp=rb;\r\n            x->apply();\r\n            return {L,R};\r\
    \n        }\r\n        else{\r\n            auto [lb,rb]=split(x->rp,k-size(x->lp)-1);\r\
    \n            Node *L=x,*R=rb;\r\n            x->rp=lb;\r\n            x->apply();\r\
    \n            return {L,R};\r\n        }\r\n    }\r\n    int lower_bound(Node*\
    \ x,T v){\r\n        if(!x)return 0;\r\n        if(x->key>=v)return lower_bound(x->lp,v);\r\
    \n        else return size(x->lp)+1+lower_bound(x->rp,v);\r\n    }\r\n    int\
    \ upper_bound(Node* x,T v){\r\n        if(!x)return -1;\r\n        if(x->key>v)return\
    \ upper_bound(x->lp,v);\r\n        else return size(x->lp)+1+upper_bound(x->rp,v);\r\
    \n    }\r\n    void _dump(Node* cur,string add){\r\n        if(!cur)return;\r\n\
    \        _dump(cur->lp,add+\"*\");\r\n        cerr<<add<<cur->key<<'\\n';\r\n\
    \        _dump(cur->rp,add+\"*\");\r\n    }\r\npublic:\r\n    RBSTset(){}\r\n\
    \    int size(){return size(root);}\r\n    bool find(T x){\r\n        Node *cur=root;\r\
    \n        for(;;){\r\n            if(!cur)break;\r\n            if(cur->key==x)return\
    \ true;\r\n            else if(x<cur->key)cur=cur->lp;\r\n            else cur=cur->rp;\r\
    \n        }\r\n        return false;\r\n    }\r\n    void insert(T x){\r\n   \
    \     int k=lower_bound(root,x);\r\n        auto [L,R]=split(root,k);\r\n    \
    \    root=merge(merge(L,new Node(x)),R);\r\n    }\r\n    void erase(T x){\r\n\
    \        assert(find(x));\r\n        int k=lower_bound(root,x);\r\n        auto\
    \ [L,t]=split(root,k);\r\n        auto [tmp,R]=split(t,1);\r\n        root=merge(L,R);\r\
    \n    }\r\n    T kth_element(int k){\r\n        if(k>=size(root) or k<0)return\
    \ -1;\r\n        auto [L,R]=split(root,k);\r\n        Node* cur=R;\r\n       \
    \ while(cur->lp)cur=cur->lp;\r\n        root=merge(L,R);\r\n        return cur->key;\r\
    \n    }\r\n    T lower_bound(T v){\r\n        return kth_element(lower_bound(root,v));\r\
    \n    }\r\n    T upper_bound(T v){\r\n        return kth_element(upper_bound(root,v));\r\
    \n    }\r\n    void dump(){\r\n        _dump(root,\"*\");\r\n    }\r\n};\r\n\r\
    \n/**\r\n * @brief Randomized Binary Search Tree (set)\r\n */\n"
  code: "#pragma once\r\n\r\n#include \"Utility/random.hpp\"\r\n\r\nRandom genRBSTset;\r\
    \ntemplate<typename T>class RBSTset{\r\n    struct Node{\r\n        Node *lp=nullptr,*rp=nullptr;\r\
    \n        int size=1;\r\n        T key;\r\n        Node(T _k=0):key(_k){}\r\n\
    \        void apply(){\r\n            size=1;\r\n            if(lp)size+=lp->size;\r\
    \n            if(rp)size+=rp->size;\r\n        }\r\n    };\r\n    Node *root=nullptr;\r\
    \n    int size(Node* x){return x?x->size:0;}\r\n    Node* merge(Node* L,Node*\
    \ R){\r\n        if(!L)return R;\r\n        if(!R)return L;\r\n        if((int)genRBSTset.get(size(L)+size(R)-1)<size(L)){\r\
    \n            L->rp=merge(L->rp,R);\r\n            L->apply();\r\n           \
    \ return L;\r\n        }\r\n        else{\r\n            R->lp=merge(L,R->lp);\r\
    \n            R->apply();\r\n            return R;\r\n        }\r\n    }\r\n \
    \   array<Node*,2> split(Node* x,int k){\r\n        if(!x)return {nullptr,nullptr};\r\
    \n        if(k==size(x))return {x,nullptr};\r\n        if(k<=size(x->lp)){\r\n\
    \            auto [lb,rb]=split(x->lp,k);\r\n            Node *L=lb,*R=x;\r\n\
    \            x->lp=rb;\r\n            x->apply();\r\n            return {L,R};\r\
    \n        }\r\n        else{\r\n            auto [lb,rb]=split(x->rp,k-size(x->lp)-1);\r\
    \n            Node *L=x,*R=rb;\r\n            x->rp=lb;\r\n            x->apply();\r\
    \n            return {L,R};\r\n        }\r\n    }\r\n    int lower_bound(Node*\
    \ x,T v){\r\n        if(!x)return 0;\r\n        if(x->key>=v)return lower_bound(x->lp,v);\r\
    \n        else return size(x->lp)+1+lower_bound(x->rp,v);\r\n    }\r\n    int\
    \ upper_bound(Node* x,T v){\r\n        if(!x)return -1;\r\n        if(x->key>v)return\
    \ upper_bound(x->lp,v);\r\n        else return size(x->lp)+1+upper_bound(x->rp,v);\r\
    \n    }\r\n    void _dump(Node* cur,string add){\r\n        if(!cur)return;\r\n\
    \        _dump(cur->lp,add+\"*\");\r\n        cerr<<add<<cur->key<<'\\n';\r\n\
    \        _dump(cur->rp,add+\"*\");\r\n    }\r\npublic:\r\n    RBSTset(){}\r\n\
    \    int size(){return size(root);}\r\n    bool find(T x){\r\n        Node *cur=root;\r\
    \n        for(;;){\r\n            if(!cur)break;\r\n            if(cur->key==x)return\
    \ true;\r\n            else if(x<cur->key)cur=cur->lp;\r\n            else cur=cur->rp;\r\
    \n        }\r\n        return false;\r\n    }\r\n    void insert(T x){\r\n   \
    \     int k=lower_bound(root,x);\r\n        auto [L,R]=split(root,k);\r\n    \
    \    root=merge(merge(L,new Node(x)),R);\r\n    }\r\n    void erase(T x){\r\n\
    \        assert(find(x));\r\n        int k=lower_bound(root,x);\r\n        auto\
    \ [L,t]=split(root,k);\r\n        auto [tmp,R]=split(t,1);\r\n        root=merge(L,R);\r\
    \n    }\r\n    T kth_element(int k){\r\n        if(k>=size(root) or k<0)return\
    \ -1;\r\n        auto [L,R]=split(root,k);\r\n        Node* cur=R;\r\n       \
    \ while(cur->lp)cur=cur->lp;\r\n        root=merge(L,R);\r\n        return cur->key;\r\
    \n    }\r\n    T lower_bound(T v){\r\n        return kth_element(lower_bound(root,v));\r\
    \n    }\r\n    T upper_bound(T v){\r\n        return kth_element(upper_bound(root,v));\r\
    \n    }\r\n    void dump(){\r\n        _dump(root,\"*\");\r\n    }\r\n};\r\n\r\
    \n/**\r\n * @brief Randomized Binary Search Tree (set)\r\n */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: DataStructure/rbstset.hpp
  requiredBy: []
  timestamp: '2022-01-16 22:20:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_predecessor_problem.test.cpp
documentation_of: DataStructure/rbstset.hpp
layout: document
redirect_from:
- /library/DataStructure/rbstset.hpp
- /library/DataStructure/rbstset.hpp.html
title: Randomized Binary Search Tree (set)
---
