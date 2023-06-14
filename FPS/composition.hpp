#pragma once

template<typename T>Poly<T> Composition(Poly<T>& p,Poly<T>& q){
    int n=min(p.size(),q.size());
    int m=1;
    while(m*m<n)m++;
    vector pwb(m+1,Poly<T>()),pwg(m+1,Poly<T>());
    pwb[0]=pwg[0]=Poly<T>({T(1)});
    pwb[1]=q;
    rep(i,2,m+1){
        pwb[i]=pwb[i-1]*pwb[1];
        pwb[i].resize(n);
    }
    pwg[1]=pwb[m];
    rep(i,2,m+1){
        pwg[i]=pwg[i-1]*pwg[1];
        pwg[i].resize(n);
    }
    Poly<T> res(n);
    rep(i,0,m+1){
        Poly<T> f;
        rep(j,0,m){
            if(m*i+j<(int)p.size()){
                f+=pwb[j]*p[m*i+j];
            }
        }
        f*=pwg[i];
        f.resize(n);
        res+=f;
    }
    return res;
}

/*
f(x)-t=0

x_{n+1}=x_n-{f(x_n)-t}/{f'(x_n)}
*/

template<typename T>Poly<T> CompositionInv(Poly<T>& f){
    assert(f.size()>=2 and f[0]==0 and f[1]!=0);
    const int n=f.size();
    Poly<T> ret(1),df=f.diff();
    for(int k=1;k<n;k<<=1){
        ret.resize(k*2);
        Poly<T> sub=f;
        sub.resize(k*2);
        sub=Composition(sub,ret);
        sub[1]-=1;
        Poly<T> base=df;
        base.resize(k*2);
        base=Composition(base,ret);
        sub*=base.inv();
        sub.resize(k*2);
        ret-=sub;
    }
    ret.resize(n);
    return ret;
}

/**
 * @brief Composition of Formal Power Series
*/