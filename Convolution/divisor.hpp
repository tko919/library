#pragma once
#include "Math/sieve.hpp"

namespace DivisorTransform{
    int n;
    vector<int> ps;
    template<typename T>void zeta(vector<T>& a){
        int N=a.size()-1;
        if(n<N){
            ps=sieve(N);
            n=N;
        }
        for(auto& p:ps){
            for(int k=1;k*p<=N;k++)a[k*p]+=a[k];
        }
    }
    template<typename T>void mobius(vector<T>& a){
        int N=a.size()-1;
        if(n<N){
            ps=sieve(N);
            n=N;
        }
        for(auto& p:ps){
            for(int k=N/p;k;k--)a[k*p]-=a[k];
        }
    }
};

namespace MultipleTransform{
    int n;
    vector<int> ps;
    template<typename T>void zeta(vector<T>& a){
        int N=a.size()-1;
        if(n<N){
            ps=sieve(N);
            n=N;
        }
        for(auto& p:ps){
            for(int k=N/p;k;k--)a[k]+=a[k*p];
        }
    }
    template<typename T>void mobius(vector<T>& a){
        int N=a.size()-1;
        if(n<N){
            ps=sieve(N);
            n=N;
        }
        for(auto& p:ps){
            for(int k=1;k*p<=N;k++)a[k]-=a[k*p];
        }
    }
};

/**
 * @brief Divisor Multiple Transform
 */