#include "test.h"

int foo(int a, int b)
{
    return a + b;
}

void bar(int a)
{
    printf("%d\n", a);
}

int foo2(void)
{
    return 0;
}

void bar2(void)
{
    bar(foo(1, 2));
    foo2();
}
