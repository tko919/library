## 使い方

`void zeta(vector<T>& a)`: $b[n]=\sum_{k \subset n} a[k]$ なる $b$ を計算。  
`void mobius(vector<T>& a)`: $a[n]=\sum_{k \subset n} b[k]$ なる $b$ を計算。  
`void fwt(vector<T>& a)`: $b[n]=\sum_k (-1)^{popcount(n \& k)} a[k]$ なる $b$ を計算。