#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

int main() {
    int t;
    ll a, b;
    read(t);
    while (t--) {
        read(a, b);
        print(a + b);
    }
    return 0;
}