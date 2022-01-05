#pragma once

struct PrimeCount{
    const ll N; const ll M;
    vector<int> lo; vector<ll> hi;
    PrimeCount(const ll& _N):N(_N),M(int(sqrt(N))),lo(M+1),hi(M+1){
        rep(i,1,M+1)lo[i]=i-1,hi[i]=N/i-1;
        int cnt=0;
        for(int p=2;p<=M;p++){
            if(lo[p-1]==lo[p])continue;
            const ll n=N/p;
            const ll q=ll(p)*p;
            const int w=M/p;
            const ll L=min(M,N/q);
            for(int i=1;i<=w;i++)hi[i]-=hi[i*p]-cnt;
            const int t=min<int>(sqrt(n),L);
            for(int i=w+1;i<=t;i++)hi[i]-=lo[n/i]-cnt;
            for(int i=L,j=n/L;i>t;j++){
                int c=lo[j];
                while(j+1<=M and lo[j+1]==c)j++;
                c-=cnt;
                for(int e=max<int>(t,n/(j+1));i>e;i--)hi[i]-=c;
            }
            for(int i=M,j=M/p;j>=p;j--){
                const int c=lo[j]-cnt;
                for(int e=j*p;i>=e;i--)lo[i]-=c;
            }
            cnt++;
        }
    }
    ll pi(ll x){
        if(x<=M)return lo[x];
        else return hi[N/x];
    }
};

/**
 * @brief Prime Count(Lucy's DP)
 */