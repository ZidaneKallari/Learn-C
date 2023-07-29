#include <stdio.h>

int main()
{
    int n, i;
    int fib[100] = {0, 1};

    printf("Input jumlah deret: ");
    scanf("%d", &n);

    for (i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);
    }

    return 0;
}
