#pragma once

inline unsigned __int64 GetCycleCount()
{
	__asm RDTSC
}

bool MemReverse(unsigned char *pBegin,unsigned char *pEnd)
{
	if(!pBegin || !pEnd || pBegin > pEnd) return false;
	while(pBegin < pEnd)
	{
		*pBegin ^= *pEnd ^= *pBegin ^= *pEnd;
		pBegin++;pEnd--;
	}
	return true;
}

bool MemReverse(unsigned char *pBegin,unsigned int size)
{
	if(!pBegin) return false;
	unsigned char *pEnd = pBegin + size - 1;
	while(pBegin < pEnd)
	{
		*pBegin ^= *pEnd ^= *pBegin ^= *pEnd;
		pBegin++;pEnd--;
	}
	return  true;
}