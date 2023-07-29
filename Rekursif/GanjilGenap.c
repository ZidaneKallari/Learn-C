#include <stdio.h>
void Ganjil(int n)
{
    if (n == 1)
    {
        printf("%d ", n);
        return;
    }
    Ganjil(n - 1);
    printf("%d ", 2 * n - 1);
}

void Genap(int n)
{
    if (n == 1)
    {
        printf("%d ", n * 2);
        return;
    }
    Genap(n - 1);
    printf("%d ", 2 * n);
}
int main()
{
    int n;
    printf("Masukkan banyak suku : ");
    scanf("%d", &n);
    printf("Hasil bilangan ganjil : ");
    Ganjil(n);
    printf("\nHasil bilangan genap : ");
    Genap(n);
    printf("\n");
    return 0;
}
