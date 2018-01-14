//Jonathan Hassel -- Section 6

#include <cmath>
#include "bitarray.h"

void Sieve(BitArray& a)
{
	int currentNum = 2;

	for(int i = 0; i < a.Length(); i++)
		a.Set(i);

	a.Unset(0);
	a.Unset(1);

	for(int i = 2; i < sqrt(a.Length()); i++)
	{
		if(a.Query(i))
		{
			for(int j = 2 * i; j < a.Length(); j += i)
			{
				a.Unset(j);
			}
		}
	}
}
