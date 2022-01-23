---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/mincostflow.hpp
    title: Minimum Cost b-flow
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#line 1 \"Verify/LC_min_cost_b_flow.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/min_cost_b_flow\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\nusing\
    \ ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF = 0x1fffffffffffffff;\r\
    \ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return\
    \ 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return\
    \ 0;}\n#line 2 \"Graph/mincostflow.hpp\"\n\r\ntemplate<typename Flow,typename\
    \ Cost,int type=1>class MinCostFlow{ //Maximize=-1\r\n    struct ptr{int v_id,e_id;};\r\
    \n    struct edge{\r\n        int from,to; Flow flow,cap; Cost weight; int rev;\r\
    \n        edge(int _f,int _t,Flow _c,Cost _w,int _r)\r\n            :from(_f),to(_t),flow(0),cap(_c),weight(_w),rev(_r){}\r\
    \n        Flow residual_cap()const{return cap-flow;}\r\n    };\r\n    int n; vector<vector<edge>>\
    \ g;\r\n    vector<Flow> b,pot; vector<ptr> ptrs;\r\n    Cost farthest; vector<Cost>\
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
    \n        ptrs.push_back(ptr{from,f_id});\r\n    }\r\n    void add_supply(int\
    \ v,Flow amount){b[v]+=amount;}\r\n    void add_demand(int v,Flow amount){b[v]-=amount;}\r\
    \n    Flow get_pot(int v){return pot[v];}\r\n    Flow get_flow(int v){return g[ptrs[v].v_id][ptrs[v].e_id].flow;}\r\
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
    \ Cost b-flow\r\n */\n#line 2 \"Utility/fastio.hpp\"\n#include <unistd.h>\r\n\r\
    \nclass FastIO{\r\n    static constexpr int L=1<<16;\r\n    char rdbuf[L];\r\n\
    \    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\n        int len=rdRight-rdLeft;\r\
    \n        memmove(rdbuf,rdbuf+rdLeft,len);\r\n        rdLeft=0,rdRight=len;\r\n\
    \        rdRight+=fread(rdbuf+len,1,L-len,stdin);\r\n    }\r\n    inline bool\
    \ skip(){\r\n        for(;;){\r\n            while(rdLeft!=rdRight and rdbuf[rdLeft]<='\
    \ ')rdLeft++;\r\n            if(rdLeft==rdRight){\r\n                reload();\r\
    \n                if(rdLeft==rdRight)return false;\r\n            }\r\n      \
    \      else break;\r\n        }\r\n        return true;\r\n    }\r\n    template<typename\
    \ T,enable_if_t<is_integral<T>::value,int> =0>inline bool _read(T& x){\r\n   \
    \     if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\n\
    \        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0')x=x*10+(rdbuf[rdLeft++]^48);\r\
    \n        if(neg)x=-x;\r\n        return true;\r\n    }\r\n    template<typename\
    \ T,enable_if_t<is_floating_point<T>::value,int> =0>inline bool _read(T& x){\r\
    \n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9')x=x*10+(rdbuf[rdLeft++]^48);\r\n        if(rdbuf[rdLeft]!='.')return\
    \ true;\r\n        rdLeft++;\r\n        T base=.1;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9'){\r\n            x+=base*(rdbuf[rdLeft++]^48);\r\n  \
    \          base*=.1;\r\n        }\r\n        if(neg)x=-x;\r\n        return true;\r\
    \n    }\r\n    inline bool _read(char& x){\r\n        if(!skip())return false;\r\
    \n        if(rdLeft+1>=rdRight)reload();\r\n        x=rdbuf[rdLeft++];\r\n   \
    \     return true;\r\n    }\r\n    inline bool _read(string& x){\r\n        if(!skip())return\
    \ false;\r\n        for(;;){\r\n            int pos=rdLeft;\r\n            while(pos<rdRight\
    \ and rdbuf[pos]>' ')pos++;\r\n            x.append(rdbuf+rdLeft,pos-rdLeft);\r\
    \n            if(rdLeft==pos)break;\r\n            rdLeft=pos;\r\n           \
    \ if(rdLeft==rdRight)reload();\r\n            else break;\r\n        }\r\n   \
    \     return true;\r\n    }\r\n    template<typename T>inline bool _read(vector<T>&\
    \ v){\r\n        for(auto& x:v){\r\n            if(!_read(x))return false;\r\n\
    \        }\r\n        return true;\r\n    }\r\n\r\n    char wtbuf[L],tmp[50];\r\
    \n    int wtRight=0;\r\n    inline void flush(){\r\n        fwrite(wtbuf,1,wtRight,stdout);\r\
    \n        wtRight=0;\r\n    }\r\n    inline void _write(const char& x){\r\n  \
    \      if(wtRight>L-32)flush();\r\n        wtbuf[wtRight++]=x;\r\n    }\r\n  \
    \  inline void _write(const string& x){\r\n        for(auto& c:x)_write(c);\r\n\
    \    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ void _write(T x){\r\n        if(wtRight>L-32)flush();\r\n        if(x==0){\r\
    \n            _write('0');\r\n            return;\r\n        }\r\n        else\
    \ if(x<0){\r\n            _write('-');\r\n            x=-x;\r\n        }\r\n \
    \       int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
    \n            x/=10;\r\n        }\r\n        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];\r\
    \n        wtRight+=pos;\r\n    }\r\n    template<typename T>inline void _write(const\
    \ vector<T>& v){\r\n        rep(i,0,v.size()){\r\n            if(i)_write(' ');\r\
    \n            _write(v[i]);\r\n        }\r\n    }\r\npublic:\r\n    FastIO(){}\r\
    \n    ~FastIO(){flush();}\r\n    inline void read(){}\r\n    template <typename\
    \ Head, typename... Tail>inline void read(Head& head,Tail&... tail){\r\n     \
    \   assert(_read(head));\r\n        read(tail...); \r\n    }\r\n    template<bool\
    \ ln=true,bool space=false>inline void write(){if(ln)_write('\\n');}\r\n    template\
    \ <bool ln=true,bool space=false,typename Head, typename... Tail>inline void write(const\
    \ Head& head,const Tail&... tail){\r\n        if(space)_write(' ');\r\n      \
    \  _write(head);\r\n        write<ln,true>(tail...); \r\n    }\r\n};\r\n\r\n/**\r\
    \n * @brief Fast IO\r\n */\n#line 6 \"Verify/LC_min_cost_b_flow.test.cpp\"\n\r\
    \nnamespace std {\r\n    string to_string(__int128_t x) {\r\n        if (x ==\
    \ 0)\r\n            return \"0\";\r\n        __uint128_t k = x;\r\n        if\
    \ (k == (((__uint128_t)1) << 127))\r\n            return \"-170141183460469231731687303715884105728\"\
    ;\r\n        string result;\r\n        if (x < 0) {\r\n            result += \"\
    -\";\r\n            x *= -1;\r\n        }\r\n        string t;\r\n        while\
    \ (x) {\r\n            t.push_back('0' + x % 10);\r\n            x /= 10;\r\n\
    \        }\r\n        reverse(t.begin(), t.end());\r\n        return result +\
    \ t;\r\n    }\r\n}\r\n\r\nint main(){\r\n    FastIO io;\r\n    int n,m;\r\n  \
    \  io.read(n,m);\r\n    MinCostFlow<ll,ll> mcf(n);\r\n    rep(i,0,n){\r\n    \
    \    int b;\r\n        io.read(b);\r\n        mcf.add_supply(i,b);\r\n    }\r\n\
    \    rep(i,0,m){\r\n        int s,t,l,u,c;\r\n        io.read(s,t,l,u,c);\r\n\
    \        mcf.add_edge(s,t,l,u,c);\r\n    }\r\n    auto [ok,ret]=mcf.run<__int128_t>();\r\
    \n    if(!ok){\r\n        io.write(\"infeasible\");\r\n        return 0;\r\n \
    \   }\r\n    io.write(to_string(ret));\r\n    rep(i,0,n)io.write(mcf.get_pot(i));\r\
    \n    rep(i,0,m)io.write(mcf.get_flow(i));\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\r\n\r\
    \n#include \"Template/template.hpp\"\r\n#include \"Graph/mincostflow.hpp\"\r\n\
    #include \"Utility/fastio.hpp\"\r\n\r\nnamespace std {\r\n    string to_string(__int128_t\
    \ x) {\r\n        if (x == 0)\r\n            return \"0\";\r\n        __uint128_t\
    \ k = x;\r\n        if (k == (((__uint128_t)1) << 127))\r\n            return\
    \ \"-170141183460469231731687303715884105728\";\r\n        string result;\r\n\
    \        if (x < 0) {\r\n            result += \"-\";\r\n            x *= -1;\r\
    \n        }\r\n        string t;\r\n        while (x) {\r\n            t.push_back('0'\
    \ + x % 10);\r\n            x /= 10;\r\n        }\r\n        reverse(t.begin(),\
    \ t.end());\r\n        return result + t;\r\n    }\r\n}\r\n\r\nint main(){\r\n\
    \    FastIO io;\r\n    int n,m;\r\n    io.read(n,m);\r\n    MinCostFlow<ll,ll>\
    \ mcf(n);\r\n    rep(i,0,n){\r\n        int b;\r\n        io.read(b);\r\n    \
    \    mcf.add_supply(i,b);\r\n    }\r\n    rep(i,0,m){\r\n        int s,t,l,u,c;\r\
    \n        io.read(s,t,l,u,c);\r\n        mcf.add_edge(s,t,l,u,c);\r\n    }\r\n\
    \    auto [ok,ret]=mcf.run<__int128_t>();\r\n    if(!ok){\r\n        io.write(\"\
    infeasible\");\r\n        return 0;\r\n    }\r\n    io.write(to_string(ret));\r\
    \n    rep(i,0,n)io.write(mcf.get_pot(i));\r\n    rep(i,0,m)io.write(mcf.get_flow(i));\r\
    \n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Graph/mincostflow.hpp
  - Utility/fastio.hpp
  isVerificationFile: true
  path: Verify/LC_min_cost_b_flow.test.cpp
  requiredBy: []
  timestamp: '2022-01-24 03:48:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_min_cost_b_flow.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_min_cost_b_flow.test.cpp
- /verify/Verify/LC_min_cost_b_flow.test.cpp.html
title: Verify/LC_min_cost_b_flow.test.cpp
---
