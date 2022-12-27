#pragma once
#include "Math/fastdiv.hpp"

ll FloorSum(ll n,ll a,ll b,ll m){
   //sum_{k=0}^{n-1} [(a*k+b)/m]
   FastDiv im(m);
   ll res=0;
   if(a>=m)res-=(a/im)*n*(n-1)/2,a-=a/im*m;
   else if(a<0)res+=((-a+m-1)/im)*n*(n-1)/2,a+=((-a+m-1)/im)*m;
   if(b>=m)res-=(b/im)*n,b-=b/im*m;
   else if(b<0)res+=((-b+m-1)/im)*n,b+=((-b+m-1)/im)*m;
   
   while(1){
      ll y_max=a*n+b;
      if(y_max<m)break;
      n=y_max/im;
      b=y_max%im;
      res+=(n*(n-1)/2)*(m/a)+n*(b/a);
      swap(m,a);
      a=a%im;
      b=b%im;
   }
   return res;
}

/**
 * @brief Floor Sum
 * @docs docs/floorsum.md
 */