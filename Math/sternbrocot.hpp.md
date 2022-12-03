---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/fraction.hpp
    title: Fraction
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Stern-Brocot Tree
    links: []
  bundledCode: "#line 2 \"Math/fraction.hpp\"\n\r\nstruct Frac{\r\n    ll a,b;\r\n\
    \    Frac(ll _a=0){init(_a,1);}\r\n    Frac(ll _a,ll _b){init(_a,_b);}\r\n   \
    \ Frac& init(ll _a,ll _b){\r\n        ll g=gcd(_a,_b);\r\n        a=_a/g,b=_b/g;\r\
    \n        if(b<0)a=-a,b=-b;\r\n        return *this;\r\n    }\r\n    Frac inv()const{return\
    \ Frac(b,a);}\r\n    Frac operator-()const{return Frac(-a,b);}\r\n    Frac& operator+=(const\
    \ Frac& x){return init(a*x.b+x.a*b,b*x.b);}\r\n    Frac& operator-=(const Frac&\
    \ x){return init(a*x.b-x.a*b,b*x.b);}\r\n    Frac& operator*=(const Frac& x){return\
    \ init(a*x.a,b*x.b);}\r\n    Frac& operator/=(const Frac& x){return init(a*x.b,b*x.a);}\r\
    \n    Frac operator+(const Frac& x)const{return Frac(*this)+=x;}\r\n    Frac operator-(const\
    \ Frac& x)const{return Frac(*this)-=x;}\r\n    Frac operator*(const Frac& x)const{return\
    \ Frac(*this)*=x;}\r\n    Frac operator/(const Frac& x)const{return Frac(*this)/=x;}\r\
    \n    bool operator<(const Frac& x)const{return a*x.b<b*x.a;}\r\n    bool operator>(const\
    \ Frac& x)const{return x<*this;}\r\n    bool operator<=(const Frac& x)const{return\
    \ !(x<*this);}\r\n    bool operator>=(const Frac& x)const{return !(*this<x);}\r\
    \n    bool operator==(const Frac& x)const{return (*this<=x and x<=*this);}\r\n\
    \    bool operator!=(const Frac& x)const{return !(*this==x);}\r\n};\r\nFrac between(const\
    \ Frac& x,const Frac& y){\r\n    if(x.a<x.b and y.b<y.a)return Frac(1);\r\n  \
    \  else if(x.b<=x.a){\r\n        ll add=floor(x.a/x.b);\r\n        return between(x-add,y-add)+add;\r\
    \n    }\r\n    else return between(y.inv(),x.inv()).inv();\r\n}\r\n\r\n/**\r\n\
    \ * @brief Fraction\r\n * @docs docs/fraction.md\r\n */\n#line 3 \"Math/sternbrocot.hpp\"\
    \n \nstruct SternBrocotTree{\n    // R start\n    static vector<int> encode(Frac\
    \ x){\n        return get(x).first;\n    }\n    static Frac decode(vector<int>&\
    \ v){\n        Frac L(0,1),R(1,0);\n        rep(i,0,v.size()){\n            if(i&1)R=Frac(L.a*v[i]+R.a,L.b*v[i]+R.b);\n\
    \            else L=Frac(R.a*v[i]+L.a,R.b*v[i]+L.b);\n        }\n        return\
    \ Frac(L.a+R.a,L.b+R.b);\n    }\n    static Frac lca(Frac x,Frac y){\n       \
    \ auto px=encode(x),py=encode(y);\n        vector<int> q;\n        rep(i,0,min(px.size(),py.size())){\n\
    \            q.push_back(min(px[i],py[i]));\n            if(q.back()!=px[i] or\
    \ q.back()!=py[i])break;\n        }\n        return decode(q);\n    }\n    static\
    \ pair<Frac,Frac> child(Frac x){\n        auto [L,R]=subtree(x);\n        Frac\
    \ lb(L.a+x.a,L.b+x.b),rb(R.a+x.a,R.b+x.b);\n        return {lb,rb};\n    }\n \
    \   static Frac la(Frac x,ll k){\n        auto path=encode(x);\n        for(;;){\n\
    \            if(path.empty())return Frac(-1,1);\n            if(k<=path.back()){\n\
    \                path.back()-=k;\n                break;\n            }\n    \
    \        else{\n                k=path.back();\n                path.pop_back();\n\
    \            }\n        }\n        return decode(path);\n    }\n    static pair<Frac,Frac>\
    \ subtree(Frac x){\n        return get(x).second;\n    }\nprivate:\n    static\
    \ ll ceil(ll a,ll b){return (a+b-1)/b;}\n    static pair<vector<int>,pair<Frac,Frac>>\
    \ get(Frac& x){\n        Frac L(0,1),R(1,0),mid(1,1);\n        vector<int> path;\n\
    \        for(;;){\n            if(mid==x)break;\n            ll k=ceil(x.a*L.b-x.b*L.a,x.b*R.a-x.a*R.b)-1;\n\
    \            L=Frac(L.a+k*R.a,L.b+k*R.b);\n            mid=Frac(L.a+R.a,L.b+R.b);\n\
    \            path.push_back(k);\n            if(mid==x)break;\n            k=ceil(x.b*R.a-x.a*R.b,x.a*L.b-x.b*L.a)-1;\n\
    \            R=Frac(R.a+k*L.a,R.b+k*L.b);\n            mid=Frac(L.a+R.a,L.b+R.b);\n\
    \            path.push_back(k);\n        }\n        return {path,{L,R}};\n   \
    \ }\n};\n \n/**\n * @brief Stern-Brocot Tree\n */\n"
  code: "#pragma once\n#include \"Math/fraction.hpp\"\n \nstruct SternBrocotTree{\n\
    \    // R start\n    static vector<int> encode(Frac x){\n        return get(x).first;\n\
    \    }\n    static Frac decode(vector<int>& v){\n        Frac L(0,1),R(1,0);\n\
    \        rep(i,0,v.size()){\n            if(i&1)R=Frac(L.a*v[i]+R.a,L.b*v[i]+R.b);\n\
    \            else L=Frac(R.a*v[i]+L.a,R.b*v[i]+L.b);\n        }\n        return\
    \ Frac(L.a+R.a,L.b+R.b);\n    }\n    static Frac lca(Frac x,Frac y){\n       \
    \ auto px=encode(x),py=encode(y);\n        vector<int> q;\n        rep(i,0,min(px.size(),py.size())){\n\
    \            q.push_back(min(px[i],py[i]));\n            if(q.back()!=px[i] or\
    \ q.back()!=py[i])break;\n        }\n        return decode(q);\n    }\n    static\
    \ pair<Frac,Frac> child(Frac x){\n        auto [L,R]=subtree(x);\n        Frac\
    \ lb(L.a+x.a,L.b+x.b),rb(R.a+x.a,R.b+x.b);\n        return {lb,rb};\n    }\n \
    \   static Frac la(Frac x,ll k){\n        auto path=encode(x);\n        for(;;){\n\
    \            if(path.empty())return Frac(-1,1);\n            if(k<=path.back()){\n\
    \                path.back()-=k;\n                break;\n            }\n    \
    \        else{\n                k=path.back();\n                path.pop_back();\n\
    \            }\n        }\n        return decode(path);\n    }\n    static pair<Frac,Frac>\
    \ subtree(Frac x){\n        return get(x).second;\n    }\nprivate:\n    static\
    \ ll ceil(ll a,ll b){return (a+b-1)/b;}\n    static pair<vector<int>,pair<Frac,Frac>>\
    \ get(Frac& x){\n        Frac L(0,1),R(1,0),mid(1,1);\n        vector<int> path;\n\
    \        for(;;){\n            if(mid==x)break;\n            ll k=ceil(x.a*L.b-x.b*L.a,x.b*R.a-x.a*R.b)-1;\n\
    \            L=Frac(L.a+k*R.a,L.b+k*R.b);\n            mid=Frac(L.a+R.a,L.b+R.b);\n\
    \            path.push_back(k);\n            if(mid==x)break;\n            k=ceil(x.b*R.a-x.a*R.b,x.a*L.b-x.b*L.a)-1;\n\
    \            R=Frac(R.a+k*L.a,R.b+k*L.b);\n            mid=Frac(L.a+R.a,L.b+R.b);\n\
    \            path.push_back(k);\n        }\n        return {path,{L,R}};\n   \
    \ }\n};\n \n/**\n * @brief Stern-Brocot Tree\n */\n"
  dependsOn:
  - Math/fraction.hpp
  isVerificationFile: false
  path: Math/sternbrocot.hpp
  requiredBy: []
  timestamp: '2022-12-03 20:46:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/sternbrocot.hpp
layout: document
redirect_from:
- /library/Math/sternbrocot.hpp
- /library/Math/sternbrocot.hpp.html
title: Stern-Brocot Tree
---
