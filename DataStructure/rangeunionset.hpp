#pragma once

template<typename T,T mx>struct RangeUnionSet{
    map<T,T> data;
    RangeUnionSet(){}
    void insert(T lb,T rb){
        auto L=data.upper_bound(lb),R=data.upper_bound(rb);
        if(L!=data.begin() and lb<=prev(L)->second)L--;
        if(L!=R){
            chmin(lb,L->first);
            chmax(rb,prev(R)->second);
            data.erase(L,R);
        }
        data[lb]=rb;
    }
    void erase(T lb,T rb){
        auto L=data.upper_bound(lb),R=data.upper_bound(rb);
        if(L!=data.begin() and lb<=prev(L)->second)L--;
        if(L==R)return;
        T nl=min(lb,L->first),nr=max(rb,prev(R)->second);
        data.erase(L,R);
        if(nl<lb)data[nl]=lb;
        if(rb<nr)data[rb]=nr;
    }
    T mex(T x)const{
        auto it=data.lower_bound(x);
        if(it!=data.begin() and prev(it)->second>x)it--;
        if(it==data.end())return mx;
        return max(x,it->first);
    }
};

/**
 * @brief Range Union Set
 * @docs docs/rangeunionset.md
 */