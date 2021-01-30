NTT<Fp,3> ntt;
vector<Fp> mult(const vector<Fp>& a,const vector<Fp>& b,bool same){
   return ntt.mult(a,b,same);
}
factorial<Fp> fact(2010101);
template<typename T=Fp>struct Poly:vector<T>{
   Poly(int n=0){this->assign(n,T());}
   Poly(const vector<T>& f){this->assign(ALL(f));}
   T eval(const T& x){T res; for(auto& v:*this)res*=x,res+=v; return res;}
   Poly rev()const{Poly res=*this; reverse(ALL(res)); return res;}
   void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}
   Poly inv()const{
      assert(this->front()!=0); const int n=this->size();
      Poly res(1); res.front()=T(1)/this->front();
      for(int k=1;k<n;k<<=1){
         Poly g=res,h=*this; h.resize(k*2); res.resize(k*2);
         g=(g.square()*h); g.resize(k*2);
         rep(i,k,min(k*2,n))res[i]-=g[i];
      }
      res.resize(n); return res;
   }
   Poly square()const{return Poly(mult(*this,*this,1));}
   Poly operator+(const Poly& g)const{return Poly(*this)+=g;}
   Poly operator-(const Poly& g)const{return Poly(*this)-=g;}
   Poly operator*(const Poly& g)const{return Poly(*this)*=g;}
   Poly operator/(const Poly& g)const{return Poly(*this)/=g;}
   Poly operator%(const Poly& g)const{return Poly(*this)%=g;}
   Poly& operator+=(const Poly& g){
      if(g.size()>this->size())this->resize(g.size());
      rep(i,0,g.size()){(*this)[i]+=g[i];} shrink(); return *this;
   }
   Poly& operator-=(const Poly& g){
      if(g.size()>this->size())this->resize(g.size());
      rep(i,0,g.size()){(*this)[i]-=g[i];} shrink(); return *this;
   }
   Poly& operator*=(const Poly& g){
      *this=mult(*this,g,0);
      shrink(); return *this;
   }
   Poly& operator/=(const Poly& g){
      if(g.size()>this->size()){
         this->clear(); return *this;
      }
      *this=this->rev(); g=g.rev();
      int n=this->size()-g.size()+1;
      this->resize(n); g.resize(n);
      *this*=g.inv_fast(); this->resize(n); //
      *this=this->rev(); shrink(); return *this;
   }
   Poly& operator%=(Poly& g){*this-=*this/g*g; shrink(); return *this;}
   Poly diff()const{
      Poly res(this->size()-1);
      rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);
      return res;
   }
   Poly inte()const{
      Poly res(this->size()+1);
      for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]*fact.inv(i);
      return res;
   }
   Poly log()const{
      assert(this->front()==1); const int n=this->size();
      Poly res=diff()*inv_fast(); res=res.inte(); //
      res.resize(n); return res;
   }
   Poly exp()const{
      assert(this->front()==0); const int n=this->size();
      Poly res(1),g(1); res.front()=g.front()=1;
      for(int k=1;k<n;k<<=1){
         g=(g+g-g.square()*res); g.resize(k);
         Poly q=*this; q.resize(k); q=q.diff();
         Poly w=(q+g*(res.diff()-res*q)),t=*this;
         w.resize(k*2-1); t.resize(k*2);
         res=(res+res*(t-w.inte())); res.resize(k*2);
      } res.resize(n); return res;
   }
   Poly shift(const int& c)const{
      const int n=this->size();
      Poly res=*this,g(n); g[1]=c; g=g.exp_fast(); //
      rep(i,0,n){res[i]*=fact.fact(i);} res=res.rev();
      res*=g; res.resize(n); res=res.rev();
      rep(i,0,n){res[i]*=fact.fact(i,1);} return res;
   }
   Poly inv_fast()const{
      const int n=this->size();
      Poly res(1); res.front()=T(1)/this->front();
      for(int k=1;k<n;k<<=1){
         Poly f(k*2),g(k*2);
         rep(i,0,min(n,k*2))f[i]=(*this)[i];
         rep(i,0,k)g[i]=res[i];
         ntt.ntt(f); ntt.ntt(g);
         rep(i,0,k*2)f[i]*=g[i];
         ntt.ntt(f,1);
         rep(i,0,k){f[i]=0; f[i+k]=-f[i+k];}
         ntt.ntt(f); rep(i,0,k*2)f[i]*=g[i]; ntt.ntt(f,1);
         rep(i,0,k)f[i]=res[i];
         swap(res,f);
      } res.resize(n); return res;
   }
   Poly exp_fast()const{
      const int n=this->size();
      if(n==1)return Poly({T(1)});
      Poly b(2),c(1),z1,z2(2);
      b[0]=c[0]=z2[0]=z2[1]=1; b[1]=(*this)[1];
      for(int k=2;k<n;k<<=1){
         Poly y=b; y.resize(k*2);
         ntt.ntt(y); z1=z2;
         Poly z(k);
         rep(i,0,k)z[i]=y[i]*z1[i];
         ntt.ntt(z,1);
         rep(i,0,k>>1)z[i]=0;
         ntt.ntt(z);
         rep(i,0,k)z[i]*=-z1[i];
         ntt.ntt(z,1);
         c.insert(c.end(),z.begin()+(k>>1),z.end());
         z2=c; z2.resize(k*2);
         ntt.ntt(z2);
         Poly x=*this; x.resize(k); x=x.diff(); x.resize(k);
         ntt.ntt(x);
         rep(i,0,k)x[i]*=y[i];
         ntt.ntt(x,1);
         Poly bb=b.diff();
         rep(i,0,k-1)x[i]-=bb[i];
         x.resize(k*2);
         rep(i,0,k-1){x[k+i]=x[i]; x[i]=0;}
         ntt.ntt(x);
         rep(i,0,k*2)x[i]*=z2[i];
         ntt.ntt(x,1);
         x.pop_back(); x=x.inte();
         rep(i,k,min(n,k*2))x[i]+=(*this)[i];
         rep(i,0,k)x[i]=0;
         ntt.ntt(x);
         rep(i,0,k*2)x[i]*=y[i];
         ntt.ntt(x,1);
         b.insert(b.end(),x.begin()+k,x.end());
      } b.resize(n); return b;
   }
   Poly pow(ll t){
      int n=this->size(),k=0; while(k<n and (*this)[k]==0)k++;
      Poly res(n); if(t*k>=n)return res;
      n-=t*k; Poly g(n); T c=(*this)[k],ic=T(1)/c;
      rep(i,0,n)g[i]=(*this)[i+k]*ic;
      g=g.log(); for(auto& x:g)x*=t; g=g.exp_fast(); //
      c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c; return res;
   }
};
Fp nth(Poly<Fp> p,Poly<Fp> q,ll n){
   while(n){
      Poly<Fp> base(q),np,nq;
      for(int i=1;i<(int)q.size();i+=2)base[i]=-base[i];
      p*=base; q*=base;
      for(int i=n&1;i<(int)p.size();i+=2)np.emplace_back(p[i]);
      for(int i=0;i<(int)q.size();i+=2)nq.emplace_back(q[i]);
      swap(p,np); swap(q,nq);
      n>>=1;
   }
   return p[0]/q[0];
}
