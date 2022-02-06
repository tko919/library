#pragma once

struct Mo{
    const int n;
    vector<int> L,R;
    Mo(int _n):n(_n){}
    void add(int lb,int rb){
        L.push_back(lb);
        R.push_back(rb);
    }
    template <typename AL, typename AR, typename DL, typename DR, typename OUT>
    void run(const AL& addl,const AR& addr,const DL& dell,const DR& delr,const OUT& out){
        const int q=L.size();
        const int w=max(1,int(n/sqrt(q+1)));
        vector<int> ord(q);
        iota(ALL(ord),0);
        sort(ALL(ord),[&](int i,int j){
            int a=L[i]/w,b=L[j]/w;
            if(a!=b)return a<b;
            else if(R[i]!=R[j])return (a&1)?R[i]>R[j]:R[i]<R[j];
            else return L[i]<L[j];
        });
        int lb=0,rb=0;
        for(auto& i:ord){
            while(lb>L[i])addl(--lb);
            while(rb<R[i])addr(rb++);
            while(lb<L[i])dell(lb++);
            while(rb>R[i])delr(--rb);
            out(i);
        }
    }
};

/**
 * @brief Mo's Algorithm
 * @docs docs/mo.md
 */