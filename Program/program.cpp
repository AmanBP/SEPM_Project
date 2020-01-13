#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

//Custom functions:
void DD(string a, string b, int c);
string encryptDecrypt(string toEncrypt);
void Register();
void ListUsers();

int main()
{
	while(1)
	{
      	      system("CLS");
	      cout << "\n--------------------Program Menu--------------------";
	      cout << "\n--Choose an option:----";
	      cout << "\n1. Register";
	      cout << "\n3. Show Users List";
	      cout << "\n4. Exit";
	      cout << endl;
	      int choice;
	      cin >> choice;
	      switch(choice)
		{
		case 1:
		  Register();
		  break;
		case 3:
		  ListUsers();
		  break;
		case 4:
		  exit(EXIT_SUCCESS);
		}
	    }
  	return 0;
}
