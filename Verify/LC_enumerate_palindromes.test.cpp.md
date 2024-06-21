---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: String/manacher.hpp
    title: Manacher Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"Verify/LC_enumerate_palindromes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\r\n\r\n#line 1 \"\
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
    \   return (x == 0 ? -1 : __builtin_ctzll(x));\r\n}\r\n\r\n#ifdef LOCAL\r\n#define\
    \ show(...) _show(0, #__VA_ARGS__, __VA_ARGS__)\r\n#else\r\n#define show(...)\
    \ true\r\n#endif\r\ntemplate <typename T> void _show(int i, T name) {\r\n    cerr\
    \ << '\\n';\r\n}\r\ntemplate <typename T1, typename T2, typename... T3>\r\nvoid\
    \ _show(int i, const T1 &a, const T2 &b, const T3 &...c) {\r\n    for (; a[i]\
    \ != ',' && a[i] != '\\0'; i++)\r\n        cerr << a[i];\r\n    cerr << \":\"\
    \ << b << \" \";\r\n    _show(i + 1, a, c...);\r\n}\r\ntemplate <class T, class\
    \ U>\r\nostream &operator<<(ostream &os, const pair<T, U> &p) {\r\n    os << \"\
    P(\" << p.first << \", \" << p.second << \")\";\r\n    return os;\r\n}\r\ntemplate\
    \ <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {\r\n  \
    \  os << \"{\";\r\n    for (int i = 0; i < vec.size(); i++) {\r\n        os <<\
    \ vec[i] << (i + 1 == vec.size() ? \"\" : \", \");\r\n    }\r\n    os << \"}\"\
    ;\r\n    return os;\r\n}\r\ntemplate <typename T, typename U>\r\nostream &operator<<(ostream\
    \ &os, const map<T, U> &map_var) {\r\n    os << \"{\";\r\n    for (auto itr =\
    \ map_var.begin(); itr != map_var.end(); itr++) {\r\n        os << \"(\" << itr->first\
    \ << \", \" << itr->second << \")\";\r\n        itr++;\r\n        if (itr != map_var.end())\r\
    \n            os << \", \";\r\n        itr--;\r\n    }\r\n    os << \"}\";\r\n\
    \    return os;\r\n}\r\ntemplate <typename T> ostream &operator<<(ostream &os,\
    \ const set<T> &set_var) {\r\n    os << \"{\";\r\n    for (auto itr = set_var.begin();\
    \ itr != set_var.end(); itr++) {\r\n        os << *itr;\r\n        ++itr;\r\n\
    \        if (itr != set_var.end())\r\n            os << \", \";\r\n        itr--;\r\
    \n    }\r\n    os << \"}\";\r\n    return os;\r\n}\n#line 2 \"String/manacher.hpp\"\
    \n\r\nvector<int> Manacher(const string& s){\r\n   string t;\r\n   for(auto& c:s){\r\
    \n      t.push_back(c);\r\n      t.push_back('$');\r\n   }\r\n   t.pop_back();\r\
    \n   int i=0,j=0,n=t.size(); vector<int> res(n);\r\n   while(i<n){\r\n      while(i-j>=0\
    \ and i+j<n and t[i-j]==t[i+j])j++;\r\n      res[i]=j;\r\n      int k=1;\r\n \
    \     while(i-k>=0 and i+k<n and k+res[i-k]<j){\r\n         res[i+k]=res[i-k];\
    \ k++;\r\n      }\r\n      i+=k; j-=k;\r\n   }\r\n   for(int i=0;i<n;i++){\r\n\
    \      if(i&1)res[i]=(res[i]/2)*2;\r\n      else res[i]=((res[i]+1)/2)*2-1;\r\n\
    \   }\r\n   return res;\r\n}\r\n\r\n/**\r\n * @brief Manacher Algorithm\r\n */\n\
    #line 5 \"Verify/LC_enumerate_palindromes.test.cpp\"\n\r\nint main(){\r\n    string\
    \ s;\r\n    cin>>s;\r\n    auto ret=Manacher(s);\r\n    rep(i,0,ret.size())cout<<ret[i]<<'\\\
    n';\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \r\n\r\n#include \"Template/template.hpp\"\r\n#include \"String/manacher.hpp\"\
    \r\n\r\nint main(){\r\n    string s;\r\n    cin>>s;\r\n    auto ret=Manacher(s);\r\
    \n    rep(i,0,ret.size())cout<<ret[i]<<'\\n';\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - String/manacher.hpp
  isVerificationFile: true
  path: Verify/LC_enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-06-22 00:56:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_enumerate_palindromes.test.cpp
- /verify/Verify/LC_enumerate_palindromes.test.cpp.html
title: Verify/LC_enumerate_palindromes.test.cpp
---
