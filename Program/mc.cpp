//Complaint Function resides here

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void  MakeComp()
{
	fstream fin;
	fin.open("../Data/Complaints.txt",ios::out);
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
		string a;
		cout << "\nWhat would you like to Complain/Suggest to us?\n";
		cin >> a;
		cout << "\n Your Complaint/Suggestion has been logged.";
		fin << a << "\n";
		fin.close();
		cout << endl;
		system("Pause");
	}
	return;
}
