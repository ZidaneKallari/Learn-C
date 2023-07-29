#include <stdio.h>

int main()
{
    int r, t;
    double volume_kerucut, volume_bola;
    double PI = 3.14;

    printf("Masukkan r : ");
    scanf("%d", &r);

    printf("Masukkan t : ");
    scanf("%d", &t);

    volume_kerucut = (1.0 / 3) * PI * r * r * t;
    printf("\n==== Volume Kerucut ====\n");
    printf("Volume : %.2f\n", volume_kerucut);

    volume_bola = (4.0 / 3) * PI * r * r * r;
    printf("\n==== Volume Bola ====\n");
    printf("Volume : %.2f\n", volume_bola);

    return 0;
}
