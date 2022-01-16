#pragma once

class BiMatching{
    int n,m;
    vector<vector<int>> g;
    bitset<501010> used;
    bool dfs(int v){
        if(used[v])return false;
        used[v]=1;
        for(auto& to:g[v])if(pre[to]==-1 or dfs(pre[to])){
            nxt[v]=to;
            pre[to]=v;
            return true;
        }
        return false;
    }
public:
    vector<int> nxt,pre;
    BiMatching(int _n,int _m):n(_n),m(_m),g(_n),nxt(_n,-1),pre(_m,-1){}
    void add_edge(int u,int v){g[u].push_back(v);}
    int run(){
        int ret=0;
        for(;;){
            bool upd=0;
            rep(v,0,n)if(nxt[v]==-1 and dfs(v)){
                upd=1;
                ret++;
            }
            if(upd)used=0;
            else break;
        }
        return ret;
    }
};

/**
 * @brief Bipartite Matching
 */