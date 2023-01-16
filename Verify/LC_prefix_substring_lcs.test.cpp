#define PROBLEM "https://judge.yosupo.jp/problem/prefix_substring_lcs"

#include "Template/template.hpp"
#include "Utility/fastio.hpp"

#include "String/prefixsubstrlcs.hpp"

FastIO io;
int main(){
    int q;
    string S,T;
    io.read(q,S,T);
    PrefixSubstringLCS buf(S,T);
    while(q--){
        int a,b,c;
        io.read(a,b,c);
        buf.add(a,b,c);
    }
    auto ret=buf.run();
    io.write(ret);
    return 0;
}