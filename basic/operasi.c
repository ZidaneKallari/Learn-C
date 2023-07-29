#include <stdio.h>

int main()
{
    int a, b, c, hasil1, hasil2;

    printf("Masukkan nilai a: ");
    scanf("%d", &a);
    printf("Masukkan nilai b: ");
    scanf("%d", &b);
    printf("Masukkan nilai c: ");
    scanf("%d", &c);

    hasil1 = a * b + c;
    printf("Hasil dari %d x %d + %d : %d\n", a, b, c, hasil1);

    hasil2 = hasil1 / c;
    printf("Hasil dari %d / %d : %d\n", hasil1, c, hasil2);

    return 0;
}
