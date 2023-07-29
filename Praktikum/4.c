#include <stdio.h>
#include <string.h>

void main()
{
    char kalimat[100], temp;
    int i, j, n;
    printf("Masukkan Kalimat: ");
    fgets(kalimat, 100, stdin);
    n = strlen(kalimat);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (kalimat[i] > kalimat[j])
            {
                temp = kalimat[i];
                kalimat[i] = kalimat[j];
                kalimat[j] = temp;
            }
        }
    }

    printf("Hasil Sorting: ");
    for (i = 0; i < n; i++)
    {
        if (kalimat[i] != ' ' && kalimat[i] != '\n')
        {
            printf("%c ", kalimat[i]);
        }
    }
}
