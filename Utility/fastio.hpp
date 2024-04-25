#pragma once
#include <unistd.h>
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf

uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
    char num[10000][4];
    constexpr Pre() : num() {
        for (int i = 0; i < 10000; i++) {
            int n = i;
            for (int j = 3; j >= 0; j--) {
                num[i][j] = n % 10 | '0';
                n /= 10;
            }
        }
    }
} constexpr pre;

inline void load() {
    memmove(ibuf, ibuf + pil, pir - pil);
    pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
    pil = 0;
    if (pir < SZ)
        ibuf[pir++] = '\n';
}

inline void flush() {
    fwrite(obuf, 1, por, stdout);
    por = 0;
}

void rd(char &c) {
    do {
        if (pil + 1 > pir)
            load();
        c = ibuf[pil++];
    } while (isspace(c));
}

void rd(string &x) {
    x.clear();
    char c;
    do {
        if (pil + 1 > pir)
            load();
        c = ibuf[pil++];
    } while (isspace(c));
    do {
        x += c;
        if (pil == pir)
            load();
        c = ibuf[pil++];
    } while (!isspace(c));
}

template <typename T> void rd_real(T &x) {
    string s;
    rd(s);
    x = stod(s);
}

template <typename T> void rd_integer(T &x) {
    if (pil + 100 > pir)
        load();
    char c;
    do
        c = ibuf[pil++];
    while (c < '-');
    bool minus = 0;
    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
        if (c == '-') {
            minus = 1, c = ibuf[pil++];
        }
    }
    x = 0;
    while ('0' <= c) {
        x = x * 10 + (c & 15), c = ibuf[pil++];
    }
    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
        if (minus)
            x = -x;
    }
}

void rd(int &x) {
    rd_integer(x);
}
void rd(ll &x) {
    rd_integer(x);
}
void rd(i128 &x) {
    rd_integer(x);
}
void rd(uint &x) {
    rd_integer(x);
}
void rd(ull &x) {
    rd_integer(x);
}
void rd(u128 &x) {
    rd_integer(x);
}
void rd(double &x) {
    rd_real(x);
}
void rd(long double &x) {
    rd_real(x);
}

template <class T, class U> void rd(pair<T, U> &p) {
    return rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T> void rd_tuple(T &t) {
    if constexpr (N < std::tuple_size<T>::value) {
        auto &x = std::get<N>(t);
        rd(x);
        rd_tuple<N + 1>(t);
    }
}
template <class... T> void rd(tuple<T...> &tpl) {
    rd_tuple(tpl);
}

template <size_t N = 0, typename T> void rd(array<T, N> &x) {
    for (auto &d : x)
        rd(d);
}
template <class T> void rd(vector<T> &x) {
    for (auto &d : x)
        rd(d);
}

void read() {}
template <class H, class... T> void read(H &h, T &...t) {
    rd(h), read(t...);
}

void wt(const char c) {
    if (por == SZ)
        flush();
    obuf[por++] = c;
}
void wt(const string s) {
    for (char c : s)
        wt(c);
}
void wt(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++)
        wt(s[i]);
}

template <typename T> void wt_integer(T x) {
    if (por > SZ - 100)
        flush();
    if (x < 0) {
        obuf[por++] = '-', x = -x;
    }
    int outi;
    for (outi = 96; x >= 10000; outi -= 4) {
        memcpy(out + outi, pre.num[x % 10000], 4);
        x /= 10000;
    }
    if (x >= 1000) {
        memcpy(obuf + por, pre.num[x], 4);
        por += 4;
    } else if (x >= 100) {
        memcpy(obuf + por, pre.num[x] + 1, 3);
        por += 3;
    } else if (x >= 10) {
        int q = (x * 103) >> 10;
        obuf[por] = q | '0';
        obuf[por + 1] = (x - q * 10) | '0';
        por += 2;
    } else
        obuf[por++] = x | '0';
    memcpy(obuf + por, out + outi + 4, 96 - outi);
    por += 96 - outi;
}

template <typename T> void wt_real(T x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << double(x);
    string s = oss.str();
    wt(s);
}

void wt(int x) {
    wt_integer(x);
}
void wt(ll x) {
    wt_integer(x);
}
void wt(i128 x) {
    wt_integer(x);
}
void wt(uint x) {
    wt_integer(x);
}
void wt(ull x) {
    wt_integer(x);
}
void wt(u128 x) {
    wt_integer(x);
}
void wt(double x) {
    wt_real(x);
}
void wt(long double x) {
    wt_real(x);
}

template <class T, class U> void wt(const pair<T, U> val) {
    wt(val.first);
    wt(' ');
    wt(val.second);
}
template <size_t N = 0, typename T> void wt_tuple(const T t) {
    if constexpr (N < std::tuple_size<T>::value) {
        if constexpr (N > 0) {
            wt(' ');
        }
        const auto x = std::get<N>(t);
        wt(x);
        wt_tuple<N + 1>(t);
    }
}
template <class... T> void wt(tuple<T...> tpl) {
    wt_tuple(tpl);
}
template <class T, size_t S> void wt(const array<T, S> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
        if (i)
            wt(' ');
        wt(val[i]);
    }
}
template <class T> void wt(const vector<T> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
        if (i)
            wt(' ');
        wt(val[i]);
    }
}

void print() {
    wt('\n');
}
template <class Head, class... Tail> void print(Head &&head, Tail &&...tail) {
    wt(head);
    if (sizeof...(Tail))
        wt(' ');
    print(forward<Tail>(tail)...);
}
void __attribute__((destructor)) _d() {
    flush();
}
} // namespace fastio

using fastio::flush;
using fastio::print;
using fastio::read;

inline void first(bool i = true) {
    print(i ? "first" : "second");
}
inline void Alice(bool i = true) {
    print(i ? "Alice" : "Bob");
}
inline void yes(bool i = true) {
    print(i ? "yes" : "no");
}
inline void Yes(bool i = true) {
    print(i ? "Yes" : "No");
}
inline void No() {
    print("No");
}
inline void YES(bool i = true) {
    print(i ? "YES" : "NO");
}
inline void NO() {
    print("NO");
}
inline void Yay(bool i = true) {
    print(i ? "Yay!" : ":(");
}
inline void Possible(bool i = true) {
    print(i ? "Possible" : "Impossible");
}
inline void POSSIBLE(bool i = true) {
    print(i ? "POSSIBLE" : "IMPOSSIBLE");
}

/**
 * @brief Fast IO
 */