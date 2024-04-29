#pragma once

template <typename T, typename F, bool MINIMIZE = 1>
T FibonacciSearch(ll lb, ll rb, F f) {
    ll s = 1, t = 2;
    while (t < rb - lb + 2) {
        s += t;
        swap(s, t);
    }
    ll L = lb - 1, m1 = L + t - s, m2 = L + s;
    T v1 = f(m1), v2 = f(m2);
    while (m1 != m2) {
        t -= s;
        swap(s, t);
        if (rb < m2 or (MINIMIZE ? v1 >= v2 : v1 <= v2)) {
            m2 = m1;
            v2 = v1;
            m1 = L + t - s;
            v1 = f(m1);
        } else {
            L = m1;
            m1 = m2;
            v1 = v2;
            m2 = L + s;
            v2 = m2 <= rb ? f(m2) : v1;
        }
    }
    return m1;
}

/**
 * @brief Fibonacci Search
 */