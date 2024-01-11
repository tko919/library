---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Maximal Rectangles
    links: []
  bundledCode: "#line 2 \"Algorithm/maximalrect.hpp\"\n\ntemplate<typename T>vector<pair<pair<int,int>,T>>\
    \ MaximalRectangles(vector<T> height){\n    int n=height.size();\n    height.push_back(0);\n\
    \    using P=pair<int,int>;\n    stack<pair<T,int>> st;\n    vector<pair<P,T>>\
    \ ret;\n    rep(i,0,n+1){\n        P add{height[i],i};\n        if(st.empty()\
    \ or st.top().first<add.first)st.push(add);\n        else{\n            int nxt=i;\n\
    \            while(!st.empty() and st.top().first>=add.first){\n             \
    \   P pre=st.top();\n                st.pop();\n                nxt=pre.second;\n\
    \                ret.push_back({{pre.second,i},pre.first});\n            }\n \
    \           add.second=nxt;\n            st.push(add);\n        }\n    }\n   \
    \ return ret;\n}\n\nvector<pair<pair<int,int>,pair<int,int>>> MaximalRectangles(vector<vector<int>>&\
    \ grid){ // 01 grid\n    int n=grid.size(),m=grid[0].size();\n    using P=pair<int,int>;\n\
    \    vector<pair<P,P>> ret;\n    vector<int> height(m);\n    rep(i,0,n){\n   \
    \     rep(j,0,m){\n            if(grid[i][j])height[j]++;\n            else height[j]=0;\n\
    \        }\n        auto add=MaximalRectangles(height);\n        for(auto& [DU,h]:add){\n\
    \            ret.push_back({{i+1-h,i+1},DU});\n        }\n    }\n    return ret;\n\
    }\n\n/**\n * @brief Maximal Rectangles\n */\n"
  code: "#pragma once\n\ntemplate<typename T>vector<pair<pair<int,int>,T>> MaximalRectangles(vector<T>\
    \ height){\n    int n=height.size();\n    height.push_back(0);\n    using P=pair<int,int>;\n\
    \    stack<pair<T,int>> st;\n    vector<pair<P,T>> ret;\n    rep(i,0,n+1){\n \
    \       P add{height[i],i};\n        if(st.empty() or st.top().first<add.first)st.push(add);\n\
    \        else{\n            int nxt=i;\n            while(!st.empty() and st.top().first>=add.first){\n\
    \                P pre=st.top();\n                st.pop();\n                nxt=pre.second;\n\
    \                ret.push_back({{pre.second,i},pre.first});\n            }\n \
    \           add.second=nxt;\n            st.push(add);\n        }\n    }\n   \
    \ return ret;\n}\n\nvector<pair<pair<int,int>,pair<int,int>>> MaximalRectangles(vector<vector<int>>&\
    \ grid){ // 01 grid\n    int n=grid.size(),m=grid[0].size();\n    using P=pair<int,int>;\n\
    \    vector<pair<P,P>> ret;\n    vector<int> height(m);\n    rep(i,0,n){\n   \
    \     rep(j,0,m){\n            if(grid[i][j])height[j]++;\n            else height[j]=0;\n\
    \        }\n        auto add=MaximalRectangles(height);\n        for(auto& [DU,h]:add){\n\
    \            ret.push_back({{i+1-h,i+1},DU});\n        }\n    }\n    return ret;\n\
    }\n\n/**\n * @brief Maximal Rectangles\n */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/maximalrect.hpp
  requiredBy: []
  timestamp: '2024-01-12 04:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/maximalrect.hpp
layout: document
redirect_from:
- /library/Algorithm/maximalrect.hpp
- /library/Algorithm/maximalrect.hpp.html
title: Maximal Rectangles
---
