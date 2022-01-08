#pragma once

ll mpow(ll a,ll t,ll m){
    ll res=1;
    while(t){
        if(t&1)res=(res*a)%m;
        a=(a*a)%m; t>>=1;
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
    vector<ll> ds;
    for(ll x=1;x*x<=p-1;x++)if((p-1)%x==0){
        ds.push_back(x);
        if(x*x!=p-1)ds.push_back((p-1)/x);
    }
    sort(ALL(ds));
    ds.pop_back();
    for(int x=1;x<p;x++){
        for(auto& d:ds){
            if(mpow(x,d,p)==1)goto fail;
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

/**
 * @brief Primitive Function
 */