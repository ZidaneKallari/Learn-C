#include <stdio.h>

void input()
{
    char teks[1000];
    printf("Masukkan teks: ");
    fgets(teks, sizeof(teks), stdin);

    FILE *file;
    file = fopen("output.txt", "w");
    fprintf(file, "%s", teks);
    fclose(file);
    printf("Teks berhasil ditulis\n");
}

void outputTeks()
{
    FILE *file;
    file = fopen("output.txt", "r");
    if (file == NULL)
    {
        printf("File tidak ditemukan.\n");
        return;
    }

    printf("Isi file:\n");
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        printf("%c", c);
    }
    fclose(file);
}

int main()
{
    input();
    outputTeks();
    return 0;
}
