#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/dualsegtree.hpp"

int f(int a, int b) {
    if (b != INT32_MAX)
        return b;
    else
        return a;
}
int e() {
    return INT32_MAX;
}

int main() {
    int n, q;
    read(n, q);

    DualSegmentTree<int, f, e> seg(n);
    int c, L, R, x;
    while (q--) {
        read(c);
        if (c == 0) {
            read(L, R, x);
            R++;
            seg.update(L, R, x);
        } else {
            read(x);
            print(seg.query(x));
        }
    }
    return 0;
}