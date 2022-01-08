#pragma once

vector<int> Manacher(const string& s){
   string t;
   for(auto& c:s){
      t.push_back(c);
      t.push_back('$');
   }
   t.pop_back();
   int i=0,j=0,n=t.size(); vector<int> res(n);
   while(i<n){
      while(i-j>=0 and i+j<n and t[i-j]==t[i+j])j++;
      res[i]=j;
      int k=1;
      while(i-k>=0 and i+k<n and k+res[i-k]<j){
         res[i+k]=res[i-k]; k++;
      }
      i+=k; j-=k;
   }
   for(int i=0;i<n;i++){
      if(i&1)res[i]=(res[i]/2)*2;
      else res[i]=((res[i]+1)/2)*2-1;
   }
   return res;
}

/**
 * @brief Manacher Algorithm
 */