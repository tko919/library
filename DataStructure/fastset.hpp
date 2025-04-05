#pragma once

struct FastSet {
    static constexpr int B = 64;
    int n, lg;
    vector<vector<ull>> seg;
    FastSet(int m) : n(m) {
        do {
            seg.push_back(vector<ull>((m + B - 1) / B));
            m = (m + B - 1) / B;
        } while (m > 1);
        lg = seg.size();
    }
    bool operator[](int i) const {
        return (seg[0][i / B] >> (i % B) & 1);
    }
    void insert(int i) {
        rep(h, 0, lg) {
            seg[h][i / B] |= 1ull << (i % B);
            i /= B;
        }
    }
    void erase(int i) {
        rep(h, 0, lg) {
            seg[h][i / B] &= ~(1ull << (i % B));
            if (seg[h][i / B])
                break;
            i /= B;
        }
    }
    // smallest >= i
    int next(int i) {
        rep(h, 0, lg) {
            if (i / B == seg[h].size())
                break;
            ull d = seg[h][i / B] >> (i % B);
            if (!d) {
                i = i / B + 1;
                continue;
            }
            i += lowbit(d);
            for (int g = h - 1; g >= 0; g--) {
                i *= B;
                i += lowbit(seg[g][i / B]);
            }
            return i;
        }
        return -1;
    }
    // largest <= i
    int prev(int i) {
        rep(h, 0, lg) {
            if (i == -1)
                break;
            ull d = seg[h][i / B] << (63 - i % 64);
            if (!d) {
                i = i / B - 1;
                continue;
            }
            i += topbit(d) - (B - 1);
            for (int g = h - 1; g >= 0; g--) {
                i *= B;
                i += topbit(seg[g][i / B]);
            }
            return i;
        }
        return -1;
    }
};

/**
 * @brief Fast Set
 */