---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/dequeswag.hpp
    title: Sliding Window Aggregation for deque
  - icon: ':question:'
    path: Math/modint.hpp
    title: Modint
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
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"Verify/LC_deque_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\r\n\r\
    \n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_deque_operate_all_composite.test.cpp\"\
    \n\r\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate<int mod=1000000007>struct fp {\r\
    \n    int v;\r\n    static constexpr int get_mod(){return mod;}\r\n    int inv()\
    \ const{\r\n        int tmp,a=v,b=mod,x=1,y=0;\r\n        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);\r\
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
    #line 2 \"DataStructure/dequeswag.hpp\"\n\r\ntemplate<typename M,M (*f)(M,M),M\
    \ (*m0)()>struct SWAGdeque{\r\n    stack<M> fval,bval;\r\n    vector<M> fsum,bsum;\r\
    \n    SWAGdeque():fsum({m0()}),bsum({m0()}){}\r\n    M fold(){\r\n        return\
    \ f(fsum.back(),bsum.back());\r\n    }\r\n    void push_front(M v){\r\n      \
    \  fval.push(v);\r\n        fsum.push_back(f(v,fsum.back()));\r\n    }\r\n   \
    \ void push_back(M v){\r\n        bval.push(v);\r\n        bsum.push_back(f(bsum.back(),v));\r\
    \n    }\r\n    void pop_front(){\r\n        if(fval.empty()){\r\n            int\
    \ sz=bval.size();\r\n            stack<M> buf;\r\n            rep(_,0,sz/2){\r\
    \n                buf.push(bval.top());\r\n                bval.pop();\r\n   \
    \         }\r\n            rep(_,sz/2,sz){\r\n                fval.push(bval.top());\r\
    \n                fsum.push_back(f(bval.top(),fsum.back()));\r\n             \
    \   bval.pop();\r\n            }\r\n            bsum={m0()};\r\n            while(!buf.empty()){\r\
    \n                bval.push(buf.top());\r\n                bsum.push_back(f(bsum.back(),buf.top()));\r\
    \n                buf.pop();\r\n            }\r\n        }\r\n        fval.pop();\r\
    \n        fsum.pop_back();\r\n    }\r\n    void pop_back(){\r\n        if(bval.empty()){\r\
    \n            int sz=fval.size();\r\n            stack<M> buf;\r\n           \
    \ rep(_,0,sz/2){\r\n                buf.push(fval.top());\r\n                fval.pop();\r\
    \n            }\r\n            rep(_,sz/2,sz){\r\n                bval.push(fval.top());\r\
    \n                bsum.push_back(f(bsum.back(),fval.top()));\r\n             \
    \   fval.pop();\r\n            }\r\n            fsum={m0()};\r\n            while(!buf.empty()){\r\
    \n                fval.push(buf.top());\r\n                fsum.push_back(f(buf.top(),fsum.back()));\r\
    \n                buf.pop();\r\n            }\r\n        }\r\n        bval.pop();\r\
    \n        bsum.pop_back();\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Sliding Window\
    \ Aggregation for deque\r\n */\n#line 8 \"Verify/LC_deque_operate_all_composite.test.cpp\"\
    \n\r\nusing Fp=fp<998244353>;\r\nusing P=pair<Fp,Fp>;\r\nP f(P a,P b){return {a.first*b.first,a.second*b.first+b.second};}\r\
    \nP e0(){return {1,0};}\r\n\r\nFastIO io;\r\nint main(){\r\n    int Q;\r\n   \
    \ io.read(Q);\r\n    SWAGdeque<P,f,e0> swag;\r\n    while(Q--){\r\n        int\
    \ t;\r\n        io.read(t);\r\n        if(t==0){\r\n            int a,b;\r\n \
    \           io.read(a,b);\r\n            swag.push_front({a,b});\r\n        }\r\
    \n        if(t==1){\r\n            int a,b;\r\n            io.read(a,b);\r\n \
    \           swag.push_back({a,b});\r\n        }\r\n        if(t==2)swag.pop_front();\r\
    \n        if(t==3)swag.pop_back();\r\n        if(t==4){\r\n            int x;\r\
    \n            io.read(x);\r\n            auto [p,q]=swag.fold();\r\n         \
    \   io.write((p*x+q).v);\r\n        }\r\n    }\r\n    return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n\r\n#include \"Math/modint.hpp\"\r\n#include \"DataStructure/dequeswag.hpp\"\
    \r\n\r\nusing Fp=fp<998244353>;\r\nusing P=pair<Fp,Fp>;\r\nP f(P a,P b){return\
    \ {a.first*b.first,a.second*b.first+b.second};}\r\nP e0(){return {1,0};}\r\n\r\
    \nFastIO io;\r\nint main(){\r\n    int Q;\r\n    io.read(Q);\r\n    SWAGdeque<P,f,e0>\
    \ swag;\r\n    while(Q--){\r\n        int t;\r\n        io.read(t);\r\n      \
    \  if(t==0){\r\n            int a,b;\r\n            io.read(a,b);\r\n        \
    \    swag.push_front({a,b});\r\n        }\r\n        if(t==1){\r\n           \
    \ int a,b;\r\n            io.read(a,b);\r\n            swag.push_back({a,b});\r\
    \n        }\r\n        if(t==2)swag.pop_front();\r\n        if(t==3)swag.pop_back();\r\
    \n        if(t==4){\r\n            int x;\r\n            io.read(x);\r\n     \
    \       auto [p,q]=swag.fold();\r\n            io.write((p*x+q).v);\r\n      \
    \  }\r\n    }\r\n    return 0;\r\n}\r\n"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - DataStructure/dequeswag.hpp
  isVerificationFile: true
  path: Verify/LC_deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_deque_operate_all_composite.test.cpp
- /verify/Verify/LC_deque_operate_all_composite.test.cpp.html
title: Verify/LC_deque_operate_all_composite.test.cpp
---
