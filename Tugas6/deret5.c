#include <stdio.h>

int main()
{
    int n, i, hasil;

    printf("Input jumlah deret: ");
    scanf("%d", &n);

    hasil = 5;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", hasil);
        hasil = hasil * 5;
    }

    return 0;
}
