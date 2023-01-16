---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/generalweightedmatching.hpp
    title: General Weighted Matching
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':question:'
    path: Utility/fastio.hpp
    title: Fast IO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_weighted_matching
    links:
    - https://judge.yosupo.jp/problem/general_weighted_matching
  bundledCode: "#line 1 \"Verify/LC_general_weighted_matching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\n\n#line\
    \ 1 \"Template/template.hpp\"\n#include <bits/stdc++.h>\r\nusing namespace std;\r\
    \n\r\n#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v)\
    \ (v).begin(),(v).end()\r\n#define UNIQUE(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())\r\
    \n#define MIN(v) *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\
    \n#define LB(v,x) lower_bound(ALL(v),(x))-v.begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-v.begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
    \n#include <unistd.h>\r\n\r\nclass FastIO{\r\n    static constexpr int L=1<<16;\r\
    \n    char rdbuf[L];\r\n    int rdLeft=0,rdRight=0;\r\n    inline void reload(){\r\
    \n        int len=rdRight-rdLeft;\r\n        memmove(rdbuf,rdbuf+rdLeft,len);\r\
    \n        rdLeft=0,rdRight=len;\r\n        rdRight+=fread(rdbuf+len,1,L-len,stdin);\r\
    \n    }\r\n    inline bool skip(){\r\n        for(;;){\r\n            while(rdLeft!=rdRight\
    \ and rdbuf[rdLeft]<=' ')rdLeft++;\r\n            if(rdLeft==rdRight){\r\n   \
    \             reload();\r\n                if(rdLeft==rdRight)return false;\r\n\
    \            }\r\n            else break;\r\n        }\r\n        return true;\r\
    \n    }\r\n    template<typename T,enable_if_t<is_integral<T>::value,int> =0>inline\
    \ bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdLeft<rdRight){\r\n            x=x*10+(neg?-(rdbuf[rdLeft++]^48):(rdbuf[rdLeft++]^48));\r\
    \n        }\r\n        return true;\r\n    }\r\n    template<typename T,enable_if_t<is_floating_point<T>::value,int>\
    \ =0>inline bool _read(T& x){\r\n        if(!skip())return false;\r\n        if(rdLeft+20>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdbuf[rdLeft]<='9' and rdLeft<rdRight){\r\n            x=x*10+(rdbuf[rdLeft++]^48);\r\
    \n        }\r\n        if(rdbuf[rdLeft]!='.')return true;\r\n        rdLeft++;\r\
    \n        T base=.1;\r\n        while(rdbuf[rdLeft]>='0' and rdbuf[rdLeft]<='9'\
    \ and rdLeft<rdRight){\r\n            x+=base*(rdbuf[rdLeft++]^48);\r\n      \
    \      base*=.1;\r\n        }\r\n        if(neg)x=-x;\r\n        return true;\r\
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
    \ if(x<0){\r\n            _write('-');\r\n            if (__builtin_expect(x ==\
    \ std::numeric_limits<T>::min(), 0)) {\r\n                switch (sizeof(x)) {\r\
    \n                case 2: _write(\"32768\"); return;\r\n                case 4:\
    \ _write(\"2147483648\"); return;\r\n                case 8: _write(\"9223372036854775808\"\
    ); return;\r\n                }\r\n            }\r\n            x=-x;\r\n    \
    \    }\r\n        int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
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
    \n * @brief Fast IO\r\n */\n#line 5 \"Verify/LC_general_weighted_matching.test.cpp\"\
    \n\n#line 2 \"Graph/generalweightedmatching.hpp\"\n\n// reference: http://www.cs.kent.edu/~dragan/GraphAn/p23-galil.pdf\n\
    class GeneralWeightedMatching{\n    struct E{int u,v; ll w;};\n    int n,m,in;\n\
    \    vector<vector<E>> G;\n    vector<int> mate,slack,root,par,isS,used;\n   \
    \ vector<vector<int>> flower,belong;\n    vector<ll> dual;\n    queue<int> que;\n\
    \    \n    ll dist(const E& e){return dual[e.u]+dual[e.v]-e.w;}\n    void update(int\
    \ u,int v){\n        if(!slack[v] or dist(G[u][v])<dist(G[slack[v]][v]))slack[v]=u;\n\
    \    }\n    void recalc(int v){\n        slack[v]=0;\n        rep(i,1,n+1)if(G[i][v].w\
    \ and root[i]!=v and isS[root[i]]==1)update(i,v);\n    }\n    void push(int v){\n\
    \        if(v<=n)que.push(v);\n        else for(auto& nxt:flower[v])push(nxt);\n\
    \    }\n    void set(int v,int rt){\n        root[v]=rt;\n        if(v>n)for(auto&\
    \ nxt:flower[v])set(nxt,rt);\n    }\n    int findeven(int b,int v){\n        int\
    \ pos=find(ALL(flower[b]),v)-flower[b].begin();\n        if(pos&1){\n        \
    \    reverse(flower[b].begin()+1,flower[b].end());\n            pos=flower[b].size()-pos;\n\
    \        }\n        return pos;\n    }\n    void match(int u,int v){\n       \
    \ mate[u]=G[u][v].v;\n        if(u>n){\n            int x=belong[u][G[u][v].u];\n\
    \            int pos=findeven(u,x);\n            rep(i,0,pos)match(flower[u][i],flower[u][i^1]);\n\
    \            match(x,v);\n            rotate(flower[u].begin(),flower[u].begin()+pos,flower[u].end());\n\
    \        }\n    }\n    void link(int u,int v){\n        for(;;){\n           \
    \ int nv=root[mate[u]];\n            match(u,v);\n            if(!nv)break;\n\
    \            v=nv,u=root[par[nv]];\n            match(v,u);\n        }\n    }\n\
    \    void make(int u,int v,int lca){\n        int id=n+1;\n        while(id<=m\
    \ and root[id])id++;\n        if(id>m)m++;\n        flower[id].clear();\n    \
    \    rep(i,1,m+1)G[id][i].w=G[i][id].w=0;\n        rep(i,1,n+1)belong[id][i]=0;\n\
    \        isS[id]=1,dual[id]=0,mate[id]=mate[lca];\n        while(u!=lca){\n  \
    \          flower[id].push_back(u);\n            u=root[mate[u]];\n          \
    \  push(u);\n            flower[id].push_back(u);\n            u=root[par[u]];\n\
    \        }\n        flower[id].push_back(lca);\n        reverse(ALL(flower[id]));\n\
    \        while(v!=lca){\n            flower[id].push_back(v);\n            v=root[mate[v]];\n\
    \            push(v);\n            flower[id].push_back(v);\n            v=root[par[v]];\n\
    \        }\n        set(id,id);\n        for(auto& c:flower[id]){\n          \
    \  rep(i,1,m+1)if(!G[id][i].w or dist(G[c][i])<dist(G[id][i])){\n            \
    \    G[id][i]=G[c][i],G[i][id]=G[i][c];\n            }\n            rep(i,1,n+1)if(belong[c][i])belong[id][i]=c;\n\
    \        }\n        recalc(id);\n    }\n    void expand(int b){\n        for(auto&\
    \ c:flower[b])set(c,c);\n        int x=belong[b][G[b][par[b]].u];\n        isS[x]=2,par[x]=par[b];\n\
    \        int pos=findeven(b,x);\n        for(int i=0;i<pos;i+=2){\n          \
    \  int T=flower[b][i],S=flower[b][i+1];\n            isS[S]=1,isS[T]=2;\n    \
    \        par[T]=G[S][T].u;\n            slack[S]=slack[T]=0;\n            push(S);\n\
    \        }\n        rep(i,pos+1,flower[b].size()){\n            isS[flower[b][i]]=0;\n\
    \            recalc(flower[b][i]);\n        }\n        flower[b].clear();\n  \
    \      root[b]=0;\n    }\n    bool path(const E& e){\n        int u=root[e.u],v=root[e.v];\n\
    \        if(!isS[v]){\n            par[v]=e.u;\n            isS[v]=2;\n      \
    \      int nu=root[mate[v]];\n            slack[v]=slack[nu]=0;\n            isS[nu]=1;\n\
    \            push(nu);\n        }\n        else if(isS[v]==1){\n            int\
    \ lca=0,bu=u,bv=v;\n            in++;\n            while(bu){\n              \
    \  used[bu]=in;\n                bu=root[mate[bu]];\n                if(bu)bu=root[par[bu]];\n\
    \            }\n            while(bv){\n                if(used[bv]==in){\n  \
    \                  lca=bv;\n                    break;\n                }\n  \
    \              bv=root[mate[bv]];\n                if(bv)bv=root[par[bv]];\n \
    \           }\n            if(lca)make(u,v,lca);\n            else{\n        \
    \        link(u,v),link(v,u);\n                return true;\n            }\n \
    \       }\n        return false;\n    }\n    bool augment(){\n        isS=slack=par=vector<int>(n*2);\n\
    \        que=queue<int>();\n        rep(i,1,m+1)if(root[i]==i and !mate[i]){\n\
    \            isS[i]=1;\n            push(i);\n        }\n        if(que.empty())return\
    \ false;\n        for(;;){\n            while(!que.empty()){\n               \
    \ int v=que.front();\n                que.pop();\n                rep(i,1,n+1)if(G[v][i].w\
    \ and root[i]!=root[v]){\n                    if(!dist(G[v][i])){\n          \
    \              if(path(G[v][i]))return true;\n                    }\n        \
    \            else if(isS[root[i]]!=2)update(v,root[i]);\n                }\n \
    \           }\n            ll delta=INF;\n            rep(i,n+1,m+1)if(root[i]==i\
    \ and isS[i]==2)chmin(delta,dual[i]/2);\n            rep(i,1,m+1)if(root[i]==i\
    \ and slack[i] and isS[i]!=2){\n                if(!isS[i])chmin(delta,dist(G[slack[i]][i]));\n\
    \                else chmin(delta,dist(G[slack[i]][i])/2);\n            }\n  \
    \          rep(i,1,n+1){\n                if(isS[root[i]]==1){\n             \
    \       dual[i]-=delta;\n                    if(dual[i]<=0)return false;\n   \
    \             }\n                else if(isS[root[i]]==2)dual[i]+=delta;\n   \
    \         }\n            rep(i,n+1,m+1)if(root[i]==i and isS[i]){\n          \
    \      if(isS[i]==1)dual[i]+=delta*2;\n                else dual[i]-=delta*2;\n\
    \            }\n            rep(i,1,m+1)if(root[i]==i and slack[i] and root[slack[i]]!=i){\n\
    \                if(dist(G[slack[i]][i])==0 and path(G[slack[i]][i]))return true;\n\
    \            }\n            rep(i,n+1,m+1)if(root[i]==i and isS[i]==2 and dual[i]==0)expand(i);\n\
    \        }\n    }\npublic:\n    GeneralWeightedMatching(int _n):n(_n),m(n),in(0),G(n*2,vector<E>(n*2)),\n\
    \        mate(n*2),root(n*2),used(n*2),flower(n*2),belong(n*2,vector<int>(n*2)),dual(n*2){\n\
    \        rep(i,0,n+1){\n            root[i]=i;\n            belong[i][i]=i;\n\
    \            if(i)dual[i]=INF;\n            rep(j,0,n+1)G[i][j]=E{i,j,0};\n  \
    \      }\n    }\n    void add_edge(int u,int v,ll w){\n        u++,v++;\n    \
    \    chmax(G[u][v].w,w*2);\n        chmax(G[v][u].w,w*2);\n    }\n    vector<int>\
    \ run(){\n        while(augment());\n        vector<int> res(n,-1);\n        rep(i,1,n+1)if(mate[i])res[i-1]=mate[i]-1;\n\
    \        return res;\n    }\n};\n\n/**\n * @brief General Weighted Matching\n\
    */\n#line 7 \"Verify/LC_general_weighted_matching.test.cpp\"\n\n\nFastIO io;\n\
    int main(){\n    int n,m;\n    io.read(n,m);\n    GeneralWeightedMatching solver(n);\n\
    \    vector g(n,vector<ll>(n));\n    rep(_,0,m){\n        int u,v,w;\n       \
    \ io.read(u,v,w);\n        g[u][v]=g[v][u]=w;\n        solver.add_edge(u,v,w);\n\
    \    }\n    auto res=solver.run();\n    ll r1=0,r2=0;\n    rep(i,0,n)if(res[i]>i){\n\
    \        r1++;\n        r2+=g[res[i]][i];\n    }\n    io.write(r1,r2);\n    rep(i,0,n)if(res[i]>i)io.write(res[i],i);\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\
    \n\n#include \"Template/template.hpp\"\n#include \"Utility/fastio.hpp\"\n\n#include\
    \ \"Graph/generalweightedmatching.hpp\"\n\n\nFastIO io;\nint main(){\n    int\
    \ n,m;\n    io.read(n,m);\n    GeneralWeightedMatching solver(n);\n    vector\
    \ g(n,vector<ll>(n));\n    rep(_,0,m){\n        int u,v,w;\n        io.read(u,v,w);\n\
    \        g[u][v]=g[v][u]=w;\n        solver.add_edge(u,v,w);\n    }\n    auto\
    \ res=solver.run();\n    ll r1=0,r2=0;\n    rep(i,0,n)if(res[i]>i){\n        r1++;\n\
    \        r2+=g[res[i]][i];\n    }\n    io.write(r1,r2);\n    rep(i,0,n)if(res[i]>i)io.write(res[i],i);\n\
    \    return 0;\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - Graph/generalweightedmatching.hpp
  isVerificationFile: true
  path: Verify/LC_general_weighted_matching.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 20:41:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/LC_general_weighted_matching.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_general_weighted_matching.test.cpp
- /verify/Verify/LC_general_weighted_matching.test.cpp.html
title: Verify/LC_general_weighted_matching.test.cpp
---
