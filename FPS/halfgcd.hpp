#pragma once

namespace HalfGCD{
    template<typename T>using P=array<T,2>;
    template<typename T>using Mat=array<T,4>;
    template<typename T>P<T> operator*(const Mat<T>& a,const P<T>& b){
        P<T> ret={a[0]*b[0]+a[1]*b[1],a[2]*b[0]+a[3]*b[1]};
        rep(i,0,2)ret[i].shrink();
        return ret;
    }
    template<typename T>Mat<T> operator*(const Mat<T>& a,const Mat<T>& b){
        Mat<T> ret={a[0]*b[0]+a[1]*b[2],a[0]*b[1]+a[1]*b[3],
            a[2]*b[0]+a[3]*b[2],a[2]*b[1]+a[3]*b[3]};
        rep(i,0,4)ret[i].shrink();
        return ret;
    }
    
    template<typename T>Mat<T> HGCD(P<T> a){
        int m=(SZ(a[0])+1)>>1;
        if(SZ(a[1])<=m){
            Mat<T> ret;
            ret[0]={1},ret[3]={1};
            return ret;
        }
        auto R=HGCD(P<T>{a[0]>>m,a[1]>>m});
        a=R*a;
        if(SZ(a[1])<=m)return R;
        Mat<T> Q;
        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);
        R=Q*R,a=Q*a;
        if(SZ(a[1])<=m)return R;
        int k=2*m+1-SZ(a[0]);
        auto H=HGCD(P<T>{a[0]>>k,a[1]>>k});
        return H*R;
    }
    template<typename T>Mat<T> InnerGCD(P<T> a){
        if(SZ(a[0])<SZ(a[1])){
            auto M=InnerGCD(P<T>{a[1],a[0]});
            swap(M[0],M[1]);
            swap(M[2],M[3]);
            return M;
        }
        auto m0=HGCD(a);
        a=m0*a;
        if(a[1].empty())return m0;
        Mat<T> Q;
        Q[1]={1},Q[2]={1},Q[3]=-(a[0]/a[1]);
        m0=Q*m0,a=Q*a;
        if(a[1].empty())return m0;
        return InnerGCD(a)*m0;
    }
    template<typename T>T gcd(const T& a,const T& b){
        P<T> p({a,b});
        auto M=InnerGCD(p);
        p=M*p;
        if(!p[0].empty()){
            auto coeff=p[0].back().inv();
            for(auto& x:p[0])x*=coeff;
        }
        return p[0];
    }
    template<typename T>pair<bool,T> PolyInv(const T& a,const T& b){
        P<T> p({a,b});
        auto M=InnerGCD(p);
        T g=(M*p)[0];
        if(g.size()!=1)return {false,{}};
        P<T> x({T({1}),b});
        auto ret=(M*x)[0]%b;
        auto coeff=g[0].inv();
        for(auto& x:ret)x*=coeff;
        return {true,ret};
    }
}

/**
 * @brief Half GCD
*/