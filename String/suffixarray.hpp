#pragma once

template<typename T>struct SuffixArray{
    T s;
    vector<int> sa,rev,lcp;
    SuffixArray(const T& _s):s(_s){
        int n=s.size();
        auto p=minmax_element(ALL(s));
        int k=*p.second-*p.first+1;
        vector<int> t(n);
        rep(i,0,n)t[i]=s[i]-*p.first;
        sais(t,k);
        rev.assign(n+1,-1);
        rep(i,0,n+1)rev[sa[i]]=i;
        build(t);
        sa.erase(sa.begin());
    }
    void sais(vector<int> s,int k){
        int n=s.size();
        for(int& c:s)c++;
        s.push_back(0);
        k++;
        vector<bool> iss(n+1);
        vector<int> lms,bin(k+1,0);
        iss[n]=1;
        bin[1]=1;
        for(int i=n-1;i>=0;i--){
            iss[i]=(s[i]!=s[i+1]?s[i]<s[i+1]:iss[i+1]);
            if(!iss[i]&&iss[i+1])lms.push_back(i+1);
            bin[s[i]+1]++;
        }
        rep(i,0,k)bin[i+1]+=bin[i];
        auto induced=[&](const vector<int>& lms){
            sa.assign(n+1,-1);
            vector<int> cnt(k,0);
            for(int x:lms){
                sa[bin[s[x]+1]-cnt[s[x]]-1]=x;
                cnt[s[x]]++;
            }
            cnt.assign(k,0);
            rep(i,0,n+1){
                int x=sa[i]-1;
                if(x>=0&&!iss[x]){
                    sa[bin[s[x]]+cnt[s[x]]]=x;
                    cnt[s[x]]++;
                }
            }
            cnt.assign(k,0);
            for(int i=n;i>=0;i--){
                int x=sa[i]-1;
                if(x>=0&&iss[x]){
                    sa[bin[s[x]+1]-cnt[s[x]]-1]=x;
                    cnt[s[x]]++;
                }
            }
        };
        induced(lms);
        if(lms.size()<=1)return;
        int m=lms.size();
        vector<int> rev(n+1,-1);
        rep(i,0,m)rev[lms[i]]=i;
        int idx=0,rec_k=1;
        vector<int> lmss(m),rec_s(m);
        for(int x:sa)if(rev[x]!=-1)lmss[idx++]=x;
        rec_s[m-1-rev[lmss[1]]]=1;
        rep(i,2,m){
            int xl=lmss[i],yl=lmss[i-1];
            int xr=lms[rev[xl]-1],yr=lms[rev[yl]-1];
            if(xr-xl!=yr-yl)rec_k++;
            else while(xl<=xr){
                if(s[xl]!=s[yl]){
                    rec_k++;
                    break;
                }
                xl++,yl++;
            }
            rec_s[m-1-rev[lmss[i]]]=rec_k;
        }
        sais(rec_s,rec_k+1);
        idx=m;
        rep(i,1,m+1)lmss[--idx]=lms[m-1-sa[i]];
        induced(lmss);
    }
    void build(const vector<int>& s){
        int n=s.size(),k=0;
        lcp.resize(n);
        rep(i,0,n+1){
            if(rev[i]){
                for(int j=sa[rev[i]-1];max(i,j)+k<n;k++){
                    if(s[i+k]!=s[j+k])break;
                }
                lcp[rev[i]-1]=k;
            }
            if(k)k--;
        }
    }
    array<int,2> search(const T& t){
        int n=sa.size()-1,m=t.size();
        array<int,2> ret;
        int L=-1,R=n;
        while(R-L>1){
            int mid=(L+R)>>1;
            if(s.compare(sa[mid],m,t)<0)L=mid;
            else R=mid;
        }
        ret[0]=R;
        L=-1,R=n;
        while(R-L>1){
            int mid=(L+R)>>1;
            if(s.compare(sa[mid],m,t)<=0)L=mid;
            else R=mid;
        }
        ret[1]=R;
        return ret;
    }
};

/**
 * @brief Suffix Array
 */