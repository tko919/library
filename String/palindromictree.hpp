#pragma once

template <typename T> struct PalindromicTree {
    struct Node {
        map<char, int> nxt;
        int link, len, id, cnt;
        Node() {}
        Node(int link, int len, int id, int cnt)
            : link(link), len(len), id(id), cnt(cnt) {}
    };
    T S;
    vector<Node> nodes;
    PalindromicTree() {}
    PalindromicTree(const T &S) : S(S) {
        nodes.push_back(Node(0, -1, -1, 0));
        nodes.push_back(Node(0, 0, -1, 0));
        int cur = 0;

        rep(i, 0, SZ(S)) {
            int k = find(i, cur);
            char c = S[i];
            if (nodes[k].nxt.count(c)) {
                cur = nodes[k].nxt[c];
                nodes[cur].cnt++;
                continue;
            }
            nodes[k].nxt[c] = SZ(nodes);
            cur = SZ(nodes);
            nodes.push_back(
                Node(-1, nodes[k].len + 2, i - nodes[k].len - 1, 1));
            if (nodes.back().len == 1)
                nodes.back().link = 1;
            else {
                int n = find(i, nodes[k].link);
                nodes.back().link = nodes[n].nxt[c];
            }
        }
    }
    vector<array<int, 3>> get_freq() {
        vector<array<int, 3>> ret;
        for (int i = SZ(nodes) - 1; i >= 2; i--) {
            ret.push_back({nodes[i].len, nodes[i].id, nodes[i].cnt});
            nodes[nodes[i].link].cnt += nodes[i].cnt;
        }
        return ret;
    }

  private:
    int find(int last, int k) const {
        for (;;) {
            int i = last - 1 - nodes[k].len;
            if (i >= 0 and S[i] == S[last])
                break;
            k = nodes[k].link;
        }
        return k;
    }
};

/**
 * @brief Palindromic Tree
 */