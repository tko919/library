#pragma once
#include "Math/sieve.hpp"

namespace DivisorTransform{
    template<typename T>void zeta(vector<T>& a){
        int N=a.size()-1;
        auto ps=sieve(N);
        for(auto& p:ps){
            for(int k=1;k*p<=N;k++)a[k*p]+=a[k];
        }
    }
    template<typename T>void mobius(vector<T>& a){
        int N=a.size()-1;
        auto ps=sieve(N);
        for(auto& p:ps){
            for(int k=N/p;k;k--)a[k*p]-=a[k];
        }
    }
};

namespace MultipleTransform{
    template<typename T>void zeta(vector<T>& a){
        int N=a.size()-1;
        auto ps=sieve(N);
        for(auto& p:ps){
            for(int k=N/p;k;k--)a[k]+=a[k*p];
        }
    }
    template<typename T>void mobius(vector<T>& a){
        int N=a.size()-1;
        auto ps=sieve(N);
        for(auto& p:ps){
            for(int k=1;k*p<=N;k++)a[k]-=a[k*p];
        }
    }
};

/**
 * @brief Divisor Multiple Transform
 */