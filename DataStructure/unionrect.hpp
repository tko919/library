#pragma once
#include "DataStructure/lazysegtree.hpp"

struct UnionInterval{
    struct M{
        ll len,mi,cnt;
    };
    static M f(M a,M b){
        if(a.mi<b.mi)return {a.len+b.len,a.mi,a.cnt};
        else if(a.mi>b.mi)return {a.len+b.len,b.mi,b.cnt};
        else return {a.len+b.len,a.mi,a.cnt+b.cnt};
    }
    static M g(M a,int b){
        return M{a.len,min(INF,a.mi+b),a.cnt};
    }
    static int h(int a,int b){
        return a+b;
    }
    static M m1(){
        return M{0,INF,0};
    }
    static int m2(){return 0;}

    const int n=0;
    LazySegmentTree<M,int,f,g,h,m1,m2> seg;
    UnionInterval(){}
    UnionInterval(vector<int>& xs):n(xs.size()-1){
        vector<M> init(n);
        rep(i,0,n){
            init[i]=M{xs[i+1]-xs[i],0,xs[i+1]-xs[i]};
        }
        seg=LazySegmentTree<M,int,f,g,h,m1,m2>(init);
    }
    void add(int L,int R){
        seg.update(L,R,1);
    }
    void erase(int L,int R){
        seg.update(L,R,-1);
    }
    ll run(){
        auto [len,mi,cnt]=seg.query(0,n);
        if(mi==0)len-=cnt;
        return len;
    }
};

struct UnionRect{
    vector<int> L,R,D,U;
    UnionRect(){}
    void add(int lb,int rb,int db,int ub){
        L.push_back(lb);
        R.push_back(rb);
        D.push_back(db);
        U.push_back(ub);
    }
    ll run(){
        int n=L.size();
        vector<int> xs=L,ys=D;
        xs.insert(xs.end(),ALL(R));
        ys.insert(ys.end(),ALL(U));
        sort(ALL(xs));
        xs.erase(unique(ALL(xs)),xs.end());
        sort(ALL(ys));
        ys.erase(unique(ALL(ys)),ys.end());

        UnionInterval buf=UnionInterval(ys);
        using P=pair<int,int>;
        vector in(xs.size(),vector<P>()),out(xs.size(),vector<P>());
        rep(i,0,n){
            L[i]=lower_bound(ALL(xs),L[i])-xs.begin();
            R[i]=lower_bound(ALL(xs),R[i])-xs.begin();
            D[i]=lower_bound(ALL(ys),D[i])-ys.begin();
            U[i]=lower_bound(ALL(ys),U[i])-ys.begin();
            in[L[i]].push_back({D[i],U[i]});
            out[R[i]].push_back({D[i],U[i]});
        }
        ll ret=0;
        rep(i,0,xs.size()-1){
            for(auto& [d,u]:in[i])buf.add(d,u);
            for(auto& [d,u]:out[i])buf.erase(d,u);
            ret+=buf.run()*(xs[i+1]-xs[i]);
        }
        return ret;
    }
};

/**
 * @brief Area of Union of Rectangles
 */