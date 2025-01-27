#pragma once

template <typename M, typename N, M (*f)(M, M), M (*g)(M, N), N (*h)(N, N),
          M (*m1)(), N (*n1)(), int LIM = 10101010>
struct PersistentLazySegmentTree {
    struct Node {
        Node *lp, *rp;
        M data;
        N lazy;
        Node() {}
    };
    using np = Node *;
    Node buf[LIM];
    int pos, sz;
    np newleaf(M v) {
        np ret = &buf[pos++];
        ret->data = v;
        ret->lazy = n1();
        return ret;
    }
    np newpar(np lp, np rp) {
        np ret = &buf[pos++];
        ret->lp = lp;
        ret->rp = rp;
        ret->data = f(lp->data, rp->data);
        ret->lazy = n1();
        return ret;
    }
    np newlazy(np root, N x) {
        np ret = &buf[pos++];
        ret->lp = root->lp;
        ret->rp = root->rp;
        ret->lazy = h(root->lazy, x);
        ret->data = g(root->data, x);
        return ret;
    }

    PersistentLazySegmentTree() {}
    PersistentLazySegmentTree(int sz) : pos(0), sz(sz) {}
    np run(vector<M> &a) {
        assert(SZ(a) == sz);
        auto dfs = [&](auto &dfs, int L, int R) -> np {
            if (R - L == 1) {
                return newleaf(a[L]);
            }
            int mid = (L + R) >> 1;
            auto lp = dfs(dfs, L, mid);
            auto rp = dfs(dfs, mid, R);
            auto ret = newpar(lp, rp);
            return ret;
        };
        return dfs(dfs, 0, sz);
    }
    void eval(np root) {
        if (root->lazy != n1()) {
            if (root->lp) {
                root->lp = newlazy(root->lp, root->lazy);
            }
            if (root->rp) {
                root->rp = newlazy(root->rp, root->lazy);
            }
            root->lazy = n1();
        }
    }
    np update(int L, int R, N x, np root, int lb = 0, int rb = -1) {
        if (rb == -1)
            rb = sz;
        if (R <= lb or rb <= L)
            return root;
        if (L <= lb and rb <= R) {
            np ret = newlazy(root, x);
            return ret;
        }
        eval(root);
        int mid = (lb + rb) >> 1;
        np lp = update(L, R, x, root->lp, lb, mid);
        np rp = update(L, R, x, root->rp, mid, rb);
        np ret = newpar(lp, rp);
        return ret;
    }
    np copy(int L, int R, np other, np root, int lb = 0, int rb = -1) {
        if (rb == -1)
            rb = sz;
        if (R <= lb or rb <= L)
            return root;
        if (L <= lb and rb <= R)
            return other;
        eval(root);
        eval(other);
        int mid = (lb + rb) >> 1;
        np lp = copy(L, R, other->lp, root->lp, lb, mid);
        np rp = copy(L, R, other->rp, root->rp, mid, rb);
        np ret = newpar(lp, rp);
        return ret;
    }
    M query(int L, int R, np root, int lb = 0, int rb = -1) {
        if (rb == -1)
            rb = sz;
        if (R <= lb or rb <= L)
            return m1();
        eval(root);
        if (L <= lb and rb <= R)
            return root->data;
        int mid = (lb + rb) >> 1;
        M lx = query(L, R, root->lp, lb, mid);
        M rx = query(L, R, root->rp, mid, rb);
        return f(lx, rx);
    }
    vector<M> dump(np root) {
        vector<M> ret;
        auto dfs = [&](auto &dfs, np v, int L, int R) -> void {
            eval(v);
            int mid = (L + R) >> 1;
            bool leaf = 1;
            if (v->lp)
                dfs(dfs, v->lp, L, mid), leaf = 0;
            if (v->rp)
                dfs(dfs, v->rp, mid, R), leaf = 0;
            if (leaf) {
                ret.push_back(v->data);
            }
        };
        dfs(dfs, root, 0, sz);
        return ret;
    }
};

/**
 * @brief Persistent Lazy Segment Tree
 */