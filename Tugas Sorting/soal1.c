#include <stdio.h>
#include <string.h>

struct Data
{
    char nama[100];
    int nilai;
};

void bubbleSort(struct Data arr[], int n)
{
    int i, j;
    struct Data temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // Membandingkan nama secara alfabetik
            if (strcmp(arr[j].nama, arr[j + 1].nama) > 0)
            {
                // Menukar posisi data jika urutan nama tidak sesuai
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;

    printf("Jumlah data: ");
    scanf("%d", &n);

    struct Data data[n];

    for (i = 0; i < n; i++)
    {
        printf("Data ke-%d\n", i + 1);
        printf("Nama: ");
        scanf("%s", data[i].nama);
        printf("Nilai: ");
        scanf("%d", &data[i].nilai);
    }

    bubbleSort(data, n);

    printf("\nData setelah diurutkan:\n");
    printf("Nama\tNilai\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\n", data[i].nama, data[i].nilai);
    }

    return 0;
}
