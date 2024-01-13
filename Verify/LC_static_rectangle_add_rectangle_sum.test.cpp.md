---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/bit.hpp
    title: Binary Indexed Tree
  - icon: ':x:'
    path: DataStructure/staticrectaddrectsum.hpp
    title: Static Rectangle Add Rectangle Sum
  - icon: ':x:'
    path: DataStructure/staticrectsum.hpp
    title: Static Rectangle Sum
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
    PROBLEM: https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum
  bundledCode: "#line 1 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define\
    \ ALL(v) (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\
    \n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define\
    \ MAX(v) *max_element(ALL(v))\r\n#define LB(v,x) int(lower_bound(ALL(v),(x))-(v).begin())\r\
    \n#define UB(v,x) int(upper_bound(ALL(v),(x))-(v).begin())\r\n\r\nusing ll=long\
    \ long int;\r\nusing ull=unsigned long long;\r\nusing i128=__int128_t;\r\nusing\
    \ u128=__uint128_t;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y;\
    \ return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename U>T floor(T x,U\
    \ y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\ntemplate<typename\
    \ T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename T>int\
    \ topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename T>int\
    \ lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\n\r\nclass FastIO {\r\n    static constexpr int L = 1\
    \ << 16;\r\n    char rdbuf[L];\r\n    int rdLeft = 0, rdRight = 0;\r\n    inline\
    \ void reload() {\r\n        int len = rdRight - rdLeft;\r\n        memmove(rdbuf,\
    \ rdbuf + rdLeft, len);\r\n        rdLeft = 0, rdRight = len;\r\n        rdRight\
    \ += fread(rdbuf + len, 1, L - len, stdin);\r\n    }\r\n    inline bool skip()\
    \ {\r\n        for (;;) {\r\n            while (rdLeft != rdRight and rdbuf[rdLeft]\
    \ <= ' ')\r\n                rdLeft++;\r\n            if (rdLeft == rdRight) {\r\
    \n                reload();\r\n                if (rdLeft == rdRight)\r\n    \
    \                return false;\r\n            } else\r\n                break;\r\
    \n        }\r\n        return true;\r\n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n     \
    \       return false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\
    \n        bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n       \
    \     neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n\
    \        while (rdbuf[rdLeft] >= '0' and rdLeft < rdRight) {\r\n            x\
    \ = x * 10 +\r\n                (neg ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++]\
    \ ^ 48));\r\n        }\r\n        return true;\r\n    }\r\n    inline bool _read(__int128_t\
    \ &x) {\r\n        if (!skip())\r\n            return false;\r\n        if (rdLeft\
    \ + 40 >= rdRight)\r\n            reload();\r\n        bool neg = false;\r\n \
    \       if (rdbuf[rdLeft] == '-') {\r\n            neg = true;\r\n           \
    \ rdLeft++;\r\n        }\r\n        x = 0;\r\n        while (rdbuf[rdLeft] >=\
    \ '0' and rdLeft < rdRight) {\r\n            x = x * 10 +\r\n                (neg\
    \ ? -(rdbuf[rdLeft++] ^ 48) : (rdbuf[rdLeft++] ^ 48));\r\n        }\r\n      \
    \  return true;\r\n    }\r\n    inline bool _read(__uint128_t &x) {\r\n      \
    \  if (!skip())\r\n            return false;\r\n        if (rdLeft + 40 >= rdRight)\r\
    \n            reload();\r\n        x = 0;\r\n        while (rdbuf[rdLeft] >= '0'\
    \ and rdLeft < rdRight) {\r\n            x = x * 10 + (rdbuf[rdLeft++] ^ 48);\r\
    \n        }\r\n        return true;\r\n    }\r\n    template <typename T, enable_if_t<is_floating_point<T>::value,\
    \ int> = 0>\r\n    inline bool _read(T &x) {\r\n        if (!skip())\r\n     \
    \       return false;\r\n        if (rdLeft + 20 >= rdRight)\r\n            reload();\r\
    \n        bool neg = false;\r\n        if (rdbuf[rdLeft] == '-') {\r\n       \
    \     neg = true;\r\n            rdLeft++;\r\n        }\r\n        x = 0;\r\n\
    \        while (rdbuf[rdLeft] >= '0' and rdbuf[rdLeft] <= '9' and\r\n        \
    \       rdLeft < rdRight) {\r\n            x = x * 10 + (rdbuf[rdLeft++] ^ 48);\r\
    \n        }\r\n        if (rdbuf[rdLeft] != '.')\r\n            return true;\r\
    \n        rdLeft++;\r\n        T base = .1;\r\n        while (rdbuf[rdLeft] >=\
    \ '0' and rdbuf[rdLeft] <= '9' and\r\n               rdLeft < rdRight) {\r\n \
    \           x += base * (rdbuf[rdLeft++] ^ 48);\r\n            base *= .1;\r\n\
    \        }\r\n        if (neg)\r\n            x = -x;\r\n        return true;\r\
    \n    }\r\n    inline bool _read(char &x) {\r\n        if (!skip())\r\n      \
    \      return false;\r\n        if (rdLeft + 1 >= rdRight)\r\n            reload();\r\
    \n        x = rdbuf[rdLeft++];\r\n        return true;\r\n    }\r\n    inline\
    \ bool _read(string &x) {\r\n        if (!skip())\r\n            return false;\r\
    \n        for (;;) {\r\n            int pos = rdLeft;\r\n            while (pos\
    \ < rdRight and rdbuf[pos] > ' ')\r\n                pos++;\r\n            x.append(rdbuf\
    \ + rdLeft, pos - rdLeft);\r\n            if (rdLeft == pos)\r\n             \
    \   break;\r\n            rdLeft = pos;\r\n            if (rdLeft == rdRight)\r\
    \n                reload();\r\n            else\r\n                break;\r\n\
    \        }\r\n        return true;\r\n    }\r\n    template <typename T> inline\
    \ bool _read(vector<T> &v) {\r\n        for (auto &x : v) {\r\n            if\
    \ (!_read(x))\r\n                return false;\r\n        }\r\n        return\
    \ true;\r\n    }\r\n\r\n    char wtbuf[L], tmp[50];\r\n    int wtRight = 0;\r\n\
    \    inline void _write(const char &x) {\r\n        if (wtRight > L - 32)\r\n\
    \            flush();\r\n        wtbuf[wtRight++] = x;\r\n    }\r\n    inline\
    \ void _write(const string &x) {\r\n        for (auto &c : x)\r\n            _write(c);\r\
    \n    }\r\n    template <typename T, enable_if_t<is_integral<T>::value, int> =\
    \ 0>\r\n    inline void _write(T x) {\r\n        if (wtRight > L - 32)\r\n   \
    \         flush();\r\n        if (x == 0) {\r\n            _write('0');\r\n  \
    \          return;\r\n        } else if (x < 0) {\r\n            _write('-');\r\
    \n            if (__builtin_expect(x == std::numeric_limits<T>::min(), 0)) {\r\
    \n                switch (sizeof(x)) {\r\n                case 2:\r\n        \
    \            _write(\"32768\");\r\n                    return;\r\n           \
    \     case 4:\r\n                    _write(\"2147483648\");\r\n             \
    \       return;\r\n                case 8:\r\n                    _write(\"9223372036854775808\"\
    );\r\n                    return;\r\n                }\r\n            }\r\n  \
    \          x = -x;\r\n        }\r\n        int pos = 0;\r\n        while (x !=\
    \ 0) {\r\n            tmp[pos++] = char((x % 10) | 48);\r\n            x /= 10;\r\
    \n        }\r\n        rep(i, 0, pos) wtbuf[wtRight + i] = tmp[pos - 1 - i];\r\
    \n        wtRight += pos;\r\n    }\r\n    inline void _write(__int128_t x) {\r\
    \n        if (wtRight > L - 40)\r\n            flush();\r\n        if (x == 0)\
    \ {\r\n            _write('0');\r\n            return;\r\n        } else if (x\
    \ < 0) {\r\n            _write('-');\r\n            x = -x;\r\n        }\r\n \
    \       int pos = 0;\r\n        while (x != 0) {\r\n            tmp[pos++] = char((x\
    \ % 10) | 48);\r\n            x /= 10;\r\n        }\r\n        rep(i, 0, pos)\
    \ wtbuf[wtRight + i] = tmp[pos - 1 - i];\r\n        wtRight += pos;\r\n    }\r\
    \n    inline void _write(__uint128_t x) {\r\n        if (wtRight > L - 40)\r\n\
    \            flush();\r\n        if (x == 0) {\r\n            _write('0');\r\n\
    \            return;\r\n        }\r\n        int pos = 0;\r\n        while (x\
    \ != 0) {\r\n            tmp[pos++] = char((x % 10) | 48);\r\n            x /=\
    \ 10;\r\n        }\r\n        rep(i, 0, pos) wtbuf[wtRight + i] = tmp[pos - 1\
    \ - i];\r\n        wtRight += pos;\r\n    }\r\n    inline void _write(double x)\
    \ {\r\n        ostringstream oss;\r\n        oss << fixed << setprecision(15)\
    \ << double(x);\r\n        string s = oss.str();\r\n        _write(s);\r\n   \
    \ }\r\n    template <typename T> inline void _write(const vector<T> &v) {\r\n\
    \        rep(i, 0, v.size()) {\r\n            if (i)\r\n                _write('\
    \ ');\r\n            _write(v[i]);\r\n        }\r\n    }\r\n\r\n  public:\r\n\
    \    FastIO() {}\r\n    ~FastIO() { flush(); }\r\n    inline void read() {}\r\n\
    \    template <typename Head, typename... Tail>\r\n    inline void read(Head &head,\
    \ Tail &...tail) {\r\n        assert(_read(head));\r\n        read(tail...);\r\
    \n    }\r\n    template <bool ln = true, bool space = false> inline void write()\
    \ {\r\n        if (ln)\r\n            _write('\\n');\r\n    }\r\n    template\
    \ <bool ln = true, bool space = false, typename Head,\r\n              typename...\
    \ Tail>\r\n    inline void write(const Head &head, const Tail &...tail) {\r\n\
    \        if (space)\r\n            _write(' ');\r\n        _write(head);\r\n \
    \       write<ln, true>(tail...);\r\n    }\r\n    inline void flush() {\r\n  \
    \      fwrite(wtbuf, 1, wtRight, stdout);\r\n        wtRight = 0;\r\n    }\r\n\
    };\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\
    \n\n#line 2 \"Math/modint.hpp\"\n\r\ntemplate <int mod = 1000000007> struct fp\
    \ {\r\n    int v;\r\n    static constexpr int get_mod() { return mod; }\r\n  \
    \  constexpr int inv() const {\r\n        assert(v != 0);\r\n        int x = v,\
    \ y = mod, u = 1, v = 0, t = 0, tmp = 0;\r\n        while (y > 0) {\r\n      \
    \      t = x / y;\r\n            x -= t * y, u -= t * v;\r\n            tmp =\
    \ x, x = y, y = tmp;\r\n            tmp = u, u = v, v = tmp;\r\n        }\r\n\
    \        return u;\r\n    }\r\n    constexpr fp(ll x = 0) : v(x >= 0 ? x % mod\
    \ : (mod - (-x) % mod) % mod) {}\r\n    fp operator-() const { return fp() - *this;\
    \ }\r\n    fp pow(ll t) {\r\n        assert(t >= 0);\r\n        fp res = 1, b\
    \ = *this;\r\n        while (t) {\r\n            if (t & 1)\r\n              \
    \  res *= b;\r\n            b *= b;\r\n            t >>= 1;\r\n        }\r\n \
    \       return res;\r\n    }\r\n    fp &operator+=(const fp &x) {\r\n        if\
    \ ((v += x.v) >= mod)\r\n            v -= mod;\r\n        return *this;\r\n  \
    \  }\r\n    fp &operator-=(const fp &x) {\r\n        if ((v += mod - x.v) >= mod)\r\
    \n            v -= mod;\r\n        return *this;\r\n    }\r\n    fp &operator*=(const\
    \ fp &x) {\r\n        v = ll(v) * x.v % mod;\r\n        return *this;\r\n    }\r\
    \n    fp &operator/=(const fp &x) {\r\n        v = ll(v) * x.inv() % mod;\r\n\
    \        return *this;\r\n    }\r\n    fp operator+(const fp &x) const { return\
    \ fp(*this) += x; }\r\n    fp operator-(const fp &x) const { return fp(*this)\
    \ -= x; }\r\n    fp operator*(const fp &x) const { return fp(*this) *= x; }\r\n\
    \    fp operator/(const fp &x) const { return fp(*this) /= x; }\r\n    bool operator==(const\
    \ fp &x) const { return v == x.v; }\r\n    bool operator!=(const fp &x) const\
    \ { return v != x.v; }\r\n    friend istream &operator>>(istream &is, fp &x) {\
    \ return is >> x.v; }\r\n    friend ostream &operator<<(ostream &os, const fp\
    \ &x) { return os << x.v; }\r\n};\r\n\r\ntemplate <typename T> T Inv(ll n) {\r\
    \n    static const int md = T::get_mod();\r\n    static vector<T> buf({0, 1});\r\
    \n    assert(n > 0);\r\n    n %= md;\r\n    while (SZ(buf) <= n) {\r\n       \
    \ int k = SZ(buf), q = (md + k - 1) / k;\r\n        buf.push_back(buf[k * q -\
    \ md] * q);\r\n    }\r\n    return buf[n];\r\n}\r\n\r\ntemplate <typename T> T\
    \ Fact(ll n, bool inv = 0) {\r\n    static const int md = T::get_mod();\r\n  \
    \  static vector<T> buf({1, 1}), ibuf({1, 1});\r\n    assert(n >= 0 and n < md);\r\
    \n    while (SZ(buf) <= n) {\r\n        buf.push_back(buf.back() * SZ(buf));\r\
    \n        ibuf.push_back(ibuf.back() * Inv<T>(SZ(ibuf)));\r\n    }\r\n    return\
    \ inv ? ibuf[n] : buf[n];\r\n}\r\n\r\ntemplate <typename T> T nPr(int n, int r,\
    \ bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\n        return 0;\r\n\
    \    return Fact<T>(n, inv) * Fact<T>(n - r, inv ^ 1);\r\n}\r\ntemplate <typename\
    \ T> T nCr(int n, int r, bool inv = 0) {\r\n    if (n < 0 || n < r || r < 0)\r\
    \n        return 0;\r\n    return Fact<T>(n, inv) * Fact<T>(r, inv ^ 1) * Fact<T>(n\
    \ - r, inv ^ 1);\r\n}\r\ntemplate <typename T> T nHr(int n, int r, bool inv =\
    \ 0) {\r\n    return nCr<T>(n + r - 1, r, inv);\r\n}\r\n\r\n/**\r\n * @brief Modint\r\
    \n */\n#line 7 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\nusing\
    \ Fp=fp<998244353>;\n\n#line 2 \"DataStructure/staticrectaddrectsum.hpp\"\n\n\
    #line 2 \"DataStructure/bit.hpp\"\n\r\ntemplate<typename T>struct BIT{\r\n   \
    \ int n; T all=0; vector<T> val;\r\n    BIT(int _n=0):n(_n),val(_n+10){}\r\n \
    \   void clear(){val.assign(n+10,0); all=T();}\r\n    void add(int i,T x){\r\n\
    \        for(i++;i<=n;i+=(i&-i))val[i]=val[i]+x;\r\n        all+=x;\r\n    }\r\
    \n    T sum(int i){\r\n        T res=0;\r\n        for(;i;i-=(i&-i))res+=val[i];\r\
    \n        return res;\r\n    }\r\n    T sum(int L,int R){return sum(R)-sum(L);}\
    \ // [L,R)\r\n    int lower_bound(T x){\r\n        int ret=0,len=1;\r\n      \
    \  while(2*len<=n)len<<=1;\r\n        for(;len>=1;len>>=1){\r\n            if(ret+len<=n\
    \ and val[ret+len]<x){\r\n                ret+=len;\r\n                x-=val[ret];\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Binary Indexed Tree\r\n */\n#line 3 \"DataStructure/staticrectsum.hpp\"\
    \n\ntemplate<class T>struct StaticRectangleSum{\n    struct P{\n        ll x,y;\
    \ T w;\n    };\n    struct Rect{\n        ll l,d,r,u;\n    };\n    struct Q{\n\
    \        ll x,d,u,id,inv;\n    };\n    vector<P> plus;\n    vector<Rect> que;\n\
    \    StaticRectangleSum(){}\n    void add(ll x,ll y,T w){\n        plus.push_back({x,y,w});\n\
    \    }\n    void query(ll l,ll d,ll r,ll u){\n        que.push_back({l,d,r,u});\n\
    \    }\n    vector<T> run(){\n        ll n=plus.size(),q=que.size();\n       \
    \ sort(ALL(plus),[](P& p,P& q){return p.y<q.y;});\n        vector<ll> ys;\n  \
    \      rep(i,0,n)ys.push_back(plus[i].y);\n        ys.erase(unique(ALL(ys)),ys.end());\n\
    \        rep(i,0,n)plus[i].y=lower_bound(ALL(ys),plus[i].y)-ys.begin();\n    \
    \    vector<Q> qs;\n        rep(i,0,q){\n            auto& [l,d,r,u]=que[i];\n\
    \            d=lower_bound(ALL(ys),d)-ys.begin();\n            u=lower_bound(ALL(ys),u)-ys.begin();\n\
    \            qs.push_back({l,d,u,i,1});\n            qs.push_back({r,d,u,i,-1});\n\
    \        }\n        sort(ALL(plus),[](P& p,P& q){return p.x<q.x;});\n        sort(ALL(qs),[](Q&\
    \ p,Q& q){return p.x<q.x;});\n        vector<T> res(q);\n        ll k=0;\n   \
    \     BIT<T> bit(ys.size());\n        for(auto& q:qs){\n            while(k<n\
    \ and plus[k].x<q.x){\n                bit.add(plus[k].y,plus[k].w);\n       \
    \         k++;\n            }\n            res[q.id]+=bit.sum(q.u,q.d)*q.inv;\n\
    \        }\n        return res;\n    }\n};\n\n/**\n * @brief Static Rectangle\
    \ Sum\n*/\n#line 4 \"DataStructure/staticrectaddrectsum.hpp\"\ntemplate<typename\
    \ T>struct StaticRectangleAddRectangleSum{\n    StaticRectangleSum<T> bit[4];\
    \ //XY,X,Y,Const\n    struct Rect{int l,d,r,u;};\n    vector<Rect> que;\n    StaticRectangleAddRectangleSum(){}\n\
    \    void add(int x,int y,T w){\n        bit[0].add(x,y,w);\n        bit[1].add(x,y,w*-y);\n\
    \        bit[2].add(x,y,w*-x);\n        bit[3].add(x,y,w*x*y);\n    }\n    void\
    \ add(int l,int d,int r,int u,T w){\n        add(l,d,w);\n        add(l,u,-w);\n\
    \        add(r,d,-w);\n        add(r,u,w);\n    }\n    void query(int l,int d,int\
    \ r,int u){\n        que.push_back({l,d,r,u});\n    }\n    vector<T> run(){\n\
    \        int q=que.size();\n        for(auto& [l,d,r,u]:que){\n            rep(j,0,4){\n\
    \                bit[j].query(0,0,l,d);\n                bit[j].query(0,0,l,u);\n\
    \                bit[j].query(0,0,r,d);\n                bit[j].query(0,0,r,u);\n\
    \            }\n        }\n        auto XY=bit[0].run();\n        auto X=bit[1].run();\n\
    \        auto Y=bit[2].run();\n        auto Const=bit[3].run();\n        vector<T>\
    \ res(q);\n        rep(i,0,q){\n            auto [l,d,r,u]=que[i];\n         \
    \   res[i]+=XY[4*i]*l*d;\n            res[i]+=X[4*i]*l;\n            res[i]+=Y[4*i]*d;\n\
    \            res[i]+=Const[4*i];\n\n            res[i]-=XY[4*i+1]*l*u;\n     \
    \       res[i]-=X[4*i+1]*l;\n            res[i]-=Y[4*i+1]*u;\n            res[i]-=Const[4*i+1];\n\
    \n            res[i]-=XY[4*i+2]*r*d;\n            res[i]-=X[4*i+2]*r;\n      \
    \      res[i]-=Y[4*i+2]*d;\n            res[i]-=Const[4*i+2];\n\n            res[i]+=XY[4*i+3]*r*u;\n\
    \            res[i]+=X[4*i+3]*r;\n            res[i]+=Y[4*i+3]*u;\n          \
    \  res[i]+=Const[4*i+3];\n        }\n        return res;\n    }\n};\n\n/**\n *\
    \ @brief Static Rectangle Add Rectangle Sum\n*/\n#line 10 \"Verify/LC_static_rectangle_add_rectangle_sum.test.cpp\"\
    \n\nFastIO io;\nint main(){\n    int n,q;\n    io.read(n,q);\n\n    StaticRectangleAddRectangleSum<Fp>\
    \ buf;\n    rep(i,0,n){\n        int L,D,R,U,w;\n        io.read(L,D,R,U,w);\n\
    \        buf.add(L,D,R,U,w);\n    }\n    rep(i,0,q){\n        int L,D,R,U;\n \
    \       io.read(L,D,R,U);\n        buf.query(L,D,R,U);\n    }\n    auto ret=buf.run();\n\
    \    rep(i,0,q)io.write(ret[i].v);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Math/modint.hpp\"\nusing Fp=fp<998244353>;\n\n#include \"DataStructure/staticrectaddrectsum.hpp\"\
    \n\nFastIO io;\nint main(){\n    int n,q;\n    io.read(n,q);\n\n    StaticRectangleAddRectangleSum<Fp>\
    \ buf;\n    rep(i,0,n){\n        int L,D,R,U,w;\n        io.read(L,D,R,U,w);\n\
    \        buf.add(L,D,R,U,w);\n    }\n    rep(i,0,q){\n        int L,D,R,U;\n \
    \       io.read(L,D,R,U);\n        buf.query(L,D,R,U);\n    }\n    auto ret=buf.run();\n\
    \    rep(i,0,q)io.write(ret[i].v);\n    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Math/modint.hpp
  - DataStructure/staticrectaddrectsum.hpp
  - DataStructure/staticrectsum.hpp
  - DataStructure/bit.hpp
  isVerificationFile: true
  path: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-14 02:23:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
- /verify/Verify/LC_static_rectangle_add_rectangle_sum.test.cpp.html
title: Verify/LC_static_rectangle_add_rectangle_sum.test.cpp
---
