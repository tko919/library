---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Math/factorial.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/310\"\r\n\r\n#include\
    \ \"Template/template.hpp\"\r\n#include \"Utility/fastio.hpp\"\r\n\r\n#include\
    \ \"Math/modint.hpp\"\r\n#include \"Math/factorial.hpp\"\r\n#include \"Convolution/arbitrary.hpp\"\
    \r\n#include \"FPS/arbitraryfps.hpp\"\r\n#include \"Math/bbla.hpp\"\r\nusing Fp=fp<>;\r\
    \ntemplate<>vector<Fp> Poly<Fp>::mult(const vector<Fp>& a,const vector<Fp>& b,bool\
    \ same)const{\r\n    return ArbitraryMult(a,b,same);\r\n}\r\n\r\nfactorial<Fp>\
    \ fact(8020);\r\nint g[4010][4010]={},in[4010],out[4010];\r\nvoid fail(){puts(\"\
    0\"); exit(0);}\r\n\r\nFastIO io;\r\nint main(){\r\n    int n,m;\r\n    io.read(n,m);\r\
    \n    if(n*n==m){puts(\"1\"); return 0;}\r\n    rep(i,0,n){\r\n        g[i][i]=in[i]=out[i]=n;\r\
    \n        rep(j,0,n)g[i][j]--;\r\n    }\r\n    rep(_,0,m){\r\n        int x,y;\r\
    \n        io.read(x,y);\r\n        x--; y--;\r\n        in[y]--; out[x]--;\r\n\
    \        g[x][y]++; g[y][y]--;\r\n    }\r\n    int s=-1,t=-1,N=0,v[4010];\r\n\
    \    rep(i,0,n){\r\n        if(in[i]==0 and out[i]==0)continue;\r\n        v[N++]=i;\r\
    \n        if(abs(in[i]-out[i])>1)fail();\r\n        if(out[i]==in[i]+1){\r\n \
    \           if(s!=-1)fail(); s=i;\r\n        }\r\n        if(out[i]+1==in[i]){\r\
    \n            if(t!=-1)fail(); t=i;\r\n        }\r\n    }\r\n\r\n    Fp ret=n*n-m;\r\
    \n    if(s!=-1 and t!=-1){\r\n        in[s]++; out[t]++;\r\n        g[t][s]--;\
    \ g[s][s]++;\r\n        ret=1;\r\n    }\r\n    rep(i,0,N)ret*=fact.fact(in[v[i]]-1);\r\
    \n    SparseMatrix<Fp> mat(N-1,-1);\r\n    rep(i,0,N-1)rep(j,0,N-1)if(g[v[i]][v[j]]!=-1\
    \ or i==j){\r\n        mat.add(i,j,g[v[i]][v[j]]);\r\n    }\r\n    ret*=FastDet(mat);\r\
    \n    io.write(ret.v);\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: true
  path: Verify/YUKI_310.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Verify/YUKI_310.test.cpp
layout: document
redirect_from:
- /verify/Verify/YUKI_310.test.cpp
- /verify/Verify/YUKI_310.test.cpp.html
title: Verify/YUKI_310.test.cpp
---
