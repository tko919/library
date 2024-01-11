---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Algorithm/monotoneminima.hpp
    title: Monotone Minima
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/convexminplus.md
    document_title: Convex Min Plus Convolution
    links: []
  bundledCode: "#line 2 \"Algorithm/monotoneminima.hpp\"\n\r\ntemplate<typename F>vector<int>\
    \ MonotoneMinima(int R,int C,F cmp){\r\n    // cmp(i,j,k) := compare A[i,j] and\
    \ A[i,k] (A[i,j] -> false, A[i,k] -> true)\r\n    vector<int> ret(R);\r\n    auto\
    \ rec=[&](auto& f,vector<int> target)->void{\r\n        int m=target.size();\r\
    \n        if(m==0)return;\r\n        vector<int> even;\r\n        for(int i=1;i<m;i+=2)even.push_back(target[i]);\r\
    \n        f(f,even);\r\n        int cur=0;\r\n        for(int i=0;i<m;i+=2){\r\
    \n            ret[target[i]]=cur;\r\n            int end=C-1;\r\n            if(i!=m-1)end=ret[even[i/2]];\r\
    \n            while(cur<end){\r\n                cur++;\r\n                if(cmp(target[i],ret[target[i]],cur))ret[target[i]]=cur;\r\
    \n            }\r\n        }\r\n    };\r\n    vector<int> tmp(R);\r\n    iota(ALL(tmp),0);\r\
    \n    rec(rec,tmp);\r\n    return ret;\r\n}\r\n\r\n/**\r\n * @brief Monotone Minima\r\
    \n * @docs docs/monotoneminima.md\r\n */\n#line 3 \"Convolution/convexminplus.hpp\"\
    \n\r\ntemplate <typename T>\r\nvector<T> ConvexMinPlusConvolution(vector<T> &a,\
    \ vector<T> &b) {\r\n    int n = a.size(), m = b.size();\r\n    auto cmp = [&](int\
    \ i, int j, int k) -> bool {\r\n        if (i < k)\r\n            return false;\r\
    \n        if (i - j >= m)\r\n            return true;\r\n        return a[j] +\
    \ b[i - j] >= a[k] + b[i - k];\r\n    };\r\n    auto arg = MonotoneMinima(n +\
    \ m - 1, n, cmp);\r\n    vector<ll> ret(n + m - 1);\r\n    rep(i, 0, n + m - 1)\
    \ ret[i] = a[arg[i]] + b[i - arg[i]];\r\n    return ret;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvector<T> Convex2MinPlusConvolution(vector<T> &a, vector<T>\
    \ &b) {\r\n    int n = SZ(a), m = SZ(b);\r\n    // rep(i, 2, n) assert(a[i - 1]\
    \ - a[i - 2] <= a[i] - a[i - 1]);\r\n    // rep(i, 2, m) assert(b[i - 1] - b[i\
    \ - 2] <= b[i] - b[i - 1]);\r\n\r\n    vector<T> c(n + m - 1);\r\n    c[0] = a[0]\
    \ + b[0];\r\n    for (int k = 0, i = 0; k < n + m - 2; k++) {\r\n        int j\
    \ = k - i;\r\n        if (j == m - 1 or (i < n - 1 and a[i + 1] + b[j] < a[i]\
    \ + b[j + 1])) {\r\n            c[k + 1] = a[++i] + b[j];\r\n        } else {\r\
    \n            c[k + 1] = a[i] + b[++j];\r\n        }\r\n    }\r\n    return c;\r\
    \n}\r\n\r\n/**\r\n * @brief Convex Min Plus Convolution\r\n * @docs docs/convexminplus.md\r\
    \n */\n"
  code: "#pragma once\r\n#include \"Algorithm/monotoneminima.hpp\"\r\n\r\ntemplate\
    \ <typename T>\r\nvector<T> ConvexMinPlusConvolution(vector<T> &a, vector<T> &b)\
    \ {\r\n    int n = a.size(), m = b.size();\r\n    auto cmp = [&](int i, int j,\
    \ int k) -> bool {\r\n        if (i < k)\r\n            return false;\r\n    \
    \    if (i - j >= m)\r\n            return true;\r\n        return a[j] + b[i\
    \ - j] >= a[k] + b[i - k];\r\n    };\r\n    auto arg = MonotoneMinima(n + m -\
    \ 1, n, cmp);\r\n    vector<ll> ret(n + m - 1);\r\n    rep(i, 0, n + m - 1) ret[i]\
    \ = a[arg[i]] + b[i - arg[i]];\r\n    return ret;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvector<T> Convex2MinPlusConvolution(vector<T> &a, vector<T> &b) {\r\n\
    \    int n = SZ(a), m = SZ(b);\r\n    // rep(i, 2, n) assert(a[i - 1] - a[i -\
    \ 2] <= a[i] - a[i - 1]);\r\n    // rep(i, 2, m) assert(b[i - 1] - b[i - 2] <=\
    \ b[i] - b[i - 1]);\r\n\r\n    vector<T> c(n + m - 1);\r\n    c[0] = a[0] + b[0];\r\
    \n    for (int k = 0, i = 0; k < n + m - 2; k++) {\r\n        int j = k - i;\r\
    \n        if (j == m - 1 or (i < n - 1 and a[i + 1] + b[j] < a[i] + b[j + 1]))\
    \ {\r\n            c[k + 1] = a[++i] + b[j];\r\n        } else {\r\n         \
    \   c[k + 1] = a[i] + b[++j];\r\n        }\r\n    }\r\n    return c;\r\n}\r\n\r\
    \n/**\r\n * @brief Convex Min Plus Convolution\r\n * @docs docs/convexminplus.md\r\
    \n */"
  dependsOn:
  - Algorithm/monotoneminima.hpp
  isVerificationFile: false
  path: Convolution/convexminplus.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Convolution/convexminplus.hpp
layout: document
redirect_from:
- /library/Convolution/convexminplus.hpp
- /library/Convolution/convexminplus.hpp.html
title: Convex Min Plus Convolution
---
## 使い方

`vector<T> ConvexMinPlusConvolution(vector<T>& a,vector<T>& b)`: $b$ は凸性 ($\forall i,b_i-b_{i-1} \leq b_{i+1}-b_i$) を満たすとする。  
$c[n]=\min_{0 \leq k \leq n}a[k]+b[n-k]$ を計算。