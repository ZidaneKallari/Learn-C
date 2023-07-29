#include <stdio.h>

struct Nilai
{
    int kode_matakuliah;
    float nilai;
};

struct Mahasiswa
{
    int NIM;
    int jumlah_matakuliah;
    struct Nilai nilai[10];
};
int main()
{
    int jumlah_mahasiswa;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &jumlah_mahasiswa);

    FILE *file = fopen("nilai_mahasiswa.txt", "w");

    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        struct Mahasiswa mahasiswa;

        printf("\nMahasiswa %d:\n", i + 1);
        printf("Masukkan NIM: ");
        scanf("%d", &mahasiswa.NIM);

        printf("Masukkan jumlah matakuliah: ");
        scanf("%d", &mahasiswa.jumlah_matakuliah);

        printf("Masukkan nilai matakuliah:\n");
        for (int j = 0; j < mahasiswa.jumlah_matakuliah; j++)
        {
            printf(" Matakuliah %d: ", j + 1);
            scanf("%d", &mahasiswa.nilai[j].kode_matakuliah);

            printf(" Nilai: ");
            scanf("%f", &mahasiswa.nilai[j].nilai);
        }

        fprintf(file, "%d %d", mahasiswa.NIM, mahasiswa.jumlah_matakuliah);
        for (int j = 0; j < mahasiswa.jumlah_matakuliah; j++)
        {
            fprintf(file, " %d %.2f", mahasiswa.nilai[j].kode_matakuliah, mahasiswa.nilai[j].nilai);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    file = fopen("nilai_mahasiswa.txt", "r");

    printf("\nDaftar Nilai Mahasiswa:\n");
    while (!feof(file))
    {
        struct Mahasiswa mahasiswa;
        float total_nilai = 0;

        fscanf(file, "%d %d", &mahasiswa.NIM, &mahasiswa.jumlah_matakuliah);
        for (int j = 0; j < mahasiswa.jumlah_matakuliah; j++)
        {
            fscanf(file, "%d %f", &mahasiswa.nilai[j].kode_matakuliah, &mahasiswa.nilai[j].nilai);
            total_nilai += mahasiswa.nilai[j].nilai;
        }

        float rata_rata = total_nilai / mahasiswa.jumlah_matakuliah;

        printf("NIM: %d\n", mahasiswa.NIM);
        printf("Nilai Rata-rata: %.2f\n\n", rata_rata);
    }

    fclose(file);

    return 0;
}