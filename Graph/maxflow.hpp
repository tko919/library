#pragma once

struct MaxFlow {
    struct Edge {
        int to, rev;
        ll cap;
    };
    int V;
    vector<vector<Edge>> G;
    vector<int> itr, level;
    using P = pair<int, int>;
    vector<P> es;

  public:
    MaxFlow() {}
    MaxFlow(int V) : V(V) {
        G.assign(V, vector<Edge>());
    }
    int add_vertex() {
        G.push_back(vector<Edge>());
        return V++;
    }
    void add_edge(int from, int to, ll cap) {
        int fid = SZ(G[from]), tid = SZ(G[to]);
        if (from == to)
            tid++;
        es.push_back({from, fid});
        G[from].push_back({to, tid, cap});
        G[to].push_back({from, fid, 0});
    }
    struct Type {
        int from, to;
        ll cap, recap;
    };
    Type get_edge(int i) {
        auto [from, pos] = es[i];
        auto e = G[from][pos];
        auto re = G[e.to][e.rev];
        return Type{from, e.to, e.cap, re.cap};
    }
    void bfs(int s) {
        level.assign(V, -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    ll dfs(int v, int t, ll f) {
        if (v == t)
            return f;
        for (int &i = itr[v]; i < (int)G[v].size(); i++) {
            Edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d, G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    ll run(int s, int t) {
        ll ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            itr.assign(V, 0);
            while ((f = dfs(s, t, INF)) > 0)
                ret += f;
        }
        return ret;
    }
    vector<int> cut() {
        vector<int> ret(V);
        rep(v, 0, V) if (level[v] < 0) ret[v] = 1;
        return ret;
    }
};

/**
 * @brief Maximum Flow
 */