#pragma once

struct HLD{
    using P=pair<int,int>;
    vector<vector<int>> g; vector<int> sz,in,out,hs,par;
    void dfs(int v,int p){
        par[v]=p; sz[v]=1;
        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());
        for(auto& to:g[v])if(to!=p){
           dfs(to,v); sz[v]+=sz[to];
           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);
        }
    }
    void dfs2(int v,int p,int& k){
        in[v]=k++;
        for(auto& to:g[v])if(to!=p){
            hs[to]=(g[v][0]==to?hs[v]:to);
            dfs2(to,v,k);
        }
        out[v]=k;
    }
    HLD(int _n):g(_n),sz(_n),in(_n),out(_n),hs(_n),par(_n){}
    void add_edge(int u,int v){
        g[u].emplace_back(v); g[v].emplace_back(u);
    }
    void run(int rt=0){dfs(rt,-1); int k=0; dfs2(rt,-1,k);}
    int lca(int u,int v){
        for(;;v=par[hs[v]]){
            if(in[u]>in[v])swap(u,v);
            if(hs[u]==hs[v])return u;
        }
    }
    vector<P> get(int u,int p,bool es=0){
        assert(in[p]<=in[u] and out[u]<=out[p]);
        vector<P> res;
        while(hs[u]!=hs[p]){
            res.push_back({in[hs[u]],in[u]+1});
            u=par[hs[u]];
        }
        res.push_back({in[p]+es,in[u]+1});
        return res;
    }
};

/**
 * @brief Heavy Light Decomposition
 */