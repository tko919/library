#pragma once

template<typename M,M (*f)(M,M),M (*m0)()>struct SWAGdeque{
    stack<M> fval,bval;
    vector<M> fsum,bsum;
    SWAGdeque():fsum({m0()}),bsum({m0()}){}
    M fold(){
        return f(fsum.back(),bsum.back());
    }
    void push_front(M v){
        fval.push(v);
        fsum.push_back(f(v,fsum.back()));
    }
    void push_back(M v){
        bval.push(v);
        bsum.push_back(f(bsum.back(),v));
    }
    void pop_front(){
        if(fval.empty()){
            int sz=bval.size();
            stack<M> buf;
            rep(_,0,sz/2){
                buf.push(bval.top());
                bval.pop();
            }
            rep(_,sz/2,sz){
                fval.push(bval.top());
                fsum.push_back(f(bval.top(),fsum.back()));
                bval.pop();
            }
            bsum={m0()};
            while(!buf.empty()){
                bval.push(buf.top());
                bsum.push_back(f(bsum.back(),buf.top()));
                buf.pop();
            }
        }
        fval.pop();
        fsum.pop_back();
    }
    void pop_back(){
        if(bval.empty()){
            int sz=fval.size();
            stack<M> buf;
            rep(_,0,sz/2){
                buf.push(fval.top());
                fval.pop();
            }
            rep(_,sz/2,sz){
                bval.push(fval.top());
                bsum.push_back(f(bsum.back(),fval.top()));
                fval.pop();
            }
            fsum={m0()};
            while(!buf.empty()){
                fval.push(buf.top());
                fsum.push_back(f(buf.top(),fsum.back()));
                buf.pop();
            }
        }
        bval.pop();
        bsum.pop_back();
    }
};

/**
 * @brief Sliding Window Aggregation for deque
 */