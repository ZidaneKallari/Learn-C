#include <stdio.h>

typedef struct
{
    char nama[50];
    int nim;
    char jurusan[50];
    char ttl[50];
    char jenis_kelamin[15];
} Mahasiswa;

int main()
{
    Mahasiswa calon_asisten;

    printf("Nama : ");
    fgets(calon_asisten.nama, 50, stdin);

    printf("NIM : ");
    scanf("%d", &calon_asisten.nim);

    printf("Jurusan : ");
    getchar();
    fgets(calon_asisten.jurusan, 50, stdin);

    printf("TTL : ");
    fgets(calon_asisten.ttl, 50, stdin);

    printf("Jenis Kelamin : ");
    fgets(calon_asisten.jenis_kelamin, 15, stdin);

    printf("\n==== OUTPUT ====\n");
    printf("Nama : %s", calon_asisten.nama);
    printf("NIM : %d\n", calon_asisten.nim);
    printf("Jurusan : %s", calon_asisten.jurusan);
    printf("TTL : %s", calon_asisten.ttl);
    printf("Jenis Kelamin : %s", calon_asisten.jenis_kelamin);

    return 0;
}