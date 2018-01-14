//Jonathan Hassel -- Section 6

#include <iostream>
#include "time.h"
using namespace std;

//default constructor
Time::Time()
{
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = 0;
}

//conversion constructor
Time::Time(int s)
{
	days = 0;
	hours = 0;
	minutes = 0;
	seconds = s;

	if(s > 59)
	{
		ConvertToDHMS();
	}
	else if(s < 0)
	{
		days = 0;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
}

//set d, h, m, s constructor
Time::Time(int d, int h, int m, int s)
{
	if( d < 0 || h < 0 || m < 0 || s < 0)
	{
		days = 0;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	else
	{
		days = d;
		hours = h;
		minutes = m;
		seconds = s;

		ConvertToSeconds();
		ConvertToDHMS();
	}
}

//converts DHMS to Seconds
void Time::ConvertToSeconds()
{
	seconds = ((seconds) + (minutes * 60) + (hours * 3600) + (days * 86400));

	minutes = 0;
	hours = 0;
	days = 0;
}

//converts Seconds to DHMS
void Time::ConvertToDHMS()
{
	if(seconds > 59)
	{
		minutes += seconds/60;
		seconds = static_cast<int>(((seconds/60.0 - seconds/60) * 60) + 0.5);

		if(minutes > 59)
		{
			hours += minutes/60;
			minutes = static_cast<int>(((minutes/60.0 - minutes/60) * 60) + 0.5);

			if(hours > 23)
			{
				days += hours/24;
				hours = static_cast<int>(((hours/24.0 - hours/24) * 24) + 0.5);
			}
		}
	}
	else
	{
		minutes = 0;
		hours = 0;
		days = 0;
	}
}

//can use << to cout objects
ostream& operator<<(ostream& out, const Time& t)
{
	//Prints days~
	if(t.days < 10)
		out << "0" << t.days << "~";
	else
		out << t.days << "~";

	//Prints hours:
	if(t.hours < 10)
		out << "0" << t.hours << ":";
	else
		out << t.hours << ":";

	//Prints minutes:
	if(t.minutes < 10)
		out << "0" << t.minutes << ":";
	else
		out << t.minutes << ":";

	//Prints seconds
	if(t.seconds < 10)
		out << "0" << t.seconds;
	else
		out << t.seconds;
}

//can use >> to input values to an object
istream& operator>>(istream& in, Time& t)
{
	int d, h, m, s;

	in >> d;
	in.get();
	in >> h;
	in.get();
	in >> m;
	in.get();
	in >> s;

	if( d < 0 || h < 0 || m < 0 || s < 0)
	{
		t.days = 0;
		t.hours = 0;
		t.minutes = 0;
		t.seconds = 0;
	}
	else
	{
		t.days = d;
		t.hours = h;
		t.minutes = m;
		t.seconds = s;

		t.ConvertToSeconds();
		t.ConvertToDHMS();
	}
}

//allows you to use + to add two objects
Time operator+(Time& t1, Time& t2)
{
	Time t3;

	t1.ConvertToSeconds();
	t2.ConvertToSeconds();

	t3.seconds = t1.seconds + t2.seconds;

	t1.ConvertToDHMS();
	t2.ConvertToDHMS();
	t3.ConvertToDHMS();

	return t3;
}

//allows you to use - to subtract two objects
Time operator-(Time& t1, Time& t2)
{
	Time t3;

	t1.ConvertToSeconds();
	t2.ConvertToSeconds();

	t3.seconds = t1.seconds - t2.seconds;

	t1.ConvertToDHMS();
	t2.ConvertToDHMS();

	if(t3.seconds < 0)
	{
		t3.days = 0;
		t3.hours = 0;
		t3.minutes = 0;
		t3.seconds = 0;
	}
	else
		t3.ConvertToDHMS();

	return t3;
}

//allows you to multiply an object by an integer
Time operator*(Time& t1, int multiplier)
{
	Time t2;

	t1.ConvertToSeconds();

	t2.seconds = t1.seconds * multiplier;
	t2.ConvertToDHMS();

	return t2;
}

//compares two objects, returns true if t1 < t2
bool operator<(Time& t1, Time& t2)
{
	t1.ConvertToSeconds();
	t2.ConvertToSeconds();

	if(t1.seconds < t2.seconds)
	{
		t1.ConvertToDHMS();
		t2.ConvertToDHMS();
		return true;
	}
	else
	{
		t1.ConvertToDHMS();
		t2.ConvertToDHMS();
		return false;
	}
}

//compares two objects, returns true if t1 > t2
bool operator>(Time& t1, Time& t2)
{
	return (t2 < t1);
}

//compares two objects, returns true if t1 <= t2
bool operator<=(Time& t1, Time& t2)
{
	return !(t1 > t2);
}

//compares two objects, returns true if t1 >= t2
bool operator>=(Time& t1, Time& t2)
{
	return !(t1 < t2);
}

//compares two objects, returns true if t1 == t2
bool operator==(Time& t1, Time& t2)
{
	return (t1 <= t2 && t1 >= t2);
}

//compares two objects, returns true if t1 != t2
bool operator!=(Time& t1, Time& t2)
{
	return !(t1 == t2);
}

//post increment
Time Time::operator++(int)
{
	Time temp = *this;

	ConvertToSeconds();
	seconds += 1;
	ConvertToDHMS();

	return temp;
}

//pre increment
Time& Time::operator++()
{
	ConvertToSeconds();
	seconds += 1;
	ConvertToDHMS();

	return *this;
}

//post decriment
Time Time::operator--(int)
{
	Time temp = *this;

	ConvertToSeconds();
	seconds -= 1;

	if(seconds < 0)
	{
		days = 0;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	else
		ConvertToDHMS();

	return temp;
}

//pre decriment
Time& Time::operator--()
{
	ConvertToSeconds();
	seconds -= 1;

	if(seconds < 0)
	{
		days = 0;
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	else
		ConvertToDHMS();

	return *this;
}

