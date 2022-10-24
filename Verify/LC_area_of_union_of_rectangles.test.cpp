#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "DataStructure/unionrect.hpp"

FastIO io;
int main(){
    int n;
    io.read(n);
    UnionRect buf;
    rep(_,0,n){
        int L,D,R,U;
        io.read(L,D,R,U);
        buf.add(L,R,D,U);
    }
    ll ret=buf.run();
    io.write(ret);
    return 0;
}