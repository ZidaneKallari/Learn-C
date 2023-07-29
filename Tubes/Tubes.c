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

void user_baru()
{
    if (jml_user == max_user)
    {
        printf("Batas maksimal tercapai\n");
        return;
    }

    User buat_user;

    printf("Masukkan username: ");
    fgets(buat_user.username, sizeof(buat_user.username), stdin);
    buat_user.username[strcspn(buat_user.username, "\n")] = '\0';

    for (int i = 0; i < jml_user; i++)
    {
        if (strcmp(users[i].username, buat_user.username) == 0)
        {
            printf("username sudah tersedia\n");
            return;
        }
    }

    printf("Masukkan password: ");
    fgets(buat_user.password, sizeof(buat_user.password), stdin);
    buat_user.password[strcspn(buat_user.password, "\n")] = '\0';

    printf("Masukkan nama: ");
    fgets(buat_user.nama, sizeof(buat_user.nama), stdin);
    buat_user.nama[strcspn(buat_user.nama, "\n")] = '\0';

    printf("Masukkan bio: ");
    fgets(buat_user.bio, sizeof(buat_user.bio), stdin);
    buat_user.bio[strcspn(buat_user.bio, "\n")] = '\0';

    printf("Masukkan nama planet: ");
    fgets(buat_user.planet, sizeof(buat_user.planet), stdin);
    buat_user.planet[strcspn(buat_user.planet, "\n")] = '\0';

    printf("Masukkan gender: ");
    fgets(buat_user.gender, sizeof(buat_user.gender), stdin);
    buat_user.gender[strcspn(buat_user.gender, "\n")] = '\0';

    printf("Masukkan umur: ");
    scanf("%d", &buat_user.umur);
    fflush(stdin);

    buat_user.like = 0;

    users[jml_user++] = buat_user;

    printf("Akun berhasil dibuat\n");
}

int login_user()
{
    char username[50];
    char password[50];
    int x = 0;
    int login = 0;
    int userindex = -1;

    while (x < max_percobaan && !login)
    {
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
                login = 1;
                userindex = i;
                break;
            }
        }

        if (!login)
        {
            x++;
            printf("username/password salah\n");
        }
    }

    if (login)
    {
        printf("Login berhasil\n");
        return userindex;
    }
    else
    {
        printf("Jumlah percobaan sudah habis\n");
        exit(0);
    }
}

void info_user(int userindex)
{
    printf("\nINFORMASI USER\n");
    printf("username: %s\n", users[userindex].username);
    printf("nama: %s\n", users[userindex].nama);
    printf("Bio: %s\n", users[userindex].bio);
    printf("Planet: %s\n", users[userindex].planet);
    printf("Gender: %s\n", users[userindex].gender);
    printf("umur: %d\n", users[userindex].umur);
    printf("like: %d\n", users[userindex].like);
}

void forum_baru()
{
    if (jml_forum == max_forum)
    {
        printf("Batas maksimal tercapai\n");
        return;
    }

    if (jml_user == 0)
    {
        printf("Tidak ada forum\n");
        return;
    }

    Forum buat_forum;

    printf("Masukkan topik: ");
    fgets(buat_forum.topik, sizeof(buat_forum.topik), stdin);
    buat_forum.topik[strcspn(buat_forum.topik, "\n")] = '\0';

    printf("Masukkan kalimat: ");
    fgets(buat_forum.admin, sizeof(buat_forum.admin), stdin);
    buat_forum.admin[strcspn(buat_forum.admin, "\n")] = '\0';

    buat_forum.jml_komentar = 0;

    forums[jml_forum++] = buat_forum;

    printf("Forum berhasil dibuat\n");
}

void hapusforum(int forumindex)
{
    for (int i = forumindex; i < jml_forum - 1; i++)
    {
        forums[i] = forums[i + 1];
    }

    jml_forum--;

    printf("Forum berhasil dihapus\n");
}

void hapusakun(int userindex)
{
    for (int i = userindex; i < jml_user - 1; i++)
    {
        users[i] = users[i + 1];
    }

    jml_user--;

    printf("Akun berhasil dihapus\n");
}

void hapuskomen(int forumindex, int buat_komentarIndex)
{
    for (int i = buat_komentarIndex; i < forums[forumindex].jml_komentar - 1; i++)
    {
        strcpy(forums[forumindex].komentar[i], forums[forumindex].komentar[i + 1]);
    }

    forums[forumindex].jml_komentar--;

    printf("Komentar berhasil dihapus\n");
}

void like(int userindex)
{
    if (jml_user == 0)
    {
        printf("Tidak ada user\n");
        return;
    }

    char carinama[50];
    printf("Masukkan nama user: ");
    fgets(carinama, sizeof(carinama), stdin);
    carinama[strcspn(carinama, "\n")] = '\0';

    int like_user = -1;
    for (int i = 0; i < jml_user; i++)
    {
        if (strcmp(users[i].nama, carinama) == 0)
        {
            like_user = i;
            break;
        }
    }

    if (like_user == -1)
    {
        printf("User tidak ada\n");
        return;
    }

    users[userindex].like++;

    printf("Like berhasil\n");
}

int main()
{
    int pilihan;
    int userindex = -1;

    while (1)
    {
        printf("\nD'Teleforum\n");
        printf("1.Login admin\n");
        printf("2.Buat user baru\n");
        printf("3.Login user\n");
        printf("4.Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
        fflush(stdin);

        switch (pilihan)
        {
        case 1:
            if (login_admin())
            {
                while (1)
                {
                    printf("\nMENU ADMIN\n");
                    printf("1.Tampilkan info user\n");
                    printf("2.Tampilkan forum\n");
                    printf("3.Buat forum\n");
                    printf("4.Hapus forum\n");
                    printf("5.Hapus user\n");
                    printf("6.Logout\n");
                    printf("Masukkan pilihan: ");
                    scanf("%d", &pilihan);
                    fflush(stdin);

                    switch (pilihan)
                    {
                    case 1:
                        lihat_info_user();
                        break;
                    case 2:
                        info_forum();
                        break;
                    case 3:
                        forum_baru();
                        break;
                    case 4:
                        if (jml_forum == 0)
                        {
                            printf("Tidak ada forum\n");
                            break;
                        }
                        int forumindex;
                        printf("Masukkan forum ke berapa yang akan dihapus: ");
                        scanf("%d", &forumindex);
                        fflush(stdin);
                        if (forumindex < 1 || forumindex > jml_forum)
                        {
                            printf("Maaf angka yang anda masukkan salah\n");
                        }
                        else
                        {
                            hapusforum(forumindex - 1);
                        }
                        break;
                    case 5:
                        if (jml_user == 0)
                        {
                            printf("Tidak ada user\n");
                            break;
                        }
                        int userindex;
                        printf("Masukkan user keberapa yang akan dihapus: ");
                        scanf("%d", &userindex);
                        fflush(stdin);
                        if (userindex < 1 || userindex > jml_user)
                        {
                            printf("Maaf angka yang anda masukkan salah\n");
                        }
                        else
                        {
                            hapusakun(userindex - 1);
                        }
                        break;
                    case 6:
                        printf("Logout\n");
                        userindex = -1;
                        break;
                    default:
                        printf("Gagal\n");
                        break;
                    }

                    if (pilihan == 6)
                    {
                        break;
                    }
                }
            }
            break;
        case 2:
            user_baru();
            break;
        case 3:
            userindex = login_user();
            while (userindex >= 0)
            {
                printf("\nMENU USER\n");
                printf("1.Tampilkan info user\n");
                printf("2.Tampilkan forum\n");
                printf("3.Buat komentar\n");
                printf("4.Hapus komentar\n");
                printf("5.LIKE\n");
                printf("6.Logout\n");
                printf("Masukkan pilihan: ");
                scanf("%d", &pilihan);
                fflush(stdin);

                switch (pilihan)
                {
                case 1:
                    info_user(userindex);
                    break;
                case 2:
                    info_forum();
                    break;
                case 3:
                    if (jml_forum == 0)
                    {
                        printf("Tidak ada forum\n");
                        break;
                    }
                    int forumindex;
                    printf("Forum ke-berapa yang akan dikomentari: ");
                    scanf("%d", &forumindex);
                    fflush(stdin);
                    if (forumindex < 1 || forumindex > jml_forum)
                    {
                        printf("Maaf angka yang anda masukkan salah\n");
                    }
                    else
                    {
                        char buat_komentar[100];
                        printf("Masukkan your buat_komentar: ");
                        fgets(buat_komentar, sizeof(buat_komentar), stdin);
                        buat_komentar[strcspn(buat_komentar, "\n")] = '\0';
                        strcpy(forums[forumindex - 1].komentar[forums[forumindex - 1].jml_komentar], buat_komentar);
                        forums[forumindex - 1].jml_komentar++;
                        printf("Komentar berhasil ditambahkan\n");
                    }
                    break;
                case 4:
                    if (jml_forum == 0)
                    {
                        printf("Tidak ada forum\n");
                        break;
                    }
                    int hapus_forum;
                    printf("Masukkan forum keberapa yang akan dihapus: ");
                    scanf("%d", &hapus_forum);
                    fflush(stdin);
                    if (hapus_forum < 1 || hapus_forum > jml_forum)
                    {
                        printf("Maaf angka yang anda masukkan salah\n");
                        break;
                    }
                    if (forums[hapus_forum - 1].jml_komentar == 0)
                    {
                        printf("Tidak ada komentar\n");
                        break;
                    }
                    int hapus_komentar;
                    printf("Masukkan komentar keberapa yang akan dihapus: ");
                    scanf("%d", &hapus_komentar);
                    fflush(stdin);
                    if (hapus_komentar < 1 || hapus_komentar > forums[hapus_forum - 1].jml_komentar)
                    {
                        printf("Maaf angka yang anda masukkan salah\n");
                        break;
                    }
                    hapuskomen(hapus_forum - 1, hapus_komentar - 1);
                    break;
                case 5:
                    like(userindex);
                    break;
                case 6:
                    printf("Logout\n");
                    userindex = -1;
                    break;
                default:
                    printf("Gagal\n");
                    break;
                }

                if (pilihan == 6)
                {
                    break;
                }
            }
            break;
        case 4:
            printf("Keluar program...\n");
            exit(0);
        default:
            printf("Gagal\n");
            break;
        }
    }

    return 0;
}
