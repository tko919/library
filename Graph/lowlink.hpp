#pragma once

struct LowLink{
    const int n; vector<vector<int>> g;
    vector<int> used,ord,low,id;
    LowLink(const int& _n):n(_n),g(n),
        used(n,0),ord(n,0),low(n,0),id(n,-1){
    }
    void add_edge(int u,int v){
        g[u].emplace_back(v); g[v].emplace_back(u);
     }
    void dfs(int v,int p,int& k){
        used[v]=1; low[v]=ord[v]=k++;
        int cnt=0,sub=0;
        for(auto& to:g[v]){
            if(to==p and (++sub)<=1)continue;
            if(!used[to]){
                cnt++; dfs(to,v,k);
                chmin(low[v],low[to]);
            }
            else chmin(low[v],ord[to]);
        }
    }
    void dfs2(int v,int p,int& k){
        if(p!=-1 and ord[p]>=low[v])id[v]=id[p];
        else id[v]=k++;
        for(auto& to:g[v])if(id[to]==-1)dfs2(to,v,k);
    }
    int run(){
        int k=0; rep(i,0,n)if(!used[i])dfs(i,-1,k);
        k=0; rep(i,0,n)if(id[i]==-1)dfs2(i,-1,k);
        return k;
    }
};

/**
 * @brief Lowlink
 */