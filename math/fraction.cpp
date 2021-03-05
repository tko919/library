struct frac{
   ll num,den;
   frac(ll n_,ll d_){init(n_,d_);}
   frac& init(ll n,ll d){
      den=d; num=n;
      if(den<0)den=-den,num=-num;
      ll g=gcd(den,num);
      den/=g; num/=g;
      return *this;
   }
   frac& operator+=(const frac& x){
      return init(num*x.den+x.num*den,den*x.den);
   }
   frac& operator-=(const frac& x){
      return init(num*x.den-x.num*den,den*x.den);
   }
   frac& operator*=(const frac& x){
      return init(num*x.num,den*x.den);
   }
   frac& operator/=(const frac& x){
      return init(num*x.den,den*x.num);
   }
   frac operator+(const frac& x)const{
      return frac(*this)+=x;
   }
   frac operator-(const frac& x)const{
      return frac(*this)-=x;
   }
   frac operator*(const frac& x)const{
      return frac(*this)*=x;
   }
   frac operator/(const frac& x)const{
      return frac(*this)/=x;
   }
   bool operator<(const frac& x)const{
      return num*x.den<den*x.num;
   }
   bool operator>(const frac& x)const{
      return x<*this;
   }
   bool operator<=(const frac& x)const{
      return !(x<*this);
   }
   bool operator>=(const frac& x)const{
      return !(*this<x);
   }
   double real(){return num*1./den;}
};

using P=pair<ll,ll>; //{num,den}
bool cmp(const P& p,const P& q){return p.first*q.second<p.second*q.first;};
P operator+(const P& p,const P& q){return P{p.first+q.first,p.second+q.second};};

P between(P mi,P ma){//mi<x<ma,min(x.first)
   auto rec=[&](auto self,P lb=P{0,1},P rb=P{1,0})->P{
      P mid=lb+rb;
      if(!cmp(mi,mid)){
         P add=rb,res=lb;
         while(!cmp(mi,res+add)){
            res=res+add; add=add+add;
         } return self(self,res,rb);
      }
      else if(!cmp(mid,ma)){
         P add=lb,res=rb;
         while(!cmp(res+add,ma)){
            res=res+add; add=add+add;
         } return self(self,lb,res);
      } return mid;
   };
   return rec(rec);
}
//verified:https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146184
