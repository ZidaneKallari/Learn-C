#include <stdio.h>

float hitung_percepatan(float kecepatan_akhir, float kecepatan_awal, float waktu)
{
    float percepatan;
    percepatan = (kecepatan_akhir - kecepatan_awal) / waktu;
    return percepatan;
}

int main()
{
    float kecepatan_akhir, kecepatan_awal, waktu, percepatan;

    printf("Masukkan kecepatan akhir (m/s): ");
    scanf("%f", &kecepatan_akhir);
    printf("Masukkan kecepatan awal (m/s): ");
    scanf("%f", &kecepatan_awal);
    printf("Masukkan waktu (s): ");
    scanf("%f", &waktu);

    percepatan = hitung_percepatan(kecepatan_akhir, kecepatan_awal, waktu);

    printf("Maka percepatan %.2f m/s^2\n", percepatan);

    return 0;
}
