#include <iostream>
#include <chrono>
#include <thread>
#include "data/data.h"
#include "Function/function.h"

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

void user();
void admin();

void submenusort()
{
  int pilihan;
  cout << "===== Menu Sorting =====" << endl;
  cout << "1. Sort by Name (QuickSort)" << endl;
  cout << "2. Sort by Tier (MergeSort)" << endl;
  cout << "Pilih metode sorting (1/2): ";
  cin >> pilihan;

  switch (pilihan)
  {
  case 1:
    sortByName();
    cout << "Data berhasil diurutkan berdasarkan Nama." << endl;
    break;
  case 2:
    sortByTier();
    cout << "Data berhasil diurutkan berdasarkan Tier." << endl;
    break;
  default:
    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    break;
  }
  lanjut(); // Menunggu input ENTER untuk melanjutkan
}

// void subMenuSort()
// {
//   cout << "menu sort" << endl;
//   cout << "1. Sort berdasarkan Tier" << endl;          // sort dengan urutan tier S, A, B, C, D
//   cout << "2. Sort berdasarkan Nama karakter" << endl; // sort dengan urutan nama karakter ASC/DSC
// }

void subMenuCRUD()
{
  clear();
  cout << "menu CRUD" << endl;
  cout << "1. Tambah karakter" << endl;
  cout << "2. Update karakter" << endl;
  cout << "3. Hapus karakter" << endl;
  cout << "4. kembali" << endl;
  cout << "Input : ";
  cin >> menu;
  switch (menu)
  {
  case '1':
    clear();
    cout << "menu tambah karakter" << endl;
    printDoubleLinkedList();
    cout << "Masukkan posisi yang ingin ditambahkan : ";
    cin >> posisi2;
    cout << "Masukkan nama karakter : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan tier karakter : ";
    getline(cin, tier);
    clear();
    hasil_Int = konversi(posisi2);
    addMiddle(nama, tier, hasil_Int);
    printDoubleLinkedList();
    lanjut();
    subMenuCRUD();
    break;
  case '2':
    clear();
    cout << "menu Update karakter" << endl;
    printDoubleLinkedList();
    cout << "Masukkan posisi yang ingin diganti : ";
    cin >> posisi2;
    cout << "Masukkan nama Karakter : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan tier Karakter : ";
    getline(cin, tier);
    clear();
    hasil_Int = konversi(posisi2);
    changeMiddle(nama, tier, hasil_Int);
    printDoubleLinkedList();
    lanjut();
    subMenuCRUD();
    break;
  case '3':
    clear();
    cout << "menu hapus karakter" << endl;
    printDoubleLinkedList();
    cout << "Masukkan posisi yang ingin dihapus : ";
    cin >> posisi2;
    hasil_Int = konversi(posisi2);
    removeMiddle(hasil_Int);
    clear();
    printDoubleLinkedList();
    lanjut();
    subMenuCRUD();
    break;
  case '4':
    clear();
    admin();
    return;
    break;
  default:
    loading(3, "inputan salah");
    subMenuCRUD();
    break;
  }
}

void SubMenuSearch()
{
  clear();
  int metode;
  string nama;

  cout << "----------------------------------------" << endl;
  cout << "|             SEARCH KARAKTER          |" << endl;
  cout << "|             Genshin Impact           |" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Pilih metode pencarian:\n";
  cout << "1. Fibonacci Search\n";
  cout << "2. Jump Search\n";
  cout << "3. Boyer-Moore Search\n";
  cout << "4. Kembali ke menu utama\n";
  cout << "Masukkan pilihan: ";
  cin >> metode;

  switch (metode)
  {
  case 1:
    clear();
    cout << "Masukkan nama karakter yang ingin dicari (Fibonacci Search): ";
    cin >> nama;
    cariNama(nama);
    break;
  case 2:
    clear();
    cout << "Masukkan nama karakter yang ingin dicari (Jump Search): ";
    cin >> nama;
    cariNamaJump(nama);
    break;
  case 3:
    clear();
    cout << "Masukkan substring nama karakter yang ingin dicari (Boyer-Moore Search): ";
    cin >> nama;
    cariNamaBoyerMoore(nama);
    break;
  case 4:
    clear();
    return;
  default:
    cout << "Pilihan tidak valid. Coba lagi.\n";
    lanjut();
    SubMenuSearch();
    break;
  }
  lanjut();
  SubMenuSearch();
}

void user()
{
  clear();
  cout << "----------------------------------------" << endl;
  cout << "|             TIER KARAKTER            |" << endl;
  cout << "|             Genshin Impact           |" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Menu : " << endl;
  cout << "1. Lihat tier" << endl;
  cout << "2. Lihat dan Sort karakter" << endl;
  cout << "3. Search karakter" << endl;
  cout << "4. kembali ke menu utama" << endl; // Opsi Registrasi
  cout << "5. Exit" << endl;
  cin >> menu;
  switch (menu)
  {
  case '1':
    clear();
    printDoubleLinkedList();
    lanjut();
    user();
    break;
  case '2':
    clear();
    submenusort();
    user();
    break;
  case '3':
    cout << "menu search" << endl;
    clear();
    SubMenuSearch();
    user();
    break;
  case '4':
    clear();
    menuUtama();
    user();
    break;
  case '5':
    cout << "exit" << endl;
    exit(0);
    break;
  default:
    loading(3, "inputan salah");
    user();
    break;
  }
}

void admin()
{
  clear();
  cout << "----------------------------------------" << endl;
  cout << "|             TIER KARAKTER            |" << endl;
  cout << "|             Genshin Impact    (admin)|" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Menu : " << endl;
  cout << "1. Lihat tier" << endl;
  cout << "2. Lihat dan Sort karakter" << endl;
  cout << "3. Search karakter" << endl;
  cout << "4. CRUD data karakter" << endl;
  cout << "5. Konfirmasi Registrasi" << endl; // New option
  cout << "6. kembali ke menu utama" << endl; // New option
  cout << "7. Exit" << endl;
  cin >> menu;
  switch (menu)
  {
  case '1':
    clear();
    printDoubleLinkedList();
    lanjut();
    admin();
    break;
  case '2':
    clear();
    submenusort();
    admin();
    break;
  case '3':
    cout << "menu search" << endl;
    clear();
    SubMenuSearch();
    admin();
    break;
  case '4':
    subMenuCRUD();
    clear();
    admin();
    break;
  case '5':
    confirmRegistrations();
    admin();
    break;
  case '6':
    menuUtama();
    break;
  case '7':
    cout << "exit" << endl;
    exit(0);
    break;
  default:
    loading(3, "inputan salah");
    admin();
    break;
  }
}

bool login()
{
  clear();
  cout << "Silahkan login atau ketik 1 untuk kembali" << endl;
  cout << "Username : ";
  cin >> loginUsername;
  if (loginUsername == "1")
  {
    clear();
    menuUtama();
  }
  cout << "Password : ";
  cin >> loginPassword;

  string statusLogin = prosesLogin(loginUsername, loginPassword);
  if (statusLogin == "admin")
  {
    admin();
  }
  else if (statusLogin == "user")
  {
    user();
  }
  else if (jumlahCobaLogin == 3)
  {
    clear();
    loading(3, "Anda sudah terlalu banyak salah");
    exit(0);
  }
  else
  {
    jumlahCobaLogin++;
    login();
  }
  return true;
}

// Fungsi untuk menampilkan menu registrasi atau login
void menuUtama()
{
  clear();
  cout << "----------------------------------------" << endl;
  cout << "|             TIER KARAKTER            |" << endl;
  cout << "|             Genshin Impact           |" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Menu Utama:" << endl;
  cout << "1. Login" << endl;
  cout << "2. Registrasi" << endl;
  cout << "3. Keluar" << endl;
  cout << "Pilih opsi (1/2/3): ";
  char pilihan;
  cin >> pilihan;

  switch (pilihan)
  {
  case '1':
    login();
    break;
  case '2':
    registerUser();
    break;
  case '3':
    cout << "Terima kasih! Keluar dari program." << endl;
    exit(0);
    break;
  default:
    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    menuUtama();
    break;
  }
}
int main()
{
  membuatDataAwal();
  membuatAkunAwal();
  loading(3, "Memuat data...");
  clear();
  menuUtama();
  return 0;
}
