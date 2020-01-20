#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <conio.h>
using namespace std;

void DD(string a, string b, int c);
std::string encryptDecrypt(string toEncrypt);


void Register()
{
	string PASSWORD,USER_ID,UID,PASS;
	int type,t;
	cout << "\nRegistering has begun";
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
	cout << "\n\n\nEnter a user type:\n1.Admin\n2.Owner\n3.Accountant\n4.Receptionist\n5.Gym Staff\n6.Gym User\t:";
	cin >> type;
	cout << "\n\nYou have entered the following ";
	DD(USER_ID,PASSWORD,type);
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
