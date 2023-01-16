#pragma once

template<typename T>Poly<T> ProdOfPolys(vector<Poly<T>>& fs){
    if(fs.empty())return Poly<T>({T(1)});
    sort(ALL(fs),[&](Poly<T>& a,Poly<T>& b){return a.size()<b.size();});
    deque<Poly<T>> deq;
    for(auto& f:fs)deq.push_back(f);
    while(deq.size()>1){
        deq.push_back(deq[0]*deq[1]);
        deq.pop_front();
        deq.pop_front();
    }
    return deq[0];
}

/**
 * @brief Product of Polynomials
*/