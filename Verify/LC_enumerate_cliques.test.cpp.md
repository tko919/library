---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/enumcliques.hpp
    title: Enumerate Cliques
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_cliques
    links:
    - https://judge.yosupo.jp/problem/enumerate_cliques
  bundledCode: "#line 1 \"Verify/LC_enumerate_cliques.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_cliques\"\r\n\r\n#line 1 \"Template/template.hpp\"\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_enumerate_cliques.test.cpp\"\n\
    \r\n#line 2 \"Graph/enumcliques.hpp\"\n\r\nstruct EnumCliques{\r\n    const int\
    \ n;\r\n    int m;\r\n    vector<vector<int>> g;\r\n    vector<int> deg;\r\n \
    \   EnumCliques(int _n):n(_n),m(0),g(n,vector<int>(n)),deg(n){}\r\n    void add_edge(int\
    \ u,int v){\r\n        g[u][v]=g[v][u]=1;\r\n        deg[u]++; deg[v]++;\r\n \
    \       m++;\r\n    }\r\n    vector<vector<int>> run(){\r\n        int L=sqrt(m);\r\
    \n        vector<vector<int>> res;\r\n        auto process=[&](vector<int>& vs,bool\
    \ fix=true)->void{\r\n            vector<int> nbhd(vs.size());\r\n           \
    \ rep(i,0,vs.size())rep(j,0,vs.size())if(i!=j){\r\n                nbhd[i]|=(!g[vs[i]][vs[j]])<<j;\r\
    \n            }\r\n            rep(mask,1,1<<vs.size()){\r\n                if(fix\
    \ and (mask&1)==0)continue;;\r\n                bool check=1;\r\n            \
    \    rep(i,0,vs.size())if(mask>>i&1){\r\n                    if(mask&nbhd[i]){\r\
    \n                        check=0;\r\n                        break;\r\n     \
    \               }\r\n                }\r\n                if(check){\r\n     \
    \               vector<int> add;\r\n                    rep(i,0,vs.size())if(mask>>i&1){\r\
    \n                        add.push_back(vs[i]);\r\n                    }\r\n \
    \                   res.push_back(add);\r\n                }\r\n            }\r\
    \n        };\r\n\r\n        vector<int> used(n);\r\n        queue<int> que;\r\n\
    \        rep(v,0,n)if(deg[v]<L){\r\n            que.push(v);\r\n            used[v]=1;\r\
    \n        }\r\n        while(!que.empty()){\r\n            int v=que.front();\r\
    \n            que.pop();\r\n            vector<int> vs;\r\n            vs.push_back(v);\r\
    \n            rep(u,0,n)if(g[v][u])vs.push_back(u);\r\n            process(vs);\r\
    \n            rep(u,0,n)if(g[v][u]){\r\n                g[v][u]=g[u][v]=0;\r\n\
    \                deg[u]--;\r\n                if(!used[u] and deg[u]<L){\r\n \
    \                   que.push(u);\r\n                    used[u]=1;\r\n       \
    \         }\r\n            }\r\n        }\r\n        vector<int> vs;\r\n     \
    \   rep(v,0,n)if(!used[v])vs.push_back(v);\r\n        process(vs,false);\r\n \
    \       return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Enumerate Cliques\r\
    \n */\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp\
    \ {\r\n    int v;\r\n    static constexpr int get_mod(){return mod;}\r\n    int\
    \ inv() const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
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
    #line 8 \"Verify/LC_enumerate_cliques.test.cpp\"\nusing Fp=fp<998244353>;\r\n\r\
    \nFastIO io;\r\nint main(){\r\n    int n,m;\r\n    io.read(n,m);\r\n    vector<int>\
    \ x(n);\r\n    io.read(x);\r\n    EnumCliques g(n);\r\n    rep(_,0,m){\r\n   \
    \     int u,v;\r\n        io.read(u,v);\r\n        g.add_edge(u,v);\r\n    }\r\
    \n    auto cs=g.run();\r\n    Fp res;\r\n    for(auto& clique:cs){\r\n       \
    \ Fp add=1;\r\n        for(auto& v:clique)add*=x[v];\r\n        res+=add;\r\n\
    \    }\r\n    io.write(res.v);\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\r\n\
    \r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\r\
    \n#include \"Graph/enumcliques.hpp\"\r\n#include \"Math/modint.hpp\"\r\nusing\
    \ Fp=fp<998244353>;\r\n\r\nFastIO io;\r\nint main(){\r\n    int n,m;\r\n    io.read(n,m);\r\
    \n    vector<int> x(n);\r\n    io.read(x);\r\n    EnumCliques g(n);\r\n    rep(_,0,m){\r\
    \n        int u,v;\r\n        io.read(u,v);\r\n        g.add_edge(u,v);\r\n  \
    \  }\r\n    auto cs=g.run();\r\n    Fp res;\r\n    for(auto& clique:cs){\r\n \
    \       Fp add=1;\r\n        for(auto& v:clique)add*=x[v];\r\n        res+=add;\r\
    \n    }\r\n    io.write(res.v);\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/enumcliques.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: Verify/LC_enumerate_cliques.test.cpp
  requiredBy: []
  timestamp: '2023-06-14 14:20:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_enumerate_cliques.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_enumerate_cliques.test.cpp
- /verify/Verify/LC_enumerate_cliques.test.cpp.html
title: Verify/LC_enumerate_cliques.test.cpp
---
