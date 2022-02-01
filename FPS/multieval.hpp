#pragma once

template<typename T>struct MultiEval{
    int m,n; vector<Poly<T>> t;
    MultiEval(vector<T>& v){
        m=v.size(),n=1; while(n<m)n<<=1;
        t.resize(n<<1);
        rep(i,0,n){
            T w=(i<m?v[i]:0);
            t[n+i]=Poly<T>({-w,T(1)});
        }
        for(int i=n-1;i;i--)t[i]=t[i*2]*t[i*2+1];
    }
    vector<T> run(const vector<T>& f){
        vector<Poly<T>> c(n*2);
        auto v=t[1].rev();
        v.resize(f.size());
        v=v.inv().rev()*Poly<T>(f);
        v.erase(v.begin(),v.begin()+f.size()-1);
        v.resize(n); reverse(ALL(v)); c[1]=v;
        rep(i,1,n){
            int d=c[i].size();
            rep(k,0,2){
                auto add=t[i*2+(k^1)];
                add.resize(d/2+1);
                add=add.rev();
                add*=c[i];
                add.resize(d);
                c[i*2+k]=vector<T>(add.begin()+d/2,add.end());
            }
        }
        vector<T> res(m); rep(i,0,m)res[i]=c[n+i][0];
        return res;
    }
    vector<T> build(vector<T>& ys){
        auto w=t[1].rev();
        w.resize(m+1);
        auto vs=run(w.rev().diff());
        rep(i,0,m)ys[i]/=vs[i];
        vector<Poly<T>> c(n*2);
        rep(i,0,n){
            if(i<m)c[n+i]=Poly<T>({ys[i]});
            else c[n+i]=Poly<T>({T()});
        }
        for(int i=n-1;i;i--)c[i]=c[i*2]*t[i*2+1]+c[i*2+1]*t[i*2];
        c[1]=vector<T>(c[1].begin()+(n-m),c[1].end());
        c[1].resize(m);
       return c[1];
    }
};

/**
 * @brief Multipoint Evaluation
 */