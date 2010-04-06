#pragma once

inline unsigned __int64 GetCycleCount()
{
	__asm RDTSC
}

bool MemReverse(char *pBegin,char *pEnd)
{
	if(!pBegin || !pEnd || pBegin > pEnd) return false;
	while(pBegin < pEnd)
	{
		*pBegin ^= *pEnd ^= *pBegin ^= *pEnd;
		pBegin++;pEnd--;
	}
	return true;
}

bool MemReverse(char *pBegin,unsigned int size)
{
	if(!pBegin) return false;
	char *pEnd = pBegin + size - 1;
	while(pBegin < pEnd)
	{
		*pBegin ^= *pEnd ^= *pBegin ^= *pEnd;
		pBegin++;pEnd--;
	}
	return  true;
}