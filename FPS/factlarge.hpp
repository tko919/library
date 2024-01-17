#pragma once
#include "FPS/samplepointshift.hpp"

template <typename T> struct FactLarge {
    static constexpr int LOG_BLOCK_SIZE = 9;
    static constexpr int BLOCK_SIZE = 1 << LOG_BLOCK_SIZE;
    static constexpr int BLOCK_NUM = T::get_mod() >> LOG_BLOCK_SIZE;
    static inline vector<T> buf;
    static T fact(int n) {
        if (buf.empty())
            run();
        int q = n / BLOCK_SIZE, r = n % BLOCK_SIZE;
        T ret;
        if (r * 2 <= BLOCK_SIZE) {
            ret = buf[q];
            rep(i, n + 1 - r, n + 1) ret *= i;
        } else if (q != BLOCK_NUM) {
            ret = buf[q + 1];
            T den = 1;
            rep(i, 1, BLOCK_SIZE - r + 1) den *= n + i;
            ret /= den;
        } else {
            ret = T::get_mod() - 1;
            T den = 1;
            rep(i, n + 1, T::get_mod()) den *= i;
            ret /= den;
        }
        return ret;
    }

  private:
    static void run() {
        vector<T> f(2);
        f[0] = 1, f[1] = 3;
        for (int x = 2; x < BLOCK_SIZE; x <<= 1) {
            auto ext = SamplePointsShift(f, T(x), x * 3);
            vector<T> g(x * 2);
            rep(j, 0, x >> 1) g[j] =
                f[j * 2] * f[j * 2 + 1] * ((2 * j + 1) * x);
            rep(j, x >> 1, x * 2) g[j] =
                ext[j * 2 - x] * ext[j * 2 + 1 - x] * ((2 * j + 1) * x);
            swap(f, g);
        }
        if (BLOCK_NUM > BLOCK_SIZE) {
            auto add =
                SamplePointsShift(f, T(BLOCK_SIZE), BLOCK_NUM - BLOCK_SIZE);
            f.insert(f.end(), ALL(add));
        } else
            f.resize(BLOCK_NUM);
        rep(i, 0, BLOCK_NUM) f[i] *= T(i + 1) * BLOCK_SIZE;
        buf = vector<T>(BLOCK_NUM + 1);
        buf[0] = 1;
        rep(i, 0, BLOCK_NUM) buf[i + 1] = buf[i] * f[i];
    }
};

/**
 * @brief Factorial (Large)
 */