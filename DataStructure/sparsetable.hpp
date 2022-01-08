#pragma once

template<typename T,T (*f)(T,T)>struct SparseTable{
    vector<vector<T>> st;
    vector<int> lgtable;
    SparseTable(const vector<T>& v){
        int LG=0;
        while((1<<LG)<=v.size())LG++;
        st.assign(LG,vector<T>(1<<LG));
        lgtable.assign(v.size()+1,0);
        rep(i,0,v.size())st[0][i]=v[i];
        rep(lg,1,LG){
            for(int j=0;j+(1<<lg)<=(1<<LG);j++){
                st[lg][j]=f(st[lg-1][j],st[lg-1][j+(1<<(lg-1))]);
            }
        }
        rep(i,2,v.size()+1)lgtable[i]=lgtable[i>>1]+1;
    }
    T query(int L,int R){
        int b=lgtable[R-L];
        return f(st[b][L],st[b][R-(1<<b)]);
    }
};

/**
 * @brief Sparse Table
 */