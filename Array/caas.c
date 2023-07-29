#include <stdio.h>
#include <string.h>

typedef struct
{
    char nama[50];
    char nim[15];
    char jurusan[30];
} Caas;

int main()
{
    int jumlahCaas, i;

    printf("Jumlah Caas Daskom : ");
    scanf("%d", &jumlahCaas);

    Caas caas[jumlahCaas];

    for (i = 0; i < jumlahCaas; i++)
    {
        printf("Calon Asisten %d\n", i + 1);
        printf("Nama : ");
        fflush(stdin);
        fgets(caas[i].nama, sizeof(caas[i].nama), stdin);
        printf("NIM : ");
        fflush(stdin);
        fgets(caas[i].nim, sizeof(caas[i].nim), stdin);
        printf("Jurusan : ");
        fflush(stdin);
        fgets(caas[i].jurusan, sizeof(caas[i].jurusan), stdin);
    }

    printf("\nDaftar Calon Asisten Dasar Komputer :\n");
    for (i = 0; i < jumlahCaas; i++)
    {
        printf("%d. %s, %s, %s", i + 1, strtok(caas[i].nama, "\n"), strtok(caas[i].nim, "\n"), strtok(caas[i].jurusan, "\n"));
    }

    return 0;
}
