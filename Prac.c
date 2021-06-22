#include <stdio.h>
#define readi(a) scanf("%d", &a)

int main()
{
    int a;
    readi(a);

    switch (a)
    {
    case (a > 90):
        printf("A") break;
    case (a > 80):
        printf("B");

    default:
        break;
    }
}