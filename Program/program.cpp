#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main()
{
	try
	{
	        fstream login("ID_List.dat",ios::in|ios::out|ios::binary);
		if(!login)
		{
			cout << "File Not Found!";
			cout << "Program will now exit";
			throw(100);
		}
		cout << "Enter Your Login ID:\n";
		string USER_ID;
		getline(cin,USER_ID);
		cout << "Enter Password:\n";
		string PASSWORD;
		char c=11;
		while(c!=13)
		  {
		    c=(char)getch();
		    if(c==13)
		      break;
		    PASSWORD+=c;
		    cout << "*";
		  }
		cout << "\nUserID:" << USER_ID << "\nPassword:" << PASSWORD;		  
		login.close();
	}
	catch(int x)
	{
		if(x==100)
			exit(0);
		
	}
	return 0;
}
