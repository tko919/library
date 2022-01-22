#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/wavelet.hpp"

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    vector<int> a(n);
    io.read(a);

    vector<int> zip;
    for(auto& x:a)zip.push_back(x);
    sort(ALL(zip));
    zip.erase(unique(ALL(zip)),zip.end());
    rep(i,0,n)a[i]=lower_bound(ALL(zip),a[i])-zip.begin();

    WaveletMatrix<int> wm(a);
    int L,R,k;
    while(q--){
        io.read(L,R,k);
        io.write(zip[wm.quantile(L,R,k)]);
    }
    return 0;
}