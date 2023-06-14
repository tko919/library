#pragma once
#include "FPS/sumofRationals.hpp"
#include "Math/factorial.hpp"

template<typename T>Poly<T> CompExp(Poly<T>& f,int m){
    int n=f.size();
    vector<pair<Poly<T>,Poly<T>>> fs;
    rep(i,0,n){
        Poly<T> p({Fp(f[i])});
        Poly<T> q({Fp(1),Fp(-i)});
        fs.push_back({p,q});
    }
    auto [p,q]=SumOfRationals(fs);
    q.resize(m);
    p*=q.inv();
    p.resize(m);
    factorial<T> fact(m+1);
    rep(i,0,m)p[i]*=fact.fact(i,1);
    return p;
}

/**
 * @brief $f(\exp(x))$
*/