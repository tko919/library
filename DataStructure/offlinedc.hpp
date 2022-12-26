#pragma once
#include "DataStructure/rollbackunionfind.hpp"

struct DynamicConnectivity{
    using edge=pair<int,int>;
    RollbackUnionFind uni; int n,q,sz;
    vector<vector<edge>> seg;
    vector<pair<pair<int,int>,edge>> keep;
    map<edge,int> appear;
    DynamicConnectivity(int n,int q):uni(n),n(n),q(q){
        sz=1; while(sz<q)sz<<=1;
        seg.resize(2*sz-1);
    }
    void insert(int t,int u,int v){
        auto e=minmax(u,v); appear[e]=t;
    }
    void erase(int t,int u,int v){
        auto e=minmax(u,v);
        keep.push_back({{appear[e],t},e}); appear.erase(e);
    }
    void add(int a,int b,const edge& e,int k=0,int l=0,int r=-1){
        if(r<0)r=sz; if(r<=a||b<=l)return;
        if(a<=l&&r<=b){seg[k].push_back(e); return;}
        add(a,b,e,2*k+1,l,(l+r)/2); add(a,b,e,2*k+2,(l+r)/2,r);
    }
    void build(){
        for(auto& p:appear)add(p.second,q,p.first);
        for(auto& s:keep)add(s.first.first,s.first.second,s.second);
    }
    template<void (*f)(int)>void run(int k=0){
        for(auto e:seg[k]){
            if(e.first<0)uni.push(-e.first-1,e.second);
            else uni.merge(e.first,e.second);
        }
        if(k<sz-1){run(f,2*k+1); run(f,2*k+2);}
        else if(k-(sz-1)<q)f(k-(sz-1));
        for(auto& e:seg[k])uni.undo();
    }
};

/**
 * Offline Dynamic Connectivity
*/