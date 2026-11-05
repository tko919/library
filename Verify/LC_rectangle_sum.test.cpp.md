---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/2dsegtree.hpp
    title: 2D Segment Tree
  - icon: ':x:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"Verify/LC_rectangle_sum.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\
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
    \n    _show(i + 1, a, c...);\r\n}\n#line 2 \"DataStructure/segtree.hpp\"\n\r\n\
    template <typename M, typename N, M (*f)(M, M), M (*g)(M, N), M (*m1)()>\r\nstruct\
    \ SegmentTree {\r\n    int sz, n;\r\n    vector<M> data;\r\n    SegmentTree(int\
    \ _n = 0) : n(_n) {\r\n        sz = 1;\r\n        while (sz < _n)\r\n        \
    \    sz <<= 1;\r\n        data.assign(2 * sz, m1());\r\n    }\r\n    void run(vector<M>\
    \ &v) {\r\n        for (int i = 0; i < (int)v.size(); i++)\r\n            data[i\
    \ + sz] = v[i];\r\n        for (int k = sz - 1; k > 0; k--)\r\n            data[k]\
    \ = f(data[2 * k], data[2 * k + 1]);\r\n    }\r\n    void set(int k, const M &x)\
    \ {\r\n        k += sz;\r\n        data[k] = x;\r\n        while (k >>= 1)\r\n\
    \            data[k] = f(data[2 * k], data[2 * k + 1]);\r\n    }\r\n    void update(int\
    \ k, const N &x) {\r\n        k += sz;\r\n        data[k] = g(data[k], x);\r\n\
    \        while (k >>= 1)\r\n            data[k] = f(data[2 * k], data[2 * k +\
    \ 1]);\r\n    }\r\n    M query(int a, int b) {\r\n        M L = m1(), R = m1();\r\
    \n        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {\r\n            if\
    \ (a & 1)\r\n                L = f(L, data[a++]);\r\n            if (b & 1)\r\n\
    \                R = f(data[--b], R);\r\n        }\r\n        return f(L, R);\r\
    \n    }\r\n    M operator[](const int &k) const {\r\n        return data[k + sz];\r\
    \n    }\r\n    vector<M> get() {\r\n        return {data.begin() + sz, data.begin()\
    \ + sz + n};\r\n    }\r\n    template <class F> int max_right(int L, F ch) const\
    \ {\r\n        int l = sz + L, w = 1;\r\n        M ansL = m1();\r\n        for\
    \ (; L + w <= sz; l >>= 1, w <<= 1)\r\n            if (l & 1) {\r\n          \
    \      if (not ch(f(ansL, data[l])))\r\n                    break;\r\n       \
    \         ansL = f(ansL, data[l++]);\r\n                L += w;\r\n          \
    \  }\r\n        while (l <<= 1, w >>= 1) {\r\n            if (L + w <= sz && ch(f(ansL,\
    \ data[l]))) {\r\n                ansL = f(ansL, data[l++]);\r\n             \
    \   L += w;\r\n            }\r\n        }\r\n        return L;\r\n    }\r\n  \
    \  template <class F> int min_left(int R, F ch) const {\r\n        int r = sz\
    \ + R, w = 1;\r\n        M ansR = m1();\r\n        for (; R - w >= 0; r >>= 1,\
    \ w <<= 1)\r\n            if (r & 1) {\r\n                if (not ch(f(data[r\
    \ - 1], ansR)))\r\n                    break;\r\n                ansR = f(data[--r],\
    \ ansR);\r\n                R -= w;\r\n            }\r\n        while (r <<= 1,\
    \ w >>= 1) {\r\n            if (R - w >= 0 && ch(f(data[r - 1], ansR))) {\r\n\
    \                ansR = f(data[--r], ansR);\r\n                R -= w;\r\n   \
    \         }\r\n        }\r\n        return R;\r\n    }\r\n};\r\n\r\n/**\r\n *\
    \ @brief Segment Tree\r\n */\n#line 3 \"DataStructure/2dsegtree.hpp\"\n\r\ntemplate<typename\
    \ M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree2D{\r\n   \
    \ int n;\r\n    vector<SegmentTree<M,N,f,g,m1>> st;\r\n    vector<vector<int>>\
    \ ys;\r\n    SegmentTree2D(){}\r\n    int id(int x,int y){return lower_bound(ALL(ys[x]),y)-ys[x].begin();}\r\
    \n    using P=pair<int,int>;\r\n    vector<int> xs; vector<P> ps;\r\n    void\
    \ push(int x,int y){\r\n        ps.push_back({x,y});\r\n    }\r\n    void init(){\r\
    \n        for(auto& [x,y]:ps)xs.push_back(x);\r\n        sort(ALL(xs));\r\n  \
    \      xs.erase(unique(ALL(xs)),xs.end());\r\n        n=xs.size();\r\n       \
    \ ys.resize(n*2);\r\n        for(auto& [x,y]:ps){\r\n            int i=lower_bound(ALL(xs),x)-xs.begin();\r\
    \n            for(i+=n;i;i>>=1)ys[i].push_back(y);\r\n        }\r\n        for(int\
    \ i=0;i<n*2;i++){\r\n            sort(ALL(ys[i]));\r\n            ys[i].erase(unique(ALL(ys[i])),ys[i].end());\r\
    \n            st.push_back(SegmentTree<M,N,f,g,m1>(ys[i].size()));\r\n       \
    \ }\r\n    }\r\n    void update(int x,int y,N w){\r\n        x=(lower_bound(ALL(xs),x)-xs.begin())+n;\r\
    \n        st[x].update(id(x,y),w);\r\n        M cur=st[x][id(x,y)];\r\n      \
    \  int pos=x;\r\n        while(x>>=1){\r\n            M opp=st[pos^1].query(id(pos^1,y),id(pos^1,y+1));\r\
    \n            cur=f(cur,opp);\r\n            st[x].set(id(x,y),cur);\r\n     \
    \       pos>>=1;\r\n        }\r\n    }\r\n    M query(int x0,int x1,int y0,int\
    \ y1){\r\n        x0=lower_bound(ALL(xs),x0)-xs.begin();\r\n        x1=lower_bound(ALL(xs),x1)-xs.begin();\r\
    \n        M res=m1();\r\n        for(x0+=n,x1+=n;x0<x1;x0>>=1,x1>>=1){\r\n   \
    \         if(x0&1)res=f(res,st[x0].query(id(x0,y0),id(x0,y1))),x0++;\r\n     \
    \       if(x1&1)x1--,res=f(res,st[x1].query(id(x1,y0),id(x1,y1)));\r\n       \
    \ }\r\n        return res;\r\n    }\r\n};\r\n\r\n/**\r\n * @brief 2D Segment Tree\r\
    \n */\n#line 5 \"Verify/LC_rectangle_sum.test.cpp\"\n\r\nll f(ll a,ll b){return\
    \ a+b;}\r\nll g(ll a,ll b){return a+b;}\r\nll e(){return 0;}\r\n\r\nint main(){\r\
    \n    int n,q;\r\n    cin>>n>>q;\r\n    vector<int> x(n),y(n),w(n);\r\n    rep(i,0,n)cin>>x[i]>>y[i]>>w[i];\r\
    \n\r\n    SegmentTree2D<ll,ll,f,g,e> seg;\r\n    rep(i,0,n)seg.push(x[i],y[i]);\r\
    \n    seg.init();\r\n    rep(i,0,n)seg.update(x[i],y[i],w[i]);\r\n    while(q--){\r\
    \n        int l,r,d,u;\r\n        cin>>l>>d>>r>>u;\r\n        cout<<seg.query(l,r,d,u)<<'\\\
    n';\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\r\n\r\n\
    #include \"Template/template.hpp\"\r\n#include \"DataStructure/2dsegtree.hpp\"\
    \r\n\r\nll f(ll a,ll b){return a+b;}\r\nll g(ll a,ll b){return a+b;}\r\nll e(){return\
    \ 0;}\r\n\r\nint main(){\r\n    int n,q;\r\n    cin>>n>>q;\r\n    vector<int>\
    \ x(n),y(n),w(n);\r\n    rep(i,0,n)cin>>x[i]>>y[i]>>w[i];\r\n\r\n    SegmentTree2D<ll,ll,f,g,e>\
    \ seg;\r\n    rep(i,0,n)seg.push(x[i],y[i]);\r\n    seg.init();\r\n    rep(i,0,n)seg.update(x[i],y[i],w[i]);\r\
    \n    while(q--){\r\n        int l,r,d,u;\r\n        cin>>l>>d>>r>>u;\r\n    \
    \    cout<<seg.query(l,r,d,u)<<'\\n';\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - DataStructure/2dsegtree.hpp
  - DataStructure/segtree.hpp
  isVerificationFile: true
  path: Verify/LC_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2025-04-17 22:07:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_rectangle_sum.test.cpp
- /verify/Verify/LC_rectangle_sum.test.cpp.html
title: Verify/LC_rectangle_sum.test.cpp
---
