#include <iostream>
#include "flist.h"
using namespace std;

int main()
{
/*	FList a;

	cout << a;
	Fraction f(1,20);
	a.Insert(f);
	a.Insert(f);
	a.Insert(f);
	cout << a << '\n';
	cout << a.Size() << '\n' << a.HowMany(f) << '\n' << a.Product(1, 3) << '\n' <<  a.Average() << '\n';
	a.Delete(1);
	cout << a << '\n' <<  a.Sum() << '\n';
*/
	 int start;
	 Fraction entry;
	 FList a;
	 cout << "Welcome!\n";
	 cout << a;
	 cout << "How many numbers to start with (1 - 20)? ";
	 cin >> start;
	 cout << "Please input the " << start << " starting fractions\n";
	 for (int i = 0; i < start; i++)
	 {
	 	cout << "Fraction #" << (i+1) << ":  ";
	 	entry.Input();
	      	a.Insert(entry);
	}
	cout << "\nHere's the list:\n" << a;

	return 0;
}
