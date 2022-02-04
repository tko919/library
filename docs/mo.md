## 使い方

`Mo(int n)`: 要素数 $n$ のデータ構造を作成。
`void add(int L,int R)`: 半開区間 $[L,R)$ をクエリに追加。
`void run()`: クエリを実行。事前に `addl(int i)` (左側に要素 $i$ を追加)、 `addr(int i)` (右側に要素 $i$ を追加)、 `dell(int i)` (左側の要素 $i$ を削除)、 `delr(int i)` (右側の要素 $i$ を削除)、 `out(int $i$)` (クエリ $i$ の結果を書き込む) を準備する必要がある。