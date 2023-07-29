#include <stdio.h>

int main()
{
    int n1, n2, n3;
    float rata;

    printf("Nilai ke-1: ");
    scanf("%d", &n1);

    printf("Nilai ke-2: ");
    scanf("%d", &n2);

    printf("Nilai ke-3: ");
    scanf("%d", &n3);

    int sum = n1 + n2 + n3;
    rata = (float)sum / 3;

    printf("Jumlah Nilai: %d\n", sum);
    printf("Rata-rata: %.2f\n", rata);

    return 0;
}
