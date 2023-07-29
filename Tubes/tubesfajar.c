#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk paket foto
struct PaketFoto
{
    char nama[50];
    int harga;
};

// Struktur data untuk pemesanan
struct Pemesanan
{
    char nama[50];
    char alamat[100];
    int jumlah_orang;
    char tanggal[20];
};

// Array untuk menyimpan paket foto
struct PaketFoto paketFoto[100];
int jumlahPaket = 0;

// Array untuk menyimpan daftar pemesanan
struct Pemesanan daftarPemesanan[100];
int jumlahPemesanan = 0;

// Variabel status login
int isLoggedIn = 0;
int isAdmin = 0;

void menuPelanggan()
{
    printf("================================\n");
    printf("Menu Pelanggan:\n");
    printf("1. Registrasi\n");
    printf("2. Login\n");
    printf("3. Cari Paket Foto\n");
    printf("4. Pilih Paket Foto\n");
    printf("5. Cetak Foto dengan Frame\n");
    printf("6. Top Up & Lihat Bill\n");
    printf("0. Keluar\n");
    printf("================================\n");
    printf("Pilihan: ");
}

void menuAdmin()
{
    printf("================================\n");
    printf("Menu Admin:\n");
    printf("1. Tambah Paket Foto\n");
    printf("2. Hapus Paket Foto\n");
    printf("3. Edit Stok Frame Foto\n");
    printf("4. Edit Jumlah Orang dalam Paket Foto\n");
    printf("5. Cetak Daftar Pemesanan\n");
    printf("6. Lihat Income\n");
    printf("7. Input & Lihat Shift Fotografer\n");
    printf("0. Keluar\n");
    printf("================================\n");
    printf("Pilihan: ");
}

void tambahPaketFoto()
{
    char nama[50];
    int harga;

    printf("Masukkan nama paket foto: ");
    scanf(" %[^\n]", nama);
    printf("Masukkan harga paket foto: ");
    scanf("%d", &harga);

    strcpy(paketFoto[jumlahPaket].nama, nama);
    paketFoto[jumlahPaket].harga = harga;
    jumlahPaket++;

    printf("Paket foto berhasil ditambahkan.\n");
}

void hapusPaketFoto()
{
    cetakDaftarPaketFoto();

    int pilihan;
    printf("Pilih nomor paket foto yang akan dihapus: ");
    scanf("%d", &pilihan);

    if (pilihan >= 1 && pilihan <= jumlahPaket)
    {
        for (int i = pilihan - 1; i < jumlahPaket - 1; i++)
        {
            strcpy(paketFoto[i].nama, paketFoto[i + 1].nama);
            paketFoto[i].harga = paketFoto[i + 1].harga;
        }
        jumlahPaket--;

        printf("Paket foto berhasil dihapus.\n");
    }
    else
    {
        printf("Pilihan tidak valid.\n");
    }
}

int cariPaketFoto2(char namaPaket[])
{
    for (int i = 0; i < jumlahPaket; i++)
    {
        if (strcmp(paketFoto[i].nama, namaPaket) == 0)
        {
            return i;
        }
    }
    return -1;
}

void cetakDaftarPaketFoto()
{
    if (jumlahPaket == 0)
    {
        printf("Belum ada paket foto yang tersedia.\n");
    }
    else
    {
        printf("Daftar Paket Foto:\n");
        for (int i = 0; i < jumlahPaket; i++)
        {
            printf("%d. Nama: %s\n", i + 1, paketFoto[i].nama);
            printf("   Harga: %d\n", paketFoto[i].harga);
        }
    }
}

void cetakDaftarPemesanan()
{
    if (jumlahPemesanan == 0)
    {
        printf("Belum ada pemesanan.\n");
    }
    else
    {
        printf("Daftar Pemesanan:\n");
        for (int i = 0; i < jumlahPemesanan; i++)
        {
            printf("%d. Nama: %s\n", i + 1, daftarPemesanan[i].nama);
            printf("   Alamat: %s\n", daftarPemesanan[i].alamat);
            printf("   Jumlah Orang: %d\n", daftarPemesanan[i].jumlah_orang);
            printf("   Tanggal: %s\n", daftarPemesanan[i].tanggal);
        }
    }
}

void cariPaketFoto()
{
    char namaPaket[50];
    printf("Masukkan nama paket foto yang ingin dicari: ");
    scanf(" %[^\n]", namaPaket);

    int indeksPaket = cariPaketFoto2(namaPaket);
    if (indeksPaket != -1)
    {
        printf("Paket foto ditemukan:\n");
        printf("Nama: %s\n", paketFoto[indeksPaket].nama);
        printf("Harga: %d\n", paketFoto[indeksPaket].harga);
    }
    else
    {
        printf("Paket foto tidak ditemukan.\n");
    }
}

void pilihPaketFoto()
{
    cetakDaftarPaketFoto();

    int pilihan;
    printf("Pilih nomor paket foto yang ingin dipilih: ");
    scanf("%d", &pilihan);

    if (pilihan >= 1 && pilihan <= jumlahPaket)
    {
        char namaPaket[50];
        strcpy(namaPaket, paketFoto[pilihan - 1].nama);

        int indeksPaket = cariPaketFoto2(namaPaket);
        if (indeksPaket != -1)
        {
            printf("Paket foto berhasil dipilih.\n");
            printf("Nama: %s\n", paketFoto[indeksPaket].nama);
            printf("Harga: %d\n", paketFoto[indeksPaket].harga);

            printf("Masukkan nama pelanggan: ");
            scanf(" %[^\n]", daftarPemesanan[jumlahPemesanan].nama);
            printf("Masukkan alamat pelanggan: ");
            scanf(" %[^\n]", daftarPemesanan[jumlahPemesanan].alamat);
            printf("Masukkan jumlah orang: ");
            scanf("%d", &daftarPemesanan[jumlahPemesanan].jumlah_orang);
            printf("Masukkan tanggal pemesanan: ");
            scanf(" %[^\n]", daftarPemesanan[jumlahPemesanan].tanggal);

            jumlahPemesanan++;
        }
        else
        {
            printf("Paket foto tidak ditemukan.\n");
        }
    }
    else
    {
        printf("Pilihan tidak valid.\n");
    }
}

void cetakFotoFrame()
{
    // Implementasi cetak foto dengan frame
    printf("Melakukan proses pencetakan foto dengan frame.\n");

    // Contoh logika implementasi tambahan
    // Buka file foto
    FILE *foto = fopen("foto.jpg", "r");
    if (foto == NULL)
    {
        printf("Gagal membuka file foto.\n");
        return;
    }

    // Tambahkan frame pada foto
    // ...

    // Simpan hasil cetakan
    FILE *cetakan = fopen("cetakan.jpg", "w");
    if (cetakan == NULL)
    {
        printf("Gagal menyimpan hasil cetakan.\n");
        fclose(foto);
        return;
    }

    // Salin isi file foto ke file cetakan
    int ch;
    while ((ch = fgetc(foto)) != EOF)
    {
        fputc(ch, cetakan);
    }

    // Tutup file
    fclose(foto);
    fclose(cetakan);

    printf("Foto dengan frame berhasil dicetak dan disimpan.\n");
}

void topUpLihatBill()
{
    printf("Melakukan proses top up dan melihat bill pembayaran.\n");

    // Logika implementasi tambahan
    // Menerima input top up
    float amount;
    printf("Masukkan jumlah top up: ");
    scanf("%f", &amount);

    // Update saldo
    float saldo = 1000; // Saldo awal
    saldo += amount;

    // Rekam transaksi
    FILE *fileTransaksi = fopen("transaksi.txt", "a");
    if (fileTransaksi == NULL)
    {
        printf("Gagal membuka file transaksi.\n");
        return;
    }

    fprintf(fileTransaksi, "Top up: +%.2f\n", amount);

    // Menutup file transaksi
    fclose(fileTransaksi);

    // Menampilkan saldo terkini dan bill pembayaran
    printf("Saldo terkini: %.2f\n", saldo);
    printf("Bill pembayaran: ...\n");
}

void editStokFrameFoto()
{
    printf("Melakukan proses pengeditan stok frame foto.\n");

    // Logika implementasi tambahan
    // Baca stok frame foto dari file teks
    int stokFrameFoto;
    FILE *fileStok = fopen("stok.txt", "r");
    if (fileStok == NULL)
    {
        printf("Gagal membuka file stok.\n");
        return;
    }
    fscanf(fileStok, "%d", &stokFrameFoto);
    fclose(fileStok);

    // Tampilkan stok frame foto saat ini
    printf("Stok frame foto saat ini: %d\n", stokFrameFoto);

    // Menerima input jumlah tambahan atau pengurangan stok
    int jumlah;
    printf("Masukkan jumlah frame foto yang akan ditambahkan (positif) atau dikurangi (negatif): ");
    scanf("%d", &jumlah);

    // Perbarui stok frame foto
    stokFrameFoto += jumlah;

    // Simpan perubahan stok frame foto ke dalam file teks
    fileStok = fopen("stok.txt", "w");
    if (fileStok == NULL)
    {
        printf("Gagal menyimpan perubahan stok.\n");
        return;
    }
    fprintf(fileStok, "%d", stokFrameFoto);
    fclose(fileStok);

    // Tampilkan stok frame foto terbaru
    printf("Stok frame foto terbaru: %d\n", stokFrameFoto);
}

void editJumlahOrangPaketFoto()
{
    printf("Melakukan proses pengeditan jumlah orang dalam paket foto.\n");

    // Logika implementasi tambahan
    // Baca jumlah orang dalam paket foto dari file teks
    int jumlahOrangPaketFoto;
    FILE *fileJumlah = fopen("jumlah.txt", "r");
    if (fileJumlah == NULL)
    {
        printf("Gagal membuka file jumlah.\n");
        return;
    }
    fscanf(fileJumlah, "%d", &jumlahOrangPaketFoto);
    fclose(fileJumlah);

    // Tampilkan jumlah orang dalam paket foto saat ini
    printf("Jumlah orang dalam paket foto saat ini: %d\n", jumlahOrangPaketFoto);

    // Menerima input jumlah orang baru
    int jumlahBaru;
    printf("Masukkan jumlah orang baru dalam paket foto: ");
    scanf("%d", &jumlahBaru);

    // Perbarui jumlah orang dalam paket foto
    jumlahOrangPaketFoto = jumlahBaru;

    // Simpan perubahan jumlah orang dalam paket foto ke dalam file teks
    fileJumlah = fopen("jumlah.txt", "w");
    if (fileJumlah == NULL)
    {
        printf("Gagal menyimpan perubahan jumlah orang.\n");
        return;
    }
    fprintf(fileJumlah, "%d", jumlahOrangPaketFoto);
    fclose(fileJumlah);

    // Tampilkan jumlah orang dalam paket foto terbaru
    printf("Jumlah orang dalam paket foto terbaru: %d\n", jumlahOrangPaketFoto);
}

void lihatIncome()
{
    printf("Melakukan proses melihat income.\n");

    // Logika implementasi tambahan
    // Baca data income dari file atau database
    float income[] = {1500.0, 2000.0, 3000.0, 2500.0, 1800.0}; // Contoh data income
    int jumlahTransaksi = sizeof(income) / sizeof(income[0]);

    // Tampilkan income saat ini
    printf("Income saat ini:\n");
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        printf("  - Transaksi %d: %.2f\n", i + 1, income[i]);
    }

    // Logika tambahan: Perhitungan total income dari data yang ada
    float totalIncome = 0.0;
    for (int i = 0; i < jumlahTransaksi; i++)
    {
        totalIncome += income[i];
    }

    // Tampilkan total income
    printf("Total income: %.2f\n", totalIncome);

    // Logika tambahan: Perhitungan rata-rata income per transaksi
    float rataRataIncome = totalIncome / jumlahTransaksi;

    // Tampilkan rata-rata income per transaksi
    printf("Rata-rata income per transaksi: %.2f\n", rataRataIncome);

    // Logika tambahan: Statistik income (maksimum, minimum)
    float maksimum = income[0];
    float minimum = income[0];
    for (int i = 1; i < jumlahTransaksi; i++)
    {
        if (income[i] > maksimum)
        {
            maksimum = income[i];
        }
        if (income[i] < minimum)
        {
            minimum = income[i];
        }
    }

    // Tampilkan statistik income
    printf("Statistik income:\n");
    printf("  - Maksimum: %.2f\n", maksimum);
    printf("  - Minimum: %.2f\n", minimum);

    // ...
}

void inputShiftFotografer()
{
    printf("Melakukan proses input dan lihat shift kerja fotografer.\n");

    // Logika implementasi tambahan
    // Baca data shift fotografer dari file teks
    int shiftFotografer;
    FILE *fileShift = fopen("shift.txt", "r");
    if (fileShift == NULL)
    {
        printf("Gagal membuka file shift.\n");
        return;
    }
    fscanf(fileShift, "%d", &shiftFotografer);
    fclose(fileShift);

    // Tampilkan shift fotografer saat ini
    printf("Shift fotografer saat ini: %d\n", shiftFotografer);

    // Menerima input shift baru
    int shiftBaru;
    printf("Masukkan shift baru untuk fotografer: ");
    scanf("%d", &shiftBaru);

    // Validasi input shift baru
    if (shiftBaru < 1 || shiftBaru > 3)
    {
        printf("Shift yang dimasukkan tidak valid.\n");
        return;
    }

    // Perbarui shift fotografer
    shiftFotografer = shiftBaru;

    // Simpan perubahan shift fotografer ke file teks
    fileShift = fopen("shift.txt", "w");
    if (fileShift == NULL)
    {
        printf("Gagal menyimpan perubahan shift fotografer.\n");
        return;
    }
    fprintf(fileShift, "%d", shiftFotografer);
    fclose(fileShift);

    // Tampilkan shift fotografer terbaru
    printf("Shift fotografer terbaru: %d\n", shiftFotografer);
}

void loginAdmin()
{
    char username[20];
    char password[20];

    printf("Username: ");
    scanf(" %[^\n]", username);
    printf("Password: ");
    scanf(" %[^\n]", password);

    // Verifikasi username dan password
    // Jika verifikasi berhasil, set isLoggedIn dan isAdmin menjadi 1
    // Jika verifikasi gagal, tampilkan pesan error
}

void loginPelanggan()
{
    // Implementasi login pelanggan
    // Jika login berhasil, set isLoggedIn menjadi 1
    // Jika login gagal, tampilkan pesan error
}

void registrasiPelanggan()
{
    // Implementasi registrasi pelanggan
    // Jika registrasi berhasil, tampilkan pesan sukses
    // Jika registrasi gagal, tampilkan pesan error
}

int main()
{
    int pilihan;
    while (1)
    {
        if (isLoggedIn == 0)
        {
            menuPelanggan();
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                registrasiPelanggan();
                break;
            case 2:
                loginPelanggan();
                break;
            case 3:
                cariPaketFoto();
                break;
            case 4:
                pilihPaketFoto();
                break;
            case 5:
                cetakFotoFrame();
                break;
            case 6:
                topUpLihatBill();
                break;
            case 0:
                printf("Terima kasih telah menggunakan program D'Jepret.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
            }
        }
        else if (isAdmin == 1)
        {
            menuAdmin();
            scanf("%d", &pilihan);
            switch (pilihan)
            {
            case 1:
                tambahPaketFoto();
                break;
            case 2:
                hapusPaketFoto();
                break;
            case 3:
                editStokFrameFoto();
                break;
            case 4:
                editJumlahOrangPaketFoto();
                break;
            case 5:
                cetakDaftarPemesanan();
                break;
            case 6:
                lihatIncome();
                break;
            case 7:
                inputShiftFotografer();
                break;
            case 0:
                printf("Terima kasih telah menggunakan program D'Jepret.\n");
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
            }
        }
    }

    return 0;
}
