#pragma once
#include "Math/pollard.hpp"

ll mpow(ll a,ll t,ll m){
    ll res=1;
    while(t){
        if(t&1)res=__int128_t(res)*a%m;
        a=__int128_t(a)*a%m; t>>=1;
    } return res;
}
ll minv(ll a,ll m){
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b; swap(a,b);
        u-=t*v; swap(u,v);
    } u=(u%m+m)%m; return u;
}
ll getPrimitiveRoot(ll p){
    vector<ll> ps=Pollard(p-1);
    sort(ALL(ps));
    rep(x,1,inf){
        for(auto& q:ps){
            if(mpow(x,(p-1)/q,p)==1)goto fail;
        }
        return x;
        fail:;
    } assert(0);
}
ll extgcd(ll a,ll b,ll& p,ll& q){
    if(b==0){p=1; q=0; return a;}
    ll d=extgcd(b,a%b,q,p); q-=a/b*p; return d;
}
pair<ll,ll> crt(const vector<ll>& vs,const vector<ll>& ms){
    ll V=vs[0],M=ms[0];
    rep(i,1,vs.size()){
        ll p,q,v=vs[i],m=ms[i];
        if(M<m)swap(M,m),swap(V,v);
        ll d=extgcd(M,m,p,q);
        if((v-V)%d!=0)return {0,-1};
        ll md=m/d,tmp=(v-V)/d%md*p%md;
        V+=M*tmp; M*=md;
    } V=(V%M+M)%M; return {V,M};
}
ll ModLog(ll a,ll b,ll p){
    ll g=1;
    for(ll t=p;t;t>>=1)g=g*a%p;
    g=__gcd(g,p);
    ll t=1,c=0;
    for(;t%g;c++){
        if(t==b)return c;
        t=t*a%p;
        }
    if(b%g)return -1;
    t/=g,b/=g;
    ll n=p/g,h=0,gs=1;
    for(;h*h<n;h++)gs=gs*a%n;
    unordered_map<ll,ll> bs;
    for(ll s=0,e=b;s<h;bs[e]=++s)e=e*a%n;
    for(ll s=0,e=t;s<n;){
        e=e*gs%n,s+=h;
        if(bs.count(e)){
            return c+s-bs[e];
        }
    } return -1;
}

ll _subroot(ll p,int e,ll a,ll m){//x^(p^e)==a(mod m)
    ll q=m-1; int s=0; while(q%p==0){q/=p; s++;} int d=s-e;
    ll pe=mpow(p,e,m),res=mpow(a,((pe-1)*minv(q,pe)%pe*q+1)/pe,m),c=1;
    while(mpow(c,(m-1)/p,m)==1)c++; c=mpow(c,q,m);
    map<ll,ll> mp; ll v=1,block=sqrt(d*p)+1,bs=mpow(c,mpow(p,s-1,m-1)*block%(m-1),m);
    rep(i,0,block+1)mp[v]=i,v=v*bs%m;
    ll gs=minv(mpow(c,mpow(p,s-1,m-1),m),m);
    rep(i,0,d){
        ll err=a*minv(mpow(res,pe,m),m)%m;
        ll pos=mpow(err,mpow(p,d-1-i,m-1),m);
        rep(j,0,block+1){
            if(mp.count(pos)){
                res=res*mpow(c,(block*mp[pos]+j)*mpow(p,i,m-1)%(m-1),m)%m;
                break;
            } pos=pos*gs%m;
        } 
    } return res;
}

ll mod_root(ll k,ll a,ll m){
    if(a==0)return k?0:-1;
    if(m==2)return a&1;
    k%=m-1; ll g=__gcd(k,m-1);
    if(mpow(a,(m-1)/g,m)!=1)return -1;
    a=mpow(a,minv(k/g,(m-1)/g),m);
    for(ll d=2;d*d<=g;d++)if(g%d==0){
        int sz=0;
        while(g%d==0){g/=d; sz++;}
        a=_subroot(d,sz,a,m);
    }
    if(g>1)a=_subroot(g,1,a,m); return a;
}

/**
 * @brief Primitive Function
 */