---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Algorithm/mo.hpp
    title: Mo's Algorithm
  - icon: ':question:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"Verify/LC_static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\r\n\
    \r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Algorithm/mo.hpp\"\
    \n\r\nstruct Mo{\r\n    const int n;\r\n    vector<int> L,R;\r\n    Mo(int _n):n(_n){}\r\
    \n    void add(int lb,int rb){\r\n        L.push_back(lb);\r\n        R.push_back(rb);\r\
    \n    }\r\n    template <typename AL, typename AR, typename DL, typename DR, typename\
    \ OUT>\r\n    void run(const AL& addl,const AR& addr,const DL& dell,const DR&\
    \ delr,const OUT& out){\r\n        const int q=L.size();\r\n        const int\
    \ w=max<int>(1,1.0*n/max<double>(1.0,sqrt(q*2.0/3.0)));\r\n        vector<int>\
    \ ord(q);\r\n        iota(ALL(ord),0);\r\n        sort(ALL(ord),[&](int i,int\
    \ j){\r\n            int a=L[i]/w,b=L[j]/w;\r\n            if(a!=b)return a<b;\r\
    \n            if(a&1)return R[i]<R[j];\r\n            else return R[i]>R[j];\r\
    \n        });\r\n        int lb=0,rb=0;\r\n        for(auto& i:ord){\r\n     \
    \       while(lb>L[i])addl(--lb);\r\n            while(rb<R[i])addr(rb++);\r\n\
    \            while(lb<L[i])dell(lb++);\r\n            while(rb>R[i])delr(--rb);\r\
    \n            out(i);\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Mo's\
    \ Algorithm\r\n * @docs docs/mo.md\r\n */\n#line 2 \"DataStructure/bit.hpp\"\n\
    \r\ntemplate<typename T>struct BIT{\r\n    int n; T all=0; vector<T> val;\r\n\
    \    BIT(int _n=0):n(_n),val(_n+10){}\r\n    void clear(){val.assign(n+10,0);\
    \ all=T();}\r\n    void add(int i,T x){\r\n        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\
    \n        all+=x;\r\n    }\r\n    T sum(int i){\r\n        T res=0;\r\n      \
    \  for(;i;i-=(i&-i))res+=val[i];\r\n        return res;\r\n    }\r\n    T sum(int\
    \ L,int R){return sum(R)-sum(L);} // [L,R)\r\n    int lower_bound(T x){\r\n  \
    \      int ret=0,len=1;\r\n        while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\
    \n            if(ret+len<=n and val[ret+len]<x){\r\n                ret+=len;\r\
    \n                x-=val[ret];\r\n            }\r\n        }\r\n        return\
    \ ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Binary Indexed Tree\r\n */\n#line\
    \ 6 \"Verify/LC_static_range_inversions_query.test.cpp\"\n\r\nint a[101010];\r\
    \nll ret[101010],cur=0;\r\nBIT<int> bit(101010);\r\n\r\nint main(){\r\n    int\
    \ n,q;\r\n    cin>>n>>q;\r\n    using P=pair<int,int>;\r\n    vector<P> vs(n);\r\
    \n    rep(i,0,n){\r\n        cin>>vs[i].first;\r\n        vs[i].second=i;\r\n\
    \    }\r\n    sort(ALL(vs));\r\n    rep(i,0,n)a[vs[i].second]=i;\r\n\r\n    auto\
    \ addl=[&](int i){\r\n        cur+=bit.sum(a[i]);\r\n        bit.add(a[i],1);\r\
    \n    };\r\n    auto addr=[&](int i){\r\n        cur+=bit.all-bit.sum(a[i]);\r\
    \n        bit.add(a[i],1);\r\n    };\r\n    auto dell=[&](int i){\r\n        bit.add(a[i],-1);\r\
    \n        cur-=bit.sum(a[i]);\r\n    };\r\n    auto delr=[&](int i){\r\n     \
    \   bit.add(a[i],-1);\r\n        cur-=bit.all-bit.sum(a[i]);\r\n    };\r\n   \
    \ auto out=[&](int i){\r\n        ret[i]=cur;\r\n    };\r\n\r\n    Mo mo(n);\r\
    \n    rep(i,0,q){\r\n        int L,R;\r\n        cin>>L>>R;\r\n        mo.add(L,R);\r\
    \n    }\r\n    mo.run(addl,addr,dell,delr,out);\r\n    rep(i,0,q)cout<<ret[i]<<'\\\
    n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Algorithm/mo.hpp\"\r\n\
    #include \"DataStructure/bit.hpp\"\r\n\r\nint a[101010];\r\nll ret[101010],cur=0;\r\
    \nBIT<int> bit(101010);\r\n\r\nint main(){\r\n    int n,q;\r\n    cin>>n>>q;\r\
    \n    using P=pair<int,int>;\r\n    vector<P> vs(n);\r\n    rep(i,0,n){\r\n  \
    \      cin>>vs[i].first;\r\n        vs[i].second=i;\r\n    }\r\n    sort(ALL(vs));\r\
    \n    rep(i,0,n)a[vs[i].second]=i;\r\n\r\n    auto addl=[&](int i){\r\n      \
    \  cur+=bit.sum(a[i]);\r\n        bit.add(a[i],1);\r\n    };\r\n    auto addr=[&](int\
    \ i){\r\n        cur+=bit.all-bit.sum(a[i]);\r\n        bit.add(a[i],1);\r\n \
    \   };\r\n    auto dell=[&](int i){\r\n        bit.add(a[i],-1);\r\n        cur-=bit.sum(a[i]);\r\
    \n    };\r\n    auto delr=[&](int i){\r\n        bit.add(a[i],-1);\r\n       \
    \ cur-=bit.all-bit.sum(a[i]);\r\n    };\r\n    auto out=[&](int i){\r\n      \
    \  ret[i]=cur;\r\n    };\r\n\r\n    Mo mo(n);\r\n    rep(i,0,q){\r\n        int\
    \ L,R;\r\n        cin>>L>>R;\r\n        mo.add(L,R);\r\n    }\r\n    mo.run(addl,addr,dell,delr,out);\r\
    \n    rep(i,0,q)cout<<ret[i]<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Algorithm/mo.hpp
  - DataStructure/bit.hpp
  isVerificationFile: true
  path: Verify/LC_static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2023-01-17 02:40:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_static_range_inversions_query.test.cpp
- /verify/Verify/LC_static_range_inversions_query.test.cpp.html
title: Verify/LC_static_range_inversions_query.test.cpp
---
