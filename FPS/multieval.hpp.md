---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_multipoint_evaluation.test.cpp
    title: Verify/LC_multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: Verify/LC_polynomial_interpolation.test.cpp
    title: Verify/LC_polynomial_interpolation.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Multipoint Evaluation
    links: []
  bundledCode: "#line 2 \"FPS/multieval.hpp\"\n\r\ntemplate<typename T>struct MultiEval{\r\
    \n    int m,n; vector<Poly<T>> t;\r\n    MultiEval(vector<T>& v){\r\n        m=v.size(),n=1;\
    \ while(n<m)n<<=1;\r\n        t.resize(n<<1);\r\n        rep(i,0,n){\r\n     \
    \       T w=(i<m?v[i]:0);\r\n            t[n+i]=Poly<T>({-w,T(1)});\r\n      \
    \  }\r\n        for(int i=n-1;i;i--)t[i]=t[i*2]*t[i*2+1];\r\n    }\r\n    vector<T>\
    \ run(const vector<T>& f){\r\n        if(f.empty())return vector<T>(m);\r\n  \
    \      vector<Poly<T>> c(n*2);\r\n        auto v=t[1].rev();\r\n        v.resize(f.size());\r\
    \n        v=v.inv().rev()*Poly<T>(f);\r\n        v.erase(v.begin(),v.begin()+f.size()-1);\r\
    \n        v.resize(n); reverse(ALL(v)); c[1]=v;\r\n        rep(i,1,n){\r\n   \
    \         int d=c[i].size();\r\n            rep(k,0,2){\r\n                auto\
    \ add=t[i*2+(k^1)];\r\n                add.resize(d/2+1);\r\n                add=add.rev();\r\
    \n                add*=c[i];\r\n                add.resize(d);\r\n           \
    \     c[i*2+k]=vector<T>(add.begin()+d/2,add.end());\r\n            }\r\n    \
    \    }\r\n        vector<T> res(m); rep(i,0,m)res[i]=c[n+i][0];\r\n        return\
    \ res;\r\n    }\r\n    vector<T> build(vector<T>& ys){\r\n        auto w=t[1].rev();\r\
    \n        w.resize(m+1);\r\n        auto vs=run(w.rev().diff());\r\n        rep(i,0,m)ys[i]/=vs[i];\r\
    \n        vector<Poly<T>> c(n*2);\r\n        rep(i,0,n){\r\n            if(i<m)c[n+i]=Poly<T>({ys[i]});\r\
    \n            else c[n+i]=Poly<T>({T()});\r\n        }\r\n        for(int i=n-1;i;i--)c[i]=c[i*2]*t[i*2+1]+c[i*2+1]*t[i*2];\r\
    \n        c[1]=vector<T>(c[1].begin()+(n-m),c[1].end());\r\n        c[1].resize(m);\r\
    \n       return c[1];\r\n    }\r\n};\r\n\r\ntemplate <typename T> struct MultievalWithNTT\
    \ {\r\n    int m, n;\r\n    vector<Poly<T>> t;\r\n    NTT<T> trans;\r\n\r\n  \
    \  MultievalWithNTT(const vector<T> &v) : m(v.size()), n(1) {\r\n        while\
    \ (n < m)\r\n            n <<= 1;\r\n        assert(2LL * n <= (1LL << NTT<T>::rank2));\r\
    \n\r\n        // t[i] is the NTT of the reversed product polynomial of node i.\r\
    \n        // Its size is twice the number of leaves below the node.\r\n      \
    \  t.resize(n << 1);\r\n        for (int i = 0; i < n; i++) {\r\n            T\
    \ x = i < m ? v[i] : T(0);\r\n            t[n + i] = Poly<T>({T(1), -x});\r\n\
    \            trans.ntt(t[n + i]);\r\n        }\r\n        for (int i = n - 1;\
    \ i; i--) {\r\n            Poly<T> l = t[i << 1], r = t[i << 1 | 1];\r\n     \
    \       trans.doubling(l);\r\n            trans.doubling(r);\r\n            t[i].resize(l.size());\r\
    \n            for (int j = 0; j < (int)l.size(); j++)\r\n                t[i][j]\
    \ = l[j] * r[j];\r\n        }\r\n    }\r\n\r\n    vector<T> run(const vector<T>\
    \ &f) {\r\n        if (f.empty())\r\n            return vector<T>(m);\r\n\r\n\
    \        Poly<T> root_rev = t[1];\r\n        trans.ntt(root_rev, 1);\r\n     \
    \   root_rev.resize(f.size());\r\n        root_rev = root_rev.inv().rev() * Poly<T>(f);\r\
    \n        root_rev.erase(root_rev.begin(), root_rev.begin() + f.size() - 1);\r\
    \n        root_rev.resize(n);\r\n        reverse(ALL(root_rev));\r\n\r\n     \
    \   vector<Poly<T>> c(n << 1);\r\n        c[1] = root_rev;\r\n        for (int\
    \ i = 1; i < n; i++) {\r\n            int d = c[i].size();\r\n            Poly<T>\
    \ fc = c[i];\r\n            trans.ntt(fc);\r\n            for (int k = 0; k <\
    \ 2; k++) {\r\n                Poly<T> prod(d);\r\n                const auto\
    \ &sibling = t[i * 2 + (k ^ 1)];\r\n                for (int j = 0; j < d; j++)\r\
    \n                    prod[j] = fc[j] * sibling[j];\r\n                trans.ntt(prod,\
    \ 1);\r\n                c[i * 2 + k] =\r\n                    vector<T>(prod.begin()\
    \ + d / 2, prod.end());\r\n            }\r\n        }\r\n\r\n        vector<T>\
    \ res(m);\r\n        for (int i = 0; i < m; i++)\r\n            res[i] = c[n +\
    \ i][0];\r\n        return res;\r\n    }\r\n\r\n    vector<T> build(vector<T>\
    \ &ys) {\r\n        assert((int)ys.size() >= m);\r\n\r\n        Poly<T> root_rev\
    \ = t[1];\r\n        trans.ntt(root_rev, 1);\r\n        root_rev.resize(m + 1);\r\
    \n        auto den = run(root_rev.rev().diff());\r\n        for (int i = 0; i\
    \ < m; i++)\r\n            ys[i] /= den[i];\r\n\r\n        // c[i] is the NTT\
    \ of the reversed interpolation numerator below i.\r\n        // Its size equals\
    \ the number of leaves below the node.\r\n        vector<Poly<T>> c(n << 1);\r\
    \n        for (int i = 0; i < n; i++) {\r\n            c[n + i].resize(1);\r\n\
    \            if (i < m)\r\n                c[n + i][0] = ys[i];\r\n        }\r\
    \n        for (int i = n - 1; i; i--) {\r\n            trans.doubling(c[i << 1]);\r\
    \n            trans.doubling(c[i << 1 | 1]);\r\n            int d = c[i << 1].size();\r\
    \n            c[i].resize(d);\r\n            for (int j = 0; j < d; j++)\r\n \
    \               c[i][j] = c[i << 1][j] * t[i << 1 | 1][j] +\r\n              \
    \            c[i << 1 | 1][j] * t[i << 1][j];\r\n        }\r\n\r\n        trans.ntt(c[1],\
    \ 1);\r\n        c[1].resize(m);\r\n        reverse(ALL(c[1]));\r\n        return\
    \ c[1];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Multipoint Evaluation\r\n */\r\n"
  code: "#pragma once\r\n\r\ntemplate<typename T>struct MultiEval{\r\n    int m,n;\
    \ vector<Poly<T>> t;\r\n    MultiEval(vector<T>& v){\r\n        m=v.size(),n=1;\
    \ while(n<m)n<<=1;\r\n        t.resize(n<<1);\r\n        rep(i,0,n){\r\n     \
    \       T w=(i<m?v[i]:0);\r\n            t[n+i]=Poly<T>({-w,T(1)});\r\n      \
    \  }\r\n        for(int i=n-1;i;i--)t[i]=t[i*2]*t[i*2+1];\r\n    }\r\n    vector<T>\
    \ run(const vector<T>& f){\r\n        if(f.empty())return vector<T>(m);\r\n  \
    \      vector<Poly<T>> c(n*2);\r\n        auto v=t[1].rev();\r\n        v.resize(f.size());\r\
    \n        v=v.inv().rev()*Poly<T>(f);\r\n        v.erase(v.begin(),v.begin()+f.size()-1);\r\
    \n        v.resize(n); reverse(ALL(v)); c[1]=v;\r\n        rep(i,1,n){\r\n   \
    \         int d=c[i].size();\r\n            rep(k,0,2){\r\n                auto\
    \ add=t[i*2+(k^1)];\r\n                add.resize(d/2+1);\r\n                add=add.rev();\r\
    \n                add*=c[i];\r\n                add.resize(d);\r\n           \
    \     c[i*2+k]=vector<T>(add.begin()+d/2,add.end());\r\n            }\r\n    \
    \    }\r\n        vector<T> res(m); rep(i,0,m)res[i]=c[n+i][0];\r\n        return\
    \ res;\r\n    }\r\n    vector<T> build(vector<T>& ys){\r\n        auto w=t[1].rev();\r\
    \n        w.resize(m+1);\r\n        auto vs=run(w.rev().diff());\r\n        rep(i,0,m)ys[i]/=vs[i];\r\
    \n        vector<Poly<T>> c(n*2);\r\n        rep(i,0,n){\r\n            if(i<m)c[n+i]=Poly<T>({ys[i]});\r\
    \n            else c[n+i]=Poly<T>({T()});\r\n        }\r\n        for(int i=n-1;i;i--)c[i]=c[i*2]*t[i*2+1]+c[i*2+1]*t[i*2];\r\
    \n        c[1]=vector<T>(c[1].begin()+(n-m),c[1].end());\r\n        c[1].resize(m);\r\
    \n       return c[1];\r\n    }\r\n};\r\n\r\ntemplate <typename T> struct MultievalWithNTT\
    \ {\r\n    int m, n;\r\n    vector<Poly<T>> t;\r\n    NTT<T> trans;\r\n\r\n  \
    \  MultievalWithNTT(const vector<T> &v) : m(v.size()), n(1) {\r\n        while\
    \ (n < m)\r\n            n <<= 1;\r\n        assert(2LL * n <= (1LL << NTT<T>::rank2));\r\
    \n\r\n        // t[i] is the NTT of the reversed product polynomial of node i.\r\
    \n        // Its size is twice the number of leaves below the node.\r\n      \
    \  t.resize(n << 1);\r\n        for (int i = 0; i < n; i++) {\r\n            T\
    \ x = i < m ? v[i] : T(0);\r\n            t[n + i] = Poly<T>({T(1), -x});\r\n\
    \            trans.ntt(t[n + i]);\r\n        }\r\n        for (int i = n - 1;\
    \ i; i--) {\r\n            Poly<T> l = t[i << 1], r = t[i << 1 | 1];\r\n     \
    \       trans.doubling(l);\r\n            trans.doubling(r);\r\n            t[i].resize(l.size());\r\
    \n            for (int j = 0; j < (int)l.size(); j++)\r\n                t[i][j]\
    \ = l[j] * r[j];\r\n        }\r\n    }\r\n\r\n    vector<T> run(const vector<T>\
    \ &f) {\r\n        if (f.empty())\r\n            return vector<T>(m);\r\n\r\n\
    \        Poly<T> root_rev = t[1];\r\n        trans.ntt(root_rev, 1);\r\n     \
    \   root_rev.resize(f.size());\r\n        root_rev = root_rev.inv().rev() * Poly<T>(f);\r\
    \n        root_rev.erase(root_rev.begin(), root_rev.begin() + f.size() - 1);\r\
    \n        root_rev.resize(n);\r\n        reverse(ALL(root_rev));\r\n\r\n     \
    \   vector<Poly<T>> c(n << 1);\r\n        c[1] = root_rev;\r\n        for (int\
    \ i = 1; i < n; i++) {\r\n            int d = c[i].size();\r\n            Poly<T>\
    \ fc = c[i];\r\n            trans.ntt(fc);\r\n            for (int k = 0; k <\
    \ 2; k++) {\r\n                Poly<T> prod(d);\r\n                const auto\
    \ &sibling = t[i * 2 + (k ^ 1)];\r\n                for (int j = 0; j < d; j++)\r\
    \n                    prod[j] = fc[j] * sibling[j];\r\n                trans.ntt(prod,\
    \ 1);\r\n                c[i * 2 + k] =\r\n                    vector<T>(prod.begin()\
    \ + d / 2, prod.end());\r\n            }\r\n        }\r\n\r\n        vector<T>\
    \ res(m);\r\n        for (int i = 0; i < m; i++)\r\n            res[i] = c[n +\
    \ i][0];\r\n        return res;\r\n    }\r\n\r\n    vector<T> build(vector<T>\
    \ &ys) {\r\n        assert((int)ys.size() >= m);\r\n\r\n        Poly<T> root_rev\
    \ = t[1];\r\n        trans.ntt(root_rev, 1);\r\n        root_rev.resize(m + 1);\r\
    \n        auto den = run(root_rev.rev().diff());\r\n        for (int i = 0; i\
    \ < m; i++)\r\n            ys[i] /= den[i];\r\n\r\n        // c[i] is the NTT\
    \ of the reversed interpolation numerator below i.\r\n        // Its size equals\
    \ the number of leaves below the node.\r\n        vector<Poly<T>> c(n << 1);\r\
    \n        for (int i = 0; i < n; i++) {\r\n            c[n + i].resize(1);\r\n\
    \            if (i < m)\r\n                c[n + i][0] = ys[i];\r\n        }\r\
    \n        for (int i = n - 1; i; i--) {\r\n            trans.doubling(c[i << 1]);\r\
    \n            trans.doubling(c[i << 1 | 1]);\r\n            int d = c[i << 1].size();\r\
    \n            c[i].resize(d);\r\n            for (int j = 0; j < d; j++)\r\n \
    \               c[i][j] = c[i << 1][j] * t[i << 1 | 1][j] +\r\n              \
    \            c[i << 1 | 1][j] * t[i << 1][j];\r\n        }\r\n\r\n        trans.ntt(c[1],\
    \ 1);\r\n        c[1].resize(m);\r\n        reverse(ALL(c[1]));\r\n        return\
    \ c[1];\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Multipoint Evaluation\r\n */\r\n"
  dependsOn: []
  isVerificationFile: false
  path: FPS/multieval.hpp
  requiredBy: []
  timestamp: '2026-10-28 08:02:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_multipoint_evaluation.test.cpp
  - Verify/LC_polynomial_interpolation.test.cpp
documentation_of: FPS/multieval.hpp
layout: document
redirect_from:
- /library/FPS/multieval.hpp
- /library/FPS/multieval.hpp.html
title: Multipoint Evaluation
---
