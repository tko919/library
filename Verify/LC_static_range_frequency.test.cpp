#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/wavelet.hpp"

FastIO io;
int main(){
    int n,q;
    io.read(n,q);
    vector<int> a(n);
    io.read(a);

    WaveletMatrix<int> wm(a);
    int L,R,x;
    while(q--){
        io.read(L,R,x);
        io.write(wm.rank(L,R,x));
    }
    return 0;
}