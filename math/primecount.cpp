#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//end

ll pi(ll n){
   if(n<=1)return 0;
   const int v=sqrtl(n); int s=(v+1)/2;
   vector<int> ss(v+1),rs(s); vector<ll> ls(s);
   rep(i,2,v+1)ss[i]=(i+1)/2;
   rep(i,0,s)rs[i]=i*2+1,ls[i]=(n/rs[i]+1)/2;
   vector<bool> skip(v+1); int cnt=0;
   for(int p=3;p<=v;p++)if(ss[p]>ss[p-1]){
      int q=p*p; cnt++;
      if(1LL*q*q>n)break; skip[p]=1;
      for(int i=q;i<=v;i+=p*2)skip[i]=1;
      int nxt=0;
      for(int k=0;k<s;k++){
         int i=rs[k]; if(skip[i])continue;
         ll d=1LL*p*i;
         ls[nxt]=ls[k]-(d<=v?ls[ss[d]-cnt]:ss[n/d])+cnt;
         rs[nxt++]=i;
      } s=nxt;
      for(int j=v/p;j>=p;j--){
         int c=ss[j]-cnt;
         for(int i=p*j,lim=min(p+i,v+1);i<lim;i++)ss[i]-=c;
      }
   }
   for(int k=1;k<s;k++){
      const ll m=n/rs[k]; ll t=ls[k]-(cnt+k-1);
      for(int l=1;l<k;l++){
         int p=rs[l]; if(1LL*p*p>m)break;
         t-=ss[m/p]-(cnt+l-1);
      } ls[0]-=t;
   } return ls[0];
}

int main(){
   ll n; cin>>n;
   printf("%lld\n",pi(n));
   return 0;
}
