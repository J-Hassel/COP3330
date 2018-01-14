#include "bitarray.h"

int main()
{
	BitArray x(37), y(41);

	cout << "x(" << x.Length() << ")"  << '\n';
	cout << "y(" << y.Length() << ")"  << '\n';

	if(x == y)
		cout << "true" << '\n';
	else
		cout << "false" << '\n';


	cout << y << '\n';

	for(int i = 0; i < y.Length(); i++)
		y.Set(i);

	cout << y << '\n';

	y.Unset(15);
	cout << y << '\n';

	y.Flip(1);
	cout << y << '\n';

	y.Flip(1);
	cout << y << '\n';

	y.Flip(3);
	cout << y << '\n';

	cout << y.Query(5) << '\n';

	cout << y.Query(3) << '\n';

	y.Flip(3);
	cout << y.Query(3) << '\n' << '\n';;

	cout << y.Query(14) << '\n';
	cout << y.Query(15) << '\n';
	cout << y.Query(16) << '\n';
	cout << y.Query(17) << '\n';
	cout << y.Query(18) << '\n';



	for(int i = 0; i < y.Length(); i++)
		y.Set(i);

	for(int i = 0; i < x.Length(); i++)
		x.Set(i);

	if(x == y)
		cout << "x == y" << '\n';
	else
		cout << "x !=y" << '\n';


	return 0;
}
