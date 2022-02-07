#define PROBLEM "https://judge.yosupo.jp/problem/static_range_lis_query"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/rangelis.hpp"

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    vector<int> p(n);
    io.read(p);

    RangeLIS buf(p);
    while(q--){
        int L,R;
        io.read(L,R);
        io.write(buf.query(L,R));
    }
    return 0;
}