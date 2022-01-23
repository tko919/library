#pragma once

template<typename T>struct WaveletMatrix{
    struct BitVector{
        vector<unsigned long long> buf;
        vector<int> rui;
        BitVector(const vector<char>& a={}){
            int n=a.size();
            buf.assign((n+63)>>6,0);
            rui.assign(buf.size()+1,0);
            rep(i,0,n)if(a[i]){
                buf[i>>6]|=1ull<<(i&63);
                rui[(i>>6)+1]++;
            }
            rep(i,0,buf.size())rui[i+1]+=rui[i];
        }
        int rank(int k,bool f=1){
            int ret=rui[k>>6]+__builtin_popcountll(buf[k>>6]&((1ull<<(k&63))-1));
            if(!f)return k-ret;
            else return ret;
        }
    };
    int N,lg=0;
    vector<int> mid;
    vector<BitVector> buf;
    WaveletMatrix(vector<T>& a):N(a.size()){
        T mx;
        for(auto& x:a)chmax(mx,x);
        while((T(1)<<lg)<=mx)lg++;
        mid.resize(lg);
        buf.resize(lg);
        for(int d=lg-1;d>=0;d--){
            vector<char> add;
            vector nxt(2,vector<T>());
            for(auto& x:a){
                add.push_back(x>>d&1);
                nxt[x>>d&1].push_back(x);
            }
            mid[d]=(int)nxt[0].size();
            buf[d]=BitVector(add);
            swap(a,nxt[0]);
            a.insert(a.end(),ALL(nxt[1]));
        }
    }
    int rank(int L,int R,T x){
        if((T(1)<<lg)<=x)return 0;
        for(int d=lg-1;d>=0;d--){
            bool f=(x>>d&1);
            L=buf[d].rank(L,f)+(f?mid[d]:0);
            R=buf[d].rank(R,f)+(f?mid[d]:0);
        }
        return R-L;
    }
    T quantile(int L,int R,int k){
        T ret=0;
        for(int d=lg-1;d>=0;d--){
            int l0=buf[d].rank(L,0),r0=buf[d].rank(R,0);
            if(k<r0-l0)L=l0,R=r0;
            else{
                k-=r0-l0;
                ret|=T(1)<<d;
                L+=mid[d]-l0,R+=mid[d]-r0;
            }
        }
        return ret;
    }
    int freq(int L,int R,T x){
        int ret=0;
        for(int d=lg-1;d>=0;d--){
            bool f=(x>>d&1);
            if(f)ret+=buf[d].rank(R,0)-buf[d].rank(L,0);
            L=buf[d].rank(L,f)+(f?mid[d]:0);
            R=buf[d].rank(R,f)+(f?mid[d]:0);
        }
        return ret;
    }
    int freq(int L,int R,T a,T b){
        return freq(L,R,b)-freq(L,R,a);
    }
    T lower_bound(int L,int R,T x){
        int cnt=freq(L,R,x);
        return cnt==R-L?T(-1):quantile(L,R,cnt);
    }
    T upper_bound(int L,int R,T x){
        int cnt=freq(L,R,x);
        return cnt==0?T(-1):quantile(L,R,cnt-1);
    }
};

/**
 * @brief Wavelet Matrix
 */