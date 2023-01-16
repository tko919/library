---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/manhattanmst.hpp
    title: Manhattan MST
  - icon: ':x:'
    path: DataStructure/unionfind.hpp
    title: Union Find
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
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"Verify/LC_manhattanmst.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\
    \n\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_manhattanmst.test.cpp\"\n\n#line\
    \ 2 \"DataStructure/unionfind.hpp\"\n\r\nstruct UnionFind{\r\n    vector<int>\
    \ par; int n;\r\n    UnionFind(){}\r\n    UnionFind(int _n):par(_n,-1),n(_n){}\r\
    \n    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}\r\n    bool same(int\
    \ x,int y){return root(x)==root(y);}\r\n    int size(int x){return -par[root(x)];}\r\
    \n    bool unite(int x,int y){\r\n        x=root(x),y=root(y); if(x==y)return\
    \ false;\r\n        if(size(x)>size(y))swap(x,y);\r\n        par[y]+=par[x]; par[x]=y;\
    \ n--; return true;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Union Find\r\n */\n\
    #line 3 \"DataStructure/manhattanmst.hpp\"\n\ntemplate<typename T>pair<T,vector<pair<int,int>>>\
    \ ManhattanMST(vector<T>& X,vector<T>& Y){\n    using Q=pair<T,pair<int,int>>;\n\
    \    int n=X.size();\n    vector<int> ord(n);\n    iota(ALL(ord),0);\n    vector<Q>\
    \ cand;\n    rep(_,0,2){\n        rep(__,0,2){\n            sort(ALL(ord),[&](int\
    \ i,int j){return X[i]+Y[i]<X[j]+Y[j];});\n            map<T,int> sweep;\n   \
    \         for(auto& i:ord){\n                for(auto it=sweep.lower_bound(-Y[i]);it!=sweep.end();it=sweep.erase(it)){\n\
    \                    int j=it->second;\n                    if(X[i]-X[j]<Y[i]-Y[j])break;\n\
    \                    cand.push_back({abs(X[i]-X[j])+abs(Y[i]-Y[j]),{i,j}});\n\
    \                }\n                sweep[-Y[i]]=i;\n            }\n         \
    \   swap(X,Y);\n        }\n        for(auto& x:X)x=-x;\n    }\n    sort(ALL(cand));\n\
    \    UnionFind uni(n);\n    T ret=0;\n    vector<pair<int,int>> es;\n    for(auto&\
    \ [cost,uv]:cand){\n        auto [u,v]=uv;\n        if(uni.unite(u,v)){\n    \
    \        ret+=cost;\n            es.push_back(uv);\n        }\n    }\n    return\
    \ {ret,es};\n}\n\n/**\n * @brief Manhattan MST\n*/\n#line 7 \"Verify/LC_manhattanmst.test.cpp\"\
    \n\nFastIO io;\nint main(){\n    int n;\n    io.read(n);\n    vector<ll> x(n),y(n);\n\
    \    rep(i,0,n)io.read(x[i],y[i]);\n    auto ret=ManhattanMST(x,y);\n    io.write(ret.first);\n\
    \    for(auto& [u,v]:ret.second)io.write(u,v);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include \"DataStructure/manhattanmst.hpp\"\
    \n\nFastIO io;\nint main(){\n    int n;\n    io.read(n);\n    vector<ll> x(n),y(n);\n\
    \    rep(i,0,n)io.read(x[i],y[i]);\n    auto ret=ManhattanMST(x,y);\n    io.write(ret.first);\n\
    \    for(auto& [u,v]:ret.second)io.write(u,v);\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/manhattanmst.hpp
  - DataStructure/unionfind.hpp
  isVerificationFile: true
  path: Verify/LC_manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_manhattanmst.test.cpp
- /verify/Verify/LC_manhattanmst.test.cpp.html
title: Verify/LC_manhattanmst.test.cpp
---
