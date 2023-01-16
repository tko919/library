---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariate.hpp
    title: Multivariate Convolution
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multivariate_convolution
    links:
    - https://judge.yosupo.jp/problem/multivariate_convolution
  bundledCode: "#line 1 \"Verify/LC_multivariate_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/multivariate_convolution\"\r\n\r\n#line 1\
    \ \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v)\
    \ (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Math/modint.hpp\"\
    \n\r\ntemplate<int mod=1000000007>struct fp {\r\n    int v;\r\n    static constexpr\
    \ int get_mod(){return mod;}\r\n    int inv() const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\
    \n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\n        if(x<0){x+=mod;}\
    \ return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\n    fp& init(ll x){v=(x<mod?x:x-mod);\
    \ return *this;}\r\n    fp operator-()const{return fp()-*this;}\r\n    fp pow(ll\
    \ t){assert(t>=0); fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return\
    \ res;}\r\n    fp& operator+=(const fp& x){return init(v+x.v);}\r\n    fp& operator-=(const\
    \ fp& x){return init(v+mod-x.v);}\r\n    fp& operator*=(const fp& x){v=ll(v)*x.v%mod;\
    \ return *this;}\r\n    fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return\
    \ *this;}\r\n    fp operator+(const fp& x)const{return fp(*this)+=x;}\r\n    fp\
    \ operator-(const fp& x)const{return fp(*this)-=x;}\r\n    fp operator*(const\
    \ fp& x)const{return fp(*this)*=x;}\r\n    fp operator/(const fp& x)const{return\
    \ fp(*this)/=x;}\r\n    bool operator==(const fp& x)const{return v==x.v;}\r\n\
    \    bool operator!=(const fp& x)const{return v!=x.v;}\r\n    friend istream&\
    \ operator>>(istream& is,fp& x){return is>>x.v;}\r\n    friend ostream& operator<<(ostream&\
    \ os,const fp& x){return os<<x.v;}\r\n};\r\n\r\n/**\r\n * @brief Modint\r\n */\n\
    #line 2 \"Convolution/ntt.hpp\"\n\r\ntemplate<typename T,unsigned p=3>struct NTT{\r\
    \n    vector<T> rt,irt;\r\n    NTT(int lg=21){\r\n        unsigned m=T::get_mod()-1;\
    \ T prt=p;\r\n        rt.resize(lg); irt.resize(lg);\r\n        rep(k,0,lg){\r\
    \n            rt[k]=-prt.pow(m>>(k+2));\r\n            irt[k]=rt[k].inv();\r\n\
    \        }\r\n    }\r\n    void ntt(vector<T>& f,bool inv=0){\r\n        int n=f.size();\r\
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
    \n}\r\n\r\n/**\r\n * @brief Multivariate Convolution\r\n */\n#line 7 \"Verify/LC_multivariate_convolution.test.cpp\"\
    \n\r\nusing Fp=fp<998244353>;\r\nNTT<Fp,3> ntt;\r\nvoid F(vector<Fp>& a,bool f){ntt.ntt(a,f);}\r\
    \n\r\nint main(){\r\n    int k,n=1;\r\n    cin>>k;\r\n    vector<int> a(k);\r\n\
    \    rep(i,0,k){\r\n        cin>>a[i];\r\n        n*=a[i];\r\n    }\r\n    vector<Fp>\
    \ f(n),g(n);\r\n    rep(i,0,n)cin>>f[i];\r\n    rep(i,0,n)cin>>g[i];\r\n\r\n \
    \   auto res=MultivariateConvolution<Fp,F>(f,g,a);\r\n    for(auto& x:res)cout<<x<<'\\\
    n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multivariate_convolution\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Math/modint.hpp\"\r\n\
    #include \"Convolution/ntt.hpp\"\r\n#include \"Convolution/multivariate.hpp\"\r\
    \n\r\nusing Fp=fp<998244353>;\r\nNTT<Fp,3> ntt;\r\nvoid F(vector<Fp>& a,bool f){ntt.ntt(a,f);}\r\
    \n\r\nint main(){\r\n    int k,n=1;\r\n    cin>>k;\r\n    vector<int> a(k);\r\n\
    \    rep(i,0,k){\r\n        cin>>a[i];\r\n        n*=a[i];\r\n    }\r\n    vector<Fp>\
    \ f(n),g(n);\r\n    rep(i,0,n)cin>>f[i];\r\n    rep(i,0,n)cin>>g[i];\r\n\r\n \
    \   auto res=MultivariateConvolution<Fp,F>(f,g,a);\r\n    for(auto& x:res)cout<<x<<'\\\
    n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Math/modint.hpp
  - Convolution/ntt.hpp
  - Convolution/multivariate.hpp
  isVerificationFile: true
  path: Verify/LC_multivariate_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_multivariate_convolution.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_multivariate_convolution.test.cpp
- /verify/Verify/LC_multivariate_convolution.test.cpp.html
title: Verify/LC_multivariate_convolution.test.cpp
---
