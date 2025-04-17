#pragma once

#include "Utility/random.hpp"

template <typename T, int LIM = 1000000> class RBSTset {
    struct Node {
        Node *lp = nullptr, *rp = nullptr;
        int size = 1;
        T key;
        Node() = default;
        Node(T _k) : key(_k), lp(nullptr), rp(nullptr) {}
        void apply() {
            size = 1;
            if (lp)
                size += lp->size;
            if (rp)
                size += rp->size;
        }
    };
    int size(Node *x) {
        return x ? x->size : 0;
    }
    Node *merge(Node *L, Node *R) {
        if (!L)
            return R;
        if (!R)
            return L;
        if ((int)Random::get(size(L) + size(R) - 1) < size(L)) {
            L->rp = merge(L->rp, R);
            L->apply();
            return L;
        } else {
            R->lp = merge(L, R->lp);
            R->apply();
            return R;
        }
    }
    array<Node *, 2> split(Node *x, int k) {
        if (!x)
            return {nullptr, nullptr};
        if (k == size(x))
            return {x, nullptr};
        if (k <= size(x->lp)) {
            auto [lb, rb] = split(x->lp, k);
            Node *L = lb, *R = x;
            x->lp = rb;
            x->apply();
            return {L, R};
        } else {
            auto [lb, rb] = split(x->rp, k - size(x->lp) - 1);
            Node *L = x, *R = rb;
            x->rp = lb;
            x->apply();
            return {L, R};
        }
    }
    int lower_bound(Node *x, T v) {
        if (!x)
            return 0;
        if (x->key >= v)
            return lower_bound(x->lp, v);
        else
            return size(x->lp) + 1 + lower_bound(x->rp, v);
    }
    int upper_bound(Node *x, T v) {
        if (!x)
            return 0;
        if (x->key > v)
            return upper_bound(x->lp, v);
        else
            return size(x->lp) + 1 + upper_bound(x->rp, v);
    }
    void _dump(Node *cur, vector<T> &a) {
        if (!cur)
            return;
        _dump(cur->lp, a);
        a.push_back(cur->key);
        _dump(cur->rp, a);
    }

  public:
    array<Node, LIM> pool;
    int ptr;
    Node *root;
    RBSTset(Node *_r = nullptr) : root(_r), ptr(0) {}
    int size() {
        return size(root);
    }
    inline Node *alloc(const T &key) {
        return &(pool[ptr++] = Node(key));
    }
    void merge(RBSTset &a) {
        root = merge(root, a.root);
    }
    RBSTset split(int k) {
        auto [L, R] = split(root, k);
        root = L;
        return RBSTset(R);
    }
    bool find(T x) {
        Node *cur = root;
        for (;;) {
            if (!cur)
                break;
            if (cur->key == x)
                return true;
            else if (x < cur->key)
                cur = cur->lp;
            else
                cur = cur->rp;
        }
        return false;
    }
    void insert(T x, int k = -1) {
        if (k == -1)
            k = lower_bound(root, x);
        auto [L, R] = split(root, k);
        root = merge(merge(L, alloc(x)), R);
    }
    void erase(T x, int k = -1) {
        if (k == -1) {
            assert(find(x));
            k = lower_bound(root, x);
        }
        auto [L, t] = split(root, k);
        auto [tmp, R] = split(t, 1);
        root = merge(L, R);
    }
    T kth_element(int k) {
        if (k >= size(root) or k < 0)
            return T();
        auto [L, R] = split(root, k);
        Node *cur = R;
        while (cur->lp)
            cur = cur->lp;
        root = merge(L, R);
        return cur->key;
    }
    int lower_bound(T v) {
        return lower_bound(root, v);
    }
    int upper_bound(T v) {
        return upper_bound(root, v);
    }
    vector<T> dump() {
        vector<T> ret;
        _dump(root, ret);
        return ret;
    }
};

/**
 * @brief Randomized Binary Search Tree (set)
 */