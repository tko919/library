#pragma once

template<typename Key,typename Val,int N=1<<20,Val Default=Val()>struct HashMap{
    Key* keys;
    Val* vals;
    bitset<N> used;
    const int shift;
    const uint64_t r=11995408973635179863ULL;
    HashMap():keys(new Key[N]),vals(new Val[N]),shift(64-__lg(N)){}
    Val& operator[](const Key& x){
        int hash=(uint64_t(x)*r)>>shift;
        for(;;){
            if(!used[hash]){
                keys[hash]=x;
                used[hash]=1;
                return vals[hash]=Default;
            }
            if(keys[hash]==x)return vals[hash];
            hash++;
            if(hash==N)hash=0;
        }
    }
};

/**
 * @brief Hash Map
 */