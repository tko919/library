---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Number Theoretic Transform
    links: []
  bundledCode: "#line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate<typename T,unsigned\
    \ p=3>struct NTT{\r\n    vector<T> rt,irt;\r\n    NTT(int lg=21){\r\n        unsigned\
    \ m=T::get_mod()-1; T prt=p;\r\n        rt.resize(lg); irt.resize(lg);\r\n   \
    \     rep(k,0,lg){\r\n            rt[k]=-prt.pow(m>>(k+2));\r\n            irt[k]=rt[k].inv();\r\
    \n        }\r\n    }\r\n    void ntt(vector<T>& f,bool inv=0){\r\n        int\
    \ n=f.size();\r\n        if(inv){\r\n            for(int m=1;m<n;m<<=1){ T w=1;\r\
    \n                for(int s=0,t=0;s<n;s+=m*2){\r\n                    for(int\
    \ i=s,j=s+m;i<s+m;i++,j++){\r\n                        auto x=f[i],y=f[j];\r\n\
    \                        f[i]=x+y; f[j]=(x-y)*w;\r\n                    } w*=irt[__builtin_ctz(++t)];\r\
    \n                }\r\n             } T mul=T(n).inv(); rep(i,0,n)f[i]*=mul;\r\
    \n        }else{\r\n            for(int m=n;m>>=1;){ T w=1;\r\n              \
    \  for(int s=0,t=0;s<n;s+=m*2){\r\n                    for(int i=s,j=s+m;i<s+m;i++,j++){\r\
    \n                        auto x=f[i],y=f[j]*w;\r\n                        f[i]=x+y;\
    \ f[j]=x-y;\r\n                    } w*=rt[__builtin_ctz(++t)];\r\n          \
    \      }\r\n            }\r\n         }\r\n    }\r\n    vector<T> mult(const vector<T>&\
    \ a,const vector<T>& b,bool same=0){\r\n        if(a.empty() or b.empty())return\
    \ vector<T>();\r\n        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);\r\n    \
    \    vector<T> res(m); rep(i,0,a.size()){res[i]=a[i];} ntt(res);\r\n        if(same)rep(i,0,m)res[i]*=res[i];\r\
    \n        else{\r\n            vector<T> c(m); rep(i,0,b.size())c[i]=b[i];\r\n\
    \            ntt(c); rep(i,0,m)res[i]*=c[i];\r\n        } ntt(res,1); res.resize(n);\
    \ return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T,unsigned p=3>struct NTT{\r\n    vector<T>\
    \ rt,irt;\r\n    NTT(int lg=21){\r\n        unsigned m=T::get_mod()-1; T prt=p;\r\
    \n        rt.resize(lg); irt.resize(lg);\r\n        rep(k,0,lg){\r\n         \
    \   rt[k]=-prt.pow(m>>(k+2));\r\n            irt[k]=rt[k].inv();\r\n        }\r\
    \n    }\r\n    void ntt(vector<T>& f,bool inv=0){\r\n        int n=f.size();\r\
    \n        if(inv){\r\n            for(int m=1;m<n;m<<=1){ T w=1;\r\n         \
    \       for(int s=0,t=0;s<n;s+=m*2){\r\n                    for(int i=s,j=s+m;i<s+m;i++,j++){\r\
    \n                        auto x=f[i],y=f[j];\r\n                        f[i]=x+y;\
    \ f[j]=(x-y)*w;\r\n                    } w*=irt[__builtin_ctz(++t)];\r\n     \
    \           }\r\n             } T mul=T(n).inv(); rep(i,0,n)f[i]*=mul;\r\n   \
    \     }else{\r\n            for(int m=n;m>>=1;){ T w=1;\r\n                for(int\
    \ s=0,t=0;s<n;s+=m*2){\r\n                    for(int i=s,j=s+m;i<s+m;i++,j++){\r\
    \n                        auto x=f[i],y=f[j]*w;\r\n                        f[i]=x+y;\
    \ f[j]=x-y;\r\n                    } w*=rt[__builtin_ctz(++t)];\r\n          \
    \      }\r\n            }\r\n         }\r\n    }\r\n    vector<T> mult(const vector<T>&\
    \ a,const vector<T>& b,bool same=0){\r\n        if(a.empty() or b.empty())return\
    \ vector<T>();\r\n        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);\r\n    \
    \    vector<T> res(m); rep(i,0,a.size()){res[i]=a[i];} ntt(res);\r\n        if(same)rep(i,0,m)res[i]*=res[i];\r\
    \n        else{\r\n            vector<T> c(m); rep(i,0,b.size())c[i]=b[i];\r\n\
    \            ntt(c); rep(i,0,m)res[i]*=c[i];\r\n        } ntt(res,1); res.resize(n);\
    \ return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Number Theoretic Transform\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/ntt.hpp
  requiredBy:
  - Convolution/arbitrary.hpp
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Convolution/ntt.hpp
layout: document
redirect_from:
- /library/Convolution/ntt.hpp
- /library/Convolution/ntt.hpp.html
title: Number Theoretic Transform
---
