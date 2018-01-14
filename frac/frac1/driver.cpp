#include "frac.h"
using namespace std;

int main()
{
	Fraction f1(1,2), f2(2,3), f3(1,8), f4(0,89);

	cout << f1 << " + " << f2 << " = " << f1 + f2 << '\n';
	cout << f1 << " * " << "3" << " = " << f1 * 3 << '\n';
	f4.Simplify();
	cout << f4 << '\n';
	cout << f1 * f2 << '\n' << f2 * f2 << '\n' << f2 * f3 << '\n';
	return 0;
}
