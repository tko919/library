oj-bundle sol.cpp -I ~/code/kyopro/library > submit.cpp
g++-11 -std=gnu++20 -mtune=native -march=native -O2 -g -Wall -Wextra -Wno-unused-result -Wfatal-errors -fsanitize=undefined,address -fsplit-stack -DLOCAL -o a.out ~/code/kyopro/submit.cpp -I .

# -O3
# -I /usr/include/eigen3