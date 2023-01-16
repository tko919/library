---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/persistentarray.hpp
    title: Persistent Array
  - icon: ':heavy_check_mark:'
    path: DataStructure/persistentunionfind.hpp
    title: Persistent Union Find
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"Verify/LC_persistent_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\n#define\
    \ UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\n#define MIN(v) *min_element(ALL(v))\r\
    \n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()\r\
    \n#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()\r\n\r\nusing ll=long long\
    \ int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\
    \r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename U>T floor(T x,U\
    \ y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename\
    \ T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename T>int\
    \ topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename T>int\
    \ lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
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
    \n * @brief Fast IO\r\n */\n#line 2 \"DataStructure/persistentarray.hpp\"\n\r\n\
    template<typename T,int B=4>class PersistentArray{\r\n    const int M=(1<<B)-1;\r\
    \n    struct Node{\r\n        Node *cp[1<<B]={};\r\n        T val;\r\n    };\r\
    \n    Node* set(int i,T x,Node* a){\r\n        Node *ret=new Node();\r\n     \
    \   if(a){\r\n            memcpy(ret->cp,a->cp,sizeof(a->cp));\r\n           \
    \ ret->val=a->val;\r\n        }\r\n        if(i)ret->cp[i&M]=set(i>>B,x,ret->cp[i&M]);\r\
    \n        else ret->val=x;\r\n        return ret;\r\n    }\r\n    T get(int i,Node*\
    \ a){\r\n        if(i)return get(i>>B,a->cp[i&M]);\r\n        else return a->val;\r\
    \n    }\r\npublic:\r\n    Node *root;\r\n    PersistentArray(Node* _r=nullptr):root(_r){}\r\
    \n    void set(int i,T x){\r\n        root=set(i,x,root);\r\n    }\r\n    T get(int\
    \ i){\r\n        return get(i,root);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Persistent\
    \ Array\r\n */\n#line 3 \"DataStructure/persistentunionfind.hpp\"\n\r\nstruct\
    \ PersistentUnionFind{\r\n    PersistentArray<int> dat;\r\n    PersistentUnionFind(int\
    \ n){\r\n        rep(i,0,n)dat.set(i,-1);\r\n    }\r\n    int root(int x){\r\n\
    \        if(dat.get(x)<0)return x;\r\n        else return root(dat.get(x));\r\n\
    \    }\r\n    bool unite(int x,int y){\r\n        x=root(x),y=root(y);\r\n   \
    \     if(x==y)return false;\r\n        int p=dat.get(x),q=dat.get(y);\r\n    \
    \    if(p>q)swap(x,y);\r\n        dat.set(x,p+q);\r\n        dat.set(y,x);\r\n\
    \        return true;\r\n    }\r\n    bool same(int x,int y){return root(x)==root(y);}\r\
    \n    int size(int a){return -dat.get(root(a));}\r\n};\r\n\r\n/**\r\n * @brief\
    \ Persistent Union Find\r\n */\n#line 6 \"Verify/LC_persistent_unionfind.test.cpp\"\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\n    io.read(n,q);\r\n    vector<PersistentUnionFind>\
    \ buf;\r\n    buf.push_back(PersistentUnionFind(n));\r\n    while(q--){\r\n  \
    \      int t,k,u,v;\r\n        io.read(t,k,u,v);\r\n        k++;\r\n        if(t==0){\r\
    \n            buf.push_back(buf[k]);\r\n            buf.back().unite(u,v);\r\n\
    \        }\r\n        else{\r\n            buf.push_back(buf[k]);\r\n        \
    \    io.write((int)buf.back().same(u,v));\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\r\
    \n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\
    #include \"DataStructure/persistentunionfind.hpp\"\r\n\r\nFastIO io;\r\nint main(){\r\
    \n    int n,q;\r\n    io.read(n,q);\r\n    vector<PersistentUnionFind> buf;\r\n\
    \    buf.push_back(PersistentUnionFind(n));\r\n    while(q--){\r\n        int\
    \ t,k,u,v;\r\n        io.read(t,k,u,v);\r\n        k++;\r\n        if(t==0){\r\
    \n            buf.push_back(buf[k]);\r\n            buf.back().unite(u,v);\r\n\
    \        }\r\n        else{\r\n            buf.push_back(buf[k]);\r\n        \
    \    io.write((int)buf.back().same(u,v));\r\n        }\r\n    }\r\n    return\
    \ 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/persistentunionfind.hpp
  - DataStructure/persistentarray.hpp
  isVerificationFile: true
  path: Verify/LC_persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_persistent_unionfind.test.cpp
- /verify/Verify/LC_persistent_unionfind.test.cpp.html
title: Verify/LC_persistent_unionfind.test.cpp
---
