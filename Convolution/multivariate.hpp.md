---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution.test.cpp
    title: Verify/LC_multivariate_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Multivariate Convolution
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
    \n */\n#line 3 \"Convolution/multivariate.hpp\"\n\r\ntemplate<typename T,void\
    \ (*ntt)(vector<T>&,bool)>vector<T> MultivariateConvolution\r\n    (const vector<T>&\
    \ f,const vector<T>& g,vector<int>& a){\r\n    int n=f.size(),k=a.size(),m=1<<__lg(4*n-1);\r\
    \n    if(k==0)return vector<T>({f[0]*g[0]});\r\n    \r\n    vector<int> chi(n);\r\
    \n    rep(x,0,n){\r\n        int t=x;\r\n        rep(i,0,k-1){\r\n           \
    \ t/=a[i];\r\n            chi[x]+=t;\r\n        }\r\n        chi[x]%=k;\r\n  \
    \  }\r\n\r\n    vector F(k,vector<T>(m)),G(k,vector<T>(m));\r\n    rep(i,0,n){\r\
    \n        F[chi[i]][i]=f[i];\r\n        G[chi[i]][i]=g[i];\r\n    }\r\n\r\n  \
    \  for(auto& v:F)ntt(v,0);\r\n    for(auto& v:G)ntt(v,0);\r\n    rep(x,0,m){\r\
    \n        vector<T> tmp(k);\r\n        rep(i,0,k)rep(j,0,k){\r\n            tmp[(i+j)%k]+=F[i][x]*G[j][x];\r\
    \n        }\r\n        rep(i,0,k)F[i][x]=tmp[i];\r\n    }\r\n    for(auto& v:F)ntt(v,1);\r\
    \n    vector<T> res(n);\r\n    rep(i,0,n)res[i]=F[chi[i]][i];\r\n    return res;\r\
    \n}\r\n\r\n/**\r\n * @brief Multivariate Convolution\r\n */\n"
  code: "#pragma once\r\n#include \"Convolution/ntt.hpp\"\r\n\r\ntemplate<typename\
    \ T,void (*ntt)(vector<T>&,bool)>vector<T> MultivariateConvolution\r\n    (const\
    \ vector<T>& f,const vector<T>& g,vector<int>& a){\r\n    int n=f.size(),k=a.size(),m=1<<__lg(4*n-1);\r\
    \n    if(k==0)return vector<T>({f[0]*g[0]});\r\n    \r\n    vector<int> chi(n);\r\
    \n    rep(x,0,n){\r\n        int t=x;\r\n        rep(i,0,k-1){\r\n           \
    \ t/=a[i];\r\n            chi[x]+=t;\r\n        }\r\n        chi[x]%=k;\r\n  \
    \  }\r\n\r\n    vector F(k,vector<T>(m)),G(k,vector<T>(m));\r\n    rep(i,0,n){\r\
    \n        F[chi[i]][i]=f[i];\r\n        G[chi[i]][i]=g[i];\r\n    }\r\n\r\n  \
    \  for(auto& v:F)ntt(v,0);\r\n    for(auto& v:G)ntt(v,0);\r\n    rep(x,0,m){\r\
    \n        vector<T> tmp(k);\r\n        rep(i,0,k)rep(j,0,k){\r\n            tmp[(i+j)%k]+=F[i][x]*G[j][x];\r\
    \n        }\r\n        rep(i,0,k)F[i][x]=tmp[i];\r\n    }\r\n    for(auto& v:F)ntt(v,1);\r\
    \n    vector<T> res(n);\r\n    rep(i,0,n)res[i]=F[chi[i]][i];\r\n    return res;\r\
    \n}\r\n\r\n/**\r\n * @brief Multivariate Convolution\r\n */"
  dependsOn:
  - Convolution/ntt.hpp
  isVerificationFile: false
  path: Convolution/multivariate.hpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_multivariate_convolution.test.cpp
documentation_of: Convolution/multivariate.hpp
layout: document
redirect_from:
- /library/Convolution/multivariate.hpp
- /library/Convolution/multivariate.hpp.html
title: Multivariate Convolution
---
