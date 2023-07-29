#include <stdio.h>
#include <stdlib.h>

struct Praktikan
{
    char nama[100];
    char nim[20];
    char kelas[20];
    int kelompok;
};

void input(struct Praktikan *praktikan, int jumlah)
{
    for (int i = 0; i < jumlah; i++)
    {
        printf("%d. Nama: ", i + 1);
        fgets(praktikan[i].nama, sizeof(praktikan[i].nama), stdin);
        printf("   NIM: ");
        fgets(praktikan[i].nim, sizeof(praktikan[i].nim), stdin);
        printf("   Kelas: ");
        fgets(praktikan[i].kelas, sizeof(praktikan[i].kelas), stdin);
        printf("   Kelompok: ");
        scanf("%d", &praktikan[i].kelompok);
        getchar(); // Menghapus karakter newline (\n) dalam buffer
    }
}

void simpan(struct Praktikan *praktikan, int jumlah)
{
    FILE *file;
    file = fopen("data.bin", "wb");
    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }
    fwrite(praktikan, sizeof(struct Praktikan), jumlah, file);
    fclose(file);
    printf("Data praktikan berhasil disimpan dalam file biner.\n");
}

void tampilkanData()
{
    FILE *file;
    file = fopen("data.bin", "rb");
    if (file == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    struct Praktikan praktikan;
    int nomor = 1;

    printf("Data praktikan:\n");
    while (fread(&praktikan, sizeof(struct Praktikan), 1, file))
    {
        printf("%d. Nama: %s", nomor, praktikan.nama);
        printf("   NIM: %s", praktikan.nim);
        printf("   Kelas: %s", praktikan.kelas);
        printf("   Kelompok: %d\n", praktikan.kelompok);
        nomor++;
    }

    fclose(file);
}

int main()
{
    int jumlah;

    printf("Banyak praktikan: ");
    scanf("%d", &jumlah);
    getchar(); // Menghapus karakter newline (\n) dalam buffer

    struct Praktikan *praktikan = malloc(jumlah * sizeof(struct Praktikan));

    input(praktikan, jumlah);
    simpan(praktikan, jumlah);
    tampilkanData();

    free(praktikan);

    return 0;
}
