template<typename T>struct BIT{
   int n; T m=0; vector<T> val;
   BIT(int _n):n(_n),val(_n+10){}
   void clear(){val.assign(n+10,0); m=0;}
   void add(int i,T x){
      for(i++;i<=n;i+=(i&-i))val[i]+=x;
      m+=x;
   }
   T sum(int i){
      T res=0;
      for(i++;i;i-=(i&-i))res+=val[i];
      return res;
   }
};
