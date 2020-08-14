# `dbg(...)`

`dbg.h` is a clumsy duplication of [sharkdp/dbg-macro](https://github.com/sharkdp/dbg-macro), which mainly target for C89.

This project provides a single header file with two macros `dbg(...)` and `dbge(...)` that can be used in all circumstances where you would typically write `printf("...", ...)` or `fprintf(stderr, "...", ...)`.

The `dbg(...)` will prints debugging output to the `stdout`, yet the `dbge(...)` will prints to the `stderr`.

# Example

```c
#include <stdio.h>

#define DBG_H_DEF_ONCE
#include "dbg.h"

static int factorial(int n) {
    if (dbg(n <= 1, %d)) return dbg(1, %d);
    return dbg(n * factorial(n - 1), %d);
}

int main(void) {
    int x = 1;
    dbg(x > 0, %d);
    factorial(4);
    const char *s = "hello world";
    dbg(s, %s);
    dbge(sizeof(double), %zu);
    dbg(&main, %p);
    dbg(main == &main, %d);
    dbg("this line is executed", %s);
    return 0;
}
```

Sample output of above code:

TODO

# Features

* Easy to read, colorized output (colors auto-disable when the output is not an interactive terminal)

* Prints file name, line number, function name and the original expression

* Prints format specifier for the printed-out value (which far less powerful than [sharkdp/dbg-macro](https://github.com/sharkdp/dbg-macro))

* Can be used inside expressions (passing through the original value)

* The dbg.h header issues a compiler warning when included (so you don't forget to remove it)

* Compatible with C89, C99, C11.

# Configuration

* `#define DBG_H_NO_WARNING` to suppress output of the `WARNING: the "dbg.h" header is included in your code base`

* `#define DBG_H_DISABLE` to disable the debugging output, so `dbg(x, fs)` will be simply replaced by `x` itself.

# Stability

The exact output printed by this macro should not be relied upon and is subject to future changes.

# Panics

Panics if writing to `fprintf(3)` fails (by `assert(3)`, so `#define NDEBUG` will disable this panic).

P.S. this is extreme unlikely to happen.

# Courtesy

This project mainly inspired by [sharkdp/dbg-macro](https://github.com/sharkdp/dbg-macro), this project cannot succeeded without his effort.

Part of this README inspired by [sharkdp/dbg-macro](https://github.com/sharkdp/dbg-macro) and Rust's [std::dbg!()](https://doc.rust-lang.org/std/macro.dbg.html).

# TODO

[`_Generic`](https://en.cppreference.com/w/c/language/generic) keyword introduced since C11, we may do better in debugging output.