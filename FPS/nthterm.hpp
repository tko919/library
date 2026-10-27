#pragma once

template <typename T> T nth(Poly<T> p, Poly<T> q, ll n) {
    while (n) {
        Poly<T> base(q), np, nq;
        for (int i = 1; i < (int)q.size(); i += 2)
            base[i] = -base[i];
        p *= base;
        q *= base;
        for (int i = n & 1; i < (int)p.size(); i += 2)
            np.emplace_back(p[i]);
        for (int i = 0; i < (int)q.size(); i += 2)
            nq.emplace_back(q[i]);
        swap(p, np);
        swap(q, nq);
        n >>= 1;
    }
    return p[0] / q[0];
}

template <typename T> T nthWithNTT(Poly<T> p, Poly<T> q, ll n) {
    assert(!p.empty() and !q.empty() and q[0] != T(0));
    if (n == 0)
        return p[0] / q[0];

    int m = 1;
    while (m < (int)max(p.size(), q.size()))
        m <<= 1;

    static NTT<T> trans;
    assert(2LL * m <= (1LL << NTT<T>::rank2));

    p.resize(m);
    q.resize(m);
    trans.ntt(p);
    trans.ntt(q);

    // In this NTT's (bit-reversed) order, index i represents evaluation at
    // root[log2(2m)]^bit_reverse(i).  These factors are needed when taking
    // the odd coefficients of p(x)q(-x).
    const int h = __builtin_ctzll((unsigned int)m);
    vector<int> rev(m);
    for (int i = 1; i < m; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h - 1));

    vector<T> inv_alpha(m);
    T pw = 1, izeta = trans.iroot[h + 1];
    for (int i = 0; i < m; i++) {
        inv_alpha[rev[i]] = pw;
        pw *= izeta;
    }

    const T inv2 = T(2).inv();
    while (n) {
        trans.doubling(p);
        trans.doubling(q);

        Poly<T> np(m), nq(m);
        for (int i = 0; i < m; i++) {
            T a = p[2 * i] * q[2 * i + 1];
            T b = p[2 * i + 1] * q[2 * i];
            if (n & 1)
                np[i] = (a - b) * inv2 * inv_alpha[i];
            else
                np[i] = (a + b) * inv2;
            nq[i] = q[2 * i] * q[2 * i + 1];
        }
        p.swap(np);
        q.swap(nq);
        n >>= 1;
    }

    // The constant coefficient is the average of all transformed values;
    // the common factor 1/m cancels in the quotient.
    T ps = 0, qs = 0;
    for (int i = 0; i < m; i++) {
        ps += p[i];
        qs += q[i];
    }
    return ps / qs;
}

/**
 * @brief Bostan-Mori Algorithm
 */
