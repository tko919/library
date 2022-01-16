#pragma once

struct Random{
    random_device rnd;
    unsigned x=123456789,y=362436069,z=521288629,w=rnd();
    Random(){}
    unsigned get(){
        unsigned t=x^(x<<11);
        x=y,y=z,z=w;
        return w=(w^(w<<19))^(t^(t>>8));
    }
    unsigned get(unsigned L){
        return get()%(L+1);
    }
    template<typename T>T get(T L,T R){
        return get(R-L)+L;
    }
    double uniform(){
        return double(get())/UINT_MAX;
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