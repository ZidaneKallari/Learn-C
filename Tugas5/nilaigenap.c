#include <stdio.h>

int main()
{
    int n, i;

    printf("Input banyak data: ");
    scanf("%d", &n);

    printf("Nilai genap: ");
    for (i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
