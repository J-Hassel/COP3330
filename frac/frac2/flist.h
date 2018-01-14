//Jonathan Hassel -- Section 6

#include "frac.h"

class FList
{
	friend ostream& operator<<(ostream& out, const FList& f);

public:
	//constructor
	FList();

	//accessors
	int Size() const;
	Fraction Sum() const;
	double Average() const;
	Fraction Product(int postion1, int position2) const;
	Fraction Largest() const;
	int HowMany(Fraction f1) const;

	//mutators
	bool Insert(Fraction f);
	bool Insert(Fraction f, int position);
	bool Delete(int position);
	void SimplifyAll();
	void Clear();

private:
	static const int MAX = 20;
	int currentSize;
	Fraction fracList[MAX];
};
