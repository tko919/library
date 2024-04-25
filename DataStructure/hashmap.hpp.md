---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/LC_associative_array.test.cpp
    title: Verify/LC_associative_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Hash Map
    links: []
  bundledCode: "#line 2 \"DataStructure/hashmap.hpp\"\n\r\ntemplate<typename Key,typename\
    \ Val,int N=1<<20>struct HashMap{\r\n    using u64 = uint64_t;\r\nprivate:\r\n\
    \    array<Key,N> keys;\r\n    array<Val,N> vals;\r\n    bitset<N> used;\r\n \
    \   const int shift;\r\n    static constexpr u64 RNG() {\r\n        mt19937_64\
    \ gen(chrono::steady_clock::now().time_since_epoch().count());\r\n        return\
    \ gen();\r\n    }\r\npublic:\r\n    HashMap():shift(64-__lg(N)){\r\n        static_assert((N\
    \ & (N - 1)) == 0 && N > 0);\r\n    }\r\n    Val& operator[](const Key& x){\r\n\
    \        static u64 r=RNG();\r\n        int hash=(u64(x)*r)>>shift;\r\n      \
    \  for(;;){\r\n            if(!used[hash]){\r\n                keys[hash]=x;\r\
    \n                used[hash]=1;\r\n                return vals[hash]=Val();\r\n\
    \            }\r\n            if(keys[hash]==x)return vals[hash];\r\n        \
    \    hash++;\r\n            hash=(hash+1)&(N-1);\r\n        }\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Hash Map\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate<typename Key,typename Val,int N=1<<20>struct\
    \ HashMap{\r\n    using u64 = uint64_t;\r\nprivate:\r\n    array<Key,N> keys;\r\
    \n    array<Val,N> vals;\r\n    bitset<N> used;\r\n    const int shift;\r\n  \
    \  static constexpr u64 RNG() {\r\n        mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n        return gen();\r\n    }\r\npublic:\r\n    HashMap():shift(64-__lg(N)){\r\
    \n        static_assert((N & (N - 1)) == 0 && N > 0);\r\n    }\r\n    Val& operator[](const\
    \ Key& x){\r\n        static u64 r=RNG();\r\n        int hash=(u64(x)*r)>>shift;\r\
    \n        for(;;){\r\n            if(!used[hash]){\r\n                keys[hash]=x;\r\
    \n                used[hash]=1;\r\n                return vals[hash]=Val();\r\n\
    \            }\r\n            if(keys[hash]==x)return vals[hash];\r\n        \
    \    hash++;\r\n            hash=(hash+1)&(N-1);\r\n        }\r\n    }\r\n};\r\
    \n\r\n/**\r\n * @brief Hash Map\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/hashmap.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/LC_associative_array.test.cpp
documentation_of: DataStructure/hashmap.hpp
layout: document
redirect_from:
- /library/DataStructure/hashmap.hpp
- /library/DataStructure/hashmap.hpp.html
title: Hash Map
---
