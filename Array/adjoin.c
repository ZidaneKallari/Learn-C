#include <stdio.h>

int main()
{
    int matriks1[10][10], matriks2[10][10], hasil[10][10];
    int baris, kolom, i, j;

    printf("Masukkan jumlah baris dan kolom: ");
    scanf("%d %d", &baris, &kolom);

    printf("Masukkan elemen-elemen matriks pertama:\n");
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            scanf("%d", &matriks1[i][j]);
        }
    }
    printf("Masukkan elemen-elemen matriks kedua:\n");
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            scanf("%d", &matriks2[i][j]);
        }
    }

    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j];
        }
    }

    printf("Hasil pengurangan matriks:\n");
    for (i = 0; i < baris; i++)
    {
        for (j = 0; j < kolom; j++)
        {
            printf("%d\t", hasil[i][j]);
        }
        printf("\n");
    }

    printf("Matriks adjoin:\n");
    for (i = 0; i < kolom; i++)
    {
        for (j = 0; j < baris; j++)
        {
            printf("%d\t", hasil[j][i]);
        }
        printf("\n");
    }

    return 0;
}
