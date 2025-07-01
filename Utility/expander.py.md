---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\"\"\"\nexpander.py: A simple C++ include expander\
    \ for competitive programming.\n\nUsage:\n    python3 expander.py -I library sol.cpp\
    \ > submit.cpp\n\nThis script expands #include \"file\" directives by inlining\
    \ the contents of the files.\nSupported features:\n  - Include directories via\
    \ -I flag\n  - #pragma once handling: files with #pragma once are included only\
    \ once\n\nLimitations:\n  - Only handles #include with double quotes (\"foo.hpp\"\
    ), not angle brackets\n  - Does not process macros or other preprocessor directives\n\
    \"\"\"\nimport os\nimport sys\nimport argparse\nimport re\n\n# Regex to match\
    \ #include \"...\"\nINCLUDE_RE = re.compile(r'^[ \\t]*#include[ \\t]+\"([^\"]+)\"\
    ')\n# Regex to detect pragma once\nPRAGMA_ONCE_RE = re.compile(r'^[ \\t]*#pragma[\
    \ \\t]+once')\n\ndef parse_args():\n    parser = argparse.ArgumentParser(description='Expand\
    \ C++ #include \"...\" directives.')\n    parser.add_argument('-I', dest='include_dirs',\
    \ action='append', default=[],\n                        help='Add directory to\
    \ include search path')\n    parser.add_argument('input', help='Input C++ source\
    \ file')\n    return parser.parse_args()\n\nclass Expander:\n    def __init__(self,\
    \ include_dirs):\n        # Search paths for includes\n        self.include_dirs\
    \ = ['.'] + include_dirs\n        # Track files with pragma once to avoid multiple\
    \ inclusion\n        self.once_files = set()\n        # Track currently expanding\
    \ to detect cycles\n        self.stack = []\n\n    def find_file(self, filename):\n\
    \        for d in self.include_dirs:\n            path = os.path.join(d, filename)\n\
    \            if os.path.isfile(path):\n                return path\n        return\
    \ None\n\n    def expand(self, filepath, out, parent=None):\n        abspath =\
    \ os.path.abspath(filepath)\n        # If already included via #pragma once, skip\n\
    \        if abspath in self.once_files:\n            return\n        # Prevent\
    \ infinite recursion\n        if abspath in self.stack:\n            print(f\"\
    Warning: circular include detected: {filepath}\", file=sys.stderr)\n         \
    \   return\n        self.stack.append(abspath)\n\n        has_pragma_once = False\n\
    \        try:\n            with open(filepath, 'r', encoding='utf-8') as f:\n\
    \                lines = f.readlines()\n        except Exception as e:\n     \
    \       print(f\"Error opening file {filepath}: {e}\", file=sys.stderr)\n    \
    \        self.stack.pop()\n            return\n\n        for line in lines:\n\
    \            # Detect pragma once\n            if PRAGMA_ONCE_RE.match(line):\n\
    \                has_pragma_once = True\n                self.once_files.add(abspath)\n\
    \                continue  # Do not output the pragma\n\n            match = INCLUDE_RE.match(line)\n\
    \            if match:\n                included = match.group(1)\n          \
    \      inc_path = self.find_file(included)\n                if inc_path:\n   \
    \                 # inline expansion\n                    self.expand(inc_path,\
    \ out, parent=filepath)\n                else:\n                    print(f\"\
    Warning: include file not found: {included}\", file=sys.stderr)\n            \
    \    continue\n\n            # Otherwise write the original line\n           \
    \ out.write(line)\n\n        self.stack.pop()\n\n    def run(self, input_file):\n\
    \        self.expand(input_file, sys.stdout)\n\n\ndef main():\n    args = parse_args()\n\
    \    expander = Expander(args.include_dirs)\n    expander.run(args.input)\n\n\
    if __name__ == '__main__':\n    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: Utility/expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utility/expander.py
layout: document
redirect_from:
- /library/Utility/expander.py
- /library/Utility/expander.py.html
title: Utility/expander.py
---
