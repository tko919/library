// len=K,sum=N
template <typename F> void enumerate_multiset(int N, int K, F query) {
    vector<int> A(K);
    auto dfs = [&](auto &dfs, int p, int s) -> void {
        if (p == K) {
            if (s == 0)
                query(A);
            return;
        }
        rep(x, 0, s + 1) {
            A[p] = x;
            dfs(dfs, p + 1, s - x);
        }
    };
    dfs(dfs, 0, N);
}
// sum=N
template <typename F>
void enumerate_partition(int N, F query, int LIM_len = -1, int LIM_val = -1) {
    assert(N >= 0);
    auto dfs = [&](auto self, vector<int> &p, int sum) -> void {
        if (sum == N) {
            query(p);
            return;
        }
        if (LIM_len != -1 && SZ(p) == LIM_len)
            return;
        int nxt = (SZ(p) == 0 ? N : p.back());
        if (LIM_val != -1)
            chmin(nxt, LIM_val);
        chmin(nxt, N - sum);
        p.push_back(0);
        rep(x, 1, nxt + 1) {
            p.back() = x;
            self(self, p, sum + x);
        }
        p.pop_back();
    };
    vector<int> p;
    dfs(dfs, p, 0);
}
// [0,A[i])^n
template <typename F, bool inc = 0>
void enumerate_product(vector<int> A, F query) {
    int N = SZ(A);
    auto dfs = [&](auto &dfs, vector<int> &p) -> void {
        int n = SZ(p);
        if (n == N)
            return query(p);
        int LIM = A[n];
        if (SZ(p) > 0 and inc)
            chmin(LIM, p.back() + 1);
        rep(x, 0, LIM) {
            p.push_back(x);
            dfs(dfs, p);
            p.pop_back();
        }
    };
    vector<int> p;
    dfs(dfs, p);
}

/**
 * @brief Enumerate function
 */