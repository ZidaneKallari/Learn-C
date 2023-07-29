#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data_admin{
    char username[20], password[20];
    char forum[50][100], komentar [200][500][1000];
    int jumlah_forum;
    int jumlah_komentar[50];

};
struct data_admin admin;
int login_admin(const char *username, const char *password) {
    strcpy(admin.username, "salamsatunyali");
    strcpy(admin.password, "wani");
    if (strcmp(admin.username, username) == 0 && strcmp(admin.password, password) == 0)
    {
        return 1;
    }
    return 0;
}
struct data_user{
    char username[20], password[20];
    char nama[50], bio[1000], asal_planet[1000], gender[20];
    int umur, like;
};
struct data_user data[5];
int usermaks = 0;


void simpan_data_user_ke_file() {
    FILE *datus = fopen("data_user.txt", "wb");
    if (datus == NULL) {
        printf("Gagal membuka file data_user.txt\n");
        return;
    }

    fwrite(data, sizeof(struct data_user), usermaks, datus);

    fclose(datus);
    printf("Data pengguna berhasil disimpan ke file.\n");
}


void baca_data_user_dari_file() {
    FILE *datus = fopen("data_user.txt", "rb");
    if (datus == NULL) {
        printf("Gagal membuka file data_user.txt\n");
        return;
    }

    usermaks = fread(data, sizeof(struct data_user), 5, datus);

    fclose(datus);
    printf("Data pengguna berhasil dibaca dari file.\n");
}

void simpan_forum_ke_file() {
    FILE *datforum = fopen("data_forum.txt", "w");
    if (datforum == NULL) {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }

    for (int i = 0; i < admin.jumlah_forum; i++) {
        fprintf(datforum, "%s\n", admin.forum[i]);

        for (int j = 0; j < admin.jumlah_komentar[i]; j++) {
            fprintf(datforum, "%s\n", admin.komentar[i][j]);
        }
        fprintf(datforum, "\n");
    }

    fclose(datforum);
    printf("Data forum berhasil disimpan ke file.\n");
}

void baca_forum_dari_file() {
    FILE *datforum = fopen("data_forum.txt", "r");
    if (datforum == NULL) {
        printf("Gagal membuka file data_forum.txt\n");
        return;
    }

    admin.jumlah_forum = 0;

    char line[500];
    int komentar_index = 0;

    while (fgets(line, sizeof(line), datforum)) {
        if (line[0] != '\n') {
            strcpy(admin.forum[admin.jumlah_forum], line);
            admin.jumlah_komentar[admin.jumlah_forum] = 0;
            admin.jumlah_forum++;
        } else {
            komentar_index = 0;
        }

        if (line[0] != '\n' && line[0] != '\0') {
            strcpy(admin.komentar[admin.jumlah_forum - 1][komentar_index], line);
            admin.jumlah_komentar[admin.jumlah_forum - 1]++;
            komentar_index++;
        }
    }

    fclose(datforum);
    printf("Data forum berhasil dibaca dari file.\n");
}


void informasi_user() {
    int i, j;
    printf("\n=== Informasi Akun ===\n");
    printf("======================\n\n");

    if (usermaks == 0) {
        printf("Belum ada user yang terdaftar.\n");
        return;
    }

    for (i = 0; i < usermaks; i++) {
        for (j = i + 1; j < usermaks; j++) {
            if (strcmp(data[i].username, data[j].username) > 0) {
                struct data_user temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    for (i = 0; i < usermaks; i++) {
        printf("Nama : %s.\n", data[i].username);
        printf("Bio : %s\n", data[i].bio);
        printf("Asal planet : %s\n", data[i].asal_planet);
        printf("Gender : %s\n", data[i].gender);
        printf("Umur : %d\n", data[i].umur);
    }
}


void buat_forum() {
    printf("\n=== Buat Forum ===\n");
    printf("================\n\n");

    if (admin.jumlah_forum >= 20)
    {
        printf("Jumlah forum sudah mencapai batas maksimal\n");
        return;
    }
    printf("Masukkan judul forum: ");
    char judul[100];
    scanf(" %s", judul);

    strcpy(admin.forum[admin.jumlah_forum], judul);
    admin.jumlah_komentar[admin.jumlah_forum] = 0;
    admin.jumlah_forum++;
    printf("Forum berhasil ditambahkan.\n");
    
}


void chat_forum() {
    int i;
    printf("\n=== Chat Forum ===\n");
    printf("==================\n\n");

    for (int i = 0; i < admin.jumlah_forum; i++) {
        printf("%d. %s\n", i + 1, admin.forum[i]);
        printf("   Jumlah Komentar: %d\n", admin.jumlah_komentar[i]);
    }
}


void hapus_forum() {
    printf("\n=== Menghapus Forum ===\n");
    printf("======================\n\n");

    printf("Forum yang tersedia:\n");
    for (int i = 0; i < admin.jumlah_forum; i++) {
        printf("%d. %s\n", i + 1, admin.forum);
    }

    int nomor_forum;
    printf("Pilih nomor forum yang akan dihapus: ");
    scanf("%d", &nomor_forum);

    if (nomor_forum < 1 || nomor_forum > admin.jumlah_forum) {
        printf("Nomor forum tidak valid.\n");
        return;
    }

    
    for (int i = nomor_forum - 1; i < admin.jumlah_forum - 1; i++) {
        strcpy(admin.forum[i], admin.forum[i + 1]);
    }
    admin.jumlah_forum--;

    printf("Forum berhasil dihapus.\n");
}


void komentar() {
    int i, nomor_forum;
    char komentar_baru[100];

    printf("\n=== Tambahkan Komentar ===\n");
    printf("==========================\n\n");

    printf("Forum yang tersedia:\n");
    for (i = 0; i < admin.jumlah_forum; i++) {
        printf("%d. %s\n", i + 1, admin.forum[i]);
    }

    printf("Pilih Forum: ");
    scanf("%d", &nomor_forum);

    if (nomor_forum < 1 || nomor_forum > admin.jumlah_forum) {
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

void hapus_komentar() {
    int nomor_forum, nomor_komentar;

    printf("\n=== Hapus Komentar ===\n");
    printf("======================\n\n");

    printf("Forum yang tersedia:\n");
    for (int i = 0; i < admin.jumlah_forum; i++) {
        printf("%d. %s\n", i + 1, admin.forum[i]);
    }

    printf("Pilih nomor forum: ");
    scanf("%d", &nomor_forum);

    if (nomor_forum < 1 || nomor_forum > admin.jumlah_forum) {
        printf("Nomor forum tidak valid.\n");
        return;
    }

    printf("Komentar yang tersedia di forum ini:\n");
    for (int i = 0; i < admin.jumlah_komentar[nomor_forum - 1]; i++) {
        printf("%d. %s\n", i + 1, admin.komentar[nomor_forum - 1][i]);
    }

    printf("Pilih nomor komentar yang akan dihapus: ");
    scanf("%d", &nomor_komentar);

    if (nomor_komentar < 1 || nomor_komentar > admin.jumlah_komentar[nomor_forum - 1]) {
        printf("Nomor komentar tidak valid.\n");
        return;
    }

    for (int i = nomor_komentar - 1; i < admin.jumlah_komentar[nomor_forum - 1] - 1; i++) {
        strcpy(admin.komentar[nomor_forum - 1][i], admin.komentar[nomor_forum - 1][i + 1]);
    }
    admin.jumlah_komentar[nomor_forum - 1]--;

    printf("Komentar berhasil dihapus.\n");
}



int cari_akun(const char* username) {
    for (int i = 0; i < usermaks; i++) {
        if (strcmp(data[i].username, username) == 0) {
            return i; 
        }
    }
    return -1; 
}


void like_akun(const char* username) {
    int jumlah = cari_akun(username);
    if (jumlah != -1) {
        data[jumlah].like++; 
        printf("Anda memberikan 'like' kepada %s\n", username);
    } else {
        printf("Pengguna %s tidak ditemukan\n", username);
    }
}


void tampilkan_akun(const struct data_user* user) {
    printf("Username: %s\n", user->username);
    printf("Likes: %d\n", user->like);
}


void clearConsole() {
    system("cls");
}


void registrasi_akun() {
    struct data_user user;
    if (usermaks >= 5) {
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

    printf("OKE! Registrasi berhasil\n\n");
}


int login_akun(const char *username, const char *password) {
    for (int i = 0; i <= usermaks; i++){
    if (strcmp(data[i].username, username)== 0 && strcmp(data[i].password, password)== 0) {
        return 1;
        }
    } 
    return 0;
}
int main() {
    baca_data_user_dari_file();
    baca_forum_dari_file();
    int i, kesempatan_maks = 3;
    do
    {
        clearConsole();
        printf("=== Menu D'Teleforum ===\n");
        printf("=======================\n\n");

        printf("1. Login Admin\n");
        printf("2. Registrasi Akun\n");
        printf("3. Login Akun\n");
        printf("4. Keluar\n");

        printf("Pilih : ");
        scanf("%d", &i);

        switch (i)
        {
        case 1 :{
            char adminuser[20] = "admin", adminpass[20];
            printf("\n===Khusus Admin===\n");
            printf("Username : ");
            scanf("%s", adminuser);
            printf("Password : ");
            scanf("%s", adminpass);

            if (login_admin(adminuser, adminpass))
            {
                printf("Login berhasil\n\n");
                char admin_menu;
            do
            {
                clearConsole();
                printf("=== Menu Admin ===\n");
                printf("================\n\n");

                printf("1. Informasi Akun\n");
                printf("2. Buat forum\n");
                printf("3. Chat forum\n");
                printf("4. Hapus Forum\n");
                printf("5. Keluar\n");

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
                    chat_forum();
                    break;
                case 4:
                    hapus_forum();
                    break;
                case 5:
                    printf("Terimakasih telah menggunakan layanan kami\n");
                    break;
                default:
                    printf("Pilihan anda tidak tersedia\n");
                    break;
                }printf("Kalo mau lanjut tekan Enter:)");
                getchar();
                getchar();

            } while (admin_menu !=5);
        } else {
            printf("Username atau password anda salah\n\n");
        }
        break;
        }
        case 2:
        registrasi_akun();
            break;
        case 3:{
            char name[20], pass[20];
            int kesempatan_maks = 3, j = kesempatan_maks;
        printf("\n=== Masukkan Data Anda Dengan Benar!===\n");
        printf("Username : ");
        scanf("%s", name);
        printf("Password : ");
        scanf("%s", pass);
    while (j > 0) { 
                if (login_akun(name, pass)) {
                    printf("Login berhasil\n\n");
                    j = kesempatan_maks;
                    char user_menu;
     do {
    clearConsole();
    printf("=== Menu User ===\n");
    printf("====================\n\n");
    printf("1. Informasi Akun\n");
    printf("2. Chat forum\n");
    printf("3. Like\n");
    printf("4. Keluar\n");

    printf("Pilih : ");
    scanf("%d", &user_menu);

    switch (user_menu) {
        case 1:
            informasi_user();
            break;
        case 2:
            chat_forum();
                int i;
        do{
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
                } while (i !=3);
        case 3:{
        int like;
        char username[20];
        do {
            printf("1. Berikan like\n");
            printf("2. Keluar\n");
            printf("pilih : ");
            scanf("%d", &like);

            switch (like) {
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

        } while (like !=2);
        case 4:
            printf("Terima kasih telah menggunakan layanan kami.\n");
            break;
        default:
            printf("Pilihan Anda tidak tersedia.\n");
            break;
            }
        }  printf("Kalo mau lanjut tekan Enter:)");
        getchar();
        getchar();
    }
    while (user_menu != 4);         
            break;
                } else {
                    j--;
                    printf("Username atau password salah. Silakan coba lagi.\n\n");

                    if (j < 1) {
                        printf("Anda sudah melebihi batas maksimal, coba lagi nanti!\n");
                    } else {
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