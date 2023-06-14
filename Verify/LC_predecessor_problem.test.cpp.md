---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/rbstset.hpp
    title: Randomized Binary Search Tree (set)
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  - icon: ':heavy_check_mark:'
    path: Utility/fastio.hpp
    title: Fast IO
  - icon: ':heavy_check_mark:'
    path: Utility/random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"Verify/LC_predecessor_problem.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\n\r\n#line 1 \"Template/template.hpp\"\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n#define rep(i,a,b) for(int\
    \ i=(int)(a);i<(int)(b);i++)\r\n#define ALL(v) (v).begin(),(v).end()\r\n#define\
    \ UNIQUE(v) sort(ALL(v)),(v).erase(unique(ALL(v)),(v).end())\r\n#define MIN(v)\
    \ *min_element(ALL(v))\r\n#define MAX(v) *max_element(ALL(v))\r\n#define LB(v,x)\
    \ lower_bound(ALL(v),(x))-(v).begin()\r\n#define UB(v,x) upper_bound(ALL(v),(x))-(v).begin()\r\
    \n\r\nusing ll=long long int;\r\nconst int inf = 0x3fffffff;\r\nconst ll INF =\
    \ 0x1fffffffffffffff;\r\n\r\ntemplate<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return\
    \ 1;}return 0;}\r\ntemplate<typename T,typename U>T ceil(T x,U y){assert(y!=0);\
    \ if(y<0)x=-x,y=-y; return (x>0?(x+y-1)/y:x/y);}\r\ntemplate<typename T,typename\
    \ U>T floor(T x,U y){assert(y!=0); if(y<0)x=-x,y=-y; return (x>0?x/y:(x-y+1)/y);}\r\
    \ntemplate<typename T>int popcnt(T x){return __builtin_popcountll(x);}\r\ntemplate<typename\
    \ T>int topbit(T x){return (x==0?-1:63-__builtin_clzll(x));}\r\ntemplate<typename\
    \ T>int lowbit(T x){return (x==0?-1:__builtin_ctzll(x));}\n#line 2 \"Utility/fastio.hpp\"\
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
    \n        }\r\n        return true;\r\n    }\r\n    inline bool _read(__int128_t&\
    \ x){\r\n        if(!skip())return false;\r\n        if(rdLeft+40>=rdRight)reload();\r\
    \n        bool neg=false;\r\n        if(rdbuf[rdLeft]=='-'){\r\n            neg=true;\r\
    \n            rdLeft++;\r\n        }\r\n        x=0;\r\n        while(rdbuf[rdLeft]>='0'\
    \ and rdLeft<rdRight){\r\n            x=x*10+(neg?-(rdbuf[rdLeft++]^48):(rdbuf[rdLeft++]^48));\r\
    \n        }\r\n        return true;\r\n    }\r\n    inline bool _read(__uint128_t&\
    \ x){\r\n        if(!skip())return false;\r\n        if(rdLeft+40>=rdRight)reload();\r\
    \n        x=0;\r\n        while(rdbuf[rdLeft]>='0' and rdLeft<rdRight){\r\n  \
    \          x=x*10+(rdbuf[rdLeft++]^48);\r\n        }\r\n        return true;\r\
    \n    }\r\n    template<typename T,enable_if_t<is_floating_point<T>::value,int>\
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
    \n        wtRight+=pos;\r\n    }\r\n    inline void _write(__int128_t x){\r\n\
    \        if(wtRight>L-40)flush();\r\n        if(x==0){\r\n            _write('0');\r\
    \n            return;\r\n        }\r\n        else if(x<0){\r\n            _write('-');\r\
    \n            x=-x;\r\n        }\r\n        int pos=0;\r\n        while(x!=0){\r\
    \n            tmp[pos++]=char((x%10)|48);\r\n            x/=10;\r\n        }\r\
    \n        rep(i,0,pos)wtbuf[wtRight+i]=tmp[pos-1-i];\r\n        wtRight+=pos;\r\
    \n    }\r\n    inline void _write(__uint128_t x){\r\n        if(wtRight>L-40)flush();\r\
    \n        if(x==0){\r\n            _write('0');\r\n            return;\r\n   \
    \     }\r\n        int pos=0;\r\n        while(x!=0){\r\n            tmp[pos++]=char((x%10)|48);\r\
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
    \n * @brief Fast IO\r\n */\n#line 2 \"DataStructure/rbstset.hpp\"\n\r\n#line 2\
    \ \"Utility/random.hpp\"\n\r\nstruct Random{\r\n    random_device rnd;\r\n   \
    \ unsigned x=123456789,y=362436069,z=521288629,w=rnd();\r\n    Random(){}\r\n\
    \    unsigned get(){\r\n        unsigned t=x^(x<<11);\r\n        x=y,y=z,z=w;\r\
    \n        return w=(w^(w<<19))^(t^(t>>8));\r\n    }\r\n    unsigned get(unsigned\
    \ L){\r\n        return get()%(L+1);\r\n    }\r\n    template<typename T>T get(T\
    \ L,T R){\r\n        return get(R-L)+L;\r\n    }\r\n    double uniform(){\r\n\
    \        return double(get())/UINT_MAX;\r\n    }\r\n    string str(int n){\r\n\
    \        string ret;\r\n        rep(i,0,n)ret+=get('a','z');\r\n        return\
    \ ret;\r\n    }\r\n    template<typename Iter>void shuffle(Iter first,Iter last){\r\
    \n        if(first==last)return;\r\n        int len=1;\r\n        for(auto it=first+1;it!=last;it++){\r\
    \n            len++;\r\n            int j=get(0,len-1);\r\n            if(j!=len-1)iter_swap(it,first+j);\r\
    \n        }\r\n    }\r\n    template<typename T>vector<T> select(int n,T L,T R){\r\
    \n        set<T> ret;\r\n        while(ret.size()<n)ret.insert(get(L,R));\r\n\
    \        return {ALL(ret)};\r\n    }\r\n};\r\n\r\n/**\r\n * @brief Random\r\n\
    \ */\n#line 4 \"DataStructure/rbstset.hpp\"\n\r\nRandom genRBSTset;\r\ntemplate<typename\
    \ T>class RBSTset{\r\n    struct Node{\r\n        Node *lp=nullptr,*rp=nullptr;\r\
    \n        int size=1;\r\n        T key;\r\n        Node(T _k=0):key(_k){}\r\n\
    \        void apply(){\r\n            size=1;\r\n            if(lp)size+=lp->size;\r\
    \n            if(rp)size+=rp->size;\r\n        }\r\n    };\r\n    int size(Node*\
    \ x){return x?x->size:0;}\r\n    Node* merge(Node* L,Node* R){\r\n        if(!L)return\
    \ R;\r\n        if(!R)return L;\r\n        if((int)genRBSTset.get(size(L)+size(R)-1)<size(L)){\r\
    \n            L->rp=merge(L->rp,R);\r\n            L->apply();\r\n           \
    \ return L;\r\n        }\r\n        else{\r\n            R->lp=merge(L,R->lp);\r\
    \n            R->apply();\r\n            return R;\r\n        }\r\n    }\r\n \
    \   array<Node*,2> split(Node* x,int k){\r\n        if(!x)return {nullptr,nullptr};\r\
    \n        if(k==size(x))return {x,nullptr};\r\n        if(k<=size(x->lp)){\r\n\
    \            auto [lb,rb]=split(x->lp,k);\r\n            Node *L=lb,*R=x;\r\n\
    \            x->lp=rb;\r\n            x->apply();\r\n            return {L,R};\r\
    \n        }\r\n        else{\r\n            auto [lb,rb]=split(x->rp,k-size(x->lp)-1);\r\
    \n            Node *L=x,*R=rb;\r\n            x->rp=lb;\r\n            x->apply();\r\
    \n            return {L,R};\r\n        }\r\n    }\r\n    int lower_bound(Node*\
    \ x,T v){\r\n        if(!x)return 0;\r\n        if(x->key>=v)return lower_bound(x->lp,v);\r\
    \n        else return size(x->lp)+1+lower_bound(x->rp,v);\r\n    }\r\n    int\
    \ upper_bound(Node* x,T v){\r\n        if(!x)return 0;\r\n        if(x->key>v)return\
    \ upper_bound(x->lp,v);\r\n        else return size(x->lp)+1+upper_bound(x->rp,v);\r\
    \n    }\r\n    void _dump(Node* cur,string add){\r\n        if(!cur)return;\r\n\
    \        _dump(cur->lp,add+\"*\");\r\n        cerr<<add<<cur->key<<'\\n';\r\n\
    \        _dump(cur->rp,add+\"*\");\r\n    }\r\npublic:\r\n    Node *root;\r\n\
    \    RBSTset(Node* _r=nullptr):root(_r){}\r\n    int size(){return size(root);}\r\
    \n    void merge(RBSTset& a){\r\n        root=merge(root,a.root);\r\n    }\r\n\
    \    RBSTset split(int k){\r\n        auto [L,R]=split(root,k);\r\n        root=L;\r\
    \n        return RBSTset(R);\r\n    }\r\n    bool find(T x){\r\n        Node *cur=root;\r\
    \n        for(;;){\r\n            if(!cur)break;\r\n            if(cur->key==x)return\
    \ true;\r\n            else if(x<cur->key)cur=cur->lp;\r\n            else cur=cur->rp;\r\
    \n        }\r\n        return false;\r\n    }\r\n    void insert(T x){\r\n   \
    \     int k=lower_bound(root,x);\r\n        auto [L,R]=split(root,k);\r\n    \
    \    root=merge(merge(L,new Node(x)),R);\r\n    }\r\n    void erase(T x){\r\n\
    \        assert(find(x));\r\n        int k=lower_bound(root,x);\r\n        auto\
    \ [L,t]=split(root,k);\r\n        auto [tmp,R]=split(t,1);\r\n        root=merge(L,R);\r\
    \n    }\r\n    T kth_element(int k){\r\n        if(k>=size(root) or k<0)return\
    \ -1;\r\n        auto [L,R]=split(root,k);\r\n        Node* cur=R;\r\n       \
    \ while(cur->lp)cur=cur->lp;\r\n        root=merge(L,R);\r\n        return cur->key;\r\
    \n    }\r\n    int lower_bound(T v){\r\n        return lower_bound(root,v);\r\n\
    \    }\r\n    int upper_bound(T v){\r\n        return upper_bound(root,v);\r\n\
    \    }\r\n    void dump(){\r\n        _dump(root,\"*\");\r\n    }\r\n};\r\n\r\n\
    /**\r\n * @brief Randomized Binary Search Tree (set)\r\n */\n#line 6 \"Verify/LC_predecessor_problem.test.cpp\"\
    \n\r\nFastIO io;\r\nint main(){\r\n    int n,q;\r\n    string s;\r\n    io.read(n,q,s);\r\
    \n    RBSTset<int> tree;\r\n    rep(i,0,n)if(s[i]=='1'){\r\n        tree.insert(i);\r\
    \n    }\r\n    while(q--){\r\n        //tree.dump();\r\n        int t,x;\r\n \
    \       io.read(t,x);\r\n        if(t==0){\r\n            if(!tree.find(x))tree.insert(x);\r\
    \n        }\r\n        if(t==1){\r\n            if(tree.find(x))tree.erase(x);\r\
    \n        }\r\n        if(t==2){\r\n            io.write((int)tree.find(x));\r\
    \n        }\r\n        if(t==3){\r\n            io.write(tree.kth_element(tree.lower_bound(x)));\r\
    \n        }\r\n        if(t==4){\r\n            io.write(tree.kth_element(tree.upper_bound(x)-1));\r\
    \n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\r\
    \n\r\n#include \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\
    #include \"DataStructure/rbstset.hpp\"\r\n\r\nFastIO io;\r\nint main(){\r\n  \
    \  int n,q;\r\n    string s;\r\n    io.read(n,q,s);\r\n    RBSTset<int> tree;\r\
    \n    rep(i,0,n)if(s[i]=='1'){\r\n        tree.insert(i);\r\n    }\r\n    while(q--){\r\
    \n        //tree.dump();\r\n        int t,x;\r\n        io.read(t,x);\r\n    \
    \    if(t==0){\r\n            if(!tree.find(x))tree.insert(x);\r\n        }\r\n\
    \        if(t==1){\r\n            if(tree.find(x))tree.erase(x);\r\n        }\r\
    \n        if(t==2){\r\n            io.write((int)tree.find(x));\r\n        }\r\
    \n        if(t==3){\r\n            io.write(tree.kth_element(tree.lower_bound(x)));\r\
    \n        }\r\n        if(t==4){\r\n            io.write(tree.kth_element(tree.upper_bound(x)-1));\r\
    \n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn:
  - Template/template.hpp
  - Utility/fastio.hpp
  - DataStructure/rbstset.hpp
  - Utility/random.hpp
  isVerificationFile: true
  path: Verify/LC_predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '2023-06-14 14:20:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/LC_predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/Verify/LC_predecessor_problem.test.cpp
- /verify/Verify/LC_predecessor_problem.test.cpp.html
title: Verify/LC_predecessor_problem.test.cpp
---
