---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: FPS/berlekampmassey.hpp
    title: Berlekamp Massey Algorithm
  - icon: ':question:'
    path: FPS/fps.hpp
    title: Formal Power Series (NTT-friendly mod)
  - icon: ':x:'
    path: Math/bbla.hpp
    title: Black Box Linear Algebra
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  - icon: ':question:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sparse_matrix_det
    links:
    - https://judge.yosupo.jp/problem/sparse_matrix_det
  bundledCode: "#line 1 \"Verify/LC_sparse_matrix_det.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\n#define\
    \ UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define MIN(v)\
    \ *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v,x)\
    \ lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_sparse_matrix_det.test.cpp\"\n\
    \r\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp {\r\
    \n    int v;\r\n    static constexpr int get_mod(){return mod;}\r\n    int inv()\
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
    \n */\n#line 2 \"FPS/fps.hpp\"\n\r\ntemplate<typename T>struct Poly:vector<T>{\r\
    \n    Poly(int n=0){this->assign(n,T());}\r\n    Poly(const vector<T>& f){this->assign(ALL(f));}\r\
    \n    T eval(const T& x){\r\n        T res;\r\n        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);\r\
    \n        return res;\r\n    }\r\n    Poly rev()const{Poly res=*this; reverse(ALL(res));\
    \ return res;}\r\n    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}\r\
    \n    Poly operator>>(int sz)const{\r\n        if((int)this->size()<=sz)return\
    \ {};\r\n        Poly ret(*this);\r\n        ret.erase(ret.begin(),ret.begin()+sz);\r\
    \n        return ret;\r\n    }\r\n    Poly operator<<(int sz)const{\r\n      \
    \  Poly ret(*this);\r\n        ret.insert(ret.begin(),sz,T(0));\r\n        return\
    \ ret;\r\n    }\r\n    vector<T> mult(const vector<T>& a,const vector<T>& b,bool\
    \ same=0)const{\r\n        if(a.empty() or b.empty())return vector<T>();\r\n \
    \       int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);\r\n        vector<T> res(m);\r\
    \n        rep(i,0,a.size())res[i]=a[i];\r\n        NTT(res,0);\r\n        if(same)rep(i,0,m)res[i]*=res[i];\r\
    \n        else{\r\n            vector<T> c(m);\r\n            rep(i,0,b.size())c[i]=b[i];\r\
    \n            NTT(c,0);\r\n            rep(i,0,m)res[i]*=c[i];\r\n        }\r\n\
    \        NTT(res,1);\r\n        res.resize(n);\r\n        return res;\r\n    }\r\
    \n    Poly square()const{return Poly(mult(*this,*this,1));}\r\n    Poly operator-()const{return\
    \ Poly()-*this;}\r\n    Poly operator+(const Poly& g)const{return Poly(*this)+=g;}\r\
    \n    Poly operator+(const T& g)const{return Poly(*this)+=g;}\r\n    Poly operator-(const\
    \ Poly& g)const{return Poly(*this)-=g;}\r\n    Poly operator-(const T& g)const{return\
    \ Poly(*this)-=g;}\r\n    Poly operator*(const Poly& g)const{return Poly(*this)*=g;}\r\
    \n    Poly operator*(const T& g)const{return Poly(*this)*=g;}\r\n    Poly operator/(const\
    \ Poly& g)const{return Poly(*this)/=g;}\r\n    Poly operator/(const T& g)const{return\
    \ Poly(*this)/=g;}\r\n    Poly operator%(const Poly& g)const{return Poly(*this)%=g;}\r\
    \n    Poly& operator+=(const Poly& g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\
    \n        rep(i,0,g.size()){(*this)[i]+=g[i];} return *this;\r\n    }\r\n    Poly&\
    \ operator+=(const T& g){\r\n        if(this->empty())this->push_back(0);\r\n\
    \        (*this)[0]+=g; return *this;\r\n    }\r\n    Poly& operator-=(const Poly&\
    \ g){\r\n        if(g.size()>this->size())this->resize(g.size());\r\n        rep(i,0,g.size()){(*this)[i]-=g[i];}\
    \ return *this;\r\n    }\r\n    Poly& operator-=(const T& g){\r\n        if(this->empty())this->push_back(0);\r\
    \n        (*this)[0]-=g; return *this;\r\n    }\r\n    Poly& operator*=(const\
    \ Poly& g){\r\n        *this=mult(*this,g,0);\r\n        return *this;\r\n   \
    \ }\r\n    Poly& operator*=(const T& g){\r\n        rep(i,0,this->size())(*this)[i]*=g;\r\
    \n        return *this;\r\n    }\r\n    Poly& operator/=(const Poly& g){\r\n \
    \       if(g.size()>this->size()){\r\n            this->clear(); return *this;\r\
    \n        }\r\n        Poly g2=g;\r\n        reverse(ALL(*this));\r\n        reverse(ALL(g2));\r\
    \n        int n=this->size()-g2.size()+1;\r\n        this->resize(n); g2.resize(n);\r\
    \n        *this*=g2.inv(); this->resize(n); \r\n        reverse(ALL(*this));\r\
    \n        shrink();\r\n        return *this;\r\n    }\r\n    Poly& operator/=(const\
    \ T& g){\r\n        rep(i,0,this->size())(*this)[i]/=g;\r\n        return *this;\r\
    \n    }\r\n    Poly& operator%=(const Poly& g){*this-=*this/g*g; shrink(); return\
    \ *this;}\r\n    Poly diff()const{\r\n        Poly res(this->size()-1);\r\n  \
    \      rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);\r\n        return res;\r\n\
    \    }\r\n    Poly inte()const{\r\n        Poly res(this->size()+1);\r\n     \
    \   for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]/i;\r\n        return res;\r\
    \n    }\r\n    Poly log()const{\r\n        assert(this->front()==1); const int\
    \ n=this->size();\r\n        Poly res=diff()*inv(); res=res.inte(); \r\n     \
    \   res.resize(n); return res;\r\n    }\r\n    Poly shift(const int& c)const{\r\
    \n        const int n=this->size();\r\n        Poly res=*this,g(n); g[0]=1; rep(i,1,n)g[i]=g[i-1]*c/i;\r\
    \n        vector<T> fact(n,1);\r\n        rep(i,0,n){\r\n            if(i)fact[i]=fact[i-1]*i;\r\
    \n            res[i]*=fact[i];\r\n        }\r\n        res=res.rev();\r\n    \
    \    res*=g;\r\n        res.resize(n);\r\n        res=res.rev();\r\n        rep(i,0,n)res[i]/=fact[i];\r\
    \n        return res;\r\n    }\r\n    Poly inv()const{\r\n        const int n=this->size();\r\
    \n        Poly res(1); res.front()=T(1)/this->front();\r\n        for(int k=1;k<n;k<<=1){\r\
    \n            Poly f(k*2),g(k*2);\r\n            rep(i,0,min(n,k*2))f[i]=(*this)[i];\r\
    \n            rep(i,0,k)g[i]=res[i];\r\n            NTT(f,0);\r\n            NTT(g,0);\r\
    \n            rep(i,0,k*2)f[i]*=g[i];\r\n            NTT(f,1);\r\n           \
    \ rep(i,0,k){f[i]=0; f[i+k]=-f[i+k];}\r\n            NTT(f,0);\r\n           \
    \ rep(i,0,k*2)f[i]*=g[i];\r\n            NTT(f,1);\r\n            rep(i,0,k)f[i]=res[i];\r\
    \n            swap(res,f);\r\n        } res.resize(n); return res;\r\n    }\r\n\
    \    Poly exp()const{\r\n        const int n=this->size();\r\n        if(n==1)return\
    \ Poly({T(1)});\r\n        Poly b(2),c(1),z1,z2(2);\r\n        b[0]=c[0]=z2[0]=z2[1]=1;\
    \ b[1]=(*this)[1];\r\n        for(int k=2;k<n;k<<=1){\r\n            Poly y=b;\r\
    \n            y.resize(k*2);\r\n            NTT(y,0);\r\n            z1=z2;\r\n\
    \            Poly z(k);\r\n            rep(i,0,k)z[i]=y[i]*z1[i];\r\n        \
    \    NTT(z,1);\r\n            rep(i,0,k>>1)z[i]=0;\r\n            NTT(z,0);\r\n\
    \            rep(i,0,k)z[i]*=-z1[i];\r\n            NTT(z,1);\r\n            c.insert(c.end(),z.begin()+(k>>1),z.end());\r\
    \n            z2=c;\r\n            z2.resize(k*2);\r\n            NTT(z2,0);\r\
    \n            Poly x=*this;\r\n            x.resize(k);\r\n            x=x.diff();x.resize(k);\r\
    \n            NTT(x,0);\r\n            rep(i,0,k)x[i]*=y[i];\r\n            NTT(x,1);\r\
    \n            Poly bb=b.diff();\r\n            rep(i,0,k-1)x[i]-=bb[i];\r\n  \
    \          x.resize(k*2);\r\n            rep(i,0,k-1){x[k+i]=x[i]; x[i]=0;}\r\n\
    \            NTT(x,0);\r\n            rep(i,0,k*2)x[i]*=z2[i];\r\n           \
    \ NTT(x,1);\r\n            x.pop_back();\r\n            x=x.inte();\r\n      \
    \      rep(i,k,min(n,k*2))x[i]+=(*this)[i];\r\n            rep(i,0,k)x[i]=0;\r\
    \n            NTT(x,0);\r\n            rep(i,0,k*2)x[i]*=y[i];\r\n           \
    \ NTT(x,1);\r\n            b.insert(b.end(),x.begin()+k,x.end());\r\n        }\
    \ b.resize(n); return b;\r\n    }\r\n    Poly pow(ll t){\r\n        if(t==0){\r\
    \n            Poly res(this->size()); res[0]=1;\r\n            return res;\r\n\
    \        }\r\n        int n=this->size(),k=0; while(k<n and (*this)[k]==0)k++;\r\
    \n        Poly res(n); if(__int128_t(t)*k>=n)return res;\r\n        n-=t*k; Poly\
    \ g(n); T c=(*this)[k],ic=c.inv();\r\n        rep(i,0,n)g[i]=(*this)[i+k]*ic;\r\
    \n        g=g.log(); for(auto& x:g)x*=t; g=g.exp();\r\n        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c;\
    \ return res;\r\n    }\r\n    void NTT(vector<T>& a,bool inv)const;\r\n};\r\n\r\
    \n/**\r\n * @brief Formal Power Series (NTT-friendly mod)\r\n */\n#line 2 \"Math/bbla.hpp\"\
    \n\r\n#line 2 \"FPS/berlekampmassey.hpp\"\n\r\ntemplate<typename T>vector<T> BerlekampMassey(vector<T>&\
    \ a){\r\n   int n=a.size(); T d=1;\r\n   vector<T> b(1),c(1);\r\n   b[0]=c[0]=1;\r\
    \n   rep(j,1,n+1){\r\n      int l=c.size(),m=b.size();\r\n      T x=0;\r\n   \
    \   rep(i,0,l)x+=c[i]*a[j-l+i];\r\n      b.push_back(0);\r\n      m++;\r\n   \
    \   if(x==0)continue;\r\n      T coeff=-x/d;\r\n      if(l<m){\r\n         auto\
    \ tmp=c;\r\n         c.insert(c.begin(),m-l,0);\r\n         rep(i,0,m)c[m-1-i]+=coeff*b[m-1-i];\r\
    \n         b=tmp; d=x;\r\n      }\r\n      else rep(i,0,m)c[l-1-i]+=coeff*b[m-1-i];\r\
    \n   }\r\n   return c;\r\n}\r\n\r\n/**\r\n * @brief Berlekamp Massey Algorithm\r\
    \n */\n#line 2 \"Utility/random.hpp\"\n\r\nstruct Random{\r\n    random_device\
    \ rnd;\r\n    unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\
    \n    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\
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
    \ */\n#line 5 \"Math/bbla.hpp\"\n\r\nRandom genBBLA;\r\ntemplate<typename T>Poly<T>\
    \ RandPoly(int n){\r\n    Poly<T> ret(n);\r\n    for(auto& x:ret)x=genBBLA.get(1,T::get_mod()-1);\r\
    \n    return ret;\r\n}\r\ntemplate<typename T>struct SparseMatrix{\r\n    vector<T>\
    \ base;\r\n    vector<map<int,T>> extra;\r\n    SparseMatrix(int n,T v=0):base(n,v),extra(n){}\r\
    \n    int size()const{return base.size();}\r\n    inline void add(int i,int j,T\
    \ x){extra[i][j]+=x;}\r\n    friend Poly<T> operator*(const SparseMatrix<T>& A,const\
    \ Poly<T>& b){\r\n        int n=A.size();\r\n        Poly<T> ret(n);\r\n     \
    \   T sum;\r\n        for(auto& v:b)sum+=v;\r\n        rep(i,0,n){\r\n       \
    \     T add=sum;\r\n            for(auto& [j,v]:A.extra[i]){\r\n             \
    \   ret[i]+=v*b[j];\r\n                add-=b[j];\r\n            }\r\n       \
    \     ret[i]+=add*A.base[i];\r\n        }\r\n        return ret;\r\n    }\r\n\
    \    void mul(int i,T x){\r\n        base[i]*=x;\r\n        for(auto& [_,v]:extra[i])v*=x;\r\
    \n    }\r\n};\r\n\r\ntemplate<typename T>Poly<T> MinPolyforVector(const vector<Poly<T>>&\
    \ b){\r\n    int n=b.size(),m=b[0].size();\r\n    Poly<T> base=RandPoly<T>(m),a(n);\r\
    \n    rep(i,0,n)rep(j,0,m)a[i]+=base[j]*b[i][j];\r\n    return Poly<T>(BerlekampMassey(a)).rev();\r\
    \n}\r\ntemplate<typename T>Poly<T> MinPolyforMatrix(const SparseMatrix<T>& A){\r\
    \n    int n=A.size();\r\n    Poly<T> base=RandPoly<T>(n);\r\n    vector<Poly<T>>\
    \ b(n*2+1);\r\n    rep(i,0,n*2+1)b[i]=base,base=A*base;\r\n    return MinPolyforVector(b);\r\
    \n}\r\ntemplate<typename T>Poly<T> FastPow(const SparseMatrix<T>& A,Poly<T> b,ll\
    \ t){\r\n    int n=A.size();\r\n    auto mp=MinPolyforMatrix(A).rev();\r\n   \
    \ Poly<T> cs({T(1)}),base({T(0),T(1)});\r\n    while(t){\r\n        if(t&1){\r\
    \n            cs*=base;\r\n            cs%=mp;\r\n        }\r\n        base=base.square();\r\
    \n        base%=mp;\r\n        t>>=1;\r\n    }\r\n    Poly<T> ret(n);\r\n    for(auto&\
    \ c:cs)ret+=b*c,b=A*b;\r\n    return ret;\r\n}\r\ntemplate<typename T>T FastDet(const\
    \ SparseMatrix<T>& A){\r\n    int n=A.size();\r\n    for(;;){\r\n        Poly<T>\
    \ d=RandPoly<T>(n);\r\n        SparseMatrix<T> AD=A;\r\n        rep(i,0,n)AD.mul(i,d[i]);\r\
    \n        auto mp=MinPolyforMatrix(AD);\r\n        if(mp.back()==0)return 0;\r\
    \n        if(int(mp.size())!=n+1)continue;\r\n        T ret=mp.back(),base=1;\r\
    \n        if(n&1)ret=-ret;\r\n        for(auto& v:d)base*=v;\r\n        return\
    \ ret/base;\r\n    }\r\n}\r\n\r\n/**\r\n * @brief Black Box Linear Algebra\r\n\
    \ */\n#line 10 \"Verify/LC_sparse_matrix_det.test.cpp\"\nusing Fp=fp<998244353>;\r\
    \nNTT<Fp,3> ntt;\r\ntemplate<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return\
    \ ntt.ntt(v,inv);}\r\n\r\nFastIO io;\r\nint main(){\r\n    int n,k;\r\n    io.read(n,k);\r\
    \n    SparseMatrix<Fp> mat(n);\r\n    int a,b,c;\r\n    rep(_,0,k){\r\n      \
    \  io.read(a,b,c);\r\n        mat.add(a,b,c);\r\n    }\r\n    Fp ret=FastDet(mat);\r\
    \n    io.write(ret.v);\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\r\n\
    \r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\r\
    \n#include \"Math/modint.hpp\"\r\n#include \"Convolution/ntt.hpp\"\r\n#include\
    \ \"FPS/fps.hpp\"\r\n#include \"Math/bbla.hpp\"\r\nusing Fp=fp<998244353>;\r\n\
    NTT<Fp,3> ntt;\r\ntemplate<>void Poly<Fp>::NTT(vector<Fp>& v,bool inv)const{return\
    \ ntt.ntt(v,inv);}\r\n\r\nFastIO io;\r\nint main(){\r\n    int n,k;\r\n    io.read(n,k);\r\
    \n    SparseMatrix<Fp> mat(n);\r\n    int a,b,c;\r\n    rep(_,0,k){\r\n      \
    \  io.read(a,b,c);\r\n        mat.add(a,b,c);\r\n    }\r\n    Fp ret=FastDet(mat);\r\
    \n    io.write(ret.v);\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - Convolution/ntt.hpp
  - FPS/fps.hpp
  - Math/bbla.hpp
  - FPS/berlekampmassey.hpp
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_sparse_matrix_det.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_sparse_matrix_det.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_sparse_matrix_det.test.cpp
- /verify/Verify/LC_sparse_matrix_det.test.cpp.html
title: Verify/LC_sparse_matrix_det.test.cpp
---
