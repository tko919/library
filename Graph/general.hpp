#pragma once

struct GeneralMatch {
    struct edge {
        int u, v;
    };
    int n, res;
    const vector<vector<int>> &g;
    vector<int> mate, idx, p;
    vector<edge> es;
    void rematch(int u, int v) {
        int w = mate[u];
        mate[u] = v;
        if (w == -1 or mate[w] != u)
            return;
        if (es[u].v == -1) {
            mate[w] = es[u].u;
            rematch(es[u].u, w);
        } else {
            rematch(es[u].u, es[u].v);
            rematch(es[u].v, es[u].u);
        }
    }
    bool check(int rt) {
        function<int(int)> f = [&](int x) {
            return (idx[x] != res or p[x] == -1) ? x : (p[x] = f(p[x]));
        };
        queue<int> que;
        que.push(rt);
        p[rt] = -1;
        idx[rt] = res;
        es[rt] = {-1, -1};
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            for (int y : g[x])
                if (y != rt) {
                    if (mate[y] == -1) {
                        mate[y] = x;
                        rematch(x, y);
                        return true;
                    } else if (idx[y] == res) {
                        int u = f(x), v = f(y), w = rt;
                        if (u == v)
                            continue;
                        while (u != rt or v != rt) {
                            if (v != rt)
                                swap(u, v);
                            if (es[u].u == x and es[u].v == y) {
                                w = u;
                                break;
                            }
                            es[u] = {x, y};
                            u = f(es[mate[u]].u);
                        }
                        int t = f(x);
                        while (t != w) {
                            idx[t] = res;
                            p[t] = w;
                            que.push(t);
                            t = f(es[mate[t]].u);
                        }
                        t = f(y);
                        while (t != w) {
                            idx[t] = res;
                            p[t] = w;
                            que.push(t);
                            t = f(es[mate[t]].u);
                        }
                    } else if (idx[mate[y]] != res) {
                        es[y] = {-1, -1};
                        idx[mate[y]] = res;
                        p[mate[y]] = y;
                        es[mate[y]] = {x, -1};
                        que.push(mate[y]);
                    }
                }
        }
        return false;
    }
    GeneralMatch(const vector<vector<int>> &h)
        : g(h), n(h.size()), res(0), mate(h.size(), -1), idx(h.size(), -1),
          p(h.size()), es(h.size()) {
        rep(i, 0, n) if (mate[i] == -1) res += check(i);
    }
};

/**
 * @brief General Matching
 */