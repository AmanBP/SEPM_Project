#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void DD(string a, string b, int c);
std::string encryptDecrypt(string toEncrypt);
void makemenuheader(string a);

void Register(int x)
{
	makemenuheader("                         REGISTER                       ");
	string PASSWORD,USER_ID,UID,PASS;
	int type,t;
	cout << "Registeration has begun";
	A1:
	fstream op("../Data/ID_List.txt",ios::in|ios::binary);
	if(!op)
	{
		cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
	}
	cout << "\nEnter a username:";
	cin >> USER_ID;
	while(op >> UID >> PASS >> t)
	{
		UID=encryptDecrypt(UID);
		if(UID.compare(USER_ID)==0)
		{
			op.close();
			cout << endl << "This user ID has been taken, Please enter a new ID:";
			goto A1;
		}
	}
	op.close();
	cout << "\nUsername Is available";
	cout << "\nPlease Enter a password:";
	cin >> PASSWORD;
	if(x==1)
		cout << "\n\n\nEnter a user type:\n1.Admin & Owner\n2.Accountant\n3.Receptionist\n4.Gym Staff\n5.Gym User\t:";
	else
		cout << "\n\n\nEnter a user type:\n1.Gym Staff\n2.Gym User:\t";
	while(true)
	{
		cin >> type;
		if(type>=1 && type<=5 && x==1)
			break;
		else if(type>=1 && type<=2 && x==2)
			{
				type+=3;
				break;
			}
		else
			cout << "\nPlease enter a correct type:";
	}
	cout << "\n\nYou have entered the following ";
	if(x==1)
		DD(USER_ID,PASSWORD,type);
	else
		DD(USER_ID,PASSWORD,type-3);
	cout << endl;
	fstream op1("../Data/ID_List.txt",ios::out|ios::app|ios::binary);
	if(!op1)
	{
		cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
	}
	cout << "\nSaving data to file\n";
	op1 << encryptDecrypt(USER_ID) << " " << encryptDecrypt(PASSWORD) << " " << type << "\n";
	op1.close();
	cout << "\nClearing screen and returning to menu, ";
	system("PAUSE");
}
