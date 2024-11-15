#ifndef data_H
#define data_H
#include <iostream>
using namespace std;

struct akun
{
  string username, password, role;
  int uid;
  akun *prevAkun;
  akun *nextAkun;
};
akun *headAkun, *tailAkun, *curAkun, *newNodeAkun, *delAkun, *afterNodeAkun;
// variabel akun
int jumlahUID = 0;
int jumlahCobaLogin = 0;
bool mulaiAkun = false;

struct karakter
{
  string nama, tier;
  int id;
  karakter *prev;
  karakter *next;
};

int jumlahId = 0;

karakter *head, *tail, *cur, *newNode, *del, *afterNode;

string loginUsername, loginPassword;

// variabel global
bool mulai = false;
int nomorId = 0;
char menu;
string posisi2, nama, tier;
int posisi;
int hasil_Int;

#endif // data_H