#include <stdio.h>

struct Mahasiswa
{
    char nama[50];
    char nim[20];
    int nilai;
};

void inputMhs(struct Mahasiswa mhs[], int n)
{
    if (n == 0)
    {
        return;
    }
    printf("%d. Nama mahasiswa : ", n);
    scanf("%s", mhs[n - 1].nama);
    printf("   NIM : ");
    scanf("%s", mhs[n - 1].nim);
    printf("   Nilai : ");
    scanf("%d", &mhs[n - 1].nilai);
    inputMhs(mhs, n - 1);
}

void tampilMhs(struct Mahasiswa mhs[], int n)
{
    if (n == 0)
    {
        return;
    }
    printf("%d. Nama  : %s\n", n, mhs[n - 1].nama);
    printf("   NIM   : %s\n", mhs[n - 1].nim);
    printf("   Nilai : %d\n", mhs[n - 1].nilai);
    tampilMhs(mhs, n - 1);
}

int main()
{
    int n;
    printf("Banyak Mahasiswa : ");
    scanf("%d", &n);

    struct Mahasiswa mhs[n];
    inputMhs(mhs, n);

    printf("\nData Mahasiswa\n");
    tampilMhs(mhs, n);

    return 0;
}
