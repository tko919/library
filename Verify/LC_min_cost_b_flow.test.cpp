#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"

#include "Template/template.hpp"
#include "Graph/mincostflow.hpp"
#include "Utility/fastio.hpp"

namespace std {
string to_string(__int128_t x) {
    if (x == 0)
        return "0";
    __uint128_t k = x;
    if (k == (((__uint128_t)1) << 127))
        return "-170141183460469231731687303715884105728";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}
} // namespace std

int main() {
    int n, m;
    read(n, m);
    MinCostFlow<ll, i128> mcf(n);
    rep(i, 0, n) {
        int b;
        read(b);
        mcf.add_excess(i, b);
    }
    rep(i, 0, m) {
        int s, t, l, u, c;
        read(s, t, l, u, c);
        mcf.add_edge(s, t, l, u, c);
    }
    auto [ok, ret] = mcf.run();
    if (!ok) {
        print("infeasible");
        return 0;
    }
    print(to_string(ret));
    rep(i, 0, n) print(to_string(mcf.dual[i]));
    rep(i, 0, m) print(mcf.get_flow(i));
    return 0;
}