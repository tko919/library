#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/modint.hpp"
using Fp=fp<998244353>;

#include "Math/powertable.hpp"
#include "FPS/sumofpolyexp.hpp"


int main(){
    Fp r;
    int d;
    ll n;
    read(r.v,d,n);

    auto pws=powertable<Fp>(d+1,d);
    auto ret=SumOfPolyExp(pws,r,n);
    print(ret.v);
    return 0;
}