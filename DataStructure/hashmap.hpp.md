---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Hash Map
    links: []
  bundledCode: "#line 2 \"DataStructure/hashmap.hpp\"\n\r\ntemplate<typename Key,typename\
    \ Val,int N=1<<20>struct HashMap{\r\n    Key* keys;\r\n    Val* vals;\r\n    bitset<N>\
    \ used;\r\n    const int shift;\r\n    const uint64_t r=11995408973635179863ULL;\r\
    \n    HashMap():keys(new Key[N]),vals(new Val[N]),shift(64-__lg(N)){}\r\n    Val&\
    \ operator[](const Key& x){\r\n        int hash=(uint64_t(x)*r)>>shift;\r\n  \
    \      for(;;){\r\n            if(!used[hash]){\r\n                keys[hash]=x;\r\
    \n                used[hash]=1;\r\n                return vals[hash];\r\n    \
    \        }\r\n            if(keys[hash]==x)return vals[hash];\r\n            hash++;\r\
    \n            if(hash==N)hash=0;\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n *\
    \ @brief Hash Map\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename Key,typename Val,int N=1<<20>struct\
    \ HashMap{\r\n    Key* keys;\r\n    Val* vals;\r\n    bitset<N> used;\r\n    const\
    \ int shift;\r\n    const uint64_t r=11995408973635179863ULL;\r\n    HashMap():keys(new\
    \ Key[N]),vals(new Val[N]),shift(64-__lg(N)){}\r\n    Val& operator[](const Key&\
    \ x){\r\n        int hash=(uint64_t(x)*r)>>shift;\r\n        for(;;){\r\n    \
    \        if(!used[hash]){\r\n                keys[hash]=x;\r\n               \
    \ used[hash]=1;\r\n                return vals[hash];\r\n            }\r\n   \
    \         if(keys[hash]==x)return vals[hash];\r\n            hash++;\r\n     \
    \       if(hash==N)hash=0;\r\n        }\r\n    }\r\n};\r\n\r\n/**\r\n * @brief\
    \ Hash Map\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/hashmap.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:50:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/hashmap.hpp
layout: document
redirect_from:
- /library/DataStructure/hashmap.hpp
- /library/DataStructure/hashmap.hpp.html
title: Hash Map
---
