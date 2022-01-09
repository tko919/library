#pragma once
#include "Math/matrix.hpp"

template<typename T>pair<vector<T>,Matrix<T>> LinearEquation(Matrix<T> a,vector<T> b){
   int h=a.h,w=a.w;
   rep(i,0,h)a[i].push_back(b[i]);
   a.w++;
   vector<int> idx=a.gauss(w);
   rep(i,idx.size(),h)if(a[i][w]!=0)return {{},{}};
   vector<T> res(w);
   rep(i,0,idx.size())res[idx[i]]=a[i][w]/a[i][idx[i]];
   Matrix<T> d(w,h+w);
   rep(i,0,h)rep(j,0,w)d[j][i]=a[i][j];
   rep(i,0,w)d[i][h+i]=1;
   int r=d.gauss(h).size();
   Matrix<T> basis(w-r,w);
   rep(i,r,w)basis[i-r]={d[i].begin()+h,d[i].end()};
   return {res,basis};
}

/**
 * @brief Linear Equation
 */