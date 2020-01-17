#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

void DD(string a, string b, int c);
string encryptDecrypt(string toEncrypt);

void ListUsers()
{
  string UID,PWD,a;
  int t;
  fstream login("../Data/ID_List.bin",ios::in|ios::out|ios::binary);
  if(!login)
	{
	  cout << "\nFile Not Found!";
	  cout << "\nError Code 100";
	  cout << "\nProgram Aborting";
	  exit(EXIT_FAILURE);
	}
  else
	{
	  system("CLS");
	  cout << "\nList of users registered:\n";
	  login.seekp(0,ios:end);
	  if(login.tellp()==0)
		  cout << "\nThere are no user currently registered in our database.";
	  else
		  while(true)
			{
				login >> UID >> PWD >> t;
				a = encryptDecrypt(UID);
				if(login.eof())
					break;
				DD(a,PWD,t);
				cout << endl;
			}
	}
  login.close();
  cout << "Clearing screen and returning to menu.  ";
  system("PAUSE");
}
