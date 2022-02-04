## 使い方

`vector<T> ConvexMinPlusConvolution(vector<T>& a,vector<T>& b)`: $b$ は凸性 ($\forall i,b_i-b_{i-1} \leq b_{i+1}-b_i$) を満たすとし、 $c[n]=\min_{0 \leq k \leq n}a[k]+b[n-k]$ を計算.
