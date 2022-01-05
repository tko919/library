#pragma once

template<typename Flow,typename Cost,int type=1>class MinCostFlow{ //Maximize=-1
    struct ptr{int v_id,e_id;};
    struct edge{
        int from,to; Flow flow,cap; Cost weight; int rev;
        edge(int _f,int _t,Flow _c,Cost _w,int _r)
            :from(_f),to(_t),flow(0),cap(_c),weight(_w),rev(_r){}
        Flow residual_cap()const{return cap-flow;}
    };
    int n; vector<vector<edge>> g;
    vector<Flow> b,pot; vector<ptr> es;
    Cost farthest; vector<Cost> dist; vector<edge*> par;
    vector<int> exc,def;
    void push(edge& e,Flow amount){
        e.flow+=amount; g[e.to][e.rev].flow-=amount;
    }
    Cost residual_cost(int from,int to,edge& e){
        return e.weight+pot[from]-pot[to];
    }
    bool dual(const Flow& delta){
        dist.assign(n,numeric_limits<Cost>::max()); par.assign(n,nullptr);
        exc.erase(remove_if(ALL(exc),[&](int v){return b[v]<delta;}),exc.end());
        def.erase(remove_if(ALL(def),[&](int v){return b[v]>-delta;}),def.end());
        priority_queue<pair<Cost,int>,vector<pair<Cost,int>>,greater<>> pq;
        for(auto& v:exc)pq.push({dist[v]=0,v});
        farthest=0; int def_cnt=0;
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            if(dist[u]<d)continue;
            farthest=d;
            if(b[u]<=-delta)def_cnt++;
            if(def_cnt>=(int)def.size())break;
            for(auto& e:g[u]){
                if(e.residual_cap()<delta)continue;
                int v=e.to; Cost nd=d+residual_cost(u,v,e);
                if(nd>=dist[v])continue;
                pq.push({dist[v]=nd,v}); par[v]=&e;
            }
        }
        rep(v,0,n)pot[v]+=min(dist[v],farthest);
        return def_cnt>0;
    }
    void primal(const Flow& delta){
        for(auto& t:def){
            if(dist[t]>farthest)continue;
            Flow f=-b[t]; int v;
            for(v=t;par[v]!=nullptr;v=par[v]->from){
                chmin(f,par[v]->residual_cap());
            }
            chmin(f,b[v]); f-=f%delta;
            if(f<=0)continue;
            for(v=t;par[v]!=nullptr;){
                auto& e=*par[v];
                push(e,f);
                int u=par[v]->from;
                if(e.residual_cap()<=0)par[v]=nullptr;
                v=u;
            }
            b[t]+=f; b[v]-=f;
        }
    }
public:
    MinCostFlow(int _n):n(_n),g(_n),b(_n),pot(_n){}
    void add_edge(int from,int to,Flow lb,Flow ub,Cost cost){
        int f_id=g[from].size(),t_id=(from==to?f_id+1:g[to].size());
        g[from].push_back(edge(from,to,ub,cost*type,t_id));
        g[to].push_back(edge(to,from,-lb,-cost*type,f_id));
        es.push_back(ptr{from,f_id});
    }
    void add_supply(int v,Flow amount){b[v]+=amount;}
    void add_demand(int v,Flow amount){b[v]-=amount;}
    Flow get_pot(int v){return pot[v];}
    Flow get_flow(int v){return g[es[v].v_id][es[v].e_id].flow;}
    template<typename T=ll>pair<bool,T> run(const Flow& sf=2){
        Flow max_flow=1;
        for(auto& t:b)chmax(max_flow,abs(t));
        for(auto& es:g)for(auto& e:es)chmax(max_flow,abs(e.residual_cap()));
        Flow delta=1;
        while(delta<max_flow)delta*=sf;
        for(;delta;delta/=sf){
            for(auto& es:g)for(auto& e:es){
                Flow rcap=e.residual_cap();
                rcap-=rcap%delta;
                Cost rcost=residual_cost(e.from,e.to,e);
                if(rcost<0 or rcap<0){
                    push(e,rcap);
                    b[e.from]-=rcap; b[e.to]+=rcap;
                }
            }
            rep(v,0,n)if(b[v]!=0){
                (b[v]>0?exc:def).push_back(v);
            }
            while(dual(delta))primal(delta);
        }
        T res=0;
        for(auto& es:g)for(auto& e:es)res+=T(e.flow)*T(e.weight);
        res>>=1;
        if(exc.empty() and def.empty())return {1,res*type};
        else return {0,res*type};
    }
};

/**
 * @brief Minimum Cost b-flow
 */