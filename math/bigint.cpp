#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
//template
#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end
 
template<unsigned mod=998244353>struct fp {
   unsigned v;
   static unsigned get_mod(){return mod;}
   unsigned inv() const{
      int tmp,a=v,b=mod,x=1,y=0;
      while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
      if(x<0){x+=mod;} return x;
   }
   fp():v(0){}
   fp(ll x):v(x>=0?x%mod:mod+(x%mod)){}
   fp operator-()const{return fp(-v);}
   fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return res;}
   fp& operator+=(const fp& x){if((v+=x.v)>=mod)v-=mod; return *this;}
   fp& operator-=(const fp& x){if((v+=mod-x.v)>=mod)v-=mod; return *this;}
   fp& operator*=(const fp& x){v=ll(v)*x.v%mod; return *this;}
   fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return *this;}
   fp operator+(const fp& x)const{return fp(*this)+=x;}
   fp operator-(const fp& x)const{return fp(*this)-=x;}
   fp operator*(const fp& x)const{return fp(*this)*=x;}
   fp operator/(const fp& x)const{return fp(*this)/=x;}
   bool operator==(const fp& x)const{return v==x.v;}
   bool operator!=(const fp& x)const{return v!=x.v;}
}; using Fp=fp<>;
 
template<typename T,unsigned p>struct NTT{
   vector<T> rt,irt;
   NTT(int lg=21){
      const unsigned m=T(-1).v; T prt=p;
      rt.resize(1<<lg,1); irt.resize(1<<lg,1);
      for(int w=0;w<lg;w++){
         int mask=1<<w; T g=prt.pow(m>>w),ig=g.inv();
         for(int i=0;i<mask-1;i++){
            rt[mask+i+1]=g*rt[mask+i];
            irt[mask+i+1]=ig*irt[mask+i];
         }
      }
   }
   void ntt(vector<T>& f,bool inv=0){
      int n=f.size();
      if(inv){
         for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=i*2)for(int k=0;k<i;k++){
            f[i+j+k]*=irt[i*2+k]; T tmp=f[j+k]-f[i+j+k];
            f[j+k]+=f[i+j+k]; f[i+j+k]=tmp;
         } T mul=T(n).inv(); rep(i,0,n)f[i]*=mul;
      }else{
         for(int i=n>>1;i;i>>=1)for(int j=0;j<n;j+=i*2)for(int k=0;k<i;k++){
            T tmp=f[j+k]-f[i+j+k]; f[j+k]+=f[i+j+k]; f[i+j+k]=tmp*rt[i*2+k];
         }
      }
   }
   template<typename U=T>vector<T> conv(vector<U> a,vector<U> b,bool same=0){
      if(a.empty() and b.empty())return vector<T>();
      int n=a.size()+b.size()-1,m=1; while(m<n)m<<=1;
      vector<T> res(m); rep(i,0,a.size()){res[i]=a[i];} ntt(res);
      if(same)rep(i,0,m)res[i]*=res[i];
      else{
         vector<T> c(m); rep(i,0,b.size())c[i]=b[i];
         ntt(c); rep(i,0,m)res[i]*=c[i];
      } ntt(res,1); return res;
   }
};
 
using F1=fp<167772161>; using F2=fp<469762049>;
NTT<F1,3> ntt1(20); NTT<F2,3> ntt2(20);
const F1 coeff=F1(F2::get_mod()).inv();
template<int D=4>struct bigint{
   int B,sign; vector<ll> v;
   static int get_D(){return D;}
   bigint(ll x=0){
      B=1; rep(_,0,D)B*=10; sign=1;
      if(x<0)x*=-1,sign=0;
      while(x){v.push_back(x%B); x/=B;}
   }
   bigint(string s){
      B=1; rep(_,0,D)B*=10; sign=1;
      if(s[0]=='-')s.erase(s.begin()),sign=0;
      int add=0,cnt=0,base=1;
      while(s.size()){
         if(cnt==D){
            v.push_back(add);
            cnt=0; add=0; base=1;
         }
         add=(s.back()-'0')*base+add;
         cnt++; base*=10; s.pop_back();
      } if(add)v.push_back(add);
   }
   bigint operator-()const{bigint res=*this; res.sign^=1; return res;}
   bigint abs()const{bigint res=*this; res.sign=1; return res;}
   ll& operator[](const int i){return v[i];}
   int size()const{return v.size();}
   void norm(){
      rep(i,0,v.size()-1){
         if(v[i]>=0){v[i+1]+=v[i]/B; v[i]%=B;}
         else{int c=(-v[i]+B-1)/B; v[i]+=c*B; v[i+1]-=c;}
      }
      while(!v.empty() and v.back()>=B){
         int c=v.back()/B;
         v.back()%=B; v.push_back(c);
      }
      while(!v.empty() and v.back()==0)v.pop_back();
   }
   string to_str()const{
      string res;
      if(v.empty())return "0";
      if(!sign)res+="-";
      res+=to_string(v.back());
      for(int i=v.size()-2;i>=0;i--){
         string add; int w=v[i];
         rep(_,0,D){
            add+=('0'+(w%10)); w/=10;
         } reverse(ALL(add)); res+=add;
      } return res;
   }
   friend istream& operator>>(istream& is,bigint<D>& x){
      string tmp; is>>tmp; x=bigint(tmp); return is;
   }
   friend ostream& operator<<(ostream& os,bigint<D>& x){
      os<<x.to_str(); return os;
   }
   bigint& operator<<=(const int& x){
      if(!v.empty()){
         vector<ll> add(x,0);
         v.insert(v.begin(),ALL(add));
      } return *this;
   }
   bigint& operator>>=(const int& x){
      v=vector<ll>(v.begin()+min(x,(int)v.size()),v.end());
      return *this;
   }
   bigint& operator+=(const bigint& x){
      if(sign!=x.sign){*this-=(-x); return *this;}
      if((int)v.size()<(int)x.size())v.resize(x.size(),0);
      rep(i,0,x.size()){v[i]+=x.v[i];} norm(); return *this;
   }
   bigint& operator-=(const bigint& x){
      if(sign!=x.sign){*this+=(-x); return *this;}
      if(abs()<x.abs()){*this=x-(*this); sign^=1; return *this;}
      rep(i,0,x.size()){v[i]-=x.v[i];} norm(); return *this;
   }
   bigint& operator*=(const bigint& x){
      if(!x.sign)sign^=1;
      auto v1=ntt1.conv<ll>(v,x.v);
      auto v2=ntt2.conv<ll>(v,x.v);
      v.assign(v1.size(),0);
      rep(i,0,v1.size()){
         ll val=1LL*F1((v1[i]-F1(v2[i].v))*coeff).v*F2::get_mod()+v2[i].v;
         for(int j=i;val;j++){
            if(j==(int)v.size())v.push_back(0);
            v[j]+=val%B; val/=B;
         }
      } norm(); return *this;
   }
   bigint& operator/=(const bigint& x){
      //reference:https://qiita.com/square1001/items/1aa12e04934b6e749962
      if((int)v.size()<(int)x.size()){return *this=bigint();}
      if(!x.sign){sign^=1;} bigint a=abs(),b=x.abs();
      int d=a.size()-b.size()+1;
      bigint inv(1),pre;
      int lim=min(d,3),blim=min((int)b.size(),6); inv<<=lim;
      while(inv.v!=pre.v){
         bigint mul; mul.v=vector<ll>(b.v.end()-blim,b.v.end());
         if(blim!=b.size()){mul[0]++; mul.norm();}
         pre=inv; inv*=((bigint(2)<<(lim+blim))-inv*mul); inv>>=(lim+blim);
      }
      if(lim!=d){
         pre=bigint();
         while(inv.v!=pre.v){
            bigint mul,two; mul.v=vector<ll>(b.v.end()-blim,b.v.end());
            if(blim!=b.size()){mul[0]++; mul.norm();}
            pre=inv; inv*=((bigint(2)<<(lim+blim))-inv*mul); inv>>=(lim+blim);
            int nxt=min(lim*2+1,d);
            if(nxt!=lim)inv<<=(nxt-lim);
            int nxtb=min(blim*2+1,b.size()); lim=nxt; blim=nxtb;
         }
      }
      bigint res=a*inv;
      res.v=vector<ll>(res.v.begin()+a.size()+1,res.v.end());
      bigint c=res*b; if(c+b<=a){res+=bigint(1); res.norm();}
      v=res.v; return *this;
   }
   bigint& operator%=(const bigint& x){
      bigint div=(*this)/x; (*this)-=div*x; return *this;
   }
   bigint& div2(){
      for(int i=v.size()-1;i>=0;i--){
         if(v[i]&1 and i!=0){v[i-1]+=B;} v[i]>>=1;
      } norm(); return *this;
   }
   bigint operator<<(const int& x)const{return bigint(*this)<<=x;}
   bigint operator>>(const int& x)const{return bigint(*this)>>=x;}
   bigint operator+(const bigint& x)const{return bigint(*this)+=x;}
   bigint operator-(const bigint& x)const{return bigint(*this)-=x;}
   bigint operator*(const bigint& x)const{return bigint(*this)*=x;}
   bigint operator/(const bigint& x)const{return bigint(*this)/=x;}
   bigint operator%(const bigint& x)const{return bigint(*this)%=x;}
   bool operator<(const bigint& x)const{
      if(sign!=x.sign)return sign<x.sign;
      if((int)v.size()!=(int)x.size())return (int)v.size()*sign<(int)x.size()*x.sign;
      for(int i=v.size()-1;i>=0;i--)if(v[i]!=x.v[i])return v[i]*sign<x.v[i]*x.sign;
      return false;
   }
   bool operator>(const bigint& x)const{return x<*this;}
   bool operator<=(const bigint& x)const{return !(*this>x);}
   bool operator>=(const bigint& x)const{return !(*this<x);}
};
typedef bigint<4> Bigint;

struct Bigfloat{
   Bigint v; int p=0;
   Bigfloat(){}
   Bigfloat(const Bigint& _v,int _p=0):v(_v),p(_p){}
   void set(int _p){if(p<_p){v>>=(_p-p);} else{v<<=(p-_p);} p=_p;}
   Bigfloat& operator+=(const Bigfloat& x){
      if(p>x.p)set(x.p),v+=x.v;
      else v+=x.v<<(x.p-p);
      return *this;
   }
   Bigfloat& operator-=(const Bigfloat& x){
      if(p>x.p)set(x.p),v-=x.v;
      else v-=x.v<<(x.p-p);
      return *this;
   }
   Bigfloat& operator*=(const Bigfloat& x){p+=x.p; v*=x.v; return *this;}
   Bigfloat& operator/=(const Bigfloat& x){p-=x.p; v/=x.v; return *this;}
   void div2(){if(v[0]&1)p--,v*=Bigint(5); else v.div2();}
	Bigfloat operator+(const Bigfloat& x)const{return Bigfloat(*this)+=x;}
	Bigfloat operator-(const Bigfloat& x)const{return Bigfloat(*this)-=x;}
	Bigfloat operator*(const Bigfloat& x)const{return Bigfloat(*this)*=x;}
	Bigfloat operator/(const Bigfloat& x)const{return Bigfloat(*this)/=x;}
   string to_str(){
      string res=v.to_str();
      if(p>0)res+=string(p,'0');
      else if(-p>=1 and -p<(int)res.size()){
         res=res.substr(0,(int)res.size()+p)+'.'+res.substr((int)res.size()+p);
      }
      else if(-p>=(int)res.size())res="0."+string(-p-(int)res.size(),'0')+res;
      return res;
   }
   friend ostream& operator<<(ostream& os,Bigfloat x){
      os<<x.to_str(); return os;
   }
};
