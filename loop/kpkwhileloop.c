#include <stdio.h>

int main()
{
    int num1, num2, i, max, kpk;

    printf("Masukan angka pertama: ");
    scanf("%d", &num1);

    printf("Masukan angka kedua: ");
    scanf("%d", &num2);

    max = (num1 > num2) ? num1 : num2;

    i = max;

    do
    {
        if (i % num1 == 0 && i % num2 == 0)
        {
            kpk = i;
            break;
        }
        i += max;
    } while (1);

    printf("KPK dari %d dan %d adalah %d\n", num1, num2, kpk);

    return 0;
}
