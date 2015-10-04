#include <memory.h>
#include <stdio.h>
#define BYTESIZE 8
void SetBit(char *p, int posi)
{
	for (int i = 0; i < (posi/BYTESIZE); i++)
	{
		p++;
	}
	*p = *p | (0x01<<(posi%BYTESIZE));
	return;
}
void BitMapSortDemo()
{
	int num[] = {3, 5, 2, 10, 6, 12, 8, 14, 9};
	const int BufferLen = 2;
	char *pBuffer = new char[BufferLen];
	memset(pBuffer, 0, BufferLen);
	for (int i = 0; i < 9; i++)
	{
		SetBit(pBuffer, num[i]);
	}
	for (int i = 0; i < BufferLen; i++)
	{
		for (int j = 0; j < BYTESIZE; j++)
		{
			if ((*pBuffer & (0x01<<j)) == (0x01<<j))
			{
				printf("%d ", i * BYTESIZE + j);
			}
		}
		pBuffer++;
	}
}
int main()
{
	BitMapSortDemo();
	return 0;
}
