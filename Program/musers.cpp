#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void Register(int x);
void ListUsers();
//void DUser();
//void Uedit();

void MUsers()
{
	while(true)
	{
		system("CLS");
		cout << "\n1.Edit a User";
		cout << "\n2.Add a User";
		cout << "\n3.Delete a User";
		cout << "\n4.List Users";
		cout << "\n5.Return to menu";
		cout << "\nWhat would you like to do? :";
		int ch;
		cin >> ch;
		switch(ch)
		{
			case 1:
	//			Uedit();
				break;
			case 2:
				Register(1);
				break;
			case 3:
	//			DUser();
				break;
			case 4:
				ListUsers();
				break;
			case 5:
				return;
				break;
			default:
				cout << "\n Wrong option!!";
				system("PAUSE");
				break;
		}
	}
	return;
}