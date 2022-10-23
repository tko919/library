#pragma once

template<typename T,bool multi,unsigned L=1010101010>struct Dirichlet{
    ll N,P,Q;
    vector<T> a,rui,A;
    vector<ll> ps;
    bool done=0;
    Dirichlet(ll n):N(n),P(min<ll>(L,cbrt(n)*cbrt(n))),Q((n+P-1)/P),
        a(P+1),rui(P+1),A(Q+1),done(0){}
    const Dirichlet ident(){
        Dirichlet res(N);
        res.a.assign(P+1,0);
        res.a[1]=1;
        res.rui.assign(P+1,1);
        res.A.assign(Q+1,1);
        res.done=1;
        return res;
    }
    void sieve(){
        if(!ps.empty())return;
        static bitset<L> isp;
        rep(p,2,P+1)isp[p]=1;
        for(ll p=2;p*p<=P;p++)if(isp[p]){
            for(ll q=p*p;q<=P;q+=p)isp[q]=0;
        }
        rep(p,2,P+1)if(isp[p])ps.push_back(p);
    }
    void reset(){
        a.assign(P+1,0);
        rui.assign(P+1,0);
        A.assign(Q+1,0);
        done=0;
    }
    void ruith(){
        rui.assign(P+1,0);
        rep(i,1,P+1)rui[i]=rui[i-1]+a[i];
        done=1;
    }
    Dirichlet operator*(const Dirichlet& x){
        assert(done and x.done);
        Dirichlet res(N);
        if(multi){
            sieve();
            res.a=a;
            for(auto& p:ps){
                for(ll i=P/p;i>0;i--){
                    ll n=p*i,q=p,m=i;
                    for(;;){
                        res.a[n]+=x.a[q]*res.a[m];
                        if(m%p)break;
                        q*=p,m/=p;
                    }
                }
            }
        }
        else{
            rep(i,1,P+1)rep(j,1,P/i+1){
                res.a[i*j]+=a[i]*x.a[j];
            }
        }
        res.ruith();
        rep(i,1,Q+1){
            ll n=N/i,M=int(sqrt(n));
            rep(j,1,M+1){
                if(n/j<=P)res.A[i]+=a[j]*x.rui[n/j]+x.a[j]*rui[n/j];
                else res.A[i]+=a[j]*x.A[i*j]+x.a[j]*A[i*j];
                if(M<=P)res.A[i]-=x.a[j]*rui[M];
                else res.A[i]-=x.a[j]*A[N/M];
            }
        }
        return res;
    }
    Dirichlet operator/(const Dirichlet& x){
        assert(done and x.done);
        Dirichlet res=*this;
        if(multi){
            sieve();
            for(auto& p:ps){
                rep(i,1,P/p+1){
                    int n=p*i,q=p,m=i;
                    for(;;){
                        res.a[n]-=x.a[q]*res.a[m];
                        if(m%p)break;
                        q*=p,m/=p;
                    }
                }
            }
        }
        else{
            rep(i,1,P)rep(j,2,P/i+1){
                res.a[i*j]-=res.a[i]*x.a[j];
            }
        }
        res.ruith();
        for(int i=Q;i>0;i--){
            ll n=N/i,M=int(sqrt(n));
            rep(j,1,M+1){
                if(n/j<=P){
                    if(j!=1)res.A[i]-=x.a[j]*res.rui[n/j];
                    res.A[i]-=res.a[j]*x.rui[n/j];
                }
                else{
                    if(j!=1)res.A[i]-=x.a[j]*res.A[i*j];
                    res.A[i]-=res.a[j]*x.A[i*j];
                }
                if(M<=P)res.A[i]+=res.a[j]*x.rui[M];
                else res.A[i]+=res.a[j]*x.A[N/M];
            }
        }
        return res;
    }
    Dirichlet pow(ll t){
        assert(done);
        Dirichlet res=ident(),b=*this;
        while(t){
           if(t&1)res=res*b;
           b=b*b;
           t>>=1;
        }
        return res;
    }
    const T& operator[](ll x){
        assert(done);
        if(x<=P)return rui[x];
        else return A[N/x];
    }
};

/**
 * @brief Dirichlet series
 */