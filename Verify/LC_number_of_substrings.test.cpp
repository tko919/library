#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "Template/template.hpp"
#include "String/suffixarray.hpp"

int main(){
    string s;
    cin>>s;
    int n=s.size();
    SuffixArray sa(s);
    ll ret=0;
    rep(i,0,n)ret+=n-sa.sa[i]-sa.lcp[i];
    cout<<ret<<'\n';
    return 0;
}