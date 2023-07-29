#include <stdio.h>

int main()
{
    int jumlah_mahasiswa, i;
    char nama[100], kelas[20], nim[20];
    float nilai;

    printf("MASUKKAN JUMLAH MAHASISWA : ");
    scanf("%d", &jumlah_mahasiswa);

    for (i = 1; i <= jumlah_mahasiswa; i++)
    {
        printf("\n=====INPUT DATA MAHASISWA %d=====\n", i);

        printf("Masukkan nama   : ");
        scanf(" %[^\n]s", nama);

        printf("Masukkan kelas  : ");
        scanf(" %[^\n]s", kelas);

        printf("Masukkan NIM    : ");
        scanf(" %[^\n]s", nim);

        printf("Masukkan Nilai Mata Kuliah Algoritma dan Pemrograman : ");
        scanf("%f", &nilai);

        printf("\n=====OUTPUT DATA MAHASISWA %d=====\n", i);
        printf("Nama    : %s\n", nama);
        printf("Kelas   : %s\n", kelas);
        printf("NIM     : %s\n", nim);
        printf("Nilai Mata Kuliah Algoritma dan Pemrograman     : %.2f\n", nilai);

        if (nilai <= 50)
        {
            printf("\nKeterangan : TIDAK LULUS\n");
            printf("Index Nilai Anda Tidak Dapat Mengikuti rekruitasi Lab Daskom\n");
        }
        else if (nilai <= 60)
        {
            printf("\nKeterangan : LULUS\n");
            printf("Index Nilai Anda C, Tidak Dapat Mengikuti rekruitasi Lab Daskom\n");
        }
        else if (nilai <= 65)
        {
            printf("\nKeterangan : LULUS\n");
            printf("Index Nilai Anda BC, Dapat Mengikuti rekruitasi Lab Daskom tetapi dalam pertimbangan\n");
        }
        else if (nilai <= 70)
        {
            printf("\nKeterangan : LULUS\n");
            printf("Index Nilai Anda B, Dapat Mengikuti rekruitasi Lab Daskom\n");
        }
        else if (nilai <= 80)
        {
            printf("\nKeterangan : LULUS\n");
            printf("Index Nilai Anda AB, Dapat Mengikuti rekruitasi Lab Daskom\n");
        }
        else
        {
            printf("\nKeterangan : LULUS\n");
            printf("Index Nilai Anda A, Selamat anda dapat Mengikuti rekruitasi Lab Daskom :D\n");
        }
    }

    return 0;
}
