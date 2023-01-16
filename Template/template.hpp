#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))
#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()
#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()

using ll=long long int;
const int inf = 0x3fffffff;
const ll INF = 0x1fffffffffffffff;

template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<typename T,typename U>T ceil(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}
template<typename T,typename U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}
template<typename T>int popcnt(T x){return __builtin_popcountll(x);}
template<typename T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}
template<typename T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}