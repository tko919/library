#pragma once

template<class T>struct Matrix{
    int h,w; vector<vector<T>> val; T det;
    Matrix(){}
    Matrix(int n,int m):h(n),w(m),val(vector<vector<T>>(n,vector<T>(m))){}
    vector<T>& operator[](const int i){return val[i];}
    Matrix& operator+=(const Matrix& m){
        rep(i,0,h)rep(j,0,w)val[i][j]+=m.val[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& m){
        rep(i,0,h)rep(j,0,w)val[i][j]-=m.val[i][j];
        return *this;
    }
    Matrix& operator*=(const Matrix& m){
        Matrix<T> res(h,m.w);
        rep(i,0,h)rep(j,0,m.w)rep(k,0,w)res.val[i][j]+=val[i][k]*m.val[k][j];
        *this=res; return *this;
    }
    Matrix operator+(const Matrix& m)const{return Matrix(*this)+=m;}
    Matrix operator-(const Matrix& m)const{return Matrix(*this)-=m;}
    Matrix operator*(const Matrix& m)const{return Matrix(*this)*=m;}
    Matrix pow(ll k){
        Matrix<T> res(h,h),c=*this; rep(i,0,h)res.val[i][i]=1;
        while(k){if(k&1)res*=c; c*=c; k>>=1;} return res;
    }
    vector<int> gauss(int c=-1){
        if(val.empty())return {};
        if(c==-1)c=w;
        int cur=0; vector<int> res; det=1;
        rep(i,0,c){
            if(cur==h)break;
            rep(j,cur,h)if(val[j][i]!=0){
                swap(val[cur],val[j]);
                if(cur!=j)det*=-1;
                break;
            }
            det*=val[cur][i];
            if(val[cur][i]==0)continue;
            rep(j,0,h)if(j!=cur){
                T z=val[j][i]/val[cur][i];
                rep(k,i,w)val[j][k]-=val[cur][k]*z;
            }
            res.push_back(i);
            cur++;
        }
        return res;
    }
    friend istream& operator>>(istream& is,Matrix& m){
        rep(i,0,m.h)rep(j,0,m.w)is>>m[i][j];
        return is;
    }
    friend ostream& operator<<(ostream& os,Matrix& m){
        rep(i,0,m.h){
            rep(j,0,m.w)os<<m[i][j]<<(j==m.w-1 and i!=m.h-1?'\n':' ');
        }
        return os;
    }
};

/**
 * @brief Matrix
 */