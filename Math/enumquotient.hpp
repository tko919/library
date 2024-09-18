#pragma once

template <typename T> vector<pair<T, T>> EnumQuotients(T n) {
    T SQ = sqrtl(n);
    while (SQ * SQ + SQ <= n)
        SQ++;
    T m = n / SQ;
    vector<pair<T, T>> ret;
    rep(i, 1, m + 1) ret.emplace_back(n / (i + 1) + 1, n / i + 1);
    rrep(i, 1, SQ) ret.emplace_back(i, i + 1);
    return ret;
}

/**
 * @brief Enumerate Quotients
 */