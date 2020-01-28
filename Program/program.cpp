#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

//Custom functions:
void AdminMenu();
void DD(string a, string b, int c);
std::string encryptDecrypt(string toEncrypt);


int main()
{	int x=0;
	while(true)
	{
		string Pass,Uname,FPass,FUname;
		int type,Ftype;
   	    system("CLS");
		fstream  fin("../Data/ID_List.txt",ios::in|ios::binary);
		if(!fin)
		{
			cout << "\nFile Not Found!";
			cout << "\nError Code 100";
			cout << "\nProgram Aborting";
			exit(EXIT_FAILURE);
		}
		int ch;
		A3:
		system("CLS");
		cout << "-----------Program Menu---------------";
		cout << "\n1. Login";
		cout << "\n2. Exit";
		cout << "\nChoose an option:";
		cin >> ch;
		switch(ch)
		{
		case 1:
			cout << "\nEnter Username:  \n";
			cin >> Uname;
			while(fin >> FUname >> FPass >> Ftype)
			{
				if(Uname.compare(encryptDecrypt(FUname))==0)
				{
					system("CLS");
					cout << "\nUser Found!\n\nWelcome " << encryptDecrypt(FUname);
					A2:
					cout << "\nPlease enter your Password: ";
					char c=char(11);
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
					if(Pass.compare(encryptDecrypt(FPass))==0)
					{
						cout << "\nPlease Wait";
						system("CLS");
						cout << "\n\nLogged in succesfully.";
						cout << "\nPlease ";
						system("PAUSE");
						system("CLS");
						switch(Ftype)
						{
							case 1:
								AdminMenu();
								goto A3;
								break;
							case 2:
								//AccountantMenu();
								cout << "AccountantMenu";
								goto A3;
								break;
							case 3:
								//ReceptionistMenu();
								cout << "ReceptionistMenu";
								goto A3;
								break;
							case 4:
								//Gym_Staff_Menu();
								cout << "Gym_Staff_Menu";
								goto A3;
								break;
							case 5:
								//Gym_User_Menu();
								cout << "Gym_User_Menu";
								goto A3;
								break;
						}
					}
					else
					{
						cout << "\nIncorrect Password!\n";
						x++;
						if(x==3)
						{
							cout << "\nYou have entered the wrong password 3 times.\nExiting to program menu\n";
							system("PAUSE");
							system("CLS");
							goto A3;
						}
						system("PAUSE");
						goto A2;
					}
				}
				else
					continue;
			}
			if(fin.eof())
				cout << "/nUsername was not found, please register./n";
			break;
		case 2:
			exit(EXIT_SUCCESS);
		default:
			exit(EXIT_SUCCESS);
		}
	}
 	return 0;
}
