#pragma once

template<typename T>struct MultiEval{
    int m,n; vector<Poly<T>> t;
    MultiEval(vector<T>& v){
        m=v.size(),n=1; while(n<m)n<<=1;
        t.resize(n<<1);
        rep(i,0,n){
            T w=(i<m?v[i]:0);
            t[n+i]=Poly<T>({-w,T(1)});
        }
        for(int i=n-1;i;i--)t[i]=t[i*2]*t[i*2+1];
    }
    vector<T> run(const vector<T>& f){
        if(f.empty())return vector<T>(m);
        vector<Poly<T>> c(n*2);
        auto v=t[1].rev();
        v.resize(f.size());
        v=v.inv().rev()*Poly<T>(f);
        v.erase(v.begin(),v.begin()+f.size()-1);
        v.resize(n); reverse(ALL(v)); c[1]=v;
        rep(i,1,n){
            int d=c[i].size();
            rep(k,0,2){
                auto add=t[i*2+(k^1)];
                add.resize(d/2+1);
                add=add.rev();
                add*=c[i];
                add.resize(d);
                c[i*2+k]=vector<T>(add.begin()+d/2,add.end());
            }
        }
        vector<T> res(m); rep(i,0,m)res[i]=c[n+i][0];
        return res;
    }
    vector<T> build(vector<T>& ys){
        auto w=t[1].rev();
        w.resize(m+1);
        auto vs=run(w.rev().diff());
        rep(i,0,m)ys[i]/=vs[i];
        vector<Poly<T>> c(n*2);
        rep(i,0,n){
            if(i<m)c[n+i]=Poly<T>({ys[i]});
            else c[n+i]=Poly<T>({T()});
        }
        for(int i=n-1;i;i--)c[i]=c[i*2]*t[i*2+1]+c[i*2+1]*t[i*2];
        c[1]=vector<T>(c[1].begin()+(n-m),c[1].end());
        c[1].resize(m);
       return c[1];
    }
};

template <typename T> struct MultievalWithNTT {
    int m, n;
    vector<Poly<T>> t;
    NTT<T> trans;

    MultievalWithNTT(const vector<T> &v) : m(v.size()), n(1) {
        while (n < m)
            n <<= 1;
        assert(2LL * n <= (1LL << NTT<T>::rank2));

        // t[i] is the NTT of the reversed product polynomial of node i.
        // Its size is twice the number of leaves below the node.
        t.resize(n << 1);
        for (int i = 0; i < n; i++) {
            T x = i < m ? v[i] : T(0);
            t[n + i] = Poly<T>({T(1), -x});
            trans.ntt(t[n + i]);
        }
        for (int i = n - 1; i; i--) {
            Poly<T> l = t[i << 1], r = t[i << 1 | 1];
            trans.doubling(l);
            trans.doubling(r);
            t[i].resize(l.size());
            for (int j = 0; j < (int)l.size(); j++)
                t[i][j] = l[j] * r[j];
        }
    }

    vector<T> run(const vector<T> &f) {
        if (f.empty())
            return vector<T>(m);

        Poly<T> root_rev = t[1];
        trans.ntt(root_rev, 1);
        root_rev.resize(f.size());
        root_rev = root_rev.inv().rev() * Poly<T>(f);
        root_rev.erase(root_rev.begin(), root_rev.begin() + f.size() - 1);
        root_rev.resize(n);
        reverse(ALL(root_rev));

        vector<Poly<T>> c(n << 1);
        c[1] = root_rev;
        for (int i = 1; i < n; i++) {
            int d = c[i].size();
            Poly<T> fc = c[i];
            trans.ntt(fc);
            for (int k = 0; k < 2; k++) {
                Poly<T> prod(d);
                const auto &sibling = t[i * 2 + (k ^ 1)];
                for (int j = 0; j < d; j++)
                    prod[j] = fc[j] * sibling[j];
                trans.ntt(prod, 1);
                c[i * 2 + k] =
                    vector<T>(prod.begin() + d / 2, prod.end());
            }
        }

        vector<T> res(m);
        for (int i = 0; i < m; i++)
            res[i] = c[n + i][0];
        return res;
    }

    vector<T> build(vector<T> &ys) {
        assert((int)ys.size() >= m);

        Poly<T> root_rev = t[1];
        trans.ntt(root_rev, 1);
        root_rev.resize(m + 1);
        auto den = run(root_rev.rev().diff());
        for (int i = 0; i < m; i++)
            ys[i] /= den[i];

        // c[i] is the NTT of the reversed interpolation numerator below i.
        // Its size equals the number of leaves below the node.
        vector<Poly<T>> c(n << 1);
        for (int i = 0; i < n; i++) {
            c[n + i].resize(1);
            if (i < m)
                c[n + i][0] = ys[i];
        }
        for (int i = n - 1; i; i--) {
            trans.doubling(c[i << 1]);
            trans.doubling(c[i << 1 | 1]);
            int d = c[i << 1].size();
            c[i].resize(d);
            for (int j = 0; j < d; j++)
                c[i][j] = c[i << 1][j] * t[i << 1 | 1][j] +
                          c[i << 1 | 1][j] * t[i << 1][j];
        }

        trans.ntt(c[1], 1);
        c[1].resize(m);
        reverse(ALL(c[1]));
        return c[1];
    }
};

/**
 * @brief Multipoint Evaluation
 */
