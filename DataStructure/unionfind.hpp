#pragma once

struct UnionFind{
    vector<int> par; int n;
    UnionFind(){}
    UnionFind(int _n):par(_n,-1),n(_n){}
    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}
    bool same(int x,int y){return root(x)==root(y);}
    int size(int x){return -par[root(x)];}
    bool unite(int x,int y){
        x=root(x),y=root(y); if(x==y)return false;
        if(size(x)>size(y))swap(x,y);
        par[y]+=par[x]; par[x]=y; n--; return true;
    }
};