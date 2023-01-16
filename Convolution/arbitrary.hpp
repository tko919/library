#pragma once
#include "Math/modint.hpp"
#include "Convolution/ntt.hpp"

using M1=fp<1045430273>; using M2=fp<1051721729>; using M3=fp<1053818881>;
NTT<fp<1045430273>,3> N1; NTT<fp<1051721729>,6> N2; NTT<fp<1053818881>,7> N3;
const M2 r_12=M2(M1::get_mod()).inv();
const M3 r_13=M3(M1::get_mod()).inv();
const M3 r_23=M3(M2::get_mod()).inv();
const M3 r_1323=r_13*r_23;
template<typename T>vector<T> ArbitraryMult(const vector<T>& a,const vector<T>& b,bool same=0){
    if(a.empty() or b.empty())return vector<T>();
    int n=a.size()+b.size()-1; vector<T> res(n);
    if(min(a.size(),b.size())<=60){
        rep(i,0,a.size())rep(j,0,b.size())res[i+j]+=a[i]*b[j];
        return res;
    }
    vector<int> vals[3];
    vector<int> aa(a.size()),bb(b.size());
    rep(i,0,a.size())aa[i]=a[i].v; rep(i,0,b.size())bb[i]=b[i].v;
    vector<M1> a1(ALL(aa)),b1(ALL(bb)),c1=N1.mult(a1,b1,same);
    vector<M2> a2(ALL(aa)),b2(ALL(bb)),c2=N2.mult(a2,b2,same);
    vector<M3> a3(ALL(aa)),b3(ALL(bb)),c3=N3.mult(a3,b3,same);
    for(M1 x:c1)vals[0].push_back(x.v);
    for(M2 x:c2)vals[1].push_back(x.v);
    for(M3 x:c3)vals[2].push_back(x.v);
    T w1(M1::get_mod()),w2=w1*T(M2::get_mod());
    rep(i,0,n){
        ll p=vals[0][i];
        ll q=(vals[1][i]+M2::get_mod()-p)*r_12.v%M2::get_mod();
        ll r=((vals[2][i]+M3::get_mod()-p)*r_1323.v+
            (M3::get_mod()-q)*r_23.v)%M3::get_mod();
        res[i]=(p+q*w1.v+r*w2.v);
    } return res;
}

/**
 * @brief Arbitrary Mod Convolution
 */