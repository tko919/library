#pragma once

template<typename M,typename N,M (*f)(M,N),M (*g)(M,int),M (*h)(M,M),M (*e)()>struct Rerooting{
    using P=pair<int,N>;
    vector<vector<P>> G;
    vector<M> buf,ret;
    Rerooting(int n):G(n),buf(n,e()),ret(n){}
    void add_edge(int u,int v,N w){
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    void dfs1(int v,int p){
        for(auto& [to,w]:G[v])if(to!=p){
            dfs1(to,v);
            buf[v]=h(buf[v],f(buf[to],w));
       }
       buf[v]=g(buf[v],v);
    }
    void dfs2(int v,int p,M pc){
        buf[v]=e();
        vector<M> cs;
        for(auto& [to,w]:G[v])if(to!=p){
            cs.push_back(f(buf[to],w));
            buf[v]=h(buf[v],f(buf[to],w));
        }
        buf[v]=g(h(buf[v],pc),v);
        ret[v]=buf[v];
        cs.push_back(pc);
        int m=cs.size();
        vector<M> L(m),R(m);
        rep(i,0,m){
            L[i]=cs[i];
            if(i)L[i]=h(L[i],L[i-1]);
        }
        for(int i=m-1;i>=0;i--){
            R[i]=cs[i];
            if(i!=m-1)R[i]=h(R[i],R[i+1]);
        }
        int id=0;
        for(auto& [to,w]:G[v])if(to!=p){
            M nxt=e();
            if(id!=0)nxt=h(nxt,L[id-1]);
            if(id!=m-1)nxt=h(nxt,R[id+1]);
            M buf_v=buf[v],buf_to=buf[to];
            buf[v]=g(nxt,v);
            M add=f(buf[v],w);
            dfs2(to,v,add);
            buf[v]=buf_v,buf[to]=buf_to;
            id++;
        }
    }
    vector<M> run(){
        dfs1(0,-1);
        dfs2(0,-1,e());
        return ret;
    }
};

/**
 * @brief Rerooting
 * @docs docs/rerooting.md
 */