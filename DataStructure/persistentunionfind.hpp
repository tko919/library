#pragma once
#include "DataStructure/persistentarray.hpp"

struct PersistentUnionFind{
    PersistentArray<int> dat;
    PersistentUnionFind(int n){
        rep(i,0,n)dat.set(i,-1);
    }
    int root(int x){
        if(dat.get(x)<0)return x;
        else return root(dat.get(x));
    }
    bool unite(int x,int y){
        x=root(x),y=root(y);
        if(x==y)return false;
        int p=dat.get(x),q=dat.get(y);
        if(p>q)swap(x,y);
        dat.set(x,p+q);
        dat.set(y,x);
        return true;
    }
    bool same(int x,int y){return root(x)==root(y);}
    int size(int a){return -dat.get(root(a));}
};

/**
 * @brief Persistent Union Find
 */