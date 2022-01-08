#pragma once

ll FloorSum(ll n,ll a,ll b,ll m){
   //sum_{k=0}^{n-1} [(a*k+b)/m]
   ll res=0;
   while(1){
      ll y_max=a*n+b;
      if(y_max<m)break;
      n=y_max/m;
      b=y_max%m;
      res+=(n*(n-1)/2)*(m/a)+n*(b/a);
      swap(m,a);
      a%=m;
      b%=m;
   }
   return res;
}

/**
 * @brief Floor Sum
 */