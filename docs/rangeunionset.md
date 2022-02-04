## 使い方

`RangeUnionSet()`: 空のデータ構造を作成。テンプレートに型と最大値を指定。
`void insert(T L,T R)`: 半開区間 $[L,R)$ を整数集合に追加。
`void erase(T L,T R)`: 半開区間 $[L,R)$ を整数集合から削除。
`T mex(T x)`: 整数集合の mex を求める。