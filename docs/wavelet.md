## 使い方

`WaveletMatrix(vector<T> a)`: 数列 $a$ のデータ構造を作成。  
`int rank(int L,int R,T x)`: 半開区間 $[L,R)$ に $x$ が出現する回数。  
`T quantile(int L,int R,int k)`: 半開区間 $[L,R)$ で $k$ 番目 (0-indexed) に小さい値。  
`int freq(int L,int R,T x)`: 半開区間 $[L,R)$ に $x$ 未満が出現する回数。  
`int freq(int L,int R,T a,T b)`: 半開区間 $[L,R)$ に $[a,b]$ 内の値が出現する回数。  
`T prev(int L,int R,T x)`: 半開区間 $[L,R)$ で $x$ 以下の値のうち最も大きいもの。  
`T next(int L,int R,T x)`: 半開区間 $[L,R)$ で $x$ より大きい値のうち最も小さいもの。