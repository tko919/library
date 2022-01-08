---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_min_cost_b_flow.test.cpp
    title: Verify/LC_min_cost_b_flow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Minimum Cost b-flow
    links: []
  bundledCode: "#line 2 \"Graph/mincostflow.hpp\"\n\r\ntemplate<typename Flow,typename\
    \ Cost,int type=1>class MinCostFlow{ //Maximize=-1\r\n    struct ptr{int v_id,e_id;};\r\
    \n    struct edge{\r\n        int from,to; Flow flow,cap; Cost weight; int rev;\r\
    \n        edge(int _f,int _t,Flow _c,Cost _w,int _r)\r\n            :from(_f),to(_t),flow(0),cap(_c),weight(_w),rev(_r){}\r\
    \n        Flow residual_cap()const{return cap-flow;}\r\n    };\r\n    int n; vector<vector<edge>>\
    \ g;\r\n    vector<Flow> b,pot; vector<ptr> es;\r\n    Cost farthest; vector<Cost>\
    \ dist; vector<edge*> par;\r\n    vector<int> exc,def;\r\n    void push(edge&\
    \ e,Flow amount){\r\n        e.flow+=amount; g[e.to][e.rev].flow-=amount;\r\n\
    \    }\r\n    Cost residual_cost(int from,int to,edge& e){\r\n        return e.weight+pot[from]-pot[to];\r\
    \n    }\r\n    bool dual(const Flow& delta){\r\n        dist.assign(n,numeric_limits<Cost>::max());\
    \ par.assign(n,nullptr);\r\n        exc.erase(remove_if(ALL(exc),[&](int v){return\
    \ b[v]<delta;}),exc.end());\r\n        def.erase(remove_if(ALL(def),[&](int v){return\
    \ b[v]>-delta;}),def.end());\r\n        priority_queue<pair<Cost,int>,vector<pair<Cost,int>>,greater<>>\
    \ pq;\r\n        for(auto& v:exc)pq.push({dist[v]=0,v});\r\n        farthest=0;\
    \ int def_cnt=0;\r\n        while(!pq.empty()){\r\n            auto [d,u]=pq.top();\
    \ pq.pop();\r\n            if(dist[u]<d)continue;\r\n            farthest=d;\r\
    \n            if(b[u]<=-delta)def_cnt++;\r\n            if(def_cnt>=(int)def.size())break;\r\
    \n            for(auto& e:g[u]){\r\n                if(e.residual_cap()<delta)continue;\r\
    \n                int v=e.to; Cost nd=d+residual_cost(u,v,e);\r\n            \
    \    if(nd>=dist[v])continue;\r\n                pq.push({dist[v]=nd,v}); par[v]=&e;\r\
    \n            }\r\n        }\r\n        rep(v,0,n)pot[v]+=min(dist[v],farthest);\r\
    \n        return def_cnt>0;\r\n    }\r\n    void primal(const Flow& delta){\r\n\
    \        for(auto& t:def){\r\n            if(dist[t]>farthest)continue;\r\n  \
    \          Flow f=-b[t]; int v;\r\n            for(v=t;par[v]!=nullptr;v=par[v]->from){\r\
    \n                chmin(f,par[v]->residual_cap());\r\n            }\r\n      \
    \      chmin(f,b[v]); f-=f%delta;\r\n            if(f<=0)continue;\r\n       \
    \     for(v=t;par[v]!=nullptr;){\r\n                auto& e=*par[v];\r\n     \
    \           push(e,f);\r\n                int u=par[v]->from;\r\n            \
    \    if(e.residual_cap()<=0)par[v]=nullptr;\r\n                v=u;\r\n      \
    \      }\r\n            b[t]+=f; b[v]-=f;\r\n        }\r\n    }\r\npublic:\r\n\
    \    MinCostFlow(int _n):n(_n),g(_n),b(_n),pot(_n){}\r\n    void add_edge(int\
    \ from,int to,Flow lb,Flow ub,Cost cost){\r\n        int f_id=g[from].size(),t_id=(from==to?f_id+1:g[to].size());\r\
    \n        g[from].push_back(edge(from,to,ub,cost*type,t_id));\r\n        g[to].push_back(edge(to,from,-lb,-cost*type,f_id));\r\
    \n        es.push_back(ptr{from,f_id});\r\n    }\r\n    void add_supply(int v,Flow\
    \ amount){b[v]+=amount;}\r\n    void add_demand(int v,Flow amount){b[v]-=amount;}\r\
    \n    Flow get_pot(int v){return pot[v];}\r\n    Flow get_flow(int v){return g[es[v].v_id][es[v].e_id].flow;}\r\
    \n    template<typename T=ll>pair<bool,T> run(const Flow& sf=2){\r\n        Flow\
    \ max_flow=1;\r\n        for(auto& t:b)chmax(max_flow,abs(t));\r\n        for(auto&\
    \ es:g)for(auto& e:es)chmax(max_flow,abs(e.residual_cap()));\r\n        Flow delta=1;\r\
    \n        while(delta<max_flow)delta*=sf;\r\n        for(;delta;delta/=sf){\r\n\
    \            for(auto& es:g)for(auto& e:es){\r\n                Flow rcap=e.residual_cap();\r\
    \n                rcap-=rcap%delta;\r\n                Cost rcost=residual_cost(e.from,e.to,e);\r\
    \n                if(rcost<0 or rcap<0){\r\n                    push(e,rcap);\r\
    \n                    b[e.from]-=rcap; b[e.to]+=rcap;\r\n                }\r\n\
    \            }\r\n            rep(v,0,n)if(b[v]!=0){\r\n                (b[v]>0?exc:def).push_back(v);\r\
    \n            }\r\n            while(dual(delta))primal(delta);\r\n        }\r\
    \n        T res=0;\r\n        for(auto& es:g)for(auto& e:es)res+=T(e.flow)*T(e.weight);\r\
    \n        res>>=1;\r\n        if(exc.empty() and def.empty())return {1,res*type};\r\
    \n        else return {0,res*type};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Minimum\
    \ Cost b-flow\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename Flow,typename Cost,int type=1>class\
    \ MinCostFlow{ //Maximize=-1\r\n    struct ptr{int v_id,e_id;};\r\n    struct\
    \ edge{\r\n        int from,to; Flow flow,cap; Cost weight; int rev;\r\n     \
    \   edge(int _f,int _t,Flow _c,Cost _w,int _r)\r\n            :from(_f),to(_t),flow(0),cap(_c),weight(_w),rev(_r){}\r\
    \n        Flow residual_cap()const{return cap-flow;}\r\n    };\r\n    int n; vector<vector<edge>>\
    \ g;\r\n    vector<Flow> b,pot; vector<ptr> es;\r\n    Cost farthest; vector<Cost>\
    \ dist; vector<edge*> par;\r\n    vector<int> exc,def;\r\n    void push(edge&\
    \ e,Flow amount){\r\n        e.flow+=amount; g[e.to][e.rev].flow-=amount;\r\n\
    \    }\r\n    Cost residual_cost(int from,int to,edge& e){\r\n        return e.weight+pot[from]-pot[to];\r\
    \n    }\r\n    bool dual(const Flow& delta){\r\n        dist.assign(n,numeric_limits<Cost>::max());\
    \ par.assign(n,nullptr);\r\n        exc.erase(remove_if(ALL(exc),[&](int v){return\
    \ b[v]<delta;}),exc.end());\r\n        def.erase(remove_if(ALL(def),[&](int v){return\
    \ b[v]>-delta;}),def.end());\r\n        priority_queue<pair<Cost,int>,vector<pair<Cost,int>>,greater<>>\
    \ pq;\r\n        for(auto& v:exc)pq.push({dist[v]=0,v});\r\n        farthest=0;\
    \ int def_cnt=0;\r\n        while(!pq.empty()){\r\n            auto [d,u]=pq.top();\
    \ pq.pop();\r\n            if(dist[u]<d)continue;\r\n            farthest=d;\r\
    \n            if(b[u]<=-delta)def_cnt++;\r\n            if(def_cnt>=(int)def.size())break;\r\
    \n            for(auto& e:g[u]){\r\n                if(e.residual_cap()<delta)continue;\r\
    \n                int v=e.to; Cost nd=d+residual_cost(u,v,e);\r\n            \
    \    if(nd>=dist[v])continue;\r\n                pq.push({dist[v]=nd,v}); par[v]=&e;\r\
    \n            }\r\n        }\r\n        rep(v,0,n)pot[v]+=min(dist[v],farthest);\r\
    \n        return def_cnt>0;\r\n    }\r\n    void primal(const Flow& delta){\r\n\
    \        for(auto& t:def){\r\n            if(dist[t]>farthest)continue;\r\n  \
    \          Flow f=-b[t]; int v;\r\n            for(v=t;par[v]!=nullptr;v=par[v]->from){\r\
    \n                chmin(f,par[v]->residual_cap());\r\n            }\r\n      \
    \      chmin(f,b[v]); f-=f%delta;\r\n            if(f<=0)continue;\r\n       \
    \     for(v=t;par[v]!=nullptr;){\r\n                auto& e=*par[v];\r\n     \
    \           push(e,f);\r\n                int u=par[v]->from;\r\n            \
    \    if(e.residual_cap()<=0)par[v]=nullptr;\r\n                v=u;\r\n      \
    \      }\r\n            b[t]+=f; b[v]-=f;\r\n        }\r\n    }\r\npublic:\r\n\
    \    MinCostFlow(int _n):n(_n),g(_n),b(_n),pot(_n){}\r\n    void add_edge(int\
    \ from,int to,Flow lb,Flow ub,Cost cost){\r\n        int f_id=g[from].size(),t_id=(from==to?f_id+1:g[to].size());\r\
    \n        g[from].push_back(edge(from,to,ub,cost*type,t_id));\r\n        g[to].push_back(edge(to,from,-lb,-cost*type,f_id));\r\
    \n        es.push_back(ptr{from,f_id});\r\n    }\r\n    void add_supply(int v,Flow\
    \ amount){b[v]+=amount;}\r\n    void add_demand(int v,Flow amount){b[v]-=amount;}\r\
    \n    Flow get_pot(int v){return pot[v];}\r\n    Flow get_flow(int v){return g[es[v].v_id][es[v].e_id].flow;}\r\
    \n    template<typename T=ll>pair<bool,T> run(const Flow& sf=2){\r\n        Flow\
    \ max_flow=1;\r\n        for(auto& t:b)chmax(max_flow,abs(t));\r\n        for(auto&\
    \ es:g)for(auto& e:es)chmax(max_flow,abs(e.residual_cap()));\r\n        Flow delta=1;\r\
    \n        while(delta<max_flow)delta*=sf;\r\n        for(;delta;delta/=sf){\r\n\
    \            for(auto& es:g)for(auto& e:es){\r\n                Flow rcap=e.residual_cap();\r\
    \n                rcap-=rcap%delta;\r\n                Cost rcost=residual_cost(e.from,e.to,e);\r\
    \n                if(rcost<0 or rcap<0){\r\n                    push(e,rcap);\r\
    \n                    b[e.from]-=rcap; b[e.to]+=rcap;\r\n                }\r\n\
    \            }\r\n            rep(v,0,n)if(b[v]!=0){\r\n                (b[v]>0?exc:def).push_back(v);\r\
    \n            }\r\n            while(dual(delta))primal(delta);\r\n        }\r\
    \n        T res=0;\r\n        for(auto& es:g)for(auto& e:es)res+=T(e.flow)*T(e.weight);\r\
    \n        res>>=1;\r\n        if(exc.empty() and def.empty())return {1,res*type};\r\
    \n        else return {0,res*type};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Minimum\
    \ Cost b-flow\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Graph/mincostflow.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - Verify/LC_min_cost_b_flow.test.cpp
documentation_of: Graph/mincostflow.hpp
layout: document
redirect_from:
- /library/Graph/mincostflow.hpp
- /library/Graph/mincostflow.hpp.html
title: Minimum Cost b-flow
---
