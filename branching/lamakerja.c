#include <stdio.h>

int main()
{
    int jamMasuk, jamKeluar, lamaKerja;

    printf("Masukkan jam masuk (1-12): ");
    scanf("%d", &jamMasuk);

    printf("Masukkan jam keluar (1-12): ");
    scanf("%d", &jamKeluar);

    if (jamKeluar >= jamMasuk)
    {
        lamaKerja = jamKeluar - jamMasuk;
    }
    else
    {
        lamaKerja = 12 - jamMasuk + jamKeluar;
    }

    printf("Lama kerja: %d jam\n", lamaKerja);

    return 0;
}
