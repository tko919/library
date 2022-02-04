## 使い方

`CHT(vector<T>& ps)`: クエリを与える点を渡してデータ構造を作成。テンプレートに型と最大値を指定。
`void add(T a,T b)`: 直線 $ax+b$ を追加。
`void add_segment(T a,T b,T L,T R)`: 半開区間 $[L,R)$ に線分 $ax+b$ を追加。
`T getmin(T x)`: y 座標の最小値を求める。(無ければ最大値を返す)