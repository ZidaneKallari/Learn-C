#include <stdio.h>

void hitung_energi_potensial(float massa, float tinggi, float *energi_potensial)
{
    float g = 9.8;
    *energi_potensial = massa * g * tinggi;
}

int main()
{
    float massa1, tinggi1, massa2, tinggi2, energi_potensial1, energi_potensial2;

    printf("Massa benda 1 (kg): ");
    scanf("%f", &massa1);
    printf("Tinggi benda 1 (m): ");
    scanf("%f", &tinggi1);

    printf("Massa benda 2 (kg): ");
    scanf("%f", &massa2);
    printf("Tinggi benda 2 (m): ");
    scanf("%f", &tinggi2);

    hitung_energi_potensial(massa1, tinggi1, &energi_potensial1);
    hitung_energi_potensial(massa2, tinggi2, &energi_potensial2);

    if (energi_potensial2 > energi_potensial1)
    {
        printf("Energi potensial benda 2 lebih besar daripada benda 1\n");
    }
    else if (energi_potensial1 > energi_potensial2)
    {
        printf("Energi potensial benda 1 lebih besar daripada benda 2\n");
    }
    else
    {
        printf("Energi potensial kedua benda sama besar\n");
    }

    return 0;
}
