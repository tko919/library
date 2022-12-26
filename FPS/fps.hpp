#pragma once

template<typename T>struct Poly:vector<T>{
    Poly(int n=0){this->assign(n,T());}
    Poly(const vector<T>& f){this->assign(ALL(f));}
    T eval(const T& x){
        T res;
        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);
        return res;
    }
    Poly rev()const{Poly res=*this; reverse(ALL(res)); return res;}
    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}
    vector<T> mult(const vector<T>& a,const vector<T>& b,bool same=0)const{
        if(a.empty() or b.empty())return vector<T>();
        int n=a.size()+b.size()-1,m=1<<__lg(n*2-1);
        vector<T> res(m);
        rep(i,0,a.size())res[i]=a[i];
        NTT(res,0);
        if(same)rep(i,0,m)res[i]*=res[i];
        else{
            vector<T> c(m);
            rep(i,0,b.size())c[i]=b[i];
            NTT(c,0);
            rep(i,0,m)res[i]*=c[i];
        }
        NTT(res,1);
        res.resize(n);
        return res;
    }
    Poly square()const{return Poly(mult(*this,*this,1));}
    Poly operator-()const{return Poly()-*this;}
    Poly operator+(const Poly& g)const{return Poly(*this)+=g;}
    Poly operator+(const T& g)const{return Poly(*this)+=g;}
    Poly operator-(const Poly& g)const{return Poly(*this)-=g;}
    Poly operator-(const T& g)const{return Poly(*this)-=g;}
    Poly operator*(const Poly& g)const{return Poly(*this)*=g;}
    Poly operator*(const T& g)const{return Poly(*this)*=g;}
    Poly operator/(const Poly& g)const{return Poly(*this)/=g;}
    Poly operator%(const Poly& g)const{return Poly(*this)%=g;}
    Poly& operator+=(const Poly& g){
        if(g.size()>this->size())this->resize(g.size());
        rep(i,0,g.size()){(*this)[i]+=g[i];} return *this;
    }
    Poly& operator+=(const T& g){
        if(this->empty())this->push_back(0);
        (*this)[0]+=g; return *this;
    }
    Poly& operator-=(const Poly& g){
        if(g.size()>this->size())this->resize(g.size());
        rep(i,0,g.size()){(*this)[i]-=g[i];} return *this;
    }
    Poly& operator-=(const T& g){
        if(this->empty())this->push_back(0);
        (*this)[0]-=g; return *this;
    }
    Poly& operator*=(const Poly& g){
        *this=mult(*this,g,0);
        return *this;
    }
    Poly& operator*=(const T& g){
        rep(i,0,this->size())(*this)[i]*=g;
        return *this;
    }
    Poly& operator/=(const Poly& g){
        if(g.size()>this->size()){
            this->clear(); return *this;
        }
        Poly g2=g;
        reverse(ALL(*this));
        reverse(ALL(g2));
        int n=this->size()-g2.size()+1;
        this->resize(n); g2.resize(n);
        *this*=g2.inv(); this->resize(n); 
        reverse(ALL(*this));
        shrink();
        return *this;
    }
    Poly& operator%=(const Poly& g){*this-=*this/g*g; shrink(); return *this;}
    Poly diff()const{
        Poly res(this->size()-1);
        rep(i,0,res.size())res[i]=(*this)[i+1]*(i+1);
        return res;
    }
    Poly inte()const{
        Poly res(this->size()+1);
        for(int i=res.size()-1;i;i--)res[i]=(*this)[i-1]/i;
        return res;
    }
    Poly log()const{
        assert(this->front()==1); const int n=this->size();
        Poly res=diff()*inv(); res=res.inte(); 
        res.resize(n); return res;
    }
    Poly shift(const int& c)const{
        const int n=this->size();
        Poly res=*this,g(n); g[0]=1; rep(i,1,n)g[i]=g[i-1]*c/i;
        vector<T> fact(n,1);
        rep(i,0,n){
            if(i)fact[i]=fact[i-1]*i;
            res[i]*=fact[i];
        }
        res=res.rev();
        res*=g;
        res.resize(n);
        res=res.rev();
        rep(i,0,n)res[i]/=fact[i];
        return res;
    }
    Poly inv()const{
        const int n=this->size();
        Poly res(1); res.front()=T(1)/this->front();
        for(int k=1;k<n;k<<=1){
            Poly f(k*2),g(k*2);
            rep(i,0,min(n,k*2))f[i]=(*this)[i];
            rep(i,0,k)g[i]=res[i];
            NTT(f,0);
            NTT(g,0);
            rep(i,0,k*2)f[i]*=g[i];
            NTT(f,1);
            rep(i,0,k){f[i]=0; f[i+k]=-f[i+k];}
            NTT(f,0);
            rep(i,0,k*2)f[i]*=g[i];
            NTT(f,1);
            rep(i,0,k)f[i]=res[i];
            swap(res,f);
        } res.resize(n); return res;
    }
    Poly exp()const{
        const int n=this->size();
        if(n==1)return Poly({T(1)});
        Poly b(2),c(1),z1,z2(2);
        b[0]=c[0]=z2[0]=z2[1]=1; b[1]=(*this)[1];
        for(int k=2;k<n;k<<=1){
            Poly y=b;
            y.resize(k*2);
            NTT(y,0);
            z1=z2;
            Poly z(k);
            rep(i,0,k)z[i]=y[i]*z1[i];
            NTT(z,1);
            rep(i,0,k>>1)z[i]=0;
            NTT(z,0);
            rep(i,0,k)z[i]*=-z1[i];
            NTT(z,1);
            c.insert(c.end(),z.begin()+(k>>1),z.end());
            z2=c;
            z2.resize(k*2);
            NTT(z2,0);
            Poly x=*this;
            x.resize(k);
            x=x.diff();x.resize(k);
            NTT(x,0);
            rep(i,0,k)x[i]*=y[i];
            NTT(x,1);
            Poly bb=b.diff();
            rep(i,0,k-1)x[i]-=bb[i];
            x.resize(k*2);
            rep(i,0,k-1){x[k+i]=x[i]; x[i]=0;}
            NTT(x,0);
            rep(i,0,k*2)x[i]*=z2[i];
            NTT(x,1);
            x.pop_back();
            x=x.inte();
            rep(i,k,min(n,k*2))x[i]+=(*this)[i];
            rep(i,0,k)x[i]=0;
            NTT(x,0);
            rep(i,0,k*2)x[i]*=y[i];
            NTT(x,1);
            b.insert(b.end(),x.begin()+k,x.end());
        } b.resize(n); return b;
    }
    Poly pow(ll t){
        if(t==0){
            Poly res(this->size()); res[0]=1;
            return res;
        }
        int n=this->size(),k=0; while(k<n and (*this)[k]==0)k++;
        Poly res(n); if(__int128_t(t)*k>=n)return res;
        n-=t*k; Poly g(n); T c=(*this)[k],ic=c.inv();
        rep(i,0,n)g[i]=(*this)[i+k]*ic;
        g=g.log(); for(auto& x:g)x*=t; g=g.exp();
        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c; return res;
    }
    void NTT(vector<T>& a,bool inv)const;
};

/**
 * @brief Formal Power Series (NTT-friendly mod)
 */