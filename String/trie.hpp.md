---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: String/ahocorasick.hpp
    title: Aho-Corasick
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Trie
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
    \        return pos;\n    }\n};\n\n/**\n * @brief Trie\n*/\n"
  code: "#pragma once\n\ntemplate<int SZ,int start>struct Trie{\n    struct Node{\n\
    \        array<int,SZ> nxt;\n        vector<int> ids;\n        Node(){fill(ALL(nxt),-1);}\n\
    \    };\n    vector<Node> vs;\n    \n    Trie(){vs.push_back(Node());}\n    Node\
    \ operator[](const int& i)const{return vs[i];}\n    int move(int pos,char c){\n\
    \        return pos<0?-1:vs[pos].nxt[int(c-start)];\n    }\n    void add(const\
    \ string& s,int id){\n        int pos=0;\n        for(auto& c:s){\n          \
    \  int to=move(pos,c);\n            if(to==-1){\n                to=vs.size();\n\
    \                vs.push_back(Node());\n                vs[pos].nxt[int(c-start)]=to;\n\
    \            }\n            pos=to;\n        }\n        vs[pos].ids.push_back(id);\n\
    \    }\n    int find(string& s){\n        int pos=0;\n        for(auto& c:s){\n\
    \            pos=move(pos,c);\n            if(pos==-1)return -1;\n        }\n\
    \        return pos;\n    }\n};\n\n/**\n * @brief Trie\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/trie.hpp
  requiredBy:
  - String/ahocorasick.hpp
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/trie.hpp
layout: document
redirect_from:
- /library/String/trie.hpp
- /library/String/trie.hpp.html
title: Trie
---
