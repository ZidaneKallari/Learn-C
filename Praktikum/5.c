#include <stdio.h>
#include <string.h>
struct Mahasiswa
{
    char nama[50];
    char nim[20];
    int nilai;
};
int main()
{
    struct Mahasiswa mhs[100];
    int i, j, n;

    printf("Jumlah Mahasiswa : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n%d.\n", i + 1);
        printf("Nama Mahasiswa : ");
        scanf(" %[^\n]", mhs[i].nama);
        printf("NIM Mahasiswa  : ");
        scanf(" %[^\n]", mhs[i].nim);
        printf("Nilai Mahasiswa: ");
        scanf("%d", &mhs[i].nilai);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(mhs[j].nama, mhs[j + 1].nama) > 0)
            {
                struct Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
    printf("\nData Mahasiswa Setelah Diurutkan Berdasarkan Nama secara Ascending:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d.\n", i + 1);
        printf("Nama Mahasiswa : %s\n", mhs[i].nama);
        printf("NIM Mahasiswa  : %s\n", mhs[i].nim);
        printf("Nilai Mahasiswa: %d\n", mhs[i].nilai);
    }

    return 0;
}
