#pragma once

template<typename T>struct LinkedList{
    struct Node{
        T val;
        Node* head,*tail;
        Node(){}
        Node(T v):val(v),head(nullptr),tail(nullptr){}
    };
    Node* front;
    LinkedList():front(nullptr){}
    Node* insert_back(Node* v,T x){
        if(v==nullptr){
            return front=new Node(x);
        }
        auto to=v->tail;
        auto add=new Node(x);
        v->tail=add;
        add->head=v;
        add->tail=to;
        if(to)to->head=add;
        return add;
    }
    Node* insert_front(Node* v,T x){
        if(v==nullptr){
            return front=new Node(x);
        }
        auto to=v->head;
        auto add=new Node(x);
        if(to)to->tail=add;
        add->head=to;
        add->tail=v;
        v->head=add;
        return add;
    }
    vector<T> dump(){
        vector<T> ret;
        Node* cur=front;
        while(cur){
            ret.push_back(cur->val);
            cur=cur->tail;
        }
        return ret;
    }
};  

/**
 * @brief Linked List
 */