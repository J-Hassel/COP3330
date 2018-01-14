class Temperature
{
public:
	Temperature();
	Temperature(double deg, char sc);


	//accessors
	void Show() const;
	double GetDegrees() const;
	char GetScale() const;
	int Compare(const Temperature& d) const;
	bool IsValid(double deg, char sc) const;
	std::string ScaleToString(char sc) const;
	double ConvertToK(const Temperature& d) const;

	//mutators
	bool SetFormat(char f);
	bool Set(double deg, char s);
	bool Convert(char sc);
	void Input();

private:
	double temperature;
	char format, scale;
	std::string scaleL;
};
