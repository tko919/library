#pragma once
#include "DataStructure/linkedlist.hpp"

vector<int> BipolarOrientation(int n,vector<vector<int>>& g,int s,int t){
    int cur=1;
    vector<int> par(n),ord(n,-1),low(n),path;
    auto dfs=[&](auto& dfs,int v)->void{
        ord[v]=cur++;
        low[v]=v;
        path.push_back(v);
        for(auto& to:g[v]){
            if(ord[to]==-1){
                dfs(dfs,to);
                par[to]=v;
                if(ord[low[to]]<ord[low[v]]){
                    low[v]=low[to];
                }
            }
            else if(ord[to]<ord[low[v]])low[v]=to;
        }
    };
    ord[s]=0;
    dfs(dfs,t);
    if(SZ(path)!=n-1)return {};
    path.erase(path.begin());
    
    const bool plus=1,minus=0;
    vector<int> sign(n);
    LinkedList<int> LL;
    vector<LinkedList<int>::Node*> nodes(n);
    nodes[s]=LL.insert_front(nullptr,s);
    nodes[t]=LL.insert_back(nodes[s],t);
    
    for(auto& v:path){
        if(sign[low[v]]==minus){
            nodes[v]=LL.insert_front(nodes[par[v]],v);
            sign[par[v]]=plus;
        }
        else{
            nodes[v]=LL.insert_back(nodes[par[v]],v);
            sign[par[v]]=minus;
        }
    }
    auto perm=LL.dump(); // index:vertices
    vector<int> ret(n);
    rep(i,0,n)ret[perm[i]]=i;

    // check
    vector<int> FROM(n),TO(n);
    FROM[s]=TO[t]=1;
    for(auto& v:perm){
        if(!FROM[v])return {};
        for(auto& to:g[v])if(ret[v]<ret[to]){
            FROM[to]=1;
        }
    }
    reverse(ALL(perm));
    for(auto& v:perm){
        if(!TO[v])return {};
        for(auto& to:g[v])if(ret[v]>ret[to]){
            TO[to]=1;
        }
    }

    return ret;
}

/**
 * @brief Bipolar Orientation
 */