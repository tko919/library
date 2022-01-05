#pragma once
#include "Graph/scc.hpp"

struct TwoSat{
    int n;
    vector<bool> res;
    SCC graph;
    TwoSat(int _n):n(_n),res(n),graph(n*2){}
    void add(int x){
        n+=x;
        res.resize(n);
        graph.resize(n*2);
    }
    void either(int i,bool f,int j,bool g){
        graph.add_edge(2*i+(f^1),2*j+g);
        graph.add_edge(2*j+(g^1),2*i+f);
    }
    void AtMostOne(vector<int>& a){
        int offset=n;
        add(a.size());
        rep(i,0,a.size())either(a[i],0,offset+i,1);
        rep(i,1,a.size())either(offset+i-1,0,offset+i,1);
        rep(i,1,a.size())either(a[i],0,offset+i-1,0);
    }
    bool satisfiable(){
        graph.run();
        auto id=graph.id;
        rep(i,0,n){
            if(id[i*2]==id[i*2+1])return false;
            res[i]=id[i*2]<id[i*2+1];
        }
        return true;
    }
};

/**
 * @brief 2-SAT
 */