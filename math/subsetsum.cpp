#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//end

template<unsigned mod=998244353>struct mint {
   unsigned val;
   static unsigned get_mod(){return mod;}
   unsigned inv() const{
      int tmp,a=val,b=mod,x=1,y=0;
      while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
      if(x<0)x+=mod; return x;
   }
   mint():val(0){}
   mint(ll x):val(x>=0?x%mod:mod+(x%mod)){}
   mint pow(ll t){mint res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
   mint& operator+=(const mint& x){if((val+=x.val)>=mod)val-=mod;return *this;}
   mint& operator-=(const mint& x){if((val+=mod-x.val)>=mod)val-=mod; return *this;}
   mint& operator*=(const mint& x){val=ll(val)*x.val%mod; return *this;}
   mint& operator/=(const mint& x){val=ll(val)*x.inv()%mod; return *this;}
   mint operator+(const mint& x)const{return mint(*this)+=x;}
   mint operator-(const mint& x)const{return mint(*this)-=x;}
   mint operator*(const mint& x)const{return mint(*this)*=x;}
   mint operator/(const mint& x)const{return mint(*this)/=x;}
   bool operator==(const mint& x)const{return val==x.val;}
   bool operator!=(const mint& x)const{return val!=x.val;}
};
template<unsigned mod=998244353>struct factorial {
   using Mint=mint<mod>;
   vector<Mint> Fact, Finv;
public:
   factorial(int maxx){
      Fact.resize(maxx+1),Finv.resize(maxx+1); Fact[0]=Mint(1); rep(i,0,maxx)Fact[i+1]=Fact[i]*(i+1);
      Finv[maxx]=Mint(1)/Fact[maxx]; rrep(i,maxx,0)Finv[i-1]=Finv[i]*i;
   }
   Mint fact(int n,bool inv=0){if(inv)return Finv[n];else return Fact[n];}
   Mint nPr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[n-r];}
   Mint nCr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[r]*Finv[n-r];}
};
using Mint=mint<>;

vector<int> rt,irt;
template<unsigned mod=998244353>void init(int lg=21){
   using Mint=mint<mod>; Mint prt=2;
   while(prt.pow(mod>>1).val==1)prt+=1;
   rt.resize(1<<lg,1); irt.resize(1<<lg,1);
   rep(w,0,lg){
      int mask=(1<<w)-1,t=Mint(-1).val>>w;
      Mint g=prt.pow(t),ig=prt.pow(mod-1-t);
      rep(i,0,mask){
         rt[mask+i+1]=(g*rt[mask+i]).val;
         irt[mask+i+1]=(ig*irt[mask+i]).val;
      }
   }
}

template<unsigned mod=998244353>struct FPS{
   using Mint=mint<mod>; vector<Mint> f;
   FPS():f({1}){}
   FPS(int _n):f(_n){}
   FPS(vector<Mint> _f):f(_f){}
   Mint& operator[](const int i){return f[i];}
   Mint eval(Mint x){
      Mint res,w=1;
      for(Mint v:f)res+=w*v,w*=x; return res;
   }
   FPS inv()const{
      assert(f[0]!=0); int n=f.size();
      FPS res(n); res.f[0]=f[0].inv();
      for(int k=1;k<n;k<<=1){
         FPS g(k*2),h(k*2);
         rep(i,0,min(k*2,n))g[i]=f[i]; rep(i,0,k)h[i]=res[i];
         g.ntt(); h.ntt(); rep(i,0,k*2)g[i]*=h[i]; g.ntt(1);
         rep(i,0,k)g[i]=0,g[i+k]*=-1;
         g.ntt(); rep(i,0,k*2)g[i]*=h[i]; g.ntt(1);
         rep(i,k,min(k*2,n))res[i]=g[i];
      } return res;
   }
   void ntt(bool inv=0){
        int n=f.size(); if(n==1)return;
        if(inv){
            for(int i=1;i<n;i<<=1){
                for(int j=0;j<n;j+=i*2){
                    rep(k,0,i){
                        f[i+j+k]*=irt[i*2-1+k];
                        const Mint tmp=f[j+k]-f[i+j+k];
                        f[j+k]+=f[i+j+k]; f[i+j+k]=tmp;
                    }
                }
            }
            Mint mul=Mint(n).inv(); rep(i,0,n)f[i]*=mul;
        }else{
            for(int i=n>>1;i;i>>=1){
                for(int j=0;j<n;j+=i*2){
                    rep(k,0,i){
                        const Mint tmp=f[j+k]-f[i+j+k];
                        f[j+k]+=f[i+j+k]; f[i+j+k]=tmp*rt[i*2-1+k];
                    }
                }
            }
        }
   }
   FPS operator+(const FPS& g)const{return FPS(*this)+=g;}
   FPS operator-(const FPS& g)const{return FPS(*this)-=g;}
   FPS operator*(const FPS& g)const{return FPS(*this)*=g;}
   template<class T>FPS operator*(T t)const{return FPS(*this)*=t;}
   FPS operator/(const FPS& g)const{return FPS(*this)/=g;}
   template<class T>FPS operator/(T t)const{return FPS(*this)/=t;}
   FPS operator%(const FPS& g)const{return FPS(*this)%=g;}
   FPS& operator+=(FPS g){
      if(g.f.size()>f.size())f.resize(g.f.size());
      rep(i,0,g.f.size())f[i]+=g[i]; return *this;
   }
   FPS& operator-=(FPS g){
      if(g.f.size()>f.size())f.resize(g.f.size());
      rep(i,0,g.f.size())f[i]-=g[i]; return *this;
   }
   FPS& operator*=(FPS g){
      int m=f.size()+g.f.size()-1,n=1; while(n<m)n<<=1;
      f.resize(n); g.f.resize(n);
      ntt(); g.ntt(); rep(i,0,n)f[i]*=g[i]; 
      ntt(1); f.resize(m); return *this;
   }
   template<class T>FPS& operator*=(T t){for(Mint x:f)x*=t; return *this;}
   FPS& operator/=(FPS g){
      if(g.f.size()>f.size())return *this=FPS({0});
      reverse(ALL(f)); reverse(ALL(g.f));
      int n=f.size()-g.f.size()+1;
      f.resize(n); g.f.resize(n); FPS mul=g.inv();
      *this*=mul; f.resize(n); reverse(ALL(f)); return *this;
   }
   template<class T>FPS& operator/=(T t){for(Mint x:f)x/=t; return *this;}
   FPS& operator%=(FPS g){
      *this-=*this/g*g;
      while(!f.empty()&&f.back()==0)f.pop_back();
      return *this;
   }
   FPS sqrt(){
      int n=f.size(); FPS res(1); res[0]=1;
      for(int k=1;k<n;k<<=1){
         FPS ff=*this; res.f.resize(k*2);
         res+=ff/res; res/=2;
      } res.f.resize(n); return res;
   }
   FPS diff(){
      FPS res=*this; rep(i,0,res.f.size()-1)res[i]=res[i+1]*(i+1);
      res.f.pop_back(); return res;
   }
   FPS inte(){
      FPS res=*this; res.f.push_back(0);
      rrep(i,res.f.size()-1,0)res[i]=res[i-1]/i;
      res[0]=0; return res;
   }
   FPS log(){
      assert(f[0]==1); FPS res=diff()*inv(); 
      res.f.resize(f.size()-1); res=res.inte(); return res;
   }
   FPS exp(){
      assert(f[0]==0); int m=f.size(),n=1; while(n<m)n<<=1;
      f.resize(n); FPS d=diff(),res(n); vector<FPS> pre;
      for(int k=n;k;k>>=1){
         FPS g=d; g.f.resize(k);
         g.ntt(); pre.push_back(g);
      }
      auto dfs=[&](auto dfs,int l,int r,int dep)->void{
         if(r-l==1){if(l>0)res[l]/=l; return;}
         int m=(l+r)>>1; dfs(dfs,l,m,dep+1);
         FPS g(r-l); rep(i,0,m-l)g[i]=res[l+i];
         g.ntt(); rep(i,0,r-l)g[i]*=pre[dep][i]; g.ntt(1);
         rep(i,m,r)res[i]+=g[i-l-1]; dfs(dfs,m,r,dep+1);
      }; res[0]=1; dfs(dfs,0,n,0); res.f.resize(m); return res;
   }
};//need to initialize

int n,t; int a[1010000];
int cnt[501000]={};
factorial<> fact(501000);
Mint inv[501000];

void verify(){
   mt19937 mt(clock());
   n=10,t=mt()%100;
   cerr<<n<<" "<<t<<'\n';
   rep(i,0,n)a[i]=mt()%t+1;
   rep(i,0,n)cerr<<a[i]<<" "; puts("");

   Mint dp[11][110]; dp[0][0]=1;
   rep(i,0,n)rep(j,0,t+1)if(dp[i][j]!=0){
      dp[i+1][j]+=dp[i][j];
      if(j+a[i]<=t)dp[i+1][j+a[i]]+=dp[i][j];
   } cerr<<dp[n][t].val<<endl;
}

int main(){
   cin>>n>>t; rep(i,0,n)cin>>a[i];
   //verify();
   rep(i,1,t+1)inv[i]=fact.fact(i,1)*fact.fact(i-1);
   init(); rep(i,0,n)cnt[a[i]]++; FPS<> f(t+1);
   rep(k,1,t+1)rep(j,1,t/k+1){
      Mint add=inv[j]*cnt[k];
      if(j&1)f[k*j]+=add; else f[k*j]-=add;
   } f=f.exp(); cout<<f[t].val<<endl;
   return 0;
}