---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':heavy_check_mark:'
    path: DataStructure/persistentrbstset.hpp
    title: Persistent Randomized Binary Search Tree (set)
  - icon: ':heavy_check_mark:'
    path: DataStructure/rbstset.hpp
    title: Randomized Binary Search Tree (set)
  - icon: ':heavy_check_mark:'
    path: Graph/maxindependentset.hpp
    title: Maximum Independent Set
  - icon: ':question:'
    path: Math/bbla.hpp
    title: Black Box Linear Algebra
  - icon: ':warning:'
    path: Math/binomquery.hpp
    title: Binomial Coefficient for query
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_discrete_logarithm_mod.test.cpp
    title: Verify/LC_discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_factorize.test.cpp
    title: Verify/LC_factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_maximum_independent_set.test.cpp
    title: Verify/LC_maximum_independent_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_predecessor_problem.test.cpp
    title: Verify/LC_predecessor_problem.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_range_kth_smallest-2.test.cpp
    title: Verify/LC_range_kth_smallest-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_sparse_matrix_det.test.cpp
    title: Verify/LC_sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1112.test.cpp
    title: Verify/YUKI_1112.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_310.test.cpp
    title: Verify/YUKI_310.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Random
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
    \ */\n"
  code: "#pragma once\r\n\r\nstruct Random{\r\n    random_device rnd;\r\n    unsigned\
    \ x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\n    unsigned\
    \ get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\n        return\
    \ w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n    unsigned get(unsigned L){\r\n    \
    \    return get()%(L+1);\r\n    }\r\n    template<typename T>T get(T L,T R){\r\
    \n        return get(R-L)+L;\r\n    }\r\n    double uniform(){\r\n        return\
    \ double(get())/UINT_MAX;\r\n    }\r\n    string str(int n){\r\n        string\
    \ ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\n        return ret;\r\n    }\r\
    \n    template<typename Iter>void shuffle(Iter first,Iter last){\r\n        if(first==last)return;\r\
    \n        int len=1;\r\n        for(auto it=first+1;it!=last;it++){\r\n      \
    \      len++;\r\n            int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\
    \n        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Utility/random.hpp
  requiredBy:
  - DataStructure/rbstset.hpp
  - DataStructure/persistentrbstset.hpp
  - Convolution/multivariatecyclic.hpp
  - Graph/maxindependentset.hpp
  - Math/pollard.hpp
  - Math/binomquery.hpp
  - Math/primitive.hpp
  - Math/bbla.hpp
  timestamp: '2022-01-16 22:20:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_factorize.test.cpp
  - Verify/LC_maximum_independent_set.test.cpp
  - Verify/YUKI_1112.test.cpp
  - Verify/LC_range_kth_smallest-2.test.cpp
  - Verify/LC_predecessor_problem.test.cpp
  - Verify/LC_sparse_matrix_det.test.cpp
  - Verify/YUKI_310.test.cpp
  - Verify/LC_discrete_logarithm_mod.test.cpp
documentation_of: Utility/random.hpp
layout: document
redirect_from:
- /library/Utility/random.hpp
- /library/Utility/random.hpp.html
title: Random
---
