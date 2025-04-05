---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Visualizer
    links:
    - http://www.w3.org/2000/svg\">\n
  bundledCode: "#line 2 \"Utility/visualizer.hpp\"\n\nstruct Vis {\n    double W;\n\
    \    ofstream ofs;\n    Vis(double L, double D, double width, double height, string\
    \ s = \"vis.html\")\n        : W(width) {\n        L *= .01;\n        D *= .01;\n\
    \        width *= .01;\n        height *= .01;\n        ofs = ofstream(s.c_str());\n\
    \        ofs << \"<svg viewBox=\\\"\";\n        ofs << L << \" \" << D << \" \"\
    \ << width << \" \" << height;\n        ofs << \" \\\" xmlns=\\\"http://www.w3.org/2000/svg\\\
    \">\\n\";\n    }\n    void line(pair<double, double> p, pair<double, double> q,\n\
    \              string col = \"black\") {\n        string out = \"<line x1=\\\"\
    \" + to_string(p.first * .01) + \"\\\" y1=\\\"\" +\n                     to_string(p.second\
    \ * .01) + \"\\\" x2=\\\"\" +\n                     to_string(q.first * .01) +\
    \ \"\\\" y2=\\\"\" +\n                     to_string(q.second * .01) + \"\\\"\
    \ stroke=\\\"\" + col +\n                     \"\\\" />\\n\";\n        ofs <<\
    \ out;\n    }\n    void polygon(vector<pair<int, int>> poly, string col = \"black\"\
    ) {\n        string out = \"<polygon points =\\\"\";\n        for (auto &[x, y]\
    \ : poly)\n            out += to_string(double(x) * .01) + \",\" +\n         \
    \          to_string(double(y) * .01) + \" \";\n        out += \"\\\" fill=\\\"\
    \" + col + \"\\\" />\\n\";\n        ofs << out;\n    }\n    void point(double\
    \ x, double y, int id = -1, string col = \"black\") {\n        x *= .01;\n   \
    \     y *= .01;\n        double rad = W * .0001;\n        string out = \"<circle\
    \ cx=\\\"\" + to_string(x) + \"\\\" cy=\\\"\" + to_string(y);\n        out +=\
    \ \"\\\" r=\\\"\" + to_string(rad) + \"\\\" fill=\\\"\" + col + \"\\\" />\\n\"\
    ;\n        ofs << out;\n        if (id != -1) {\n            out = \"<text x =\
    \ \\\"\" + to_string(x) + \"\\\" y = \\\"\" + to_string(y) +\n               \
    \   \"\\\" font-size =\\\"\" + to_string(rad) +\n                  \"\\\" text-anchor\
    \ = \\\"middle\\\" dy =\\\".3em\\\" fill=\\\"white\\\" \"\n                  \"\
    >\" +\n                  to_string(id) + \"</text>\\n\";\n            ofs << out;\n\
    \        }\n    }\n    ~Vis() {\n        ofs << \"</svg>\\n\";\n        ofs.close();\n\
    \    }\n};\n\n/**\n * @brief Visualizer\n */\n"
  code: "#pragma once\n\nstruct Vis {\n    double W;\n    ofstream ofs;\n    Vis(double\
    \ L, double D, double width, double height, string s = \"vis.html\")\n       \
    \ : W(width) {\n        L *= .01;\n        D *= .01;\n        width *= .01;\n\
    \        height *= .01;\n        ofs = ofstream(s.c_str());\n        ofs << \"\
    <svg viewBox=\\\"\";\n        ofs << L << \" \" << D << \" \" << width << \" \"\
    \ << height;\n        ofs << \" \\\" xmlns=\\\"http://www.w3.org/2000/svg\\\"\
    >\\n\";\n    }\n    void line(pair<double, double> p, pair<double, double> q,\n\
    \              string col = \"black\") {\n        string out = \"<line x1=\\\"\
    \" + to_string(p.first * .01) + \"\\\" y1=\\\"\" +\n                     to_string(p.second\
    \ * .01) + \"\\\" x2=\\\"\" +\n                     to_string(q.first * .01) +\
    \ \"\\\" y2=\\\"\" +\n                     to_string(q.second * .01) + \"\\\"\
    \ stroke=\\\"\" + col +\n                     \"\\\" />\\n\";\n        ofs <<\
    \ out;\n    }\n    void polygon(vector<pair<int, int>> poly, string col = \"black\"\
    ) {\n        string out = \"<polygon points =\\\"\";\n        for (auto &[x, y]\
    \ : poly)\n            out += to_string(double(x) * .01) + \",\" +\n         \
    \          to_string(double(y) * .01) + \" \";\n        out += \"\\\" fill=\\\"\
    \" + col + \"\\\" />\\n\";\n        ofs << out;\n    }\n    void point(double\
    \ x, double y, int id = -1, string col = \"black\") {\n        x *= .01;\n   \
    \     y *= .01;\n        double rad = W * .0001;\n        string out = \"<circle\
    \ cx=\\\"\" + to_string(x) + \"\\\" cy=\\\"\" + to_string(y);\n        out +=\
    \ \"\\\" r=\\\"\" + to_string(rad) + \"\\\" fill=\\\"\" + col + \"\\\" />\\n\"\
    ;\n        ofs << out;\n        if (id != -1) {\n            out = \"<text x =\
    \ \\\"\" + to_string(x) + \"\\\" y = \\\"\" + to_string(y) +\n               \
    \   \"\\\" font-size =\\\"\" + to_string(rad) +\n                  \"\\\" text-anchor\
    \ = \\\"middle\\\" dy =\\\".3em\\\" fill=\\\"white\\\" \"\n                  \"\
    >\" +\n                  to_string(id) + \"</text>\\n\";\n            ofs << out;\n\
    \        }\n    }\n    ~Vis() {\n        ofs << \"</svg>\\n\";\n        ofs.close();\n\
    \    }\n};\n\n/**\n * @brief Visualizer\n */"
  dependsOn: []
  isVerificationFile: false
  path: Utility/visualizer.hpp
  requiredBy: []
  timestamp: '2025-04-06 06:46:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/visualizer.hpp
layout: document
redirect_from:
- /library/Utility/visualizer.hpp
- /library/Utility/visualizer.hpp.html
title: Visualizer
---
