#include "bit.h"


int bit_egaux(bit b,bit c)
{
	return bit_en_int(b)==bit_en_int(c);
}

int bit_en_int (bit b)
{
	int res;
	if (b==b0) 
	{
		res=0;
	}
	if (b==b1)
	{
		res=1;
	}
	return res;
}

bit int_en_bit (int i)
{
assert((i==0) || (i==1));
	bit res;
	if (i) 
	{
		res=b1;
	}
	else 
	{
		res=b0;
	}
	return res;
}

bit copierBit(bit b)
	{
		bit bTemp=*(bit*)BAD_copierBit(&b);
		return bTemp;
	}
