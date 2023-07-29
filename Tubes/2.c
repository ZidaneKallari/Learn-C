#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_user 100
#define max_forum 100
#define max_komentar 100
#define max_percobaan 3

typedef struct
{
    char username[50];
    char password[50];
    char nama[50];
    char bio[100];
    char planet[50];
    char gender[10];
    int umur;
    int like;
} User;

typedef struct
{
    char topik[100];
    char admin[50];
    char komentar[max_komentar][100];
    int jml_komentar;
} Forum;

User users[max_user];
int jml_user = 0;

Forum forums[max_forum];
int jml_forum = 0;

int login_admin()
{
    char username_admin[50];
    char password_admin[50];
    int x = 0;

    while (x < max_percobaan)
    {
        printf("Masukkan username: ");
        fgets(username_admin, sizeof(username_admin), stdin);
        username_admin[strcspn(username_admin, "\n")] = '\0';

        printf("Masukkan password: ");
        fgets(password_admin, sizeof(password_admin), stdin);
        password_admin[strcspn(password_admin, "\n")] = '\0';

        if (strcmp(username_admin, "salam satu nyali") == 0 && strcmp(password_admin, "wani") == 0)
        {
            printf("login berhasil\n");
            return 1;
        }
        else
        {
            x++;
            printf("username/password salah\n");
        }
    }

    printf("Jumlah percobaan sudah habis\n");
    exit(0);
}

void lihat_info_user()
{
    if (jml_user == 0)
    {
        printf("Tidak ada user\n");
        return;
    }

    for (int i = 0; i < jml_user - 1; i++)
    {
        for (int j = 0; j < jml_user - i - 1; j++)
        {
            if (strcmp(users[j].username, users[j + 1].username) > 0)
            {
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }

    printf("\nInformasi User\n");
    for (int i = 0; i < jml_user; i++)
    {
        printf("username: %s\n", users[i].username);
    }
}

void info_forum()
{
    if (jml_forum == 0)
    {
        printf("Tidak ada forum\n");
        return;
    }

    printf("\nFORUM\n");
    for (int i = 0; i < jml_forum; i++)
    {
        printf("Topik: %s\n", forums[i].topik);
        printf("Admin: %s\n", forums[i].admin);
        printf("komentar:\n");
        for (int j = 0; j < forums[i].jml_komentar; j++)
        {
            printf("- %s\n", forums[i].komentar[j]);
        }
    }
}

void simpan_data_user()
{
    FILE *file = fopen("users.dat", "wb");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    fwrite(&jml_user, sizeof(int), 1, file);
    fwrite(users, sizeof(User), jml_user, file);

    fclose(file);
}

void baca_data_user()
{
    FILE *file = fopen("users.dat", "rb");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    fread(&jml_user, sizeof(int), 1, file);
    fread(users, sizeof(User), jml_user, file);

    fclose(file);
}

void simpan_data_forum()
{
    FILE *file = fopen("forums.dat", "wb");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    fwrite(&jml_forum, sizeof(int), 1, file);
    fwrite(forums, sizeof(Forum), jml_forum, file);

    fclose(file);
}

void baca_data_forum()
{
    FILE *file = fopen("forums.dat", "rb");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    fread(&jml_forum, sizeof(int), 1, file);
    fread(forums, sizeof(Forum), jml_forum, file);

    fclose(file);
}

void user_baru()
{
    User user;

    printf("Masukkan username: ");
    fgets(user.username, sizeof(user.username), stdin);
    user.username[strcspn(user.username, "\n")] = '\0';

    // Periksa apakah username sudah digunakan
    for (int i = 0; i < jml_user; i++)
    {
        if (strcmp(user.username, users[i].username) == 0)
        {
            printf("Username sudah digunakan\n");
            return;
        }
    }

    printf("Masukkan password: ");
    fgets(user.password, sizeof(user.password), stdin);
    user.password[strcspn(user.password, "\n")] = '\0';

    printf("Masukkan nama: ");
    fgets(user.nama, sizeof(user.nama), stdin);
    user.nama[strcspn(user.nama, "\n")] = '\0';

    printf("Masukkan bio: ");
    fgets(user.bio, sizeof(user.bio), stdin);
    user.bio[strcspn(user.bio, "\n")] = '\0';

    printf("Masukkan planet: ");
    fgets(user.planet, sizeof(user.planet), stdin);
    user.planet[strcspn(user.planet, "\n")] = '\0';

    printf("Masukkan gender: ");
    fgets(user.gender, sizeof(user.gender), stdin);
    user.gender[strcspn(user.gender, "\n")] = '\0';

    printf("Masukkan umur: ");
    scanf("%d", &user.umur);
    getchar();

    user.like = 0;

    users[jml_user] = user;
    jml_user++;

    printf("User baru berhasil ditambahkan\n");

    // Simpan data pengguna setelah menambahkan pengguna baru
    simpan_data_user();
}

int login_user()
{
    char username[50];
    char password[50];

    printf("Masukkan username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Masukkan password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    for (int i = 0; i < jml_user; i++)
    {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0)
        {
            printf("Login berhasil\n");
            return i;
        }
    }

    printf("Login gagal\n");
    return -1;
}

void tambah_forum(int user_index)
{
    if (user_index == -1)
    {
        printf("Login dulu\n");
        return;
    }

    Forum forum;

    printf("Masukkan topik: ");
    fgets(forum.topik, sizeof(forum.topik), stdin);
    forum.topik[strcspn(forum.topik, "\n")] = '\0';

    strcpy(forum.admin, users[user_index].username);
    forum.jml_komentar = 0;

    forums[jml_forum] = forum;
    jml_forum++;

    printf("Forum berhasil ditambahkan\n");

    // Simpan data forum setelah menambahkan forum baru
    simpan_data_forum();
}

void tambah_komentar(int user_index)
{
    if (user_index == -1)
    {
        printf("Login dulu\n");
        return;
    }

    if (jml_forum == 0)
    {
        printf("Tidak ada forum\n");
        return;
    }

    printf("FORUM\n");
    for (int i = 0; i < jml_forum; i++)
    {
        printf("%d. %s\n", i + 1, forums[i].topik);
    }

    int index;
    printf("Pilih nomor forum: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > jml_forum)
    {
        printf("Nomor forum tidak valid\n");
        return;
    }

    index--;

    if (forums[index].jml_komentar == max_komentar)
    {
        printf("Komentar sudah penuh\n");
        return;
    }

    printf("Masukkan komentar: ");
    fgets(forums[index].komentar[forums[index].jml_komentar], sizeof(forums[index].komentar[forums[index].jml_komentar]), stdin);
    forums[index].komentar[forums[index].jml_komentar][strcspn(forums[index].komentar[forums[index].jml_komentar], "\n")] = '\0';

    forums[index].jml_komentar++;

    printf("Komentar berhasil ditambahkan\n");

    // Simpan data forum setelah menambahkan komentar
    simpan_data_forum();
}

void hapus_forum(int user_index)
{
    if (user_index == -1)
    {
        printf("Login dulu\n");
        return;
    }

    if (jml_forum == 0)
    {
        printf("Tidak ada forum\n");
        return;
    }

    printf("FORUM\n");
    for (int i = 0; i < jml_forum; i++)
    {
        printf("%d. %s\n", i + 1, forums[i].topik);
    }

    int index;
    printf("Pilih nomor forum: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > jml_forum)
    {
        printf("Nomor forum tidak valid\n");
        return;
    }

    index--;

    if (strcmp(users[user_index].username, forums[index].admin) != 0)
    {
        printf("Hanya admin yang bisa menghapus forum\n");
        return;
    }

    for (int i = index; i < jml_forum - 1; i++)
    {
        forums[i] = forums[i + 1];
    }

    jml_forum--;

    printf("Forum berhasil dihapus\n");

    // Simpan data forum setelah menghapus forum
    simpan_data_forum();
}

void hapus_komentar(int user_index)
{
    if (user_index == -1)
    {
        printf("Login dulu\n");
        return;
    }

    if (jml_forum == 0)
    {
        printf("Tidak ada forum\n");
        return;
    }

    printf("FORUM\n");
    for (int i = 0; i < jml_forum; i++)
    {
        printf("%d. %s\n", i + 1, forums[i].topik);
    }

    int index_forum;
    printf("Pilih nomor forum: ");
    scanf("%d", &index_forum);
    getchar();

    if (index_forum < 1 || index_forum > jml_forum)
    {
        printf("Nomor forum tidak valid\n");
        return;
    }

    index_forum--;

    if (forums[index_forum].jml_komentar == 0)
    {
        printf("Tidak ada komentar pada forum ini\n");
        return;
    }

    printf("KOMENTAR\n");
    for (int i = 0; i < forums[index_forum].jml_komentar; i++)
    {
        printf("%d. %s\n", i + 1, forums[index_forum].komentar[i]);
    }

    int index_komentar;
    printf("Pilih nomor komentar: ");
    scanf("%d", &index_komentar);
    getchar();

    if (index_komentar < 1 || index_komentar > forums[index_forum].jml_komentar)
    {
        printf("Nomor komentar tidak valid\n");
        return;
    }

    index_komentar--;

    if (strcmp(users[user_index].username, forums[index_forum].admin) != 0 && strcmp(users[user_index].username, forums[index_forum].komentar[index_komentar]) != 0)
    {
        printf("Hanya admin atau pemilik komentar yang bisa menghapus komentar\n");
        return;
    }

    for (int i = index_komentar; i < forums[index_forum].jml_komentar - 1; i++)
    {
        strcpy(forums[index_forum].komentar[i], forums[index_forum].komentar[i + 1]);
    }

    forums[index_forum].jml_komentar--;

    printf("Komentar berhasil dihapus\n");

    // Simpan data forum setelah menghapus komentar
    simpan_data_forum();
}

int main()
{
    baca_data_user();
    baca_data_forum();

    int choice;
    int user_index = -1;

    do
    {
        printf("\nMenu:\n");
        printf("1. Daftar\n");
        printf("2. Login\n");
        printf("3. Info User\n");
        printf("4. Tambah Forum\n");
        printf("5. Tambah Komentar\n");
        printf("6. Hapus Forum\n");
        printf("7. Hapus Komentar\n");
        printf("8. Info Forum\n");
        printf("9. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            user_baru();
            break;
        case 2:
            user_index = login_user();
            break;
        case 3:
            lihat_info_user();
            break;
        case 4:
            tambah_forum(user_index);
            break;
        case 5:
            tambah_komentar(user_index);
            break;
        case 6:
            hapus_forum(user_index);
            break;
        case 7:
            hapus_komentar(user_index);
            break;
        case 8:
            lihat_info_forum();
            break;
        case 9:
            printf("Terima kasih!\n");
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }
    } while (choice != 9);

    return 0;
}
