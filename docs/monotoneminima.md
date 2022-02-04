## 使い方

`vector<int> MonotoneMinima(int R,int C,function<bool(int,int,int)> f)`: $R \times C$ 行列の各行で最小値を取る列の index を返す。  
$f(i,j,k)$ は $A_{i,j}$ と $A_{i,k}$ を比較して、 $A_{i,j}$ を採用するなら false ( $A_{i,k}$ を採用するなら true ) を返す関数。