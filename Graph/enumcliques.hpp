#pragma once

struct EnumCliques{
    const int n;
    int m;
    vector<vector<int>> g;
    vector<int> deg;
    EnumCliques(int _n):n(_n),m(0),g(n,vector<int>(n)),deg(n){}
    void add_edge(int u,int v){
        g[u][v]=g[v][u]=1;
        deg[u]++; deg[v]++;
        m++;
    }
    vector<vector<int>> run(){
        int L=sqrt(m);
        vector<vector<int>> res;
        auto process=[&](vector<int>& vs,bool fix=true)->void{
            vector<int> nbhd(vs.size());
            rep(i,0,vs.size())rep(j,0,vs.size())if(i!=j){
                nbhd[i]|=(!g[vs[i]][vs[j]])<<j;
            }
            rep(mask,1,1<<vs.size()){
                if(fix and (mask&1)==0)continue;;
                bool check=1;
                rep(i,0,vs.size())if(mask>>i&1){
                    if(mask&nbhd[i]){
                        check=0;
                        break;
                    }
                }
                if(check){
                    vector<int> add;
                    rep(i,0,vs.size())if(mask>>i&1){
                        add.push_back(vs[i]);
                    }
                    res.push_back(add);
                }
            }
        };

        vector<int> used(n);
        queue<int> que;
        rep(v,0,n)if(deg[v]<L){
            que.push(v);
            used[v]=1;
        }
        while(!que.empty()){
            int v=que.front();
            que.pop();
            vector<int> vs;
            vs.push_back(v);
            rep(u,0,n)if(g[v][u])vs.push_back(u);
            process(vs);
            rep(u,0,n)if(g[v][u]){
                g[v][u]=g[u][v]=0;
                deg[u]--;
                if(!used[u] and deg[u]<L){
                    que.push(u);
                    used[u]=1;
                }
            }
        }
        vector<int> vs;
        rep(v,0,n)if(!used[v])vs.push_back(v);
        process(vs,false);
        return res;
    }
};

/**
 * @brief Enumerate Cliques
 */