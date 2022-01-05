#pragma once

vector<int> z_algo(string s){
   int n=s.size(); vector<int> res(n);
   for(int i=1,j=0;i<n;i++){
      if(i+res[i-j]<j+res[j])res[i]=res[i-j];
      else{
         int k=max(0,j+res[j]-i);
         while(i+k<n&&s[k]==s[i+k])k++;
         res[i]=k; j=i;
      }
   } res[0]=n; return res;
}

/**
 * @brief Z-Algorithm
 */