---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_range_kth_smallest-2.test.cpp
    title: Verify/LC_range_kth_smallest-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Persistent Randomized Binary Search Tree (set)
    links: []
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nstruct Random{\r\n    random_device\
    \ rnd;\r\n    unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\
    \n    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\
    \n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n    unsigned get(unsigned\
    \ L){\r\n        return get()%(L+1);\r\n    }\r\n    template<typename T>T get(T\
    \ L,T R){\r\n        return get(R-L)+L;\r\n    }\r\n    double uniform(){\r\n\
    \        return double(get())/UINT_MAX;\r\n    }\r\n    string str(int n){\r\n\
    \        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\n        return\
    \ ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter first,Iter last){\r\
    \n        if(first==last)return;\r\n        int len=1;\r\n        for(auto it=first+1;it!=last;it++){\r\
    \n            len++;\r\n            int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\
    \n        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 3 \"DataStructure/persistentrbstset.hpp\"\n\r\nRandom genPRBSTset;\r\
    \ntemplate<typename T,int LIM=5010101>struct PRBSTset{\r\n    struct Node{\r\n\
    \        Node *lp=nullptr,*rp=nullptr;\r\n        int sz=1;\r\n        T val;\r\
    \n        Node(){}\r\n        void apply(){\r\n            sz=1;\r\n         \
    \   if(lp)sz+=lp->sz;\r\n            if(rp)sz+=rp->sz;\r\n        }\r\n    };\r\
    \n    using np=Node*;\r\n    Node buf[LIM];\r\n    int pos=0;\r\n    int sz(np\
    \ root){return root?root->sz:0;}\r\n    np merge(np L,np R){\r\n        if(!L)return\
    \ R;\r\n        if(!R)return L;\r\n        if(genPRBSTset.uniform()*(sz(L)+sz(R))<sz(L)){\r\
    \n            auto rb=merge(L->rp,R);\r\n            np ret=make(L->val,L->lp,rb);\r\
    \n            return ret;\r\n        }\r\n        else{\r\n            auto lb=merge(L,R->lp);\r\
    \n            np ret=make(R->val,lb,R->rp);\r\n            return ret;\r\n   \
    \     }\r\n    }\r\n    array<np,2> split(np root,int k){\r\n        if(k<=0)return\
    \ {nullptr,root};\r\n        if(k>=sz(root))return {root,nullptr};\r\n       \
    \ if(k<=sz(root->lp)){\r\n            auto [L,lb]=split(root->lp,k);\r\n     \
    \       np R=make(root->val,lb,root->rp);\r\n            return {L,R};\r\n   \
    \     }\r\n        else{\r\n            auto [rb,R]=split(root->rp,k-1-sz(root->lp));\r\
    \n            np L=make(root->val,root->lp,rb);\r\n            return {L,R};\r\
    \n        }\r\n    }\r\n    bool find(np root,T v){\r\n        if(!root)return\
    \ false;\r\n        if(root->val==v)return true;\r\n        else if(root->val>v)return\
    \ find(root->lp,v);\r\n        else return find(root->rp,v);\r\n    }\r\n    int\
    \ lower_bound(np root,T v){\r\n        if(!root)return 0;\r\n        if(root->val>v)return\
    \ lower_bound(root->lp,v);\r\n        else return sz(root->lp)+1+lower_bound(root->rp,v);\r\
    \n    }\r\n    int upper_bound(np root,T v){\r\n        if(!root)return 0;\r\n\
    \        if(root->val>=v)return upper_bound(root->lp,v);\r\n        else return\
    \ sz(root->lp)+1+upper_bound(root->rp,v);\r\n    }\r\n    np make(T v,np L=nullptr,np\
    \ R=nullptr){\r\n        np ret=&buf[pos++];\r\n        ret->val=v;\r\n      \
    \  ret->lp=L;\r\n        ret->rp=R;\r\n        ret->apply();\r\n        return\
    \ ret;\r\n    }\r\n    void dfs(np root,vector<T>& a){\r\n        if(!root)return;\r\
    \n        dfs(root->lp,a);\r\n        a.push_back(root->val);\r\n        dfs(root->rp,a);\r\
    \n    }\r\n    np rebuild(np root){\r\n        if(pos<LIM*.95)return root;\r\n\
    \        vector<T> tmp;\r\n        dfs(root,tmp);\r\n        return build(tmp);\r\
    \n    }\r\n    np insert(np root,T v){\r\n        int k=lower_bound(root,v);\r\
    \n        auto [L,R]=split(root,k);\r\n        return merge(merge(L,make(v)),R);\r\
    \n    }\r\n    np erase(np root,T v){\r\n        int k=lower_bound(root,v);\r\n\
    \        auto [L,rb]=split(root,k);\r\n        auto [tmp,R]=split(rb,1);\r\n \
    \       return merge(L,R);\r\n    }\r\n    T kth_elem(np root,int k){\r\n    \
    \    assert(k<=0 and k<sz(root));\r\n        if(sz(root->lp)==k)return root->val;\r\
    \n        else if(sz(root->lp)>k)return kth_elem(root->lp,k);\r\n        else\
    \ return kth_elem(root->rp,k-1-sz(root->lp));\r\n    }\r\n    np build(vector<T>&\
    \ a){\r\n        np root=nullptr;\r\n        for(auto& x:a)root=merge(root,make(x));\r\
    \n        return root;\r\n    }\r\n    void dump(np root){\r\n        if(!root)return;\r\
    \n        dump(root->lp);\r\n        cerr<<root->val<<'\\n';\r\n        dump(root->rp);\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Persistent Randomized Binary Search Tree\
    \ (set)\r\n */\n"
  code: "#pragma once\r\n#include \"Utility/random.hpp\"\r\n\r\nRandom genPRBSTset;\r\
    \ntemplate<typename T,int LIM=5010101>struct PRBSTset{\r\n    struct Node{\r\n\
    \        Node *lp=nullptr,*rp=nullptr;\r\n        int sz=1;\r\n        T val;\r\
    \n        Node(){}\r\n        void apply(){\r\n            sz=1;\r\n         \
    \   if(lp)sz+=lp->sz;\r\n            if(rp)sz+=rp->sz;\r\n        }\r\n    };\r\
    \n    using np=Node*;\r\n    Node buf[LIM];\r\n    int pos=0;\r\n    int sz(np\
    \ root){return root?root->sz:0;}\r\n    np merge(np L,np R){\r\n        if(!L)return\
    \ R;\r\n        if(!R)return L;\r\n        if(genPRBSTset.uniform()*(sz(L)+sz(R))<sz(L)){\r\
    \n            auto rb=merge(L->rp,R);\r\n            np ret=make(L->val,L->lp,rb);\r\
    \n            return ret;\r\n        }\r\n        else{\r\n            auto lb=merge(L,R->lp);\r\
    \n            np ret=make(R->val,lb,R->rp);\r\n            return ret;\r\n   \
    \     }\r\n    }\r\n    array<np,2> split(np root,int k){\r\n        if(k<=0)return\
    \ {nullptr,root};\r\n        if(k>=sz(root))return {root,nullptr};\r\n       \
    \ if(k<=sz(root->lp)){\r\n            auto [L,lb]=split(root->lp,k);\r\n     \
    \       np R=make(root->val,lb,root->rp);\r\n            return {L,R};\r\n   \
    \     }\r\n        else{\r\n            auto [rb,R]=split(root->rp,k-1-sz(root->lp));\r\
    \n            np L=make(root->val,root->lp,rb);\r\n            return {L,R};\r\
    \n        }\r\n    }\r\n    bool find(np root,T v){\r\n        if(!root)return\
    \ false;\r\n        if(root->val==v)return true;\r\n        else if(root->val>v)return\
    \ find(root->lp,v);\r\n        else return find(root->rp,v);\r\n    }\r\n    int\
    \ lower_bound(np root,T v){\r\n        if(!root)return 0;\r\n        if(root->val>v)return\
    \ lower_bound(root->lp,v);\r\n        else return sz(root->lp)+1+lower_bound(root->rp,v);\r\
    \n    }\r\n    int upper_bound(np root,T v){\r\n        if(!root)return 0;\r\n\
    \        if(root->val>=v)return upper_bound(root->lp,v);\r\n        else return\
    \ sz(root->lp)+1+upper_bound(root->rp,v);\r\n    }\r\n    np make(T v,np L=nullptr,np\
    \ R=nullptr){\r\n        np ret=&buf[pos++];\r\n        ret->val=v;\r\n      \
    \  ret->lp=L;\r\n        ret->rp=R;\r\n        ret->apply();\r\n        return\
    \ ret;\r\n    }\r\n    void dfs(np root,vector<T>& a){\r\n        if(!root)return;\r\
    \n        dfs(root->lp,a);\r\n        a.push_back(root->val);\r\n        dfs(root->rp,a);\r\
    \n    }\r\n    np rebuild(np root){\r\n        if(pos<LIM*.95)return root;\r\n\
    \        vector<T> tmp;\r\n        dfs(root,tmp);\r\n        return build(tmp);\r\
    \n    }\r\n    np insert(np root,T v){\r\n        int k=lower_bound(root,v);\r\
    \n        auto [L,R]=split(root,k);\r\n        return merge(merge(L,make(v)),R);\r\
    \n    }\r\n    np erase(np root,T v){\r\n        int k=lower_bound(root,v);\r\n\
    \        auto [L,rb]=split(root,k);\r\n        auto [tmp,R]=split(rb,1);\r\n \
    \       return merge(L,R);\r\n    }\r\n    T kth_elem(np root,int k){\r\n    \
    \    assert(k<=0 and k<sz(root));\r\n        if(sz(root->lp)==k)return root->val;\r\
    \n        else if(sz(root->lp)>k)return kth_elem(root->lp,k);\r\n        else\
    \ return kth_elem(root->rp,k-1-sz(root->lp));\r\n    }\r\n    np build(vector<T>&\
    \ a){\r\n        np root=nullptr;\r\n        for(auto& x:a)root=merge(root,make(x));\r\
    \n        return root;\r\n    }\r\n    void dump(np root){\r\n        if(!root)return;\r\
    \n        dump(root->lp);\r\n        cerr<<root->val<<'\\n';\r\n        dump(root->rp);\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Persistent Randomized Binary Search Tree\
    \ (set)\r\n */"
  dependsOn:
  - Utility/random.hpp
  isVerificationFile: false
  path: DataStructure/persistentrbstset.hpp
  requiredBy: []
  timestamp: '2022-01-22 19:43:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_range_kth_smallest-2.test.cpp
documentation_of: DataStructure/persistentrbstset.hpp
layout: document
redirect_from:
- /library/DataStructure/persistentrbstset.hpp
- /library/DataStructure/persistentrbstset.hpp.html
title: Persistent Randomized Binary Search Tree (set)
---
