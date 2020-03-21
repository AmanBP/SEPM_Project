#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void DD(string a, string b, int c);
std::string encryptDecrypt(string toEncrypt);
void Register(int x);
void ListUsers();
//void DUser();
//void Uedit();

void ListUsers()
{
  fstream login("../Data/ID_List.txt",ios::in|ios::binary);
  if(!login)
	{
	  cout << "\nFile Not Found!";
	  cout << "\nError Code 100";
	  cout << "\nProgram Aborting";
	  exit(EXIT_FAILURE);
	}
  else
	{
		string a,b;
		int c;
		system("CLS");
		cout << "\nList of users registered:\n";
		while(login >> a >> b >> c)
		{
			if(login.eof())
				break;
			DD(encryptDecrypt(a),b,c);
			cout << endl;
		}
	}
  login.close();
  cout << "\nClearing screen and returning to menu.\n";
  system("PAUSE");
}

void UsersMenu()
{
	while(true)
	{
		system("CLS");
		cout << setw(80) << setfill('-') <<"-\n";
  		cout << "|" << setw(39) << setfill(' ') <<"Users Menu";
  		cout << setw(40) << setfill(' ') << "|\n";
  		cout << setw(79) << setfill('-') <<"-";
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
