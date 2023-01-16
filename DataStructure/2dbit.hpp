#pragma once
#include "DataStructure/bit.hpp"

template<class T>struct BIT2D{
    int n; vector<BIT<T>> d;
    vector<int> xs; vector<vector<int>> ys;
    vector<pair<ll,ll>> p;
    BIT2D(){}
    void push(ll x,ll y){p.push_back({x,y});}
    void init(){
        rep(i,0,p.size())xs.push_back(p[i].first);
        sort(ALL(xs)); xs.erase(unique(ALL(xs)),xs.end());
        n=xs.size()+1; ys.resize(n);
        rep(j,0,p.size()){
            int s=upper_bound(ALL(xs),p[j].first)-xs.begin();
            for(int i=s;i<n;i+=(i&-i))ys[i].push_back(p[j].second);
        }
        d.resize(n);
        rep(i,0,n){
            sort(ALL(ys[i])); ys[i].erase(unique(ALL(ys[i])),ys[i].end());
            d[i]=BIT<T>(ys[i].size()+2);
        }
    }
    void add(ll x,ll y,T z=1){
        int s=upper_bound(ALL(xs),x)-xs.begin();
        for(int i=s;i<n;i+=(i&-i)){
            int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();
            d[i].add(idx,z);
        }
    }
    T sum(ll x,ll y){
        T res=0;
        int s=upper_bound(ALL(xs),x)-xs.begin();
        for(int i=s;i;i-=(i&-i)){
            int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();
            res+=d[i].sum(idx+1);
        }
        return res;
    }
    T sum(ll x1,ll y1,ll x2,ll y2){return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);}
};

/**
 * @brief 2D Binary Indexed Tree
*/