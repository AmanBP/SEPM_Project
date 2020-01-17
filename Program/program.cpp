#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct userdata
{
	string Uname,Pass;
	int type;
};

//Custom functions:
void DD(userdata A);
string encryptDecrypt(string toEncrypt);
void Register();
void ListUsers();

int main()
{
	while(true)
	{
	    userdata a;
		string Pass,Uname;
   	    system("CLS");
		fstream  fin("../Data/ID_List.bin",ios::binary|ios::in);
		if(!fin)
		{
			cout << "\nFile Not Found!";
			cout << "\nError Code 100";
			cout << "\nProgram Aborting";
			exit(EXIT_FAILURE);
		}
		int ch;
		cout << "-----------Program Menu---------------"
		cout << "\n1. Login";
		cout << "2. Exit";
		cout << "Choose an option:";
		cin >> ch;
		seitch(ch)
		{
		case 1:
			cout << "\nEnter Username:  \n";
			cin >> Uname;
			while(true)
			{
				fin.read((char*)&a,sizeof(userdata));
				if(strcmp(a.Uname,encryptDecrypt(Uname)==0))
				{
					system("CLS")
					cout << "\nUser Found!\n\n Welcome " << encryptDecrypt(a.Uname);
				A2:
					cout << "\nPlease enter your Password: ";
					char c;
					Pass="";
					while(c!=13)
					{
						c=(char)getch();
						if(c==13)
							break;
						if(c==8)
							continue;
						Pass+=c;
						cout << "*";
					}
					if(strcmp(a.Pass, encryptDecrypt(Pass))==0)
					{
						cout << "\nLogged in succesfully.";
						cout << "\nPlease ";
						system("PAUSE");
						system("CLS");
						switch(a.type)
						{
							case 1:
								AdminMenu();
								break;
							case 2:
								OwnerMenu();
								break;
							case 3:
								AccountantMenu();
								break;
							case 4:
								ReceptionistMenu();
								break;
							case 5:
								Gym_Staff_Menu();
								break;
							case 6:
								Gym_User_Menu();
								break;
						}
					}
					else
					{
						cout << "Incorrect Password!\n";
						system("PAUSE");
						goto A2;
					}
				}
				else
				{
					if(fin.eof())
						cout << "\nUsername not found, please register or check input.";
				}
			}
		case 2:
			exit(EXIT_SUCCESS);
		}
	}
  	return 0;
}
