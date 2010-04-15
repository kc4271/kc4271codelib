#include <iostream>
#include <cstring>
#include "CPPTools.h"
using namespace std;

int main()
{
	char A[] = "1234";
	char B[] = "12345\0";
	unsigned char *e = NULL;
	int c = -10; 
	memrevrs((unsigned char *)&c,4);
	memrevrs((unsigned char *)&c,4);
	memrevrs((unsigned char *)A,4);
	memrevrs((unsigned char *)A,(unsigned char *)A+3);
	memrevrs((unsigned char *)B,(unsigned char *)B+4);
	memrevrs((unsigned char *)B,strlen(B));
	memrevrs(e,e+3);
	memrevrs(e,99999);
	cout<<A<<endl<<B<<endl<<c<<endl;
	return 0;
}