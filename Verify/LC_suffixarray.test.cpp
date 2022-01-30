#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "Template/template.hpp"
#include "String/suffixarray.hpp"

int main(){
    string s;
    cin>>s;
    SuffixArray sa(s);
    rep(i,1,s.size()+1)cout<<sa.sa[i]<<'\n';
    return 0;
}