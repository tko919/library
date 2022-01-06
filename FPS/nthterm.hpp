#pragma once
#include "FPS/fps.hpp"

template<typename T>T nth(Poly<T> p,Poly<T> q,ll n){
    while(n){
        Poly<Fp> base(q),np,nq;
        for(int i=1;i<(int)q.size();i+=2)base[i]=-base[i];
        p*=base; q*=base;
        for(int i=n&1;i<(int)p.size();i+=2)np.emplace_back(p[i]);
        for(int i=0;i<(int)q.size();i+=2)nq.emplace_back(q[i]);
        swap(p,np); swap(q,nq);
        n>>=1;
    }
    return p[0]/q[0];
}

/**
 * @brief Bostan-Mori Algorithm
 */