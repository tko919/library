## 使い方

`RollbackMo(int n)`: 要素数 $n$ のデータ構造を作成。  
`void add(int L,int R)`: 半開区間 $[L,R)$ をクエリに追加。  
`void run()`: クエリを実行。
* `init()` (初期化)  
* `insert(int i)` (要素 $i$ を追加)  
* `snapshot()` (部分永続的に保存)  
* `rollback()` (保存した状態まで巻き戻す)  
* `out(int $i$)` (クエリ $i$ の結果を書き込む)  
を準備する必要がある。