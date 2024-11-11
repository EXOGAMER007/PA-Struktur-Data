#ifndef data_H
#define data_H
#include <iostream>
using namespace std;

struct karakter
{
  string nama, tier;
  int id;
  karakter *prev;
  karakter *next;
};

karakter *head, *tail, *cur, *newNode, *del, *afterNode;

// variabel global
bool mulai = false;
char menu;
string posisi, nama, tier;
int hasil_Int;

#endif // data_H