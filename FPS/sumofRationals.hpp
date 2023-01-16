#pragma once

template<typename T>pair<Poly<T>,Poly<T>> SumOfRationals(vector<pair<Poly<T>,Poly<T>>>& fs){
    using Ratio=pair<Poly<T>,Poly<T>>;
    if(fs.empty())return {Poly<T>({T(1)}),Poly<T>({T(1)})};
    sort(ALL(fs),[&](Ratio& a,Ratio& b){return a.first.size()+a.second.size()<b.first.size()+b.second.size();});
    deque<Ratio> deq;
    for(auto& f:fs)deq.push_back(f);
    while(deq.size()>1){
        auto [f,g]=deq[0];
        auto [p,q]=deq[1];
        deq.push_back({f*q+g*p,g*q});
        deq.pop_front();
        deq.pop_front();
    }
    return deq[0];
}

/**
 * @brief Sum of Rationals
*/