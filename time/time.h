//Jonathan Hassel -- Section 6

#include <iostream>
using namespace std;

class Time
{
	friend ostream& operator<<(ostream& out, const Time& t);
	friend istream& operator>>(istream& in, Time& t);
	friend Time operator+(Time& t1, Time& t2);
	friend Time operator-(Time& t1, Time& t2);
	friend Time operator*(Time&, int multiplier);
	friend bool operator<(Time& t1, Time& t2);
	friend bool operator>(Time& t1, Time& t2);
	friend bool operator<=(Time& t1, Time& t2);
	friend bool operator>=(Time& t1, Time& t2);
	friend bool operator==(Time& t1, Time& t2);
	friend bool operator!=(Time& t1, Time& t2);

public:
	Time();
	Time(int s);
	Time(int d, int h, int m, int s);

 	Time operator++(int);
	Time& operator++();
	Time operator--(int);
	Time& operator--();


private:
	int days, hours, minutes, seconds;
	void ConvertToSeconds();
	void ConvertToDHMS();

};
