#pragma once
#include "FPS/sumofRationals.hpp"

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
    rep(i,0,m)p[i]*=Fact<T>(i,1);
    return p;
}

/**
 * @brief $f(\exp(x))$
*/