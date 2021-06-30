// #include <stdio.h>
// #include <conio.h>
// #include <math.h>
// #define br printf("\n")
// #define readi(a) scanf("%d", &a)
// #define readf(a) scanf("%f", &a)
// #define readc(a) scanf("%c", &a)
// #define reads(a) scanf("%s", &a)

// void init_code()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }
// int max(int a, int b)
// {
//     if (a > b)
//     {
//         return a;
//     }
//     return b;
// }
// int min(int a, int b)
// {
//     if (a < b)
//     {
//         return a;
//     }
//     return b;
// }
// int abs(int a)
// {
//     if (a < 0)
//     {
//         return -a;
//     }
//     return a;
// }
// int countDig(int a)
// {
//     int ans = 0;
//     while (a > 0)
//     {
//         ans++;
//         a /= 10;
//     }

//     return ans;
// }
// int gcd(int a, int b)
// {
//     if (!a)
//         return b;
//     return gcd(b % a, a);
// }

// void solve()
// {
//     int n;
//     readi(n);
//     int sum = 0;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         readi(arr[i]);
//         sum += arr[i];
//     }

//     printf("%d", sum);
// }

// int main()

// {
//     solve();
//     return 0;
// }

#include <stdio.h>
int main()
{
    int n;
    int i = 2;
    printf("enter number to check if its prime or not\n");
    scanf("%d", &n);
    while (i < n)
    {
        if (n % i == 0)
        {
            printf("this is not a prime number\n");
            return 0;
        }
        i++;
    }
    printf("this is a prime no.\n");
    return 0;
}
