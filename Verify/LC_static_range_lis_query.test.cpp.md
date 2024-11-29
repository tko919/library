---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/rangelis.hpp
    title: Range LIS Query
  - icon: ':heavy_check_mark:'
    path: DataStructure/wavelet.hpp
    title: Wavelet Matrix
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_lis_query
    links:
    - https://judge.yosupo.jp/problem/static_range_lis_query
  bundledCode: "#line 1 \"Verify/LC_static_range_lis_query.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_lis_query\"\r\n\r\n#line 1 \"\
    Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\
    \n#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)\r\n#define rrep(i,\
    \ a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)\r\n#define ALL(v) (v).begin(),\
    \ (v).end()\r\n#define UNIQUE(v) sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end())\r\
    \n#define SZ(v) (int)v.size()\r\n#define MIN(v) *min_element(ALL(v))\r\n#define\
    \ MAX(v) *max_element(ALL(v))\r\n#define LB(v, x) int(lower_bound(ALL(v), (x))\
    \ - (v).begin())\r\n#define UB(v, x) int(upper_bound(ALL(v), (x)) - (v).begin())\r\
    \n\r\nusing uint = unsigned int;\r\nusing ll = long long int;\r\nusing ull = unsigned\
    \ long long;\r\nusing i128 = __int128_t;\r\nusing u128 = __uint128_t;\r\nconst\
    \ int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\n\r\ntemplate\
    \ <typename T> inline bool chmax(T &a, T b) {\r\n    if (a < b) {\r\n        a\
    \ = b;\r\n        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename\
    \ T> inline bool chmin(T &a, T b) {\r\n    if (a > b) {\r\n        a = b;\r\n\
    \        return 1;\r\n    }\r\n    return 0;\r\n}\r\ntemplate <typename T, typename\
    \ U> T ceil(T x, U y) {\r\n    assert(y != 0);\r\n    if (y < 0)\r\n        x\
    \ = -x, y = -y;\r\n    return (x > 0 ? (x + y - 1) / y : x / y);\r\n}\r\ntemplate\
    \ <typename T, typename U> T floor(T x, U y) {\r\n    assert(y != 0);\r\n    if\
    \ (y < 0)\r\n        x = -x, y = -y;\r\n    return (x > 0 ? x / y : (x - y + 1)\
    \ / y);\r\n}\r\ntemplate <typename T> int popcnt(T x) {\r\n    return __builtin_popcountll(x);\r\
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
    \ os;\r\n}\r\n#ifdef LOCAL\r\n#define show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\
    \n#else\r\n#define show(...) true\r\n#endif\r\ntemplate <typename T> void _show(int\
    \ i, T name) {\r\n    cerr << '\\n';\r\n}\r\ntemplate <typename T1, typename T2,\
    \ typename... T3>\r\nvoid _show(int i, const T1 &a, const T2 &b, const T3 &...c)\
    \ {\r\n    for (; a[i] != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\
    \n    cerr << \":\" << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\n#line 2\
    \ \"Utility/fastio.hpp\"\n#include <unistd.h>\r\nnamespace fastio {\r\nstatic\
    \ constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\nchar\
    \ out[100];\r\n// pointer of ibuf, obuf\r\n\r\nuint32_t pil = 0, pir = 0, por\
    \ = 0;\r\n\r\nstruct Pre {\r\n    char num[10000][4];\r\n    constexpr Pre() :\
    \ num() {\r\n        for (int i = 0; i < 10000; i++) {\r\n            int n =\
    \ i;\r\n            for (int j = 3; j >= 0; j--) {\r\n                num[i][j]\
    \ = n % 10 | '0';\r\n                n /= 10;\r\n            }\r\n        }\r\n\
    \    }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n    memmove(ibuf, ibuf\
    \ + pil, pir - pil);\r\n    pir = pir - pil + fread(ibuf + pir - pil, 1, SZ -\
    \ pir + pil, stdin);\r\n    pil = 0;\r\n    if (pir < SZ)\r\n        ibuf[pir++]\
    \ = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n    fwrite(obuf, 1, por, stdout);\r\
    \n    por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n    do {\r\n        if (pil +\
    \ 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\n    } while (isspace(c));\r\
    \n}\r\n\r\nvoid rd(string &x) {\r\n    x.clear();\r\n    char c;\r\n    do {\r\
    \n        if (pil + 1 > pir)\r\n            load();\r\n        c = ibuf[pil++];\r\
    \n    } while (isspace(c));\r\n    do {\r\n        x += c;\r\n        if (pil\
    \ == pir)\r\n            load();\r\n        c = ibuf[pil++];\r\n    } while (!isspace(c));\r\
    \n}\r\n\r\ntemplate <typename T> void rd_real(T &x) {\r\n    string s;\r\n   \
    \ rd(s);\r\n    x = stod(s);\r\n}\r\n\r\ntemplate <typename T> void rd_integer(T\
    \ &x) {\r\n    if (pil + 100 > pir)\r\n        load();\r\n    char c;\r\n    do\r\
    \n        c = ibuf[pil++];\r\n    while (c < '-');\r\n    bool minus = 0;\r\n\
    \    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n        if\
    \ (c == '-') {\r\n            minus = 1, c = ibuf[pil++];\r\n        }\r\n   \
    \ }\r\n    x = 0;\r\n    while ('0' <= c) {\r\n        x = x * 10 + (c & 15),\
    \ c = ibuf[pil++];\r\n    }\r\n    if constexpr (is_signed<T>::value || is_same_v<T,\
    \ i128>) {\r\n        if (minus)\r\n            x = -x;\r\n    }\r\n}\r\n\r\n\
    void rd(int &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(ll &x) {\r\n    rd_integer(x);\r\
    \n}\r\nvoid rd(i128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(uint &x) {\r\n\
    \    rd_integer(x);\r\n}\r\nvoid rd(ull &x) {\r\n    rd_integer(x);\r\n}\r\nvoid\
    \ rd(u128 &x) {\r\n    rd_integer(x);\r\n}\r\nvoid rd(double &x) {\r\n    rd_real(x);\r\
    \n}\r\nvoid rd(long double &x) {\r\n    rd_real(x);\r\n}\r\n\r\ntemplate <class\
    \ T, class U> void rd(pair<T, U> &p) {\r\n    return rd(p.first), rd(p.second);\r\
    \n}\r\ntemplate <size_t N = 0, typename T> void rd_tuple(T &t) {\r\n    if constexpr\
    \ (N < std::tuple_size<T>::value) {\r\n        auto &x = std::get<N>(t);\r\n \
    \       rd(x);\r\n        rd_tuple<N + 1>(t);\r\n    }\r\n}\r\ntemplate <class...\
    \ T> void rd(tuple<T...> &tpl) {\r\n    rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t\
    \ N = 0, typename T> void rd(array<T, N> &x) {\r\n    for (auto &d : x)\r\n  \
    \      rd(d);\r\n}\r\ntemplate <class T> void rd(vector<T> &x) {\r\n    for (auto\
    \ &d : x)\r\n        rd(d);\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class...\
    \ T> void read(H &h, T &...t) {\r\n    rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const\
    \ char c) {\r\n    if (por == SZ)\r\n        flush();\r\n    obuf[por++] = c;\r\
    \n}\r\nvoid wt(const string s) {\r\n    for (char c : s)\r\n        wt(c);\r\n\
    }\r\nvoid wt(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t\
    \ i = 0; i < len; i++)\r\n        wt(s[i]);\r\n}\r\n\r\ntemplate <typename T>\
    \ void wt_integer(T x) {\r\n    if (por > SZ - 100)\r\n        flush();\r\n  \
    \  if (x < 0) {\r\n        obuf[por++] = '-', x = -x;\r\n    }\r\n    int outi;\r\
    \n    for (outi = 96; x >= 10000; outi -= 4) {\r\n        memcpy(out + outi, pre.num[x\
    \ % 10000], 4);\r\n        x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n  \
    \      memcpy(obuf + por, pre.num[x], 4);\r\n        por += 4;\r\n    } else if\
    \ (x >= 100) {\r\n        memcpy(obuf + por, pre.num[x] + 1, 3);\r\n        por\
    \ += 3;\r\n    } else if (x >= 10) {\r\n        int q = (x * 103) >> 10;\r\n \
    \       obuf[por] = q | '0';\r\n        obuf[por + 1] = (x - q * 10) | '0';\r\n\
    \        por += 2;\r\n    } else\r\n        obuf[por++] = x | '0';\r\n    memcpy(obuf\
    \ + por, out + outi + 4, 96 - outi);\r\n    por += 96 - outi;\r\n}\r\n\r\ntemplate\
    \ <typename T> void wt_real(T x) {\r\n    ostringstream oss;\r\n    oss << fixed\
    \ << setprecision(15) << double(x);\r\n    string s = oss.str();\r\n    wt(s);\r\
    \n}\r\n\r\nvoid wt(int x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ll x) {\r\n\
    \    wt_integer(x);\r\n}\r\nvoid wt(i128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid\
    \ wt(uint x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(ull x) {\r\n    wt_integer(x);\r\
    \n}\r\nvoid wt(u128 x) {\r\n    wt_integer(x);\r\n}\r\nvoid wt(double x) {\r\n\
    \    wt_real(x);\r\n}\r\nvoid wt(long double x) {\r\n    wt_real(x);\r\n}\r\n\r\
    \ntemplate <class T, class U> void wt(const pair<T, U> val) {\r\n    wt(val.first);\r\
    \n    wt(' ');\r\n    wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename\
    \ T> void wt_tuple(const T t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n        if constexpr (N > 0) {\r\n            wt(' ');\r\n        }\r\n\
    \        const auto x = std::get<N>(t);\r\n        wt(x);\r\n        wt_tuple<N\
    \ + 1>(t);\r\n    }\r\n}\r\ntemplate <class... T> void wt(tuple<T...> tpl) {\r\
    \n    wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t S> void wt(const array<T,\
    \ S> val) {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++)\
    \ {\r\n        if (i)\r\n            wt(' ');\r\n        wt(val[i]);\r\n    }\r\
    \n}\r\ntemplate <class T> void wt(const vector<T> val) {\r\n    auto n = val.size();\r\
    \n    for (size_t i = 0; i < n; i++) {\r\n        if (i)\r\n            wt(' ');\r\
    \n        wt(val[i]);\r\n    }\r\n}\r\n\r\nvoid print() {\r\n    wt('\\n');\r\n\
    }\r\ntemplate <class Head, class... Tail> void print(Head &&head, Tail &&...tail)\
    \ {\r\n    wt(head);\r\n    if (sizeof...(Tail))\r\n        wt(' ');\r\n    print(forward<Tail>(tail)...);\r\
    \n}\r\nvoid __attribute__((destructor)) _d() {\r\n    flush();\r\n}\r\n} // namespace\
    \ fastio\r\n\r\nusing fastio::flush;\r\nusing fastio::print;\r\nusing fastio::read;\r\
    \n\r\ninline void first(bool i = true) {\r\n    print(i ? \"first\" : \"second\"\
    );\r\n}\r\ninline void Alice(bool i = true) {\r\n    print(i ? \"Alice\" : \"\
    Bob\");\r\n}\r\ninline void Takahashi(bool i = true) {\r\n    print(i ? \"Takahashi\"\
    \ : \"Aoki\");\r\n}\r\ninline void yes(bool i = true) {\r\n    print(i ? \"yes\"\
    \ : \"no\");\r\n}\r\ninline void Yes(bool i = true) {\r\n    print(i ? \"Yes\"\
    \ : \"No\");\r\n}\r\ninline void No() {\r\n    print(\"No\");\r\n}\r\ninline void\
    \ YES(bool i = true) {\r\n    print(i ? \"YES\" : \"NO\");\r\n}\r\ninline void\
    \ NO() {\r\n    print(\"NO\");\r\n}\r\ninline void Yay(bool i = true) {\r\n  \
    \  print(i ? \"Yay!\" : \":(\");\r\n}\r\ninline void Possible(bool i = true) {\r\
    \n    print(i ? \"Possible\" : \"Impossible\");\r\n}\r\ninline void POSSIBLE(bool\
    \ i = true) {\r\n    print(i ? \"POSSIBLE\" : \"IMPOSSIBLE\");\r\n}\r\n\r\n/**\r\
    \n * @brief Fast IO\r\n */\n#line 2 \"DataStructure/wavelet.hpp\"\n\r\ntemplate<typename\
    \ T>struct WaveletMatrix{\r\n    struct BitVector{\r\n        vector<unsigned\
    \ long long> buf;\r\n        vector<int> rui;\r\n        BitVector(const vector<char>&\
    \ a={}){\r\n            int n=a.size();\r\n            buf.assign((n+63)>>6,0);\r\
    \n            rui.assign(buf.size()+1,0);\r\n            rep(i,0,n)if(a[i]){\r\
    \n                buf[i>>6]|=1ull<<(i&63);\r\n                rui[(i>>6)+1]++;\r\
    \n            }\r\n            rep(i,0,buf.size())rui[i+1]+=rui[i];\r\n      \
    \  }\r\n        int rank(int k,bool f=1){\r\n            int ret=rui[k>>6]+__builtin_popcountll(buf[k>>6]&((1ull<<(k&63))-1));\r\
    \n            if(!f)return k-ret;\r\n            else return ret;\r\n        }\r\
    \n    };\r\n    int N,lg;\r\n    vector<int> mid;\r\n    vector<BitVector> buf;\r\
    \n    WaveletMatrix(){}\r\n    WaveletMatrix(vector<T> a):N(a.size()),lg(0){\r\
    \n        T mx=0;\r\n        for(auto& x:a)chmax(mx,x);\r\n        while((T(1)<<lg)<=mx)lg++;\r\
    \n        mid.resize(lg);\r\n        buf.resize(lg);\r\n        for(int d=lg-1;d>=0;d--){\r\
    \n            vector<char> add;\r\n            vector nxt(2,vector<T>());\r\n\
    \            for(auto& x:a){\r\n                add.push_back(x>>d&1);\r\n   \
    \             nxt[x>>d&1].push_back(x);\r\n            }\r\n            mid[d]=(int)nxt[0].size();\r\
    \n            buf[d]=BitVector(add);\r\n            swap(a,nxt[0]);\r\n      \
    \      a.insert(a.end(),ALL(nxt[1]));\r\n        }\r\n    }\r\n    int rank(int\
    \ L,int R,T x){\r\n        if((T(1)<<lg)<=x)return 0;\r\n        for(int d=lg-1;d>=0;d--){\r\
    \n            bool f=(x>>d&1);\r\n            L=buf[d].rank(L,f)+(f?mid[d]:0);\r\
    \n            R=buf[d].rank(R,f)+(f?mid[d]:0);\r\n        }\r\n        return\
    \ R-L;\r\n    }\r\n    T quantile(int L,int R,int k){\r\n        T ret=0;\r\n\
    \        for(int d=lg-1;d>=0;d--){\r\n            int l0=buf[d].rank(L,0),r0=buf[d].rank(R,0);\r\
    \n            if(k<r0-l0)L=l0,R=r0;\r\n            else{\r\n                k-=r0-l0;\r\
    \n                ret|=T(1)<<d;\r\n                L+=mid[d]-l0,R+=mid[d]-r0;\r\
    \n            }\r\n        }\r\n        return ret;\r\n    }\r\n    int freq(int\
    \ L,int R,T x){\r\n        if((T(1)<<lg)<=x)return R-L;\r\n        int ret=0;\r\
    \n        for(int d=lg-1;d>=0;d--){\r\n            bool f=(x>>d&1);\r\n      \
    \      if(f)ret+=buf[d].rank(R,0)-buf[d].rank(L,0);\r\n            L=buf[d].rank(L,f)+(f?mid[d]:0);\r\
    \n            R=buf[d].rank(R,f)+(f?mid[d]:0);\r\n        }\r\n        return\
    \ ret;\r\n    }\r\n    int freq(int L,int R,T a,T b){\r\n        return freq(L,R,b)-freq(L,R,a);\r\
    \n    }\r\n    T prev(int L,int R,T x){\r\n        int cnt=freq(L,R,x);\r\n  \
    \      return cnt==R-L?T(-1):quantile(L,R,cnt);\r\n    }\r\n    T next(int L,int\
    \ R,T x){\r\n        int cnt=freq(L,R,x);\r\n        return cnt==0?T(-1):quantile(L,R,cnt-1);\r\
    \n    }\r\n};\r\n\r\n/**\r\n * @brief Wavelet Matrix\r\n * @docs docs/wavelet.md\r\
    \n */\n#line 3 \"DataStructure/rangelis.hpp\"\n\r\nstruct RangeLIS{\r\n    WaveletMatrix<int>\
    \ wm;\r\n    int N;\r\n    RangeLIS(vector<int> p){\r\n        N=1;\r\n      \
    \  while(N<int(p.size()))N<<=1;\r\n        rep(i,p.size(),N)p.push_back(i);\r\n\
    \        auto init=seaweed(p);\r\n        wm=WaveletMatrix<int>(init);\r\n   \
    \ }\r\n    int query(int L,int R){\r\n        if(L>=R)return 0;\r\n        return\
    \ R-L-wm.freq(0,R,L,N);\r\n    }\r\nprivate:\r\n    vector<int> seaweed(const\
    \ vector<int>& p){\r\n        int n=p.size();\r\n        if(n==1)return {inf};\r\
    \n        vector<int> lo,hi,lpos,hpos;\r\n        rep(i,0,n){\r\n            if(p[i]<n/2){\r\
    \n                lo.push_back(p[i]);\r\n                lpos.push_back(i);\r\n\
    \            }\r\n            else{\r\n                hi.push_back(p[i]-n/2);\r\
    \n                hpos.push_back(i);\r\n            }\r\n        }\r\n       \
    \ auto x=seaweed(lo),y=seaweed(hi);\r\n        vector<int> s(n),t(n);\r\n    \
    \    iota(ALL(s),0);\r\n        iota(ALL(t),0);\r\n        int xi=0,yi=0;\r\n\
    \        rep(i,0,n){\r\n            if(p[i]<n/2){\r\n                if(x[xi]==inf)s[i]=inf;\r\
    \n                else s[i]=lpos[x[xi]];\r\n                xi++;\r\n        \
    \    }\r\n            else{\r\n                if(y[yi]==inf)t[i]=inf;\r\n   \
    \             else t[i]=hpos[y[yi]];\r\n                yi++;\r\n            }\r\
    \n        }\r\n        vector<int> a(n,inf),b(n);\r\n        vector<int> revs(n,inf);\r\
    \n        rep(i,0,n)if(s[i]!=inf)revs[s[i]]=i;\r\n        int pos=n-1;\r\n   \
    \     vector<int> tos(n,inf),tot(n,inf);\r\n        for(int i=n-1;i>=0;i--)if(revs[i]!=inf){\r\
    \n            a[revs[i]]=pos;\r\n            tos[pos--]=i;\r\n        }\r\n  \
    \      rep(i,0,n)if(a[i]==inf)a[i]=pos--;\r\n        pos=0;\r\n        vector<int>\
    \ used(n);\r\n        rep(i,0,n)if(t[i]!=inf){\r\n            b[pos]=t[i];\r\n\
    \            tot[pos++]=i;\r\n            used[t[i]]=1;\r\n        }\r\n     \
    \   rep(i,0,n)if(!used[i]){\r\n            b[pos++]=i;\r\n        }\r\n      \
    \  auto c=squaredot(a,b);\r\n        vector<int> res(n,inf);\r\n        rep(i,0,n)if(tot[i]!=inf\
    \ and tos[c[i]]!=inf){\r\n            res[tot[i]]=tos[c[i]];\r\n        }\r\n\
    \        return res;\r\n    }\r\n    vector<int> squaredot(const vector<int>&\
    \ a,const vector<int>& b){\r\n        int n=a.size();\r\n        if(n==1)return\
    \ {0};\r\n        vector<int> alo,ahi,blo,bhi;\r\n        vector<int> inva(n);\r\
    \n        rep(i,0,n)inva[a[i]]=i;\r\n        int aloi=0,ahii=0;\r\n        vector<int>\
    \ azip(n),alov,ahiv;\r\n        rep(i,0,n){\r\n            if(inva[i]<n/2){\r\n\
    \                azip[inva[i]]=aloi++;\r\n                alov.push_back(i);\r\
    \n            }\r\n            else{\r\n                azip[inva[i]]=ahii++;\r\
    \n                ahiv.push_back(i);\r\n            }\r\n            if(b[i]<n/2)blo.push_back(b[i]);\r\
    \n            else bhi.push_back(b[i]-n/2);\r\n        }\r\n        rep(i,0,n){\r\
    \n            if(i<n/2)alo.push_back(azip[i]);\r\n            else ahi.push_back(azip[i]);\r\
    \n        }\r\n        auto sublo=squaredot(alo,blo);\r\n        auto subhi=squaredot(ahi,bhi);\r\
    \n        vector<int> clo(n,inf),chi(n,inf),res(n,inf);\r\n        int subloi=0,subhii=0;\r\
    \n        rep(i,0,n){\r\n            if(b[i]<n/2)clo[i]=alov[sublo[subloi++]];\r\
    \n            else chi[i]=ahiv[subhi[subhii++]];\r\n        }\r\n        vector<int>\
    \ invclo(n,inf),invchi(n,inf);\r\n        rep(i,0,n){\r\n            if(clo[i]!=inf)invclo[clo[i]]=i;\r\
    \n            if(chi[i]!=inf)invchi[chi[i]]=i;\r\n        }\r\n        int cloi=n,cloj=-1,chii=n,chij=-1;\r\
    \n        int ldelta=0,hdelta=0;\r\n        for(;;){\r\n            if(cloi<0\
    \ and chij>=n)break;\r\n            if(ldelta>0){\r\n                cloj++;\r\
    \n                if(cloj<n and chi[cloj]!=inf and chi[cloj]<cloi)ldelta--;\r\n\
    \                if(cloj<n and clo[cloj]!=inf and clo[cloj]>=cloi)ldelta--;\r\n\
    \            }\r\n            else{\r\n                cloi--;\r\n           \
    \     if(cloi>=0 and invchi[cloi]!=inf and invchi[cloi]<=cloj)ldelta++;\r\n  \
    \              if(cloi>=0 and invclo[cloi]!=inf and invclo[cloi]>cloj)ldelta++;\r\
    \n            }\r\n            if(0<=cloj and cloj<n and clo[cloj]!=inf and clo[cloj]<=cloi)res[cloj]=clo[cloj];\r\
    \n            if(hdelta>=0){\r\n                chij++;\r\n                if(chij<n\
    \ and chi[chij]!=inf and chi[chij]<chii)hdelta--;\r\n                if(chij<n\
    \ and clo[chij]!=inf and clo[chij]>=chii)hdelta--;\r\n            }\r\n      \
    \      else{\r\n                chii--;\r\n                if(chii>=0 and invchi[chii]!=inf\
    \ and invchi[chii]<=chij)hdelta++;\r\n                if(chii>=0 and invclo[chii]!=inf\
    \ and invclo[chii]>chij)hdelta++;\r\n            }\r\n            if(0<=chij and\
    \ chij<n and chi[chij]!=inf and chi[chij]>=chii)res[chij]=chi[chij];\r\n     \
    \       if(cloi==chii and cloj==chij)res[cloj]=cloi;\r\n        }\r\n        return\
    \ res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Range LIS Query\r\n */\n#line 6\
    \ \"Verify/LC_static_range_lis_query.test.cpp\"\n\r\nint main(){\r\n    int n,q;\r\
    \n    read(n,q);\r\n    vector<int> p(n);\r\n    read(p);\r\n\r\n    RangeLIS\
    \ buf(p);\r\n    while(q--){\r\n        int L,R;\r\n        read(L,R);\r\n   \
    \     print(buf.query(L,R));\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_lis_query\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\
    \n#include \"DataStructure/rangelis.hpp\"\r\n\r\nint main(){\r\n    int n,q;\r\
    \n    read(n,q);\r\n    vector<int> p(n);\r\n    read(p);\r\n\r\n    RangeLIS\
    \ buf(p);\r\n    while(q--){\r\n        int L,R;\r\n        read(L,R);\r\n   \
    \     print(buf.query(L,R));\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/rangelis.hpp
  - DataStructure/wavelet.hpp
  isVerificationFile: true
  path: Verify/LC_static_range_lis_query.test.cpp
  requiredBy: []
  timestamp: '2024-06-23 06:04:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_static_range_lis_query.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_static_range_lis_query.test.cpp
- /verify/Verify/LC_static_range_lis_query.test.cpp.html
title: Verify/LC_static_range_lis_query.test.cpp
---
