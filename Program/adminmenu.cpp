#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ListUsers();
void Register();
//void ViewAttendance();
//void ChangeRates();
//void TransLogs();
//void Backup();


void AdminMenu()
{
	int choice=8;
	while(true)
	{
		system("CLS");
		cout << "\n-------------------------Admin & Owner Menu----------------------------";
		cout << "\n1.View Attendance";
		cout << "\n2.Change Rates";
		cout << "\n3.Register";
		cout << "\n4.List Users";
		cout << "\n5.Access Transaction Logs";
		cout << "\n6.Create Backups";
		cout << "\n7.Log Out";
		cout << "\n:";
		cin >> choice;
		switch(choice)
		{
			case 1:
//				ViewAttendance();
				break;
			case 2:
//				ChangeRates();
				break;
			case 3:
				Register();
				break;
			case 4:
				ListUsers();
				break;
			case 5:
//				TransLogs();
				break;
			case 6:
//				Backup();
				break;
			case 7:
				return;
				break;
			default:
				cout << "\nWrong Choice, Please choose again:\n";
				system("PAUSE");
				break;
		}
	}
}