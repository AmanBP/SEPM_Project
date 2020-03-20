#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void MakeComp();
void Register(int x);
void Fees(string uid);

void ReceptionistMenu(string uid)
{
	while(true)
	{
		system("CLS");
		cout << setw(80) << setfill('-') <<"-\n";
  		cout << "|" << setw(39) << setfill(' ') <<"Receptionist Menu";
  		cout << setw(40) << setfill(' ') << "|\n";
  		cout << setw(79) << setfill('-') <<"-";
		cout << "\n1.Register";
		cout << "\n2.Recieve Fees";
		cout << "\n3.Complaint/Suggestion";
		cout << "\n4.Logout";
		cout << "\n:";
		int ch;
		cin >> ch;
		switch(ch)
		{
			case 1:
				Register(2);
				break;
			case 2:
				Fees(uid);
				break;
			case 3:
				MakeComp();
				break;
			case 4:
				return;
				break;
			default:
				cout << "\n Wrong Choice, Please choose again:\n";
				system("PAUSE");
				break;
		}
	}
	return;
}
