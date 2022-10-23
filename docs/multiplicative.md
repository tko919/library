## 使い方

`T MultiplicativeSum(ll N)`: **乗法的関数** $f$ について $\sum_{k=1}^N f(k)$ を計算する。テンプレートには
* `T`: 返り値の型
* `T (*pe)(int p,int e)`: $f(p^e)$ を返す関数
* `T (*psum)(ll x)`: $\sum_{p \leq x:\mbox{prime}} f(p)$ を返す関数 ( $x$ は $\lfloor N/d \rfloor$ の形に限られる)