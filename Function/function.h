#ifndef fungsi_h
#define fungsi_h

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

// FUNGSI UMUM
void clear()
{ // membersihkan terminal
  system("cls");
}

void lanjut() // memberi jeda
{
  string enter;
  cout << "tekan ENTER untuk lanjut\n";
  cin.clear();
  cin.ignore();
  getline(cin, enter);
  clear();
}

int konversi(string huruf) // konversi string ke int
{
  int angka = stoi(huruf);
  return angka;
}

void loading(int waktu, string pesan) // hitung mundur jika inputan salah
{
  clear();
  int detik = waktu;
  for (int i = 0; i <= waktu; i++)
  {
    cout << pesan << endl;
    cout << "Ke halaman berikut nya dalam " << detik << endl;
    detik--;
    sleep_for(seconds(1));
    clear();
  }
}

// FUNGSI DOUBLE LINKED LIST

int countDoubleLinkedList() // hitung jumlah node
{
  if (head == NULL)
  {
    cout << "Double Linked List belum dibuat!!!";
  }
  else
  {
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
      // print
      jumlah++;
      // step
      cur = cur->next;
    }
    return jumlah;
  }
}

void createDoubleLinkedList(string nama, string tier) // membuat node awal
{
  head = new karakter();
  head->nama = nama;
  head->tier = tier;
  head->id += 1;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

void addLast(string nama, string tier)
{ // menambahkan node baru ke akhir
  newNode = new karakter();
  newNode->nama = nama;
  newNode->tier = tier;
  newNode->id += 1;
  newNode->prev = tail;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void addFirst(string nama, string tier)
{ // menambahkan node baru ke awal
  newNode = new karakter();
  newNode->nama = nama;
  newNode->tier = tier;
  newNode->id += 1;
  newNode->prev = NULL;
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void printDoubleLinkedList()
{ // menampilkan semua node
  cur = head;
  int nomor = 1;
  while (cur != NULL)
  {
    cout << "Nama  : " << cur->nama << endl;
    cout << "Tier  : " << cur->tier << endl;
    cout << "ID    : " << cur->id << endl;
    cout << "Nomor : " << nomor << endl;
    cout << "====================" << endl;
    nomor++;
    cur = cur->next;
  }
}

void addMiddle(string nama, string tier, int posisi)
{ // menambahkan node baru ke tengah
  if (posisi == 1)
  {
    addFirst(nama, tier);
    return;
  }
  if (posisi == countDoubleLinkedList())
  {
    addLast(nama, tier);
    return;
  }
  if (posisi < 1 || posisi > countDoubleLinkedList())
  {
    cout << "Posisi diluar jangkauan2" << endl;
    return;
  }
  else
  {
    newNode = new karakter();
    newNode->nama = nama;
    newNode->tier = tier;
    newNode->id += 1;

    // tranversing
    cur = head;
    int nomor = 1;
    while (nomor > posisi - 1)
    {
      cur = cur->next;
      cur++;
    }
    afterNode = cur->next;
    newNode->prev = cur;
    newNode->next = afterNode;
    cur->next = newNode;
    afterNode->prev = newNode;
  }
}

void membuatDataAwal()
{ // membuat data awal
  if (mulai == false)
  {
    createDoubleLinkedList("HuTao", "S");
    addLast("Diluc", "A");
    addLast("Razor", "B");
    addLast("Qiqi", "C");
    mulai = true;
    return;
  }
  else
  {
    return;
  }
}

void removeFirst()
{ /// menghapus node awal
  del = head;
  head = head->next;
  head->prev = NULL;
  delete del;
}

void removeLast()
{ // menghapus node akhir
  del = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete del;
}

void removeMiddle(int posisi)
{ // menghapus node di tengah
  if (posisi == 1)
  {
    removeFirst();
    return;
  }
  if (posisi == countDoubleLinkedList())
  {
    removeLast();
    return;
  }
  if (posisi < 1 || posisi > countDoubleLinkedList())
  {
    cout << "Posisi diluar jangkauan2" << endl;
    return;
  }
  else
  {
    int nomor = 1;
    cur = head;
    while (nomor < posisi - 1)
    {
      cur = cur->next;
      nomor++;
    }
    del = cur->next;
    afterNode = del->next;
    cur->next = afterNode;
    afterNode->prev = cur;
    delete del;
  }
}

void changeFirst(string nama, string tier)
{ // mengubah node awal
  head->nama = nama;
  head->tier = tier;
}

void changeLast(string nama, string tier)
{ // mengubah node akhir
  tail->nama = nama;
  tail->tier = tier;
}

void changeMiddle(string nama, string tier, int posisi)
{ // mengubah node di tengah
  if (posisi == 1)
  {
    changeFirst(nama, tier);
    return;
  }
  if (posisi == countDoubleLinkedList())
  {
    changeLast(nama, tier);
    return;
  }
  if (posisi < 1 || posisi > countDoubleLinkedList())
  {
    cout << "Posisi diluar jangkauan2" << endl;
    return;
  }
  else
  {
    cur = head;
    int nomor = 1;
    while (nomor < posisi)
    {
      cur = cur->next;
      nomor++;
    }
    cur->nama = nama;
    cur->tier = tier;
  }
}

// FUNGSI LOGIN
string prosesLogin(string username, string password)
{
  curAkun = headAkun;
  while (curAkun != NULL)
  {
    if (username == curAkun->username && password == curAkun->password)
    {
      if (curAkun->role == "admin")
      {
        loading(5, "Selamat datang, " + curAkun->username);
        return curAkun->role;
      }
      else
      {
        loading(5, "Selamat datang, " + curAkun->username);
        return curAkun->role;
      }
    }
    curAkun = curAkun->nextAkun;
  }

  loading(5, "Username atau password salah");
  return "gagal";
}

void createFirstAccount() // membuat node awal
{
  headAkun = new akun();
  headAkun->username = "admin";
  headAkun->password = "admin";
  headAkun->role = "admin";
  headAkun->uid += 1;
  headAkun->prevAkun = NULL;
  headAkun->nextAkun = NULL;
  tailAkun = headAkun;
}

void addLastAccount(string username, string password)
{ // menambahkan node baru ke akhir
  newNodeAkun = new akun();
  newNodeAkun->username = username;
  newNodeAkun->password = password;
  newNodeAkun->role = "user";
  newNodeAkun->uid += 1;
  newNodeAkun->prevAkun = tailAkun;
  newNodeAkun->nextAkun = NULL;
  tailAkun->nextAkun = newNodeAkun;
  tailAkun = newNodeAkun;
}

void membuatAkunAwal()
{ // membuat data awal
  if (mulaiAkun == false)
  {
    createFirstAccount();
    addLastAccount("a", "a");
    addLastAccount("b", "b");
    mulaiAkun = true;
    return;
  }
  else
  {
    return;
  }
}

#endif // fungsi_h