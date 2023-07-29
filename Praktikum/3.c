// Selection Sort Ascending
#include <stdio.h>

void main()
{
    int angka[50], i, j, x, temp, min;

    printf("Banyak data: ");
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        printf("Masukkan Data Ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
    }
    // proses sort
    for (i = 0; i <= x - 2; i++)
    { //(A) Tentukan Operasi
        min = i;
        for (j = i; j <= x - 1; j++)
            if (angka[j] < angka[min])
                min = j; //(B) Tentukan Variabel
        temp = angka[min];
        angka[min] = angka[i];
        angka[i] = temp; //(C) Tentukan Variabel
    }
    // Output Hasil
    printf("\nHasil Sorting: ");
    for (i = 0; i <= x - 1; i++)
    { //(D) Tentukan operasi
        printf("%d ", angka[i]);
    }
}