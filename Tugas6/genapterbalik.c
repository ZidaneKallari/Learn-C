#include <stdio.h>

int main()
{
    int n, i;

    printf("Input jumlah deret: ");
    scanf("%d", &n);

    for (i = 2 * n - 2; i >= 0; i -= 2)
    {
        printf("%d ", i);
    }

    return 0;
}
