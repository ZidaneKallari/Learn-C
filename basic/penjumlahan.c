#include <stdio.h>
int main()
{
    int a, b, hasil;

    printf("Masukkan nilai pertama:");
    scanf("%d", &a);
    printf("Masukkan nilai kedua:");
    scanf("%d", &b);
    hasil = a + b;
    printf("hasil dari %d + %d = %d\n", a, b, hasil);
    return 0;
}