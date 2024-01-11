#pragma once

namespace Random{
    mt19937_64 randgen(chrono::steady_clock::now().time_since_epoch().count());
    using u64=unsigned long long;
    u64 get(){
        return randgen();
    }
    template<typename T>T get(T L){
        return get()%(L+1);
    }
    template<typename T>T get(T L,T R){
        return get(R-L)+L;
    }
    double uniform(){
        return double(get(1000000000))/1000000000;
    }
    string str(int n){
        string ret;
        rep(i,0,n)ret+=get('a','z');
        return ret;
    }
    template<typename Iter>void shuffle(Iter first,Iter last){
        if(first==last)return;
        int len=1;
        for(auto it=first+1;it!=last;it++){
            len++;
            int j=get(0,len-1);
            if(j!=len-1)iter_swap(it,first+j);
        }
    }
    template<typename T>vector<T> select(int n,T L,T R){
        set<T> ret;
        while(ret.size()<n)ret.insert(get(L,R));
        return {ALL(ret)};
    }
};

/**
 * @brief Random
 */