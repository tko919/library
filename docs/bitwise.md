## 使い方

`void zeta(vector<T>& a)`: $a'[n]=\sum_{k \subset n} a[k]$ を計算。  
`void mobius(vector<T>& a)`: $a[n]=\sum_{k \subset n} a'[k]$ を計算。  
`void fwt(vector<T>& a)`: $a$ に $H_K=\begin{cases}
    1 & (K=0) \\
    \begin{bmatrix}
        H_{K-1} & H_{K-1} \\
        H_{K-1} & -H_{K-1}
    \end{bmatrix} & (\mbox{otherwise})
\end{cases}$ で定義される一次変換を施す。