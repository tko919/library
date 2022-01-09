---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"Verify/LC_many_aplusb.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
    \r\n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\
    \nconst ll INF = 0x1fffffffffffffff;\r\ntemplate<typename T>inline bool chmax(T&\
    \ a,T b){if(a<b){a=b;return 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T&\
    \ a,T b){if(a>b){a=b;return 1;}return 0;}\n#line 2 \"Utility/fastio.hpp\"\n#include\
    \ <unistd.h>\r\n\r\nclass FastIO{\r\n    static constexpr int L=1<<16;\r\n   \
    \ char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\
    \n        int len=rdRight-rdLeft;\r\n        memmove(rdbuf,rdbuf+rdLeft,len);\r\
    \n        rdLeft=0,rdRight=len;\r\n        rdRight+=fread(rdbuf+len,1,L-len,stdin);\r\
    \n        rdbuf[rdRight]='\\0';\r\n    }\r\n    inline bool skip(){\r\n      \
    \  for(;;){\r\n            while(rdLeft!=rdRight and rdbuf[rdLeft]<=' ')rdLeft++;\r\
    \n            if(rdLeft==rdRight){\r\n                reload();\r\n          \
    \      if(rdLeft==rdRight)return false;\r\n            }\r\n            else break;\r\
    \n        }\r\n        return true;\r\n    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int>\
    \ =0>inline bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0')x=x*10+(rdbuf[rdLeft++]^48);\r\
    \n        if(neg)x=-x;\r\n        return true;\r\n    }\r\n    template<typename\
    \ T,enable_if_t<is_floating_point<T>::value,int> =0>inline bool _read(T& x){\r\
    \n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9')x=x*10+(rdbuf[rdLeft++]^48);\r\n        if(rdbuf[rdLeft]!='.')return\
    \ true;\r\n        rdLeft++;\r\n        T base=.1;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9'){\r\n            x+=base*(rdbuf[rdLeft++]^48);\r\n  \
    \          base*=.1;\r\n        }\r\n        if(neg)x=-x;\r\n        return true;\r\
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
    \ if(x<0){\r\n            _write('-');\r\n            x=-x;\r\n        }\r\n \
    \       int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
    \n            x/=10;\r\n        }\r\n        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];\r\
    \n        wtRight+=pos;\r\n    }\r\n    template<typename T>inline void _write(vector<T>&\
    \ v){\r\n        rep(i,0,v.size()){\r\n            if(i)_write(' ');\r\n     \
    \       _write(v[i]);\r\n        }\r\n    }\r\npublic:\r\n    FastIO(){}\r\n \
    \   ~FastIO(){flush();}\r\n    inline void read(){}\r\n    template <typename\
    \ Head, typename... Tail>inline void read(Head& head,Tail&... tail){\r\n     \
    \   assert(_read(head));\r\n        read(tail...); \r\n    }\r\n    template<bool\
    \ space=false>inline void write(){_write('\\n');}\r\n    template <bool space=false,typename\
    \ Head, typename... Tail>inline void write(const Head& head,const Tail&... tail){\r\
    \n        if(space)_write(' ');\r\n        _write(head);\r\n        write<true>(tail...);\
    \ \r\n    }\r\n};\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_many_aplusb.test.cpp\"\
    \n\r\nint main(){\r\n    FastIO io;\r\n    int t;\r\n    ll a,b;\r\n    io.read(t);\r\
    \n    while(t--){\r\n        io.read(a,b);\r\n        io.write(a+b);\r\n    }\r\
    \n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\r\nint main(){\r\
    \n    FastIO io;\r\n    int t;\r\n    ll a,b;\r\n    io.read(t);\r\n    while(t--){\r\
    \n        io.read(a,b);\r\n        io.write(a+b);\r\n    }\r\n    return 0;\r\n\
    }"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  isVerificationFile: true
  path: Verify/LC_many_aplusb.test.cpp
  requiredBy: []
  timestamp: '2022-01-09 05:20:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_many_aplusb.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_many_aplusb.test.cpp
- /verify/Verify/LC_many_aplusb.test.cpp.html
title: Verify/LC_many_aplusb.test.cpp
---
