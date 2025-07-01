---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/divisor.hpp
    title: Divisor Multiple Transform
  - icon: ':warning:'
    path: Math/lpftable.hpp
    title: lpf table
  - icon: ':x:'
    path: Math/lucydp.hpp
    title: Prime Sum
  - icon: ':warning:'
    path: Math/mobius.hpp
    title: Mobius table
  - icon: ':x:'
    path: Math/powertable.hpp
    title: Enumrate $n^k$
  - icon: ':warning:'
    path: Math/totient.hpp
    title: lpf table
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/LC_counting_primes.test.cpp
    title: Verify/LC_counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_enumerate_primes.test.cpp
    title: Verify/LC_enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_gcd_convolution.test.cpp
    title: Verify/LC_gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/LC_lcm_convolution.test.cpp
    title: Verify/LC_lcm_convolution.test.cpp
  - icon: ':x:'
    path: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - icon: ':x:'
    path: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
    title: Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - icon: ':x:'
    path: Verify/YUKI_1781.test.cpp
    title: Verify/YUKI_1781.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Prime Sieve
    links: []
  bundledCode: "#line 2 \"Math/sieve.hpp\"\n\r\ntemplate <int L = 101010101> vector<int>\
    \ sieve(int N) {\r\n    bitset<L> isp;\r\n    int n, sq = ceil(sqrt(N));\r\n \
    \   for (int z = 1; z <= 5; z += 4) {\r\n        for (int y = z; y <= sq; y +=\
    \ 6) {\r\n            for (int x = 1; x <= sq and (n = 4 * x * x + y * y) <= N;\
    \ ++x) {\r\n                isp[n].flip();\r\n            }\r\n            for\
    \ (int x = y + 1; x <= sq and (n = 3 * x * x - y * y) <= N;\r\n              \
    \   x += 2) {\r\n                isp[n].flip();\r\n            }\r\n        }\r\
    \n    }\r\n    for (int z = 2; z <= 4; z += 2) {\r\n        for (int y = z; y\
    \ <= sq; y += 6) {\r\n            for (int x = 1; x <= sq and (n = 3 * x * x +\
    \ y * y) <= N; x += 2) {\r\n                isp[n].flip();\r\n            }\r\n\
    \            for (int x = y + 1; x <= sq and (n = 3 * x * x - y * y) <= N;\r\n\
    \                 x += 2) {\r\n                isp[n].flip();\r\n            }\r\
    \n        }\r\n    }\r\n    for (int y = 3; y <= sq; y += 6) {\r\n        for\
    \ (int z = 1; z <= 2; ++z) {\r\n            for (int x = z; x <= sq and (n = 4\
    \ * x * x + y * y) <= N; x += 3) {\r\n                isp[n].flip();\r\n     \
    \       }\r\n        }\r\n    }\r\n    for (int n = 5; n <= sq; ++n)\r\n     \
    \   if (isp[n]) {\r\n            for (int k = n * n; k <= N; k += n * n) {\r\n\
    \                isp[k] = false;\r\n            }\r\n        }\r\n    isp[2] =\
    \ isp[3] = true;\r\n\r\n    vector<int> ret;\r\n    for (int i = 2; i <= N; i++)\r\
    \n        if (isp[i]) {\r\n            ret.push_back(i);\r\n        }\r\n    return\
    \ ret;\r\n}\r\n\r\n/**\r\n * @brief Prime Sieve\r\n */\n"
  code: "#pragma once\r\n\r\ntemplate <int L = 101010101> vector<int> sieve(int N)\
    \ {\r\n    bitset<L> isp;\r\n    int n, sq = ceil(sqrt(N));\r\n    for (int z\
    \ = 1; z <= 5; z += 4) {\r\n        for (int y = z; y <= sq; y += 6) {\r\n   \
    \         for (int x = 1; x <= sq and (n = 4 * x * x + y * y) <= N; ++x) {\r\n\
    \                isp[n].flip();\r\n            }\r\n            for (int x = y\
    \ + 1; x <= sq and (n = 3 * x * x - y * y) <= N;\r\n                 x += 2) {\r\
    \n                isp[n].flip();\r\n            }\r\n        }\r\n    }\r\n  \
    \  for (int z = 2; z <= 4; z += 2) {\r\n        for (int y = z; y <= sq; y +=\
    \ 6) {\r\n            for (int x = 1; x <= sq and (n = 3 * x * x + y * y) <= N;\
    \ x += 2) {\r\n                isp[n].flip();\r\n            }\r\n           \
    \ for (int x = y + 1; x <= sq and (n = 3 * x * x - y * y) <= N;\r\n          \
    \       x += 2) {\r\n                isp[n].flip();\r\n            }\r\n     \
    \   }\r\n    }\r\n    for (int y = 3; y <= sq; y += 6) {\r\n        for (int z\
    \ = 1; z <= 2; ++z) {\r\n            for (int x = z; x <= sq and (n = 4 * x *\
    \ x + y * y) <= N; x += 3) {\r\n                isp[n].flip();\r\n           \
    \ }\r\n        }\r\n    }\r\n    for (int n = 5; n <= sq; ++n)\r\n        if (isp[n])\
    \ {\r\n            for (int k = n * n; k <= N; k += n * n) {\r\n             \
    \   isp[k] = false;\r\n            }\r\n        }\r\n    isp[2] = isp[3] = true;\r\
    \n\r\n    vector<int> ret;\r\n    for (int i = 2; i <= N; i++)\r\n        if (isp[i])\
    \ {\r\n            ret.push_back(i);\r\n        }\r\n    return ret;\r\n}\r\n\r\
    \n/**\r\n * @brief Prime Sieve\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Math/sieve.hpp
  requiredBy:
  - Convolution/divisor.hpp
  - Math/lucydp.hpp
  - Math/lpftable.hpp
  - Math/mobius.hpp
  - Math/powertable.hpp
  - Math/totient.hpp
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/LC_sum_of_exponential_times_polynomial_limit.test.cpp
  - Verify/LC_lcm_convolution.test.cpp
  - Verify/LC_gcd_convolution.test.cpp
  - Verify/LC_sum_of_exponential_times_polynomial.test.cpp
  - Verify/YUKI_1781.test.cpp
  - Verify/LC_counting_primes.test.cpp
  - Verify/LC_enumerate_primes.test.cpp
documentation_of: Math/sieve.hpp
layout: document
redirect_from:
- /library/Math/sieve.hpp
- /library/Math/sieve.hpp.html
title: Prime Sieve
---
