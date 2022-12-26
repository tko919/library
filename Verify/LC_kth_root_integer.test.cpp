#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/kthroot.hpp"
using ull=unsigned long long;

FastIO io;
void solve(int _rot){
    // io.write<false>("Case #"+to_string(_rot)+": ");
    ull a,k;
    io.read(a,k);
    ull ret=Kthroot(k,a);
    io.write(ret);
}

int main(){
    int t;
    io.read(t);
    rep(rot,0,t)solve(rot+1);
    return 0;
}