//Jonathan Hassel -- Section 6

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;

class Student
{
public:
	//accessors
	char ConvertToGrade() const;
	char* GetFirstName();
	char* GetLastName();
	char GetType() const;
	virtual int GetFinalExam() const = 0;
	virtual double Avg() const = 0;

protected:
	//common member data
	char firstName[21], lastName[21], studentType;
};

//------------------------------------------------------------------------------------------------

class English : public Student
{
public:
	//constructor
	English(char fn[], char ln[], char type, int& tp, int& m, int& fe);

	//accessors
	double Avg() const;
	int GetFinalExam() const;

private:
	int termPaper, midterm, finalExam;

};

//------------------------------------------------------------------------------------------------


class History : public Student
{
public:
	//constructor
	History(char fn[], char ln[], char type, int& a, int& p, int& m, int& fe);

	//accessors
	double Avg() const;
	int GetFinalExam() const;

private:
	int attendance, project, midterm, finalExam;
};

//------------------------------------------------------------------------------------------------


class Math : public Student
{
public:
	//constructor
	Math(char fn[], char ln[], char type, int& q1, int& q2, int& q3, int& q4, int& q5, int& t1, int& t2, int& fe);

	//accessors
	double Avg() const;
	int GetFinalExam() const;

private:
	int quiz1, quiz2, quiz3, quiz4, quiz5, test1, test2, finalExam;
};
