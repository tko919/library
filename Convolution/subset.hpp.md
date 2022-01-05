---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Convolution/subset.hpp\"\n\r\ntemplate<typename T>vector<T>\
    \ SubsetConvolution(vector<T>& a,vector<T>& b){\r\n    int m=a.size(),n=__lg(m);\r\
    \n    vector aa(n+1,vector<T>(m)),bb(n+1,vector<T>(m)),cc(n+1,vector<T>(m));\r\
    \n    rep(i,0,m){\r\n        aa[__builtin_popcountll(i)][i]=a[i];\r\n        bb[__builtin_popcountll(i)][i]=b[i];\r\
    \n    }\r\n    rep(base,0,n+1){\r\n        rep(i,0,n)rep(mask,0,m)if(!(mask>>i&1)){\r\
    \n            aa[base][mask|(1<<i)]+=aa[base][mask];\r\n            bb[base][mask|(1<<i)]+=bb[base][mask];\r\
    \n        }\r\n    }\r\n    rep(i,0,n+1)rep(j,0,n+1-i)rep(mask,0,m){\r\n     \
    \   cc[i+j][mask]+=aa[i][mask]*bb[j][mask];\r\n    }\r\n    rep(base,0,n+1){\r\
    \n        rep(i,0,n)rep(mask,0,m)if(mask>>i&1){\r\n            cc[base][mask]-=cc[base][mask^(1<<i)];\r\
    \n        }\r\n    }\r\n    vector<T> ret(m);\r\n    rep(i,0,m){\r\n        ret[i]=cc[__builtin_popcountll(i)][i];\r\
    \n    }\r\n    return ret;\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>vector<T> SubsetConvolution(vector<T>&\
    \ a,vector<T>& b){\r\n    int m=a.size(),n=__lg(m);\r\n    vector aa(n+1,vector<T>(m)),bb(n+1,vector<T>(m)),cc(n+1,vector<T>(m));\r\
    \n    rep(i,0,m){\r\n        aa[__builtin_popcountll(i)][i]=a[i];\r\n        bb[__builtin_popcountll(i)][i]=b[i];\r\
    \n    }\r\n    rep(base,0,n+1){\r\n        rep(i,0,n)rep(mask,0,m)if(!(mask>>i&1)){\r\
    \n            aa[base][mask|(1<<i)]+=aa[base][mask];\r\n            bb[base][mask|(1<<i)]+=bb[base][mask];\r\
    \n        }\r\n    }\r\n    rep(i,0,n+1)rep(j,0,n+1-i)rep(mask,0,m){\r\n     \
    \   cc[i+j][mask]+=aa[i][mask]*bb[j][mask];\r\n    }\r\n    rep(base,0,n+1){\r\
    \n        rep(i,0,n)rep(mask,0,m)if(mask>>i&1){\r\n            cc[base][mask]-=cc[base][mask^(1<<i)];\r\
    \n        }\r\n    }\r\n    vector<T> ret(m);\r\n    rep(i,0,m){\r\n        ret[i]=cc[__builtin_popcountll(i)][i];\r\
    \n    }\r\n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/subset.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Convolution/subset.hpp
layout: document
redirect_from:
- /library/Convolution/subset.hpp
- /library/Convolution/subset.hpp.html
title: Convolution/subset.hpp
---
