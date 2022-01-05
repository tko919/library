#pragma once
#include "DataStructure/segtree.hpp"

template<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)()>struct SegmentTree2D{
    int n;
    vector<SegmentTree<M,N,f,g,m1>> st;
    vector<vector<int>> ys;
    SegmentTree2D(){}
    int id(int x,int y){return lower_bound(ALL(ys[x]),y)-ys[x].begin();}
    using P=pair<int,int>;
    vector<int> xs; vector<P> ps;
    void push(int x,int y){
        ps.push_back({x,y});
    }
    void init(){
        for(auto& [x,y]:ps)xs.push_back(x);
        sort(ALL(xs));
        xs.erase(unique(ALL(xs)),xs.end());
        n=xs.size();
        ys.resize(n*2);
        for(auto& [x,y]:ps){
            int i=lower_bound(ALL(xs),x)-xs.begin();
            for(i+=n;i;i>>=1)ys[i].push_back(y);
        }
        for(int i=0;i<n*2;i++){
            sort(ALL(ys[i]));
            ys[i].erase(unique(ALL(ys[i])),ys[i].end());
            st.push_back(SegmentTree<M,N,f,g,m1>(ys[i].size()));
        }
    }
    void update(int x,int y,N w){
        x=(lower_bound(ALL(xs),x)-xs.begin())+n;
        st[x].update(id(x,y),w);
        M cur=st[x][id(x,y)];
        int pos=x;
        while(x>>=1){
            M opp=st[pos^1].query(id(pos^1,y),id(pos^1,y+1));
            cur=f(cur,opp);
            st[x].set(id(x,y),cur);
            pos>>=1;
        }
    }
    M query(int x0,int x1,int y0,int y1){
        x0=lower_bound(ALL(xs),x0)-xs.begin();
        x1=lower_bound(ALL(xs),x1)-xs.begin();
        M res=m1();
        for(x0+=n,x1+=n;x0<x1;x0>>=1,x1>>=1){
            if(x0&1)res=f(res,st[x0].query(id(x0,y0),id(x0,y1))),x0++;
            if(x1&1)x1--,res=f(res,st[x1].query(id(x1,y0),id(x1,y1)));
        }
        return res;
    }
};

/**
 * @brief 2D Segment Tree
 */