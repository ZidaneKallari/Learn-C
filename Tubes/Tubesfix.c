#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FORUMS 50
#define MAX_COMMENTS 500
#define MAX_PERCOBAAN 3

struct data_admin
{
    char username[20], password[20];
    char forum[MAX_FORUMS][100];
    char komentar[MAX_FORUMS][MAX_COMMENTS][1000];
    int jumlah_forum;
    int jumlah_komentar[MAX_FORUMS];
};

struct data_user
{
    char username[20], password[20];
    char nama[50], bio[1000], asal_planet[1000], gender[20];
    int umur, like;
};

struct data_admin admin;
struct data_user data[5];
int usermaks = 0;

int login_admin()
{
    struct Admin
    {
        char username[50];
        char password[50];
    } admin;

    strcpy(admin.username, "salamsatunyali");
    strcpy(admin.password, "wani");

    int percobaan = 0;
    char username[50];
    char password[50];

    while (percobaan < MAX_PERCOBAAN)
    {
        printf("Username : ");
        scanf("%s", username);
        printf("Password : ");
        scanf("%s", password);

        if (strcmp(admin.username, username) == 0 && strcmp(admin.password, password) == 0)
        {
            printf("Login berhasil\n");
            return 1;
        }
        else
        {
            percobaan++;
            printf("Username/password salah. Sisa percobaan: %d\n", MAX_PERCOBAAN - percobaan);
        }
    }
    printf("Jumlah percobaan sudah habis\n");
    return 0;
}

void simpan_data_user_ke_file()
{
    FILE *datus = fopen("data_user.txt", "w");
    if (datus == NULL)
    {
        printf("Gagal membuka file data_user.txt\n");
        return;
    }

    for (int i = 0; i < usermaks; i++)
    {
        fprintf(datus, "%s|%s|%s|%s|%s|%s|%d|%d\n",
                data[i].username, data[i].password, data[i].nama,
                data[i].bio, data[i].asal_planet, data[i].gender,
                data[i].umur, data[i].like);
    }

    fclose(datus);
    printf("Data pengguna berhasil disimpan ke file.\n");
}

void hapus_data_user_dari_file(const char *username)
{
    FILE *file = fopen("data_user.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file data_user.txt\n");
        return;
    }

    FILE *temp_file = fopen("temp_file.txt", "w");
    if (temp_file == NULL)
    {
        printf("Gagal membuat file temp_file.txt\n");
        fclose(file);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL)
    {

        char temp_username[50];
        sscanf(line, "%[^|]", temp_username);
        if (strcmp(temp_username, username) != 0)
        {
            fputs(line, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    remove("data_user.txt");
    rename("temp_file.txt", "data_user.txt");

    printf("Data pengguna dengan username '%s' berhasil dihapus dari file.\n", username);
}

void baca_data_user_dari_file()
{
    FILE *datus = fopen("data_user.txt", "r");
    if (datus == NULL)
    {
        printf("Gagal membuka file data_user.txt\n");
        return;
    }

    usermaks = 0;
    while (fscanf(datus, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d|%d\n",
                  data[usermaks].username, data[usermaks].password,
                  data[usermaks].nama, data[usermaks].bio,
                  data[usermaks].asal_planet, data[usermaks].gender,
                  &data[usermaks].umur, &data[usermaks].like) == 8)
    {
        usermaks++;
    }

    fclose(datus);
    printf("Data pengguna berhasil dibaca dari file.\n");
}

void simpan_forum_ke_file()
{
    FILE *datforum = fopen("data_forum.txt", "w");
    if (datforum == NULL)
    {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }

    for (int i = 0; i < admin.jumlah_forum; i++)
    {
        fprintf(datforum, "%s\n", admin.forum[i]);

        for (int j = 0; j < admin.jumlah_komentar[i]; j++)
        {
            fprintf(datforum, "%s\n", admin.komentar[i][j]);
        }
        fprintf(datforum, "\n");
    }

    fclose(datforum);
    printf("Data forum berhasil disimpan ke file.\n");
}

void baca_forum_dari_file()
{
    FILE *file = fopen("data_forum.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }
}

void informasi_user()
{
    int i, j;
    printf("\n=== Informasi Akun ===\n");
    printf("======================\n\n");

    if (usermaks == 0)
    {
        printf("Belum ada user yang terdaftar.\n");
        return;
    }

    for (i = 0; i < usermaks; i++)
    {
        for (j = i + 1; j < usermaks; j++)
        {
            if (strcmp(data[i].username, data[j].username) > 0)
            {
                struct data_user temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    for (i = 0; i < usermaks; i++)
    {
        printf("Nama : %s.\n", data[i].username);
        printf("Bio : %s\n", data[i].bio);
        printf("Asal planet : %s\n", data[i].asal_planet);
        printf("Gender : %s\n", data[i].gender);
        printf("Umur : %d\n", data[i].umur);
    }
}

void buat_forum()
{
    printf("\n=== Buat Forum ===\n");
    printf("================\n\n");

    if (admin.jumlah_forum >= 20)
    {
        printf("Jumlah forum sudah mencapai batas maksimal\n");
        return;
    }

    printf("Masukkan judul forum: ");
    char judul[100];
    scanf(" %99[^\n]", judul);

    strcpy(admin.forum[admin.jumlah_forum], judul);
    admin.jumlah_komentar[admin.jumlah_forum] = 0;
    admin.jumlah_forum++;
    printf("Forum berhasil ditambahkan.\n");

    FILE *file = fopen("data_forum.txt", "a");
    if (file == NULL)
    {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }

    fprintf(file, "%s\n", judul);

    fclose(file);
}

void lihat_forum()
{
    printf("\n=== Chat Forum ===\n");
    printf("==================\n\n");

    FILE *file = fopen("data_forum.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }

    char judul[100];

    int i = 1;
    while (fgets(judul, sizeof(judul), file) != NULL)
    {
        judul[strcspn(judul, "\n")] = '\0';

        printf("%d. %s\n", i, judul);
        i++;
    }

    fclose(file);
}

void hapus_forum()
{
    printf("\n=== Menghapus Forum ===\n");
    printf("======================\n\n");

    FILE *file = fopen("data_forum.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }

    char judul[100];
    int i = 1;

    printf("Forum yang tersedia:\n");
    while (fgets(judul, sizeof(judul), file) != NULL)
    {
        judul[strcspn(judul, "\n")] = '\0';

        printf("%d. %s\n", i, judul);
        i++;
    }

    fclose(file);

    int nomor_forum;
    printf("Pilih nomor forum yang akan dihapus: ");
    scanf("%d", &nomor_forum);

    if (nomor_forum < 1 || nomor_forum >= i)
    {
        printf("Nomor forum tidak valid.\n");
        return;
    }

    for (int j = nomor_forum - 1; j < admin.jumlah_forum - 1; j++)
    {
        strcpy(admin.forum[j], admin.forum[j + 1]);
    }
    admin.jumlah_forum--;

    printf("Forum berhasil dihapus.\n");

    file = fopen("data_forum.txt", "r");
    if (file == NULL)
    {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }

    FILE *tempFile = fopen("temp_data_forum.txt", "w");
    if (tempFile == NULL)
    {
        printf("Gagal membuka file temp_data_forum.txt\n");
        fclose(file);
        return;
    }

    i = 1;
    while (fgets(judul, sizeof(judul), file))
    {
        judul[strcspn(judul, "\n")] = '\0';
        if (i != nomor_forum)
        {
            fprintf(tempFile, "%s\n", judul);
        }
        i++;
    }

    fclose(file);
    fclose(tempFile);

    if (remove("data_forum.txt") != 0)
    {
        printf("Gagal menghapus file data_forum.txt\n");
        return;
    }

    if (rename("temp_data_forum.txt", "data_forum.txt") != 0)
    {
        printf("Gagal mengganti nama file temp_data_forum.txt\n");
        return;
    }

    printf("Data forum berhasil dihapus dari file.\n");
}

void komentar()
{
    int i, nomor_forum;
    char komentar_baru[100];

    printf("\n=== Tambahkan Komentar ===\n");
    printf("==========================\n\n");

    printf("Forum yang tersedia:\n");
    for (i = 0; i < admin.jumlah_forum; i++)
    {
        printf("%d. %s\n", i + 1, admin.forum[i]);
    }

    printf("Pilih Forum: ");
    scanf("%d", &nomor_forum);

    if (nomor_forum < 1 || nomor_forum > admin.jumlah_forum)
    {
        printf("Pilihan anda tidak tersedia.\n");
        return;
    }

    printf("Masukkan komentar anda: ");
    getchar();
    fgets(komentar_baru, sizeof(komentar_baru), stdin);
    strcpy(admin.komentar[nomor_forum - 1][admin.jumlah_komentar[nomor_forum - 1]], komentar_baru);
    admin.jumlah_komentar[nomor_forum - 1]++;

    printf("OKE Komentar berhasil ditambahkan.\n");
}

void hapus_komentar()
{
    int nomor_forum, nomor_komentar;

    printf("\n=== Hapus Komentar ===\n");
    printf("========================\n\n");

    printf("Forum yang tersedia:\n");
    for (int i = 0; i < admin.jumlah_forum; i++)
    {
        printf("%d. %s\n", i + 1, admin.forum[i]);
    }

    printf("Pilih nomor forum: ");
    scanf("%d", &nomor_forum);

    if (nomor_forum < 1 || nomor_forum > admin.jumlah_forum)
    {
        printf("Nomor forum tidak valid.\n");
        return;
    }

    printf("Komentar yang tersedia di forum ini:\n");
    for (int i = 0; i < admin.jumlah_komentar[nomor_forum - 1]; i++)
    {
        printf("%d. %s\n", i + 1, admin.komentar[nomor_forum - 1][i]);
    }

    printf("Pilih nomor komentar yang akan dihapus: ");
    scanf("%d", &nomor_komentar);

    if (nomor_komentar < 1 || nomor_komentar > admin.jumlah_komentar[nomor_forum - 1])
    {
        printf("Nomor komentar tidak valid.\n");
        return;
    }

    for (int i = nomor_komentar - 1; i < admin.jumlah_komentar[nomor_forum - 1] - 1; i++)
    {
        strcpy(admin.komentar[nomor_forum - 1][i], admin.komentar[nomor_forum - 1][i + 1]);
    }
    admin.jumlah_komentar[nomor_forum - 1]--;

    printf("Komentar berhasil dihapus.\n");
}

int cari_akun(const char *username)
{
    for (int i = 0; i < usermaks; i++)
    {
        if (strcmp(data[i].username, username) == 0)
        {
            return i;
        }
    }
    return -1;
}

void like_akun(const char *username)
{
    int jumlah = cari_akun(username);
    if (jumlah != -1)
    {
        data[jumlah].like++;
        printf("Anda memberikan 'like' kepada %s\n", username);
    }
    else
    {
        printf("Pengguna %s tidak ditemukan\n", username);
    }
}

void tampilkan_akun(const struct data_user *user)
{
    printf("Username: %s\n", user->username);
    printf("Likes: %d\n", user->like);
}

void clearConsole()
{
    system("cls");
}

void registrasi_akun()
{
    struct data_user user;
    if (usermaks >= 5)
    {
        printf("Batas maksimum user telah tercapai. Tidak dapat melakukan registrasi baru.\n");
        return;
    }
    printf("\n=== Jangan sampai lupa akun ===\n\n");

    printf("Username : ");
    scanf("%s", user.username);
    printf("Password : ");
    scanf("%s", user.password);
    printf("Nama : ");
    scanf(" %[^\n]", user.nama);
    printf("Deskripsi Diri/Bio : ");
    scanf(" %[^\n]", user.bio);
    printf("Asal Planet : ");
    scanf(" %[^\n]", user.asal_planet);
    printf("Gender : ");
    scanf(" %[^\n]", user.gender);
    printf("Umur : ");
    scanf("%d", &user.umur);

    data[usermaks] = user;
    usermaks++;

    simpan_data_user_ke_file();
    printf("OKE! Registrasi berhasil\n\n");
}

int login_akun(const char *username, const char *password)
{
    for (int i = 0; i <= usermaks; i++)
    {
        printf("%s", data[i]);
        if (strcmp(data[i].username, username) == 0 && strcmp(data[i].password, password) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    baca_data_user_dari_file();
    baca_forum_dari_file();
    int i, kesempatan_maks = 3;
    do
    {
        clearConsole();
        printf("=== Menu D'Teleforum ===\n");
        printf("========================\n\n");

        printf("1. Login Admin\n");
        printf("2. Registrasi Akun\n");
        printf("3. Login Akun\n");
        printf("4. Keluar\n");

        printf("Pilih : ");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
        {
            char adminuser[20] = "admin", adminpass[20];
            printf("\n===Khusus Admin===\n");

            if (login_admin(adminuser, adminpass))
            {
                printf("Login berhasil\n\n");
                char admin_menu;
                char usernameInput[50];
                do
                {
                    clearConsole();
                    printf("=== Menu Admin ===\n");
                    printf("==================\n\n");

                    printf("1. Informasi Akun\n");
                    printf("2. Buat forum\n");
                    printf("3. Lihat forum\n");
                    printf("4. Hapus Forum\n");
                    printf("5. Hapus Akun\n");
                    printf("6. Keluar\n");

                    printf("Pilih : ");
                    scanf("%d", &admin_menu);

                    switch (admin_menu)
                    {
                    case 1:
                        informasi_user();
                        break;
                    case 2:
                        buat_forum();
                        break;
                    case 3:
                        lihat_forum();
                        break;
                    case 4:
                        hapus_forum();
                        break;
                    case 5:
                        printf("Masukkan username: ");
                        scanf("%49s", usernameInput);
                        hapus_data_user_dari_file(usernameInput);
                        break;
                    case 6:
                        printf("Terimakasih telah menggunakan layanan kami\n");
                        break;
                    default:
                        printf("Pilihan anda tidak tersedia\n");
                        break;
                    }
                    printf("Kalo mau lanjut tekan Enter:)");
                    getchar();
                    getchar();

                } while (admin_menu != 6);
            }
            else
            {
                printf("Username atau password anda salah\n\n");
            }
            break;
        }
        case 2:
            registrasi_akun();
            break;
        case 3:
        {
            char name[20], pass[20];
            int kesempatan_maks = 3, j = kesempatan_maks;
            printf("\n=== Masukkan Data Anda Dengan Benar!===\n");
            printf("Username : ");
            scanf("%s", name);
            printf("Password : ");
            scanf("%s", pass);
            while (j > 0)
            {
                if (login_akun(name, pass))
                {
                    printf("Login berhasil\n\n");
                    j = kesempatan_maks;
                    char user_menu;
                    do
                    {
                        clearConsole();
                        printf("=== Menu User ===\n");
                        printf("=================\n\n");
                        printf("1. Informasi Akun\n");
                        printf("2. Chat forum\n");
                        printf("3. Like\n");
                        printf("4. Keluar\n");

                        printf("Pilih : ");
                        scanf("%d", &user_menu);

                        switch (user_menu)
                        {
                        case 1:
                            informasi_user();
                            break;
                        case 2:
                            lihat_forum();
                            int i;
                            do
                            {
                                printf("===================\n");
                                printf("1. komentar\n");
                                printf("2. Hapus komentar\n");
                                printf("3. lanjut menu like\n");

                                printf("Pilih : ");
                                scanf("%d", &i);

                                switch (i)
                                {
                                case 1:
                                    komentar();
                                    break;
                                case 2:
                                    hapus_komentar();
                                    break;
                                case 3:
                                    printf("OKE\n");
                                    break;
                                default:
                                    printf("Pilihan anda tidak tersedia\n");
                                    break;
                                }
                            } while (i != 3);
                        case 3:
                        {
                            int like;
                            char username[20];
                            do
                            {
                                clearConsole();
                                printf("1. Berikan like\n");
                                printf("2. Keluar\n");
                                printf("pilih : ");
                                scanf("%d", &like);

                                switch (like)
                                {
                                case 1:
                                    printf("\nCari akun : ");
                                    scanf("%s", username);
                                    like_akun(username);
                                    break;
                                case 2:
                                    printf("\nOKE silahkan keluar\n");
                                    break;
                                default:
                                    printf("\nPilihan tidak tersedia\n");
                                    break;
                                }

                            } while (like != 2);
                        case 4:
                            printf("Terima kasih telah menggunakan layanan kami.\n");
                            break;
                        default:
                            printf("Pilihan Anda tidak tersedia.\n");
                            break;
                        }
                        }
                        printf("Kalo mau lanjut tekan Enter:)");
                        getchar();
                        getchar();
                    } while (user_menu != 4);
                    break;
                }
                else
                {
                    j--;
                    printf("Username atau password salah. Silakan coba lagi.\n\n");

                    if (j < 1)
                    {
                        printf("Anda sudah melebihi batas maksimal, coba lagi nanti!\n");
                    }
                    else
                    {
                        printf("Kesempatan sisa: %d\n", j);
                        printf("Username : ");
                        scanf("%s", name);
                        printf("Password : ");
                        scanf("%s", pass);
                    }
                }
            }
            break;
        }
        case 4:
            simpan_data_user_ke_file();
            simpan_forum_ke_file();
            printf("Terimakasih telah berkunjung :)\n");
            break;
        default:
            printf("Pilihan anda tidak tersedia\n");
            break;
        }

        printf("Kalo mau lanjut tekan Enter:)");
        getchar();
        getchar();
    } while (i != 4);

    return 0;
}