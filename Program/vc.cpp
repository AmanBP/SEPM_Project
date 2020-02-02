#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void ViewComplaints()
{
	fstream fin("../Data/Complaints.txt",ios::in);
	if(!fin)
	{
		cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
	}
	else
	{
		string ftext;
		cout << "\nCurrent complaints are:";
		while(fin >> ftext)
		{
			break;
		}
	}
}
