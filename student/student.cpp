
//Jonathan Hassel -- Section 6

#include "student.h"

//--------------------------------------------STUDENT CLASS--------------------------------------------\\

char Student::ConvertToGrade() const
{
	if(this->Avg() >= 90)
		return 'A';
	else if(this->Avg() <= 89 && this->Avg() >= 80)
		return 'B';
	else if(this->Avg() <= 79 && this->Avg() >= 70)
		return 'C';
	else if(this->Avg() <= 69 && this->Avg() >= 60)
		return 'D';
	else if(this->Avg() < 60)
		return 'F';
}

char* Student::GetFirstName()
{
	return this->firstName;
}

char* Student::GetLastName()
{
	return this->lastName;
}

char Student::GetType() const
{
	return this->studentType;
}

//---------------------------------------------ENGLISH CLASS---------------------------------------------\\

English::English(char fn[], char ln[], char type, int& tp, int& m, int& fe)
{
	strcpy(firstName, fn);
	strcpy(lastName, ln);
	studentType = type;
	termPaper = tp;
	midterm = m;
	finalExam = fe;
}

double English::Avg() const
{
	return ((this->termPaper * 0.25) + (this->midterm * 0.35) + (this->finalExam * 0.40));
}

int English::GetFinalExam() const
{
	return this->finalExam;
}

//---------------------------------------------HISTORY CLASS---------------------------------------------\\-

History::History(char fn[], char ln[], char type, int& a, int& p, int& m, int& fe)
{
	strcpy(firstName, fn);
	strcpy(lastName, ln);
	studentType = type;
	attendance = a;
	project = p;
	midterm = m;
	finalExam = fe;
}

double History::Avg() const
{
	return ((this->attendance * 0.10) + (this->project * 0.30) + (this->midterm * 0.30)
	     + (this->finalExam * 0.30));
}

int History::GetFinalExam() const
{
	return this->finalExam;
}


//-----------------------------------------------MATH CLASS-----------------------------------------------\\

Math::Math(char fn[], char ln[], char type, int& q1, int& q2, int& q3, int& q4, int& q5, int& t1, int& t2, int& fe)
{
	strcpy(firstName, fn);
	strcpy(lastName, ln);
	studentType = type;
	quiz1 = q1;
	quiz2 = q2;
	quiz3 = q3;
	quiz4 = q4;
	quiz5 = q5;
	test1 = t1;
	test2 = t2;
	finalExam = fe;
}

double Math::Avg() const
{
	double quizAvg;
	quizAvg = ((this->quiz1) + (this->quiz2) + (this->quiz3) + (this->quiz4) + (this->quiz5)) / (5.0);

	return ((quizAvg * 0.15) + (this->test1 * 0.25) + (this->test2 * 0.25) + (this->finalExam * 0.35));
}

int Math::GetFinalExam() const
{
	return this->finalExam;
}
