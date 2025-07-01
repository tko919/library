#!/usr/bin/env python3
"""
expander.py: A simple C++ include expander for competitive programming.

Usage:
    python3 expander.py -I library sol.cpp > submit.cpp

This script expands #include "file" directives by inlining the contents of the files.
Supported features:
  - Include directories via -I flag
  - #pragma once handling: files with #pragma once are included only once

Limitations:
  - Only handles #include with double quotes ("foo.hpp"), not angle brackets
  - Does not process macros or other preprocessor directives
"""
import os
import sys
import argparse
import re

# Regex to match #include "..."
INCLUDE_RE = re.compile(r'^[ \t]*#include[ \t]+"([^"]+)"')
# Regex to detect pragma once
PRAGMA_ONCE_RE = re.compile(r'^[ \t]*#pragma[ \t]+once')

def parse_args():
    parser = argparse.ArgumentParser(description='Expand C++ #include "..." directives.')
    parser.add_argument('-I', dest='include_dirs', action='append', default=[],
                        help='Add directory to include search path')
    parser.add_argument('input', help='Input C++ source file')
    return parser.parse_args()

class Expander:
    def __init__(self, include_dirs):
        # Search paths for includes
        self.include_dirs = ['.'] + include_dirs
        # Track files with pragma once to avoid multiple inclusion
        self.once_files = set()
        # Track currently expanding to detect cycles
        self.stack = []

    def find_file(self, filename):
        for d in self.include_dirs:
            path = os.path.join(d, filename)
            if os.path.isfile(path):
                return path
        return None

    def expand(self, filepath, out, parent=None):
        abspath = os.path.abspath(filepath)
        # If already included via #pragma once, skip
        if abspath in self.once_files:
            return
        # Prevent infinite recursion
        if abspath in self.stack:
            print(f"Warning: circular include detected: {filepath}", file=sys.stderr)
            return
        self.stack.append(abspath)

        has_pragma_once = False
        try:
            with open(filepath, 'r', encoding='utf-8') as f:
                lines = f.readlines()
        except Exception as e:
            print(f"Error opening file {filepath}: {e}", file=sys.stderr)
            self.stack.pop()
            return

        for line in lines:
            # Detect pragma once
            if PRAGMA_ONCE_RE.match(line):
                has_pragma_once = True
                self.once_files.add(abspath)
                continue  # Do not output the pragma

            match = INCLUDE_RE.match(line)
            if match:
                included = match.group(1)
                inc_path = self.find_file(included)
                if inc_path:
                    # inline expansion
                    self.expand(inc_path, out, parent=filepath)
                else:
                    print(f"Warning: include file not found: {included}", file=sys.stderr)
                continue

            # Otherwise write the original line
            out.write(line)

        self.stack.pop()

    def run(self, input_file):
        self.expand(input_file, sys.stdout)


def main():
    args = parse_args()
    expander = Expander(args.include_dirs)
    expander.run(args.input)

if __name__ == '__main__':
    main()
