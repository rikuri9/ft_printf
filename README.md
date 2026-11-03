*This project has been created as part of the 42 curriculum by riwamoto.*

# ft_printf

## Description

ft_printfは、C標準ライブラリ（libc）の関数である `printf` の一部を実装したものである。
ライブラリは `libftprintf.a` としてビルドされ、宣言は `ft_printf.h` にまとめられる。

**目的**

* C言語の可変長引数関数（variadic functions）に対する理解
* 今後の課題で使用できる自分用のライブラリの作成

## Instructions

### Compile

リポジトリのルートで下記コマンドを実行する。

```bash
make            # (make all) libftprintf.a を作成
make clean      # オブジェクトファイルを削除
make fclean     # オブジェクトファイルと libftprintf.a を削除
make re         # fclean して再ビルド
```

### Usage

```c
// main.c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! %d\n", "world", 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror -I includes main.c libftprintf.a
./a.out
```

実行結果

```
Hello, world! 42
```

### Library details

| 変換指定子 | 内容 |
| --- | --- |
| %c | 1文字を出力 |
| %s | 文字列を出力 |
| %p | `void *` 型のポインタ引数を16進数形式で出力 |
| %d | 10進数の数値を出力 |
| %i | 10進数の整数を出力 |
| %u | 符号なし10進数の数値を出力 |
| %x | 数値を16進数（小文字）で出力 |
| %X | 数値を16進数（大文字）で出力 |
| %% | `%` を出力 |

## Algorithm and data structure

```
project/
├── includes/
|   └── ft_printf.h
├── src/
|   ├── ft_print_chars.c    # ft_putchar, ft_putstr
|   ├── ft_print_nums.c     # ft_putbase, ft_putnbr, ft_putptr
|   ├── ft_printf.c
|   └── ft_strlen.c
├── Makefile
└── README.md
```

#### ft_putchar(int c)

- 1文字を標準出力に書き出し、出力した文字数(成功なら1, 失敗なら-1)を返す関数
- `%c` 以外にも `%%` やフォーマット文字列の `%` 以外の通常文字の出力にも使用
- 引数を `int` で受け取っている理由として、可変長引数において `char` は自動的に `int` に昇格されるので、それをそのまま受け取るために `int` にしている

#### ft_putstr(const char *s)

- 文字列を標準出力に書き出し、出力した文字数を返す関数(-1)を返す関数
- Cの規格上、 `printf("%s", NULL)` は未定義動作であるが、glibcでは `(null)` と出力する実装となっていたためそれに合わせて実装した。
- printfの返り値は `int` であるため `INT_MAX` を超える文字数は表現できないため（-1）を返している
- whileでループしている理由は、一回でwriteで転送できるのは最大0x7ffff000バイト(2147479552)、INT＿MAXは2147483647なので一回でINT_MAXを転送できない。そのためその境界値が来た場合、1回目に0x7ffff000バイト書き込み、2回目で残りの数千バイトを書く仕組みにしている。

#### ft_putbase(unsigned long n, const char *base)

- 数値を任意の基数で出力する関数で、基数文字列baseの長さがそのまま基数となる。
- 基数と各桁にどの文字を使うかを1つの引数で同時に表せるため、`%p` `%d` `%i` `%u` `%x` `%X` でこの関数を使用している。

#### ft_putnbr(long n)

- `%d` `%i` 用の符号付き整数を出力するための関数。負の値の場合、 `-` を出力させて符号を反転し、 `ft_putbase` に10進数で任せている。
- 引数の型をlongにしているのは intの範囲が `-2147483648 〜 2147483647` なのでINT_MINをintのまま-nするとオーバーフローしてしまい未定義動作となるのを防ぐため。

#### ft_putptr(void * ptr)

- `%p` 用の関数で `0x` を出力してからアドレスを小文字16進数で出力している。
- `NULL` のとき(nil)となっているのはglibcに合わせた挙動を再現するため。

### 関数全体としての処理

- 成功したら出力した文字数を `int` で返す
- `write` が失敗したら `-1` を返すようにしている

## Resources

### Reference material



### How AI was used

