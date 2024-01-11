---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: String/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Aho-Corasick
    links: []
  bundledCode: "#line 2 \"String/trie.hpp\"\n\ntemplate<int SZ,int start>struct Trie{\n\
    \    struct Node{\n        array<int,SZ> nxt;\n        vector<int> ids;\n    \
    \    Node(){fill(ALL(nxt),-1);}\n    };\n    vector<Node> vs;\n    \n    Trie(){vs.push_back(Node());}\n\
    \    Node operator[](const int& i)const{return vs[i];}\n    int move(int pos,char\
    \ c){\n        return pos<0?-1:vs[pos].nxt[int(c-start)];\n    }\n    void add(const\
    \ string& s,int id){\n        int pos=0;\n        for(auto& c:s){\n          \
    \  int to=move(pos,c);\n            if(to==-1){\n                to=vs.size();\n\
    \                vs.push_back(Node());\n                vs[pos].nxt[int(c-start)]=to;\n\
    \            }\n            pos=to;\n        }\n        vs[pos].ids.push_back(id);\n\
    \    }\n    int find(string& s){\n        int pos=0;\n        for(auto& c:s){\n\
    \            pos=move(pos,c);\n            if(pos==-1)return -1;\n        }\n\
    \        return pos;\n    }\n};\n\n/**\n * @brief Trie\n*/\n#line 3 \"String/ahocorasick.hpp\"\
    \n\ntemplate<int SZ,int start>struct AhoCorasick:Trie<SZ,start>{\n    using super=Trie<SZ,start>;\n\
    \    using super::vs;\n    vector<int> fail,bfs;\n    void make_failure(){\n \
    \       fail.resize(vs.size());\n        queue<int> que;\n        que.push(0);\n\
    \        while(!que.empty()){\n            int v=que.front();\n            que.pop();\n\
    \            bfs.push_back(v);\n            rep(c,0,SZ){\n                if(vs[v].nxt[c]==-1)continue;\n\
    \                int to=vs[v].nxt[c];\n                que.push(to);\n       \
    \         if(v==0)continue;\n                int f=fail[v];\n                while(f\
    \ and vs[f].nxt[c]==-1)f=fail[f];\n                if(vs[f].nxt[c]!=-1)fail[to]=vs[f].nxt[c];\n\
    \            }\n        }\n    }\n    void make_next(){\n        for(auto& v:bfs){\n\
    \            rep(c,0,SZ)if(vs[v].nxt[c]==-1){\n                vs[v].nxt[c]=vs[fail[v]].nxt[c];\n\
    \                if(vs[v].nxt[c]==-1)vs[v].nxt[c]=0;\n            }\n        }\n\
    \    }\n    void merge_id(){\n        for(auto& v:bfs)if(v>0){\n            rep(c,0,SZ){\n\
    \                int from=vs[fail[v]].nxt[c];\n                int to=vs[v].nxt[c];\n\
    \                if(from!=-1 and to!=-1){\n                    for(auto& id:vs[from].ids)vs[to].ids.push_back(id);\n\
    \                }\n            }\n        }\n    }\n};\n\n\n/**\n * @brief Aho-Corasick\n\
    */\n"
  code: "#pragma once\n#include \"String/trie.hpp\"\n\ntemplate<int SZ,int start>struct\
    \ AhoCorasick:Trie<SZ,start>{\n    using super=Trie<SZ,start>;\n    using super::vs;\n\
    \    vector<int> fail,bfs;\n    void make_failure(){\n        fail.resize(vs.size());\n\
    \        queue<int> que;\n        que.push(0);\n        while(!que.empty()){\n\
    \            int v=que.front();\n            que.pop();\n            bfs.push_back(v);\n\
    \            rep(c,0,SZ){\n                if(vs[v].nxt[c]==-1)continue;\n   \
    \             int to=vs[v].nxt[c];\n                que.push(to);\n          \
    \      if(v==0)continue;\n                int f=fail[v];\n                while(f\
    \ and vs[f].nxt[c]==-1)f=fail[f];\n                if(vs[f].nxt[c]!=-1)fail[to]=vs[f].nxt[c];\n\
    \            }\n        }\n    }\n    void make_next(){\n        for(auto& v:bfs){\n\
    \            rep(c,0,SZ)if(vs[v].nxt[c]==-1){\n                vs[v].nxt[c]=vs[fail[v]].nxt[c];\n\
    \                if(vs[v].nxt[c]==-1)vs[v].nxt[c]=0;\n            }\n        }\n\
    \    }\n    void merge_id(){\n        for(auto& v:bfs)if(v>0){\n            rep(c,0,SZ){\n\
    \                int from=vs[fail[v]].nxt[c];\n                int to=vs[v].nxt[c];\n\
    \                if(from!=-1 and to!=-1){\n                    for(auto& id:vs[from].ids)vs[to].ids.push_back(id);\n\
    \                }\n            }\n        }\n    }\n};\n\n\n/**\n * @brief Aho-Corasick\n\
    */"
  dependsOn:
  - String/trie.hpp
  isVerificationFile: false
  path: String/ahocorasick.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/ahocorasick.hpp
layout: document
redirect_from:
- /library/String/ahocorasick.hpp
- /library/String/ahocorasick.hpp.html
title: Aho-Corasick
---
