#pragma once

struct SCC{
    int n,m,cur;
    vector<vector<int>> g;
    vector<int> low,ord,id;
    SCC(int _n=0):n(_n),m(0),cur(0),g(_n),low(_n),ord(_n,-1),id(_n){}
    void resize(int _n){
        n=_n;
        g.resize(n);
        low.resize(n);
        ord.resize(n,-1);
        id.resize(n);
    }
    void add_edge(int u,int v){g[u].emplace_back(v);}
    void dfs(int v,vector<int>& used){
        ord[v]=low[v]=cur++;
        used.emplace_back(v);
        for(auto& nxt:g[v]){
            if(ord[nxt]==-1){
                dfs(nxt,used); chmin(low[v],low[nxt]);
            }
            else{
                chmin(low[v],ord[nxt]);
            }
        }
        if(ord[v]==low[v]){
            while(1){
                int add=used.back(); used.pop_back();
                ord[add]=n; id[add]=m;
                if(v==add)break;
            }
            m++;
        }
    }
    void run(){
        vector<int> used;
        rep(v,0,n)if(ord[v]==-1)dfs(v,used);
        for(auto& x:id)x=m-1-x;
    }
};

/**
 * @brief Strongly Connected Components
 */