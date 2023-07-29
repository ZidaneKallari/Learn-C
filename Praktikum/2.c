// Insertion Sort Ascending
#include <stdio.h>

void main()
{
    int angka[50], i, j, x, temp; //(A) Tentukan Variabel

    printf("Banyak data: ");
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        printf("Masukkan Data Ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
    }
    // proses sort
    for (i = 0; i <= x - 1; i++)
    {
        temp = angka[i];
        j = i;
        while ((j > 0) && (temp < angka[j - 1]))
        { // Tentukan (B) Sintaks Perulangan dan (C) Operator Boolean
            angka[j] = angka[j - 1];
            j = j - 1;
        }
        angka[j] = temp;
    }
    // Output Hasil
    printf("\nHasil Sorting: ");
    for (i = 0; i < x; i++)
    {
        printf("%d ", angka[i]); //(D) Tentukan Variabel Output
    }
}