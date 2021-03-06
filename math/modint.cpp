template<unsigned mod=1000000007>struct fp {
   using uint=unsigned; uint v;
   static uint get_mod(){return mod;}
   int inv() const{
      int tmp,a=v,b=mod,x=1,y=0;
      while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
      if(x<0){x+=mod;} return x;
   }
   fp(ll x=0){init(x%mod+mod);}
   fp& init(uint x){v=(x<mod?x:x-mod); return *this;}
   fp operator-()const{return fp()-*this;}
   fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return res;}
   fp& operator+=(const fp& x){return init(v+x.v);}
   fp& operator-=(const fp& x){return init(v+mod-x.v);}
   fp& operator*=(const fp& x){v=ll(v)*x.v%mod; return *this;}
   fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return *this;}
   fp operator+(const fp& x)const{return fp(*this)+=x;}
   fp operator-(const fp& x)const{return fp(*this)-=x;}
   fp operator*(const fp& x)const{return fp(*this)*=x;}
   fp operator/(const fp& x)const{return fp(*this)/=x;}
   bool operator==(const fp& x)const{return v==x.v;}
   bool operator!=(const fp& x)const{return v!=x.v;}
   friend istream& operator>>(istream& is,fp& x){is>>x.v; return is;}
   friend ostream& operator<<(ostream& os,fp& x){os<<x.v; return os;}
}; using Fp=fp<>;
template<typename T>struct factorial {
   vector<T> Fact,Finv,Inv;
   factorial(int maxx){
      Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);
      Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;
      rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();
      for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}
   }
   T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}
   T inv(int n){if(n<0)return 0; return Inv[n];}
   T nPr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}
   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}
};
