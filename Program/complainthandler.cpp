#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void MakeComp()
{
	fstream fin;
	fin.open("../Data/complaints.txt",ios::out|ios::app);
	if(!fin)
	{
		cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
	}
	else
	{
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

void ViewComplaints()
{
	fstream fin("../Data/complaints.txt",ios::in);
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
		int i=0;
		cout << "\nComplaints/Suggestions registered are :\n\n";
		while(fin >> ftext)
		{
			if(fin.eof())
				break;
			cout << i+1 << ". " << ftext << "\n";
			i++;
		}
		cout << endl;
		system("Pause");
		fin.close();
	}
}

void DelComplaints()
{
	int n,line_no=1;
    char c; 
	ofstream ofs; 
	ifstream is;
	ViewComplaints();
	cout << "\nEnter which complaint/suggestion no. would you like to delete:";
	cin >> n;
	is.open("../Data/complaints.txt");
    ofs.open("../Data/temp.txt", ofstream::out); 
    while (is.get(c)) 
    {
        if (c == '\n') 
        line_no++;
        if (line_no != n) 
            ofs << c; 
    } 
    ofs.close(); 
    is.close();
	remove("../Data/complaints.txt"); 
    rename("../Data/temp.txt", "../Data/complaints.txt");
	cout << "\nComplaint no." << n << " has been deleted.\n";
	system("PAUSE");
}

void ComplaintHandler()
{
	while(true)
	{
		system("CLS");
		cout << setw(80) << setfill('-') <<"-\n";
  		cout << "|" << setw(39) << setfill(' ') <<"Complaints/Suggestion Menu";
  		cout << setw(40) << setfill(' ') << "|\n";
  		cout << setw(79) << setfill('-') <<"-";
		cout << "\n1. View Complaints/Suggestions";
		cout << "\n2. Delete a Complaint/Suggestion";
		cout << "\n3. Make a Complaint/Suggestion";
		cout << "\n4. Back";
		cout << "\n:";
		int choice;
		cin >> choice;
		switch(choice)
		{
			case 1:
					ViewComplaints();
					break;

			case 2:
					DelComplaints();
					break;

			case 3:
					MakeComp();
					break;
					
			case 4:
					return;
					break;
			
			default:
					cout << "\nWrong Option selected, Please Try Again\n";
					system("PAUSE");
					break;
		}
	}
}