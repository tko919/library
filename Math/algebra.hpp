#pragma once

template<typename T,T (*add)(T, T),T (*sub)(T, T),T (*e0)()>struct Abel{
    T v;
    Abel(T _v=e0()):v(_v){}
    static T id0(){return e0();}
    Abel& operator+=(const Abel& x){return *this=add(v,x.v);}
    Abel& operator-=(const Abel& x){return *this=sub(v,x.v);}
    Abel operator+(const Abel& x)const{return Abel(*this)+=x;}
    Abel operator-(const Abel& x)const{return Abel(*this)-=x;}
    bool operator==(const Abel &x)const{return v==x.v;}
    bool operator!=(const Abel &x)const{return v!=x.v;}
};

template<typename T,T (*add)(T, T),T (*mul)(T, T),T (*e0)(),T (*e1)()>struct Semiring{
    T v;
    Semiring(T _v=e0()):v(_v){}
    static T id0(){return e0();}
    static T id1(){return e1();}    
    Semiring& operator+=(const Semiring& x){return *this=add(v,x.v);}
    Semiring& operator*=(const Semiring& x){return *this=mul(v,x.v);}
    Semiring operator+(const Semiring& x)const{return Semiring(*this)+=x;}
    Semiring operator*(const Semiring& x)const{return Semiring(*this)*=x;}
    bool operator==(const Semiring &x)const{return v==x.v;}
    bool operator!=(const Semiring &x)const{return v!=x.v;}
};

template<class T>struct Matrix{
    int h,w;
    vector<vector<T>> val;
    Matrix(){}
    Matrix(int n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m,T::id0()))){}
    vector<T>& operator[](const int i){return val[i];}
    Matrix& operator+=(const Matrix& m){
        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];
        return *this;
    }
    Matrix& operator*=(const Matrix& m){
        Matrix<T> res(h,m.w);
        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];
        *this=res; return *this;
    }
    Matrix operator+(const Matrix& m)const{return Matrix(*this)+=m;}
    Matrix operator*(const Matrix& m)const{return Matrix(*this)*=m;}
    Matrix pow(ll k){
        Matrix<T> res(h,h),c=*this;
        rep(i,0,h)res.val[i][i]=T::id1();
        while(k){
            if(k&1)res*=c;
            c*=c;
            k>>=1;
        }
        return res;
    }
};

/**
 * @brief Semiring
 */