#pragma once

template<typename T=int>inline T get(){
   char c=getchar(); bool neg=(c=='-');
   T res=neg?0:c-'0'; while(isdigit(c=getchar()))res=res*10+(c-'0');
   return neg?-res:res;
}
template<typename T=int>inline void put(T x,char c='\n'){
   int d[20],i=0; if(x<0)putchar('-'),x*=-1;
   do{d[i++]=x%10;}while(x/=10); while(i--)putchar('0'+d[i]);
   putchar(c);
}

/**
 * @brief Fast IO
 */