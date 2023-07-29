#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("%d.Nama: ", i + 1);
        fgets(praktikan[i].nama, sizeof(praktikan[i].nama), stdin);
        printf("NIM: ");
        fgets(praktikan[i].nim, sizeof(praktikan[i].nim), stdin);
        printf("Kelas: ");
        fgets(praktikan[i].kelas, sizeof(praktikan[i].kelas), stdin);
        printf("Kelompok: ");
        scanf("%d", &praktikan[i].kelompok);
        getchar();
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
}

void output()
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

    printf("Output:\n");
    while (fread(&praktikan, sizeof(struct Praktikan), 1, file))
    {
        printf("%d.Nama: %s", nomor, praktikan.nama);
        printf("NIM: %s", praktikan.nim);
        printf("Kelas: %s", praktikan.kelas);
        printf("Kelompok: %d\n", praktikan.kelompok);
        nomor++;
    }

    fclose(file);
}

void hapus(const char *hapusnama)
{
    FILE *file, *tempFile;
    file = fopen("data.bin", "rb");
    tempFile = fopen("temp.bin", "wb");
    if (file == NULL || tempFile == NULL)
    {
        printf("Gagal membuka file.\n");
        return;
    }

    struct Praktikan praktikan;

    while (fread(&praktikan, sizeof(struct Praktikan), 1, file))
    {
        if (strcmp(praktikan.nama, hapusnama) != 0)
        {
            fwrite(&praktikan, sizeof(struct Praktikan), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("data.bin");
    rename("temp.bin", "data.bin");
}

int main()
{
    int jumlah;

    printf("Banyak praktikan: ");
    scanf("%d", &jumlah);
    getchar();

    struct Praktikan *praktikan = malloc(jumlah * sizeof(struct Praktikan));

    input(praktikan, jumlah);
    simpan(praktikan, jumlah);
    output();

    char hapusnama[100];
    printf("\nMasukkan nama praktikan yang datanya ingin dihapus: ");
    fgets(hapusnama, sizeof(hapusnama), stdin);

    hapus(hapusnama);
    output();

    free(praktikan);

    return 0;
}
