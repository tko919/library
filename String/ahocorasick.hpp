#pragma once
#include "String/trie.hpp"

template<int SZ,int start>struct AhoCorasick:Trie<SZ,start>{
    using super=Trie<SZ,start>;
    using super::vs;
    vector<int> fail,bfs;
    void make_failure(){
        fail.resize(vs.size());
        queue<int> que;
        que.push(0);
        while(!que.empty()){
            int v=que.front();
            que.pop();
            bfs.push_back(v);
            rep(c,0,SZ){
                if(vs[v].nxt[c]==-1)continue;
                int to=vs[v].nxt[c];
                que.push(to);
                if(v==0)continue;
                int f=fail[v];
                while(f and vs[f].nxt[c]==-1)f=fail[f];
                if(vs[f].nxt[c]!=-1)fail[to]=vs[f].nxt[c];
            }
        }
    }
    void make_next(){
        for(auto& v:bfs){
            rep(c,0,SZ)if(vs[v].nxt[c]==-1){
                vs[v].nxt[c]=vs[fail[v]].nxt[c];
                if(vs[v].nxt[c]==-1)vs[v].nxt[c]=0;
            }
        }
    }
    void merge_id(){
        for(auto& v:bfs)if(v>0){
            rep(c,0,SZ){
                int from=vs[fail[v]].nxt[c];
                int to=vs[v].nxt[c];
                if(from!=-1 and to!=-1){
                    for(auto& id:vs[from].ids)vs[to].ids.push_back(id);
                }
            }
        }
    }
};


/**
 * @brief Aho-Corasick
*/