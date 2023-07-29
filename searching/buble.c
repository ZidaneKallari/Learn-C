#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int binary_search(int arr[], int n, int cari)
{
    int kiri = 0;
    int kanan = n - 1;
    int tengah;

    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;

        if (arr[tengah] == cari)
        {
            return tengah;
        }
        else if (arr[tengah] < cari)
        {
            kiri = tengah + 1;
        }
        else
        {
            kanan = tengah - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    printf("Banyak angka : ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Angka %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    printf("Angka yang sudah terurut : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int cari;
    printf("\nAngka yang dicari : ");
    scanf("%d", &cari);

    int indeks = binary_search(arr, n, cari);
    if (indeks == -1)
    {
        printf("Angka tidak ditemukan");
    }
    else
    {
        printf("Angka %d ditemukan pada urutan ke-%d", cari, indeks + 1);
    }

    return 0;
}
