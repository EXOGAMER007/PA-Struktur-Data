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

void subMenuSort()
{
  cout << "menu sort" << endl;
  cout << "1. Sort berdasarkan Tier" << endl;          // sort dengan urutan tier S, A, B, C, D
  cout << "2. Sort berdasarkan Nama karakter" << endl; // sort dengan urutan nama karakter ASC/DSC
}

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
    cin >> posisi;
    cout << "Masukkan nama item : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan tier item : ";
    getline(cin, tier);
    clear();
    hasil_Int = konversi(posisi);
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
    cin >> posisi;
    cout << "Masukkan nama item : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan tier item : ";
    getline(cin, tier);
    clear();
    hasil_Int = konversi(posisi);
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
    cin >> posisi;
    hasil_Int = konversi(posisi);
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
    loadingSalahInput(5);
    subMenuCRUD();
    break;
  }
}

void user()
{
  cout << "----------------------------------------" << endl;
  cout << "|             TIER KARAKTER            |" << endl;
  cout << "|             Genshin Impact           |" << endl;
  cout << "----------------------------------------" << endl;
  cout << "Menu : " << endl;
  cout << "1. Lihat tier" << endl;
  cout << "2. Lihat dan Sort karakter" << endl;
  cout << "3. Search karakter" << endl;
  cout << "4. Exit" << endl;
  cin >> menu;
  switch (menu)
  {
  case '1':
    cout << "menu tier" << endl;
    user();
    break;
  case '2':
    subMenuSort();
    user();
    break;
  case '3':
    cout << "menu search" << endl;
    user();
    break;
  case '4':
    cout << "exit" << endl;
    break;
  case '5':
    cout << "exit" << endl;
    exit(0);
    break;
  default:
    loadingSalahInput(5);
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
  cout << "5. Exit" << endl;
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
    subMenuSort();
    admin();
    break;
  case '3':
    cout << "menu search" << endl;
    admin();
    break;
  case '4':
    subMenuCRUD();
    clear();
    admin();
    break;
  case '5':
    cout << "exit" << endl;
    exit(0);
    break;
  default:
    loadingSalahInput(5);
    admin();
    break;
  }
}

int main()
{
  clear();
  membuatDataAwal();
  // user();
  admin();
  return 0;
}