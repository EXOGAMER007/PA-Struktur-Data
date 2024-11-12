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
int jumlahAkun;
int jumlahCobaLogin = 0;
bool mulaiAkun = false;

struct karakter
{
  string nama, tier;
  int id;
  karakter *prev;
  karakter *next;
};

string loginUsername, loginPassword;

karakter *head, *tail, *cur, *newNode, *del, *afterNode;
// variabel global
bool mulai = false;
char menu;
string posisi, nama, tier;
int hasil_Int;

#endif // data_H