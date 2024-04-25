#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"
#include "DataStructure/wavelet.hpp"

int main(){
    int n,q;
    read(n,q);
    vector<int> a(n);
    read(a);

    WaveletMatrix<int> wm(a);
    int L,R,x;
    while(q--){
        read(L,R,x);
        print(wm.rank(L,R,x));
    }
    return 0;
}