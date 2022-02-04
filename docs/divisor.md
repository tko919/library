## 使い方

`void DivisorTransform::zeta(vector<T>& a)`: $a'[n]=\sum_{n \bmod d=0} a[d]$ を計算。 `mobius(vector<T>& a)` は逆変換。
`void MultipleTransform::zeta(vector<T>& a)`: $a'[n]=\sum_{k \bmod n=0} a[k]$ を計算。 `mobius(vector<T>& a)` は逆変換。