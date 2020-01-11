#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

string USER_ID;
string PASSWORD;
int type;

void DD(string a, string b, int c)
{
  cout << "\nDetails:";
  cout << "\nUSERNAME:" << a;
  cout << "\nPassword:" << b;
  cout << "\nUser Type:" << c;
}

void Register()
{
  cout << "\nRegistering has begun";
 A1:
  cout << "\nEnter a username:";
  cin >> USER_ID;
  fstream op("../Data/ID_List.txt",ios::in);
  if(!op)
    {
      cout << "\nFile Not Found!";
      cout << "\nError Code 100";
      cout << "\nProgram Aborting";
      throw(100);
    }
  while(!op.eof())
  {
    string UID,PWD;
    op >> UID;
    if(UID==USER_ID)
      {
	op.close();
	cout << endl << "This user ID has been taken, Please enter a new ID:";
	goto A1;
      }
  }
  op.close();
  cout << "\nUsername Is available";
  cout << "\nPlease Enter a password:";
  char c;
  while(c!=13)
    {
      c=(char)getch();
      if(c==13)
	break;
      if(c==8)
	continue;
      PASSWORD+=c;
      cout << "*";
    }
  cout << "\nEnter a user type:\n1.Admin\n2.Owner\n3.Accountant\n4.Receptionist\n5.Gym Client:";
  cin >> type;
  DD(USER_ID,PASSWORD,type);
  cout << endl;
  fstream op1("../Data/ID_List.txt",ios::out|ios::app);
  op1 << USER_ID << "\t" << PASSWORD << "\t" << type << "\n";
  op1.close();
}
void ListUsers()
{
  string UID,PWD;
  int t;
  fstream login("../Data/ID_List.txt",ios::in);
  if(!login)
    {
      cout << "\nFile Not Found!";
      cout << "\nError Code 100";
      cout << "\nProgram Aborting";
    }
  else
    {
      cout << "\n List of users registered:\n";
      while(true)
	{
	  login >> UID >> PWD >> t;
	  if(login.eof())
	    break;
	  DD(UID,PWD,t);
	  cout << endl;
	}
    }
  login.close();
}

int main()
{
  while(1)
    {
      cout << "\n--------------------Program Menu--------------------";
      cout << "\n--Choose an option:----";
      cout << "\n1. Register";
      //cout << "\n2. Login";
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
	  exit(0);
	}
    }
  return 0;
}
