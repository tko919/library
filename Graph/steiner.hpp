#pragma once

struct SteinerTree{
    using P=pair<ll,ll>;
    int n;
    vector<vector<P>> g;
    SteinerTree(int _n):n(_n),g(n){}
    void add_edge(int u,int v,ll c){
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
    ll run(vector<int>& term){
        int k=term.size();
        if(k<=1)return 0;
        vector dp(1<<k,vector<ll>(n,INF));
        rep(i,0,k)dp[1<<i][term[i]]=0;
        using P=pair<ll,int>;
        rep(mask,1,1<<k){
            for(ll sub=mask;;sub=(sub-1)&mask){
                rep(v,0,n)chmin(dp[mask][v],dp[sub][v]+dp[mask^sub][v]);
                if(sub==0)break;
            }
            priority_queue<P,vector<P>,greater<P>> pq;
            rep(v,0,n)pq.push({dp[mask][v],v});
            while(!pq.empty()){
                auto [d,v]=pq.top();
                pq.pop();
                if(dp[mask][v]<d)continue;
                for(auto& [nxt,c]:g[v])if(chmin(dp[mask][nxt],d+c)){
                    pq.push({dp[mask][nxt],nxt});
                }
            }
        }
        ll ret=INF;
        rep(j,0,n)chmin(ret,dp[(1<<k)-1][j]);
        return ret;
    }
};

/**
 * @brief Steiner Tree
 */