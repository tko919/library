---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/wavelet.hpp
    title: Wavelet Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"Verify/LC_range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\r\n#line 1 \"Template/template.hpp\"\
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
    \n * @brief Fast IO\r\n */\n#line 2 \"DataStructure/wavelet.hpp\"\n\r\ntemplate<typename\
    \ T>struct WaveletMatrix{\r\n    struct BitVector{\r\n        vector<unsigned\
    \ long long> buf;\r\n        vector<int> rui;\r\n        BitVector(const vector<char>&\
    \ a={}){\r\n            int n=a.size();\r\n            buf.assign((n+63)>>6,0);\r\
    \n            rui.assign(buf.size()+1,0);\r\n            rep(i,0,n)if(a[i]){\r\
    \n                buf[i>>6]|=1ull<<(i&63);\r\n                rui[(i>>6)+1]++;\r\
    \n            }\r\n            rep(i,0,buf.size())rui[i+1]+=rui[i];\r\n      \
    \  }\r\n        int rank(int k,bool f=1){\r\n            int ret=rui[k>>6]+__builtin_popcountll(buf[k>>6]&((1ull<<(k&63))-1));\r\
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
    \ * @brief Wavelet Matrix\r\n * @docs docs/wavelet.md\r\n */\n#line 6 \"Verify/LC_range_kth_smallest.test.cpp\"\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\n    io.read(n,q);\r\n    vector<int>\
    \ a(n);\r\n    io.read(a);\r\n\r\n    vector<int> zip;\r\n    for(auto& x:a)zip.push_back(x);\r\
    \n    sort(ALL(zip));\r\n    zip.erase(unique(ALL(zip)),zip.end());\r\n    rep(i,0,n)a[i]=lower_bound(ALL(zip),a[i])-zip.begin();\r\
    \n\r\n    WaveletMatrix<int> wm(a);\r\n    int L,R,k;\r\n    while(q--){\r\n \
    \       io.read(L,R,k);\r\n        io.write(zip[wm.quantile(L,R,k)]);\r\n    }\r\
    \n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\r\n\
    \r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\
    #include \"DataStructure/wavelet.hpp\"\r\n\r\nFastIO io;\r\nint main(){\r\n  \
    \  int n,q;\r\n    io.read(n,q);\r\n    vector<int> a(n);\r\n    io.read(a);\r\
    \n\r\n    vector<int> zip;\r\n    for(auto& x:a)zip.push_back(x);\r\n    sort(ALL(zip));\r\
    \n    zip.erase(unique(ALL(zip)),zip.end());\r\n    rep(i,0,n)a[i]=lower_bound(ALL(zip),a[i])-zip.begin();\r\
    \n\r\n    WaveletMatrix<int> wm(a);\r\n    int L,R,k;\r\n    while(q--){\r\n \
    \       io.read(L,R,k);\r\n        io.write(zip[wm.quantile(L,R,k)]);\r\n    }\r\
    \n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/wavelet.hpp
  isVerificationFile: true
  path: Verify/LC_range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_range_kth_smallest.test.cpp
- /verify/Verify/LC_range_kth_smallest.test.cpp.html
title: Verify/LC_range_kth_smallest.test.cpp
---
