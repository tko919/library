#pragma once

template<typename T,int B=4>class PersistentArray{
    const int M=(1<<B)-1;
    struct Node{
        Node *cp[1<<B]={};
        T val;
    };
    Node* set(int i,T x,Node* a){
        Node *ret=new Node();
        if(a){
            memcpy(ret->cp,a->cp,sizeof(a->cp));
            ret->val=a->val;
        }
        if(i)ret->cp[i&M]=set(i>>B,x,ret->cp[i&M]);
        else ret->val=x;
        return ret;
    }
    T get(int i,Node* a){
        if(i)return get(i>>B,a->cp[i&M]);
        else return a->val;
    }
public:
    Node *root;
    PersistentArray(Node* _r=nullptr):root(_r){}
    void set(int i,T x){
        root=set(i,x,root);
    }
    T get(int i){
        return get(i,root);
    }
};

/**
 * @brief Persistent Array
 */