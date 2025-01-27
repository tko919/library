#pragma once

#include "Math/fraction.hpp"
template <typename T> struct Surreal {
    static constexpr int LG = std::numeric_limits<T>::digits - 2;
    Frac<T> a;
    Surreal(T a = 0) : a(a, 1) {}
    Surreal(T a, T b) : a(a, b) {}
    Surreal(Frac<T> a) : a(a) {}
    static constexpr Surreal infty() {
        return Surreal(INF, 1);
    }
    bool operator==(Surreal const &rhs) const {
        return (a == rhs.a);
    }
    bool operator!=(Surreal const &rhs) const {
        return !(a == rhs);
    }
    bool operator<(Surreal const &rhs) const {
        return (a < rhs.a);
    }
    bool operator<=(Surreal const &rhs) const {
        return (a <= rhs.a);
    }
    bool operator>(Surreal const &rhs) const {
        return (a > rhs.a);
    }
    bool operator>=(Surreal const &rhs) const {
        return (a >= rhs.a);
    }
    friend Surreal operator+(const Surreal &x, const Surreal &y) {
        return x.a + y.a;
    }
    friend Surreal operator-(const Surreal &x, const Surreal &y) {
        return x.a - y.a;
    }
    friend Surreal operator-(const Surreal &x) {
        return -x.a;
    }
    Surreal &operator+=(const Surreal &x) {
        return (*this) = (*this) + x;
    }
    Surreal &operator-=(const Surreal &x) {
        return (*this) = (*this) - x;
    }

    static Surreal between(Surreal L, Surreal R, bool incL = 0, bool incR = 0) {
        Surreal ret(0);
        if (L < ret or (incL and L == ret)) {
            if (ret < R or (incR and R == ret)) {
                return ret;
            }
        }
        bool sign = 0;
        if (R <= 0) {
            sign = 1;
            swap(L, R);
            swap(incL, incR);
            L = -L, R = -R;
        }
        rep(lg, 0, LG + 1) {
            ll num = ceil(L.a.a << lg, L.a.b);
            if ((i128(L.a.a) << lg) == i128(L.a.b) * num and !incL)
                num++;
            ret = Surreal(num, 1LL << lg);
            if (ret < R or (incR and R == ret)) {
                if (sign)
                    ret = -ret;
                return ret;
            }
        }
        assert(0);
    }
    friend ostream &operator<<(ostream &os, const Surreal &x) {
        return os << x.a;
    }
};

struct NumStar {
    using A = Surreal<ll>;
    A a;
    int b;
    NumStar(A a = 0, int b = 0) : a(a), b(b) {}
    NumStar &operator+=(const NumStar &rhs) {
        a += rhs.a, b ^= rhs.b;
        return *this;
    }
    NumStar &operator-=(const NumStar &rhs) {
        a -= rhs.a, b ^= rhs.b;
        return *this;
    }
    NumStar operator-() const {
        return NumStar(-a, b);
    }
    bool operator==(const NumStar &rhs) const {
        return (a == rhs.a && b == rhs.b);
    }
    static int mex(vector<int> &a) {
        vector<int> exi(SZ(a) + 1);
        for (auto &x : a)
            exi[x] = 1;
        int ret = 0;
        while (exi[ret])
            ret++;
        return ret;
    }
    static pair<bool, NumStar> calc(vector<NumStar> lb, vector<NumStar> rb) {
        A L = -A::infty(), R = A::infty();
        vector<int> ls, rs;
        for (auto &num : lb) {
            if (chmax(L, num.a))
                ls.clear();
            if (L == num.a)
                ls.push_back(num.b);
        }
        for (auto &num : rb) {
            if (chmin(R, num.a))
                rs.clear();
            if (R == num.a)
                rs.push_back(num.b);
        }
        int lm = mex(ls), rm = mex(rs);
        if (L < R) {
            return {true, NumStar(A::between(L, R, lm == 0, rm == 0), 0)};
        } else if (L == R) {
            if (lm == rm)
                return {true, NumStar(L, lm)};
        }
        return {false, NumStar()};
    }
    friend ostream &operator<<(ostream &os, const NumStar &x) {
        return os << x.a << "+*" << x.b;
    }
    pair<bool, bool> outcome() {
        if (a > 0)
            return {1, 0};
        if (a < 0)
            return {0, 1};
        if (b == 0)
            return {0, 0};
        return {1, 1};
    }
};

// F(G):= {G_L,G_R} (pair)
template <typename State, typename F>
map<State, NumStar> SolvePartizanGame(const vector<State> &states, F option) {
    map<State, NumStar> ret;
    auto dfs = [&](auto &dfs, const State &current) -> pair<bool, NumStar> {
        if (ret.count(current))
            return {true, ret[current]};
        auto [gl, gr] = option(current);
        vector<NumStar> ls, rs;
        for (auto &to : gl) {
            auto [ch, lv] = dfs(dfs, to);
            if (!ch)
                return {false, NumStar()};
            ls.push_back(lv);
        }
        for (auto &to : gr) {
            auto [ch, rv] = dfs(dfs, to);
            if (!ch)
                return {false, NumStar()};
            rs.push_back(rv);
        }
        auto [ch, val] = NumStar::calc(ls, rs);
        if (!ch)
            return {false, NumStar()};
        return {true, ret[current] = val};
    };
    for (auto &s : states) {
        if (!dfs(dfs, s).first)
            return map<State, NumStar>();
    }
    return ret;
}

/**
 * @ Partizan Game Solver
 */