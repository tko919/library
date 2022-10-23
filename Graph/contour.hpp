#pragma once
#include "Graph/centroid.hpp"
#include "Graph/hld.hpp"

struct ContourQuery{
    using P=pair<int,int>;
    using T=pair<int,P>;
    ContourQuery(int _n=0):n(_n),m(_n),cd(_n),
        hld(_n),tree(_n*3),depth(_n*3),
        base(_n*3),parent(_n*3,-1),SZ(_n*3),width(_n*3,1),seg(_n*3){}
    void add_edge(int u,int v){
        cd.add_edge(u,v);
        hld.add_edge(u,v);
    }
    vector<int> run(){
        hld.run();
        root=rec(0);
        depth[0]=0;
        dfs(0,-1);
        rep(v,0,m)if(v!=root){
            seg[v]=width[v];
        }
        return seg;
    }
    vector<P> point(int v){
        vector<P> ret;
        int cur=v;
        while(cur!=root){
            int D=depth[v]+depth[base[cur]]-2*depth[hld.lca(v,base[cur])];
            ret.push_back({cur,D});
            cur=parent[cur];
        }
        return ret;
    }
    vector<T> range(int v,int L,int R){
        vector<T> ret;
        if(L<=0 and 0<R)ret.push_back({v,{0,1}});
        int cur=parent[v],pre=v;
        while(pre!=root){
            int bro=-1;
            for(auto& to:tree[cur])if(to!=parent[cur] and to!=pre){
                bro=to;
                break;
            }
            if(bro!=-1){
                int D=depth[v]+depth[base[bro]]-2*depth[hld.lca(v,base[bro])];
                ret.push_back({bro,{clamp(L-D,0,seg[bro]),clamp(R-D,0,seg[bro])}});
            }
            pre=cur;
            cur=parent[cur];
        }
        return ret;
    }
private:
    int n,m,root;
    CentroidDecomposition cd;
    HLD hld;
    vector<vector<int>> tree;
    vector<int> depth,base,parent,SZ,width,seg;
    int rec(int rt){
        int cen=cd.find(rt);
        SZ[cen]=1;
        queue<P> que;
        auto cmp=[&](int u,int v){return SZ[u]>SZ[v];};
        priority_queue<int,vector<int>,decltype(cmp)> pq{cmp};
        pq.push(cen);
        depth[cen]=0;
        base[cen]=cen;
        for(auto& to:cd.g[cen])if(!cd.used[to]){
            int v=rec(to);
            que.push({to,cen});
            depth[to]=1;
            while(!que.empty()){
                auto [cur,par]=que.front();
                que.pop();
                width[v]=depth[cur]+1;
                for(auto& nxt:cd.g[cur])if(nxt!=par and !cd.used[nxt]){
                    depth[nxt]=depth[cur]+1;
                    que.push({nxt,cur});
                }
            }
            pq.push(v);
            base[v]=cen;
        }
        cd.used[cen]=0;
        if(pq.size()>1){
            for(;;){
                int v1=pq.top();
                pq.pop();
                int v2=pq.top();
                pq.pop();
                int extra=m++;
                tree[extra].push_back(v1);
                tree[extra].push_back(v2);
                tree[v1].push_back(extra);
                tree[v2].push_back(extra);
                SZ[extra]=SZ[v1]+SZ[v2];
                parent[v1]=parent[v2]=extra;
                if(pq.empty()){
                    return extra;
                }
                pq.push(extra);
                base[extra]=cen;
                width[extra]=max(width[v1],width[v2]);
            }
        }
        else{
            int extra=m++;
            tree[extra].push_back(cen);
            tree[cen].push_back(extra);
            SZ[extra]=1;
            parent[cen]=extra;
            return extra;
        }
    }
    void dfs(int v,int p){
        for(auto& to:cd.g[v])if(to!=p){
            depth[to]=depth[v]+1;
            dfs(to,v);
        }
    }
};

/**
 * @brief Contour Sum Query
 */