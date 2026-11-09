*This project has been created as part of the 42 curriculum by riwamoto.*

# ft_printf

## Description

ft_printfは、C標準ライブラリ（libc）の関数である `printf` の一部を実装したものである。
ライブラリは `libftprintf.a` としてビルドされ、宣言は `ft_printf.h` にまとめられる。

**目的**

* C言語の可変長引数関数（variadic functions）に対する理解
* 今後の課題で使用できる自分用のライブラリの作成

**実装範囲**

* 対応する変換指定子は `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%` の9種類
* フラグ（`-` `0` `.` `#` `+` ` `）には対応していない（ボーナスは未実装）
* バッファリングは行わず、出力のたびに `write` を呼び出す

## Instructions

### Directory structure

```
project/
├── includes/
│   └── ft_printf.h
├── src/
│   ├── ft_print_chars.c    # ft_putchar, ft_putstr
│   ├── ft_print_nums.c     # ft_putbase, ft_putnbr, ft_putptr
│   ├── ft_printf.c         # to_convert, ft_printf
│   └── ft_strlen.c         # ft_strlen
├── Makefile
└── README.md
```

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

### Process flow

`ft_printf` は次の手順で処理を行う

1. `va_start` で可変長引数の読み取りを開始する
2. フォーマット文字列を先頭から 1 文字ずつ走査する
3. 通常文字なら `ft_putchar` でそのまま出力する
4. `%` を見つけたら次の文字を読み、変換指定子に対応する関数を呼び出す。引数は `va_arg` で必要な型として取り出す
5. 各関数が返した出力文字数を合計に加算する。いずれかの関数が `-1` を返した時点で処理を打ち切り、`va_end` を呼んで `-1` を返す。
6. フォーマット文字列の終端まで到達したら `va_end` を呼び、出力した文字数の合計を返す。

> [!IMPORTANT]
> * フォーマット末尾の単独の `%` はその次の文字が終端ならばループを終了するようにした。
> * 未定義の変換指定子が来た場合、エラーとして扱い-1を返すようにした
> * 合計文字数がINT_MAXを超える場合、エラーとして扱い-1を返すようにした

#### ft_putchar(int c)

- 1文字を標準出力に書き出し、出力した文字数(成功なら1, 失敗なら-1)を返す関数
- `%c` 以外にも `%%` やフォーマット文字列の `%` 以外の通常文字の出力にも使用
- 引数を `int` で受け取っている理由として、可変長引数において `char` は自動的に `int` に昇格されるので、それをそのまま受け取るために `int` にしている

#### ft_putstr(const char *s)

- 文字列を標準出力に書き出し、出力した文字数を返す関数(失敗時は-1)を返す関数
- Cの規格上、 `printf("%s", NULL)` は未定義動作であるが、glibcでは `(null)` と出力する実装となっていたためそれに合わせて実装した。
- printfの返り値は `int` であるため `INT_MAX` を超える文字数は表現できないため（-1）を返している
- whileでループしている理由は、一回でwriteで転送できるのは最大0x7ffff000バイト(2147479552)、INT＿MAXは2147483647なので一回でINT_MAXを転送できない。そのためその境界値が来た場合、1回目に0x7ffff000バイト書き込み、2回目で残りの数千バイトを書く仕組みにしている。

#### ft_putbase(uintptr_t n, const char *base)

- 数値を任意の基数で出力する関数で、基数文字列baseの長さがそのまま基数となる。
- 基数と各桁にどの文字を使うかを1つの引数で同時に表せるため、`%p` `%d` `%i` `%u` `%x` `%X` でこの関数を使用している。
- 引数を `uintptr_t` にしているのは、64 bit のポインタ値を `%p` で扱うためである。
- 上位の桁から出力するため再帰で n / 基数 を先に処理した

#### ft_putnbr(long n)

- `%d` `%i` 用の符号付き整数を出力するための関数。負の値の場合、 `-` を出力させて符号を反転し、 `ft_putbase` に10進数で任せている。
- 引数の型をlongにしているのは intの範囲が `-2147483648 〜 2147483647` なのでINT_MINをintのまま-nするとオーバーフローしてしまい未定義動作となるのを防ぐため。

#### ft_putptr(void * ptr)

- `%p` 用の関数で `0x` を出力してからアドレスを小文字16進数で出力している。
- `NULL` のとき(nil)となっているのはglibcに合わせた挙動を再現するため。

## Resources

### Reference material

- [va_arg](https://ja.cppreference.com/c/variadic/va_arg): va_argの構造、使用の確認
- [va_list](https://ja.cppreference.com/c/variadic/va_list): va_listの構造、使用の確認
- [va_start](https://ja.cppreference.com/c/variadic/va_start): va_startの構造、使用の確認
- [va_end](https://ja.cppreference.com/c/variadic/va_end): va_endの構造、使用の確認

### How AI was used

* README の構成と文章の見直しに使用した
* `write` の転送上限など、仕様の調査の補助に使用した