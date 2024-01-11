#pragma once

template<int SZ,int start>struct Trie{
    struct Node{
        array<int,SZ> nxt;
        vector<int> ids;
        Node(){fill(ALL(nxt),-1);}
    };
    vector<Node> vs;
    
    Trie(){vs.push_back(Node());}
    Node operator[](const int& i)const{return vs[i];}
    int move(int pos,char c){
        return pos<0?-1:vs[pos].nxt[int(c-start)];
    }
    void add(const string& s,int id){
        int pos=0;
        for(auto& c:s){
            int to=move(pos,c);
            if(to==-1){
                to=vs.size();
                vs.push_back(Node());
                vs[pos].nxt[int(c-start)]=to;
            }
            pos=to;
        }
        vs[pos].ids.push_back(id);
    }
    int find(string& s){
        int pos=0;
        for(auto& c:s){
            pos=move(pos,c);
            if(pos==-1)return -1;
        }
        return pos;
    }
};

/**
 * @brief Trie
*/