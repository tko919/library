---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Composition of Formal Power Series
    links: []
  bundledCode: "#line 2 \"FPS/composition.hpp\"\n\ntemplate <typename T> Poly<T> Composition(Poly<T>\
    \ f, Poly<T> g) {\n    assert(SZ(f) == SZ(g));\n    f = f.shift(g[0].v);\n   \
    \ g[0] = 0;\n\n    int sz = SZ(f), N = 1;\n    while (N < sz)\n        N <<= 1;\n\
    \    f.resize(N);\n    g.resize(N);\n    reverse(ALL(f));\n\n    static NTT<T>\
    \ trans;\n    const int M = 4 * N;\n    assert(M <= (1 << NTT<T>::rank2));\n\n\
    \    // The NTT is stored in bit-reversed order.  For R(x) = Q(-x), prepare\n\
    \    // the permutation and phase that turn NTT(Q) into NTT(reverse(R)).\n   \
    \ const int h = __builtin_ctzll((unsigned int)M);\n    vector<int> bitrev(M),\
    \ reflect(M);\n    for (int i = 1; i < M; i++)\n        bitrev[i] = (bitrev[i\
    \ >> 1] >> 1) | ((i & 1) << (h - 1));\n\n    Poly<T> twist(M);\n    T pw = 1,\
    \ step = -trans.iroot[h];\n    for (int e = 0; e < M; e++) {\n        int i =\
    \ bitrev[e];\n        reflect[i] = bitrev[((M >> 1) - e) & (M - 1)];\n       \
    \ twist[i] = pw;\n        pw *= step;\n    }\n\n    auto dfs = [&](auto &dfs,\
    \ int n, int k, Poly<T> &Q) -> Poly<T> {\n        if (n == 1) {\n            Poly<T>\
    \ P(k * 2);\n            rep(i, 0, k) P[i * 2] = f[i];\n            return P;\n\
    \        }\n        int n2 = n >> 1, k2 = k << 1;\n        const int L = 2 * n\
    \ * k;\n\n        // NTT(Q(-x))[i] is NTT(Q)[i ^ 1] in this ordering, so Q*R needs\n\
    \        // only one forward transform and one inverse transform.\n        Poly<T>\
    \ qhat = Q;\n        qhat.resize(M);\n        trans.ntt(qhat);\n        {\n  \
    \          Poly<T> QR(M);\n            for (int i = 0; i < M; i++)\n         \
    \       QR[i] = qhat[i] * qhat[i ^ 1];\n            trans.ntt(QR, 1);\n\n    \
    \        // Q(x) + Q(-x) contains only the even coefficients.\n            for\
    \ (int i = 0; i < L; i += 2)\n                QR[L + i] += Q[i] + Q[i];\n\n  \
    \          Poly<T> nQ(L);\n            rep(i, 0, k2) rep(j, 0, n2) nQ[n * i +\
    \ j] = QR[2 * n * i + 2 * j];\n            Q.swap(nQ);\n        }\n\n        //\
    \ Convert qhat in place to NTT(reverse(Q_old(-x))).  The mapping is\n        //\
    \ an involution, so each pair can be updated without another buffer.\n       \
    \ for (int i = 0; i < M; i++) {\n            int j = reflect[i];\n           \
    \ if (i < j) {\n                T x = qhat[i], y = qhat[j];\n                qhat[i]\
    \ = y * twist[i];\n                qhat[j] = x * twist[j];\n            } else\
    \ if (i == j) {\n                qhat[i] *= twist[i];\n            }\n       \
    \ }\n\n        auto nP = dfs(dfs, n2, k2, Q);\n        Poly<T> PR(M);\n      \
    \  rep(i, 0, k2) rep(j, 0, n2) PR[2 * n * i + 2 * j + 1] = nP[n * i + j];\n  \
    \      Poly<T> P(L);\n        rep(i, 0, L) P[i] += PR[L + i];\n        // middle\
    \ product\n        const int offset = L - 1;\n        trans.ntt(PR);\n       \
    \ rep(i, 0, M) PR[i] *= qhat[i];\n        trans.ntt(PR, 1);\n        rep(i, 0,\
    \ L) P[i] += PR[i + offset];\n        return P;\n    };\n\n    int k = 1;\n  \
    \  Poly<T> Q(N * 2);\n    rep(i, 0, sz) Q[i] = -g[i];\n    auto P = dfs(dfs, N,\
    \ k, Q);\n    Poly<T> ret(sz);\n    rep(i, 0, sz) ret[i] = P[N - 1 - i];\n   \
    \ return ret;\n};\n\n/**\n * @brief Composition of Formal Power Series\n */\n"
  code: "#pragma once\n\ntemplate <typename T> Poly<T> Composition(Poly<T> f, Poly<T>\
    \ g) {\n    assert(SZ(f) == SZ(g));\n    f = f.shift(g[0].v);\n    g[0] = 0;\n\
    \n    int sz = SZ(f), N = 1;\n    while (N < sz)\n        N <<= 1;\n    f.resize(N);\n\
    \    g.resize(N);\n    reverse(ALL(f));\n\n    static NTT<T> trans;\n    const\
    \ int M = 4 * N;\n    assert(M <= (1 << NTT<T>::rank2));\n\n    // The NTT is\
    \ stored in bit-reversed order.  For R(x) = Q(-x), prepare\n    // the permutation\
    \ and phase that turn NTT(Q) into NTT(reverse(R)).\n    const int h = __builtin_ctzll((unsigned\
    \ int)M);\n    vector<int> bitrev(M), reflect(M);\n    for (int i = 1; i < M;\
    \ i++)\n        bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (h - 1));\n\n\
    \    Poly<T> twist(M);\n    T pw = 1, step = -trans.iroot[h];\n    for (int e\
    \ = 0; e < M; e++) {\n        int i = bitrev[e];\n        reflect[i] = bitrev[((M\
    \ >> 1) - e) & (M - 1)];\n        twist[i] = pw;\n        pw *= step;\n    }\n\
    \n    auto dfs = [&](auto &dfs, int n, int k, Poly<T> &Q) -> Poly<T> {\n     \
    \   if (n == 1) {\n            Poly<T> P(k * 2);\n            rep(i, 0, k) P[i\
    \ * 2] = f[i];\n            return P;\n        }\n        int n2 = n >> 1, k2\
    \ = k << 1;\n        const int L = 2 * n * k;\n\n        // NTT(Q(-x))[i] is NTT(Q)[i\
    \ ^ 1] in this ordering, so Q*R needs\n        // only one forward transform and\
    \ one inverse transform.\n        Poly<T> qhat = Q;\n        qhat.resize(M);\n\
    \        trans.ntt(qhat);\n        {\n            Poly<T> QR(M);\n           \
    \ for (int i = 0; i < M; i++)\n                QR[i] = qhat[i] * qhat[i ^ 1];\n\
    \            trans.ntt(QR, 1);\n\n            // Q(x) + Q(-x) contains only the\
    \ even coefficients.\n            for (int i = 0; i < L; i += 2)\n           \
    \     QR[L + i] += Q[i] + Q[i];\n\n            Poly<T> nQ(L);\n            rep(i,\
    \ 0, k2) rep(j, 0, n2) nQ[n * i + j] = QR[2 * n * i + 2 * j];\n            Q.swap(nQ);\n\
    \        }\n\n        // Convert qhat in place to NTT(reverse(Q_old(-x))).  The\
    \ mapping is\n        // an involution, so each pair can be updated without another\
    \ buffer.\n        for (int i = 0; i < M; i++) {\n            int j = reflect[i];\n\
    \            if (i < j) {\n                T x = qhat[i], y = qhat[j];\n     \
    \           qhat[i] = y * twist[i];\n                qhat[j] = x * twist[j];\n\
    \            } else if (i == j) {\n                qhat[i] *= twist[i];\n    \
    \        }\n        }\n\n        auto nP = dfs(dfs, n2, k2, Q);\n        Poly<T>\
    \ PR(M);\n        rep(i, 0, k2) rep(j, 0, n2) PR[2 * n * i + 2 * j + 1] = nP[n\
    \ * i + j];\n        Poly<T> P(L);\n        rep(i, 0, L) P[i] += PR[L + i];\n\
    \        // middle product\n        const int offset = L - 1;\n        trans.ntt(PR);\n\
    \        rep(i, 0, M) PR[i] *= qhat[i];\n        trans.ntt(PR, 1);\n        rep(i,\
    \ 0, L) P[i] += PR[i + offset];\n        return P;\n    };\n\n    int k = 1;\n\
    \    Poly<T> Q(N * 2);\n    rep(i, 0, sz) Q[i] = -g[i];\n    auto P = dfs(dfs,\
    \ N, k, Q);\n    Poly<T> ret(sz);\n    rep(i, 0, sz) ret[i] = P[N - 1 - i];\n\
    \    return ret;\n};\n\n/**\n * @brief Composition of Formal Power Series\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: FPS/composition.hpp
  requiredBy: []
  timestamp: '2026-10-28 08:02:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: FPS/composition.hpp
layout: document
redirect_from:
- /library/FPS/composition.hpp
- /library/FPS/composition.hpp.html
title: Composition of Formal Power Series
---
