---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bitwise_and_convolution.test.cpp
    title: Verify/LC_bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_bitwise_xor_convolution.test.cpp
    title: Verify/LC_bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod.test.cpp
    title: Verify/LC_convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_1000000007.test.cpp
    title: Verify/LC_convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_convolution_mod_2.test.cpp
    title: Verify/LC_convolution_mod_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_exp_of_formal_power_series.test.cpp
    title: Verify/LC_exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_find_linear_recurrence.test.cpp
    title: Verify/LC_find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_inv_of_formal_power_series.test.cpp
    title: Verify/LC_inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
    title: Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_log_of_formal_power_series.test.cpp
    title: Verify/LC_log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_matrix_det.test.cpp
    title: Verify/LC_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_matrix_product.test.cpp
    title: Verify/LC_matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multipoint_evaluation.test.cpp
    title: Verify/LC_multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_multivariate_convolution.test.cpp
    title: Verify/LC_multivariate_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_set_range_composite.test.cpp
    title: Verify/LC_point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_polynomial_interpolation.test.cpp
    title: Verify/LC_polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_polynomial_taylor_shift.test.cpp
    title: Verify/LC_polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_pow_of_formal_power_series.test.cpp
    title: Verify/LC_pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_queue_operate_all_composite.test.cpp
    title: Verify/LC_queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_range_affine_range_sum.test.cpp
    title: Verify/LC_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_subset_convolution.test.cpp
    title: Verify/LC_subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_system_of_linear_equations.test.cpp
    title: Verify/LC_system_of_linear_equations.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_vertex_set_path_composite.test.cpp
    title: Verify/LC_vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Modint
    links: []
  bundledCode: "#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct\
    \ fp {\r\n    int v; static int get_mod(){return mod;}\r\n    int inv() const{\r\
    \n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(int x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
    \ fp()-*this;}\r\n    fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
    \ return res;}\r\n    fp& operator+=(const fp& x){return init(v+x.v);}\r\n   \
    \ fp& operator-=(const fp& x){return init(v+mod-x.v);}\r\n    fp& operator*=(const\
    \ fp& x){v=ll(v)*x.v%mod; return *this;}\r\n    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod;\
    \ return *this;}\r\n    fp operator+(const fp& x)const{return fp(*this)+=x;}\r\
    \n    fp operator-(const fp& x)const{return fp(*this)-=x;}\r\n    fp operator*(const\
    \ fp& x)const{return fp(*this)*=x;}\r\n    fp operator/(const fp& x)const{return\
    \ fp(*this)/=x;}\r\n    bool operator==(const fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const fp& x){return os<<x.v;}\r\n};\r\ntemplate<typename T>struct factorial\
    \ {\r\n    vector<T> Fact,Finv,Inv;\r\n    factorial(int maxx){\r\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\r\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\
    \n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();\r\
    \n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\r\
    \n    }\r\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\r\
    \n    T inv(int n){if(n<0)return 0; return Inv[n];}\r\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\r\n \
    \   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\
    \n    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\
    \n * @brief Modint\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<int mod=1000000007>struct fp {\r\n    int v;\
    \ static int get_mod(){return mod;}\r\n    int inv() const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\
    \n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\n        if(x<0){x+=mod;}\
    \ return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\n    fp& init(int x){v=(x<mod?x:x-mod);\
    \ return *this;}\r\n    fp operator-()const{return fp()-*this;}\r\n    fp pow(ll\
    \ t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return res;}\r\n  \
    \  fp& operator+=(const fp& x){return init(v+x.v);}\r\n    fp& operator-=(const\
    \ fp& x){return init(v+mod-x.v);}\r\n    fp& operator*=(const fp& x){v=ll(v)*x.v%mod;\
    \ return *this;}\r\n    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return\
    \ *this;}\r\n    fp operator+(const fp& x)const{return fp(*this)+=x;}\r\n    fp\
    \ operator-(const fp& x)const{return fp(*this)-=x;}\r\n    fp operator*(const\
    \ fp& x)const{return fp(*this)*=x;}\r\n    fp operator/(const fp& x)const{return\
    \ fp(*this)/=x;}\r\n    bool operator==(const fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const fp& x){return os<<x.v;}\r\n};\r\ntemplate<typename T>struct factorial\
    \ {\r\n    vector<T> Fact,Finv,Inv;\r\n    factorial(int maxx){\r\n        Fact.resize(maxx);\
    \ Finv.resize(maxx); Inv.resize(maxx);\r\n        Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;\r\
    \n        rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();\r\
    \n        for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}\r\
    \n    }\r\n    T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}\r\
    \n    T inv(int n){if(n<0)return 0; return Inv[n];}\r\n    T nPr(int n,int r,bool\
    \ inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}\r\n \
    \   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}\r\
    \n    T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}\r\n};\r\n\r\n/**\r\
    \n * @brief Modint\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/modint.hpp
  requiredBy:
  - Convolution/arbitrary.hpp
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_exp_of_formal_power_series.test.cpp
  - Verify/LC_convolution_mod_1000000007.test.cpp
  - Verify/LC_system_of_linear_equations.test.cpp
  - Verify/LC_log_of_formal_power_series.test.cpp
  - Verify/LC_bitwise_and_convolution.test.cpp
  - Verify/LC_bitwise_xor_convolution.test.cpp
  - Verify/LC_range_affine_range_sum.test.cpp
  - Verify/LC_subset_convolution.test.cpp
  - Verify/LC_polynomial_interpolation.test.cpp
  - Verify/LC_point_set_range_composite.test.cpp
  - Verify/LC_multipoint_evaluation.test.cpp
  - Verify/LC_queue_operate_all_composite.test.cpp
  - Verify/LC_kth_term_of_linearly_recurrent_sequence.test.cpp
  - Verify/LC_find_linear_recurrence.test.cpp
  - Verify/LC_inv_of_formal_power_series.test.cpp
  - Verify/LC_pow_of_formal_power_series.test.cpp
  - Verify/LC_multivariate_convolution.test.cpp
  - Verify/LC_matrix_det.test.cpp
  - Verify/LC_vertex_set_path_composite.test.cpp
  - Verify/LC_polynomial_taylor_shift.test.cpp
  - Verify/LC_convolution_mod.test.cpp
  - Verify/LC_convolution_mod_2.test.cpp
  - Verify/LC_matrix_product.test.cpp
documentation_of: Math/modint.hpp
layout: document
redirect_from:
- /library/Math/modint.hpp
- /library/Math/modint.hpp.html
title: Modint
---
