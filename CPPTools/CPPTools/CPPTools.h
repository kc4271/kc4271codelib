#pragma once

inline unsigned __int64 GetCycleCount()
{
	__asm RDTSC
}

bool memrevrs(unsigned char *pBegin,unsigned char *pEnd)
{
	if(!pBegin || !pEnd || pBegin > pEnd) return false;
	while(pBegin < pEnd)
	{
		*pBegin ^= *pEnd ^= *pBegin ^= *pEnd;
		pBegin++;pEnd--;
	}
	return true;
}

bool memrevrs(unsigned char *pBegin,unsigned int size)
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

template <class Type>
void revrs(Type &inValue)
{
	memrevrs((unsigned char*)&inValue,sizeof(inValue));
}

template <class Type>
void read_big_endien_value(std::istream &in,Type &v)
{
	unsigned int len = sizeof(v);
	for(int i = len - 1;i >= 0;i--)
	{
		in.read(((char *)&v)+i,sizeof(char));
	}
}