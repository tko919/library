#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "Template/template.hpp"
#include "DataStructure/sparsetable.hpp"

int f(int a,int b){return min(a,b);}

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    rep(i,0,n)cin>>a[i];

    SparseTable<int,f> st(a);
    while(q--){
        int L,R;
        cin>>L>>R;
        cout<<st.query(L,R)<<'\n';
    }
    return 0;
}