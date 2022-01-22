#pragma once
#include "Utility/random.hpp"

Random genPRBSTset;
template<typename T,int LIM=5010101>struct PRBSTset{
    struct Node{
        Node *lp=nullptr,*rp=nullptr;
        int sz=1;
        T val;
        Node(){}
        void apply(){
            sz=1;
            if(lp)sz+=lp->sz;
            if(rp)sz+=rp->sz;
        }
    };
    using np=Node*;
    Node buf[LIM];
    int pos=0;
    int sz(np root){return root?root->sz:0;}
    np merge(np L,np R){
        if(!L)return R;
        if(!R)return L;
        if(genPRBSTset.uniform()*(sz(L)+sz(R))<sz(L)){
            auto rb=merge(L->rp,R);
            np ret=make(L->val,L->lp,rb);
            return ret;
        }
        else{
            auto lb=merge(L,R->lp);
            np ret=make(R->val,lb,R->rp);
            return ret;
        }
    }
    array<np,2> split(np root,int k){
        if(k<=0)return {nullptr,root};
        if(k>=sz(root))return {root,nullptr};
        if(k<=sz(root->lp)){
            auto [L,lb]=split(root->lp,k);
            np R=make(root->val,lb,root->rp);
            return {L,R};
        }
        else{
            auto [rb,R]=split(root->rp,k-1-sz(root->lp));
            np L=make(root->val,root->lp,rb);
            return {L,R};
        }
    }
    bool find(np root,T v){
        if(!root)return false;
        if(root->val==v)return true;
        else if(root->val>v)return find(root->lp,v);
        else return find(root->rp,v);
    }
    int lower_bound(np root,T v){
        if(!root)return 0;
        if(root->val>v)return lower_bound(root->lp,v);
        else return sz(root->lp)+1+lower_bound(root->rp,v);
    }
    int upper_bound(np root,T v){
        if(!root)return 0;
        if(root->val>=v)return upper_bound(root->lp,v);
        else return sz(root->lp)+1+upper_bound(root->rp,v);
    }
    np make(T v,np L=nullptr,np R=nullptr){
        np ret=&buf[pos++];
        ret->val=v;
        ret->lp=L;
        ret->rp=R;
        ret->apply();
        return ret;
    }
    void dfs(np root,vector<T>& a){
        if(!root)return;
        dfs(root->lp,a);
        a.push_back(root->val);
        dfs(root->rp,a);
    }
    np rebuild(np root){
        if(pos<LIM*.95)return root;
        vector<T> tmp;
        dfs(root,tmp);
        return build(tmp);
    }
    np insert(np root,T v){
        int k=lower_bound(root,v);
        auto [L,R]=split(root,k);
        return merge(merge(L,make(v)),R);
    }
    np erase(np root,T v){
        int k=lower_bound(root,v);
        auto [L,rb]=split(root,k);
        auto [tmp,R]=split(rb,1);
        return merge(L,R);
    }
    T kth_elem(np root,int k){
        assert(k<=0 and k<sz(root));
        if(sz(root->lp)==k)return root->val;
        else if(sz(root->lp)>k)return kth_elem(root->lp,k);
        else return kth_elem(root->rp,k-1-sz(root->lp));
    }
    np build(vector<T>& a){
        np root=nullptr;
        for(auto& x:a)root=merge(root,make(x));
        return root;
    }
    void dump(np root){
        if(!root)return;
        dump(root->lp);
        cerr<<root->val<<'\n';
        dump(root->rp);
    }
};

/**
 * @brief Persistent Randomized Binary Search Tree (set)
 */