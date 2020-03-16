#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//void TransLogs();
//void Backup();
void VRates();
void CRates();
void MUsers();
void ViewComplaints();
void AttendanceHandler();

void AdminMenu()
{
	int choice=9;
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
		cout << "\n7.View Complaints/Suggestions";
		cout << "\n8.Log Out";
		cout << "\n:";
		cin >> choice;
		switch(choice)
		{
			case 1:
				AttendanceHandler();
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
				ViewComplaints();
				break;
			case 8:
				return;
				break;
			default:
				cout << "\nWrong Choice, Please choose again:\n";
				system("PAUSE");
				break;
		}
	}
}
