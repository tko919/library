#pragma once
#include "DataStructure/wavelet.hpp"

struct RangeLIS{
    WaveletMatrix<int> wm;
    int N;
    RangeLIS(vector<int> p){
        N=1;
        while(N<int(p.size()))N<<=1;
        rep(i,p.size(),N)p.push_back(i);
        auto init=seaweed(p);
        wm=WaveletMatrix<int>(init);
    }
    int query(int L,int R){
        if(L>=R)return 0;
        return R-L-wm.freq(0,R,L,N);
    }
private:
    vector<int> seaweed(const vector<int>& p){
        int n=p.size();
        if(n==1)return {inf};
        vector<int> lo,hi,lpos,hpos;
        rep(i,0,n){
            if(p[i]<n/2){
                lo.push_back(p[i]);
                lpos.push_back(i);
            }
            else{
                hi.push_back(p[i]-n/2);
                hpos.push_back(i);
            }
        }
        auto x=seaweed(lo),y=seaweed(hi);
        vector<int> s(n),t(n);
        iota(ALL(s),0);
        iota(ALL(t),0);
        int xi=0,yi=0;
        rep(i,0,n){
            if(p[i]<n/2){
                if(x[xi]==inf)s[i]=inf;
                else s[i]=lpos[x[xi]];
                xi++;
            }
            else{
                if(y[yi]==inf)t[i]=inf;
                else t[i]=hpos[y[yi]];
                yi++;
            }
        }
        vector<int> a(n,inf),b(n);
        vector<int> revs(n,inf);
        rep(i,0,n)if(s[i]!=inf)revs[s[i]]=i;
        int pos=n-1;
        vector<int> tos(n,inf),tot(n,inf);
        for(int i=n-1;i>=0;i--)if(revs[i]!=inf){
            a[revs[i]]=pos;
            tos[pos--]=i;
        }
        rep(i,0,n)if(a[i]==inf)a[i]=pos--;
        pos=0;
        vector<int> used(n);
        rep(i,0,n)if(t[i]!=inf){
            b[pos]=t[i];
            tot[pos++]=i;
            used[t[i]]=1;
        }
        rep(i,0,n)if(!used[i]){
            b[pos++]=i;
        }
        auto c=squaredot(a,b);
        vector<int> res(n,inf);
        rep(i,0,n)if(tot[i]!=inf and tos[c[i]]!=inf){
            res[tot[i]]=tos[c[i]];
        }
        return res;
    }
    vector<int> squaredot(const vector<int>& a,const vector<int>& b){
        int n=a.size();
        if(n==1)return {0};
        vector<int> alo,ahi,blo,bhi;
        vector<int> inva(n);
        rep(i,0,n)inva[a[i]]=i;
        int aloi=0,ahii=0;
        vector<int> azip(n),alov,ahiv;
        rep(i,0,n){
            if(inva[i]<n/2){
                azip[inva[i]]=aloi++;
                alov.push_back(i);
            }
            else{
                azip[inva[i]]=ahii++;
                ahiv.push_back(i);
            }
            if(b[i]<n/2)blo.push_back(b[i]);
            else bhi.push_back(b[i]-n/2);
        }
        rep(i,0,n){
            if(i<n/2)alo.push_back(azip[i]);
            else ahi.push_back(azip[i]);
        }
        auto sublo=squaredot(alo,blo);
        auto subhi=squaredot(ahi,bhi);
        vector<int> clo(n,inf),chi(n,inf),res(n,inf);
        int subloi=0,subhii=0;
        rep(i,0,n){
            if(b[i]<n/2)clo[i]=alov[sublo[subloi++]];
            else chi[i]=ahiv[subhi[subhii++]];
        }
        vector<int> invclo(n,inf),invchi(n,inf);
        rep(i,0,n){
            if(clo[i]!=inf)invclo[clo[i]]=i;
            if(chi[i]!=inf)invchi[chi[i]]=i;
        }
        int cloi=n,cloj=-1,chii=n,chij=-1;
        int ldelta=0,hdelta=0;
        for(;;){
            if(cloi<0 and chij>=n)break;
            if(ldelta>0){
                cloj++;
                if(cloj<n and chi[cloj]!=inf and chi[cloj]<cloi)ldelta--;
                if(cloj<n and clo[cloj]!=inf and clo[cloj]>=cloi)ldelta--;
            }
            else{
                cloi--;
                if(cloi>=0 and invchi[cloi]!=inf and invchi[cloi]<=cloj)ldelta++;
                if(cloi>=0 and invclo[cloi]!=inf and invclo[cloi]>cloj)ldelta++;
            }
            if(cloj<n and clo[cloj]!=inf and clo[cloj]<=cloi)res[cloj]=clo[cloj];
            if(hdelta>=0){
                chij++;
                if(chij<n and chi[chij]!=inf and chi[chij]<chii)hdelta--;
                if(chij<n and clo[chij]!=inf and clo[chij]>=chii)hdelta--;
            }
            else{
                chii--;
                if(chii>=0 and invchi[chii]!=inf and invchi[chii]<=chij)hdelta++;
                if(chii>=0 and invclo[chii]!=inf and invclo[chii]>chij)hdelta++;
            }
            if(chij<n and chi[chij]!=inf and chi[chij]>=chii)res[chij]=chi[chij];
            if(cloi==chii and cloj==chij)res[cloj]=cloi;
        }
        return res;
    }
};

/**
 * @brief Range LIS Query
 */