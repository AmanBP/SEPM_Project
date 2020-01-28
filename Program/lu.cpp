#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

void DD(string a, string b, int c);
std::string encryptDecrypt(string toEncrypt);

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
