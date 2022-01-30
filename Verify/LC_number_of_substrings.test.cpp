#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "Template/template.hpp"
#include "String/suffixarray.hpp"

int main(){
    string s;
    cin>>s;
    int n=s.size();
    SuffixArray sa(s);
    ll ret=n-sa.sa[0];
    rep(i,1,n+1)ret+=n-sa.sa[i]-sa.lcp[i-1];
    cout<<ret<<'\n';
    return 0;
}