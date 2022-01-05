---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Random
    links: []
  bundledCode: "#line 2 \"Utility/random.hpp\"\n\r\nstruct Random{\r\n    random_device\
    \ rnd;\r\n    unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\
    \n    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\
    \n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n    unsigned get(unsigned\
    \ L){\r\n        return get()%(L+1);\r\n    }\r\n    template<typename T>T get(T\
    \ L,T R){\r\n        return get(R-L)+L;\r\n    }\r\n    string str(int n){\r\n\
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
    \n        return get(R-L)+L;\r\n    }\r\n    string str(int n){\r\n        string\
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
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/random.hpp
layout: document
redirect_from:
- /library/Utility/random.hpp
- /library/Utility/random.hpp.html
title: Random
---
