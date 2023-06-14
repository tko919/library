---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: DataStructure/sortablesegtree.hpp
    title: Sortable Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
  bundledCode: "#line 1 \"Verify/LC_point_set_range_sort_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_point_set_range_sort_range_composite.test.cpp\"\
    \n\r\n#line 2 \"DataStructure/segtree.hpp\"\n\r\ntemplate<typename M,typename\
    \ N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree{\r\n    int n; vector<M>\
    \ data;\r\n    SegmentTree(int _n=0){\r\n        n=1; while(n<_n)n<<=1; data.assign(2*n,m1());\r\
    \n    }\r\n    void run(vector<M>& v){\r\n        for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];\r\
    \n        for(int k=n-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n\
    \    void set(int k,const M &x){\r\n        k+=n; data[k]=x;\r\n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\
    \n    }\r\n    void update(int k,const N &x){\r\n        k+=n; data[k]=g(data[k],x);\r\
    \n        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);\r\n    }\r\n    M query(int\
    \ a,int b){\r\n        M L=m1(),R=m1();\r\n        for(a+=n,b+=n;a<b;a>>=1,b>>=1){\r\
    \n            if(a&1)L=f(L,data[a++]);\r\n            if(b&1)R=f(data[--b],R);\r\
    \n        }\r\n        return f(L,R);\r\n    }\r\n    M operator[](const int &k)const{return\
    \ data[k+n];}\r\n};\r\n\r\n/**\r\n * @brief Segment Tree\r\n */\n#line 3 \"DataStructure/sortablesegtree.hpp\"\
    \n\r\ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)(),int LG=30>struct\
    \ SortableSegmentTree{\r\n    SortableSegmentTree(){}\r\n    SortableSegmentTree(vector<int>&\
    \ ks,vector<M>& vs):n(ks.size()),seg(n),Es(n){\r\n        rep(i,0,n){\r\n    \
    \        Ls.insert(i);\r\n            Es[i]=new Elem(ks[i],vs[i]);\r\n       \
    \     seg.set(i,vs[i]);\r\n        }\r\n        Ls.insert(n);\r\n    }\r\n   \
    \ void update(int i,int key,M val){\r\n        split(i);\r\n        split(i+1);\r\
    \n        Es[i]=new Elem(key,val);\r\n        seg.set(i,val);\r\n    }  \r\n \
    \   M query(int L,int R){\r\n        split(L);\r\n        split(R);\r\n      \
    \  return seg.query(L,R);\r\n    }\r\n    void sort(int L,int R,bool rev=false){\r\
    \n        split(L);\r\n        split(R);\r\n        int pos=L;\r\n        for(;;){\r\
    \n            pos=*(Ls.upper_bound(pos));\r\n            if(pos>=R)break;\r\n\
    \            Es[L]=meld(Es[L],Es[pos]);\r\n            Es[pos]=new Elem();\r\n\
    \            seg.set(pos,m1());\r\n            Ls.erase(pos);\r\n        }\r\n\
    \        Es[L]->set(rev);\r\n        seg.set(L,Es[L]->value());\r\n    }\r\nprivate:\r\
    \n    struct Trie{\r\n        Trie *cp[2];\r\n        int sz;\r\n        M val,lav;\r\
    \n        Trie(){cp[0]=cp[1]=nullptr;}\r\n        Trie(int key,M v){cp[0]=cp[1]=nullptr,init(key,v);}\r\
    \n        void init(int key,M v,int lg=LG){\r\n            sz=1;\r\n         \
    \   val=lav=v;\r\n            if(lg==-1)return;\r\n            if(!cp[key>>lg&1])cp[key>>lg&1]=new\
    \ Trie();\r\n            cp[key>>lg&1]->init(key,v,lg-1);\r\n        }\r\n   \
    \     void update(){\r\n            if(!cp[0] and !cp[1])return;\r\n         \
    \   sz=0;\r\n            val=lav=m1();\r\n            if(cp[0]){\r\n         \
    \       sz+=cp[0]->sz;\r\n                val=f(val,cp[0]->val);\r\n         \
    \       lav=f(cp[0]->lav,lav);\r\n            }\r\n            if(cp[1]){\r\n\
    \                sz+=cp[1]->sz;\r\n                val=f(val,cp[1]->val);\r\n\
    \                lav=f(cp[1]->lav,lav);\r\n            }\r\n        }\r\n    \
    \    void apply(N x){\r\n            assert(sz==1);\r\n            val=lav=g(val,x);\r\
    \n            if(cp[0])cp[0]->apply(x);\r\n            if(cp[1])cp[1]->apply(x);\r\
    \n        }\r\n    };\r\n    using Tp=Trie*;\r\n    int sz(Tp t){return t?t->sz:0;}\r\
    \n    Tp meld(Tp a,Tp b){\r\n        if(!a)return b;\r\n        if(!b)return a;\r\
    \n        a->cp[0]=meld(a->cp[0],b->cp[0]);\r\n        a->cp[1]=meld(a->cp[1],b->cp[1]);\r\
    \n        a->update();\r\n        return a;\r\n    }\r\n    pair<Tp,Tp> split(Tp\
    \ t,int k){\r\n        if(k==0)return {nullptr,t};\r\n        if(k==sz(t))return\
    \ {t,nullptr};\r\n        if(k<sz(t->cp[0])){\r\n            auto [l,tmp]=split(t->cp[0],k);\r\
    \n            auto L=new Trie();\r\n            L->cp[0]=l;\r\n            L->update();\r\
    \n            auto R=new Trie();\r\n            R->cp[0]=tmp,R->cp[1]=t->cp[1];\r\
    \n            R->update();\r\n            return {L,R};\r\n        }\r\n     \
    \   else{\r\n            auto [tmp,r]=split(t->cp[1],k-sz(t->cp[0]));\r\n    \
    \        auto L=new Trie();\r\n            auto R=new Trie();\r\n            L->cp[0]=t->cp[0],L->cp[1]=tmp;\r\
    \n            L->update();\r\n            R->cp[1]=r;\r\n            R->update();\r\
    \n            return {L,R};\r\n        }\r\n    }\r\n    struct Elem{\r\n    \
    \    Tp node;\r\n        bool rev;\r\n        Elem():node(nullptr),rev(0){}\r\n\
    \        Elem(int key,M x):node(new Trie(key,x)),rev(0){}\r\n        Elem(Tp t,bool\
    \ r):node(t),rev(r){}\r\n        void set(bool r){rev=r;}\r\n        void apply(N\
    \ x){node->apply(x);}\r\n        M value(){return rev?node->lav:node->val;}\r\n\
    \    };\r\n    using Ep=Elem*;\r\n    Ep meld(Ep s,Ep t){\r\n        return new\
    \ Elem(meld(s->node,t->node),0);\r\n    }\r\n    pair<Ep,Ep> split(Ep t,int k){\r\
    \n        if(t->rev)k=sz(t->node)-k;\r\n        auto [L,R]=split(t->node,k);\r\
    \n        if(t->rev)swap(L,R);\r\n        auto LE=new Elem(L,t->rev);\r\n    \
    \    auto RE=new Elem(R,t->rev);\r\n        return {LE,RE};\r\n    }\r\n\r\n \
    \   const int n;\r\n    SegmentTree<M,N,f,g,m1> seg;\r\n    set<int> Ls;\r\n \
    \   vector<Ep> Es;\r\n    void split(int k){\r\n        if(k>=n)return;\r\n  \
    \      int pos=*(--Ls.upper_bound(k));\r\n        if(pos==k)return;\r\n      \
    \  auto [L,R]=split(Es[pos],k-pos);\r\n        Es[pos]=L,Es[k]=R;\r\n        seg.set(pos,Es[pos]->value());\r\
    \n        seg.set(k,Es[k]->value());\r\n        Ls.insert(k);\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Sortable Segment Tree\r\n */\n#line 2 \"Math/modint.hpp\"\
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
    #line 8 \"Verify/LC_point_set_range_sort_range_composite.test.cpp\"\n\r\nusing\
    \ Fp=fp<998244353>;\r\nusing P=pair<Fp,Fp>;\r\n\r\nP f(P a,P b){\r\n    return\
    \ {a.first*b.first,b.first*a.second+b.second};\r\n}\r\nP g(P a,P b){return b;}\r\
    \nP m1(){return {1,0};}\r\n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\n \
    \   io.read(n,q);\r\n    vector<int> ps(n);\r\n    vector<P> vs(n);\r\n    rep(i,0,n)io.read(ps[i],vs[i].first.v,vs[i].second.v);\r\
    \n    SortableSegmentTree<P,P,f,g,m1> seg(ps,vs);\r\n\r\n    while(q--){\r\n \
    \       int t;\r\n        io.read(t);\r\n        if(t==0){\r\n            int\
    \ i,p,a,b;\r\n            io.read(i,p,a,b);\r\n            seg.update(i,p,P{a,b});\r\
    \n        }\r\n        if(t==1){\r\n            int L,R,x;\r\n            io.read(L,R,x);\r\
    \n            auto ab=seg.query(L,R);\r\n            Fp res=Fp(x)*ab.first+ab.second;\r\
    \n            io.write(res.v);\r\n        }\r\n        if(t==2){\r\n         \
    \   int L,R;\r\n            io.read(L,R);\r\n            seg.sort(L,R);\r\n  \
    \      }\r\n        if(t==3){\r\n            int L,R;\r\n            io.read(L,R);\r\
    \n            seg.sort(L,R,1);\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n\r\n#include \"DataStructure/sortablesegtree.hpp\"\r\n#include \"Math/modint.hpp\"\
    \r\n\r\nusing Fp=fp<998244353>;\r\nusing P=pair<Fp,Fp>;\r\n\r\nP f(P a,P b){\r\
    \n    return {a.first*b.first,b.first*a.second+b.second};\r\n}\r\nP g(P a,P b){return\
    \ b;}\r\nP m1(){return {1,0};}\r\n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\
    \n    io.read(n,q);\r\n    vector<int> ps(n);\r\n    vector<P> vs(n);\r\n    rep(i,0,n)io.read(ps[i],vs[i].first.v,vs[i].second.v);\r\
    \n    SortableSegmentTree<P,P,f,g,m1> seg(ps,vs);\r\n\r\n    while(q--){\r\n \
    \       int t;\r\n        io.read(t);\r\n        if(t==0){\r\n            int\
    \ i,p,a,b;\r\n            io.read(i,p,a,b);\r\n            seg.update(i,p,P{a,b});\r\
    \n        }\r\n        if(t==1){\r\n            int L,R,x;\r\n            io.read(L,R,x);\r\
    \n            auto ab=seg.query(L,R);\r\n            Fp res=Fp(x)*ab.first+ab.second;\r\
    \n            io.write(res.v);\r\n        }\r\n        if(t==2){\r\n         \
    \   int L,R;\r\n            io.read(L,R);\r\n            seg.sort(L,R);\r\n  \
    \      }\r\n        if(t==3){\r\n            int L,R;\r\n            io.read(L,R);\r\
    \n            seg.sort(L,R,1);\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/sortablesegtree.hpp
  - DataStructure/segtree.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: Verify/LC_point_set_range_sort_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-06-14 14:20:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_point_set_range_sort_range_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_point_set_range_sort_range_composite.test.cpp
- /verify/Verify/LC_point_set_range_sort_range_composite.test.cpp.html
title: Verify/LC_point_set_range_sort_range_composite.test.cpp
---
