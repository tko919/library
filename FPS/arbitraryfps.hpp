#pragma once

template<typename T,vector<T> (*mult)(vector<T>&,vector<T>&,bool)>struct Poly:vector<T>{
    Poly(int n=0){this->assign(n,T());}
    Poly(const vector<T>& f){this->assign(ALL(f));}
    T eval(const T& x){
        T res;
        for(int i=this->size()-1;i>=0;i--)res*=x,res+=this->at(i);
        return res;
    }
    Poly rev()const{Poly res=*this; reverse(ALL(res)); return res;}
    void shrink(){while(!this->empty() and this->back()==0)this->pop_back();}
    Poly inv()const{
        assert(this->front()!=0); const int n=this->size();
        Poly res(1); res.front()=T(1)/this->front();
        for(int k=1;k<n;k<<=1){
            Poly g=res,h=*this; h.resize(k*2); res.resize(k*2);
            g=(g.square()*h); g.resize(k*2);
            rep(i,k,min(k*2,n))res[i]-=g[i];
        }
        res.resize(n); return res;
    }
    Poly square()const{return Poly(mult(*this,*this,1));}
    Poly operator+(const Poly& g)const{return Poly(*this)+=g;}
    Poly operator-(const Poly& g)const{return Poly(*this)-=g;}
    Poly operator*(const Poly& g)const{return Poly(*this)*=g;}
    Poly operator/(const Poly& g)const{return Poly(*this)/=g;}
    Poly operator%(const Poly& g)const{return Poly(*this)%=g;}
    Poly& operator+=(const Poly& g){
        if(g.size()>this->size())this->resize(g.size());
        rep(i,0,g.size()){(*this)[i]+=g[i];} shrink(); return *this;
    }
    Poly& operator-=(const Poly& g){
        if(g.size()>this->size())this->resize(g.size());
        rep(i,0,g.size()){(*this)[i]-=g[i];} shrink(); return *this;
    }
    Poly& operator*=(const Poly& g){
        *this=mult(*this,g,0);
        shrink(); return *this;
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
        shrink(); return *this;
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
    Poly exp()const{
        assert(this->front()==0); const int n=this->size();
        Poly res(1),g(1); res.front()=g.front()=1;
        for(int k=1;k<n;k<<=1){
            g=(g+g-g.square()*res); g.resize(k);
            Poly q=*this; q.resize(k); q=q.diff();
            Poly w=(q+g*(res.diff()-res*q)),t=*this;
            w.resize(k*2-1); t.resize(k*2);
            res=(res+res*(t-w.inte())); res.resize(k*2);
        } res.resize(n); return res;
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
    Poly pow(ll t){
        int n=this->size(),k=0; while(k<n and (*this)[k]==0)k++;
        Poly res(n); if(t*k>=n)return res;
        n-=t*k; Poly g(n); T c=(*this)[k],ic=T(1)/c;
        rep(i,0,n)g[i]=(*this)[i+k]*ic;
        g=g.log(); for(auto& x:g)x*=t; g=g.exp(); 
        c=c.pow(t); rep(i,0,n)res[i+t*k]=g[i]*c; return res;
    }
};

/**
 * @brief Formal Power Series (Arbitrary mod)
 */