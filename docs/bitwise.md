## 使い方

`void zeta(vector<T>& a)`: $a'[n]=\sum_{k \subset n} a[k]$ を計算。  
`void mobius(vector<T>& a)`: $a[n]=\sum_{k \subset n} a'[k]$ を計算。  
`void fwt(vector<T>& a)`: $a$ と $n$ 次 Hadamard 行列の積を計算。