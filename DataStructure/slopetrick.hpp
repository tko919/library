#pragma once

template<typename T,T mx>struct SlopeTrick{
    T mn=0,addL=0,addR=0;
    priority_queue<T> L;
    priority_queue<T,vector<T>,greater<T>> R;
    SlopeTrick(){
        L.push(-mx);
        R.push(mx);
    }
    T getmin(){return mn;}
    pair<T,T> argmin(){
        return {L.top()+addL,R.top()+addR};
    }
    void addConst(T a){mn+=a;}
    void addx_a(T a){
        mn+=max(T(0),L.top()+addL-a);
        L.push(a-addL);
        R.push(L.top()+addL-addR);
        L.pop();
    }
    void adda_x(T a){
        mn+=max(T(0),a-(R.top()+addR));
        R.push(a-addR);
        L.push(R.top()+addR-addL);
        R.pop();
    }
    void addAbs(T a){
        addx_a(a);
        adda_x(a);
    }
    void chminRight(){
        priority_queue<T,vector<T>,greater<T>> nxt;
        nxt.push(mx);
        swap(R,nxt);
        addR=0;
    }
    void chminLeft(){
        priority_queue<T> nxt;
        nxt.push(-mx);
        swap(L,nxt);
        addL=0;
    }
    void shiftLeft(T a){
        addL+=a;
    }
    void shiftRight(T a){
        addR+=a;
    }
    void shift(T a){
        shiftRight(a);
        shiftLeft(a);
    }
    T eval(T x_0){
        T y=mn;
        while(!L.empty()){
            auto x=L.top();
            L.pop();
            y+=max(T(0),(x+addL)-x_0);
        }
        while(!R.empty()){
            auto x=R.top();
            R.pop();
            y+=max(T(0),x_0-(x+addR));
        }
        return y;
    }
};

/**
 * @brief Slope Trick
 */