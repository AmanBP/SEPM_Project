#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

void TransLogs(string uid);
void Backup();
void RateHandler();
void UsersMenu();
void ComplaintHandler();
void AttendanceHandler();
void makemenuheader(string a);

void AdminMenu(string uid)
{
	int choice;
	while(true)
	{
		system("CLS");
		makemenuheader("          Admin & Owner Menu          ");
		cout << "1. Attendance Menu";
		cout << "\n2. Rates Menu";
		cout << "\n3. Users Menu";
		cout << "\n4. Access Transaction Logs";
		cout << "\n5. Create Backups";
		cout << "\n6. Complaints/Suggestions Menu";
		cout << "\n7. Log Out";
		cout << "\n:";
		cin >> choice;
		switch(choice)
		{
			case 1:
				AttendanceHandler();
				break;
			case 2:
				RateHandler();
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
				ComplaintHandler();
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
