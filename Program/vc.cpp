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
		system("CLS");
		string ftext;
		int i=0;
		cout << "\nComplaints/Suggestions registered are :";
		while(fin >> ftext)
		{
			if(fin.eof())
				break;
			cout << i+1 << ". " << ftext << "\n";
		}
	}
}
