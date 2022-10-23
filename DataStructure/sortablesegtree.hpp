#pragma once
#include "DataStructure/segtree.hpp"

template<typename M,typename N,M (*f)(M,M),M (*g)(M,N),M (*m1)(),int LG=30>struct SortableSegmentTree{
    SortableSegmentTree(){}
    SortableSegmentTree(vector<int>& ks,vector<M>& vs):n(ks.size()),seg(n),Es(n){
        rep(i,0,n){
            Ls.insert(i);
            Es[i]=new Elem(ks[i],vs[i]);
            seg.set(i,vs[i]);
        }
        Ls.insert(n);
    }
    void update(int i,int key,M val){
        split(i);
        split(i+1);
        Es[i]=new Elem(key,val);
        seg.set(i,val);
    }  
    M query(int L,int R){
        split(L);
        split(R);
        return seg.query(L,R);
    }
    void sort(int L,int R,bool rev=false){
        split(L);
        split(R);
        int pos=L;
        for(;;){
            pos=*(Ls.upper_bound(pos));
            if(pos>=R)break;
            Es[L]=meld(Es[L],Es[pos]);
            Es[pos]=new Elem();
            seg.set(pos,m1());
            Ls.erase(pos);
        }
        Es[L]->set(rev);
        seg.set(L,Es[L]->value());
    }
private:
    struct Trie{
        Trie *cp[2];
        int sz;
        M val,lav;
        Trie(){cp[0]=cp[1]=nullptr;}
        Trie(int key,M v){cp[0]=cp[1]=nullptr,init(key,v);}
        void init(int key,M v,int lg=LG){
            sz=1;
            val=lav=v;
            if(lg==-1)return;
            if(!cp[key>>lg&1])cp[key>>lg&1]=new Trie();
            cp[key>>lg&1]->init(key,v,lg-1);
        }
        void update(){
            if(!cp[0] and !cp[1])return;
            sz=0;
            val=lav=m1();
            if(cp[0]){
                sz+=cp[0]->sz;
                val=f(val,cp[0]->val);
                lav=f(cp[0]->lav,lav);
            }
            if(cp[1]){
                sz+=cp[1]->sz;
                val=f(val,cp[1]->val);
                lav=f(cp[1]->lav,lav);
            }
        }
        void apply(N x){
            assert(sz==1);
            val=lav=g(val,x);
            if(cp[0])cp[0]->apply(x);
            if(cp[1])cp[1]->apply(x);
        }
    };
    using Tp=Trie*;
    int sz(Tp t){return t?t->sz:0;}
    Tp meld(Tp a,Tp b){
        if(!a)return b;
        if(!b)return a;
        a->cp[0]=meld(a->cp[0],b->cp[0]);
        a->cp[1]=meld(a->cp[1],b->cp[1]);
        a->update();
        return a;
    }
    pair<Tp,Tp> split(Tp t,int k){
        if(k==0)return {nullptr,t};
        if(k==sz(t))return {t,nullptr};
        if(k<sz(t->cp[0])){
            auto [l,tmp]=split(t->cp[0],k);
            auto L=new Trie();
            L->cp[0]=l;
            L->update();
            auto R=new Trie();
            R->cp[0]=tmp,R->cp[1]=t->cp[1];
            R->update();
            return {L,R};
        }
        else{
            auto [tmp,r]=split(t->cp[1],k-sz(t->cp[0]));
            auto L=new Trie();
            auto R=new Trie();
            L->cp[0]=t->cp[0],L->cp[1]=tmp;
            L->update();
            R->cp[1]=r;
            R->update();
            return {L,R};
        }
    }
    struct Elem{
        Tp node;
        bool rev;
        Elem():node(nullptr),rev(0){}
        Elem(int key,M x):node(new Trie(key,x)),rev(0){}
        Elem(Tp t,bool r):node(t),rev(r){}
        void set(bool r){rev=r;}
        void apply(N x){node->apply(x);}
        M value(){return rev?node->lav:node->val;}
    };
    using Ep=Elem*;
    Ep meld(Ep s,Ep t){
        return new Elem(meld(s->node,t->node),0);
    }
    pair<Ep,Ep> split(Ep t,int k){
        if(t->rev)k=sz(t->node)-k;
        auto [L,R]=split(t->node,k);
        if(t->rev)swap(L,R);
        auto LE=new Elem(L,t->rev);
        auto RE=new Elem(R,t->rev);
        return {LE,RE};
    }

    const int n;
    SegmentTree<M,N,f,g,m1> seg;
    set<int> Ls;
    vector<Ep> Es;
    void split(int k){
        if(k>=n)return;
        int pos=*(--Ls.upper_bound(k));
        if(pos==k)return;
        auto [L,R]=split(Es[pos],k-pos);
        Es[pos]=L,Es[k]=R;
        seg.set(pos,Es[pos]->value());
        seg.set(k,Es[k]->value());
        Ls.insert(k);
    }
};

/**
 * @brief Sortable Segment Tree
 */