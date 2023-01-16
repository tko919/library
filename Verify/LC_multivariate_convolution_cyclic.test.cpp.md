---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Convolution/arbitrary.hpp
    title: Arbitrary Mod Convolution
  - icon: ':heavy_check_mark:'
    path: Convolution/multivariatecyclic.hpp
    title: Multivarate Convolution Cyclic
  - icon: ':heavy_check_mark:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: FPS/arbitraryfps.hpp
    title: Formal Power Series (Arbitrary mod)
  - icon: ':heavy_check_mark:'
    path: FPS/multievalgeom.hpp
    title: Multipoint Evaluation on Geometric Sequence
  - icon: ':heavy_check_mark:'
    path: Math/dynamic.hpp
    title: Dynamic Modint
  - icon: ':heavy_check_mark:'
    path: Math/fastdiv.hpp
    title: Math/fastdiv.hpp
  - icon: ':heavy_check_mark:'
    path: Math/miller.hpp
    title: Miller-Rabin
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':heavy_check_mark:'
    path: Math/pollard.hpp
    title: Pollard-Rho
  - icon: ':heavy_check_mark:'
    path: Math/primitive.hpp
    title: Primitive Function
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/fastio.hpp
    title: Fast IO
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multivariate_convolution_cyclic
    links:
    - https://judge.yosupo.jp/problem/multivariate_convolution_cyclic
  bundledCode: "#line 1 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/multivariate_convolution_cyclic\"\n\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\
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
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\n\r\nclass FastIO{\r\n    static constexpr int L=1<<16;\r\
    \n    char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\
    \n        int len=rdRight-rdLeft;\r\n        memmove(rdbuf,rdbuf+rdLeft,len);\r\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\
    \n\n#line 2 \"Math/fastdiv.hpp\"\n\nstruct FastDiv{\n    using u64=uint64_t;\n\
    \    using u128=__uint128_t;\n    constexpr FastDiv():m(),s(),x(){}\n    constexpr\
    \ FastDiv(int _m)\n        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}\n\
    \    constexpr int get(){return m;}\n    constexpr friend u64 operator/(u64 n,const\
    \ FastDiv& d){\n        return (u128(n)*d.x>>d.s)>>64;\n    }\n    constexpr friend\
    \ int operator%(u64 n,const FastDiv& d){\n        return n-n/d*d.m;\n    }\n \
    \   constexpr pair<u64,int> divmod(u64 n)const{\n        u64 q=n/(*this);\n  \
    \      return {q,n-q*m};\n    }\n    int m,s; u64 x;\n};\n\n/**\n * Fast Division\n\
    */\n#line 3 \"Math/dynamic.hpp\"\n\r\nstruct Fp{\r\n    using u64=uint64_t;\r\n\
    \    int v;\r\n    static int get_mod(){return _getmod();}\r\n    static void\
    \ set_mod(int _m){bar=FastDiv(_m);}\r\n    Fp inv() const{\r\n        int tmp,a=v,b=get_mod(),x=1,y=0;\r\
    \n        while(b){\r\n            tmp=a/b,a-=tmp*b;\r\n            swap(a,b);\r\
    \n            x-=tmp*y;\r\n            swap(x,y);\r\n        }\r\n        if(x<0){x+=get_mod();}\r\
    \n        return x;\r\n    }\r\n    Fp():v(0){}\r\n    Fp(ll x){\r\n        v=x%get_mod();\r\
    \n        if(v<0)v+=get_mod();\r\n    }\r\n    Fp operator-()const{return Fp()-*this;}\r\
    \n    Fp pow(ll t){\r\n        assert(t>=0);\r\n        Fp res=1,b=*this;\r\n\
    \        while(t){\r\n            if(t&1)res*=b;\r\n            b*=b;\r\n    \
    \        t>>=1;\r\n        }\r\n        return res;\r\n    }\r\n    Fp& operator+=(const\
    \ Fp& x){\r\n        v+=x.v;\r\n        if(v>=get_mod())v-=get_mod();\r\n    \
    \    return *this;\r\n    }\r\n    Fp& operator-=(const Fp& x){\r\n        v+=get_mod()-x.v;\r\
    \n        if(v>=get_mod())v-=get_mod();\r\n        return *this;\r\n    }\r\n\
    \    Fp& operator*=(const Fp& x){\r\n        v=(u64(v)*x.v)%bar;\r\n        return\
    \ *this;\r\n    }\r\n    Fp& operator/=(const Fp& x){\r\n        (*this)*=x.inv();\r\
    \n        return *this;\r\n    }\r\n    Fp operator+(const Fp& x)const{return\
    \ Fp(*this)+=x;}\r\n    Fp operator-(const Fp& x)const{return Fp(*this)-=x;}\r\
    \n    Fp operator*(const Fp& x)const{return Fp(*this)*=x;}\r\n    Fp operator/(const\
    \ Fp& x)const{return Fp(*this)/=x;}\r\n    bool operator==(const Fp& x)const{return\
    \ v==x.v;}\r\n    bool operator!=(const Fp& x)const{return v!=x.v;}\r\nprivate:\r\
    \n    static FastDiv bar;\r\n    static int _getmod(){return bar.get();}\r\n};\r\
    \nFastDiv Fp::bar(998244353);\r\n\r\n/**\r\n * @brief Dynamic Modint\r\n */\n\
    #line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp {\r\n \
    \   int v;\r\n    static constexpr int get_mod(){return mod;}\r\n    int inv()\
    \ const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
    \n        if(x<0){x+=mod;} return x;\r\n    }\r\n    fp(ll x=0){init(x%mod+mod);}\r\
    \n    fp& init(ll x){v=(x<mod?x:x-mod); return *this;}\r\n    fp operator-()const{return\
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
    \n */\n#line 4 \"Convolution/arbitrary.hpp\"\n\r\nusing M1=fp<1045430273>; using\
    \ M2=fp<1051721729>; using M3=fp<1053818881>;\r\nNTT<fp<1045430273>,3> N1; NTT<fp<1051721729>,6>\
    \ N2; NTT<fp<1053818881>,7> N3;\r\nconst M2 r_12=M2(M1::get_mod()).inv();\r\n\
    const M3 r_13=M3(M1::get_mod()).inv();\r\nconst M3 r_23=M3(M2::get_mod()).inv();\r\
    \nconst M3 r_1323=r_13*r_23;\r\ntemplate<typename T>vector<T> ArbitraryMult(const\
    \ vector<T>& a,const vector<T>& b,bool same=0){\r\n    if(a.empty() or b.empty())return\
    \ vector<T>();\r\n    int n=a.size()+b.size()-1; vector<T> res(n);\r\n    if(min(a.size(),b.size())<=60){\r\
    \n        rep(i,0,a.size())rep(j,0,b.size())res[i+j]+=a[i]*b[j];\r\n        return\
    \ res;\r\n    }\r\n    vector<int> vals[3];\r\n    vector<int> aa(a.size()),bb(b.size());\r\
    \n    rep(i,0,a.size())aa[i]=a[i].v; rep(i,0,b.size())bb[i]=b[i].v;\r\n    vector<M1>\
    \ a1(ALL(aa)),b1(ALL(bb)),c1=N1.mult(a1,b1,same);\r\n    vector<M2> a2(ALL(aa)),b2(ALL(bb)),c2=N2.mult(a2,b2,same);\r\
    \n    vector<M3> a3(ALL(aa)),b3(ALL(bb)),c3=N3.mult(a3,b3,same);\r\n    for(M1\
    \ x:c1)vals[0].push_back(x.v);\r\n    for(M2 x:c2)vals[1].push_back(x.v);\r\n\
    \    for(M3 x:c3)vals[2].push_back(x.v);\r\n    T w1(M1::get_mod()),w2=w1*T(M2::get_mod());\r\
    \n    rep(i,0,n){\r\n        ll p=vals[0][i];\r\n        ll q=(vals[1][i]+M2::get_mod()-p)*r_12.v%M2::get_mod();\r\
    \n        ll r=((vals[2][i]+M3::get_mod()-p)*r_1323.v+\r\n            (M3::get_mod()-q)*r_23.v)%M3::get_mod();\r\
    \n        res[i]=(p+q*w1.v+r*w2.v);\r\n    } return res;\r\n}\r\n\r\n/**\r\n *\
    \ @brief Arbitrary Mod Convolution\r\n */\n#line 2 \"FPS/arbitraryfps.hpp\"\n\r\
    \ntemplate<typename T>struct Poly:vector<T>{\r\n    Poly(int n=0){this->assign(n,T());}\r\
    \n    Poly(const vector<T>& f){this->assign(ALL(f));}\r\n    T eval(const T& x){\r\
    \n        T res;\r\n        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);\r\
    \n        return res;\r\n    }\r\n    Poly rev()const{Poly res=*this; reverse(ALL(res));\
    \ return res;}\r\n    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}\r\
    \n    Poly inv()const{\r\n        assert(this->front()!=0); const int n=this->size();\r\
    \n        Poly res(1); res.front()=T(1)/this->front();\r\n        for(int k=1;k<n;k<<=1){\r\
    \n            Poly g=res,h=*this; h.resize(k*2); res.resize(k*2);\r\n        \
    \    g=(g.square()*h); g.resize(k*2);\r\n            rep(i,k,min(k*2,n))res[i]-=g[i];\r\
    \n        }\r\n        res.resize(n); return res;\r\n    }\r\n    Poly square()const{return\
    \ Poly(mult(*this,*this,1));}\r\n    Poly operator+(const Poly& g)const{return\
    \ Poly(*this)+=g;}\r\n    Poly operator+(const T& g)const{return Poly(*this)+=g;}\r\
    \n    Poly operator-(const Poly& g)const{return Poly(*this)-=g;}\r\n    Poly operator-(const\
    \ T& g)const{return Poly(*this)-=g;}\r\n    Poly operator*(const Poly& g)const{return\
    \ Poly(*this)*=g;}\r\n    Poly operator*(const T& g)const{return Poly(*this)*=g;}\r\
    \n    Poly operator/(const Poly& g)const{return Poly(*this)/=g;}\r\n    Poly operator%(const\
    \ Poly& g)const{return Poly(*this)%=g;}\r\n    Poly& operator+=(const Poly& g){\r\
    \n        if(g.size()>this->size())this->resize(g.size());\r\n        rep(i,0,g.size()){(*this)[i]+=g[i];}\
    \ return *this;\r\n    }\r\n    Poly& operator+=(const T& g){\r\n        if(this->empty())this->push_back(0);\r\
    \n        (*this)[0]+=g; return *this;\r\n    }\r\n    Poly& operator-=(const\
    \ Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\n  \
    \      rep(i,0,g.size()){(*this)[i]-=g[i];} return *this;\r\n    }\r\n    Poly&\
    \ operator-=(const T& g){\r\n        if(this->empty())this->push_back(0);\r\n\
    \        (*this)[0]-=g; return *this;\r\n    }\r\n    Poly& operator*=(const Poly&\
    \ g){\r\n        *this=mult(*this,g,0);\r\n        return *this;\r\n    }\r\n\
    \    Poly& operator*=(const T& g){\r\n        rep(i,0,this->size())(*this)[i]*=g;\r\
    \n        return *this;\r\n    }\r\n    Poly& operator/=(const Poly& g){\r\n \
    \       if(g.size()>this->size()){\r\n            this->clear(); return *this;\r\
    \n        }\r\n        Poly g2=g;\r\n        reverse(ALL(*this));\r\n        reverse(ALL(g2));\r\
    \n        int n=this->size()-g2.size()+1;\r\n        this->resize(n); g2.resize(n);\r\
    \n        *this*=g2.inv(); this->resize(n); \r\n        reverse(ALL(*this));\r\
    \n        shrink();\r\n        return *this;\r\n    }\r\n    Poly& operator%=(const\
    \ Poly& g){*this-=*this/g*g; shrink(); return *this;}\r\n    Poly diff()const{\r\
    \n        Poly res(this->size()-1);\r\n        rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);\r\
    \n        return res;\r\n    }\r\n    Poly inte()const{\r\n        Poly res(this->size()+1);\r\
    \n        for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]/i;\r\n        return\
    \ res;\r\n    }\r\n    Poly log()const{\r\n        assert(this->front()==1); const\
    \ int n=this->size();\r\n        Poly res=diff()*inv(); res=res.inte(); \r\n \
    \       res.resize(n); return res;\r\n    }\r\n    Poly exp()const{\r\n      \
    \  assert(this->front()==0); const int n=this->size();\r\n        Poly res(1),g(1);\
    \ res.front()=g.front()=1;\r\n        for(int k=1;k<n;k<<=1){\r\n            g=(g+g-g.square()*res);\
    \ g.resize(k);\r\n            Poly q=*this; q.resize(k); q=q.diff();\r\n     \
    \       Poly w=(q+g*(res.diff()-res*q)),t=*this;\r\n            w.resize(k*2-1);\
    \ t.resize(k*2);\r\n            res=(res+res*(t-w.inte())); res.resize(k*2);\r\
    \n        } res.resize(n); return res;\r\n    }\r\n    Poly shift(const int& c)const{\r\
    \n        const int n=this->size();\r\n        Poly res=*this,g(n); g[0]=1; rep(i,1,n)g[i]=g[i-1]*c/i;\r\
    \n        vector<T> fact(n,1);\r\n        rep(i,0,n){\r\n            if(i)fact[i]=fact[i-1]*i;\r\
    \n            res[i]*=fact[i];\r\n        }\r\n        res=res.rev();\r\n    \
    \    res*=g;\r\n        res.resize(n);\r\n        res=res.rev();\r\n        rep(i,0,n)res[i]/=fact[i];\r\
    \n        return res;\r\n    }\r\n    Poly pow(ll t){\r\n        if(t==0){\r\n\
    \            Poly res(this->size()); res[0]=1;\r\n            return res;\r\n\
    \        }\r\n        int n=this->size(),k=0; while(k<n and (*this)[k]==0)k++;\r\
    \n        Poly res(n); if(__int128_t(t)*k>=n)return res;\r\n        n-=t*k; Poly\
    \ g(n); T c=(*this)[k],ic=c.inv();\r\n        rep(i,0,n)g[i]=(*this)[i+k]*ic;\r\
    \n        g=g.log(); for(auto& x:g)x*=t; g=g.exp();\r\n        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c;\
    \ return res;\r\n    }\r\n    vector<T> mult(const vector<T>& a,const vector<T>&\
    \ b,bool same)const;\r\n};\r\n\r\n/**\r\n * @brief Formal Power Series (Arbitrary\
    \ mod)\r\n */\n#line 9 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\n\
    template<>vector<Fp> Poly<Fp>::mult(const vector<Fp>& a,const vector<Fp>& b,bool\
    \ same)const{\n    return ArbitraryMult(a,b,same);\n}\n#line 2 \"Math/miller.hpp\"\
    \n\r\nbool Miller(ll n){\r\n    if(n<2 or (n&1)==0)return (n==2);\r\n    ll d=n-1;\
    \ while((d&1)==0)d>>=1;\r\n    vector<ll> seeds;\r\n    auto MP=[&](ll x,ll t,ll\
    \ m)->ll{\r\n        ll res=1;\r\n        while(t){\r\n            if(t&1)res=(__int128_t(res)*x)%m;\r\
    \n            x=(__int128_t(x)*x)%m; t>>=1;\r\n        } return res;\r\n    };\r\
    \n    if(n<(1<<30))seeds={2, 7, 61};\r\n    else seeds={2, 325, 9375, 28178, 450775,\
    \ 9780504};\r\n    for(auto& x:seeds){\r\n        if(n<=x)break;\r\n        ll\
    \ t=d,y=MP(x,t,n);\r\n        while(t!=n-1 and y!=1 and y!=n-1){\r\n         \
    \   y=(__int128_t(y)*y)%n; t<<=1;\r\n        }\r\n        if(y!=n-1 and (t&1)==0)return\
    \ 0;\r\n    } return 1;\r\n}\r\n\r\n/**\r\n * @brief Miller-Rabin\r\n */\n#line\
    \ 2 \"Utility/random.hpp\"\n\r\nstruct Random{\r\n    random_device rnd;\r\n \
    \   unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\n\
    \    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\
    \n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n    unsigned get(unsigned\
    \ L){\r\n        return get()%(L+1);\r\n    }\r\n    template<typename T>T get(T\
    \ L,T R){\r\n        return get(R-L)+L;\r\n    }\r\n    double uniform(){\r\n\
    \        return double(get())/UINT_MAX;\r\n    }\r\n    string str(int n){\r\n\
    \        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\n        return\
    \ ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter first,Iter last){\r\
    \n        if(first==last)return;\r\n        int len=1;\r\n        for(auto it=first+1;it!=last;it++){\r\
    \n            len++;\r\n            int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\
    \n        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 4 \"Math/pollard.hpp\"\n\r\nRandom genPollard;\r\nvector<ll> Pollard(ll\
    \ n){\r\n    if(n<=1)return {};\r\n    if(Miller(n))return {n};\r\n    if((n&1)==0){\r\
    \n        vector<ll> v=Pollard(n>>1); v.push_back(2);\r\n        return v;\r\n\
    \    }\r\n    for(ll x=2,y=2,d;;){\r\n        ll c=genPollard.get(2LL,n-1);\r\n\
    \        do{\r\n            x=(__int128_t(x)*x+c)%n;\r\n            y=(__int128_t(y)*y+c)%n;\r\
    \n            y=(__int128_t(y)*y+c)%n;\r\n            d=__gcd(x-y+n,n);\r\n  \
    \      }while(d==1);\r\n        if(d<n){\r\n            vector<ll> lb=Pollard(d),rb=Pollard(n/d);\r\
    \n            lb.insert(lb.end(),ALL(rb)); return lb;\r\n        }\r\n    }\r\n\
    }\r\n\r\n/**\r\n * @brief Pollard-Rho\r\n */\n#line 4 \"Math/primitive.hpp\"\n\
    \r\nll mpow(ll a,ll t,ll m){\r\n    ll res=1;\r\n    FastDiv im(m);\r\n    while(t){\r\
    \n        if(t&1)res=__int128_t(res)*a%im;\r\n        a=__int128_t(a)*a%im;\r\n\
    \        t>>=1;\r\n    } return res;\r\n}\r\nll minv(ll a,ll m){\r\n    ll b=m,u=1,v=0;\r\
    \n    while(b){\r\n        ll t=a/b;\r\n        a-=t*b; swap(a,b);\r\n       \
    \ u-=t*v; swap(u,v);\r\n    }\r\n    u=(u%m+m)%m;\r\n    return u;\r\n}\r\nll\
    \ getPrimitiveRoot(ll p){\r\n    vector<ll> ps=Pollard(p-1);\r\n    sort(ALL(ps));\r\
    \n    rep(x,1,inf){\r\n        for(auto& q:ps){\r\n            if(mpow(x,(p-1)/q,p)==1)goto\
    \ fail;\r\n        }\r\n        return x;\r\n        fail:;\r\n    } assert(0);\r\
    \n}\r\nll extgcd(ll a,ll b,ll& p,ll& q){\r\n    if(b==0){p=1; q=0; return a;}\r\
    \n    ll d=extgcd(b,a%b,q,p); q-=a/b*p; return d;\r\n}\r\npair<ll,ll> crt(const\
    \ vector<ll>& vs,const vector<ll>& ms){\r\n    ll V=vs[0],M=ms[0];\r\n    rep(i,1,vs.size()){\r\
    \n        ll p,q,v=vs[i],m=ms[i];\r\n        if(M<m)swap(M,m),swap(V,v);\r\n \
    \       ll d=extgcd(M,m,p,q);\r\n        if((v-V)%d!=0)return {0,-1};\r\n    \
    \    ll md=m/d,tmp=(v-V)/d%md*p%md;\r\n        V+=M*tmp; M*=md;\r\n    }\r\n \
    \   V=(V%M+M)%M;\r\n    return {V,M};\r\n}\r\nll ModLog(ll a,ll b,ll p){\r\n \
    \   ll g=1;\r\n    for(ll t=p;t;t>>=1)g=g*a%p;\r\n    g=__gcd(g,p);\r\n    ll\
    \ t=1,c=0;\r\n    for(;t%g;c++){\r\n        if(t==b)return c;\r\n        t=t*a%p;\r\
    \n    }\r\n    if(b%g)return -1;\r\n    t/=g,b/=g;\r\n    ll n=p/g,h=0,gs=1;\r\
    \n    for(;h*h<n;h++)gs=gs*a%n;\r\n    unordered_map<ll,ll> bs;\r\n    for(ll\
    \ s=0,e=b;s<h;bs[e]=++s)e=e*a%n;\r\n    for(ll s=0,e=t;s<n;){\r\n        e=e*gs%n,s+=h;\r\
    \n        if(bs.count(e)){\r\n            return c+s-bs[e];\r\n        }\r\n \
    \   }\r\n    return -1;\r\n}\r\n\r\nll mod_root(ll k,ll a,ll m){\r\n    if(a==0)return\
    \ k?0:-1;\r\n    if(m==2)return a&1;\r\n    k%=m-1;\r\n    ll g=gcd(k,m-1);\r\n\
    \    if(mpow(a,(m-1)/g,m)!=1)return -1;\r\n    a=mpow(a,minv(k/g,(m-1)/g),m);\r\
    \n    FastDiv im(m);\r\n\r\n    auto _subroot=[&](ll p,int e,ll a)->ll{//x^(p^e)==a(mod\
    \ m)\r\n        ll q=m-1; int s=0;\r\n        while(q%p==0){q/=p; s++;}\r\n  \
    \      int d=s-e;\r\n        ll pe=mpow(p,e,m),res=mpow(a,((pe-1)*minv(q,pe)%pe*q+1)/pe,m),c=1;\r\
    \n        while(mpow(c,(m-1)/p,m)==1)c++;\r\n        c=mpow(c,q,m);\r\n      \
    \  map<ll,ll> mp;\r\n        ll v=1,block=sqrt(d*p)+1,bs=mpow(c,mpow(p,s-1,m-1)*block%(m-1),m);\r\
    \n        rep(i,0,block+1)mp[v]=i,v=v*bs%im;\r\n        ll gs=minv(mpow(c,mpow(p,s-1,m-1),m),m);\r\
    \n        rep(i,0,d){\r\n            ll err=a*minv(mpow(res,pe,m),m)%im;\r\n \
    \           ll pos=mpow(err,mpow(p,d-1-i,m-1),m);\r\n            rep(j,0,block+1){\r\
    \n                if(mp.count(pos)){\r\n                    res=res*mpow(c,(block*mp[pos]+j)*mpow(p,i,m-1)%(m-1),m)%im;\r\
    \n                    break;\r\n                }\r\n                pos=pos*gs%im;\r\
    \n            } \r\n        }\r\n        return res;\r\n    };\r\n\r\n    for(ll\
    \ d=2;d*d<=g;d++)if(g%d==0){\r\n        int sz=0;\r\n        while(g%d==0){g/=d;\
    \ sz++;}\r\n        a=_subroot(d,sz,a);\r\n    }\r\n    if(g>1)a=_subroot(g,1,a);\r\
    \n    return a;\r\n}\r\n\r\n/**\r\n * @brief Primitive Function\r\n */\n#line\
    \ 2 \"FPS/multievalgeom.hpp\"\n\ntemplate<typename T>vector<T> MultievalGeomSeq(vector<T>&\
    \ f,T a,T w,int m){\n    int n=f.size();\n    vector<T> tri(n+m-1),itri(n+m-1);\n\
    \    tri[0]=itri[0]=1;\n    T iw=w.inv(),pww=1,pwiw=1;\n    for(int i=1;i<n+m-1;i++,pww*=w,pwiw*=iw){\n\
    \        tri[i]=tri[i-1]*pww;\n        itri[i]=itri[i-1]*pwiw;\n    }\n\n    Poly<T>\
    \ y(n),v(n+m-1);\n    T pwa=1;\n    for(int i=0;i<n;i++,pwa*=a){\n        y[i]=f[i]*itri[i]*pwa;\n\
    \    }\n    rep(i,0,n+m-1)v[i]=tri[i];\n    reverse(ALL(y));\n    y*=v;\n    vector<T>\
    \ ret(m);\n    rep(i,0,m)ret[i]=y[n-1+i]*itri[i];\n    return ret;\n}\n\n/**\n\
    \ * @brief Multipoint Evaluation on Geometric Sequence\n*/\n#line 4 \"Convolution/multivariatecyclic.hpp\"\
    \n\ntemplate<typename T>vector<T> MultivariateCyclic\n    (vector<T> f,vector<T>\
    \ g,vector<int>& a){\n    int MO=T::get_mod();\n    int k=a.size(),n=1;\n    for(auto&\
    \ x:a)n*=x;\n    T pr=getPrimitiveRoot(MO),ipr=T(pr).inv();\n\n    int offset=1;\n\
    \    rep(x,0,k){\n        assert((MO-1)%a[x]==0);\n        T w=pr.pow((MO-1)/a[x]);\n\
    \        rep(i,0,n)if(i%(offset*a[x])<offset){\n            vector<T> na(a[x]),nb(a[x]);\n\
    \            rep(j,0,a[x]){\n                na[j]=f[i+offset*j];\n          \
    \      nb[j]=g[i+offset*j];\n            }\n            na=MultievalGeomSeq(na,T(1),w,a[x]);\n\
    \            nb=MultievalGeomSeq(nb,T(1),w,a[x]);\n            rep(j,0,a[x]){\n\
    \                f[i+offset*j]=na[j];\n                g[i+offset*j]=nb[j];\n\
    \            }\n        }\n        offset*=a[x];\n    }\n\n    rep(i,0,n)f[i]*=g[i];\n\
    \    \n    offset=1;\n    rep(x,0,k){\n        T iw=ipr.pow((MO-1)/a[x]);\n  \
    \      rep(i,0,n)if(i%(offset*a[x])<offset){\n            vector<T> na(a[x]);\n\
    \            rep(j,0,a[x])na[j]=f[i+offset*j];\n            na=MultievalGeomSeq(na,T(1),iw,a[x]);\n\
    \            rep(j,0,a[x])f[i+offset*j]=na[j];\n        }\n        offset*=a[x];\n\
    \    }\n    T ninv=T(n).inv();\n    rep(i,0,n)f[i]*=ninv;\n    return f;\n}\n\n\
    /**\n * @brief Multivarate Convolution Cyclic\n*/\n#line 13 \"Verify/LC_multivariate_convolution_cyclic.test.cpp\"\
    \n\nFastIO io;\nint main(){\n    int p,k;\n    io.read(p,k);\n    Fp::set_mod(p);\n\
    \    vector<int> a(k);\n    io.read(a);\n    int n=1;\n    for(auto& x:a)n*=x;\n\
    \    vector<Fp> f(n),g(n);\n    rep(i,0,n)io.read(f[i].v);\n    rep(i,0,n)io.read(g[i].v);\n\
    \n    auto ret=MultivariateCyclic(f,g,a);\n    rep(i,0,n)io.write(ret[i].v);\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multivariate_convolution_cyclic\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/dynamic.hpp\"\n#include \"Convolution/arbitrary.hpp\"\n#include \"FPS/arbitraryfps.hpp\"\
    \ntemplate<>vector<Fp> Poly<Fp>::mult(const vector<Fp>& a,const vector<Fp>& b,bool\
    \ same)const{\n    return ArbitraryMult(a,b,same);\n}\n#include \"Convolution/multivariatecyclic.hpp\"\
    \n\nFastIO io;\nint main(){\n    int p,k;\n    io.read(p,k);\n    Fp::set_mod(p);\n\
    \    vector<int> a(k);\n    io.read(a);\n    int n=1;\n    for(auto& x:a)n*=x;\n\
    \    vector<Fp> f(n),g(n);\n    rep(i,0,n)io.read(f[i].v);\n    rep(i,0,n)io.read(g[i].v);\n\
    \n    auto ret=MultivariateCyclic(f,g,a);\n    rep(i,0,n)io.write(ret[i].v);\n\
    \    return 0;\n}\n"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/dynamic.hpp
  - Math/fastdiv.hpp
  - Convolution/arbitrary.hpp
  - Math/modint.hpp
  - Convolution/ntt.hpp
  - FPS/arbitraryfps.hpp
  - Convolution/multivariatecyclic.hpp
  - Math/primitive.hpp
  - Math/pollard.hpp
  - Math/miller.hpp
  - Utility/random.hpp
  - FPS/multievalgeom.hpp
  isVerificationFile: true
  path: Verify/LC_multivariate_convolution_cyclic.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 01:31:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_multivariate_convolution_cyclic.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_multivariate_convolution_cyclic.test.cpp
- /verify/Verify/LC_multivariate_convolution_cyclic.test.cpp.html
title: Verify/LC_multivariate_convolution_cyclic.test.cpp
---
