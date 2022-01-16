#pragma once

struct Segtreebeats{
    struct state{
        ll maxx=-INF,smax=-INF,cmax=0,lmax=-INF;
        ll minn=INF,smin=INF,cmin=0,lmin=INF;
        ll sum=0,add=0; int len=1;
        state(){}
        state(ll val):maxx(val),cmax(1),minn(val),cmin(1),sum(val){}
    };
    int n; vector<state> val;
    Segtreebeats(int _n):Segtreebeats(vector<ll>(_n,0)){}
    Segtreebeats(const vector<ll>& a){
        for(n=1;n<(int)a.size();n<<=1);
        val.assign(2*n,state());
        rep(i,0,a.size())val[i+n]=state(a[i]);
        for(int i=n-1;i;i--)apply(i);
    }
    void apply(int k){
        state &x=val[k],&lb=val[2*k],&rb=val[2*k+1];
        if(lb.minn<rb.minn)x.minn=lb.minn,x.cmin=lb.cmin,x.smin=min(lb.smin,rb.minn);
        else if(lb.minn>rb.minn)x.minn=rb.minn,x.cmin=rb.cmin,x.smin=min(rb.smin,lb.minn);
        else x.minn=lb.minn,x.cmin=lb.cmin+rb.cmin,x.smin=min(lb.smin,rb.smin);
        if(lb.maxx>rb.maxx)x.maxx=lb.maxx,x.cmax=lb.cmax,x.smax=max(lb.smax,rb.maxx);
        else if(lb.maxx<rb.maxx)x.maxx=rb.maxx,x.cmax=rb.cmax,x.smax=max(rb.smax,lb.maxx);
        else x.maxx=lb.maxx,x.cmax=lb.cmax+rb.cmax,x.smax=max(lb.smax,rb.smax);
        x.len=lb.len+rb.len; x.sum=lb.sum+rb.sum;
    }
    void eval(int k){
        state &x=val[k],&lb=(k<n?val[2*k]:val[0]),&rb=(k<n?val[2*k+1]:val[0]);
        if(x.add){
            if(lb.lmax!=-INF)lb.lmax+=x.add;
            if(lb.lmin!=INF)lb.lmin+=x.add;
            if(rb.lmax!=-INF)rb.lmax+=x.add;
            if(rb.lmin!=INF)rb.lmin+=x.add;
            lb.add+=x.add; rb.add+=x.add;
            x.minn+=x.add;
            if(x.smin!=INF)x.smin+=x.add;
            x.maxx+=x.add;
            if(x.smax!=-INF)x.smax+=x.add;
            x.sum+=x.len*x.add; x.add=0;
        }
        if(x.lmax!=-INF){
            chmax(lb.lmax,x.lmax);
            chmax(lb.lmin,x.lmax);
            chmax(rb.lmax,x.lmax);
            chmax(rb.lmin,x.lmax);
            if(x.lmax>=x.smin){eval(k*2); eval(k*2+1); apply(k);}
            else if(x.lmax>x.minn){
                x.sum+=x.cmin*(x.lmax-x.minn);
                if(x.smax==x.minn)x.smax=x.lmax;
                if(x.maxx==x.minn)x.maxx=x.lmax;
                x.minn=x.lmax;
            } x.lmax=-INF;
        }
        if(x.lmin!=INF){
            chmin(lb.lmax,x.lmin);
            chmin(lb.lmin,x.lmin);
            chmin(rb.lmax,x.lmin);
            chmin(rb.lmin,x.lmin);
            if(x.lmin<=x.smax){eval(k*2); eval(k*2+1); apply(k);}
            else if(x.lmin<x.maxx){
                x.sum+=x.cmax*(x.lmin-x.maxx);
                if(x.smin==x.maxx)x.smin=x.lmin;
                if(x.minn==x.maxx)x.minn=x.lmin;
                x.maxx=x.lmin;
            } x.lmin=INF;
        }
    }
    void range_add(int a,int b,ll c,int k=1,int l=0,int r=-1){
        if(r<0)r=n; eval(k);
        if(b<=l||a>=r)return;
        if(b>=r&&a<=l){
            val[k].add=c; eval(k);
        }else{
            range_add(a,b,c,k*2,l,(l+r)/2);
            range_add(a,b,c,k*2+1,(l+r)/2,r);
            apply(k);
        }
    }
    void range_chmin(int a,int b,ll c,int k=1,int l=0,int r=-1){
        if(r<0)r=n; eval(k);
        if(b<=l||a>=r)return;
        if(b>=r&&a<=l){
            val[k].lmin=c; eval(k);
        }else{
            range_chmin(a,b,c,k*2,l,(l+r)/2);
            range_chmin(a,b,c,k*2+1,(l+r)/2,r);
            apply(k);
        }
    }
    void range_chmax(int a,int b,ll c,int k=1,int l=0,int r=-1){
        if(r<0)r=n; eval(k);
        if(b<=l||a>=r)return;
        if(b>=r&&a<=l){
            val[k].lmax=c; eval(k);
        }else{
            range_chmax(a,b,c,k*2,l,(l+r)/2);
            range_chmax(a,b,c,k*2+1,(l+r)/2,r);
            apply(k);
        }
    }
    ll query_max(int a,int b,int k=1,int l=0,int r=-1){
        if(r<0)r=n; eval(k);
        if(b<=l||a>=r)return -INF;
        if(b>=r&&a<=l)return val[k].maxx;
        else{
            ll res=max(query_max(a,b,k*2,l,(l+r)/2),query_max(a,b,k*2+1,(l+r)/2,r));
            return res;
        }
    }
    ll query_min(int a,int b,int k=1,int l=0,int r=-1){
        if(r<0)r=n; eval(k);
        if(b<=l||a>=r)return INF;
        if(b>=r&&a<=l)return val[k].minn;
        else{
            ll res=min(query_min(a,b,k*2,l,(l+r)/2),query_min(a,b,k*2+1,(l+r)/2,r));
            return res;
        }
    }
    ll query_sum(int a,int b,int k=1,int l=0,int r=-1){
        if(r<0)r=n; eval(k);
        if(b<=l||a>=r)return 0;
        if(b>=r&&a<=l)return val[k].sum;
        else{
            ll res=query_sum(a,b,k*2,l,(l+r)/2)+query_sum(a,b,k*2+1,(l+r)/2,r);
            return res;
        }
    }
};

/**
 * @brief Segment Tree Beats
 */