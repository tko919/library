#pragma once

template<typename T>struct WeightedUnionFind{
    int n;
    vector<int> par;
    vector<T> pot;
    WeightedUnionFind(int _n=0):n(_n),par(n,-1),pot(n){}
    int root(int x){
        if(par[x]<0)return x;
        else{
            int r=root(par[x]);
            pot[x]+=pot[par[x]];
            return par[x]=r;
        }
    }
    bool same(int x,int y){return root(x)==root(y);}
    int size(int x){return -par[root(x)];}
    T diff(int x,int y){return pot[x]-pot[y];}
    bool unite(int x,int y,T w){
        int rx=root(x),ry=root(y);
        if(rx==ry)return false;
        if(size(x)<size(y))swap(x,y),swap(rx,ry),w=-w;
        par[rx]+=par[ry];
        par[ry]=rx;
        pot[ry]=diff(x,y)-w;
        n--;
        return true;
    }
};

/**
 * @brief Weighted Union Find
 */