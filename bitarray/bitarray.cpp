//Jonathan Hassel -- Section 6

#include "bitarray.h"

//----------------------------------------Friend Functions------------------------------------------\\

ostream& operator<<(ostream& out, const BitArray& a)
{
	out << "(";
	for(int i = 0; i < a.Length(); i++)
	{
		if(a.Query(i) == 1)
			out << "1";
		else
			out << "0";
	}
	out << ")";

	return out;
}

bool operator==(const BitArray& ba1, const BitArray& ba2)
{
	if(ba1.arraySize == ba2.arraySize)
	{
		for(int i = 0; i < ba1.arraySize; i++)
		{
			if(ba1.barray[i] != ba2.barray[i])
				return false;
		}
		return true;
	}

	return false;
}

bool operator!=(const BitArray& ba1, const BitArray& ba2)
{
	return !(ba1 == ba2);
}

//----------------------------------------Member Functions------------------------------------------\\

BitArray::BitArray(unsigned int n)
{
	arraySize = n / charBits;
	if(n % charBits != 0)
		arraySize++;

	barray = new unsigned char[arraySize];

	for(int i = 0; i < arraySize; i++)
		barray[i] = 0;
}

BitArray::BitArray(const BitArray& a)
{
	arraySize = a.arraySize;

	barray = new unsigned char[arraySize];

	for(int i = 0; i < arraySize; i++)
		barray[i] = a.barray[i];
}

BitArray::~BitArray()
{
	delete [] barray;
	barray = 0;
}

BitArray& BitArray::operator=(const BitArray& a)
{
	if(this != &a)
	{
		delete [] barray;

		arraySize = a.arraySize;

		barray = new unsigned char[arraySize];

		for(int i = 0; i < arraySize; i++)
			barray[i] = a.barray[i];
	}

	return *this;
}


unsigned int BitArray::Length() const
{
	return (arraySize * charBits);
}

void BitArray::Set(unsigned int index)
{
	switch(index % charBits)
	{
		case 7:
			barray[index / charBits] = barray[index / charBits] | 1;
			break;

		case 6:
			barray[index / charBits] = barray[index / charBits] | 2;
			break;

		case 5:
			barray[index / charBits] = barray[index / charBits] | 4;
			break;

		case 4:
			barray[index / charBits] = barray[index / charBits] | 8;
			break;

		case 3:
			barray[index / charBits] = barray[index / charBits] | 16;
			break;

		case 2:
			barray[index / charBits] = barray[index / charBits] | 32;
			break;

		case 1:
			barray[index / charBits] = barray[index / charBits] | 64;
			break;

		case 0:
			barray[index / charBits] = barray[index / charBits] | 128;
			break;
	}
}

void BitArray::Unset(unsigned int index)
{
	switch(index % charBits)
	{
		case 7:
			barray[index / charBits] = barray[index / charBits] & 254;
			break;

		case 6:
			barray[index / charBits] = barray[index / charBits] & 253;
			break;

		case 5:
			barray[index / charBits] = barray[index / charBits] & 251;
			break;

		case 4:
			barray[index / charBits] = barray[index / charBits] & 247;
			break;

		case 3:
			barray[index / charBits] = barray[index / charBits] & 239;
			break;

		case 2:
			barray[index / charBits] = barray[index / charBits] & 223;
			break;

		case 1:
			barray[index / charBits] = barray[index / charBits] & 191;
			break;

		case 0:
			barray[index / charBits] = barray[index / charBits] & 127;
			break;
	}
}

void BitArray::Flip(unsigned int index)
{
	switch(index % charBits)
	{
		case 7:
			barray[index / charBits] = barray[index / charBits] ^ 1;
			break;

		case 6:
			barray[index / charBits] = barray[index / charBits] ^ 2;
			break;

		case 5:
			barray[index / charBits] = barray[index / charBits] ^ 4;
			break;

		case 4:
			barray[index / charBits] = barray[index / charBits] ^ 8;
			break;

		case 3:
			barray[index / charBits] = barray[index / charBits] ^ 16;
			break;

		case 2:
			barray[index / charBits] = barray[index / charBits] ^ 32;
			break;

		case 1:
			barray[index / charBits] = barray[index / charBits] ^ 64;
			break;

		case 0:
			barray[index / charBits] = barray[index / charBits] ^ 128;
			break;
	}
}

bool BitArray::Query(unsigned int index) const
{
	switch(index % charBits)
	{
		case 7:
			if((barray[index / charBits] | 1) == barray[index / charBits])
				return true;
			else
				return false;

		case 6:
			if((barray[index / charBits] | 2) == barray[index / charBits])
				return true;
			else
				return false;

		case 5:
			if((barray[index / charBits] | 4) == barray[index / charBits])
				return true;
			else
				return false;

		case 4:
			if((barray[index / charBits] | 8) == barray[index / charBits])
				return true;
			else
				return false;

		case 3:
			if((barray[index / charBits] | 16) == barray[index / charBits])
				return true;
			else
				return false;

		case 2:
			if((barray[index / charBits] |32) == barray[index / charBits])
				return true;
			else
				return false;

		case 1:
			if((barray[index / charBits] | 64) == barray[index / charBits])
				return true;
			else
				return false;

		case 0:
			if((barray[index / charBits] | 128) == barray[index / charBits])
				return true;
			else
				return false;
	}


//	x:  0110 10b0
//	y:  0000 0000
//-----------------------
//(x | y):  0110 10b0
}
