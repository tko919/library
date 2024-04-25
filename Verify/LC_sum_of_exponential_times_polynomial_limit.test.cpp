#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
using Fp=fp<998244353>;

#include "Math/powertable.hpp"
#include "FPS/sumofpolyexp.hpp"

int main(){
    Fp r;
    int d;
    read(r.v,d);

    auto pws=powertable<Fp>(d+1,d);
    auto ret=LimitSumOfPolyExp(pws,r);
    print(ret.v);
    return 0;
}