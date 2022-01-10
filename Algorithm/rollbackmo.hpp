#pragma once

struct RollbackMo{
    using P=array<int,2>;
    int n,w;
    vector<P> qs;
    RollbackMo(int _n):n(_n),w(sqrt(n)){}
    void add(int lb,int rb){qs.push_back({lb,rb});}
    void init();
    void insert(int i);
    void snapshot();
    void rollback();
    void out(int i);
    void run(){
        const int q=qs.size();
        vector<int> ord(q);
        iota(ALL(ord),0);
        sort(ALL(ord),[&](int i,int j){
            return P{qs[i][0]/w,qs[i][1]}<P{qs[j][0],qs[j][1]};
        });
        init();
        snapshot();
        int last=-1,r=0;
        for(auto& i:ord)if(qs[i][1]-qs[i][0]<w){
            rep(j,qs[i][0],qs[i][1])insert(j);
            out(i);
            rollback();
        }
        for(auto& i:ord)if(qs[i][1]-qs[i][0]>=w){
            int b=qs[i][0]/w;
            if(last!=b){
                init();
                last=b;
                r=(b+1)*w;
            }
            while(r<qs[i][1])insert(r++);
            snapshot();
            for(int j=(b+1)*w-1;j>=qs[i][0];j--)insert(j);
            out(i);
            rollback();
        }
    }
};

/**
 * @brief Rollback Mo
 */