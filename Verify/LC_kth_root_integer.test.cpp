#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/kthroot.hpp"
using ull=unsigned long long;

void solve(int _rot){
    // io.write<false>("Case #"+to_string(_rot)+": ");
    ull a,k;
    read(a,k);
    ull ret=Kthroot(k,a);
    print(ret);
}

int main(){
    int t;
    read(t);
    rep(rot,0,t)solve(rot+1);
    return 0;
}