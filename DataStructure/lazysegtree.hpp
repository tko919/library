#pragma once

template<typename M,typename N
    ,M (*f)(M,M),M (*g)(M,N),N (*h)(N,N),M (*m1)(),N (*n1)()>
class LazySegmentTree{
    int sz,height; vector<M> data; vector<N> lazy;
    M ref(int k){return g(data[k],lazy[k]);}
    void recalc(int k){while(k>>=1)data[k]=f(ref(2*k),ref(2*k+1));}
    void thrust(int k){for(int i=height;i>0;i--)eval(k>>i);}
    void eval(int k){
        lazy[2*k]=h(lazy[2*k],lazy[k]); lazy[2*k+1]=h(lazy[2*k+1],lazy[k]);
        data[k]=ref(k); lazy[k]=n1();
    }
public:
    LazySegmentTree(int n){
        sz=1,height=0; while(sz<n)sz<<=1,height++;
        data.assign(2*sz,m1()); lazy.assign(2*sz,n1());
    }
    void run(vector<M>& v){
        rep(i,0,v.size())data[i+sz]=v[i];
        for(int k=sz-1;k>0;k--)data[k]=f(data[2*k],data[2*k+1]);
    }
    void set(int a,M x){thrust(a+=sz); data[a]=x; recalc(a);}
    void update(int a,int b,N x){
        if(a>=b)return;
        thrust(a+=sz); thrust(b+=sz-1);
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1)lazy[l]=h(lazy[l],x),++l;
            if(r&1)--r,lazy[r]=h(lazy[r],x);
        }
        recalc(a); recalc(b);
    }
    M query(int a,int b){
        if(a>=b)return m1();
        thrust(a+=sz); thrust(b+=sz-1);
        M L=m1(),R=m1();
        for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if(l&1)L=f(L,ref(l++));
            if(r&1)R=f(ref(--r),R);
        } return f(L,R);
    }
};

/**
 * @brief Lazy Segment Tree
 */