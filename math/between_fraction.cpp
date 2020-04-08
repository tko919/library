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

typedef pair<ll,ll> P;
bool cmp(const P& p,const P& q){return p.second*q.first<p.first*q.second;};
P operator+(const P& p,const P& q){return P{p.first+q.first,p.second+q.second};};

P mi,ma;
P rec(P lb,P rb){//mi<x<ma,min(x.first)
   P mid=lb+rb;
   if(!cmp(mi,mid)){
      P add=rb,res=lb;
      while(!cmp(mi,res+add)){
         res=res+add; add=add+add;
      } return rec(res,rb);
   }
   else if(!cmp(mid,ma)){
      P add=lb,res=rb;
      while(!cmp(res+add,ma)){
         res=res+add; add=add+add;
      } return rec(lb,res);
   } return mid;
}
//verified:https://codingcompetitions.withgoogle.com/codejam/round/0000000000051679/0000000000146184

int main(){
   scanf("%lld%lld%lld%lld",&mi.first,&mi.second,&ma.first,&ma.second);
   auto res=rec({1,0},{0,1}); printf("%lld %lld\n",res.first,res.second);
}
