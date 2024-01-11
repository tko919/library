#pragma once

struct SuffixAutomaton{
    struct Node{
        map<char,int> nxt;
        int link,len;
        Node(int L=0):link(-1),len(L){}
    };
    vector<Node> Nodes;
    int last;
    SuffixAutomaton(){
        Nodes.push_back(Node());
        last=0;
    }
    void push(char c){
        int nlast=Nodes.size();
        Nodes.push_back(Node(Nodes[last].len+1));
        int cur=last;
        while(cur!=-1 and !Nodes[cur].nxt.count(c)){
            Nodes[cur].nxt[c]=nlast;
            cur=Nodes[cur].link;
        }
        if(cur==-1)Nodes[nlast].link=0;
        else{
            int to=Nodes[cur].nxt[c];
            if(Nodes[to].len==Nodes[cur].len+1)Nodes[nlast].link=to;
            else{
                int extra=Nodes.size();
                Nodes.push_back(Nodes[to]);
                Nodes.back().len=Nodes[cur].len+1;
                Nodes[to].link=Nodes[nlast].link=extra;
                while(cur!=-1 and Nodes[cur].nxt[c]==to){
                    Nodes[cur].nxt[c]=extra;
                    cur=Nodes[cur].link;
                }
            }
        }
        last=nlast;
    }
};

/*
 * @brief Suffix Automaton
*/