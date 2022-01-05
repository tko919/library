#pragma once

struct MaxFlow{
    struct Edge { ll to,cap,rev; };
    int V; vector<vector<Edge>> G; vector<int> itr,level;
public:
    MaxFlow(int V):V(V){G.assign(V,vector<Edge>()); }
    void add_edge(int from,int to,ll cap){
        G[from].push_back({to,cap,(int)G[to].size()});
        G[to].push_back({from,0,(int)G[from].size()-1});
    }
    void bfs(int s){
        level.assign(V,-1); queue<int> q;
        level[s]=0; q.push(s);
        while(!q.empty()){
            int v=q.front(); q.pop();
            for(auto& e:G[v]){
                if(e.cap>0&&level[e.to]<0) {
                   level[e.to]=level[v]+1;
                   q.push(e.to);
                }
            }
        }
    }
    ll dfs(int v,int t,ll f){
        if(v==t)return f;
        for(int& i=itr[v];i<(int)G[v].size();i++){
            Edge& e=G[v][i];
            if(e.cap>0&&level[v]<level[e.to]){
                ll d=dfs(e.to,t,min(f,e.cap));
                if(d>0){
                    e.cap-=d,G[e.to][e.rev].cap+=d;
                    return d;
                }
            }
        } return 0;
    }
    ll run(int s,int t){
        ll ret=0,f;
        while(bfs(s),level[t]>=0){
            itr.assign(V,0);
            while((f=dfs(s,t,INF))>0)ret+=f;
        } return ret;
    }
};

/**
 * @brief Maximum Flow
 */