#pragma once

template<typename M,M (*f)(M,M),M (*m1)()>class DualSegmentTree{
    int sz,height;
    vector<M> data;
    void down(int k){
        data[k*2]=f(data[k*2],data[k]);
        data[k*2+1]=f(data[k*2+1],data[k]);
        data[k]=m1();
    }
public:
    DualSegmentTree(int n){
        sz=1,height=0;
        while(sz<n)sz<<=1,height++;
        data.assign(2*sz,m1());
    }
    void run(vector<M>& v){
        for(int i=0;i<(int)v.size();i++)data[i+sz]=v[i];
    }
    void update(int a,int b,M x){
        if(a>=b)return;
        a+=sz,b+=sz;
        for(int i=height;i;i--){
            if(((a>>i)<<i)!=a)down(a>>i);
            if(((b>>i)<<i)!=b)down((b-1)>>i);
        }
        for(;a<b;a>>=1,b>>=1){
            if(a&1)data[a]=f(data[a],x),a++;
            if(b&1)--b,data[b]=f(data[b],x);
        }
    }
    M query(int k){
        k+=sz;
        for(int i=height;i;i--){
            if(((k>>i)<<i)!=k)down(k>>i);
        }
        M ret=data[k];
        while(k>>=1)ret=f(ret,data[k]);
        return ret;
    }
};

/**
 * @brief Dual Segment Tree
 */