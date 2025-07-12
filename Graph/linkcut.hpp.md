---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_dynamic_tree_vertex_add_path_sum.test.cpp
    title: Verify/LC_dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: Verify/LC_dynamic_tree_vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_dynamic_tree_vertex_set_path_composite.test.cpp
    title: Verify/LC_dynamic_tree_vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Link-Cut Tree
    links: []
  bundledCode: "#line 2 \"Graph/linkcut.hpp\"\n\ntemplate <typename M, typename N,\
    \ N (*f)(N, N)> struct LCT {\n    struct Node {\n        Node *lp = nullptr, *rp\
    \ = nullptr, *par = nullptr;\n        N val;\n        M sum;\n        int idx,\
    \ sz = 1;\n        bool rev = 0;\n        Node() {}\n        Node(int idx, N val)\
    \ : idx(idx), val(val) {}\n        void inverse() {\n            swap(lp, rp);\n\
    \            sum.inverse();\n            rev ^= 1;\n        }\n        void eval()\
    \ {\n            if (rev) {\n                if (lp)\n                    lp->inverse();\n\
    \                if (rp)\n                    rp->inverse();\n               \
    \ rev = 0;\n            }\n        }\n        void update() {\n            sz\
    \ = 1;\n            if (lp)\n                sz += lp->sz;\n            if (rp)\n\
    \                sz += rp->sz;\n            sum.merge(val, lp ? lp->sum : M(),\
    \ rp ? rp->sum : M());\n        }\n        bool is_root() {\n            return\
    \ !par || (par->lp != this && par->rp != this);\n        }\n        void rotate()\
    \ {\n            Node *pp, *p, *c;\n            p = par, pp = p->par;\n      \
    \      if (p->lp == this) {\n                c = rp;\n                rp = p;\n\
    \                p->lp = c;\n            } else {\n                c = lp;\n \
    \               lp = p;\n                p->rp = c;\n            }\n         \
    \   if (pp) {\n                if (pp->lp == p)\n                    pp->lp =\
    \ this;\n                if (pp->rp == p)\n                    pp->rp = this;\n\
    \            }\n            par = pp;\n            p->par = this;\n          \
    \  if (c)\n                c->par = p;\n            p->update();\n           \
    \ update();\n        }\n        void splay() {\n            eval();\n        \
    \    while (!is_root()) {\n                Node *q = par;\n                if\
    \ (q->is_root()) {\n                    q->eval();\n                    eval();\n\
    \                    if (q->lp == this)\n                        rotate();\n \
    \                   else\n                        rotate();\n                }\
    \ else {\n                    Node *r = q->par;\n                    r->eval();\n\
    \                    q->eval();\n                    eval();\n               \
    \     if (r->lp == q) {\n                        if (q->lp == this) {\n      \
    \                      q->rotate();\n                            rotate();\n \
    \                       } else {\n                            rotate();\n    \
    \                        rotate();\n                        }\n              \
    \      } else {\n                        if (q->rp == this) {\n              \
    \              q->rotate();\n                            rotate();\n         \
    \               } else {\n                            rotate();\n            \
    \                rotate();\n                        }\n                    }\n\
    \                }\n            }\n        }\n    };\n    std::vector<Node *>\
    \ all_nodes;\n    LCT() {}\n    ~LCT() {\n        // \u30C7\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u3067\u5168 Node \u3092 delete\n        for (Node *p : all_nodes) {\n \
    \           delete p;\n        }\n        all_nodes.clear();\n    }\n    Node\
    \ *make(int idx, N val) {\n        Node *p = new Node(idx, val);\n        all_nodes.push_back(p);\n\
    \        return p;\n    }\n    Node *expose(Node *v) {\n        Node *pre = nullptr;\n\
    \        for (Node *cur = v; cur; cur = cur->par) {\n            cur->splay();\n\
    \            if (cur->rp)\n                cur->sum.add(cur->rp->sum);\n     \
    \       cur->rp = pre;\n            if (cur->rp)\n                cur->sum.sub(cur->rp->sum);\n\
    \            cur->update();\n            pre = cur;\n        }\n        v->splay();\n\
    \        return pre;\n    }\n    void link(Node *c, Node *p) {\n        evert(c);\n\
    \        expose(p);\n        c->par = p;\n        p->rp = c;\n        p->update();\n\
    \    }\n    void cut(Node *c, Node *p) {\n        evert(p);\n        expose(c);\n\
    \        c->lp->par = nullptr;\n        c->lp = nullptr;\n        c->update();\n\
    \    }\n    void evert(Node *v) {\n        expose(v);\n        v->inverse();\n\
    \        v->eval();\n    }\n    Node *lca(Node *u, Node *v) {\n        expose(u);\n\
    \        return expose(v);\n    }\n    Node *root(Node *v) {\n        expose(v);\n\
    \        while (v->lp)\n            v->eval(), v = v->lp;\n        return v;\n\
    \    }\n    bool same(Node *u, Node *v) {\n        return root(u) == root(v);\n\
    \    }\n    void update(Node *v, N x) {\n        expose(v);\n        v->val =\
    \ f(v->val, x);\n        v->update();\n    }\n    M &query(Node *u, Node *v) {\
    \ // root = u -> v\n        evert(u);\n        expose(v);\n        return v->sum;\n\
    \    }\n};\n\n/**\n * @brief Link-Cut Tree\n */\n"
  code: "#pragma once\n\ntemplate <typename M, typename N, N (*f)(N, N)> struct LCT\
    \ {\n    struct Node {\n        Node *lp = nullptr, *rp = nullptr, *par = nullptr;\n\
    \        N val;\n        M sum;\n        int idx, sz = 1;\n        bool rev =\
    \ 0;\n        Node() {}\n        Node(int idx, N val) : idx(idx), val(val) {}\n\
    \        void inverse() {\n            swap(lp, rp);\n            sum.inverse();\n\
    \            rev ^= 1;\n        }\n        void eval() {\n            if (rev)\
    \ {\n                if (lp)\n                    lp->inverse();\n           \
    \     if (rp)\n                    rp->inverse();\n                rev = 0;\n\
    \            }\n        }\n        void update() {\n            sz = 1;\n    \
    \        if (lp)\n                sz += lp->sz;\n            if (rp)\n       \
    \         sz += rp->sz;\n            sum.merge(val, lp ? lp->sum : M(), rp ? rp->sum\
    \ : M());\n        }\n        bool is_root() {\n            return !par || (par->lp\
    \ != this && par->rp != this);\n        }\n        void rotate() {\n         \
    \   Node *pp, *p, *c;\n            p = par, pp = p->par;\n            if (p->lp\
    \ == this) {\n                c = rp;\n                rp = p;\n             \
    \   p->lp = c;\n            } else {\n                c = lp;\n              \
    \  lp = p;\n                p->rp = c;\n            }\n            if (pp) {\n\
    \                if (pp->lp == p)\n                    pp->lp = this;\n      \
    \          if (pp->rp == p)\n                    pp->rp = this;\n            }\n\
    \            par = pp;\n            p->par = this;\n            if (c)\n     \
    \           c->par = p;\n            p->update();\n            update();\n   \
    \     }\n        void splay() {\n            eval();\n            while (!is_root())\
    \ {\n                Node *q = par;\n                if (q->is_root()) {\n   \
    \                 q->eval();\n                    eval();\n                  \
    \  if (q->lp == this)\n                        rotate();\n                   \
    \ else\n                        rotate();\n                } else {\n        \
    \            Node *r = q->par;\n                    r->eval();\n             \
    \       q->eval();\n                    eval();\n                    if (r->lp\
    \ == q) {\n                        if (q->lp == this) {\n                    \
    \        q->rotate();\n                            rotate();\n               \
    \         } else {\n                            rotate();\n                  \
    \          rotate();\n                        }\n                    } else {\n\
    \                        if (q->rp == this) {\n                            q->rotate();\n\
    \                            rotate();\n                        } else {\n   \
    \                         rotate();\n                            rotate();\n \
    \                       }\n                    }\n                }\n        \
    \    }\n        }\n    };\n    std::vector<Node *> all_nodes;\n    LCT() {}\n\
    \    ~LCT() {\n        // \u30C7\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u5168 Node\
    \ \u3092 delete\n        for (Node *p : all_nodes) {\n            delete p;\n\
    \        }\n        all_nodes.clear();\n    }\n    Node *make(int idx, N val)\
    \ {\n        Node *p = new Node(idx, val);\n        all_nodes.push_back(p);\n\
    \        return p;\n    }\n    Node *expose(Node *v) {\n        Node *pre = nullptr;\n\
    \        for (Node *cur = v; cur; cur = cur->par) {\n            cur->splay();\n\
    \            if (cur->rp)\n                cur->sum.add(cur->rp->sum);\n     \
    \       cur->rp = pre;\n            if (cur->rp)\n                cur->sum.sub(cur->rp->sum);\n\
    \            cur->update();\n            pre = cur;\n        }\n        v->splay();\n\
    \        return pre;\n    }\n    void link(Node *c, Node *p) {\n        evert(c);\n\
    \        expose(p);\n        c->par = p;\n        p->rp = c;\n        p->update();\n\
    \    }\n    void cut(Node *c, Node *p) {\n        evert(p);\n        expose(c);\n\
    \        c->lp->par = nullptr;\n        c->lp = nullptr;\n        c->update();\n\
    \    }\n    void evert(Node *v) {\n        expose(v);\n        v->inverse();\n\
    \        v->eval();\n    }\n    Node *lca(Node *u, Node *v) {\n        expose(u);\n\
    \        return expose(v);\n    }\n    Node *root(Node *v) {\n        expose(v);\n\
    \        while (v->lp)\n            v->eval(), v = v->lp;\n        return v;\n\
    \    }\n    bool same(Node *u, Node *v) {\n        return root(u) == root(v);\n\
    \    }\n    void update(Node *v, N x) {\n        expose(v);\n        v->val =\
    \ f(v->val, x);\n        v->update();\n    }\n    M &query(Node *u, Node *v) {\
    \ // root = u -> v\n        evert(u);\n        expose(v);\n        return v->sum;\n\
    \    }\n};\n\n/**\n * @brief Link-Cut Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/linkcut.hpp
  requiredBy: []
  timestamp: '2025-06-15 03:24:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_dynamic_tree_vertex_add_subtree_sum.test.cpp
  - Verify/LC_dynamic_tree_vertex_set_path_composite.test.cpp
  - Verify/LC_dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: Graph/linkcut.hpp
layout: document
redirect_from:
- /library/Graph/linkcut.hpp
- /library/Graph/linkcut.hpp.html
title: Link-Cut Tree
---
