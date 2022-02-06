#pragma once
#include "Graph/lowlink.hpp"

struct BiconnectedComponents{
    using P=pair<int,int>;
    LowLink base;
    vector<vector<P>> g;
    vector<int> used;
    int eidx;
    vector<vector<int>> bc;
    BiconnectedComponents(){}
    BiconnectedComponents(const int& n):base(n),g(n),used(n),eidx(0){}
    void add_edge(int u,int v){
        base.add_edge(u,v);
        g[u].push_back({v,eidx});
        g[v].push_back({u,eidx++});
    }
    void run(){
        base.run();
        rep(i,0,g.size())if(!used[i])dfs(i,-1);
    }
private:
    vector<int> buf;
    void dfs(int v,int p){
        used[v]=1;
        int cnt=0;
        for(auto& [to,id]:g[v]){
            if(to==p){
                cnt++;
                if(cnt<=1)continue;
            }
            if(!used[to] or base.ord[to]<base.ord[v]){
                buf.push_back(id);
            }
            if(!used[to]){
                dfs(to,v);
                if(base.low[to]>=base.ord[v]){
                    vector<int> add;
                    for(;;){
                        add.push_back(buf.back());
                        buf.pop_back();
                        if(add.back()==id)break;
                    }
                    bc.push_back(add);
                }
            }
        }
    }
};

/**
 * @brief Biconnected Components
 */