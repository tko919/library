#pragma once
#include "Math/matrix.hpp"
#include "Math/charpoly.hpp"
#include "Utility/random.hpp"

template<typename T>vector<T> detApBx(Matrix<T> a,Matrix<T> b){
    Random gen;
    int n=a.h;
    vector<T> f(n+1);
    T ran=gen.get();
    rep(i,0,n)rep(j,0,n)a[i][j]-=b[i][j]*ran;
    auto ainv=a.inv();
    if(a.det==0)return f;
    b*=ainv;
    rep(i,0,n)rep(j,0,n)b[i][j]=-b[i][j];
    f=CharPoly(b);
    reverse(ALL(f));
    for(auto& x:f)x*=a.det;
    vector C(n+1,vector<T>(n+1));
    vector<T> pw(n+1,1);
    rep(i,0,n+1){
        if(i)pw[i]=pw[i-1]*ran;
        C[i][0]=C[i][i]=1;
        rep(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    vector<T> ret(n+1);
    rep(i,0,n+1)rep(j,0,i+1)ret[j]+=f[i]*C[i][j]*pw[i-j];
    return ret;
}

/**
 * @brief $\det(A+Bx)$
*/