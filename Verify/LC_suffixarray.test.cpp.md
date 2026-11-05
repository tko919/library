---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: String/suffixarray.hpp
    title: Suffix Array
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"Verify/LC_suffixarray.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\
    \n#define rrep(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define\
    \ ALL(v) (v).begin(), (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)),\
    \ (v).end())\r\n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\
    \n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v),\
    \ (x)) - (v).begin())\r\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\
    \n\r\nusing uint = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned\
    \ long long;\r\nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst\
    \ int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate\
    \ <typename T, typename S = T> S SUM(const vector<T> &a) {\r\n    return accumulate(ALL(a),\
    \ S(0));\r\n}\r\ntemplate <typename S, typename T = S> S POW(S a, T b) {\r\n \
    \   S ret = 1, base = a;\r\n    for (;;) {\r\n        if (b & 1)\r\n         \
    \   ret *= base;\r\n        b >>= 1;\r\n        if (b == 0)\r\n            break;\r\
    \n        base *= base;\r\n    }\r\n    return ret;\r\n}\r\ntemplate <typename\
    \ T> inline bool chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a = b;\r\n\
    \        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T> inline\
    \ bool chmin(T &a, T b) {\r\n    if (a > b) {\r\n        a = b;\r\n        return\
    \ 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T, typename U> T ceil(T\
    \ x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x = -x, y = -y;\r\
    \n    return (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate <typename T,\
    \ typename U> T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n\
    \        x = -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1) / y);\r\n\
    }\r\ntemplate <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\
    \n}\r\ntemplate <typename T> int topbit(T x) {\r\n    return (x == 0 ? -1 : 63\
    \ - __builtin_clzll(x));\r\n}\r\ntemplate <typename T> int lowbit(T x) {\r\n \
    \   return (x == 0 ? -1 : __builtin_ctzll(x));\r\n}\r\n\r\ntemplate <class T,\
    \ class U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p) {\r\n    os\
    \ << \"P(\" << p.first << \", \" << p.second << \")\";\r\n    return os;\r\n}\r\
    \ntemplate <typename T> ostream &operator<<(ostream &os, const vector<T> &vec)\
    \ {\r\n    os << \"{\";\r\n    for (int i = 0; i < vec.size(); i++) {\r\n    \
    \    os << vec[i] << (i + 1 == vec.size() ? \"\" : \", \");\r\n    }\r\n    os\
    \ << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename T, typename U>\r\nostream\
    \ &operator<<(ostream &os, const map<T, U> &map_var) {\r\n    os << \"{\";\r\n\
    \    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {\r\n     \
    \   os << \"(\" << itr->first << \", \" << itr->second << \")\";\r\n        itr++;\r\
    \n        if (itr != map_var.end())\r\n            os << \", \";\r\n        itr--;\r\
    \n    }\r\n    os << \"}\";\r\n    return os;\r\n}\r\ntemplate <typename T> ostream\
    \ &operator<<(ostream &os, const set<T> &set_var) {\r\n    os << \"{\";\r\n  \
    \  for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {\r\n       \
    \ os << *itr;\r\n        ++itr;\r\n        if (itr != set_var.end())\r\n     \
    \       os << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n    return\
    \ os;\r\n}\r\n#ifdef LOCAL\r\n#define debug 1\r\n#define show(...) _show(0, #__VA_ARGS__,\
    \ __VA_ARGS__)\r\n#else\r\n#define debug 0\r\n#define show(...) true\r\n#endif\r\
    \ntemplate <typename T> void _show(int i, T name) {\r\n    cerr << '\\n';\r\n\
    }\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid _show(int i,\
    \ const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i] != ',' && a[i]\
    \ != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\" << b << \" \";\r\
    \n    _show(i + 1, a, c...);\r\n}\n#line 2 \"String/suffixarray.hpp\"\n\r\ntemplate<typename\
    \ T>struct SuffixArray{\r\n    T base;\r\n    vector<int> sa,rsa,lcp;\r\n    SuffixArray(const\
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
    \n */\n#line 5 \"Verify/LC_suffixarray.test.cpp\"\n\r\nint main(){\r\n    string\
    \ s;\r\n    cin>>s;\r\n    SuffixArray sa(s);\r\n    rep(i,1,s.size()+1)cout<<sa.sa[i]<<'\\\
    n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"String/suffixarray.hpp\"\r\n\r\nint\
    \ main(){\r\n    string s;\r\n    cin>>s;\r\n    SuffixArray sa(s);\r\n    rep(i,1,s.size()+1)cout<<sa.sa[i]<<'\\\
    n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - String/suffixarray.hpp
  isVerificationFile: true
  path: Verify/LC_suffixarray.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_suffixarray.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_suffixarray.test.cpp
- /verify/Verify/LC_suffixarray.test.cpp.html
title: Verify/LC_suffixarray.test.cpp
---
