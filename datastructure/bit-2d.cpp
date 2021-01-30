template<class T>struct BIT2D{
   struct BIT{
      int n; vector<T> d;
      BIT(){}
      BIT(int _n):d(n=_n){}
      void add(int i,T x){
         for(i++;i<n;i+=(i&-i))d[i]+=x;
      }
      T sum(int i){
         T x=0; for(i++;i;i-=(i&-i))x+=d[i];
         return x;
      }
   };
   int n; vector<BIT> d;
   vector<int> xs; vector<vector<int>> ys;
   vector<pair<T,T>> p;
   BIT2D(){}
   void push(T x,T y){p.push_back({x,y});}
   void init(){
      rep(i,0,p.size())xs.push_back(p[i].first);
      sort(ALL(xs)); xs.erase(unique(ALL(xs)),xs.end());
      n=xs.size()+1; ys.resize(n);
      rep(j,0,p.size()){
         int s=upper_bound(ALL(xs),p[j].first)-xs.begin();
         for(int i=s;i<n;i+=(i&-i))ys[i].push_back(p[j].second);
      } d.resize(n);
      rep(i,0,n){
         sort(ALL(ys[i])); ys[i].erase(unique(ALL(ys[i])),ys[i].end());
         d[i]=BIT(ys[i].size()+2);
      }
   }
   void add(T x,T y,T z=1){
      int s=upper_bound(ALL(xs),x)-xs.begin();
      for(int i=s;i<n;i+=(i&-i)){
         int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();
         d[i].add(idx,z);
      }
   }
   T sum(T x,T y){
      T res=0; int s=upper_bound(ALL(xs),x)-xs.begin();
      for(int i=s;i;i-=(i&-i)){
         int idx=upper_bound(ALL(ys[i]),y)-ys[i].begin();
         res+=d[i].sum(idx);
      } return res;
   }
   T sum(T x1,T y1,T x2,T y2){return sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);}
};
