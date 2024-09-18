---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Timer
    links: []
  bundledCode: "#line 2 \"Utility/timer.hpp\"\n#include <chrono>\r\n\r\nclass timer_\
    \ {\r\n    std::chrono::system_clock::time_point start_;\r\n\r\n  public:\r\n\
    \    timer_() : start_(now()) {}\r\n    static std::chrono::system_clock::time_point\
    \ now() {\r\n        return std::chrono::system_clock::now();\r\n    }\r\n   \
    \ int spent_ms() const {\r\n        auto diff = now() - start_;\r\n        return\
    \ std::chrono::duration_cast<std::chrono::milliseconds>(diff)\r\n            .count();\r\
    \n    }\r\n} timer;\r\n\r\n/**\r\n * @brief Timer\r\n */\n"
  code: "#pragma once\r\n#include <chrono>\r\n\r\nclass timer_ {\r\n    std::chrono::system_clock::time_point\
    \ start_;\r\n\r\n  public:\r\n    timer_() : start_(now()) {}\r\n    static std::chrono::system_clock::time_point\
    \ now() {\r\n        return std::chrono::system_clock::now();\r\n    }\r\n   \
    \ int spent_ms() const {\r\n        auto diff = now() - start_;\r\n        return\
    \ std::chrono::duration_cast<std::chrono::milliseconds>(diff)\r\n            .count();\r\
    \n    }\r\n} timer;\r\n\r\n/**\r\n * @brief Timer\r\n */"
  dependsOn: []
  isVerificationFile: false
  path: Utility/timer.hpp
  requiredBy: []
  timestamp: '2024-09-19 03:09:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/timer.hpp
layout: document
redirect_from:
- /library/Utility/timer.hpp
- /library/Utility/timer.hpp.html
title: Timer
---
