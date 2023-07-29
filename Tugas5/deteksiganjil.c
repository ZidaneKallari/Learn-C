#include <stdio.h>

int main()
{
    int n, i, num;
    int p = 0;

    printf("Input jumlah data: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Nilai ke-%d: ", i);
        scanf("%d", &num);

        if (num % 2 == 1)
        {
            p = 1;
        }
    }

    if (p == 1)
    {
        printf("Terdapat angka ganjil dalam serangkaian input.\n");
    }
    else
    {
        printf("Tidak terdapat angka ganjil dalam serangkaian input.\n");
    }

    return 0;
}
