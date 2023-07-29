#include <stdio.h>

int aritmatika(int n, int beda)
{
    if (n == 1)
    {
        return 1 * beda;
    }
    else
    {
        return aritmatika(n - 1, beda) + beda;
    }
}

int main()
{
    int panjang, beda, hasil_total = 0;

    printf("Panjang deret : ");
    scanf("%d", &panjang);

    printf("Beda : ");
    scanf("%d", &beda);

    printf("Deret : ");
    for (int i = 1; i <= panjang; i++)
    {
        int suku = aritmatika(i, beda);
        printf("%d ", suku);
        hasil_total += suku;
    }

    printf("\nHasil Total: %d", hasil_total);

    return 0;
}
