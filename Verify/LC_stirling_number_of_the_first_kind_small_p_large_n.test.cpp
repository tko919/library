#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/stirlingquery.hpp"

FastIO io;
int main(){
    int T,p;
    io.read(T,p);
    StirlingNumberQuery buf(p);
    while(T--){
        ll n,k;
        io.read(n,k);
        io.write(buf.FirstKind(n,k));
    }
    return 0;
}