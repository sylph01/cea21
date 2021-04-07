# Notes 0407

## must have either zero or one argument

```
complex.cpp:38:11: error: ‘complex complex::operator+(complex, complex)’ must have either zero or one argument
   38 |   complex operator+(complex a, complex b) { return a += b; }
      |           ^~~~~~~~
```

これは complex クラスの中に2引数の operator+ を書いたときに出る。
complex クラスの中に書いた場合、引数のうち1つは暗黙に自分自身であるということになるので、2引数与えると引数が1個余計として怒られる。

## Resource Acquisition is Initialization

* コンストラクタで資源を獲得し
* デストラクタで解放する

ことを指す。
