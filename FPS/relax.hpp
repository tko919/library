#pragma once
#include "FPS/fps.hpp"

template<typename T>class RelaxedConvolution{
    using P=array<int,2>;
    using Q=array<P,2>;
    int N,pos=0;
    vector<vector<Q>> event;
    void dfs1(int L,int R){
        if(R-L==1){
            event[L].push_back({P{L,L+1},P{0,1}});
            return;
        }
        int mid=(L+R)>>1;
        event[mid].push_back({P{L,mid},P{mid-L,R-L}});
        event[R].push_back({P{mid,R},P{mid-L,R-L}});
        dfs1(L,mid);
        dfs1(mid,R);
    }
    void dfs2(int L,int R){
        if(R-L==1){
            event[L].push_back({P{0,1},P{L,L+1}});
            return;
        }
        int mid=(L+R)>>1;
        event[mid].push_back({P{mid-L,R-L},P{L,mid}});
        event[R].push_back({P{mid-L,R-L},P{mid,R}});
        dfs2(L,mid);
        dfs2(mid,R);
    }
    void dfs(int len){
        if(len==1){
            event[0].push_back({P{0,1},P{0,1}});
            return;
        }
        int mid=len>>1;
        event[len].push_back({P{mid,len},P{mid,len}});
        dfs(mid);
        dfs1(mid,len);
        dfs2(mid,len);
    }
public:
    Poly<T> f,g,buf;
    RelaxedConvolution(int n){
        N=1;
        while(N<n)N<<=1;
        f.resize(N);
        g.resize(N);
        buf.resize(N);
        event.resize(N+1);
        dfs(N);
    }
    T next(){
        for(auto& [ft,gt]:event[pos]){
            auto [fL,fR]=ft;
            auto [gL,gR]=gt;
            Poly<T> _f({f.begin()+fL,f.begin()+fR});
            Poly<T> _g({g.begin()+gL,g.begin()+gR});
            auto add=_f*_g;
            rep(i,0,add.size()){
                if(i+fL+gL>=N)break;
                buf[i+fL+gL]+=add[i];
            }
        }
        return buf[pos++];
    }
};

/**
 * @brief Relaxed Convolution
 */