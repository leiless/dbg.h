#include <stdio.h>

#define DBG_DEF_ONCE
#include "dbg.h"

int factorial(int n) {
    if (dbg(n <= 1, %d)) {
        return dbg(1, %d);
    } else {
        return dbg(n * factorial(n - 1), %d);
    }
}

int main(void) {
    int x = 1;
    dbg(x > 0, %d);
    factorial(4);
    const char *s = "hello world";
    dbg(s, %s);
    return 0;
}
