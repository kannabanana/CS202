using namespace std;
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>


void fun1()
{
	int * storage;
	storage = fun(storage);
	cout << storage[0];
}


int * fun(int * storage)
{
	storage[0] = 6;
	return storage;
}
