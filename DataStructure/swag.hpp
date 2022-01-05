#pragma once

template<typename M,M (*f)(M,M),M (*m0)()>struct SWAG{
   stack<M> fval,bval; vector<M> fsum,bsum;
   SWAG(){}
   M fold(){
      if(fsum.empty()){
         if(bsum.empty())return m0();
         return bsum.back();
      }else{
         if(bsum.empty())return fsum.back();
         else return f(fsum.back(),bsum.back());
      }
   }
   void push(M x){
      bval.push(x);
      if(bsum.empty())bsum.push_back(x);
      else{
         M y=f(bsum.back(),x);
         bsum.push_back(y);
      }
   }
   void pop(){
      if(fval.empty()){
         bsum.clear();
         while(!bval.empty()){
            auto x=bval.top(); bval.pop();
            fval.push(x);
            if(fsum.empty())fsum.push_back(x);
            else{
               M y=f(x,fsum.back());
               fsum.push_back(y);
            }
         }
      }
      fval.pop(); fsum.pop_back();
   }
};

/**
 * @brief Sliding Window Aggregation
 */