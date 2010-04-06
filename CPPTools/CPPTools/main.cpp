#include <iostream>
#include <cstring>
#include "CPPTools.h"
using namespace std;

int main()
{
	char A[] = "1234";
	char B[] = "12345";
	unsigned char *e = NULL;
	int c = -10;
	MemReverse((unsigned char *)&c,4);
	MemReverse((unsigned char *)&c,4);
	MemReverse((unsigned char *)A,4);
	MemReverse((unsigned char *)A,(unsigned char *)A+3);
	MemReverse((unsigned char *)B,(unsigned char *)B+4);
	MemReverse((unsigned char *)B,5);
	MemReverse(e,e+3);
	MemReverse(e,99999);
	cout<<A<<endl<<B<<endl<<c<<endl;
	return 0;
}