#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char nama[50];
    float nilai;
    char nim[15];
};

void selectionSort(struct Mahasiswa mhs[], int n)
{
    int i, j, minIndex;
    struct Mahasiswa temp;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(mhs[j].nama, mhs[minIndex].nama) < 0)
            {
                minIndex = j;
            }
        }
        temp = mhs[i];
        mhs[i] = mhs[minIndex];
        mhs[minIndex] = temp;
    }
}

int main()
{
    int i, n;
    struct Mahasiswa mhs[50];

    printf("Jumlah Mahasiswa : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nMahasiswa %d :\n", i + 1);
        printf("Nama : ");
        scanf("%s", mhs[i].nama);
        printf("Nilai : ");
        scanf("%f", &mhs[i].nilai);
        printf("NIM : ");
        scanf("%s", mhs[i].nim);
    }

    selectionSort(mhs, n);

    printf("\nHasil Pengurutan :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. Nama : %s\n   Nilai : %.2f\n   NIM  : %s\n", i + 1, mhs[i].nama, mhs[i].nilai, mhs[i].nim);
    }

    return 0;
}
