#pragma once

template <class S, S (*op)(S, S), S (*e)()> class DynamicSegmenttree {
  public:
    DynamicSegmenttree(size_t n) : n(n), root(nullptr) {}

    void set(size_t p, S x) {
        assert(p < n);
        set(root, 0, n, p, x);
    }

    S get(size_t p) const {
        assert(p < n);
        return get(root, 0, n, p);
    }

    S query(size_t l, size_t r) const {
        assert(l <= r && r <= n);
        return prod(root, 0, n, l, r);
    }

    S query() const {
        return root ? root->product : e();
    }

    void reset(size_t l, size_t r) {
        assert(l <= r && r <= n);
        return reset(root, 0, n, l, r);
    }

    template <bool (*f)(S)> size_t max_right(size_t l) const {
        return max_right(l, [](S x) { return f(x); });
    }

    template <class F> size_t max_right(size_t l, const F &f) const {
        assert(l <= n);
        S product = e();
        assert(f(product));
        return max_right(root, 0, n, l, f, product);
    }

    template <bool (*f)(S)> size_t min_left(size_t r) const {
        return min_left(r, [](S x) { return f(x); });
    }

    template <class F> size_t min_left(size_t r, const F &f) const {
        assert(r <= n);
        S product = e();
        assert(f(product));
        return min_left(root, 0, n, r, f, product);
    }

  private:
    struct node;
    using node_ptr = std::unique_ptr<node>;

    struct node {
        size_t index;
        S value, product;
        node_ptr left, right;

        node(size_t index, S value)
            : index(index), value(value), product(value), left(nullptr),
              right(nullptr) {}

        void update() {
            product = op(op(left ? left->product : e(), value),
                         right ? right->product : e());
        }
    };

    const size_t n;
    node_ptr root;

    void set(node_ptr &t, size_t a, size_t b, size_t p, S x) const {
        if (!t) {
            t = std::make_unique<node>(p, x);
            return;
        }
        if (t->index == p) {
            t->value = x;
            t->update();
            return;
        }
        size_t c = (a + b) >> 1;
        if (p < c) {
            if (t->index < p)
                std::swap(t->index, p), std::swap(t->value, x);
            set(t->left, a, c, p, x);
        } else {
            if (p < t->index)
                std::swap(p, t->index), std::swap(x, t->value);
            set(t->right, c, b, p, x);
        }
        t->update();
    }

    S get(const node_ptr &t, size_t a, size_t b, size_t p) const {
        if (!t)
            return e();
        if (t->index == p)
            return t->value;
        size_t c = (a + b) >> 1;
        if (p < c)
            return get(t->left, a, c, p);
        else
            return get(t->right, c, b, p);
    }

    S prod(const node_ptr &t, size_t a, size_t b, size_t l, size_t r) const {
        if (!t || b <= l || r <= a)
            return e();
        if (l <= a && b <= r)
            return t->product;
        size_t c = (a + b) >> 1;
        S result = prod(t->left, a, c, l, r);
        if (l <= t->index && t->index < r)
            result = op(result, t->value);
        return op(result, prod(t->right, c, b, l, r));
    }

    void reset(node_ptr &t, size_t a, size_t b, size_t l, size_t r) const {
        if (!t || b <= l || r <= a)
            return;
        if (l <= a && b <= r) {
            t.reset();
            return;
        }
        size_t c = (a + b) >> 1;
        reset(t->left, a, c, l, r);
        reset(t->right, c, b, l, r);
        t->update();
    }

    template <class F>
    size_t max_right(const node_ptr &t, size_t a, size_t b, size_t l,
                     const F &f, S &product) const {
        if (!t || b <= l)
            return n;
        if (f(op(product, t->product))) {
            product = op(product, t->product);
            return n;
        }
        size_t c = (a + b) >> 1;
        size_t result = max_right(t->left, a, c, l, f, product);
        if (result != n)
            return result;
        if (l <= t->index) {
            product = op(product, t->value);
            if (!f(product))
                return t->index;
        }
        return max_right(t->right, c, b, l, f, product);
    }

    template <class F>
    size_t min_left(const node_ptr &t, size_t a, size_t b, size_t r, const F &f,
                    S &product) const {
        if (!t || r <= a)
            return 0;
        if (f(op(t->product, product))) {
            product = op(t->product, product);
            return 0;
        }
        size_t c = (a + b) >> 1;
        size_t result = min_left(t->right, c, b, r, f, product);
        if (result != 0)
            return result;
        if (t->index < r) {
            product = op(t->value, product);
            if (!f(product))
                return t->index + 1;
        }
        return min_left(t->left, a, c, r, f, product);
    }
};

/**
 * @brief Dynamic Segment Tree
 */