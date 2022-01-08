#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "Template/template.hpp"
#include "String/manacher.hpp"

int main(){
    string s;
    cin>>s;
    auto ret=Manacher(s);
    rep(i,0,ret.size())cout<<ret[i]<<'\n';
    return 0;
}