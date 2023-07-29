#include <stdio.h>

void hitung_percepatan(float kecepatan_akhir, float kecepatan_awal, float waktu, float *percepatan)
{
    *percepatan = (kecepatan_akhir - kecepatan_awal) / waktu;
}

int main()
{
    float kecepatan_akhir, kecepatan_awal, waktu, percepatan;

    // meminta input dari user
    printf("Masukkan kecepatan akhir (m/s): ");
    scanf("%f", &kecepatan_akhir);
    printf("Masukkan kecepatan awal (m/s): ");
    scanf("%f", &kecepatan_awal);
    printf("Masukkan waktu (s): ");
    scanf("%f", &waktu);

    // memanggil prosedur hitung_percepatan
    hitung_percepatan(kecepatan_akhir, kecepatan_awal, waktu, &percepatan);

    // menampilkan output
    printf("Maka percepatan %.2f m/s^2\n", percepatan);

    return 0;
}
