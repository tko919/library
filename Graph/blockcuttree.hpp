#pragma once
#include "Graph/bc.hpp"

struct BlockCutTree{
    using P=pair<int,int>;
    int n;
    BiconnectedComponents bc;
    vector<P> es;
    
    vector<int> rev;
    vector<vector<int>> tree;
    BlockCutTree(int _n):n(_n),bc(_n),rev(_n,-1){}
    void add_edge(int u,int v){
        es.push_back({u,v});
        bc.add_edge(u,v);
    }
    void run(){
        bc.run();
        int B=bc.bc.size();
        int ptr=B;
        for(auto& v:bc.base.arti)rev[v]=ptr++;
        vector<int> last(ptr,-1);
        tree.resize(n+ptr);
        rep(i,0,B){
            for(auto& e:bc.bc[i]){
                for(auto& v:{es[e].first,es[e].second}){
                    if(rev[v]>=B){
                        if(exchange(last[rev[v]],i)!=i){
                            tree[n+rev[v]].push_back(n+i);
                            tree[n+i].push_back(n+rev[v]);
                        }
                    }
                    else rev[v]=i;
                }
            }
        }
        rep(i,0,n){
            tree[i].push_back(n+rev[i]);
            tree[n+rev[i]].push_back(i);
        }
    }
};

/**
 * @brief Block Cut Tree
 */