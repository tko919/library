---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: $q$-binomial
    links: []
  bundledCode: "#line 2 \"Math/qbinom.hpp\"\n\ntemplate<typename T>struct QBinom{\n\
    \    int ord;\n    vector<T> fact,ifact;\n    QBinom(T q,int sz){\n        vector<T>\
    \ base;\n        T x=1;\n        rep(i,0,sz){\n            base.push_back(x);\n\
    \            x=x*q+1;\n            if(x==0)break;\n        }\n        ord=SZ(base);\n\
    \        fact.push_back(1);\n        rep(i,0,ord){\n            fact.push_back(fact.back()*base[i]);\n\
    \        }\n        ifact.push_back(T(1)/fact.back());\n        rrep(i,0,ord){\n\
    \            ifact.push_back(ifact.back()*base[i]);\n        }\n        reverse(ALL(ifact));\n\
    \        ord++;\n        show(fact,ifact,ord);\n    }  \n    T binom(int n,int\
    \ r){\n        if(r<0 or n<r)return 0;\n        if(n<ord)return fact[n]*ifact[r]*ifact[n-r];\n\
    \        \n        int n1=n/ord,n2=n%ord;\n        int r1=r/ord,r2=r%ord;\n  \
    \      return nCr<T>(n1, r1) * binom(n2, r2);\n    }\n};\n\n/**\n * @brief $q$-binomial\n\
    \ */\n"
  code: "#pragma once\n\ntemplate<typename T>struct QBinom{\n    int ord;\n    vector<T>\
    \ fact,ifact;\n    QBinom(T q,int sz){\n        vector<T> base;\n        T x=1;\n\
    \        rep(i,0,sz){\n            base.push_back(x);\n            x=x*q+1;\n\
    \            if(x==0)break;\n        }\n        ord=SZ(base);\n        fact.push_back(1);\n\
    \        rep(i,0,ord){\n            fact.push_back(fact.back()*base[i]);\n   \
    \     }\n        ifact.push_back(T(1)/fact.back());\n        rrep(i,0,ord){\n\
    \            ifact.push_back(ifact.back()*base[i]);\n        }\n        reverse(ALL(ifact));\n\
    \        ord++;\n        show(fact,ifact,ord);\n    }  \n    T binom(int n,int\
    \ r){\n        if(r<0 or n<r)return 0;\n        if(n<ord)return fact[n]*ifact[r]*ifact[n-r];\n\
    \        \n        int n1=n/ord,n2=n%ord;\n        int r1=r/ord,r2=r%ord;\n  \
    \      return nCr<T>(n1, r1) * binom(n2, r2);\n    }\n};\n\n/**\n * @brief $q$-binomial\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: Math/qbinom.hpp
  requiredBy: []
  timestamp: '2024-06-22 00:56:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/qbinom.hpp
layout: document
redirect_from:
- /library/Math/qbinom.hpp
- /library/Math/qbinom.hpp.html
title: $q$-binomial
---
