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
        const int w=max<int>(1,1.0*n/max<double>(1.0,sqrt(q*2.0/3.0)));
        vector<int> ord(q);
        iota(ALL(ord),0);
        sort(ALL(ord),[&](int i,int j){
            int a=L[i]/w,b=L[j]/w;
            if(a!=b)return a<b;
            if(a&1)return R[i]<R[j]
            else return R[i]>R[j];
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