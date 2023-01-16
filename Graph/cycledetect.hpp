#pragma once

template<bool directed>struct CycleDetect{
    using P=pair<int,int>;
    int n,m;
    vector<vector<P>> g;
    vector<P> cycle;
    CycleDetect(){}
    CycleDetect(int _n):n(_n),m(0),g(n),used(n){}
    void add_edge(int u,int v){
        g[u].push_back({v,m});
        if(!directed)g[v].push_back({u,m});
        m++;
    }
    void run(){
        rep(i,0,n)if(dfs(i,-1)==-2){
            reverse(ALL(cycle));
            break;
        }
    }
private:
    vector<int> used; // 0:not,1:seen,2:visited
    int dfs(int v,int pid){ // -1:over,-2:done
        if(used[v]==1)return v;
        if(used[v]==2)return -1;
        used[v]=1;
        for(auto& [to,id]:g[v])if(id!=pid){
            int nxt=dfs(to,id);
            if(nxt!=-1){
                if(nxt==-2)return -2;
                cycle.push_back({to,id});
                if(nxt==v)return -2;
                return nxt;
            }
        }
        used[v]=2;
        return -1;
    }
};

/**
 * @brief Cycle Detection
*/