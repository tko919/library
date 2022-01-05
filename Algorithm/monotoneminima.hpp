#pragma once

template<typename F>vector<int> MonotoneMinima(int R,int C,F cmp){
    // cmp(i,j,k) := compare A[i,j] and A[i,k] (A[i,j] -> false, A[i,k] -> true)
    vector<int> ret(R);
    auto rec=[&](auto& f,vector<int> target)->void{
        int m=target.size();
        if(m==0)return;
        vector<int> even;
        for(int i=1;i<m;i+=2)even.push_back(target[i]);
        f(f,even);
        int cur=0;
        for(int i=0;i<m;i+=2){
            ret[target[i]]=cur;
            int end=C-1;
            if(i!=m-1)end=ret[even[i/2]];
            while(cur<end){
                cur++;
                if(cmp(target[i],ret[target[i]],cur))ret[target[i]]=cur;
            }
        }
    };
    vector<int> tmp(R);
    iota(ALL(tmp),0);
    rec(rec,tmp);
    return ret;
}

/**
 * @brief Monotone Minima
 */