#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

void MakeComp();
void Register(int x);

void ReceptionistMenu()
{
	while(true)
	{
		system("CLS");
		cout << "---------------Receptionist Menu------------------";
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
				//Fees();
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
