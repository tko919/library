#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/binomquery.hpp"

int main() {
    int q, m;
    read(q, m);
    BinomialQuery buf(m);
    while (q--) {
        ll n, r;
        read(n, r);
        print(buf.nCr(n, r));
    }
    return 0;
}