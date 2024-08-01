---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multipoint_evaluation.test.cpp
    title: Verify/LC_multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_polynomial_interpolation.test.cpp
    title: Verify/LC_polynomial_interpolation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Multipoint Evaluation
    links: []
  bundledCode: "#line 2 \"FPS/multieval.hpp\"\n\r\ntemplate<typename T>struct MultiEval{\r\
    \n    int m,n; vector<Poly<T>> t;\r\n    MultiEval(vector<T>& v){\r\n        m=v.size(),n=1;\
    \ while(n<m)n<<=1;\r\n        t.resize(n<<1);\r\n        rep(i,0,n){\r\n     \
    \       T w=(i<m?v[i]:0);\r\n            t[n+i]=Poly<T>({-w,T(1)});\r\n      \
    \  }\r\n        for(int i=n-1;i;i--)t[i]=t[i*2]*t[i*2+1];\r\n    }\r\n    vector<T>\
    \ run(const vector<T>& f){\r\n        if(f.empty())return vector<T>(m);\r\n  \
    \      vector<Poly<T>> c(n*2);\r\n        auto v=t[1].rev();\r\n        v.resize(f.size());\r\
    \n        v=v.inv().rev()*Poly<T>(f);\r\n        v.erase(v.begin(),v.begin()+f.size()-1);\r\
    \n        v.resize(n); reverse(ALL(v)); c[1]=v;\r\n        rep(i,1,n){\r\n   \
    \         int d=c[i].size();\r\n            rep(k,0,2){\r\n                auto\
    \ add=t[i*2+(k^1)];\r\n                add.resize(d/2+1);\r\n                add=add.rev();\r\
    \n                add*=c[i];\r\n                add.resize(d);\r\n           \
    \     c[i*2+k]=vector<T>(add.begin()+d/2,add.end());\r\n            }\r\n    \
    \    }\r\n        vector<T> res(m); rep(i,0,m)res[i]=c[n+i][0];\r\n        return\
    \ res;\r\n    }\r\n    vector<T> build(vector<T>& ys){\r\n        auto w=t[1].rev();\r\
    \n        w.resize(m+1);\r\n        auto vs=run(w.rev().diff());\r\n        rep(i,0,m)ys[i]/=vs[i];\r\
    \n        vector<Poly<T>> c(n*2);\r\n        rep(i,0,n){\r\n            if(i<m)c[n+i]=Poly<T>({ys[i]});\r\
    \n            else c[n+i]=Poly<T>({T()});\r\n        }\r\n        for(int i=n-1;i;i--)c[i]=c[i*2]*t[i*2+1]+c[i*2+1]*t[i*2];\r\
    \n        c[1]=vector<T>(c[1].begin()+(n-m),c[1].end());\r\n        c[1].resize(m);\r\
    \n       return c[1];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Multipoint Evaluation\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct MultiEval{\r\n    int m,n;\
    \ vector<Poly<T>> t;\r\n    MultiEval(vector<T>& v){\r\n        m=v.size(),n=1;\
    \ while(n<m)n<<=1;\r\n        t.resize(n<<1);\r\n        rep(i,0,n){\r\n     \
    \       T w=(i<m?v[i]:0);\r\n            t[n+i]=Poly<T>({-w,T(1)});\r\n      \
    \  }\r\n        for(int i=n-1;i;i--)t[i]=t[i*2]*t[i*2+1];\r\n    }\r\n    vector<T>\
    \ run(const vector<T>& f){\r\n        if(f.empty())return vector<T>(m);\r\n  \
    \      vector<Poly<T>> c(n*2);\r\n        auto v=t[1].rev();\r\n        v.resize(f.size());\r\
    \n        v=v.inv().rev()*Poly<T>(f);\r\n        v.erase(v.begin(),v.begin()+f.size()-1);\r\
    \n        v.resize(n); reverse(ALL(v)); c[1]=v;\r\n        rep(i,1,n){\r\n   \
    \         int d=c[i].size();\r\n            rep(k,0,2){\r\n                auto\
    \ add=t[i*2+(k^1)];\r\n                add.resize(d/2+1);\r\n                add=add.rev();\r\
    \n                add*=c[i];\r\n                add.resize(d);\r\n           \
    \     c[i*2+k]=vector<T>(add.begin()+d/2,add.end());\r\n            }\r\n    \
    \    }\r\n        vector<T> res(m); rep(i,0,m)res[i]=c[n+i][0];\r\n        return\
    \ res;\r\n    }\r\n    vector<T> build(vector<T>& ys){\r\n        auto w=t[1].rev();\r\
    \n        w.resize(m+1);\r\n        auto vs=run(w.rev().diff());\r\n        rep(i,0,m)ys[i]/=vs[i];\r\
    \n        vector<Poly<T>> c(n*2);\r\n        rep(i,0,n){\r\n            if(i<m)c[n+i]=Poly<T>({ys[i]});\r\
    \n            else c[n+i]=Poly<T>({T()});\r\n        }\r\n        for(int i=n-1;i;i--)c[i]=c[i*2]*t[i*2+1]+c[i*2+1]*t[i*2];\r\
    \n        c[1]=vector<T>(c[1].begin()+(n-m),c[1].end());\r\n        c[1].resize(m);\r\
    \n       return c[1];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Multipoint Evaluation\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: FPS/multieval.hpp
  requiredBy: []
  timestamp: '2022-12-26 23:10:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_multipoint_evaluation.test.cpp
  - Verify/LC_polynomial_interpolation.test.cpp
documentation_of: FPS/multieval.hpp
layout: document
redirect_from:
- /library/FPS/multieval.hpp
- /library/FPS/multieval.hpp.html
title: Multipoint Evaluation
---
