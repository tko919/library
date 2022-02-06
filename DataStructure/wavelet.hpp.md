---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_range_kth_smallest.test.cpp
    title: Verify/LC_range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_static_range_frequency.test.cpp
    title: Verify/LC_static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/wavelet.md
    document_title: Wavelet Matrix
    links: []
  bundledCode: "#line 2 \"DataStructure/wavelet.hpp\"\n\r\ntemplate<typename T>struct\
    \ WaveletMatrix{\r\n    struct BitVector{\r\n        vector<unsigned long long>\
    \ buf;\r\n        vector<int> rui;\r\n        BitVector(const vector<char>& a={}){\r\
    \n            int n=a.size();\r\n            buf.assign((n+63)>>6,0);\r\n    \
    \        rui.assign(buf.size()+1,0);\r\n            rep(i,0,n)if(a[i]){\r\n  \
    \              buf[i>>6]|=1ull<<(i&63);\r\n                rui[(i>>6)+1]++;\r\n\
    \            }\r\n            rep(i,0,buf.size())rui[i+1]+=rui[i];\r\n       \
    \ }\r\n        int rank(int k,bool f=1){\r\n            int ret=rui[k>>6]+__builtin_popcountll(buf[k>>6]&((1ull<<(k&63))-1));\r\
    \n            if(!f)return k-ret;\r\n            else return ret;\r\n        }\r\
    \n    };\r\n    int N,lg=0;\r\n    vector<int> mid;\r\n    vector<BitVector> buf;\r\
    \n    WaveletMatrix(vector<T> a={}):N(a.size()){\r\n        T mx;\r\n        for(auto&\
    \ x:a)chmax(mx,x);\r\n        while((T(1)<<lg)<=mx)lg++;\r\n        mid.resize(lg);\r\
    \n        buf.resize(lg);\r\n        for(int d=lg-1;d>=0;d--){\r\n           \
    \ vector<char> add;\r\n            vector nxt(2,vector<T>());\r\n            for(auto&\
    \ x:a){\r\n                add.push_back(x>>d&1);\r\n                nxt[x>>d&1].push_back(x);\r\
    \n            }\r\n            mid[d]=(int)nxt[0].size();\r\n            buf[d]=BitVector(add);\r\
    \n            swap(a,nxt[0]);\r\n            a.insert(a.end(),ALL(nxt[1]));\r\n\
    \        }\r\n    }\r\n    int rank(int L,int R,T x){\r\n        if((T(1)<<lg)<=x)return\
    \ 0;\r\n        for(int d=lg-1;d>=0;d--){\r\n            bool f=(x>>d&1);\r\n\
    \            L=buf[d].rank(L,f)+(f?mid[d]:0);\r\n            R=buf[d].rank(R,f)+(f?mid[d]:0);\r\
    \n        }\r\n        return R-L;\r\n    }\r\n    T quantile(int L,int R,int\
    \ k){\r\n        T ret=0;\r\n        for(int d=lg-1;d>=0;d--){\r\n           \
    \ int l0=buf[d].rank(L,0),r0=buf[d].rank(R,0);\r\n            if(k<r0-l0)L=l0,R=r0;\r\
    \n            else{\r\n                k-=r0-l0;\r\n                ret|=T(1)<<d;\r\
    \n                L+=mid[d]-l0,R+=mid[d]-r0;\r\n            }\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    int freq(int L,int R,T x){\r\n        if((T(1)<<lg)<=x)return\
    \ R-L;\r\n        int ret=0;\r\n        for(int d=lg-1;d>=0;d--){\r\n        \
    \    bool f=(x>>d&1);\r\n            if(f)ret+=buf[d].rank(R,0)-buf[d].rank(L,0);\r\
    \n            L=buf[d].rank(L,f)+(f?mid[d]:0);\r\n            R=buf[d].rank(R,f)+(f?mid[d]:0);\r\
    \n        }\r\n        return ret;\r\n    }\r\n    int freq(int L,int R,T a,T\
    \ b){\r\n        return freq(L,R,b)-freq(L,R,a);\r\n    }\r\n    T prev(int L,int\
    \ R,T x){\r\n        int cnt=freq(L,R,x);\r\n        return cnt==R-L?T(-1):quantile(L,R,cnt);\r\
    \n    }\r\n    T next(int L,int R,T x){\r\n        int cnt=freq(L,R,x);\r\n  \
    \      return cnt==0?T(-1):quantile(L,R,cnt-1);\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Wavelet Matrix\r\n * @docs docs/wavelet.md\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct WaveletMatrix{\r\n    struct\
    \ BitVector{\r\n        vector<unsigned long long> buf;\r\n        vector<int>\
    \ rui;\r\n        BitVector(const vector<char>& a={}){\r\n            int n=a.size();\r\
    \n            buf.assign((n+63)>>6,0);\r\n            rui.assign(buf.size()+1,0);\r\
    \n            rep(i,0,n)if(a[i]){\r\n                buf[i>>6]|=1ull<<(i&63);\r\
    \n                rui[(i>>6)+1]++;\r\n            }\r\n            rep(i,0,buf.size())rui[i+1]+=rui[i];\r\
    \n        }\r\n        int rank(int k,bool f=1){\r\n            int ret=rui[k>>6]+__builtin_popcountll(buf[k>>6]&((1ull<<(k&63))-1));\r\
    \n            if(!f)return k-ret;\r\n            else return ret;\r\n        }\r\
    \n    };\r\n    int N,lg=0;\r\n    vector<int> mid;\r\n    vector<BitVector> buf;\r\
    \n    WaveletMatrix(vector<T> a={}):N(a.size()){\r\n        T mx;\r\n        for(auto&\
    \ x:a)chmax(mx,x);\r\n        while((T(1)<<lg)<=mx)lg++;\r\n        mid.resize(lg);\r\
    \n        buf.resize(lg);\r\n        for(int d=lg-1;d>=0;d--){\r\n           \
    \ vector<char> add;\r\n            vector nxt(2,vector<T>());\r\n            for(auto&\
    \ x:a){\r\n                add.push_back(x>>d&1);\r\n                nxt[x>>d&1].push_back(x);\r\
    \n            }\r\n            mid[d]=(int)nxt[0].size();\r\n            buf[d]=BitVector(add);\r\
    \n            swap(a,nxt[0]);\r\n            a.insert(a.end(),ALL(nxt[1]));\r\n\
    \        }\r\n    }\r\n    int rank(int L,int R,T x){\r\n        if((T(1)<<lg)<=x)return\
    \ 0;\r\n        for(int d=lg-1;d>=0;d--){\r\n            bool f=(x>>d&1);\r\n\
    \            L=buf[d].rank(L,f)+(f?mid[d]:0);\r\n            R=buf[d].rank(R,f)+(f?mid[d]:0);\r\
    \n        }\r\n        return R-L;\r\n    }\r\n    T quantile(int L,int R,int\
    \ k){\r\n        T ret=0;\r\n        for(int d=lg-1;d>=0;d--){\r\n           \
    \ int l0=buf[d].rank(L,0),r0=buf[d].rank(R,0);\r\n            if(k<r0-l0)L=l0,R=r0;\r\
    \n            else{\r\n                k-=r0-l0;\r\n                ret|=T(1)<<d;\r\
    \n                L+=mid[d]-l0,R+=mid[d]-r0;\r\n            }\r\n        }\r\n\
    \        return ret;\r\n    }\r\n    int freq(int L,int R,T x){\r\n        if((T(1)<<lg)<=x)return\
    \ R-L;\r\n        int ret=0;\r\n        for(int d=lg-1;d>=0;d--){\r\n        \
    \    bool f=(x>>d&1);\r\n            if(f)ret+=buf[d].rank(R,0)-buf[d].rank(L,0);\r\
    \n            L=buf[d].rank(L,f)+(f?mid[d]:0);\r\n            R=buf[d].rank(R,f)+(f?mid[d]:0);\r\
    \n        }\r\n        return ret;\r\n    }\r\n    int freq(int L,int R,T a,T\
    \ b){\r\n        return freq(L,R,b)-freq(L,R,a);\r\n    }\r\n    T prev(int L,int\
    \ R,T x){\r\n        int cnt=freq(L,R,x);\r\n        return cnt==R-L?T(-1):quantile(L,R,cnt);\r\
    \n    }\r\n    T next(int L,int R,T x){\r\n        int cnt=freq(L,R,x);\r\n  \
    \      return cnt==0?T(-1):quantile(L,R,cnt-1);\r\n    }\r\n};\r\n\r\n/**\r\n\
    \ * @brief Wavelet Matrix\r\n * @docs docs/wavelet.md\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/wavelet.hpp
  requiredBy: []
  timestamp: '2022-02-06 21:52:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_range_kth_smallest.test.cpp
  - Verify/LC_static_range_frequency.test.cpp
documentation_of: DataStructure/wavelet.hpp
layout: document
redirect_from:
- /library/DataStructure/wavelet.hpp
- /library/DataStructure/wavelet.hpp.html
title: Wavelet Matrix
---
## 使い方

`WaveletMatrix(vector<T> a)`: 数列 $a$ のデータ構造を作成。  
`int rank(int L,int R,T x)`: 半開区間 $[L,R)$ に $x$ が出現する回数。  
`T quantile(int L,int R,int k)`: 半開区間 $[L,R)$ で $k$ 番目 (0-indexed) に小さい値。  
`int freq(int L,int R,T x)`: 半開区間 $[L,R)$ に $x$ 未満が出現する回数。  
`int freq(int L,int R,T a,T b)`: 半開区間 $[L,R)$ に $[a,b]$ 内の値が出現する回数。  
`T prev(int L,int R,T x)`: 半開区間 $[L,R)$ で $x$ 以下の値のうち最も大きいもの。  
`T next(int L,int R,T x)`: 半開区間 $[L,R)$ で $x$ より大きい値のうち最も小さいもの。