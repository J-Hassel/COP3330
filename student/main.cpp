//Jonathan Hassel -- Section 6

#include "student.h"

int main()
{
	char studentType, ifile[20], ofile[20], firstName[21], lastName[21], throwaway[10];
	int listSize, a = 0, b = 0, c = 0, d = 0, f = 0;
	ifstream fin;
	ofstream fout;


	//getting input file
	do
	{
		fin.clear();
		cout << "Please enter the name of the input file." << '\n' << "Filename: ";
		cin >> ifile;

		fin.open(ifile);
		if(!fin)
			cout << "Invalid file. Try again!" << '\n';
		else
			break;
	}while(true);


	//getting output file

	cout << "Please enter the name of the output file." << '\n' << "Filename: ";
	cin >> ofile;

	//reading in student data from input file
	fin >> listSize;

	Student** studentArray = new Student*[listSize];

	for(int i = 0; i < listSize; i++)
	{
		fin.get();	//gets newline
		fin.getline(lastName, 20, ',');

		fin.get();	//gets space
		fin.getline(firstName, 20);

		fin.get(studentType);	//gets type
		fin.getline(throwaway, 10, ' ');

		if(studentType == 'E')
		{
			int tp, m, fe;

			fin >> tp >> m >> fe;

			studentArray[i] = new English(firstName, lastName, studentType, tp, m, fe);
		}
		else if(studentType == 'H')
		{
			int a, p, m, fe;

			fin >> a >> p >> m >> fe;

			studentArray[i] = new History(firstName, lastName, studentType, a, p, m, fe);
		}
		else if(studentType == 'M')
		{
			int q1, q2, q3, q4, q5, t1, t2, fe;

			fin >> q1 >> q2 >> q3 >> q4 >> q5 >> t1 >> t2 >> fe;

			studentArray[i] = new Math(firstName, lastName, studentType, q1, q2, q3, q4, q5, t1, t2, fe);
		}

	}

	//done with input
	fin.close();
//----------------------------------------------------OUTPUT-------------------------------------------------\\

	fout.open(ofile);

	fout << "Student Grade Summary" << '\n';
	fout << "---------------------" << '\n' << '\n';


	//prints english students
	fout << "ENGLISH CLASS" << '\n' << '\n';
	fout << "Student" << "\t\t\t\t\t" << "Final\t" << "Final\t" << "Letter" << '\n';
	fout <<"Name" << "\t\t\t\t\t" << "Exam\t" << "Avg\t" << "Grade" << '\n';
	fout << "----------------------------------------------------------------" << '\n';

	for(int i = 0; i < listSize; i++)
	{
		if(studentArray[i]->GetType() == 'E')
		{
			fout << studentArray[i]->GetFirstName() << " " << studentArray[i]->GetLastName();

			if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 8)
				fout << "\t\t\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 16)
				fout << "\t\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 24)
				fout << "\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 32)
				fout << "\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 40)
				fout << "\t";

			fout << studentArray[i]->GetFinalExam() << '\t';

			//saving old precision settings
			int oldprecision = fout.precision();
			ios_base::fmtflags oldflags = fout.flags();

			fout << fixed << setprecision(2) << studentArray[i]->Avg() << '\t';

			//reverting back to old settings
			fout.precision(oldprecision);
			fout.flags(oldflags);

			fout  << studentArray[i]->ConvertToGrade() << '\n';
		}
	}
	fout << '\n' << '\n';


	//prints history students
	fout << "HISTORY CLASS" << '\n' << '\n';
	fout << "Student" << "\t\t\t\t\t" << "Final\t" << "Final\t" << "Letter" << '\n';
	fout <<"Name" << "\t\t\t\t\t" << "Exam\t" << "Avg\t" << "Grade" << '\n';
	fout << "----------------------------------------------------------------" << '\n';

	for(int i = 0; i < listSize; i++)
	{
		if(studentArray[i]->GetType() == 'H')
		{
			fout << studentArray[i]->GetFirstName() << " " << studentArray[i]->GetLastName();

			if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 8)
				fout << "\t\t\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 16)
				fout << "\t\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 24)
				fout << "\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 32)
				fout << "\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 40)
				fout << "\t";

			fout << studentArray[i]->GetFinalExam() << '\t';

			//saving old precision settings
			int oldprecision = fout.precision();
			ios_base::fmtflags oldflags = fout.flags();

			fout << fixed << setprecision(2) << studentArray[i]->Avg() << '\t';

			//reverting back to old settings
			fout.precision(oldprecision);
			fout.flags(oldflags);

			fout << studentArray[i]->ConvertToGrade() << '\n';
		}
	}
	fout << '\n' << '\n';


	//prints math students
	fout << "MATH CLASS" << '\n' << '\n';
	fout << "Student" << "\t\t\t\t\t" << "Final\t" << "Final\t" << "Letter" << '\n';
	fout <<"Name" << "\t\t\t\t\t" << "Exam\t" << "Avg\t" << "Grade" << '\n';
	fout << "----------------------------------------------------------------" << '\n';

	for(int i = 0; i < listSize; i++)
	{
		if(studentArray[i]->GetType() == 'M')
		{
			fout << studentArray[i]->GetFirstName() << " " << studentArray[i]->GetLastName();

			if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 8)
				fout << "\t\t\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 16)
				fout << "\t\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 24)
				fout << "\t\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 32)
				fout << "\t\t";
			else if(strlen(studentArray[i]->GetFirstName()) + strlen(studentArray[i]->GetLastName()) + 1 < 40)
				fout << "\t";

			fout << studentArray[i]->GetFinalExam() << '\t';

			//saving old precision settings
			int oldprecision = fout.precision();
			ios_base::fmtflags oldflags = fout.flags();

			fout << fixed << setprecision(2) << studentArray[i]->Avg() << '\t';

			//reverting back to old settings
			fout.precision(oldprecision);
			fout.flags(oldflags);

			fout << studentArray[i]->ConvertToGrade() << '\n';
		}
	}
	fout << '\n' << '\n';


	//grade distribution
	for(int i = 0; i < listSize; i++)
	{
		switch(studentArray[i]->ConvertToGrade())
		{
			case 'A':
				a++;
				break;

			case 'B':
				b++;
				break;

			case 'C':
				c++;
				break;

			case 'D':
				d++;
				break;

			case 'F':
				f++;
				break;

		}
	}

	fout << "OVERALL GRADE DISTRIBUTION" << '\n' << '\n';
	fout << "A:\t" << a << '\n' << "B:\t" << b << '\n' << "C:\t" << c << '\n';
	fout << "D:\t" << d << '\n' << "F:\t" << f << '\n';

	//closing output file
	fout.close();

	//de-allocation
	for(int i = 0; i < listSize; i++)
	{
		delete studentArray[i];
		studentArray[i] = 0;
	}

	delete [] studentArray;
	studentArray = 0;

	return 0;
}
