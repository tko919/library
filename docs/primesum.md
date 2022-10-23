## 使い方

`PrimeSum(ll n)`: テンプレートには
* `T`: 返り値の型
* `T (*F)(ll)`: **完全乗法的関数** $f$ のprefix sumを返す関数
を指定。

`T operator[](ll x)`: $\sum_{p \leq x:\mbox{prime}} f(p)$ を出力。 $x=\lfloor n/d \rfloor$ で表される必要がある。