#include <stdio.h>
#include <conio.h>
#include <math.h>
#define br printf("\n")
#define readi(a) scanf("%d", &a)
#define readf(a) scanf("%f", &a)
#define readc(a) scanf("%c", &a)
#define reads(a) scanf("%s", &a)

void init_code()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}
int abs(int a)
{
    if (a < 0)
    {
        return -a;
    }
    return a;
}
int countDig(int a)
{
    int ans = 0;
    while (a > 0)
    {
        ans++;
        a /= 10;
    }

    return ans;
}
int gcd(int a, int b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}

void solve()
{
    int a, b;
    readi(a);
    readi(b);

    printf("%d", gcd(a, b));
}

int main()

{
    solve();
    return 0;
}
