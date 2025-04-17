#pragma once

template <typename T, typename F> void EnumQuotients(T n, F f) {
    T SQ = sqrtl(n);
    while (SQ * SQ + SQ <= n)
        SQ++;
    T m = n / SQ;
    rep(i, 1, m + 1) f(n / (i + 1) + 1, n / i + 1);
    rrep(i, 1, SQ) f(i, i + 1);
}

/**
 * @brief Enumerate Quotients
 */