#pragma once

template<typename T,T (*f)(T,T)>struct DisjointSparseTable{
    vector<vector<T>> buf;
    vector<int> height;
    DisjointSparseTable(const vector<T>& a){
        int n=a.size(),LG=0;
        while((1<<LG)<=n)LG++;
        buf.assign(LG,vector<T>(n));
        height.assign(1<<LG,0);
        rep(i,2,1<<LG)height[i]=height[i>>1]+1;
        rep(i,0,n)buf[0][i]=a[i];
        rep(lg,1,LG){
            int add=1<<lg;
            for(int j=0;j<n;j+=(add<<1)){
                int pos=min(j+add,n);
                buf[lg][pos-1]=a[pos-1];
                for(int k=pos-2;k>=j;k--)buf[lg][k]=f(a[k],buf[lg][k+1]);
                if(n<=pos)break;
                buf[lg][pos]=a[pos];
                for(int k=pos+1;k<min(pos+add,n);k++)buf[lg][k]=f(buf[lg][k-1],a[k]);
            }
        }
    }
    T query(int L,int R){
        if(L>=--R)return buf[0][L];
        return f(buf[height[L^R]][L],buf[height[L^R]][R]);
    }
};

/**
 * @brief Disjoint Sparse Table
 */