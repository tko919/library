#pragma once

template<typename T>pair<T,ll> MaxIndependentSet(vector<vector<int>>& a,vector<T> cost,int _rot=1e6){
    int n=a.size();
    vector<ll> es(n);
    rep(i,0,n)rep(j,0,n)if(a[i][j]){
        es[i]|=(1LL<<j);
    }
    vector<int> ord(n);
    iota(ALL(ord),0);
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    T ret=0;
    ll cur=0;
    rep(_,0,_rot){
        shuffle(ALL(ord),mt);
        T add=0;
        ll used=0;
        for(auto& v:ord)if(!(used&es[v])){
            used|=(1LL<<v);
            add+=cost[v];
        }
        if(chmax(ret,add))cur=used;
    }
    return {ret,cur};
}

/**
 * @brief Maximum Independent Set
 */