#pragma once
#include "DataStructure/unionfind.hpp"

template<typename T>pair<T,vector<pair<int,int>>> ManhattanMST(vector<T>& X,vector<T>& Y){
    using Q=pair<T,pair<int,int>>;
    int n=X.size();
    vector<int> ord(n);
    iota(ALL(ord),0);
    vector<Q> cand;
    rep(_,0,2){
        rep(__,0,2){
            sort(ALL(ord),[&](int i,int j){return X[i]+Y[i]<X[j]+Y[j];});
            map<T,int> sweep;
            for(auto& i:ord){
                for(auto it=sweep.lower_bound(-Y[i]);it!=sweep.end();it=sweep.erase(it)){
                    int j=it->second;
                    if(X[i]-X[j]<Y[i]-Y[j])break;
                    cand.push_back({abs(X[i]-X[j])+abs(Y[i]-Y[j]),{i,j}});
                }
                sweep[-Y[i]]=i;
            }
            swap(X,Y);
        }
        for(auto& x:X)x=-x;
    }
    sort(ALL(cand));
    UnionFind uni(n);
    T ret=0;
    vector<pair<int,int>> es;
    for(auto& [cost,uv]:cand){
        auto [u,v]=uv;
        if(uni.unite(u,v)){
            ret+=cost;
            es.push_back(uv);
        }
    }
    return {ret,es};
}

/**
 * @brief Manhattan MST
*/