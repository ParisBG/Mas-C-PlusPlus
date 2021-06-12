//================================ Part one =================================
// Write a program (procedual program) that reads data from two input file.
// One input file is students (10) grade of type integer
// Another input file is students (first and last name (10)
//Read these datas into two arrays one integer other string
// Now your program consist of two functions
// one that reads data , and other display the data
// Now read students grade in two dim. array of int.
//========================= Part two ==================================
// Modify above program so you have multiple grades for each students
// necessary changes to the main program that can read and write data in to an output file
// Example of Output file :
// Students Name Student grade
// Ali Nikzad 87 78 67 56 90 10
// Mike Lapory 90 90 89 56 4 20
// Maria Portaly 87 90 89 90 90 87
//========================= Part three ==================================
// Modify this program now to find sum of grades for each studentsm and store it in an array
// called Total. Then display students name , grades and their total.
//========================= Part 4 & 5 =====================================
// Add two more functions one calculates average of each students and store it in a double arraye called average
// Another function finds letter garde for each students and store the letter grade in an array of char vcalled letter_grade
// Make necessary changes to main program and display function to display
// Students name grades, total, average and letter garde foe each students

//may name
//Date

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //

using namespace std;

const int row = 7;
const int col = 7;

ifstream inn, ing;
ofstream result;

//================================================================>

void readdata(string name[row], int grade[row][col]);
void displaydata(string name[row], int grade[row][col], int total[row], double average[row], char lgrade[row]);
void Calculate_Total(int grade[row][col], int total[row]);
void Calculate_average(int total[row], double average[row]);
void Calculate_LetterGrade(double average[row], char lgrade[row]);
void sortletter(string name[row], int grade[row][col], int total[row], double average[row], char lgrade[row]);

//=================================================================

int main()
{
	int g[row][col] = { {0},{0} }; // This array holds grades
	string n[row] = {}; // This array holds names
	int t[row] = { 0 }; // This array holds total grade
	double a[row] = { 0.0 }; // This array is storing average of grades for each student
	char l[row] = {}; // This array holds letter grade

	readdata(n, g);
	Calculate_Total(g, t);
	Calculate_average(t, a);
	Calculate_LetterGrade(a, l);
	displaydata(n, g, t, a, l);

	sortletter(n, g, t, a, l);
	displaydata(n, g, t, a, l);

	inn.close();
	ing.close();
	result.close();

	system("pause");
	return 0;
}
//=========================== Read Data ============================================
void readdata(string name[row], int grade[row][col])
{
	inn.open("StudentsName.txt");
	ing.open("StudentsGrade.txt");

	int r, c;

	for (r = 0; r < row; r++) // This loop takes names and store them in array of name
		getline(inn, name[r]);

	for (r = 0; r < row; r++) // This nested loops are storing grades into array of grade
		for (c = 0; c < col; c++)
			ing >> grade[r][c];
}
//============================== Display data ======================================
void displaydata(string name[row], int grade[row][col], int total[row], double average[row], char lgrade[row])
{
	result.open("CS2410Record.txt", ios::app);
	int r, c;
	result << fixed << showpoint;
	result << "====================================================================================" << endl;
	result << " Students Name Grades Total average lettergrade " << endl;
	result << "====================================================================================" << endl;
	
	for (r = 0; r < row; r++)
	{
		result << setw(20) << left << name[r];
		for (c = 0; c < col; c++)
			result << setw(4) << right << grade[r][c];
		result << setw(5) << total[r] << setw(8) << setprecision(2) << average[r] << setw(4) << lgrade[r] << endl;
	}

	result << endl << endl;
}
//===========================================================================

void Calculate_Total(int grade[row][col], int total[row])
{
	int r, c;
	for (r = 0; r < row; r++) // This loop goes through all rows
		for (c = 0; c < col; c++) // This loop adds greads from each column
			total[r] = total[r] + grade[r][c];
}
//=============================== Average =====================================
void Calculate_average(int total[row], double average[row])
{
	int r;
	for (r = 0; r < row; r++)
		average[r] = static_cast <double> (total[r]) / col;
}
//=======================================================
void Calculate_LetterGrade(double average[row], char lgrade[row])
{
	int r;
	for (r = 0; r < row; r++)
	{
		if (average[r] >= 90)
			lgrade[r] = 'A';
		else if (average[r] >= 80)
			lgrade[r] = 'B';
		else if (average[r] >= 70)
			lgrade[r] = 'C';
		else if (average[r] >= 60)
			lgrade[r] = 'D';
		else
			lgrade[r] = 'F';
	}
}
//===================================== Sort function using bubble sort =============================
void sortletter(string name[row], int grade[row][col], int total[row], double average[row], char lgrade[row])
{
	int r, c, fp;
	char templgrade;
	int tempgrade;
	int temptotal;
	double tempaverage;
	string tempname;


	for (r = 0; r < row; r++)
	{
		for (fp = 0; fp < (row - 1); fp++)
		{
			if (lgrade[fp] > lgrade[fp + 1])
			{
				templgrade = lgrade[fp]; // This part will swap letter gardes
				lgrade[fp] = lgrade[fp + 1];
				lgrade[fp + 1] = templgrade;

				tempname = name[fp]; // This part will swap names
				name[fp] = name[fp + 1];
				name[fp + 1] = tempname;

				temptotal = total[fp]; // This part will swap total
				total[fp] = total[fp + 1];
				total[fp + 1] = temptotal;

				tempaverage = average[fp]; // This part will swap avearge
				average[fp] = average[fp + 1];
				average[fp + 1] = tempaverage;

				for (c = 0; c < col; c++)
				{
					tempgrade = grade[fp][c]; // This part will swap grades
					grade[fp][c] = grade[fp + 1][c];
					grade[fp + 1][c] = tempgrade;
				}
			}
		}
	}
}