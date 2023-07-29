// Bubble Sort Descending
#include <stdio.h>

void main()
{
    int angka[50], i, j, x, temp;

    printf("Banyak data: ");
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        printf("Masukkan Data Ke-%d: ", i + 1);
        scanf("%d", &angka[i]); //(A) Tentukan Variabel
    }
    // Proses Sorting
    for (i = x - 1; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if (angka[j - 1] < angka[j])
            { //(B) Tentukan Operasi
                temp = angka[j - 1];
                angka[j - 1] = angka[j];
                angka[j] = temp; //(C) Tentukan Variabel
            }
        }
    }
    // Output Hasil
    printf("\nHasil Sorting: ");
    for (i = 0; i < x; i++)
    {
        printf("%d ", angka[i]);
    }
}