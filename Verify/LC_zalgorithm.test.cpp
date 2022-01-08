#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "Template/template.hpp"
#include "String/zalgo.hpp"

int main(){
    string s;
    cin>>s;
    auto ret=Zalgo(s);
    rep(i,0,s.size())cout<<ret[i]<<'\n';
    return 0;
}