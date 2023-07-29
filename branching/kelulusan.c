#include <stdio.h>
#include <string.h>

struct nilai_mk
{
    char nama[50];
    char nim[20];
    float nilai;
};

int main()
{
    struct nilai_mk mk;
    printf("Nama : ");
    fgets(mk.nama, 50, stdin);
    printf("NIM : ");
    fgets(mk.nim, 20, stdin);
    printf("Nilai Mata Kuliah Algoritma dan Pemrograman : ");
    scanf("%f", &mk.nilai);

    printf("\n=== OUTPUT ===\n");
    printf("Nama : %s", mk.nama);
    printf("NIM : %s", mk.nim);
    printf("Nilai Mata Kuliah Algoritma dan Pemrograman  : %.2f\n", mk.nilai);

    if (mk.nilai > 0 && mk.nilai <= 50)
    {
        printf("Keterangan : Tidak Lulus\n");
        printf("Anda tidak dapat mengikuti rekruitasi Lab Daskom :(\n");
    }
    else if (mk.nilai > 50 && mk.nilai <= 60)
    {
        printf("Keterangan : C\n");
        printf("Anda tidak dapat mengikuti rekruitasi Lab Daskom :(\n");
    }
    else if (mk.nilai > 60 && mk.nilai <= 65)
    {
        printf("Keterangan : BC\n");
        printf("Anda dapat mengikuti rekruitasi Lab Daskom tapi dipertimbangkan :)\n");
    }
    else if (mk.nilai > 65 && mk.nilai <= 70)
    {
        printf("Keterangan : B\n");
        printf("Anda dapat mengikuti rekruitasi Lab Daskom :)\n");
    }
    else if (mk.nilai > 70 && mk.nilai <= 80)
    {
        printf("Keterangan : AB\n");
        printf("Anda dapat mengikuti rekruitasi Lab Daskom :)\n");
    }
    else if (mk.nilai > 80 && mk.nilai <= 100)
    {
        printf("Keterangan : A\n");
        printf("Selamat anda dapat mengikuti rekruitasi Lab Daskom :D\n");
    }
    else
    {
        printf("Keterangan : Nilai tidak valid\n");
    }

    return 0;
}
