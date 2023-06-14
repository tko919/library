---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Convolution/subset.hpp
    title: Subset Convolution
  - icon: ':x:'
    path: Math/hafnian.hpp
    title: Hafnian of matrix
  - icon: ':question:'
    path: Math/matrix.hpp
    title: Matrix
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/hafnian_of_matrix
    links:
    - https://judge.yosupo.jp/problem/hafnian_of_matrix
  bundledCode: "#line 1 \"Verify/LC_hafnian_of_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n\n#line 1 \"Template/template.hpp\"\
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
    \n        }\r\n        return true;\r\n    }\r\n    inline bool _read(__int128_t&\
    \ x){\r\n        if(!skip())return false;\r\n        if(rdLeft+40>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdLeft<rdRight){\r\n            x=x*10+(neg?-(rdbuf[rdLeft++]^48):(rdbuf[rdLeft++]^48));\r\
    \n        }\r\n        return true;\r\n    }\r\n    inline bool _read(__uint128_t&\
    \ x){\r\n        if(!skip())return false;\r\n        if(rdLeft+40>=rdRight)reload();\r\
    \n        x=0;\r\n        while(rdbuf[rdLeft]>='0' and rdLeft<rdRight){\r\n  \
    \          x=x*10+(rdbuf[rdLeft++]^48);\r\n        }\r\n        return true;\r\
    \n    }\r\n    template<typename T,enable_if_t<is_floating_point<T>::value,int>\
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
    \n        wtRight+=pos;\r\n    }\r\n    inline void _write(__int128_t x){\r\n\
    \        if(wtRight>L-40)flush();\r\n        if(x==0){\r\n            _write('0');\r\
    \n            return;\r\n        }\r\n        else if(x<0){\r\n            _write('-');\r\
    \n            x=-x;\r\n        }\r\n        int pos=0;\r\n        while(x!=0){\r\
    \n            tmp[pos++]=char((x%10)|48);\r\n            x/=10;\r\n        }\r\
    \n        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];\r\n        wtRight+=pos;\r\
    \n    }\r\n    inline void _write(__uint128_t x){\r\n        if(wtRight>L-40)flush();\r\
    \n        if(x==0){\r\n            _write('0');\r\n            return;\r\n   \
    \     }\r\n        int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_hafnian_of_matrix.test.cpp\"\n\
    \n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp {\r\n\
    \    int v;\r\n    static constexpr int get_mod(){return mod;}\r\n    int inv()\
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
    #line 7 \"Verify/LC_hafnian_of_matrix.test.cpp\"\nusing Fp=fp<998244353>;\n\n\
    #line 2 \"Math/hafnian.hpp\"\n\n#line 2 \"Math/matrix.hpp\"\n\r\ntemplate<class\
    \ T>struct Matrix{\r\n    int h,w; vector<vector<T>> val; T det;\r\n    Matrix(){}\r\
    \n    Matrix(int n):h(n),w(n),val(vector<vector<T>>(n,vector<T>(n))){}\r\n   \
    \ Matrix(int n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m))){}\r\n \
    \   vector<T>& operator[](const int i){return val[i];}\r\n    Matrix& operator+=(const\
    \ Matrix& m){\r\n        assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix& operator-=(const Matrix& m){\r\
    \n        assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)val[i][j]-=m.val[i][j];\r\
    \n        return *this;\r\n    }\r\n    Matrix& operator*=(const Matrix& m){\r\
    \n        assert(w==m.h);\r\n        Matrix<T> res(h,m.w);\r\n        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];\r\
    \n        *this=res; return *this;\r\n    }\r\n    Matrix operator+(const Matrix&\
    \ m)const{return Matrix(*this)+=m;}\r\n    Matrix operator-(const Matrix& m)const{return\
    \ Matrix(*this)-=m;}\r\n    Matrix operator*(const Matrix& m)const{return Matrix(*this)*=m;}\r\
    \n    Matrix pow(ll k){\r\n        Matrix<T> res(h,h),c=*this; rep(i,0,h)res.val[i][i]=1;\r\
    \n        while(k){if(k&1)res*=c; c*=c; k>>=1;} return res;\r\n    }\r\n    vector<int>\
    \ gauss(int c=-1){\r\n        if(val.empty())return {};\r\n        if(c==-1)c=w;\r\
    \n        int cur=0; vector<int> res; det=1;\r\n        rep(i,0,c){\r\n      \
    \      if(cur==h)break;\r\n            rep(j,cur,h)if(val[j][i]!=0){\r\n     \
    \           swap(val[cur],val[j]);\r\n                if(cur!=j)det*=-1;\r\n \
    \               break;\r\n            }\r\n            det*=val[cur][i];\r\n \
    \           if(val[cur][i]==0)continue;\r\n            rep(j,0,h)if(j!=cur){\r\
    \n                T z=val[j][i]/val[cur][i];\r\n                rep(k,i,w)val[j][k]-=val[cur][k]*z;\r\
    \n            }\r\n            res.push_back(i);\r\n            cur++;\r\n   \
    \     }\r\n        return res;\r\n    }\r\n    Matrix inv(){\r\n        assert(h==w);\r\
    \n        Matrix base(h,h*2),res(h,h);\r\n        rep(i,0,h)rep(j,0,h)base[i][j]=val[i][j];\r\
    \n        rep(i,0,h)base[i][h+i]=1;\r\n        base.gauss(h);\r\n        rep(i,0,h)rep(j,0,h)res[i][j]=base[i][h+j]/base[i][i];\r\
    \n        return res;\r\n    }\r\n    bool operator==(const Matrix& m){\r\n  \
    \      assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)if(val[i][j]!=m.val[i][j])return\
    \ false;\r\n        return true;\r\n    }\r\n    bool operator!=(const Matrix&\
    \ m){\r\n        assert(h==m.h and w==m.w);\r\n        rep(i,0,h)rep(j,0,w)if(val[i][j]==m.val[i][j])return\
    \ false;\r\n        return true;\r\n    }\r\n    friend istream& operator>>(istream&\
    \ is,Matrix& m){\r\n        rep(i,0,m.h)rep(j,0,m.w)is>>m[i][j];\r\n        return\
    \ is;\r\n    }\r\n    friend ostream& operator<<(ostream& os,Matrix& m){\r\n \
    \       rep(i,0,m.h){\r\n            rep(j,0,m.w)os<<m[i][j]<<(j==m.w-1 and i!=m.h-1?'\\\
    n':' ');\r\n        }\r\n        return os;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Matrix\r\n */\n#line 2 \"Convolution/subset.hpp\"\n\r\ntemplate<typename T,int\
    \ LG=20>struct SubsetConvolution{\r\n    using POL=array<T,LG+1>;\r\n    vector<int>\
    \ bpc;\r\n    vector<T> inv;\r\n    SubsetConvolution():bpc(1<<LG),inv(LG+1){\r\
    \n        rep(i,1,1<<LG)bpc[i]=bpc[i-(i&-i)]+1;\r\n        rep(i,1,LG+1)inv[i]=T(1)/i;\r\
    \n    }\r\n    void zeta(vector<POL>& a){\r\n        int n=a.size();\r\n     \
    \   for(int w=1;w<n;w<<=1){\r\n            for(int k=0;k<n;k+=w*2)rep(i,0,w){\r\
    \n                rep(j,0,bpc[k+w+i])a[k+w+i][j]+=a[k+i][j];\r\n            }\r\
    \n        }\r\n    }\r\n    void mobius(vector<POL>& a){\r\n        int n=a.size(),m=__lg(n);\r\
    \n        for(int w=n>>1;w;w>>=1){\r\n            for(int k=0;k<n;k+=w*2)rep(i,0,w){\r\
    \n                rep(j,bpc[k+w+i],m+1)a[k+w+i][j]-=a[k+i][j];\r\n           \
    \ }\r\n        }\r\n    }\r\n    vector<T> mult(vector<T>& a,vector<T>& b,bool\
    \ same=0){\r\n        assert(a.size()==b.size());\r\n        int n=a.size(),m=__lg(n);\r\
    \n        vector<POL> A(n),B(n);\r\n        rep(i,0,n){\r\n            A[i][bpc[i]]=a[i];\r\
    \n            B[i][bpc[i]]=b[i];\r\n        }\r\n        zeta(A);\r\n        if(same)B=A;\r\
    \n        else zeta(B);\r\n        rep(i,0,n){\r\n            POL c;\r\n     \
    \       rep(j,0,m+1)rep(k,0,m+1-j)c[j+k]+=A[i][j]*B[i][k];\r\n            swap(A[i],c);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> exp(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    ret[0]=1;\r\n            rep(j,1,m+1){\r\n                rep(k,1,j+1)ret[j]+=ret[j-k]*A[i][k]*k;\r\
    \n                ret[j]*=inv[j];\r\n            }\r\n            swap(A[i],ret);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> log(vector<T>& a){\r\n       \
    \ int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    rep(j,1,m+1){\r\n                ret[j]=A[i][j]*j;\r\n                rep(k,1,j)ret[j]-=ret[k]*A[i][j-k]*k;\r\
    \n                ret[j]*=inv[j];\r\n            }\r\n            swap(A[i],ret);\r\
    \n        }\r\n        mobius(A);\r\n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\
    \n        return ret;\r\n    }\r\n    vector<T> sqrt(vector<T>& a){\r\n      \
    \  int n=a.size(),m=__lg(n);\r\n        vector<POL> A(n);\r\n        rep(i,0,n)A[i][bpc[i]]=a[i];\r\
    \n        zeta(A);\r\n        rep(i,0,n){\r\n            POL ret;\r\n        \
    \    ret[0]=1;\r\n            rep(j,1,m+1){\r\n                ret[j]=A[i][j];\r\
    \n                rep(k,1,j)ret[j]-=ret[k]*ret[j-k];\r\n                ret[j]*=inv[2];\r\
    \n            }\r\n            swap(A[i],ret);\r\n        }\r\n        mobius(A);\r\
    \n        vector<T> ret(n);\r\n        rep(i,0,n)ret[i]=A[i][bpc[i]];\r\n    \
    \    return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Subset Convolution\r\n\
    \ */\n#line 5 \"Math/hafnian.hpp\"\n\ntemplate<typename T>T Hafnian(Matrix<T>&\
    \ a){\n    int n=a.h;\n    assert(n%2==0);\n    n>>=1;\n\n    vector<T> cycle(1<<n);\n\
    \    vector dp(1<<n,vector<T>(n*2));\n    rep(base,0,n)dp[1<<base][base*2]=1;\n\
    \    rep(mask,0,1<<n){\n        int top=-1;\n        rep(i,0,n)if(mask>>i&1)top=i;\n\
    \        rep(base,0,n*2)if(mask>>(base>>1)&1){\n            T add=dp[mask][base];\n\
    \            rep(nxt,0,top)if(!(mask>>nxt&1)){\n                dp[mask|(1<<nxt)][nxt*2+1]+=add*a[base][nxt*2];\n\
    \                dp[mask|(1<<nxt)][nxt*2]+=add*a[base][nxt*2+1];\n           \
    \ }\n        }\n    }\n    rep(mask,1,1<<n){\n        int top=-1;\n        rep(i,0,n)if(mask>>i&1)top=i;\n\
    \        rep(base,0,n*2)cycle[mask]+=dp[mask][base]*a[base][top*2+1];\n    }\n\
    \    \n    SubsetConvolution<T> buf;\n    auto ret=buf.exp(cycle);\n    return\
    \ ret[(1<<n)-1];\n}\n\n/**\n * @brief Hafnian of matrix\n*/\n#line 10 \"Verify/LC_hafnian_of_matrix.test.cpp\"\
    \n\nFastIO io;\nint main(){\n    int n;\n    io.read(n);\n    Matrix<Fp> mat(n);\n\
    \    rep(i,0,n)rep(j,0,n)io.read(mat[i][j].v);\n\n    auto ret=Hafnian(mat);\n\
    \    io.write(ret.v);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n\n\
    #include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/modint.hpp\"\nusing Fp=fp<998244353>;\n\n#include \"Math/hafnian.hpp\"\
    \n\nFastIO io;\nint main(){\n    int n;\n    io.read(n);\n    Matrix<Fp> mat(n);\n\
    \    rep(i,0,n)rep(j,0,n)io.read(mat[i][j].v);\n\n    auto ret=Hafnian(mat);\n\
    \    io.write(ret.v);\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - Math/hafnian.hpp
  - Math/matrix.hpp
  - Convolution/subset.hpp
  isVerificationFile: true
  path: Verify/LC_hafnian_of_matrix.test.cpp
  requiredBy: []
  timestamp: '2023-06-14 14:20:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_hafnian_of_matrix.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_hafnian_of_matrix.test.cpp
- /verify/Verify/LC_hafnian_of_matrix.test.cpp.html
title: Verify/LC_hafnian_of_matrix.test.cpp
---
