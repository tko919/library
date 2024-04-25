#define PROBLEM "https://judge.yosupo.jp/problem/static_range_lis_query"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/rangelis.hpp"

int main(){
    int n,q;
    read(n,q);
    vector<int> p(n);
    read(p);

    RangeLIS buf(p);
    while(q--){
        int L,R;
        read(L,R);
        print(buf.query(L,R));
    }
    return 0;
}