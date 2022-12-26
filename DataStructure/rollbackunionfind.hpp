#pragma once

struct RollbackUnionFind{
    vector<int> par;
    stack<pair<int,int>> history;
    int snap;
    RollbackUnionFind(){}
    RollbackUnionFind(int _n):par(_n,-1),snap(0){}
    int root(int x){return par[x]<0?x:par[x]=root(par[x]);}
    bool same(int x,int y){return root(x)==root(y);}
    int size(int x){return -par[root(x)];}
    bool unite(int x,int y){
        x=root(x),y=root(y);
        history.push({x,par[x]});
        history.push({y,par[y]});
        if(x==y)return false;
        if(size(x)>size(y))swap(x,y);
        par[y]+=par[x]; par[x]=y;
        return true;
    }
    void undo(){
        par[history.top().first]=history.top().second;
        history.pop();
        par[history.top().first]=history.top().second;
        history.pop();
    }
    void snapshot(){snap=int(history.size()>>1);}
    int get(){return int(history.size()>>1);}
    void rollback(int state=-1){
        if(state==-1)state=snap;
        state<<=1;
        while(state<history.size())undo();
    }
};

/**
 * @brief Rollback Union Find
 */