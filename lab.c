#include <stdio.h>
#include <conio.h>
#include <strings.h>
#include <string.h>
#include <math.h>
#include <strings.h>
#define br printf("\n")
#define readi(a) scanf("%d", &a)
#define readf(a) scanf("%f", &a)
#define readc(a) scanf("%c", &a)
#define reads(a) scanf("%s", &a)
#define readarr(a, n)           \
	for (int i = 0; i < n; i++) \
	{                           \
		readi(a[i]);            \
	}
#define printarr(a, n)          \
	for (int i = 0; i < n; i++) \
	{                           \
		printf("%d ", a[i]);    \
	}
#define read2darr(a, n, m)          \
	for (int i = 0; i < n; i++)     \
	{                               \
		for (int i = 0; i < m; i++) \
		{                           \
			readi(a[i][j]);         \
		}                           \
	}
	
int main()
{
	printf("%d", show());
	return 0;
}

int show()
{
	return 15;
}
