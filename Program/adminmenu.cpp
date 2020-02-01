#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void ListUsers();
void Register();
//void ViewAttendance();
//void TransLogs();
//void Backup();
void VRates();
void CRates();
void MUsers();

void AdminMenu()
{
	int choice=8;
	while(true)
	{
		system("CLS");
		cout << "\n-------------------------Admin & Owner Menu----------------------------";
		cout << "\n1.View Attendance";
		cout << "\n2.Change Rates";
		cout << "\n3.User Options";
		cout << "\n4.Access Transaction Logs";
		cout << "\n5.Create Backups";
		cout << "\n6.View Rates";
		cout << "\n7.Log Out";
		cout << "\n:";
		cin >> choice;
		switch(choice)
		{
			case 1:
//				ViewAttendance();
				break;
			case 2:
				CRates();
				break;
			case 3:
				MUsers();
				break;
			case 4:
//				TransLogs();
				break;
			case 5:
//				Backup();
				break;
			case 6:
				VRates();
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
