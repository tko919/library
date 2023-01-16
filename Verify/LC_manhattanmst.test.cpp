#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "DataStructure/manhattanmst.hpp"

FastIO io;
int main(){
    int n;
    io.read(n);
    vector<ll> x(n),y(n);
    rep(i,0,n)io.read(x[i],y[i]);
    auto ret=ManhattanMST(x,y);
    io.write(ret.first);
    for(auto& [u,v]:ret.second)io.write(u,v);
    return 0;
}