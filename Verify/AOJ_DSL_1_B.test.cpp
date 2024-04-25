#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/weightedunionfind.hpp"

int main() {
    int n, q;
    read(n, q);
    WeightedUnionFind<int> uni(n);
    while (q--) {
        int t;
        read(t);
        if (t == 0) {
            int x, y, z;
            read(x, y, z);
            uni.unite(x, y, z);
        } else {
            int x, y;
            read(x, y);
            if (uni.same(x, y))
                print(uni.diff(x, y));
            else
                print('?');
        }
    }
    return 0;
}