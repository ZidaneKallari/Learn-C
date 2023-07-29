#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char nama[50];
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
            if (strcmp(mhs[j].nim, mhs[minIndex].nim) < 0)
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
        printf("\nNama Mahasiswa %d : ", i + 1);
        scanf("%s", mhs[i].nama);
        printf("NIM : ");
        scanf("%s", mhs[i].nim);
    }

    selectionSort(mhs, n);

    printf("\nHasil Pengurutan :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d. Nama : %s\n   NIM  : %s\n", i + 1, mhs[i].nama, mhs[i].nim);
    }

    return 0;
}
