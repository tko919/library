---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segtree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_point_set_range_sort_range_composite.test.cpp
    title: Verify/LC_point_set_range_sort_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Sortable Segment Tree
    links: []
  bundledCode: "#line 2 \"DataStructure/segtree.hpp\"\n\r\ntemplate <typename M, typename\
    \ N, M (*f)(M, M), M (*g)(M, N), M (*m1)()>\r\nstruct SegmentTree {\r\n    int\
    \ sz, n;\r\n    vector<M> data;\r\n    SegmentTree(int _n = 0) : n(_n) {\r\n \
    \       sz = 1;\r\n        while (sz < _n)\r\n            sz <<= 1;\r\n      \
    \  data.assign(2 * sz, m1());\r\n    }\r\n    void run(vector<M> &v) {\r\n   \
    \     for (int i = 0; i < (int)v.size(); i++)\r\n            data[i + sz] = v[i];\r\
    \n        for (int k = sz - 1; k > 0; k--)\r\n            data[k] = f(data[2 *\
    \ k], data[2 * k + 1]);\r\n    }\r\n    void set(int k, const M &x) {\r\n    \
    \    k += sz;\r\n        data[k] = x;\r\n        while (k >>= 1)\r\n         \
    \   data[k] = f(data[2 * k], data[2 * k + 1]);\r\n    }\r\n    void update(int\
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
    \ @brief Segment Tree\r\n */\n#line 3 \"DataStructure/sortablesegtree.hpp\"\n\r\
    \ntemplate<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)(),int LG=30>struct\
    \ SortableSegmentTree{\r\n    SortableSegmentTree(){}\r\n    SortableSegmentTree(vector<int>&\
    \ ks,vector<M>& vs):n(ks.size()),seg(n),Es(n){\r\n        rep(i,0,n){\r\n    \
    \        Ls.insert(i);\r\n            Es[i]=new Elem(ks[i],vs[i]);\r\n       \
    \     seg.set(i,vs[i]);\r\n        }\r\n        Ls.insert(n);\r\n    }\r\n   \
    \ void update(int i,int key,M val){\r\n        split(i);\r\n        split(i+1);\r\
    \n        Es[i]=new Elem(key,val);\r\n        seg.set(i,val);\r\n    }  \r\n \
    \   M query(int L,int R){\r\n        split(L);\r\n        split(R);\r\n      \
    \  return seg.query(L,R);\r\n    }\r\n    void sort(int L,int R,bool rev=false){\r\
    \n        split(L);\r\n        split(R);\r\n        int pos=L;\r\n        for(;;){\r\
    \n            pos=*(Ls.upper_bound(pos));\r\n            if(pos>=R)break;\r\n\
    \            Es[L]=meld(Es[L],Es[pos]);\r\n            Es[pos]=new Elem();\r\n\
    \            seg.set(pos,m1());\r\n            Ls.erase(pos);\r\n        }\r\n\
    \        Es[L]->set(rev);\r\n        seg.set(L,Es[L]->value());\r\n    }\r\nprivate:\r\
    \n    struct Trie{\r\n        Trie *cp[2];\r\n        int sz;\r\n        M val,lav;\r\
    \n        Trie(){cp[0]=cp[1]=nullptr;}\r\n        Trie(int key,M v){cp[0]=cp[1]=nullptr,init(key,v);}\r\
    \n        void init(int key,M v,int lg=LG){\r\n            sz=1;\r\n         \
    \   val=lav=v;\r\n            if(lg==-1)return;\r\n            if(!cp[key>>lg&1])cp[key>>lg&1]=new\
    \ Trie();\r\n            cp[key>>lg&1]->init(key,v,lg-1);\r\n        }\r\n   \
    \     void update(){\r\n            if(!cp[0] and !cp[1])return;\r\n         \
    \   sz=0;\r\n            val=lav=m1();\r\n            if(cp[0]){\r\n         \
    \       sz+=cp[0]->sz;\r\n                val=f(val,cp[0]->val);\r\n         \
    \       lav=f(cp[0]->lav,lav);\r\n            }\r\n            if(cp[1]){\r\n\
    \                sz+=cp[1]->sz;\r\n                val=f(val,cp[1]->val);\r\n\
    \                lav=f(cp[1]->lav,lav);\r\n            }\r\n        }\r\n    \
    \    void apply(N x){\r\n            assert(sz==1);\r\n            val=lav=g(val,x);\r\
    \n            if(cp[0])cp[0]->apply(x);\r\n            if(cp[1])cp[1]->apply(x);\r\
    \n        }\r\n    };\r\n    using Tp=Trie*;\r\n    int sz(Tp t){return t?t->sz:0;}\r\
    \n    Tp meld(Tp a,Tp b){\r\n        if(!a)return b;\r\n        if(!b)return a;\r\
    \n        a->cp[0]=meld(a->cp[0],b->cp[0]);\r\n        a->cp[1]=meld(a->cp[1],b->cp[1]);\r\
    \n        a->update();\r\n        return a;\r\n    }\r\n    pair<Tp,Tp> split(Tp\
    \ t,int k){\r\n        if(k==0)return {nullptr,t};\r\n        if(k==sz(t))return\
    \ {t,nullptr};\r\n        if(k<sz(t->cp[0])){\r\n            auto [l,tmp]=split(t->cp[0],k);\r\
    \n            auto L=new Trie();\r\n            L->cp[0]=l;\r\n            L->update();\r\
    \n            auto R=new Trie();\r\n            R->cp[0]=tmp,R->cp[1]=t->cp[1];\r\
    \n            R->update();\r\n            return {L,R};\r\n        }\r\n     \
    \   else{\r\n            auto [tmp,r]=split(t->cp[1],k-sz(t->cp[0]));\r\n    \
    \        auto L=new Trie();\r\n            auto R=new Trie();\r\n            L->cp[0]=t->cp[0],L->cp[1]=tmp;\r\
    \n            L->update();\r\n            R->cp[1]=r;\r\n            R->update();\r\
    \n            return {L,R};\r\n        }\r\n    }\r\n    struct Elem{\r\n    \
    \    Tp node;\r\n        bool rev;\r\n        Elem():node(nullptr),rev(0){}\r\n\
    \        Elem(int key,M x):node(new Trie(key,x)),rev(0){}\r\n        Elem(Tp t,bool\
    \ r):node(t),rev(r){}\r\n        void set(bool r){rev=r;}\r\n        void apply(N\
    \ x){node->apply(x);}\r\n        M value(){return rev?node->lav:node->val;}\r\n\
    \    };\r\n    using Ep=Elem*;\r\n    Ep meld(Ep s,Ep t){\r\n        return new\
    \ Elem(meld(s->node,t->node),0);\r\n    }\r\n    pair<Ep,Ep> split(Ep t,int k){\r\
    \n        if(t->rev)k=sz(t->node)-k;\r\n        auto [L,R]=split(t->node,k);\r\
    \n        if(t->rev)swap(L,R);\r\n        auto LE=new Elem(L,t->rev);\r\n    \
    \    auto RE=new Elem(R,t->rev);\r\n        return {LE,RE};\r\n    }\r\n\r\n \
    \   const int n;\r\n    SegmentTree<M,N,f,g,m1> seg;\r\n    set<int> Ls;\r\n \
    \   vector<Ep> Es;\r\n    void split(int k){\r\n        if(k>=n)return;\r\n  \
    \      int pos=*(--Ls.upper_bound(k));\r\n        if(pos==k)return;\r\n      \
    \  auto [L,R]=split(Es[pos],k-pos);\r\n        Es[pos]=L,Es[k]=R;\r\n        seg.set(pos,Es[pos]->value());\r\
    \n        seg.set(k,Es[k]->value());\r\n        Ls.insert(k);\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Sortable Segment Tree\r\n */\n"
  code: "#pragma once\r\n#include \"DataStructure/segtree.hpp\"\r\n\r\ntemplate<typename\
    \ M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)(),int LG=30>struct SortableSegmentTree{\r\
    \n    SortableSegmentTree(){}\r\n    SortableSegmentTree(vector<int>& ks,vector<M>&\
    \ vs):n(ks.size()),seg(n),Es(n){\r\n        rep(i,0,n){\r\n            Ls.insert(i);\r\
    \n            Es[i]=new Elem(ks[i],vs[i]);\r\n            seg.set(i,vs[i]);\r\n\
    \        }\r\n        Ls.insert(n);\r\n    }\r\n    void update(int i,int key,M\
    \ val){\r\n        split(i);\r\n        split(i+1);\r\n        Es[i]=new Elem(key,val);\r\
    \n        seg.set(i,val);\r\n    }  \r\n    M query(int L,int R){\r\n        split(L);\r\
    \n        split(R);\r\n        return seg.query(L,R);\r\n    }\r\n    void sort(int\
    \ L,int R,bool rev=false){\r\n        split(L);\r\n        split(R);\r\n     \
    \   int pos=L;\r\n        for(;;){\r\n            pos=*(Ls.upper_bound(pos));\r\
    \n            if(pos>=R)break;\r\n            Es[L]=meld(Es[L],Es[pos]);\r\n \
    \           Es[pos]=new Elem();\r\n            seg.set(pos,m1());\r\n        \
    \    Ls.erase(pos);\r\n        }\r\n        Es[L]->set(rev);\r\n        seg.set(L,Es[L]->value());\r\
    \n    }\r\nprivate:\r\n    struct Trie{\r\n        Trie *cp[2];\r\n        int\
    \ sz;\r\n        M val,lav;\r\n        Trie(){cp[0]=cp[1]=nullptr;}\r\n      \
    \  Trie(int key,M v){cp[0]=cp[1]=nullptr,init(key,v);}\r\n        void init(int\
    \ key,M v,int lg=LG){\r\n            sz=1;\r\n            val=lav=v;\r\n     \
    \       if(lg==-1)return;\r\n            if(!cp[key>>lg&1])cp[key>>lg&1]=new Trie();\r\
    \n            cp[key>>lg&1]->init(key,v,lg-1);\r\n        }\r\n        void update(){\r\
    \n            if(!cp[0] and !cp[1])return;\r\n            sz=0;\r\n          \
    \  val=lav=m1();\r\n            if(cp[0]){\r\n                sz+=cp[0]->sz;\r\
    \n                val=f(val,cp[0]->val);\r\n                lav=f(cp[0]->lav,lav);\r\
    \n            }\r\n            if(cp[1]){\r\n                sz+=cp[1]->sz;\r\n\
    \                val=f(val,cp[1]->val);\r\n                lav=f(cp[1]->lav,lav);\r\
    \n            }\r\n        }\r\n        void apply(N x){\r\n            assert(sz==1);\r\
    \n            val=lav=g(val,x);\r\n            if(cp[0])cp[0]->apply(x);\r\n \
    \           if(cp[1])cp[1]->apply(x);\r\n        }\r\n    };\r\n    using Tp=Trie*;\r\
    \n    int sz(Tp t){return t?t->sz:0;}\r\n    Tp meld(Tp a,Tp b){\r\n        if(!a)return\
    \ b;\r\n        if(!b)return a;\r\n        a->cp[0]=meld(a->cp[0],b->cp[0]);\r\
    \n        a->cp[1]=meld(a->cp[1],b->cp[1]);\r\n        a->update();\r\n      \
    \  return a;\r\n    }\r\n    pair<Tp,Tp> split(Tp t,int k){\r\n        if(k==0)return\
    \ {nullptr,t};\r\n        if(k==sz(t))return {t,nullptr};\r\n        if(k<sz(t->cp[0])){\r\
    \n            auto [l,tmp]=split(t->cp[0],k);\r\n            auto L=new Trie();\r\
    \n            L->cp[0]=l;\r\n            L->update();\r\n            auto R=new\
    \ Trie();\r\n            R->cp[0]=tmp,R->cp[1]=t->cp[1];\r\n            R->update();\r\
    \n            return {L,R};\r\n        }\r\n        else{\r\n            auto\
    \ [tmp,r]=split(t->cp[1],k-sz(t->cp[0]));\r\n            auto L=new Trie();\r\n\
    \            auto R=new Trie();\r\n            L->cp[0]=t->cp[0],L->cp[1]=tmp;\r\
    \n            L->update();\r\n            R->cp[1]=r;\r\n            R->update();\r\
    \n            return {L,R};\r\n        }\r\n    }\r\n    struct Elem{\r\n    \
    \    Tp node;\r\n        bool rev;\r\n        Elem():node(nullptr),rev(0){}\r\n\
    \        Elem(int key,M x):node(new Trie(key,x)),rev(0){}\r\n        Elem(Tp t,bool\
    \ r):node(t),rev(r){}\r\n        void set(bool r){rev=r;}\r\n        void apply(N\
    \ x){node->apply(x);}\r\n        M value(){return rev?node->lav:node->val;}\r\n\
    \    };\r\n    using Ep=Elem*;\r\n    Ep meld(Ep s,Ep t){\r\n        return new\
    \ Elem(meld(s->node,t->node),0);\r\n    }\r\n    pair<Ep,Ep> split(Ep t,int k){\r\
    \n        if(t->rev)k=sz(t->node)-k;\r\n        auto [L,R]=split(t->node,k);\r\
    \n        if(t->rev)swap(L,R);\r\n        auto LE=new Elem(L,t->rev);\r\n    \
    \    auto RE=new Elem(R,t->rev);\r\n        return {LE,RE};\r\n    }\r\n\r\n \
    \   const int n;\r\n    SegmentTree<M,N,f,g,m1> seg;\r\n    set<int> Ls;\r\n \
    \   vector<Ep> Es;\r\n    void split(int k){\r\n        if(k>=n)return;\r\n  \
    \      int pos=*(--Ls.upper_bound(k));\r\n        if(pos==k)return;\r\n      \
    \  auto [L,R]=split(Es[pos],k-pos);\r\n        Es[pos]=L,Es[k]=R;\r\n        seg.set(pos,Es[pos]->value());\r\
    \n        seg.set(k,Es[k]->value());\r\n        Ls.insert(k);\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Sortable Segment Tree\r\n */"
  dependsOn:
  - DataStructure/segtree.hpp
  isVerificationFile: false
  path: DataStructure/sortablesegtree.hpp
  requiredBy: []
  timestamp: '2024-08-09 08:04:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_point_set_range_sort_range_composite.test.cpp
documentation_of: DataStructure/sortablesegtree.hpp
layout: document
redirect_from:
- /library/DataStructure/sortablesegtree.hpp
- /library/DataStructure/sortablesegtree.hpp.html
title: Sortable Segment Tree
---
