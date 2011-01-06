#ifndef _KTRACE_
#define	_KTRACE_

#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

namespace KTRACE
{
	enum PIPES { READ, WRITE }; /* Constants 0 and 1 for READ and WRITE */
	class KTrace
	{
	private:
		int fdpipe[2];
		int bufsize;
		int pid;
		char hstr[20];
		char sstr[20];
		char displayTool[512];
		char *buf;
		bool successPipe;
		bool successTraceTools;
		
	public:
		KTrace(const char *_exe_path,const int _bufsize)
		{
			strcpy(displayTool,_exe_path);
			bufsize = _bufsize;
			successTraceTools = false;
			successPipe = (_pipe(fdpipe,bufsize,O_BINARY) != -1);
			if(successPipe)
			{
				itoa(fdpipe[READ],hstr,10);
				itoa(bufsize,sstr,10);
				buf = (char *)malloc(sizeof(char) * bufsize);
			}
			pid = 0;
		}
		
		void Run()
		{
			if(successPipe)
			{
				pid = _spawnl(P_NOWAIT,displayTool,displayTool,hstr,sstr,NULL);
				successTraceTools = (pid != -1);
			}
		}

		void Trace(const char *fmt, ...)
		{
			if(successPipe && successTraceTools)
			{
				va_list ap;
				va_start(ap,fmt);
				vsprintf(buf,fmt,ap);
				_write(fdpipe[WRITE],buf,bufsize);
				va_end(ap);
			}
		}

		~KTrace()
		{
			if(successPipe)
			{
				if(successTraceTools)
				{
					Trace("__EOF__");
				}
				_close( fdpipe[READ] );
				_close( fdpipe[WRITE] );
				free(buf);
			}
		}
	};
}


#endif