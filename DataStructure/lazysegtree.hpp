#pragma once

template<typename M,typename N,M (*f)(M,M),M (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>
    class LazySegmentTree{
    int sz,height;
    vector<M> data;
    vector<N> lazy;
    void update(int k){data[k]=f(data[k*2],data[k*2+1]);}
    void apply(int k,N x){
        data[k]=g(data[k],x);
        if(k<sz)lazy[k]=h(lazy[k],x);
    }
    void down(int k){
        apply(k*2,lazy[k]);
        apply(k*2+1,lazy[k]);
        lazy[k]=n1();
    }
public:
    LazySegmentTree(int n=0):LazySegmentTree(vector<M>(n,m1())){}
    LazySegmentTree(const vector<M>& a){
        sz=1,height=0;
        while(sz<(int)a.size())sz<<=1,height++;
        data.assign(2*sz,m1());
        lazy.assign(sz,n1());
        rep(i,0,a.size())data[sz+i]=a[i];
        for(int i=sz-1;i;i--)update(i);
    }
    void set(int k,M x){
        k+=sz;
        for(int i=height;i;i--)down(k>>i);
        data[k]=x;
        for(int i=1;i<=height;i++)update(k>>i);
    }
    void update(int L,int R,N x){
        if(L>=R)return;
        L+=sz,R+=sz;
        for(int i=height;i;i--){
            if(((L>>i)<<i)!=L)down(L>>i);
            if(((R>>i)<<i)!=R)down((R-1)>>i);
        }
        int lb=L,rb=R;
        while(L<R){
            if(L&1)apply(L++,x);
            if(R&1)apply(--R,x);
            L>>=1;
            R>>=1;
        }
        L=lb,R=rb;
        for(int i=1;i<=height;i++){
            if(((L>>i)<<i)!=L)update(L>>i);
            if(((R>>i)<<i)!=R)update((R-1)>>i);
        }
    }
    M query(int L,int R){
        if(L>=R)return m1();
        L+=sz,R+=sz;
        for(int i=height;i;i--){
            if(((L>>i)<<i)!=L)down(L>>i);
            if(((R>>i)<<i)!=R)down((R-1)>>i);
        }
        M lb=m1(),rb=m1();
        while(L<R){
            if(L&1)lb=f(lb,data[L++]);
            if(R&1)rb=f(data[--R],rb);
            L>>=1;
            R>>=1;
        }
        return f(lb,rb);
    }
};

/**
 * @brief Lazy Segment Tree
 */