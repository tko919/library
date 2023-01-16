#pragma once

template<typename T=ll>T FloorSum(ll n,ll a,ll b,ll m){
   //sum_{k=0}^{n-1} [(a*k+b)/m]
   T res=0;
   if(a>=m)res+=T(a/m)*n*(n-1)/2,a-=a/m*m;
   else if(a<0)res-=T((-a+m-1)/m)*n*(n-1)/2,a+=((-a+m-1)/m)*m;
   if(b>=m)res+=(b/m)*n,b-=b/m*m;
   else if(b<0)res-=((-b+m-1)/m)*n,b+=((-b+m-1)/m)*m;
   
   while(1){
      ll y_max=a*n+b;
      if(y_max<m)break;
      n=y_max/m;
      b=y_max%m;
      res+=(n*(n-1)/2)*(m/a)+n*(b/a);
      swap(m,a);
      a=a%m;
      b=b%m;
   }
   return res;
}

/**
 * @brief Floor Sum
 * @docs docs/floorsum.md
 */