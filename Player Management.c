#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
void display(string n[], int m[], int r[], int hs[], int c[])
{
	for (int x = 0; x < 10; x++)
		cout << n[x] << "\t" << m[x] << "\t" << r[x] << "\t" << hs[x] << "\t" << c[x] << endl;
	cout << endl;
}
void max(string n[], int m[], int r[], int hs[], int c[])
{
	int max = 0;
	for (int i = 1; i < 10; i++)
	{

		if (hs[i] > hs[max])
		{
			max = i;
		}
	}
	cout << "Player With Maximum Highest Score : \n";
	cout << "Player \t\t\t Matches \tRuns \t HS \t Hundreds " << endl;
	cout << n[max] << "		 ";
	cout << m[max] << " 		";
	cout << r[max] << "\t ";
	cout << hs[max] << "	  ";
	cout << c[max] << "	";
	cout << endl
		 << endl;
}
void average(string n[], int m[], int r[], int hs[], int cent[])
{

	int max = 0;
	for (int i = 1; i < 10; i++)
	{
		if (r[i] > r[max])
		{
			max = i;
		}
	}
	double avg = r[max] / m[max];
	cout << "Average of Top Pakistani Batsman"
		 << " " << n[max] << " "
		 << "is : " << avg << endl
		 << endl;
}
void ascending(string n[], int m[], int r[], int hs[], int cent[])
{
	{
		int i, j;

		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9 - i; j++)
			{
				if (r[j] > r[j + 1])
				{
					swap(m[j], m[j + 1]);
					swap(r[j], r[j + 1]);
					swap(hs[j], hs[j + 1]);
					swap(cent[j], cent[j + 1]);
					swap(n[j], n[j + 1]);
				}
			}
		}
	}
}

void Output(string fileName, string n[], int matches[], int runs[], int hs[], int centuries[])
{
	ofstream out;
	out.open(fileName);

	out << "Player"
		<< "\t"
		<< "\t"
		<< "Matches"
		<< "\t"
		<< "Runs"
		<< "\t"
		<< "HS"
		<< "\t"
		<< "Centuries" << endl
		<< endl;

	for (int i = 0; i < 10; i++)
	{
		out << n[i] << "\t" << matches[i] << "\t" << runs[i] << "\t" << hs[i] << "\t" << centuries[i] << endl;
	}
	out.close();
}

void main()
{
	string row;
	string fullname[15];
	int match[10], runs[10], high[10], cent[10];
	ifstream in;
	in.open("Batsman.txt");
	getline(in, row);
	for (int i = 0; i < 10; i++)
	{
		in >> fullname[i] >> match[i] >> runs[i] >> high[i] >> cent[i];
	}
	cout << row << endl;
	in.close();
	display(fullname, match, runs, high, cent);
	max(fullname, match, runs, high, cent);
	average(fullname, match, runs, high, cent);
	ascending(fullname, match, runs, high, cent);
	Output("Output.txt", fullname, match, runs, high, cent);
}
