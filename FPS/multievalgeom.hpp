#pragma once

template<typename T>vector<T> MultievalGeomSeq(vector<T>& f,T a,T w,int m){
    int n=f.size();
    vector<T> tri(n+m-1),itri(n+m-1);
    tri[0]=itri[0]=1;
    T iw=w.inv(),pww=1,pwiw=1;
    for(int i=1;i<n+m-1;i++,pww*=w,pwiw*=iw){
        tri[i]=tri[i-1]*pww;
        itri[i]=itri[i-1]*pwiw;
    }

    Poly<T> y(n),v(n+m-1);
    T pwa=1;
    for(int i=0;i<n;i++,pwa*=a){
        y[i]=f[i]*itri[i]*pwa;
    }
    rep(i,0,n+m-1)v[i]=tri[i];
    reverse(ALL(y));
    y*=v;
    vector<T> ret(m);
    rep(i,0,m)ret[i]=y[n-1+i]*itri[i];
    return ret;
}

/**
 * @brief Multipoint Evaluation on Geometric Sequence
*/