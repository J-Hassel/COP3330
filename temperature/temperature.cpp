#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include "temperature.h"
using namespace std;

Temperature::Temperature()
{
	temperature = 0;
	scale = 'C';
	scaleL = "Celsius";
	format = 'D';
}

Temperature::Temperature(double deg, char sc)
{
	if(IsValid(deg, sc))
	{
		temperature = deg;
		scale = toupper(sc);
		scaleL = ScaleToString(sc);
		format = 'D';
	}
	else
	{
		temperature = 0;
		scale = 'C';
		scaleL = "Celsius";
		format = 'D';
	}
}

void Temperature::Show() const
{
	if(format == 'D')
		cout << temperature << " " << scale << '\n';
	else if(format == 'P')
	{
		int oldprecision = cout.precision();
		ios_base::fmtflags oldflags = cout.flags();

		cout << fixed << setprecision(1) << temperature << " " << scale << '\n';

		cout.precision(oldprecision);
		cout.flags(oldflags);
	}
	else if(format == 'L')
		cout << temperature << " " << scaleL << '\n';

}

double Temperature::GetDegrees() const
{
	return temperature;
}

char Temperature::GetScale() const
{
	return scale;
}

int Temperature::Compare(const Temperature& d) const
{
	if(ConvertToK(*this) < ConvertToK(d))
		return -1;
	else if(ConvertToK(*this) == ConvertToK(d))
		return 0;
	else if(ConvertToK(*this) > ConvertToK(d))
		return 1;
}

bool Temperature::IsValid(double deg, char sc) const
{
	switch(sc)
	{
		case 'c':
		case 'C':
			if(deg < -273.15)
				return false;
			else
				return true;
			break;

		case 'f':
		case 'F':
			if(deg < -459.67)
				return false;
			else
				return true;
			break;

		case 'k':
		case 'K':
			if(deg < 0)
				return false;
			else
				return true;
			break;
	}
}

string Temperature::ScaleToString(char sc) const
{
	if(sc == 'c' || sc == 'C')
		return "Celsius";
	else if(sc == 'f' || sc == 'F')
		return "Fahrenheit";
	else if(sc == 'k' || 'K')
		return "Kelvin";
}

bool Temperature::SetFormat(char f)
{
	if(f == 'D' || f == 'P' || f == 'L')
	{
		format = f;
		return true;
	}
	else
		return false;
}

bool Temperature::Set(double deg, char sc)
{
	if(IsValid(deg, sc))
	{
		temperature = deg;
		scale = toupper(sc);
		scaleL = ScaleToString(sc);
		return true;
	}
	else
		return false;
}

bool Temperature::Convert(char sc)
{
	if(GetScale() == 'c' || GetScale() == 'C')
	{
		switch(sc)
		{
			case 'c':
			case 'C':
				break;

			case 'f':
			case 'F':
				temperature = ((GetDegrees() * (9/5.0)) + 32);
				scale = 'F';
				scaleL = ScaleToString(sc);
				break;

			case 'k':
			case 'K':
				temperature = (GetDegrees() + 273.15);
				scale = 'K';
				scaleL = ScaleToString(sc);
				break;

		}
		return true;
	}
	else if(GetScale() == 'f' || GetScale() == 'F')
	{
		switch(sc)
		{
			case 'c':
			case 'C':
				temperature = ((GetDegrees() - 32) * (5/9.0));
				scale = 'C';
				scaleL = ScaleToString(sc);
				break;

			case 'f':
			case 'F':
				break;

			case 'k':
			case 'K':
				temperature = (((GetDegrees() - 32) * (5/9.0)) + 273.15);
				scale = 'K';
				scaleL = ScaleToString(sc);
				break;
		}
		return true;
	}
	else if(GetScale() == 'k' || GetScale() == 'K')
	{
		switch(sc)
		{
			case 'c':
			case 'C':
				temperature = (GetDegrees() - 273.15);
				scale = 'C';
				scaleL = ScaleToString(sc);
				break;

			case 'f':
			case 'F':
				temperature = ((GetDegrees() - 273.15) * (9/5.0) + 32);
				scale = 'F';
				scaleL = ScaleToString(sc);
				break;

			case 'k':
			case 'K':
				break;
		}
		return true;
	}
	else
		return false;
}

double Temperature::ConvertToK(const Temperature& d) const
//for the Compare function
{
	if(d.GetScale() == 'c' || d.GetScale() == 'C')
	{
		return (d.GetDegrees() + 273.15);
	}
	else if(d.GetScale() == 'f' || d.GetScale() == 'F')
	{
		return (((d.GetDegrees() - 32) * (5/9.0)) + 273.15);
	}
	else
		return d.GetDegrees();
}

void Temperature::Input()
{
	double deg;
	char sc;

	cout << "Enter a temperature: ";
	do
	{
		cin >> deg >> sc;

		if(IsValid(deg, sc))
		{
			temperature = deg;
			scale = toupper(sc);
			scaleL = ScaleToString(sc);
		}
		else
			cout << "Invalid temperature. Try again: ";

	}while(!IsValid(deg, sc));

}
