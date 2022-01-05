#pragma once

template<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree{
    int sz; vector<M> data;
    SegmentTree(int n){
        sz=1; while(sz<n)sz<<=1; data.assign(2*sz,m1());
    }
    void run(vector<M> v){
        for(int i=0;i<(int)v.size();i++)data[i+sz]=v[i];
        for(int k=sz-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);
    }
    void set(int k,const M &x){
        k+=sz; data[k]=x;
        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);
    }
    void update(int k,const N &x){
        k+=sz; data[k]=g(data[k],x);
        while(k>>=1)data[k]=f(data[2*k],data[2*k+1]);
    }
    M query(int a,int b){
        M L=m1(),R=m1();
        for(a+=sz,b+=sz;a<b;a>>=1,b>>=1){
            if(a&1)L=f(L,data[a++]);
            if(b&1)R=f(data[--b],R);
       } return f(L,R);
    }
    M operator[](const int &k)const{return data[k+sz];}
};

/**
 * @brief Segment Tree
 */