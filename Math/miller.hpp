#pragma once

struct m64 {
    using i64 = int64_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static u64 mod;
    static u64 r;
    static u64 n2;

    static u64 get_r() {
        u64 ret = mod;
        rep(_,0,5) ret *= 2 - mod * ret;
        return ret;
    }

    static void set_mod(u64 m) {
        assert(m < (1LL << 62));
        assert((m & 1) == 1);
        mod = m;
        n2 = -u128(m) % m;
        r = get_r();
        assert(r * mod == 1);
    }
    static u64 get_mod() { return mod; }

    u64 a;
    m64() : a(0) {}
    m64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};

    static u64 reduce(const u128 &b) {
        return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
    }
    u64 get() const {
        u64 ret = reduce(a);
        return ret >= mod ? ret - mod : ret;
    }
    m64 &operator*=(const m64 &b) {
        a = reduce(u128(a) * b.a);
        return *this;
    }
    m64 operator*(const m64 &b) const { return m64(*this) *= b; }
    bool operator==(const m64 &b) const {
        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
    }
    bool operator!=(const m64 &b) const {
        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
    }
    m64 pow(u128 n) const {
        m64 ret(1), mul(*this);
        while (n > 0) {
        if (n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
        }
        return ret;
    }
};
typename m64::u64 m64::mod, m64::r, m64::n2;

bool Miller(ll n){
    if(n<2 or (n&1)==0)return (n==2);
    m64::set_mod(n);
    ll d=n-1; while((d&1)==0)d>>=1;
    vector<ll> seeds;
    if(n<(1<<30))seeds={2, 7, 61};
    else seeds={2, 325, 9375, 28178, 450775, 9780504};
    for(auto& x:seeds){
        if(n<=x)break;
        ll t=d;
        m64 y=m64(x).pow(t);
        while(t!=n-1 and y!=1 and y!=n-1){
            y*=y;
            t<<=1;
        }
        if(y!=n-1 and (t&1)==0)return 0;
    } return 1;
}

/**
 * @brief Miller-Rabin
 */