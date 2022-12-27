#pragma once

struct FastDiv{
    using u64=uint64_t;
    using u128=__uint128_t;
    constexpr FastDiv():m(),s(),x(){}
    constexpr FastDiv(int _m)
        :m(_m),s(__lg(m-1)),x(((u128(1)<<(s+64))+m-1)/m){}
    constexpr int get(){return m;}
    constexpr friend u64 operator/(u64 n,const FastDiv& d){
        return (u128(n)*d.x>>d.s)>>64;
    }
    constexpr friend int operator%(u64 n,const FastDiv& d){
        return n-n/d*d.m;
    }
    constexpr pair<u64,int> divmod(u64 n)const{
        u64 q=n/(*this);
        return {q,n-q*m};
    }
    int m,s; u64 x;
};

/**
 * Fast Division
*/