#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

void TransLogs(string uid);
void Backup();
void VRates();
void CRates();
void UsersMenu();
void ComplaintHandler();
void AttendanceHandler();

void AdminMenu(string uid)
{
	int choice;
	while(true)
	{
		system("CLS");
		cout << setw(80) << setfill('-') <<"-\n";
  		cout << "|" << setw(39) << setfill(' ') <<"Admin & Owner Menu";
  		cout << setw(40) << setfill(' ') << "|\n";
  		cout << setw(79) << setfill('-') <<"-";
		cout << "\n1. Attendance Menu";
		cout << "\n2. Change Rates";
		cout << "\n3. Users Menu";
		cout << "\n4. Access Transaction Logs";
		cout << "\n5. Create Backups";
		cout << "\n6. View Rates";
		cout << "\n7. Complaints/Suggestions Menu";
		cout << "\n8. Log Out";
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
				UsersMenu();
				break;
			case 4:
				TransLogs(uid);
				break;
			case 5:
				Backup();
				break;
			case 6:
				VRates();
				break;
			case 7:
				ComplaintHandler();
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
