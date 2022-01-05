#pragma once

int chromatic(vector<vector<int>>& a){
    int n=a.size();
    vector<int> es(n);
    rep(i,0,n)rep(j,0,n)if(a[i][j]){
        es[i]|=(1<<j);
    }
    vector<int> dp(1<<n),sign(1<<n);
    dp[0]=1;
    rep(mask,0,1<<n){
        if(mask){
            int v=__builtin_ctz(mask);
            dp[mask]=dp[mask^(1<<v)]+dp[(mask^(1<<v))&(~es[v])];
        }
        sign[mask]=((n-__builtin_popcountll(mask))&1?-1:1);
    }
    int ret=n;
    auto calc=[&](int md)->void{
        vector<ll> cur(ALL(sign));
        rep(k,1,ret){
            int cnt=0;
            rep(mask,0,1<<n){
                cur[mask]=(cur[mask]*dp[mask])%md;
                if(cur[mask]<0)cur[mask]+=md;
                cnt=(cnt+cur[mask])%md;
            }
            if(cnt!=0){
                ret=k;
                break;
            }
        }
    };
    for(auto& md:{998244353,1000000007,1000000011}){
        calc(md);
    }
    return ret;
}

/**
 * @brief Chromatic Number
 */