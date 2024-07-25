#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define RESET       "\033[0m"
#define BLACK       "\033[30m" /* Warna hitam */
#define RED         "\033[31m" /* Warna merah */
#define GREEN       "\033[32m" /* Warna hijau */
#define YELLOW      "\033[33m" /* Warna kuning */
#define BLUE        "\033[34m" /* Warna biru */
#define MAGENTA     "\033[35m" /* Warna ungu */
#define CYAN        "\033[36m" /* Warna cyan */
#define WHITE       "\033[37m" /* Warna putih */
#define BOLD        "\033[1m"  /* Huruf tebal */
#define UNDERLINE   "\033[4m"  /* Huruf bergaris bawah */

#define GOLD       "\033[38;2;255;215;0m"  // RGB values for gold color
#define SILVER     "\033[38;2;192;192;192m" // RGB values for silver color
#define NEON_GREEN "\033[38;2;57;255;20m"   // RGB values for neon green color
#define REDDISH_PINK "\033[38;2;208;113;113m"  // RGB values for #D07171 (reddish-pink)
#define LIGHT_BROWN "\033[38;2;210;180;140m" // RGB values for light brown color
#define NEON_RED     "\033[38;2;255;0;0m"  // RGB values for neon red

struct barang {
    string namaBarang;
    string kodeBarang;
    double hargaBarang;
    string kategoriBarang;
    int jumlahBarang;
};

void menuKaryawan() {
    cout << endl;
    cout << BOLD << "==========[" << YELLOW << "SELAMAT DATANG ADMIN" << RESET << BOLD << "]=========" << RESET << endl;
    cout << "1. Masukkan barang baru" << endl;
    cout << "2. Edit barang yang ada" << endl;
    cout << "3. Ubah stok barang" << endl;
    cout << "4. Hapus barang" << endl;
    cout << "5. Tampilkan stok" << endl;
    cout << "6. Exit" << endl;
}

void menuPelanggan() {
    cout << endl;
    cout << BOLD << "==========[" << YELLOW << "SELAMAT DATANG DI TOKOSERBA ADA JANUARI" << RESET << BOLD << "]=========" << RESET << endl;
    cout << BOLD << "Ada yang bisa kami bantu?" << endl;
    cout << "1. Lihat stok barang" << endl;
    cout << "2. Cari barang" << endl;
    cout << "3. Exit" << endl;
}

void displayKategoriBarang() {
    cout << endl;
    cout << BOLD << "=====[ " << LIGHT_BROWN << "Jenis Barang" << RESET << BOLD" ]=====" << RESET << endl;
    cout << "1. Makanan Ringan" << endl;
    cout << "2. Bahan Makanan" << endl;
    cout << "3. Frozen Food" << endl;
    cout << "4. Minuman" << endl;
    cout << "5. Makanan & Minuman Instan" << endl;
    cout << "6. Produk Kebersihan" << endl;
    cout << "7. Alat Tulis" << endl;
    cout << "8. Elektronik" << endl;
}

string getKategoriBarang(int choice) {
    switch (choice) {
        case 1: return "Makanan Ringan";
        case 2: return "Bahan Makanan";
        case 3: return "Frozen Food";
        case 4: return "Minuman";
        case 5: return "Makanan & Minuman Instan";
        case 6: return "Produk Kebersihan";
        case 7: return "Alat Tulis";
        case 8: return "Elektronik";
        default: return "Jenis tidak valid";
    }
}

void tambahBarang(vector<barang>& data) {
    barang newData;
    cout << BOLD << "\n=====[ " << LIGHT_BROWN << "Input Barang" << RESET << BOLD << " ]=====" << RESET << endl;
    cout << BOLD << "Masukan kode barang : " << RESET;
    getline(cin, newData.kodeBarang);
    cout << BOLD << "Masukan nama barang : " << RESET;
    getline(cin, newData.namaBarang);

    displayKategoriBarang();
    int jenisChoice;
    cout << BOLD << "Masukan pilihan jenis barang (1-8) : " << RESET;
    cin >> jenisChoice;
    cin.ignore();
    newData.kategoriBarang = getKategoriBarang(jenisChoice);

    cout << BOLD << "Masukan harga                      : " << RESET;
    cin >> newData.hargaBarang;
    cin.ignore();

    cout << BOLD << "Masukan jumlah                     : " << RESET;
    cin >> newData.jumlahBarang;
    cin.ignore();

    if (jenisChoice < 1 || jenisChoice > 6 || newData.hargaBarang <= 0) {
        cout << BOLD << NEON_RED << "\nInput tidak valid! Pastikan jenis barang (1-8) dan harga barang positif." << RESET << endl;
        return;
    }

    data.push_back(newData);
    cout << BOLD << NEON_GREEN << "\nData berhasil ditambahkan!" << RESET << endl;
}

void displayBarang(const std::vector<barang>& data) {
    for (const auto& item : data) {
        std::cout << "Kode Barang: " << item.kodeBarang << std::endl;
        std::cout << "Nama Barang: " << item.namaBarang << std::endl;
        std::cout << "Jenis Barang: " << item.kategoriBarang << std::endl;
        std::cout << "Harga Barang: Rp. " << item.hargaBarang << std::endl;
        std::cout << "Jumlah Barang: " << item.jumlahBarang << std::endl;
    }
}

void updateBarang(vector<barang>& data) {
    displayBarang(data);

    int index;
    cout << BOLD << "Masukan index data yang ingin diubah: " << RESET;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > data.size()) {
        cout << BOLD << "\nIndeks tidak valid! Perubahan data gagal." << RESET << endl;
        return;
    }
    cout << endl;
    cout << BOLD << "========[ " << GOLD <<"Data Exchange" << RESET << BOLD << " ]========" << RESET << endl;
    cout << BOLD << "Kode Barang   : " << RESET << data[index - 1].kodeBarang << endl;
    cout << BOLD << "Nama Barang   : " << RESET << data[index - 1].namaBarang << endl;
    cout << BOLD << "Jenis Barang  : " << RESET << data[index - 1].kategoriBarang << endl;
    cout << BOLD << "Harga Barang  : " << RESET << data[index - 1].hargaBarang << endl;
    cout << BOLD << "Jumlah Barang : " << RESET << data[index - 1].jumlahBarang << endl;

    int choice;
    while (true) {
        cout << endl;
        cout << BOLD << "Pilih data barang yang ingin anda ubah : " << RESET;
        cin >> choice;
        cin.ignore();

        switch (choice){
        case 1:
            cout << BOLD << "Masukkan kode barang baru : " << RESET;
            getline(cin, data[index - 1].kodeBarang);
            break;
        case 2:
            cout << BOLD << "Masukkan nama barang baru : " << RESET;
            getline(cin, data[index - 1].namaBarang);
            break;
        case 3:
            cout << endl;
            cout << BOLD << "========[ " << GOLD << "Jenis Barang" << RESET << BOLD" ]========" << RESET << endl;
            cout << "1. Makanan Ringan" << endl;
            cout << "2. Bahan Makanan" << endl;
            cout << "3. Frozen Food" << endl;
            cout << "4. Minuman" << endl;
            cout << "5. Makanan & Minuman Instan" << endl;
            cout << "6. Produk Kebersihan" << endl;
            cout << "7. Alat Tulis" << endl;
            cout << "8. Elektronik" << endl;

            int jenisChoice;
            cout << BOLD << "Masukan pilihan jenis barang baru : " << RESET;
            cin >> jenisChoice;
            cin.ignore();
            data[index - 1].kategoriBarang = getKategoriBarang(jenisChoice);
            break;
        case 4:
            cout << BOLD << "Masukan harga barang baru         : " << RESET;
            cin >> data[index - 1].hargaBarang;
            cin.ignore();
            break;
        case 5:
            cout << BOLD << "Masukan jumlah barang baru        : " << RESET;
            cin >> data[index - 1].jumlahBarang;
            cin.ignore();
            break;
        case 6:
            continue;
        default:
            cout << "Index yang anda masukkan tidak valid\n" << endl;
            break;
        }
        cout << BOLD << NEON_GREEN << "\nData berhasil diubah!" << RESET << endl;
    }
}

void deleteData(vector<barang>& data) {
    cout << BOLD << "\n======[ " << NEON_RED << "Data Barang" << RESET << BOLD << " ]======" << endl;
    for (int i = 0; i < data.size(); ++i) {
        cout << "Index: " << i + 1 << endl;
        cout << "Kode Barang   : " << data[i].kodeBarang << endl;
        cout << "Nama Barang   : " << data[i].namaBarang << endl;
        cout << "Jenis Barang  : " << data[i].kategoriBarang << endl;
        cout << "Harga Barang  : Rp." << data[i].hargaBarang << endl;
        cout << "Jumlah Barang : " << data[i].jumlahBarang << endl;
        cout << "-----------------------------" << endl;
    }

    int index;
    cout << "Masukan index data yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > data.size()) {
        cout << BOLD << NEON_RED << "\nIndeks tidak valid! Penghapusan data gagal." << RESET << endl;
        return;
    }

    data.erase(data.begin() + index - 1);
    cout << BOLD << NEON_GREEN << "\nData berhasil dihapus!" << RESET << endl;
}

void searchByKodeBarang(const std::vector<barang>& data, const std::string& kode) {
    for (const auto& item : data) {
        if (item.kodeBarang == kode) {
            std::cout << "Kode Barang: " << item.kodeBarang << std::endl;
            std::cout << "Nama Barang: " << item.namaBarang << std::endl;
            std::cout << "Jenis Barang: " << item.kategoriBarang << std::endl;
            std::cout << "Harga Barang: Rp. " << item.hargaBarang << std::endl;
            std::cout << "Jumlah Barang: " << item.jumlahBarang << std::endl;
            return; // Exit after finding the item
        }
    }
    std::cout << "Item dengan Kode " << kode << " tidak ditemukan." << std::endl;
}

void searchByNamaBarang(const std::vector<barang>& data, const std::string& nama) {
    for (const auto& item : data) {
        if (item.namaBarang == nama) {
            std::cout << "Kode Barang: " << item.kodeBarang << std::endl;
            std::cout << "Nama Barang: " << item.namaBarang << std::endl;
            std::cout << "Jenis Barang: " << item.kategoriBarang << std::endl;
            std::cout << "Harga Barang: Rp. " << item.hargaBarang << std::endl;
            std::cout << "Jumlah Barang: " << item.jumlahBarang << std::endl;
            return; // Exit after finding the item
        }
    }
    std::cout << "Item dengan Nama " << nama << " tidak ditemukan." << std::endl;
}

void searchByKategoriBarang(const std::vector<barang>& data, const std::string& kategori) {
    for (const auto& item : data) {
        if (item.kategoriBarang == kategori) {
            std::cout << "Kode Barang: " << item.kodeBarang << std::endl;
            std::cout << "Nama Barang: " << item.namaBarang << std::endl;
            std::cout << "Jenis Barang: " << item.kategoriBarang << std::endl;
            std::cout << "Harga Barang: Rp. " << item.hargaBarang << std::endl;
            std::cout << "Jumlah Barang: " << item.jumlahBarang << std::endl;
            return; // Exit after finding the item
        }
    }
    std::cout << "Item with Kategori Barang " << kategori << " not found." << std::endl;
}

int main() {
    vector<barang> data;
    string username, password;
    const string adminUsername = "Januari'sppl";
    const string adminPassword = "J4nu4r1";
    int pilihMenu;
    string inputNama;

    cout << BOLD << "======[" << LIGHT_BROWN << "Selamat datang di toko serba ada Januari" << RESET << BOLD << "]=====" << RESET << endl;
    cout << "1. Admin" << endl;
    cout << "2. Pelanggan" << endl;
    cout << "Silahkan pilih menu : ";
    cin >> pilihMenu;

    if (pilihMenu == 1){
        cout << endl;
        cout << BOLD << "=====[ " << LIGHT_BROWN << "Login" << RESET << BOLD << " ]=====" << RESET << endl;
        cout << "Username : ";
        getline(cin, username);
        cin.ignore();
        cout << "Password : ";
        getline(cin, password);
        cin.ignore();

        if (username == adminUsername && password == adminPassword) {
            cout << BOLD << NEON_GREEN "\nLogin berhasil!" << RESET << endl;
            int choice;
            while (true) {
                cout << endl;
                menuKaryawan();
                cout << "Pilihan: " << RESET;
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1:
                        tambahBarang(data);
                        break;
                    case 2:
                        displayBarang(data);
                        break;
                    case 3:
                        updateBarang(data);
                        break;
                    case 4:
                        deleteData(data);
                        break;
                    case 5:
                        cout << "Terima kasih!" << endl;
                        return 0;
                    default:
                        cout << BOLD << NEON_RED << "Pilihan tidak valid!" << RESET << endl;
                }
            }
        } else {
            cout << BOLD << NEON_RED << "\nLogin gagal! Username atau password salah." << RESET << endl << endl;
            return 0;
        }
    }else if(pilihMenu == 2){
        while (true) {
            int menu;
            string nama, kode, kategori;
            int choice;
            cout << endl;
            menuPelanggan();
            cout << "Pilihan: " << RESET;
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    displayBarang(data);
                    break;
                case 2:
                    
                    cout << "Silahkan pilih menu dibawah ini : " << endl;
                    cout << "1. Cari dengan nama" << endl;
                    cout << "2. Cari dengan kode" << endl;
                    cout << "3. Cari dengan kategori" << endl;
                    cout << "4. Keluar" << endl;
                    cout << "Pilihan anda : ";
                    cin >> menu;
                    cin.ignore();

                    if (menu == 1){
                        std::cout << "Masukan nama barang : ";
                        std::getline(std::cin, nama);
                        searchByNamaBarang(data, nama);
                        break;
                    }else if (menu == 2) {
                        std::cout << "Masukan kode barang : ";
                        std::getline(std::cin, kode);
                        searchByKodeBarang(data, kode);
                        break;
                    }else if (menu == 3) 
                    {
                        std::cout << "Masukan kategori barang : ";
                        std::getline(std::cin, kategori);
                        searchByKategoriBarang(data, kategori);
                        break;
                    }else if (menu == 4){
                        cout << "Terima kasih!" << endl;
                        return 0;
                    }else{
                        cout << "Input tidak valid" << endl;
                        break;
                    } 
                case 3:
                    cout << "Terima kasih!" << endl;
                    return 0;
                default:
                    cout << BOLD << NEON_RED << "Pilihan tidak valid!" << RESET << endl;
                    break;
            }
            break;
        }
    } 


    return 0;
}