#pragma once

template<typename T,unsigned p=3>struct NTT{
    vector<T> rt,irt;
    NTT(int lg=21){
        unsigned m=T::get_mod()-1; T prt=p;
        rt.resize(lg); irt.resize(lg);
        rep(k,0,lg){
            rt[k]=-prt.pow(m>>(k+2));
            irt[k]=rt[k].inv();
        }
    }
    void ntt(vector<T>& f,bool inv=0){
        int n=f.size();
        if(inv){
            for(int m=1;m<n;m<<=1){ T w=1;
                for(int s=0,t=0;s<n;s+=m*2){
                    for(int i=s,j=s+m;i<s+m;i++,j++){
                        auto x=f[i],y=f[j];
                        f[i]=x+y; f[j]=(x-y)*w;
                    } w*=irt[__builtin_ctz(++t)];
                }
             } T mul=T(n).inv(); rep(i,0,n)f[i]*=mul;
        }else{
            for(int m=n;m>>=1;){ T w=1;
                for(int s=0,t=0;s<n;s+=m*2){
                    for(int i=s,j=s+m;i<s+m;i++,j++){
                        auto x=f[i],y=f[j]*w;
                        f[i]=x+y; f[j]=x-y;
                    } w*=rt[__builtin_ctz(++t)];
                }
            }
         }
    }
    vector<T> mult(const vector<T>& a,const vector<T>& b,bool same=0){
        if(a.empty() or b.empty())return vector<T>();
        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);
        vector<T> res(m); rep(i,0,a.size()){res[i]=a[i];} ntt(res);
        if(same)rep(i,0,m)res[i]*=res[i];
        else{
            vector<T> c(m); rep(i,0,b.size())c[i]=b[i];
            ntt(c); rep(i,0,m)res[i]*=c[i];
        } ntt(res,1); res.resize(n); return res;
    }
};

/**
 * @brief Number Theoretic Transform
 */