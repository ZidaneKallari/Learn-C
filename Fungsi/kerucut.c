#include <stdio.h>
#define PI 3.14159265359

float hitung_volume(float r, float t)
{
    float volume;
    volume = (1.0 / 3.0) * PI * r * r * t;
    return volume;
}

int main()
{
    float r, t, volume;

    printf("Masukkan jari-jari dari kerucut(cm): ");
    scanf("%f", &r);
    printf("Masukkan tinggi dari kerucut(cm): ");
    scanf("%f", &t);

    volume = hitung_volume(r, t);
    printf("Volume kerucut tersebut adalah %.2f cm^3\n", volume);

    return 0;
}
