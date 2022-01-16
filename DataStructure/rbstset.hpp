#pragma once

#include "Utility/random.hpp"

Random genRBSTset;
template<typename T>class RBSTset{
    struct Node{
        Node *lp=nullptr,*rp=nullptr;
        int size=1;
        T key;
        Node(T _k=0):key(_k){}
        void apply(){
            size=1;
            if(lp)size+=lp->size;
            if(rp)size+=rp->size;
        }
    };
    Node *root=nullptr;
    int size(Node* x){return x?x->size:0;}
    Node* merge(Node* L,Node* R){
        if(!L)return R;
        if(!R)return L;
        if((int)genRBSTset.get(size(L)+size(R)-1)<size(L)){
            L->rp=merge(L->rp,R);
            L->apply();
            return L;
        }
        else{
            R->lp=merge(L,R->lp);
            R->apply();
            return R;
        }
    }
    array<Node*,2> split(Node* x,int k){
        if(!x)return {nullptr,nullptr};
        if(k==size(x))return {x,nullptr};
        if(k<=size(x->lp)){
            auto [lb,rb]=split(x->lp,k);
            Node *L=lb,*R=x;
            x->lp=rb;
            x->apply();
            return {L,R};
        }
        else{
            auto [lb,rb]=split(x->rp,k-size(x->lp)-1);
            Node *L=x,*R=rb;
            x->rp=lb;
            x->apply();
            return {L,R};
        }
    }
    int lower_bound(Node* x,T v){
        if(!x)return 0;
        if(x->key>=v)return lower_bound(x->lp,v);
        else return size(x->lp)+1+lower_bound(x->rp,v);
    }
    int upper_bound(Node* x,T v){
        if(!x)return -1;
        if(x->key>v)return upper_bound(x->lp,v);
        else return size(x->lp)+1+upper_bound(x->rp,v);
    }
    void _dump(Node* cur,string add){
        if(!cur)return;
        _dump(cur->lp,add+"*");
        cerr<<add<<cur->key<<'\n';
        _dump(cur->rp,add+"*");
    }
public:
    RBSTset(){}
    int size(){return size(root);}
    bool find(T x){
        Node *cur=root;
        for(;;){
            if(!cur)break;
            if(cur->key==x)return true;
            else if(x<cur->key)cur=cur->lp;
            else cur=cur->rp;
        }
        return false;
    }
    void insert(T x){
        int k=lower_bound(root,x);
        auto [L,R]=split(root,k);
        root=merge(merge(L,new Node(x)),R);
    }
    void erase(T x){
        assert(find(x));
        int k=lower_bound(root,x);
        auto [L,t]=split(root,k);
        auto [tmp,R]=split(t,1);
        root=merge(L,R);
    }
    T kth_element(int k){
        if(k>=size(root) or k<0)return -1;
        auto [L,R]=split(root,k);
        Node* cur=R;
        while(cur->lp)cur=cur->lp;
        root=merge(L,R);
        return cur->key;
    }
    T lower_bound(T v){
        return kth_element(lower_bound(root,v));
    }
    T upper_bound(T v){
        return kth_element(upper_bound(root,v));
    }
    void dump(){
        _dump(root,"*");
    }
};

/**
 * @brief Randomized Binary Search Tree (set)
 */