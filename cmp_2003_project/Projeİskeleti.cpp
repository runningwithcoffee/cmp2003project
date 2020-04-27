#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>


using namespace std;



int main()
{
	ItemList a;
	
	a.read();
	a.top10();
	return 0;
}
