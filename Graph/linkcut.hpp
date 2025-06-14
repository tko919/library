#pragma once

template <typename M, typename N, N (*f)(N, N)> struct LCT {
    struct Node {
        Node *lp = nullptr, *rp = nullptr, *par = nullptr;
        N val;
        M sum;
        int idx, sz = 1;
        bool rev = 0;
        Node() {}
        Node(int idx, N val) : idx(idx), val(val) {}
        void inverse() {
            swap(lp, rp);
            sum.inverse();
            rev ^= 1;
        }
        void eval() {
            if (rev) {
                if (lp)
                    lp->inverse();
                if (rp)
                    rp->inverse();
                rev = 0;
            }
        }
        void update() {
            sz = 1;
            if (lp)
                sz += lp->sz;
            if (rp)
                sz += rp->sz;
            sum.merge(val, lp ? lp->sum : M(), rp ? rp->sum : M());
        }
        bool is_root() {
            return !par || (par->lp != this && par->rp != this);
        }
        void rotate() {
            Node *pp, *p, *c;
            p = par, pp = p->par;
            if (p->lp == this) {
                c = rp;
                rp = p;
                p->lp = c;
            } else {
                c = lp;
                lp = p;
                p->rp = c;
            }
            if (pp) {
                if (pp->lp == p)
                    pp->lp = this;
                if (pp->rp == p)
                    pp->rp = this;
            }
            par = pp;
            p->par = this;
            if (c)
                c->par = p;
            p->update();
            update();
        }
        void splay() {
            eval();
            while (!is_root()) {
                Node *q = par;
                if (q->is_root()) {
                    q->eval();
                    eval();
                    if (q->lp == this)
                        rotate();
                    else
                        rotate();
                } else {
                    Node *r = q->par;
                    r->eval();
                    q->eval();
                    eval();
                    if (r->lp == q) {
                        if (q->lp == this) {
                            q->rotate();
                            rotate();
                        } else {
                            rotate();
                            rotate();
                        }
                    } else {
                        if (q->rp == this) {
                            q->rotate();
                            rotate();
                        } else {
                            rotate();
                            rotate();
                        }
                    }
                }
            }
        }
    };
    std::vector<Node *> all_nodes;
    LCT() {}
    ~LCT() {
        // デストラクタで全 Node を delete
        for (Node *p : all_nodes) {
            delete p;
        }
        all_nodes.clear();
    }
    Node *make(int idx, N val) {
        Node *p = new Node(idx, val);
        all_nodes.push_back(p);
        return p;
    }
    Node *expose(Node *v) {
        Node *pre = nullptr;
        for (Node *cur = v; cur; cur = cur->par) {
            cur->splay();
            if (cur->rp)
                cur->sum.add(cur->rp->sum);
            cur->rp = pre;
            if (cur->rp)
                cur->sum.sub(cur->rp->sum);
            cur->update();
            pre = cur;
        }
        v->splay();
        return pre;
    }
    void link(Node *c, Node *p) {
        evert(c);
        expose(p);
        c->par = p;
        p->rp = c;
        p->update();
    }
    void cut(Node *c, Node *p) {
        evert(p);
        expose(c);
        c->lp->par = nullptr;
        c->lp = nullptr;
        c->update();
    }
    void evert(Node *v) {
        expose(v);
        v->inverse();
        v->eval();
    }
    Node *lca(Node *u, Node *v) {
        expose(u);
        return expose(v);
    }
    Node *root(Node *v) {
        expose(v);
        while (v->lp)
            v->eval(), v = v->lp;
        return v;
    }
    bool same(Node *u, Node *v) {
        return root(u) == root(v);
    }
    void update(Node *v, N x) {
        expose(v);
        v->val = f(v->val, x);
        v->update();
    }
    M &query(Node *u, Node *v) { // root = u -> v
        evert(u);
        expose(v);
        return v->sum;
    }
};

/**
 * @brief Link-Cut Tree
 */