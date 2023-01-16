#pragma once

template<typename T>Poly<T> ProdOf_f_rk_x(Poly<T>& f,T r,int m){ // f(x)f(rx)...f(r^{m-1}x)
    assert(f[0]==1);
    T pwr=1,rm=T(r).pow(m),pwrm=1;
    auto g=f.log();
    rep(i,1,g.size()){
        pwr*=r;
        pwrm*=rm;
        if(pwr==1)g[i]*=m;
        else g[i]*=(pwrm-1)/(pwr-1);
    }
    return g.exp();
}

/**
 * @brief $\Pi_{k=0}^{m-1} f(r^kx)$
*/