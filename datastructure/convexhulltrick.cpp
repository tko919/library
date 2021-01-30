struct CHT{
   int n; vector<ll> xs,p,q; vector<bool> used;
   CHT(vector<ll> ps){
      n=1; while(n<ps.size())n<<=1;
      used.assign(4*n,0); xs.resize(4*n,inf);
      p.resize(4*n); q.resize(4*n);
      rep(i,0,ps.size())xs[i]=ps[i];
   }
   void add(ll a,ll b,int k=0,int l=0,int r=-1){
      if(r==-1)r=n;
      while(r-l>0){
         int m=(l+r)>>1;
         if(!used[k]){
            p[k]=a; q[k]=b; used[k]=1;
            return;
         }
         ll lx=xs[l],mx=xs[m],rx=xs[r-1];
         ll pk=p[k],qk=q[k];
         bool lb=(a*lx+b<pk*lx+qk);
         bool mid=(a*mx+b<pk*mx+qk);
         bool rb=(a*rx+b<pk*rx+qk);
         if(lb&&rb){p[k]=a; q[k]=b; return;}
         if(!lb&&!rb)return;
         if(mid){swap(p[k],a); swap(q[k],b);}
         if(lb!=mid){k=2*k+1; r=m;} else{k=2*k+2; l=m;}
      }
   }
   void add_segment(ll a,ll b,int l,int r){
      ll l0=l+n,r0=r+n,s0=l,t0=r,sz=1;
      while(l0<r0){
         if(r0&1){r0--; t0-=sz; add(a,b,r0-1,t0,t0+sz);}
         if(l0&1){add(a,b,l0-1,s0,s0+sz); l0++; s0+=sz;}
         l0>>=1; r0>>=1; sz<<=1;
      }
   }
   ll query(int i){
      int k=i+n-1;
      ll x=xs[i],s=used[k]?p[k]*x+q[k]:INF;
      while(k){
         k=(k-1)>>1;
         if(used[k])chmin(s,p[k]*x+q[k]);
      } return s;
   }
};
