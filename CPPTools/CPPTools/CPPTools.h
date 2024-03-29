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
void read_big_endien_value(std::istream &instream,Type &inValue)
{
	unsigned int len = sizeof(v);
	for(int i = len - 1;i >= 0;i--)
	{
		in.read(((char *)&v)+i,sizeof(char));
	}
}

template <class Type>
Type get_upbound(Type integer_value, Type segment)
{
    Type t = integer_value % segment;
    return t == 0 ? integer_value : integer_value - t + segment;
}

