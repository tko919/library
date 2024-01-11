#pragma once

template<typename T>vector<pair<pair<int,int>,T>> MaximalRectangles(vector<T> height){
    int n=height.size();
    height.push_back(0);
    using P=pair<int,int>;
    stack<pair<T,int>> st;
    vector<pair<P,T>> ret;
    rep(i,0,n+1){
        P add{height[i],i};
        if(st.empty() or st.top().first<add.first)st.push(add);
        else{
            int nxt=i;
            while(!st.empty() and st.top().first>=add.first){
                P pre=st.top();
                st.pop();
                nxt=pre.second;
                ret.push_back({{pre.second,i},pre.first});
            }
            add.second=nxt;
            st.push(add);
        }
    }
    return ret;
}

vector<pair<pair<int,int>,pair<int,int>>> MaximalRectangles(vector<vector<int>>& grid){ // 01 grid
    int n=grid.size(),m=grid[0].size();
    using P=pair<int,int>;
    vector<pair<P,P>> ret;
    vector<int> height(m);
    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j])height[j]++;
            else height[j]=0;
        }
        auto add=MaximalRectangles(height);
        for(auto& [DU,h]:add){
            ret.push_back({{i+1-h,i+1},DU});
        }
    }
    return ret;
}

/**
 * @brief Maximal Rectangles
 */