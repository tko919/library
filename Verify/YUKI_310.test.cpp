#define PROBLEM "https://yukicoder.me/problems/no/310"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
#include "Convolution/arbitrary.hpp"
#include "FPS/arbitraryfps.hpp"
#include "Math/bbla.hpp"
using Fp = fp<>;
template <>
vector<Fp> Poly<Fp>::mult(const vector<Fp> &a, const vector<Fp> &b) const {
    return ArbitraryMult<Fp>(a, b);
}

int g[4010][4010] = {}, in[4010], out[4010];
void fail() {
    puts("0");
    exit(0);
}

FastIO io;
int main() {
    int n, m;
    io.read(n, m);
    if (n * n == m) {
        puts("1");
        return 0;
    }
    rep(i, 0, n) {
        g[i][i] = in[i] = out[i] = n;
        rep(j, 0, n) g[i][j]--;
    }
    rep(_, 0, m) {
        int x, y;
        io.read(x, y);
        x--;
        y--;
        in[y]--;
        out[x]--;
        g[x][y]++;
        g[y][y]--;
    }
    int s = -1, t = -1, N = 0, v[4010];
    rep(i, 0, n) {
        if (in[i] == 0 and out[i] == 0)
            continue;
        v[N++] = i;
        if (abs(in[i] - out[i]) > 1)
            fail();
        if (out[i] == in[i] + 1) {
            if (s != -1)
                fail();
            s = i;
        }
        if (out[i] + 1 == in[i]) {
            if (t != -1)
                fail();
            t = i;
        }
    }

    Fp ret = n * n - m;
    if (s != -1 and t != -1) {
        in[s]++;
        out[t]++;
        g[t][s]--;
        g[s][s]++;
        ret = 1;
    }
    rep(i, 0, N) ret *= Fact<Fp>(in[v[i]] - 1);
    SparseMatrix<Fp> mat(N - 1, -1);
    rep(i, 0, N - 1) rep(j, 0, N - 1) if (g[v[i]][v[j]] != -1 or i == j) {
        mat.add(i, j, g[v[i]][v[j]]);
    }
    ret *= FastDet(mat);
    io.write(ret.v);
    return 0;
}