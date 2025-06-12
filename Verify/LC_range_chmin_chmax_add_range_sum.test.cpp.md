---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtreebeats.hpp
    title: Segment Tree Beats
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"Verify/LC_range_chmin_chmax_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\r\
    \n\r\n#line 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
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
    \n    _show(i + 1, a, c...);\r\n}\n#line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\
    \nnamespace fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\
    \nchar obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\n\r\nuint32_t\
    \ pil = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n    char num[10000][4];\r\n\
    \    constexpr Pre() : num() {\r\n        for (int i = 0; i < 10000; i++) {\r\n\
    \            int n = i;\r\n            for (int j = 3; j >= 0; j--) {\r\n    \
    \            num[i][j] = n % 10 | '0';\r\n                n /= 10;\r\n       \
    \     }\r\n        }\r\n    }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\
    \n    memmove(ibuf, ibuf + pil, pir - pil);\r\n    pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\r\n    pil = 0;\r\n    if (pir < SZ)\r\
    \n        ibuf[pir++] = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n    fwrite(obuf,\
    \ 1, por, stdout);\r\n    por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n    do {\r\
    \n        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (isspace(c));\r\n}\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\
    \n    char c;\r\n    do {\r\n        if (pil + 1 > pir)\r\n            load();\r\
    \n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\n    do {\r\n      \
    \  x += c;\r\n        if (pil == pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (!isspace(c));\r\n}\r\n\r\ntemplate <typename T> void rd_real(T\
    \ &x) {\r\n    string s;\r\n    rd(s);\r\n    x = stod(s);\r\n}\r\n\r\ntemplate\
    \ <typename T> void rd_integer(T &x) {\r\n    if (pil + 100 > pir)\r\n       \
    \ load();\r\n    char c;\r\n    do\r\n        c = ibuf[pil++];\r\n    while (c\
    \ < '-');\r\n    bool minus = 0;\r\n    if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\r\n        if (c == '-') {\r\n            minus = 1, c = ibuf[pil++];\r\
    \n        }\r\n    }\r\n    x = 0;\r\n    while ('0' <= c) {\r\n        x = x\
    \ * 10 + (c & 15), c = ibuf[pil++];\r\n    }\r\n    if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n        if (minus)\r\n            x = -x;\r\n  \
    \  }\r\n}\r\n\r\nvoid rd(int &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ll &x)\
    \ {\r\n    rd_integer(x);\r\n}\r\nvoid rd(i128 &x) {\r\n    rd_integer(x);\r\n\
    }\r\nvoid rd(uint &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ull &x) {\r\n  \
    \  rd_integer(x);\r\n}\r\nvoid rd(u128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid\
    \ rd(double &x) {\r\n    rd_real(x);\r\n}\r\nvoid rd(long double &x) {\r\n   \
    \ rd_real(x);\r\n}\r\n\r\ntemplate <class T, class U> void rd(pair<T, U> &p) {\r\
    \n    return rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t N = 0, typename\
    \ T> void rd_tuple(T &t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n        auto &x = std::get<N>(t);\r\n        rd(x);\r\n        rd_tuple<N\
    \ + 1>(t);\r\n    }\r\n}\r\ntemplate <class... T> void rd(tuple<T...> &tpl) {\r\
    \n    rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t N = 0, typename T> void rd(array<T,\
    \ N> &x) {\r\n    for (auto &d : x)\r\n        rd(d);\r\n}\r\ntemplate <class\
    \ T> void rd(vector<T> &x) {\r\n    for (auto &d : x)\r\n        rd(d);\r\n}\r\
    \n\r\nvoid read() {}\r\ntemplate <class H, class... T> void read(H &h, T &...t)\
    \ {\r\n    rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const char c) {\r\n    if (por\
    \ == SZ)\r\n        flush();\r\n    obuf[por++] = c;\r\n}\r\nvoid wt(const string\
    \ s) {\r\n    for (char c : s)\r\n        wt(c);\r\n}\r\nvoid wt(const char *s)\
    \ {\r\n    size_t len = strlen(s);\r\n    for (size_t i = 0; i < len; i++)\r\n\
    \        wt(s[i]);\r\n}\r\n\r\ntemplate <typename T> void wt_integer(T x) {\r\n\
    \    if (por > SZ - 100)\r\n        flush();\r\n    if (x < 0) {\r\n        obuf[por++]\
    \ = '-', x = -x;\r\n    }\r\n    int outi;\r\n    for (outi = 96; x >= 10000;\
    \ outi -= 4) {\r\n        memcpy(out + outi, pre.num[x % 10000], 4);\r\n     \
    \   x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n        memcpy(obuf + por,\
    \ pre.num[x], 4);\r\n        por += 4;\r\n    } else if (x >= 100) {\r\n     \
    \   memcpy(obuf + por, pre.num[x] + 1, 3);\r\n        por += 3;\r\n    } else\
    \ if (x >= 10) {\r\n        int q = (x * 103) >> 10;\r\n        obuf[por] = q\
    \ | '0';\r\n        obuf[por + 1] = (x - q * 10) | '0';\r\n        por += 2;\r\
    \n    } else\r\n        obuf[por++] = x | '0';\r\n    memcpy(obuf + por, out +\
    \ outi + 4, 96 - outi);\r\n    por += 96 - outi;\r\n}\r\n\r\ntemplate <typename\
    \ T> void wt_real(T x) {\r\n    ostringstream oss;\r\n    oss << fixed << setprecision(15)\
    \ << double(x);\r\n    string s = oss.str();\r\n    wt(s);\r\n}\r\n\r\nvoid wt(int\
    \ x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ll x) {\r\n    wt_integer(x);\r\n\
    }\r\nvoid wt(i128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(uint x) {\r\n   \
    \ wt_integer(x);\r\n}\r\nvoid wt(ull x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(u128\
    \ x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(double x) {\r\n    wt_real(x);\r\n\
    }\r\nvoid wt(long double x) {\r\n    wt_real(x);\r\n}\r\n\r\ntemplate <class T,\
    \ class U> void wt(const pair<T, U> val) {\r\n    wt(val.first);\r\n    wt(' ');\r\
    \n    wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename T> void wt_tuple(const\
    \ T t) {\r\n    if constexpr (N < std::tuple_size<T>::value) {\r\n        if constexpr\
    \ (N > 0) {\r\n            wt(' ');\r\n        }\r\n        const auto x = std::get<N>(t);\r\
    \n        wt(x);\r\n        wt_tuple<N + 1>(t);\r\n    }\r\n}\r\ntemplate <class...\
    \ T> void wt(tuple<T...> tpl) {\r\n    wt_tuple(tpl);\r\n}\r\ntemplate <class\
    \ T, size_t S> void wt(const array<T, S> val) {\r\n    auto n = val.size();\r\n\
    \    for (size_t i = 0; i < n; i++) {\r\n        if (i)\r\n            wt(' ');\r\
    \n        wt(val[i]);\r\n    }\r\n}\r\ntemplate <class T> void wt(const vector<T>\
    \ val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++) {\r\
    \n        if (i)\r\n            wt(' ');\r\n        wt(val[i]);\r\n    }\r\n}\r\
    \n\r\nvoid print() {\r\n    wt('\\n');\r\n}\r\ntemplate <class Head, class...\
    \ Tail> void print(Head &&head, Tail &&...tail) {\r\n    wt(head);\r\n    if (sizeof...(Tail))\r\
    \n        wt(' ');\r\n    print(forward<Tail>(tail)...);\r\n}\r\nvoid __attribute__((destructor))\
    \ _d() {\r\n    flush();\r\n}\r\n} // namespace fastio\r\n\r\nusing fastio::flush;\r\
    \nusing fastio::print;\r\nusing fastio::read;\r\n\r\ninline void first(bool i\
    \ = true) {\r\n    print(i ? \"first\" : \"second\");\r\n}\r\ninline void Alice(bool\
    \ i = true) {\r\n    print(i ? \"Alice\" : \"Bob\");\r\n}\r\ninline void Takahashi(bool\
    \ i = true) {\r\n    print(i ? \"Takahashi\" : \"Aoki\");\r\n}\r\ninline void\
    \ yes(bool i = true) {\r\n    print(i ? \"yes\" : \"no\");\r\n}\r\ninline void\
    \ Yes(bool i = true) {\r\n    print(i ? \"Yes\" : \"No\");\r\n}\r\ninline void\
    \ No() {\r\n    print(\"No\");\r\n}\r\ninline void YES(bool i = true) {\r\n  \
    \  print(i ? \"YES\" : \"NO\");\r\n}\r\ninline void NO() {\r\n    print(\"NO\"\
    );\r\n}\r\ninline void Yay(bool i = true) {\r\n    print(i ? \"Yay!\" : \":(\"\
    );\r\n}\r\ninline void Possible(bool i = true) {\r\n    print(i ? \"Possible\"\
    \ : \"Impossible\");\r\n}\r\ninline void POSSIBLE(bool i = true) {\r\n    print(i\
    \ ? \"POSSIBLE\" : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\n * @brief Fast IO\r\n */\n\
    #line 2 \"DataStructure/segtreebeats.hpp\"\n\r\nstruct Segtreebeats{\r\n    struct\
    \ state{\r\n        ll maxx=-INF,smax=-INF,cmax=0,lmax=-INF;\r\n        ll minn=INF,smin=INF,cmin=0,lmin=INF;\r\
    \n        ll sum=0,add=0; int len=1;\r\n        state(){}\r\n        state(ll\
    \ val):maxx(val),cmax(1),minn(val),cmin(1),sum(val){}\r\n    };\r\n    int n;\
    \ vector<state> val;\r\n    Segtreebeats(int _n):Segtreebeats(vector<ll>(_n,0)){}\r\
    \n    Segtreebeats(const vector<ll>& a){\r\n        for(n=1;n<(int)a.size();n<<=1);\r\
    \n        val.assign(2*n,state());\r\n        rep(i,0,a.size())val[i+n]=state(a[i]);\r\
    \n        for(int i=n-1;i;i--)apply(i);\r\n    }\r\n    void apply(int k){\r\n\
    \        state &x=val[k],&lb=val[2*k],&rb=val[2*k+1];\r\n        if(lb.minn<rb.minn)x.minn=lb.minn,x.cmin=lb.cmin,x.smin=min(lb.smin,rb.minn);\r\
    \n        else if(lb.minn>rb.minn)x.minn=rb.minn,x.cmin=rb.cmin,x.smin=min(rb.smin,lb.minn);\r\
    \n        else x.minn=lb.minn,x.cmin=lb.cmin+rb.cmin,x.smin=min(lb.smin,rb.smin);\r\
    \n        if(lb.maxx>rb.maxx)x.maxx=lb.maxx,x.cmax=lb.cmax,x.smax=max(lb.smax,rb.maxx);\r\
    \n        else if(lb.maxx<rb.maxx)x.maxx=rb.maxx,x.cmax=rb.cmax,x.smax=max(rb.smax,lb.maxx);\r\
    \n        else x.maxx=lb.maxx,x.cmax=lb.cmax+rb.cmax,x.smax=max(lb.smax,rb.smax);\r\
    \n        x.len=lb.len+rb.len; x.sum=lb.sum+rb.sum;\r\n    }\r\n    void eval(int\
    \ k){\r\n        state &x=val[k],&lb=(k<n?val[2*k]:val[0]),&rb=(k<n?val[2*k+1]:val[0]);\r\
    \n        if(x.add){\r\n            if(lb.lmax!=-INF)lb.lmax+=x.add;\r\n     \
    \       if(lb.lmin!=INF)lb.lmin+=x.add;\r\n            if(rb.lmax!=-INF)rb.lmax+=x.add;\r\
    \n            if(rb.lmin!=INF)rb.lmin+=x.add;\r\n            lb.add+=x.add; rb.add+=x.add;\r\
    \n            x.minn+=x.add;\r\n            if(x.smin!=INF)x.smin+=x.add;\r\n\
    \            x.maxx+=x.add;\r\n            if(x.smax!=-INF)x.smax+=x.add;\r\n\
    \            x.sum+=x.len*x.add; x.add=0;\r\n        }\r\n        if(x.lmax!=-INF){\r\
    \n            chmax(lb.lmax,x.lmax);\r\n            chmax(lb.lmin,x.lmax);\r\n\
    \            chmax(rb.lmax,x.lmax);\r\n            chmax(rb.lmin,x.lmax);\r\n\
    \            if(x.lmax>=x.smin){eval(k*2); eval(k*2+1); apply(k);}\r\n       \
    \     else if(x.lmax>x.minn){\r\n                x.sum+=x.cmin*(x.lmax-x.minn);\r\
    \n                if(x.smax==x.minn)x.smax=x.lmax;\r\n                if(x.maxx==x.minn)x.maxx=x.lmax;\r\
    \n                x.minn=x.lmax;\r\n            } x.lmax=-INF;\r\n        }\r\n\
    \        if(x.lmin!=INF){\r\n            chmin(lb.lmax,x.lmin);\r\n          \
    \  chmin(lb.lmin,x.lmin);\r\n            chmin(rb.lmax,x.lmin);\r\n          \
    \  chmin(rb.lmin,x.lmin);\r\n            if(x.lmin<=x.smax){eval(k*2); eval(k*2+1);\
    \ apply(k);}\r\n            else if(x.lmin<x.maxx){\r\n                x.sum+=x.cmax*(x.lmin-x.maxx);\r\
    \n                if(x.smin==x.maxx)x.smin=x.lmin;\r\n                if(x.minn==x.maxx)x.minn=x.lmin;\r\
    \n                x.maxx=x.lmin;\r\n            } x.lmin=INF;\r\n        }\r\n\
    \    }\r\n    void range_add(int a,int b,ll c,int k=1,int l=0,int r=-1){\r\n \
    \       if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return;\r\n        if(b>=r&&a<=l){\r\
    \n            val[k].add=c; eval(k);\r\n        }else{\r\n            range_add(a,b,c,k*2,l,(l+r)/2);\r\
    \n            range_add(a,b,c,k*2+1,(l+r)/2,r);\r\n            apply(k);\r\n \
    \       }\r\n    }\r\n    void range_chmin(int a,int b,ll c,int k=1,int l=0,int\
    \ r=-1){\r\n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return;\r\n\
    \        if(b>=r&&a<=l){\r\n            val[k].lmin=c; eval(k);\r\n        }else{\r\
    \n            range_chmin(a,b,c,k*2,l,(l+r)/2);\r\n            range_chmin(a,b,c,k*2+1,(l+r)/2,r);\r\
    \n            apply(k);\r\n        }\r\n    }\r\n    void range_chmax(int a,int\
    \ b,ll c,int k=1,int l=0,int r=-1){\r\n        if(r<0)r=n; eval(k);\r\n      \
    \  if(b<=l||a>=r)return;\r\n        if(b>=r&&a<=l){\r\n            val[k].lmax=c;\
    \ eval(k);\r\n        }else{\r\n            range_chmax(a,b,c,k*2,l,(l+r)/2);\r\
    \n            range_chmax(a,b,c,k*2+1,(l+r)/2,r);\r\n            apply(k);\r\n\
    \        }\r\n    }\r\n    ll query_max(int a,int b,int k=1,int l=0,int r=-1){\r\
    \n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return -INF;\r\n     \
    \   if(b>=r&&a<=l)return val[k].maxx;\r\n        else{\r\n            ll res=max(query_max(a,b,k*2,l,(l+r)/2),query_max(a,b,k*2+1,(l+r)/2,r));\r\
    \n            return res;\r\n        }\r\n    }\r\n    ll query_min(int a,int\
    \ b,int k=1,int l=0,int r=-1){\r\n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return\
    \ INF;\r\n        if(b>=r&&a<=l)return val[k].minn;\r\n        else{\r\n     \
    \       ll res=min(query_min(a,b,k*2,l,(l+r)/2),query_min(a,b,k*2+1,(l+r)/2,r));\r\
    \n            return res;\r\n        }\r\n    }\r\n    ll query_sum(int a,int\
    \ b,int k=1,int l=0,int r=-1){\r\n        if(r<0)r=n; eval(k);\r\n        if(b<=l||a>=r)return\
    \ 0;\r\n        if(b>=r&&a<=l)return val[k].sum;\r\n        else{\r\n        \
    \    ll res=query_sum(a,b,k*2,l,(l+r)/2)+query_sum(a,b,k*2+1,(l+r)/2,r);\r\n \
    \           return res;\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Segment\
    \ Tree Beats\r\n */\n#line 6 \"Verify/LC_range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\r\nint main(){\r\n    int n,q;\r\n    read(n,q);\r\n    vector<ll> a(n);\r\n\
    \    read(a);\r\n    Segtreebeats seg(a);\r\n\r\n    int t,L,R;\r\n    ll x;\r\
    \n    while(q--){\r\n        read(t);\r\n        if(t==0){\r\n            read(L,R,x);\r\
    \n            seg.range_chmin(L,R,x);\r\n        }\r\n        if(t==1){\r\n  \
    \          read(L,R,x);\r\n            seg.range_chmax(L,R,x);\r\n        }  \
    \ \r\n        if(t==2){\r\n            read(L,R,x);\r\n            seg.range_add(L,R,x);\r\
    \n        }\r\n        if(t==3){\r\n            read(L,R);\r\n            print(seg.query_sum(L,R));\r\
    \n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n#include \"DataStructure/segtreebeats.hpp\"\r\n\r\nint main(){\r\n    int n,q;\r\
    \n    read(n,q);\r\n    vector<ll> a(n);\r\n    read(a);\r\n    Segtreebeats seg(a);\r\
    \n\r\n    int t,L,R;\r\n    ll x;\r\n    while(q--){\r\n        read(t);\r\n \
    \       if(t==0){\r\n            read(L,R,x);\r\n            seg.range_chmin(L,R,x);\r\
    \n        }\r\n        if(t==1){\r\n            read(L,R,x);\r\n            seg.range_chmax(L,R,x);\r\
    \n        }   \r\n        if(t==2){\r\n            read(L,R,x);\r\n          \
    \  seg.range_add(L,R,x);\r\n        }\r\n        if(t==3){\r\n            read(L,R);\r\
    \n            print(seg.query_sum(L,R));\r\n        }\r\n    }\r\n    return 0;\r\
    \n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/segtreebeats.hpp
  isVerificationFile: true
  path: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
- /verify/Verify/LC_range_chmin_chmax_add_range_sum.test.cpp.html
title: Verify/LC_range_chmin_chmax_add_range_sum.test.cpp
---
