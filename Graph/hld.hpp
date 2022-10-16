#pragma once

struct HLD{
    using P=pair<int,int>;
    vector<vector<int>> g; vector<int> sz,in,out,rev,hs,par,dist;
    void dfs(int v,int p){
        par[v]=p; sz[v]=1; dist[v]=dist[p]+1;
        if(!g[v].empty() and g[v][0]==p)swap(g[v][0],g[v].back());
        for(auto& to:g[v])if(to!=p){
           dfs(to,v); sz[v]+=sz[to];
           if(sz[g[v][0]]<sz[to])swap(g[v][0],to);
        }
    }
    void dfs2(int v,int p,int& k){
        in[v]=k++; rev[in[v]]=v;
        for(auto& to:g[v])if(to!=p){
            hs[to]=(g[v][0]==to?hs[v]:to);
            dfs2(to,v,k);
        }
        out[v]=k;
    }
    HLD(int _n):g(_n),sz(_n),in(_n),out(_n),rev(_n),hs(_n),par(_n),dist(_n){}
    void add_edge(int u,int v){
        g[u].emplace_back(v); g[v].emplace_back(u);
    }
    void run(int rt=0){dfs(rt,-1); hs[rt]=rt; int k=0; dfs2(rt,-1,k);}
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
    int jump(int u,int v,int k){
        if(k<0)return -1;
        int g=lca(u,v);
        int d0=dist[u]+dist[v]-dist[g]*2;
        if(d0<k)return -1;
        int st=u;
        if(dist[u]-dist[g]<k)st=v,k=d0-k;
        for(;;){
            int to=hs[st];
            if(in[st]-k>=in[to])return rev[in[st]-k];
            k-=in[st]-in[to]+1; st=par[to];
        }
    }
};

/**
 * @brief Heavy Light Decomposition
 */