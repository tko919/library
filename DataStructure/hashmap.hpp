#pragma once

template<typename Key,typename Val,int N=1<<20>struct HashMap{
    using u64 = uint64_t;
private:
    array<Key,N> keys;
    array<Val,N> vals;
    bitset<N> used;
    const int shift;
    static constexpr u64 RNG() {
        mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
        return gen();
    }
public:
    HashMap():shift(64-__lg(N)){
        static_assert((N & (N - 1)) == 0 && N > 0);
    }
    Val& operator[](const Key& x){
        static u64 r=RNG();
        int hash=(u64(x)*r)>>shift;
        for(;;){
            if(!used[hash]){
                keys[hash]=x;
                used[hash]=1;
                return vals[hash]=Val();
            }
            if(keys[hash]==x)return vals[hash];
            hash++;
            hash=(hash+1)&(N-1);
        }
    }
};

/**
 * @brief Hash Map
 */