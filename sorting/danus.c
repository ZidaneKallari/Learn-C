#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int i, j, k, temp;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main()
{
    int danus[5] = {5, 10, 15, 13, 2};
    int i;

    printf("Sebelum diurutkan: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", danus[i]);
    }

    selectionSort(danus, 5);

    printf("\nSetelah diurutkan: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", danus[i]);
    }

    return 0;
}
