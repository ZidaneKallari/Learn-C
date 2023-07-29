#include <stdio.h>

#define PI 3.14

int main()
{
    int pilihan;
    float sisi, panjang, lebar, tinggi, jari_jari;
    float luas_permukaan, volume;

    printf("==== MENU ====\n");
    printf("1. Balok\n");
    printf("2. Kubus\n");
    printf("3. Tabung\n");

    printf("Pilih menu : ");
    scanf("%d", &pilihan);

    if (pilihan == 1)
    {
        printf("Masukkan panjang : ");
        scanf("%f", &panjang);
        printf("Masukkan lebar   : ");
        scanf("%f", &lebar);
        printf("Masukkan tinggi  : ");
        scanf("%f", &tinggi);

        luas_permukaan = 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
        volume = panjang * lebar * tinggi;

        printf("\n==== OUTPUT ====\n");
        printf("Luas Permukaan : %.2f cm^2\n", luas_permukaan);
        printf("Volume         : %.2f cm^3\n", volume);
    }
    else if (pilihan == 2)
    {
        printf("Masukkan sisi : ");
        scanf("%f", &sisi);

        luas_permukaan = 6 * sisi * sisi;
        volume = sisi * sisi * sisi;

        printf("\n==== OUTPUT ====\n");
        printf("Luas Permukaan : %.2f cm^2\n", luas_permukaan);
        printf("Volume         : %.2f cm^3\n", volume);
    }
    else if (pilihan == 3)
    {
        printf("Masukkan jari-jari : ");
        scanf("%f", &jari_jari);
        printf("Masukkan tinggi    : ");
        scanf("%f", &tinggi);

        luas_permukaan = 2 * PI * jari_jari * (jari_jari + tinggi);
        volume = PI * jari_jari * jari_jari * tinggi;

        printf("\n==== OUTPUT ====\n");
        printf("Luas Permukaan : %.2f cm^2\n", luas_permukaan);
        printf("Volume         : %.2f cm^3\n", volume);
    }
    else
    {
        printf("Pilihan tidak valid\n");
    }

    return 0;
}
