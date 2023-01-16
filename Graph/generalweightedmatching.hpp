#pragma once

// reference: http://www.cs.kent.edu/~dragan/GraphAn/p23-galil.pdf
class GeneralWeightedMatching{
    struct E{int u,v; ll w;};
    int n,m,in;
    vector<vector<E>> G;
    vector<int> mate,slack,root,par,isS,used;
    vector<vector<int>> flower,belong;
    vector<ll> dual;
    queue<int> que;
    
    ll dist(const E& e){return dual[e.u]+dual[e.v]-e.w;}
    void update(int u,int v){
        if(!slack[v] or dist(G[u][v])<dist(G[slack[v]][v]))slack[v]=u;
    }
    void recalc(int v){
        slack[v]=0;
        rep(i,1,n+1)if(G[i][v].w and root[i]!=v and isS[root[i]]==1)update(i,v);
    }
    void push(int v){
        if(v<=n)que.push(v);
        else for(auto& nxt:flower[v])push(nxt);
    }
    void set(int v,int rt){
        root[v]=rt;
        if(v>n)for(auto& nxt:flower[v])set(nxt,rt);
    }
    int findeven(int b,int v){
        int pos=find(ALL(flower[b]),v)-flower[b].begin();
        if(pos&1){
            reverse(flower[b].begin()+1,flower[b].end());
            pos=flower[b].size()-pos;
        }
        return pos;
    }
    void match(int u,int v){
        mate[u]=G[u][v].v;
        if(u>n){
            int x=belong[u][G[u][v].u];
            int pos=findeven(u,x);
            rep(i,0,pos)match(flower[u][i],flower[u][i^1]);
            match(x,v);
            rotate(flower[u].begin(),flower[u].begin()+pos,flower[u].end());
        }
    }
    void link(int u,int v){
        for(;;){
            int nv=root[mate[u]];
            match(u,v);
            if(!nv)break;
            v=nv,u=root[par[nv]];
            match(v,u);
        }
    }
    void make(int u,int v,int lca){
        int id=n+1;
        while(id<=m and root[id])id++;
        if(id>m)m++;
        flower[id].clear();
        rep(i,1,m+1)G[id][i].w=G[i][id].w=0;
        rep(i,1,n+1)belong[id][i]=0;
        isS[id]=1,dual[id]=0,mate[id]=mate[lca];
        while(u!=lca){
            flower[id].push_back(u);
            u=root[mate[u]];
            push(u);
            flower[id].push_back(u);
            u=root[par[u]];
        }
        flower[id].push_back(lca);
        reverse(ALL(flower[id]));
        while(v!=lca){
            flower[id].push_back(v);
            v=root[mate[v]];
            push(v);
            flower[id].push_back(v);
            v=root[par[v]];
        }
        set(id,id);
        for(auto& c:flower[id]){
            rep(i,1,m+1)if(!G[id][i].w or dist(G[c][i])<dist(G[id][i])){
                G[id][i]=G[c][i],G[i][id]=G[i][c];
            }
            rep(i,1,n+1)if(belong[c][i])belong[id][i]=c;
        }
        recalc(id);
    }
    void expand(int b){
        for(auto& c:flower[b])set(c,c);
        int x=belong[b][G[b][par[b]].u];
        isS[x]=2,par[x]=par[b];
        int pos=findeven(b,x);
        for(int i=0;i<pos;i+=2){
            int T=flower[b][i],S=flower[b][i+1];
            isS[S]=1,isS[T]=2;
            par[T]=G[S][T].u;
            slack[S]=slack[T]=0;
            push(S);
        }
        rep(i,pos+1,flower[b].size()){
            isS[flower[b][i]]=0;
            recalc(flower[b][i]);
        }
        flower[b].clear();
        root[b]=0;
    }
    bool path(const E& e){
        int u=root[e.u],v=root[e.v];
        if(!isS[v]){
            par[v]=e.u;
            isS[v]=2;
            int nu=root[mate[v]];
            slack[v]=slack[nu]=0;
            isS[nu]=1;
            push(nu);
        }
        else if(isS[v]==1){
            int lca=0,bu=u,bv=v;
            in++;
            while(bu){
                used[bu]=in;
                bu=root[mate[bu]];
                if(bu)bu=root[par[bu]];
            }
            while(bv){
                if(used[bv]==in){
                    lca=bv;
                    break;
                }
                bv=root[mate[bv]];
                if(bv)bv=root[par[bv]];
            }
            if(lca)make(u,v,lca);
            else{
                link(u,v),link(v,u);
                return true;
            }
        }
        return false;
    }
    bool augment(){
        isS=slack=par=vector<int>(n*2);
        que=queue<int>();
        rep(i,1,m+1)if(root[i]==i and !mate[i]){
            isS[i]=1;
            push(i);
        }
        if(que.empty())return false;
        for(;;){
            while(!que.empty()){
                int v=que.front();
                que.pop();
                rep(i,1,n+1)if(G[v][i].w and root[i]!=root[v]){
                    if(!dist(G[v][i])){
                        if(path(G[v][i]))return true;
                    }
                    else if(isS[root[i]]!=2)update(v,root[i]);
                }
            }
            ll delta=INF;
            rep(i,n+1,m+1)if(root[i]==i and isS[i]==2)chmin(delta,dual[i]/2);
            rep(i,1,m+1)if(root[i]==i and slack[i] and isS[i]!=2){
                if(!isS[i])chmin(delta,dist(G[slack[i]][i]));
                else chmin(delta,dist(G[slack[i]][i])/2);
            }
            rep(i,1,n+1){
                if(isS[root[i]]==1){
                    dual[i]-=delta;
                    if(dual[i]<=0)return false;
                }
                else if(isS[root[i]]==2)dual[i]+=delta;
            }
            rep(i,n+1,m+1)if(root[i]==i and isS[i]){
                if(isS[i]==1)dual[i]+=delta*2;
                else dual[i]-=delta*2;
            }
            rep(i,1,m+1)if(root[i]==i and slack[i] and root[slack[i]]!=i){
                if(dist(G[slack[i]][i])==0 and path(G[slack[i]][i]))return true;
            }
            rep(i,n+1,m+1)if(root[i]==i and isS[i]==2 and dual[i]==0)expand(i);
        }
    }
public:
    GeneralWeightedMatching(int _n):n(_n),m(n),in(0),G(n*2,vector<E>(n*2)),
        mate(n*2),root(n*2),used(n*2),flower(n*2),belong(n*2,vector<int>(n*2)),dual(n*2){
        rep(i,0,n+1){
            root[i]=i;
            belong[i][i]=i;
            if(i)dual[i]=INF;
            rep(j,0,n+1)G[i][j]=E{i,j,0};
        }
    }
    void add_edge(int u,int v,ll w){
        u++,v++;
        chmax(G[u][v].w,w*2);
        chmax(G[v][u].w,w*2);
    }
    vector<int> run(){
        while(augment());
        vector<int> res(n,-1);
        rep(i,1,n+1)if(mate[i])res[i-1]=mate[i]-1;
        return res;
    }
};

/**
 * @brief General Weighted Matching
*/