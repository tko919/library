---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/dirichlet.hpp
    title: Dirichlet series
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"Verify/LC_sum_of_totient_function.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\
    \nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\n\r\nclass FastIO{\r\
    \n    static constexpr int L=1<<16;\r\n    char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\
    \n    inline void reload(){\r\n        int len=rdRight-rdLeft;\r\n        memmove(rdbuf,rdbuf+rdLeft,len);\r\
    \n        rdLeft=0,rdRight=len;\r\n        rdRight+=fread(rdbuf+len,1,L-len,stdin);\r\
    \n    }\r\n    inline bool skip(){\r\n        for(;;){\r\n            while(rdLeft!=rdRight\
    \ and rdbuf[rdLeft]<=' ')rdLeft++;\r\n            if(rdLeft==rdRight){\r\n   \
    \             reload();\r\n                if(rdLeft==rdRight)return false;\r\n\
    \            }\r\n            else break;\r\n        }\r\n        return true;\r\
    \n    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdLeft<rdRight){\r\n            x=x*10+(neg?-(rdbuf[rdLeft++]^48):(rdbuf[rdLeft++]^48));\r\
    \n        }\r\n        return true;\r\n    }\r\n    template<typename T,enable_if_t<is_floating_point<T>::value,int>\
    \ =0>inline bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9' and rdLeft<rdRight){\r\n            x=x*10+(rdbuf[rdLeft++]^48);\r\
    \n        }\r\n        if(rdbuf[rdLeft]!='.')return true;\r\n        rdLeft++;\r\
    \n        T base=.1;\r\n        while(rdbuf[rdLeft]>='0' and rdbuf[rdLeft]<='9'\
    \ and rdLeft<rdRight){\r\n            x+=base*(rdbuf[rdLeft++]^48);\r\n      \
    \      base*=.1;\r\n        }\r\n        if(neg)x=-x;\r\n        return true;\r\
    \n    }\r\n    inline bool _read(char& x){\r\n        if(!skip())return false;\r\
    \n        if(rdLeft+1>=rdRight)reload();\r\n        x=rdbuf[rdLeft++];\r\n   \
    \     return true;\r\n    }\r\n    inline bool _read(string& x){\r\n        if(!skip())return\
    \ false;\r\n        for(;;){\r\n            int pos=rdLeft;\r\n            while(pos<rdRight\
    \ and rdbuf[pos]>' ')pos++;\r\n            x.append(rdbuf+rdLeft,pos-rdLeft);\r\
    \n            if(rdLeft==pos)break;\r\n            rdLeft=pos;\r\n           \
    \ if(rdLeft==rdRight)reload();\r\n            else break;\r\n        }\r\n   \
    \     return true;\r\n    }\r\n    template<typename T>inline bool _read(vector<T>&\
    \ v){\r\n        for(auto& x:v){\r\n            if(!_read(x))return false;\r\n\
    \        }\r\n        return true;\r\n    }\r\n\r\n    char wtbuf[L],tmp[50];\r\
    \n    int wtRight=0;\r\n    inline void flush(){\r\n        fwrite(wtbuf,1,wtRight,stdout);\r\
    \n        wtRight=0;\r\n    }\r\n    inline void _write(const char& x){\r\n  \
    \      if(wtRight>L-32)flush();\r\n        wtbuf[wtRight++]=x;\r\n    }\r\n  \
    \  inline void _write(const string& x){\r\n        for(auto& c:x)_write(c);\r\n\
    \    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ void _write(T x){\r\n        if(wtRight>L-32)flush();\r\n        if(x==0){\r\
    \n            _write('0');\r\n            return;\r\n        }\r\n        else\
    \ if(x<0){\r\n            _write('-');\r\n            if (__builtin_expect(x ==\
    \ std::numeric_limits<T>::min(), 0)) {\r\n                switch (sizeof(x)) {\r\
    \n                case 2: _write(\"32768\"); return;\r\n                case 4:\
    \ _write(\"2147483648\"); return;\r\n                case 8: _write(\"9223372036854775808\"\
    ); return;\r\n                }\r\n            }\r\n            x=-x;\r\n    \
    \    }\r\n        int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
    \n            x/=10;\r\n        }\r\n        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];\r\
    \n        wtRight+=pos;\r\n    }\r\n    template<typename T>inline void _write(const\
    \ vector<T>& v){\r\n        rep(i,0,v.size()){\r\n            if(i)_write(' ');\r\
    \n            _write(v[i]);\r\n        }\r\n    }\r\npublic:\r\n    FastIO(){}\r\
    \n    ~FastIO(){flush();}\r\n    inline void read(){}\r\n    template <typename\
    \ Head, typename... Tail>inline void read(Head& head,Tail&... tail){\r\n     \
    \   assert(_read(head));\r\n        read(tail...); \r\n    }\r\n    template<bool\
    \ ln=true,bool space=false>inline void write(){if(ln)_write('\\n');}\r\n    template\
    \ <bool ln=true,bool space=false,typename Head, typename... Tail>inline void write(const\
    \ Head& head,const Tail&... tail){\r\n        if(space)_write(' ');\r\n      \
    \  _write(head);\r\n        write<ln,true>(tail...); \r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_sum_of_totient_function.test.cpp\"\
    \n\r\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp {\r\
    \n    int v; static int get_mod(){return mod;}\r\n    int inv() const{\r\n   \
    \     int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(int x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
    \ fp()-*this;}\r\n    fp pow(ll t){assert(t>=0); fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}\
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
    \n * @brief Modint\r\n */\n#line 7 \"Verify/LC_sum_of_totient_function.test.cpp\"\
    \nusing Fp=fp<998244353>;\r\n#line 2 \"Math/dirichlet.hpp\"\n\r\ntemplate<typename\
    \ T,bool multi,unsigned L=1010101010>struct Dirichlet{\r\n    ll N,P,Q;\r\n  \
    \  vector<T> a,rui,A;\r\n    vector<ll> ps;\r\n    bool done=0;\r\n    Dirichlet(ll\
    \ n):N(n),P(min<ll>(L,cbrt(n)*cbrt(n))),Q((n+P-1)/P),\r\n        a(P+1),rui(P+1),A(Q+1),done(0){}\r\
    \n    const Dirichlet ident(){\r\n        Dirichlet res(N);\r\n        res.a.assign(P+1,0);\r\
    \n        res.a[1]=1;\r\n        res.rui.assign(P+1,1);\r\n        res.A.assign(Q+1,1);\r\
    \n        res.done=1;\r\n        return res;\r\n    }\r\n    void sieve(){\r\n\
    \        if(!ps.empty())return;\r\n        static bitset<L> isp;\r\n        rep(p,2,P+1)isp[p]=1;\r\
    \n        for(ll p=2;p*p<=P;p++)if(isp[p]){\r\n            for(ll q=p*p;q<=P;q+=p)isp[q]=0;\r\
    \n        }\r\n        rep(p,2,P+1)if(isp[p])ps.push_back(p);\r\n    }\r\n   \
    \ void reset(){\r\n        a.assign(P+1,0);\r\n        rui.assign(P+1,0);\r\n\
    \        A.assign(Q+1,0);\r\n        done=0;\r\n    }\r\n    void ruith(){\r\n\
    \        rui.assign(P+1,0);\r\n        rep(i,1,P+1)rui[i]=rui[i-1]+a[i];\r\n \
    \       done=1;\r\n    }\r\n    Dirichlet operator*(const Dirichlet& x){\r\n \
    \       assert(done and x.done);\r\n        Dirichlet res(N);\r\n        if(multi){\r\
    \n            sieve();\r\n            res.a=a;\r\n            for(auto& p:ps){\r\
    \n                for(ll i=P/p;i>0;i--){\r\n                    ll n=p*i,q=p,m=i;\r\
    \n                    for(;;){\r\n                        res.a[n]+=x.a[q]*res.a[m];\r\
    \n                        if(m%p)break;\r\n                        q*=p,m/=p;\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        else{\r\n            rep(i,1,P+1)rep(j,1,P/i+1){\r\n                res.a[i*j]+=a[i]*x.a[j];\r\
    \n            }\r\n        }\r\n        res.ruith();\r\n        rep(i,1,Q+1){\r\
    \n            ll n=N/i,M=int(sqrt(n));\r\n            rep(j,1,M+1){\r\n      \
    \          if(n/j<=P)res.A[i]+=a[j]*x.rui[n/j]+x.a[j]*rui[n/j];\r\n          \
    \      else res.A[i]+=a[j]*x.A[i*j]+x.a[j]*A[i*j];\r\n                if(M<=P)res.A[i]-=x.a[j]*rui[M];\r\
    \n                else res.A[i]-=x.a[j]*A[N/M];\r\n            }\r\n        }\r\
    \n        return res;\r\n    }\r\n    Dirichlet operator/(const Dirichlet& x){\r\
    \n        assert(done and x.done);\r\n        Dirichlet res=*this;\r\n       \
    \ if(multi){\r\n            sieve();\r\n            for(auto& p:ps){\r\n     \
    \           rep(i,1,P/p+1){\r\n                    int n=p*i,q=p,m=i;\r\n    \
    \                for(;;){\r\n                        res.a[n]-=x.a[q]*res.a[m];\r\
    \n                        if(m%p)break;\r\n                        q*=p,m/=p;\r\
    \n                    }\r\n                }\r\n            }\r\n        }\r\n\
    \        else{\r\n            rep(i,1,P)rep(j,2,P/i+1){\r\n                res.a[i*j]-=res.a[i]*x.a[j];\r\
    \n            }\r\n        }\r\n        res.ruith();\r\n        for(int i=Q;i>0;i--){\r\
    \n            ll n=N/i,M=int(sqrt(n));\r\n            rep(j,1,M+1){\r\n      \
    \          if(n/j<=P){\r\n                    if(j!=1)res.A[i]-=x.a[j]*res.rui[n/j];\r\
    \n                    res.A[i]-=res.a[j]*x.rui[n/j];\r\n                }\r\n\
    \                else{\r\n                    if(j!=1)res.A[i]-=x.a[j]*res.A[i*j];\r\
    \n                    res.A[i]-=res.a[j]*x.A[i*j];\r\n                }\r\n  \
    \              if(M<=P)res.A[i]+=res.a[j]*x.rui[M];\r\n                else res.A[i]+=res.a[j]*x.A[N/M];\r\
    \n            }\r\n        }\r\n        return res;\r\n    }\r\n    Dirichlet\
    \ pow(ll t){\r\n        assert(done);\r\n        Dirichlet res=ident(),b=*this;\r\
    \n        while(t){\r\n           if(t&1)res=res*b;\r\n           b=b*b;\r\n \
    \          t>>=1;\r\n        }\r\n        return res;\r\n    }\r\n    const T&\
    \ operator[](ll x){\r\n        assert(done);\r\n        if(x<=P)return rui[x];\r\
    \n        else return A[N/x];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Dirichlet\
    \ series\r\n */\n#line 9 \"Verify/LC_sum_of_totient_function.test.cpp\"\n\r\n\r\
    \nFastIO io;\r\nint main(){\r\n    ll n;\r\n    io.read(n);\r\n    \r\n    Dirichlet<Fp,1>\
    \ phi(n),one(n);\r\n    rep(d,1,phi.P+1)phi.a[d]=d;\r\n    rep(d,1,phi.Q+1){\r\
    \n        Fp x=n/d;\r\n        phi.A[d]=x*(x+1)/2;\r\n    }\r\n    rep(d,1,one.P+1)one.a[d]=1;\r\
    \n    rep(d,1,one.Q+1)one.A[d]=n/d;\r\n    phi.ruith();\r\n    one.ruith();\r\n\
    \    \r\n    phi=phi/one;\r\n    cout<<phi[n]<<'\\n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n\r\n#include \"Math/modint.hpp\"\r\nusing Fp=fp<998244353>;\r\n#include \"Math/dirichlet.hpp\"\
    \r\n\r\n\r\nFastIO io;\r\nint main(){\r\n    ll n;\r\n    io.read(n);\r\n    \r\
    \n    Dirichlet<Fp,1> phi(n),one(n);\r\n    rep(d,1,phi.P+1)phi.a[d]=d;\r\n  \
    \  rep(d,1,phi.Q+1){\r\n        Fp x=n/d;\r\n        phi.A[d]=x*(x+1)/2;\r\n \
    \   }\r\n    rep(d,1,one.P+1)one.a[d]=1;\r\n    rep(d,1,one.Q+1)one.A[d]=n/d;\r\
    \n    phi.ruith();\r\n    one.ruith();\r\n    \r\n    phi=phi/one;\r\n    cout<<phi[n]<<'\\\
    n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - Math/dirichlet.hpp
  isVerificationFile: true
  path: Verify/LC_sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2022-10-24 03:26:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_sum_of_totient_function.test.cpp
- /verify/Verify/LC_sum_of_totient_function.test.cpp.html
title: Verify/LC_sum_of_totient_function.test.cpp
---
