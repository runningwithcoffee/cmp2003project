#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

struct Node
{
    string code;
    string desc;
    int quantity;
    Node* next;
};


class ItemList
{
public:
    Node* first;
    Node* last;

   ItemList();
   void read();
   void top10();

};
