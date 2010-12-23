#include "KTrace.h"

int main( int argc, char *argv[] )
{
	int pread;
	int bufsize;
	char *buf;
	printf("KTRACE BEGIN!\n");
	if(argc == 3)
	{
		pread = atoi(argv[1]);
		bufsize = atoi(argv[2]);
		buf = (char *)malloc(sizeof(char) * (bufsize + 1));
		while(true)
		{
			_read(pread,buf,bufsize);
			buf[bufsize] = 0;
			printf("%s",buf);
			if(strcmp(buf,"__EOF__") == 0)
				break;
		}
		free(buf);
	}
	printf("KTRACE END!\n");
	return 0;
}