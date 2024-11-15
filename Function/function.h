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
  waktu = 1; // debug only
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
  return 0;
}

void createDoubleLinkedList(string nama, string tier) // membuat node awal
{
  head = new karakter();
  head->nama = nama;
  head->tier = tier;
  head->id = ++jumlahId;
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

void addLast(string nama, string tier)
{ // menambahkan node baru ke akhir
  newNode = new karakter();
  newNode->nama = nama;
  newNode->tier = tier;
  newNode->id = ++jumlahId;
  newNode->prev = tail;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
  // nomorId++;
}

void addFirst(string nama, string tier)
{ // menambahkan node baru ke awal
  newNode = new karakter();
  newNode->nama = nama;
  newNode->tier = tier;
  newNode->id = ++jumlahId;
  newNode->prev = NULL;
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void printDoubleLinkedList()
{ // menampilkan semua node
  cur = head;
  int nomor = 1;
  bool pertamaKali = true;
  string tier;
  while (cur != NULL)
  {
    if (pertamaKali || cur->tier != tier)
    {
      cout << "====================" << endl;
      cout << "Tier  : " << cur->tier << endl;
      cout << "====================" << endl;
      cout << "Nama  : " << cur->nama << endl;
      cout << "ID    : " << cur->id << endl;
      cout << "Nomor : " << nomor << endl;
      cout << endl;
      tier = cur->tier;
      pertamaKali = false;
    }
    else
    {
      cout << "Nama  : " << cur->nama << endl;
      cout << "ID    : " << cur->id << endl;
      cout << "Nomor : " << nomor << endl;
      cout << endl;
    }
    nomor++;
    cur = cur->next;
  }
}

// void printDoubleLinkedList()
// { // menampilkan semua node
//   cur = head;
//   int nomor = 1;
//   while (cur != NULL)
//   {
//     cout << "Nama  : " << cur->nama << endl;
//     cout << "Tier  : " << cur->tier << endl;
//     cout << "ID    : " << cur->id << endl;
//     cout << "Nomor : " << nomor << endl;
//     cout << "====================" << endl;
//     nomor++;
//     cur = cur->next;
//   }
// }

void printDoubleLinkedListAccount()
{ // menampilkan semua node
  curAkun = headAkun;
  int nomor = 1;
  while (curAkun != NULL)
  {
    cout << "Nama  : " << curAkun->username << endl;
    cout << "Tier  : " << curAkun->password << endl;
    cout << "ID    : " << curAkun->uid << endl;
    cout << "Nomor : " << nomor << endl;
    cout << "====================" << endl;
    nomor++;
    curAkun = curAkun->nextAkun;
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
    newNode->id = ++jumlahId;

    // tranversing
    cur = head;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
      cur = cur->next;
      nomor++;
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
    createDoubleLinkedList("Jean", "A");
    addLast("Kinich", "A");
    addLast("Lyney", "A");
    addLast("Mona", "A");
    addLast("Mualani", "A");
    addLast("Navia", "A");
    addLast("Shenhe", "A");
    addLast("Tighnari", "A");
    addLast("Xianyun", "A");
    addLast("Faruzan", "A");
    addLast("Albedo", "B");
    addLast("Ayaka", "B");
    addLast("Chiori", "B");
    addLast("Emilie", "B");
    addLast("Ganyu", "B");
    addLast("Sigewinne", "B");
    addLast("Venti", "B");
    addLast("Xiao", "B");
    addLast("Beidou", "B");
    addLast("Charlotte", "B");
    addLast("Ayato", "C");
    addLast("Cyno", "C");
    addLast("Dehya", "C");
    addLast("Diluc", "C");
    addLast("Eula", "C");
    addLast("Itto", "C");
    addLast("Keqing", "C");
    addLast("Klee", "C");
    addLast("Wanderer", "C");
    addLast("Yoimiya", "C");
    addLast("Kachina", "D");
    addLast("Kaeya", "D");
    addLast("Kaveh", "D");
    addLast("Kirara", "D");
    addLast("Layla", "D");
    addLast("Lisa", "D");
    addLast("Lynette", "D");
    addLast("Mika", "D");
    addLast("Sayu", "D");
    addLast("Sethos", "D");
    addLast("Amber", "E");
    addLast("Barbara", "E");
    addLast("Diona", "E");
    addLast("Chongyun", "E");
    addLast("Razor", "E");
    addLast("Yanfei", "E");
    addLast("Thoma", "E");
    addLast("Candace", "E");
    addLast("Noelle", "E");
    addLast("Sucrose", "E");
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
        loading(3, "Selamat datang, " + curAkun->username);
        return curAkun->role;
      }
      else if (curAkun->role == "user")
      {
        loading(3, "Selamat datang, " + curAkun->username);
        return curAkun->role;
      }
    }
    curAkun = curAkun->nextAkun;
  }

  loading(3, "Username atau password salah atau akun anda belum di konfirmasi admin.....");
  return "gagal";
}

void createFirstAccount() // membuat node awal
{
  headAkun = new akun();
  headAkun->username = "admin";
  headAkun->password = "admin";
  headAkun->role = "admin";
  headAkun->uid = 1;
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
  newNodeAkun->uid = ++jumlahUID;
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

// Fungsi Sorting

#include <string>

void swap(karakter *a, karakter *b)
{
  string tempNama = a->nama;
  string tempTier = a->tier;
  a->nama = b->nama;
  a->tier = b->tier;
  b->nama = tempNama;
  b->tier = tempTier;
}

// QuickSort berdasarkan nama
karakter *partition(karakter *low, karakter *high)
{
  string pivot = high->nama;
  karakter *i = low->prev;

  for (karakter *j = low; j != high; j = j->next)
  {
    if (j->nama < pivot)
    {
      i = (i == nullptr) ? low : i->next;
      swap(i, j);
    }
  }
  i = (i == nullptr) ? low : i->next;
  swap(i, high);
  return i;
}

void quickSort(karakter *low, karakter *high)
{
  if (high != nullptr && low != high && low != high->next)
  {
    karakter *pivot = partition(low, high);
    quickSort(low, pivot->prev);
    quickSort(pivot->next, high);
  }
}

void sortByName()
{
  if (head != nullptr)
  {
    quickSort(head, tail);
  }
}

// MergeSort berdasarkan tier
karakter *merge(karakter *left, karakter *right)
{
  if (!left)
    return right;
  if (!right)
    return left;

  if (left->tier <= right->tier)
  {
    left->next = merge(left->next, right);
    left->next->prev = left;
    left->prev = nullptr;
    return left;
  }
  else
  {
    right->next = merge(left, right->next);
    right->next->prev = right;
    right->prev = nullptr;
    return right;
  }
}

karakter *split(karakter *head)
{
  karakter *fast = head;
  karakter *slow = head;

  while (fast->next != nullptr && fast->next->next != nullptr)
  {
    fast = fast->next->next;
    slow = slow->next;
  }
  karakter *temp = slow->next;
  slow->next = nullptr;
  return temp;
}

karakter *mergeSort(karakter *node)
{
  if (!node || !node->next)
    return node;

  karakter *second = split(node);

  node = mergeSort(node);
  second = mergeSort(second);

  return merge(node, second);
}

void sortByTier()
{
  if (head != nullptr)
  {
    head = mergeSort(head);

    // Update tail after merge sort
    tail = head;
    while (tail->next != nullptr)
    {
      tail = tail->next;
    }
  }
}

// registrasi

void addAkun(string username, string password, string role)
{
  newNodeAkun = new akun();
  newNodeAkun->username = username;
  newNodeAkun->password = password;
  newNodeAkun->role = role;
  newNodeAkun->uid = ++jumlahUID; // Generate unique ID
  newNodeAkun->nextAkun = nullptr;
  newNodeAkun->prevAkun = nullptr;

  if (headAkun == nullptr)
  {
    // Jika list kosong, jadikan node baru sebagai head dan tail
    headAkun = tailAkun = newNodeAkun;
  }
  else
  {
    // Tambahkan node baru di akhir list
    tailAkun->nextAkun = newNodeAkun;
    newNodeAkun->prevAkun = tailAkun;
    tailAkun = newNodeAkun;
  }
  cout << "Akun dengan username '" << username << "' berhasil didaftarkan." << endl;
}

void removeAkun(int uid)
{
  curAkun = headAkun;

  // Cari akun dengan uid yang sesuai
  while (curAkun != nullptr)
  {
    if (curAkun->uid == uid)
    {
      // Jika akun berada di head
      if (curAkun == headAkun)
      {
        headAkun = headAkun->nextAkun;
        if (headAkun != nullptr)
        {
          headAkun->prevAkun = nullptr;
        }
        else
        {
          tailAkun = nullptr;
        }
      }
      // Jika akun berada di tail
      else if (curAkun == tailAkun)
      {
        tailAkun = tailAkun->prevAkun;
        tailAkun->nextAkun = nullptr;
      }
      // Jika akun berada di tengah
      else
      {
        curAkun->prevAkun->nextAkun = curAkun->nextAkun;
        curAkun->nextAkun->prevAkun = curAkun->prevAkun;
      }

      delete curAkun;
      cout << "Akun dengan UID " << uid << " berhasil dihapus." << endl;
      return;
    }
    curAkun = curAkun->nextAkun;
  }

  cout << "Akun dengan UID " << uid << " tidak ditemukan." << endl;
}

void menuUtama();

void registerUser()
{
  clear();
  cout << "Registrasi Akun Baru" << endl;
  cout << "Username: ";
  string newUsername, newPassword;
  cin >> newUsername;
  cout << "Password: ";
  cin >> newPassword;

  // Add new account with "pending" role
  addAkun(newUsername, newPassword, "pending"); // Function that adds to the linked list
  cout << "Registrasi berhasil. Menunggu konfirmasi dari admin." << endl;
  lanjut();
  menuUtama();
}

void confirmRegistrations()
{
  curAkun = headAkun;
  bool hasPending = false;
  int choice;

  while (curAkun != nullptr)
  {
    if (curAkun->role == "pending")
    {
      hasPending = true;
      cout << "UID: " << curAkun->uid;
      cout << " | Username: " << curAkun->username << endl;
      cout << "1. Konfirmasi\n2. Tolak\nPilihan: ";
      cin >> choice;

      if (choice == 1)
      {
        curAkun->role = "user";
        cout << "Akun " << curAkun->username << " dikonfirmasi." << endl;
      }
      else if (choice == 2)
      {
        removeAkun(curAkun->uid); // Function to remove account by UID
        cout << "Akun " << curAkun->username << " ditolak." << endl;
      }
      lanjut();
    }
    curAkun = curAkun->nextAkun;
  }

  if (!hasPending)
  {
    cout << "Tidak ada akun yang menunggu konfirmasi." << endl;
  }
}

// search
// Fathir
#include <string>

// Metode Fibonacci Search
karakter *fibonacciSearch(string target)
{
  if (head == nullptr)
  {
    cout << "Linked list kosong!" << endl;
    return nullptr;
  }

  int jumlah = countDoubleLinkedList();

  int fibMMm2 = 0;
  int fibMMm1 = 1;
  int fibM = fibMMm2 + fibMMm1;

  while (fibM < jumlah)
  {
    fibMMm2 = fibMMm1;
    fibMMm1 = fibM;
    fibM = fibMMm2 + fibMMm1;
  }

  karakter *cur = head;
  int offset = -1;

  while (fibM > 1)
  {
    int i = min(offset + fibMMm2, jumlah - 1);

    karakter *temp = cur;
    for (int j = 0; j < i - offset; j++)
    {
      if (temp == nullptr)
        break;
      temp = temp->next;
    }

    if (temp == nullptr)
      break;

    if (temp->nama < target)
    {
      fibM = fibMMm1;
      fibMMm1 = fibMMm2;
      fibMMm2 = fibM - fibMMm1;
      offset = i;
      cur = temp;
    }
    else if (temp->nama > target)
    {
      fibM = fibMMm2;
      fibMMm1 -= fibMMm2;
      fibMMm2 = fibM - fibMMm1;
    }
    else
    {
      return temp;
    }
  }

  if (fibMMm1 && cur->nama == target)
  {
    return cur;
  }

  cout << "Nama " << target << " tidak ditemukan!" << endl;
  return nullptr;
}

void cariNama(string nama)
{
  karakter *hasil = fibonacciSearch(nama);
  if (hasil != nullptr)
  {
    cout << "Data ditemukan:" << endl;
    cout << "Nama: " << hasil->nama << endl;
    cout << "Tier: " << hasil->tier << endl;
    cout << "ID  : " << hasil->id << endl;
  }
}

// jump search
#include <cmath>
#include <string>

karakter *jumpSearch(string target)
{
  if (head == nullptr)
  {
    cout << "Linked list kosong!" << endl;
    return nullptr;
  }

  int jumlah = countDoubleLinkedList();
  int step = sqrt(jumlah);
  karakter *cur = head;
  karakter *prev = nullptr;
  int index = 0;

  while (cur->next != nullptr && cur->nama < target)
  {
    prev = cur;
    for (int i = 0; i < step && cur->next != nullptr; i++)
    {
      cur = cur->next;
      index++;
    }
  }

  while (prev != nullptr && prev->nama <= target)
  {
    if (prev->nama == target)
    {
      return prev;
    }
    prev = prev->next;
  }

  cout << "Nama " << target << " tidak ditemukan!" << endl;
  return nullptr;
}

void cariNamaJump(string nama)
{
  karakter *hasil = jumpSearch(nama);
  if (hasil != nullptr)
  {
    cout << "Data ditemukan:" << endl;
    cout << "Nama: " << hasil->nama << endl;
    cout << "Tier: " << hasil->tier << endl;
    cout << "ID  : " << hasil->id << endl;
  }
}
// boyer-moore search
#include <vector>

vector<int> buildLastOccurrenceTable(const string &pattern)
{
  const int ALPHABET_SIZE = 256;
  vector<int> lastOccurrence(ALPHABET_SIZE, -1);
  int besar_pola = pattern.size();

  for (int i = 0; i < besar_pola; i++)
  {
    lastOccurrence[(int)pattern[i]] = i;
  }
  return lastOccurrence;
}

karakter *boyerMooreSearch(const string &pattern)
{
  if (head == nullptr)
  {
    cout << "Linked list kosong!" << endl;
    return nullptr;
  }

  vector<int> lastOccurrence = buildLastOccurrenceTable(pattern);
  karakter *cur = head;

  while (cur != nullptr)
  {
    string text = cur->nama;
    int m = pattern.size();
    int n = text.size();
    int s = 0;

    while (s <= (n - m))
    {
      int j = m - 1;

      while (j >= 0 && pattern[j] == text[s + j])
      {
        j--;
      }

      if (j < 0)
      {
        return cur;
      }
      else
      {
        s += max(1, j - lastOccurrence[(int)text[s + j]]);
      }
    }
    cur = cur->next;
  }

  cout << "Nama dengan substring '" << pattern << "' tidak ditemukan!" << endl;
  return nullptr;
}

void cariNamaBoyerMoore(string nama)
{
  karakter *hasil = boyerMooreSearch(nama);
  if (hasil != nullptr)
  {
    cout << "Data ditemukan:" << endl;
    cout << "Nama: " << hasil->nama << endl;
    cout << "Tier: " << hasil->tier << endl;
    cout << "ID  : " << hasil->id << endl;
  }
}

#endif