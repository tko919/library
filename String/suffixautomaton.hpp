#pragma once

struct SuffixAutomaton {
    struct Node {
        map<char, int> nxt;
        int link, len, origin;
        Node(int L = 0) : link(-1), len(L) {}
    };
    vector<Node> Nodes;
    vector<int> ord;
    int last, count;
    SuffixAutomaton() {
        Nodes.push_back(Node());
        Nodes.back().origin = 0;
        last = count = 0;
    }
    void push(int c) {
        int nlast = Nodes.size();
        Nodes.push_back(Node(Nodes[last].len + 1));
        count += Nodes[last].len + 1;
        Nodes.back().origin = nlast;
        int cur = last;
        while (cur != -1 and !Nodes[cur].nxt.count(c)) {
            Nodes[cur].nxt[c] = nlast;
            cur = Nodes[cur].link;
        }
        if (cur == -1)
            Nodes[nlast].link = 0;
        else {
            int to = Nodes[cur].nxt[c];
            if (Nodes[to].len == Nodes[cur].len + 1) {
                Nodes[nlast].link = to;
                count -= Nodes[to].len;
            } else {
                int extra = Nodes.size();
                Nodes.push_back(Nodes[to]);
                Nodes.back().len = Nodes[cur].len + 1;
                Nodes.back().origin = to;

                count += Nodes[Nodes[to].link].len;
                if (Nodes[nlast].link != -1)
                    count += Nodes[Nodes[nlast].link].len;

                Nodes[to].link = Nodes[nlast].link = extra;

                count -= Nodes[Nodes[to].link].len;
                count -= Nodes[Nodes[nlast].link].len;
                count += Nodes.back().len - Nodes[Nodes.back().link].len;

                while (cur != -1 and Nodes[cur].nxt[c] == to) {
                    Nodes[cur].nxt[c] = extra;
                    cur = Nodes[cur].link;
                }
            }
        }
        last = nlast;
    }
    void tsort() {
        int n = SZ(Nodes);
        vector<int> deg(n);
        rep(i, 0, n) if (Nodes[i].link >= 0) {
            deg[Nodes[i].link]++;
        }
        queue<int> que;
        rep(i, 0, n) if (deg[i] == 0) {
            que.push(i);
        }
        while (!que.empty()) {
            int i = que.front();
            que.pop();
            ord.push_back(i);
            if (Nodes[i].link >= 0) {
                deg[Nodes[i].link]--;
                if (deg[Nodes[i].link] == 0) {
                    que.push(Nodes[i].link);
                }
            }
        }
    }
};

/*
 * @brief Suffix Automaton
 */