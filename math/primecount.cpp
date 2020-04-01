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

constexpr int lim=1341398;
constexpr int mul[]={2,6,30,210,2310,30030,510510};
constexpr short sz=256;
unordered_map<ll,ll> phi_memo[sz],pi_memo;
vector<int> ps;
int rem[7][510510]={};
void init(){
   bitset<lim> isp;
   rep(i,2,lim+1)isp[i]=1;
   for(int p=2;p*p<=lim;p++)if(isp[p]){
      for(int q=p*p;q<=lim;q+=p)isp[q]=0;
   }
   rep(i,1,lim+1){
      if(isp[i])ps.push_back(i);
      pi_memo[i]=ps.size();
   }
   rep(i,0,7)rep(j,1,mul[i]){
      bool f=1;
      rep(k,0,i+1)if(j%ps[k]==0){f=0; break;}
      rem[i][j]=rem[i][j-1]+f;
   }
}

ll pi(ll x);

ll phi(ll x,short a){
   if(phi_memo[a][x])return phi_memo[a][x];
   else if(x==0)return phi_memo[a][x]=0;
   else if(a<=7)return phi_memo[a][x]=x/mul[a-1]*rem[a-1][mul[a-1]-1]+rem[a-1][x%mul[a-1]];
   else if(x<ps[a]*ps[a])return phi_memo[a][x]=pi(x)-a+1;
   else{
      ll res=x;
      rep(i,0,a)if(x>=ps[i])res-=phi(x/ps[i],i); else break;
      return phi_memo[a][x]=res;
   }
}

ll pi(ll x){
   if(pi_memo[x])return pi_memo[x];
   ll a=pi(pow(x,.25)),b=pi(sqrt(x)),c=pi(cbrt(x));
   ll res=phi(x,a)+(b+a-2)*(b-a+1)/2;
   rep(i,a,b){
      ll y=x/ps[i]; res-=pi(y);
      if(i<c){
         ll b_i=pi(sqrt(y)); res+=(i+b_i-1)*(b_i-i)/2;
         rep(j,i,b_i)res-=pi(y/ps[j]);
      }
   } return pi_memo[x]=res;
} //need to initialize

int main(){
   init();
   ll n; cin>>n;
   cout<<pi(n)<<endl;
   return 0;
}