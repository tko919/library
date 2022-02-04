#pragma once

struct Mo{
    using P=pair<int,int>;
    const int n,w; vector<P> qs;
    Mo(int _n):n(_n),w(sqrt(n)){}
    void add(int lb,int rb){qs.push_back({lb,rb});}
    void addl(int i);
    void addr(int i);
    void dell(int i);
    void delr(int i);
    void out(int i);
    void run(){
        const int q=qs.size();
        vector<int> ord(q); iota(ALL(ord),0);
        sort(ALL(ord),[&](int i,int j){
            if(qs[i].first/w!=qs[j].first/w)return qs[i].first<qs[j].first;
            else return qs[i].second<qs[j].second;
        });
        int lb=0,rb=0;
        for(int i:ord){
            auto [li,ri]=qs[i];
            while(lb>li)addl(--lb);
            while(rb<ri)addr(rb++);
            while(lb<li)dell(lb++);
            while(rb>ri)delr(--rb);
            out(i);
        }
    }
};

/**
 * @brief Mo's Algorithm
 * @docs docs/mo.md
 */