#pragma once

class CentroidDecomposition{
    void get(int v,int p){
        sz[v]=1;
        for(auto& to:g[v])if(to!=p and !used[to]){
            get(to,v);
            sz[v]+=sz[to];
        }
    }
    int dfs(int v,int p,int rt){
        for(auto& to:g[v])if(to!=p and !used[to]){
            if(sz[to]>(sz[rt]>>1))return dfs(to,v,rt);
        }
        return v;
    }
public:
    int n;
    vector<vector<int>> g;
    vector<int> sz,used;
    CentroidDecomposition(int n_):n(n_),g(n),sz(n),used(n){}
    void add_edge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int find(int rt){
        get(rt,-1);
        int res=dfs(rt,-1,rt);
        used[res]=1;
        return res;
    }
};

/**
 * @brief Centroid Decomposition
 */