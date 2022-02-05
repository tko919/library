## 使い方

`SlopeTrick()`: 空のデータ構造を作成。  
`T getmin()`: 凸関数の最小値。  
`pair<T,T> argmin()`: 凸関数の最小値となる $x$ の閉区間。  
`void addConst(T a)`: $y=a$ を凸関数に加算。  
`void addx_a(T a)`: $y=\max(0,x-a)$ を凸関数に加算。  
`void adda_x(T a)`: $y=\max(0,a-x)$ を凸関数に加算。  
`void addAbs(T a)`: $y=|x-a|$ を凸関数に加算。  
`void chminRight()`: 正の方向に向かって累積最小値を取る。  
`void chminLeft()`: 負の方向に向かって累積最小値を取る。  
`void shiftLeft(T a)`: $g(x)=\max_{t \in [x-a,x]} f(t)(0 \leq a),\min_{t \in [x,x-a]} f(t)(0>a)$ を計算。  
`void shiftRight(T a)`: $g(x)=\min_{t \in [x-a,x]} f(t)(0 \leq a),\max_{t \in [x,x-a]} f(t)(0>a)$ を計算。  
`void shift(T a)`: $g(x)=f(x-a)$ を計算。  
`T eval(T x_0)`: $x=x_0$ での値を計算。(破壊的)