---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Suffix Automaton
    links: []
  bundledCode: "#line 2 \"String/suffixautomaton.hpp\"\n\nstruct SuffixAutomaton {\n\
    \    struct Node {\n        map<char, int> nxt;\n        int link, len, origin;\n\
    \        Node(int L = 0) : link(-1), len(L) {}\n    };\n    vector<Node> Nodes;\n\
    \    int last, count;\n    SuffixAutomaton() {\n        Nodes.push_back(Node());\n\
    \        Nodes.back().origin = 0;\n        last = count = 0;\n    }\n    void\
    \ push(int c) {\n        int nlast = Nodes.size();\n        Nodes.push_back(Node(Nodes[last].len\
    \ + 1));\n        count += Nodes[last].len + 1;\n        Nodes.back().origin =\
    \ nlast;\n        int cur = last;\n        while (cur != -1 and !Nodes[cur].nxt.count(c))\
    \ {\n            Nodes[cur].nxt[c] = nlast;\n            cur = Nodes[cur].link;\n\
    \        }\n        if (cur == -1)\n            Nodes[nlast].link = 0;\n     \
    \   else {\n            int to = Nodes[cur].nxt[c];\n            if (Nodes[to].len\
    \ == Nodes[cur].len + 1) {\n                Nodes[nlast].link = to;\n        \
    \        count -= Nodes[to].len;\n            } else {\n                int extra\
    \ = Nodes.size();\n                Nodes.push_back(Nodes[to]);\n             \
    \   Nodes.back().len = Nodes[cur].len + 1;\n                Nodes.back().origin\
    \ = to;\n\n                count += Nodes[Nodes[to].link].len;\n             \
    \   if (Nodes[nlast].link != -1)\n                    count += Nodes[Nodes[nlast].link].len;\n\
    \n                Nodes[to].link = Nodes[nlast].link = extra;\n\n            \
    \    count -= Nodes[Nodes[to].link].len;\n                count -= Nodes[Nodes[nlast].link].len;\n\
    \                count += Nodes.back().len - Nodes[Nodes.back().link].len;\n\n\
    \                while (cur != -1 and Nodes[cur].nxt[c] == to) {\n           \
    \         Nodes[cur].nxt[c] = extra;\n                    cur = Nodes[cur].link;\n\
    \                }\n            }\n        }\n        last = nlast;\n    }\n};\n\
    \n/*\n * @brief Suffix Automaton\n */\n"
  code: "#pragma once\n\nstruct SuffixAutomaton {\n    struct Node {\n        map<char,\
    \ int> nxt;\n        int link, len, origin;\n        Node(int L = 0) : link(-1),\
    \ len(L) {}\n    };\n    vector<Node> Nodes;\n    int last, count;\n    SuffixAutomaton()\
    \ {\n        Nodes.push_back(Node());\n        Nodes.back().origin = 0;\n    \
    \    last = count = 0;\n    }\n    void push(int c) {\n        int nlast = Nodes.size();\n\
    \        Nodes.push_back(Node(Nodes[last].len + 1));\n        count += Nodes[last].len\
    \ + 1;\n        Nodes.back().origin = nlast;\n        int cur = last;\n      \
    \  while (cur != -1 and !Nodes[cur].nxt.count(c)) {\n            Nodes[cur].nxt[c]\
    \ = nlast;\n            cur = Nodes[cur].link;\n        }\n        if (cur ==\
    \ -1)\n            Nodes[nlast].link = 0;\n        else {\n            int to\
    \ = Nodes[cur].nxt[c];\n            if (Nodes[to].len == Nodes[cur].len + 1) {\n\
    \                Nodes[nlast].link = to;\n                count -= Nodes[to].len;\n\
    \            } else {\n                int extra = Nodes.size();\n           \
    \     Nodes.push_back(Nodes[to]);\n                Nodes.back().len = Nodes[cur].len\
    \ + 1;\n                Nodes.back().origin = to;\n\n                count +=\
    \ Nodes[Nodes[to].link].len;\n                if (Nodes[nlast].link != -1)\n \
    \                   count += Nodes[Nodes[nlast].link].len;\n\n               \
    \ Nodes[to].link = Nodes[nlast].link = extra;\n\n                count -= Nodes[Nodes[to].link].len;\n\
    \                count -= Nodes[Nodes[nlast].link].len;\n                count\
    \ += Nodes.back().len - Nodes[Nodes.back().link].len;\n\n                while\
    \ (cur != -1 and Nodes[cur].nxt[c] == to) {\n                    Nodes[cur].nxt[c]\
    \ = extra;\n                    cur = Nodes[cur].link;\n                }\n  \
    \          }\n        }\n        last = nlast;\n    }\n};\n\n/*\n * @brief Suffix\
    \ Automaton\n */"
  dependsOn: []
  isVerificationFile: false
  path: String/suffixautomaton.hpp
  requiredBy: []
  timestamp: '2024-06-28 21:40:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/suffixautomaton.hpp
layout: document
redirect_from:
- /library/String/suffixautomaton.hpp
- /library/String/suffixautomaton.hpp.html
title: Suffix Automaton
---
