#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "Math/stirlingquery.hpp"

int main(){
    int T,p;
    read(T,p);
    StirlingNumberQuery buf(p);
    while(T--){
        ll n,k;
        read(n,k);
        print(buf.SecondKind(n,k));
    }
    return 0;
}