#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

void Trans(string uid);
void VRates();
void MakeComp();
void makemenuheader(string a);


void AccountantMenu(string uid)
{
	int choice=0;
	while(true)
	{
		system("CLS");
		makemenuheader("          Accountant Menu          ");
		cout << "1. Transaction Menu";
		cout << "\n2. View Rates";
		cout << "\n3. Make Complaint/Suggestion";
		cout << "\n4. Log Out";
		cout << "\n:";
		cin >> choice;
		switch(choice)
		{
			case 1:
				Trans(uid);
				break;
			case 2:
				VRates();
				break;
			case 3:
				MakeComp();
				return;
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
