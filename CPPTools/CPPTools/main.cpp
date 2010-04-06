#include <iostream>
#include <cstring>
#include "CPPTools.h"
using namespace std;

int main()
{
	char A[] = "1234";
	char B[] = "12345";
	char *e = NULL;
	int c = 10;
	MemReverse((char *)&c,4);
	MemReverse((char *)&c,4);
	MemReverse(e,e+3);
	cout<<A<<endl<<B<<endl<<c<<endl;
	return 0;
}