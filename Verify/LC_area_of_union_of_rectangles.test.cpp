#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "DataStructure/unionrect.hpp"

int main(){
    int n;
    read(n);
    UnionRect buf;
    rep(_,0,n){
        int L,D,R,U;
        read(L,D,R,U);
        buf.add(L,R,D,U);
    }
    ll ret=buf.run();
    print(ret);
    return 0;
}