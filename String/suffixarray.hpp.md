---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_number_of_substrings.test.cpp
    title: Verify/LC_number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_suffixarray.test.cpp
    title: Verify/LC_suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/suffixarray.md
    document_title: Suffix Array
    links: []
  bundledCode: "#line 2 \"String/suffixarray.hpp\"\n\r\ntemplate<typename T>struct\
    \ SuffixArray{\r\n    T base;\r\n    vector<int> sa,rsa,lcp;\r\n    SuffixArray(const\
    \ T& _s):base(_s){\r\n        int n=base.size();\r\n        auto p=minmax_element(ALL(base));\r\
    \n        int k=*p.second-*p.first+1;\r\n        vector<int> t(n);\r\n       \
    \ rep(i,0,n)t[i]=base[i]-*p.first;\r\n        sais(t,k);\r\n        rsa.assign(n+1,-1);\r\
    \n        rep(i,0,n+1)rsa[sa[i]]=i;\r\n        build(t);\r\n    }\r\n    void\
    \ sais(vector<int> s,int k){\r\n        int n=s.size();\r\n        for(int& c:s)c++;\r\
    \n        s.push_back(0);\r\n        k++;\r\n        vector<bool> iss(n+1);\r\n\
    \        vector<int> lms,bin(k+1,0);\r\n        iss[n]=1;\r\n        bin[1]=1;\r\
    \n        for(int i=n-1;i>=0;i--){\r\n            iss[i]=(s[i]!=s[i+1]?s[i]<s[i+1]:iss[i+1]);\r\
    \n            if(!iss[i]&&iss[i+1])lms.push_back(i+1);\r\n            bin[s[i]+1]++;\r\
    \n        }\r\n        rep(i,0,k)bin[i+1]+=bin[i];\r\n        auto induced=[&](const\
    \ vector<int>& _lms)->void{\r\n            sa.assign(n+1,-1);\r\n            vector<int>\
    \ cnt(k,0);\r\n            for(int x:_lms){\r\n                sa[bin[s[x]+1]-cnt[s[x]]-1]=x;\r\
    \n                cnt[s[x]]++;\r\n            }\r\n            cnt.assign(k,0);\r\
    \n            rep(i,0,n+1){\r\n                int x=sa[i]-1;\r\n            \
    \    if(x>=0&&!iss[x]){\r\n                    sa[bin[s[x]]+cnt[s[x]]]=x;\r\n\
    \                    cnt[s[x]]++;\r\n                }\r\n            }\r\n  \
    \          cnt.assign(k,0);\r\n            for(int i=n;i>=0;i--){\r\n        \
    \        int x=sa[i]-1;\r\n                if(x>=0&&iss[x]){\r\n             \
    \       sa[bin[s[x]+1]-cnt[s[x]]-1]=x;\r\n                    cnt[s[x]]++;\r\n\
    \                }\r\n            }\r\n        };\r\n        induced(lms);\r\n\
    \        if(lms.size()<=1)return;\r\n        int m=lms.size();\r\n        vector<int>\
    \ rev(n+1,-1);\r\n        rep(i,0,m)rev[lms[i]]=i;\r\n        int idx=0,rec_k=1;\r\
    \n        vector<int> lmss(m),rec_s(m);\r\n        for(int x:sa)if(rev[x]!=-1)lmss[idx++]=x;\r\
    \n        rec_s[m-1-rev[lmss[1]]]=1;\r\n        rep(i,2,m){\r\n            int\
    \ xl=lmss[i],yl=lmss[i-1];\r\n            int xr=lms[rev[xl]-1],yr=lms[rev[yl]-1];\r\
    \n            if(xr-xl!=yr-yl)rec_k++;\r\n            else while(xl<=xr){\r\n\
    \                if(s[xl]!=s[yl]){\r\n                    rec_k++;\r\n       \
    \             break;\r\n                }\r\n                xl++,yl++;\r\n  \
    \          }\r\n            rec_s[m-1-rev[lmss[i]]]=rec_k;\r\n        }\r\n  \
    \      sais(rec_s,rec_k+1);\r\n        idx=m;\r\n        rep(i,1,m+1)lmss[--idx]=lms[m-1-sa[i]];\r\
    \n        induced(lmss);\r\n    }\r\n    void build(const vector<int>& s){\r\n\
    \        int n=s.size(),k=0;\r\n        lcp.resize(n);\r\n        rep(i,0,n+1){\r\
    \n            if(rsa[i]){\r\n                for(int j=sa[rsa[i]-1];max(i,j)+k<n;k++){\r\
    \n                    if(s[i+k]!=s[j+k])break;\r\n                }\r\n      \
    \          lcp[rsa[i]-1]=k;\r\n            }\r\n            if(k)k--;\r\n    \
    \    }\r\n    }\r\n    array<int,2> search(const T& t){\r\n        int n=sa.size(),m=t.size();\r\
    \n        array<int,2> ret;\r\n        int L=0,R=n;\r\n        while(R-L>1){\r\
    \n            int mid=(L+R)>>1;\r\n            if(base.compare(sa[mid],m,t)<0)L=mid;\r\
    \n            else R=mid;\r\n        }\r\n        ret[0]=R;\r\n        L=0,R=n;\r\
    \n        while(R-L>1){\r\n            int mid=(L+R)>>1;\r\n            if(base.compare(sa[mid],m,t)<=0)L=mid;\r\
    \n            else R=mid;\r\n        }\r\n        ret[1]=R;\r\n        return\
    \ ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Suffix Array\r\n * @docs docs/suffixarray.md\r\
    \n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct SuffixArray{\r\n    T base;\r\
    \n    vector<int> sa,rsa,lcp;\r\n    SuffixArray(const T& _s):base(_s){\r\n  \
    \      int n=base.size();\r\n        auto p=minmax_element(ALL(base));\r\n   \
    \     int k=*p.second-*p.first+1;\r\n        vector<int> t(n);\r\n        rep(i,0,n)t[i]=base[i]-*p.first;\r\
    \n        sais(t,k);\r\n        rsa.assign(n+1,-1);\r\n        rep(i,0,n+1)rsa[sa[i]]=i;\r\
    \n        build(t);\r\n    }\r\n    void sais(vector<int> s,int k){\r\n      \
    \  int n=s.size();\r\n        for(int& c:s)c++;\r\n        s.push_back(0);\r\n\
    \        k++;\r\n        vector<bool> iss(n+1);\r\n        vector<int> lms,bin(k+1,0);\r\
    \n        iss[n]=1;\r\n        bin[1]=1;\r\n        for(int i=n-1;i>=0;i--){\r\
    \n            iss[i]=(s[i]!=s[i+1]?s[i]<s[i+1]:iss[i+1]);\r\n            if(!iss[i]&&iss[i+1])lms.push_back(i+1);\r\
    \n            bin[s[i]+1]++;\r\n        }\r\n        rep(i,0,k)bin[i+1]+=bin[i];\r\
    \n        auto induced=[&](const vector<int>& _lms)->void{\r\n            sa.assign(n+1,-1);\r\
    \n            vector<int> cnt(k,0);\r\n            for(int x:_lms){\r\n      \
    \          sa[bin[s[x]+1]-cnt[s[x]]-1]=x;\r\n                cnt[s[x]]++;\r\n\
    \            }\r\n            cnt.assign(k,0);\r\n            rep(i,0,n+1){\r\n\
    \                int x=sa[i]-1;\r\n                if(x>=0&&!iss[x]){\r\n    \
    \                sa[bin[s[x]]+cnt[s[x]]]=x;\r\n                    cnt[s[x]]++;\r\
    \n                }\r\n            }\r\n            cnt.assign(k,0);\r\n     \
    \       for(int i=n;i>=0;i--){\r\n                int x=sa[i]-1;\r\n         \
    \       if(x>=0&&iss[x]){\r\n                    sa[bin[s[x]+1]-cnt[s[x]]-1]=x;\r\
    \n                    cnt[s[x]]++;\r\n                }\r\n            }\r\n \
    \       };\r\n        induced(lms);\r\n        if(lms.size()<=1)return;\r\n  \
    \      int m=lms.size();\r\n        vector<int> rev(n+1,-1);\r\n        rep(i,0,m)rev[lms[i]]=i;\r\
    \n        int idx=0,rec_k=1;\r\n        vector<int> lmss(m),rec_s(m);\r\n    \
    \    for(int x:sa)if(rev[x]!=-1)lmss[idx++]=x;\r\n        rec_s[m-1-rev[lmss[1]]]=1;\r\
    \n        rep(i,2,m){\r\n            int xl=lmss[i],yl=lmss[i-1];\r\n        \
    \    int xr=lms[rev[xl]-1],yr=lms[rev[yl]-1];\r\n            if(xr-xl!=yr-yl)rec_k++;\r\
    \n            else while(xl<=xr){\r\n                if(s[xl]!=s[yl]){\r\n   \
    \                 rec_k++;\r\n                    break;\r\n                }\r\
    \n                xl++,yl++;\r\n            }\r\n            rec_s[m-1-rev[lmss[i]]]=rec_k;\r\
    \n        }\r\n        sais(rec_s,rec_k+1);\r\n        idx=m;\r\n        rep(i,1,m+1)lmss[--idx]=lms[m-1-sa[i]];\r\
    \n        induced(lmss);\r\n    }\r\n    void build(const vector<int>& s){\r\n\
    \        int n=s.size(),k=0;\r\n        lcp.resize(n);\r\n        rep(i,0,n+1){\r\
    \n            if(rsa[i]){\r\n                for(int j=sa[rsa[i]-1];max(i,j)+k<n;k++){\r\
    \n                    if(s[i+k]!=s[j+k])break;\r\n                }\r\n      \
    \          lcp[rsa[i]-1]=k;\r\n            }\r\n            if(k)k--;\r\n    \
    \    }\r\n    }\r\n    array<int,2> search(const T& t){\r\n        int n=sa.size(),m=t.size();\r\
    \n        array<int,2> ret;\r\n        int L=0,R=n;\r\n        while(R-L>1){\r\
    \n            int mid=(L+R)>>1;\r\n            if(base.compare(sa[mid],m,t)<0)L=mid;\r\
    \n            else R=mid;\r\n        }\r\n        ret[0]=R;\r\n        L=0,R=n;\r\
    \n        while(R-L>1){\r\n            int mid=(L+R)>>1;\r\n            if(base.compare(sa[mid],m,t)<=0)L=mid;\r\
    \n            else R=mid;\r\n        }\r\n        ret[1]=R;\r\n        return\
    \ ret;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Suffix Array\r\n * @docs docs/suffixarray.md\r\
    \n */"
  dependsOn: []
  isVerificationFile: false
  path: String/suffixarray.hpp
  requiredBy: []
  timestamp: '2022-02-05 01:38:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_number_of_substrings.test.cpp
  - Verify/LC_suffixarray.test.cpp
documentation_of: String/suffixarray.hpp
layout: document
redirect_from:
- /library/String/suffixarray.hpp
- /library/String/suffixarray.hpp.html
title: Suffix Array
---
## 使い方

`SuffixArray(const T& s)`: $s$ の Suffix Array (**1-indexed**) 及び LCP 配列を作成。  
`array<int,2> search(const T& t)`: $t$ を完全に含むような Suffix Array の index 区間。