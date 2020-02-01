#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//void ViewAttendance();
//void TransLogs();
//void Backup();
void VRates();
void AccountantMenu()
{
	int choice=8;
	while(true)
	{
		system("CLS");
		cout << "\n-------------------------Accountant Menu----------------------------";
		cout << "\n1.Do a Transaction";
		cout << "\n2.View Transaction Logs";
		cout << "\n3.View Rates"
		cout << "\n4.Log Out";
		cout << "\n:";
		cin >> choice;
		switch(choice)
		{
			case 1:
//				TransLogs();
				break;
			case 2:
//				Trans();
				break;
			case 3:
				VRates();
				break;
			case 4:
				return;
				break;
			default:
				cout << "\nWrong Choice, Please choose again:\n";
				system("PAUSE");
				break;
		}
	}
}
