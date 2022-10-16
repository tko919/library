#pragma once

#include "Graph/lca.hpp"
struct AuxiliaryTree{
    int n,pos;
    LCA lca;
    vector<int> in,dep;
    vector<vector<int>> _g,g;
    AuxiliaryTree(int _n):n(_n),pos(0),lca(n),in(n),dep(n),_g(n),g(n){}
    void add_edge(int u,int v){
        lca.add_edge(u,v);
        _g[u].push_back(v);
        _g[v].push_back(u);
    }
    void run(int root=0){
        lca.run(root);
        dfs(root,-1);
    }
    void query(vector<int>& vs){
        sort(ALL(vs),[&](int u,int v){return in[u]<in[v];});
        vs.erase(unique(ALL(vs)),vs.end());
        int m=vs.size();
        stack<int> st;
        st.push(vs[0]);
        rep(i,0,m-1){
            int w=lca.lca(vs[i],vs[i+1]);
            if(w!=vs[i]){
                int cur=st.top();
                st.pop();
                while(!st.empty() and dep[w]<dep[st.top()]){
                    add(st.top(),cur);
                    cur=st.top();
                    st.pop();
                }
                if(st.empty() or st.top()!=w){
                    st.push(w);
                    vs.push_back(w);
                }
                add(w,cur);
            }
            st.push(vs[i+1]);
        }
        while(st.size()>1){
            int c=st.top();
            st.pop();
            add(st.top(),c);
        }
    }
    void clear(vector<int>& vs){
        for(auto& w:vs)g[w].clear();
    }
private:
    void dfs(int v,int p){
        in[v]=pos++;
        for(auto& to:_g[v])if(to!=p){
            dep[to]=dep[v]+1;
            dfs(to,v);
        }
    }
    void add(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
};

/**
 * @brief Auxiliary Tree(Virtual Tree)
 */