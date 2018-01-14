//Jonathan Hassel -- Section 6

#include "flist.h"

ostream& operator<<(ostream& out, const FList& f)
{
	if(f.currentSize == 0)
		out << "FList is empty";
	else
	{
		for(int i = 0; i < f.currentSize; i++)
		{
			out << f.fracList[i];
			if(i < f.currentSize - 1)
			{
				out << ", ";
			}
		}
	}
	out << '\n';

	return out;
}


FList::FList()
{
	currentSize = 0;
}


//---------------------------------------------ACCESSORS---------------------------------------\\


int FList::Size() const
{
	return currentSize;
}

Fraction FList::Sum() const
{
	Fraction sum(0,1);
	for(int i = 0; i < currentSize; i++)
		sum = sum + fracList[i];

	return sum;
}

double FList::Average() const
{
	double average;
	Fraction r;

	r = (*this).Sum();

	average = ((static_cast<double>(r.GetNumerator())) / ((r.GetDenominator()) * currentSize));

	return average;
}

Fraction FList::Product(int position1, int position2) const
{
	Fraction product(1,1);
	for(int i = position1 - 1; i <= position2 - 1; i++)
		product = product * fracList[i];

	return product;
}

Fraction FList::Largest() const
{
	Fraction largest = fracList[0];

	for(int i = 0; i < currentSize; i++)
	{
		if(fracList[i] > largest)
		largest = fracList[i];
	}

	return largest;
}

int FList::HowMany(Fraction f1) const
{
	int howMany = 0;
	for(int i = 0; i < currentSize; i++)
	{
		if(fracList[i] == f1)
			howMany++;
	}

	return howMany;
}


//---------------------------------------------MUTATORS---------------------------------------\\


bool FList::Insert(Fraction f)
{
	if(currentSize < MAX)
	{
		currentSize++;
		fracList[currentSize - 1] = f;

		return true;
	}

	return false;
}

bool FList::Insert(Fraction f, int position)
{
	if(currentSize < MAX && position > 0 && position <= currentSize)
	{
		currentSize++;
		for(int i = 0; i <= currentSize - position; i++)
		{
			fracList[currentSize - i - 1] = fracList[currentSize - i - 2];
		}
		fracList[position - 1] = f;
		return true;
	}

	cout << "*** Invalid list position" << '\n';
	return false;
}

bool FList::Delete(int position)
{
	if(position > 0 && position <= currentSize)
	{
		for(int i = position - 1; i < currentSize; i++)
		{
			fracList[i] = fracList[i + 1];
		}
		currentSize--;
		return true;
	}

	cout << "*** Invalid list position" << '\n';
	return false;
}

void FList::SimplifyAll()
{
	for(int i = 0; i <= currentSize; i++)
		fracList[i].Simplify();
}

void FList::Clear()
{
	currentSize = 0;
}
