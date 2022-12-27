---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lazysegtree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: DataStructure/unionrect.hpp
    title: Area of Union of Rectangles
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"Verify/LC_area_of_union_of_rectangles.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\r\n\r\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Utility/fastio.hpp\"\n#include\
    \ <unistd.h>\r\n\r\nclass FastIO{\r\n    static constexpr int L=1<<16;\r\n   \
    \ char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_area_of_union_of_rectangles.test.cpp\"\
    \n\r\n#line 2 \"DataStructure/lazysegtree.hpp\"\n\r\ntemplate<typename M,typename\
    \ N,M (*f)(M,M),M (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>\r\n    class LazySegmentTree{\r\
    \n    int sz,height;\r\n    vector<M> data;\r\n    vector<N> lazy;\r\n    void\
    \ update(int k){data[k]=f(data[k*2],data[k*2+1]);}\r\n    void apply(int k,N x){\r\
    \n        data[k]=g(data[k],x);\r\n        if(k<sz)lazy[k]=h(lazy[k],x);\r\n \
    \   }\r\n    void down(int k){\r\n        apply(k*2,lazy[k]);\r\n        apply(k*2+1,lazy[k]);\r\
    \n        lazy[k]=n1();\r\n    }\r\npublic:\r\n    LazySegmentTree(int n=0):LazySegmentTree(vector<M>(n,m1())){}\r\
    \n    LazySegmentTree(const vector<M>& a){\r\n        sz=1,height=0;\r\n     \
    \   while(sz<(int)a.size())sz<<=1,height++;\r\n        data.assign(2*sz,m1());\r\
    \n        lazy.assign(sz,n1());\r\n        rep(i,0,a.size())data[sz+i]=a[i];\r\
    \n        for(int i=sz-1;i;i--)update(i);\r\n    }\r\n    void set(int k,M x){\r\
    \n        k+=sz;\r\n        for(int i=height;i;i--)down(k>>i);\r\n        data[k]=x;\r\
    \n        for(int i=1;i<=height;i++)update(k>>i);\r\n    }\r\n    void update(int\
    \ L,int R,N x){\r\n        if(L>=R)return;\r\n        L+=sz,R+=sz;\r\n       \
    \ for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\n  \
    \          if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        int lb=L,rb=R;\r\
    \n        while(L<R){\r\n            if(L&1)apply(L++,x);\r\n            if(R&1)apply(--R,x);\r\
    \n            L>>=1;\r\n            R>>=1;\r\n        }\r\n        L=lb,R=rb;\r\
    \n        for(int i=1;i<=height;i++){\r\n            if(((L>>i)<<i)!=L)update(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)update((R-1)>>i);\r\n        }\r\n    }\r\n  \
    \  M query(int L,int R){\r\n        if(L>=R)return m1();\r\n        L+=sz,R+=sz;\r\
    \n        for(int i=height;i;i--){\r\n            if(((L>>i)<<i)!=L)down(L>>i);\r\
    \n            if(((R>>i)<<i)!=R)down((R-1)>>i);\r\n        }\r\n        M lb=m1(),rb=m1();\r\
    \n        while(L<R){\r\n            if(L&1)lb=f(lb,data[L++]);\r\n          \
    \  if(R&1)rb=f(data[--R],rb);\r\n            L>>=1;\r\n            R>>=1;\r\n\
    \        }\r\n        return f(lb,rb);\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Lazy Segment Tree\r\n */\n#line 3 \"DataStructure/unionrect.hpp\"\n\r\nstruct\
    \ UnionInterval{\r\n    struct M{\r\n        ll len,mi,cnt;\r\n    };\r\n    static\
    \ M f(M a,M b){\r\n        if(a.mi<b.mi)return {a.len+b.len,a.mi,a.cnt};\r\n \
    \       else if(a.mi>b.mi)return {a.len+b.len,b.mi,b.cnt};\r\n        else return\
    \ {a.len+b.len,a.mi,a.cnt+b.cnt};\r\n    }\r\n    static M g(M a,int b){\r\n \
    \       return M{a.len,min(INF,a.mi+b),a.cnt};\r\n    }\r\n    static int h(int\
    \ a,int b){\r\n        return a+b;\r\n    }\r\n    static M m1(){\r\n        return\
    \ M{0,INF,0};\r\n    }\r\n    static int m2(){return 0;}\r\n\r\n    const int\
    \ n=0;\r\n    LazySegmentTree<M,int,f,g,h,m1,m2> seg;\r\n    UnionInterval(){}\r\
    \n    UnionInterval(vector<int>& xs):n(xs.size()-1){\r\n        vector<M> init(n);\r\
    \n        rep(i,0,n){\r\n            init[i]=M{xs[i+1]-xs[i],0,xs[i+1]-xs[i]};\r\
    \n        }\r\n        seg=LazySegmentTree<M,int,f,g,h,m1,m2>(init);\r\n    }\r\
    \n    void add(int L,int R){\r\n        seg.update(L,R,1);\r\n    }\r\n    void\
    \ erase(int L,int R){\r\n        seg.update(L,R,-1);\r\n    }\r\n    ll run(){\r\
    \n        auto [len,mi,cnt]=seg.query(0,n);\r\n        if(mi==0)len-=cnt;\r\n\
    \        return len;\r\n    }\r\n};\r\n\r\nstruct UnionRect{\r\n    vector<int>\
    \ L,R,D,U;\r\n    UnionRect(){}\r\n    void add(int lb,int rb,int db,int ub){\r\
    \n        L.push_back(lb);\r\n        R.push_back(rb);\r\n        D.push_back(db);\r\
    \n        U.push_back(ub);\r\n    }\r\n    ll run(){\r\n        int n=L.size();\r\
    \n        vector<int> xs=L,ys=D;\r\n        xs.insert(xs.end(),ALL(R));\r\n  \
    \      ys.insert(ys.end(),ALL(U));\r\n        sort(ALL(xs));\r\n        xs.erase(unique(ALL(xs)),xs.end());\r\
    \n        sort(ALL(ys));\r\n        ys.erase(unique(ALL(ys)),ys.end());\r\n\r\n\
    \        UnionInterval buf=UnionInterval(ys);\r\n        using P=pair<int,int>;\r\
    \n        vector in(xs.size(),vector<P>()),out(xs.size(),vector<P>());\r\n   \
    \     rep(i,0,n){\r\n            L[i]=lower_bound(ALL(xs),L[i])-xs.begin();\r\n\
    \            R[i]=lower_bound(ALL(xs),R[i])-xs.begin();\r\n            D[i]=lower_bound(ALL(ys),D[i])-ys.begin();\r\
    \n            U[i]=lower_bound(ALL(ys),U[i])-ys.begin();\r\n            in[L[i]].push_back({D[i],U[i]});\r\
    \n            out[R[i]].push_back({D[i],U[i]});\r\n        }\r\n        ll ret=0;\r\
    \n        rep(i,0,xs.size()-1){\r\n            for(auto& [d,u]:in[i])buf.add(d,u);\r\
    \n            for(auto& [d,u]:out[i])buf.erase(d,u);\r\n            ret+=buf.run()*(xs[i+1]-xs[i]);\r\
    \n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Area\
    \ of Union of Rectangles\r\n */\n#line 7 \"Verify/LC_area_of_union_of_rectangles.test.cpp\"\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n;\r\n    io.read(n);\r\n    UnionRect\
    \ buf;\r\n    rep(_,0,n){\r\n        int L,D,R,U;\r\n        io.read(L,D,R,U);\r\
    \n        buf.add(L,R,D,U);\r\n    }\r\n    ll ret=buf.run();\r\n    io.write(ret);\r\
    \n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n\r\n#include \"DataStructure/unionrect.hpp\"\r\n\r\nFastIO io;\r\nint main(){\r\
    \n    int n;\r\n    io.read(n);\r\n    UnionRect buf;\r\n    rep(_,0,n){\r\n \
    \       int L,D,R,U;\r\n        io.read(L,D,R,U);\r\n        buf.add(L,R,D,U);\r\
    \n    }\r\n    ll ret=buf.run();\r\n    io.write(ret);\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/unionrect.hpp
  - DataStructure/lazysegtree.hpp
  isVerificationFile: true
  path: Verify/LC_area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2022-10-25 04:47:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_area_of_union_of_rectangles.test.cpp
- /verify/Verify/LC_area_of_union_of_rectangles.test.cpp.html
title: Verify/LC_area_of_union_of_rectangles.test.cpp
---
