## 使い方

`SuffixArray(const T& s)`: $s$ の Suffix Array (**添字:1-indexed,値:0-indexed**) 及び LCP 配列 (**添字:1-indexed**)を作成。  
`array<int,2> search(const T& t)`: $t$ を完全に含むような Suffix Array の index 区間。