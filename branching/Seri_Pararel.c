#include <stdio.h>

int main()
{
    char jenis_rangkaian[10];
    float hambatan[100];
    int i, n;
    float hambatan_total = 0.0;

    printf("Pilih jenis rangkaian (seri atau paralel): ");
    scanf("%s", jenis_rangkaian);

    printf("Masukkan jumlah komponen rangkaian: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Masukkan nilai hambatan pada komponen %d: ", i + 1);
        scanf("%f", &hambatan[i]);
    }

    if (strcmp(jenis_rangkaian, "seri") == 0)
    {
        for (i = 0; i < n; i++)
        {
            hambatan_total += hambatan[i];
        }
    }
    else if (strcmp(jenis_rangkaian, "paralel") == 0)
    {
        for (i = 0; i < n; i++)
        {
            hambatan_total += 1.0 / hambatan[i];
        }
        hambatan_total = 1.0 / hambatan_total;
    }
    else
    {
        printf("Jenis rangkaian tidak valid.\n");
        return 0;
    }

    printf("Hambatan total pada rangkaian %s adalah %.2f ohm.\n", jenis_rangkaian, hambatan_total);

    return 0;
}