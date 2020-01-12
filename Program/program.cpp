#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

string encryptDecrypt(string toEncrypt);
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
  fstream op("../Data/ID_List.bin",ios::in|ios::binary);
  if(!op)
    {
      cout << "\nFile Not Found!";
      cout << "\nError Code 100";
      cout << "\nProgram Aborting";
      exit(EXIT_FAILURE);
    }
  while(!op.eof())
  {
    string UID,PWD,a;
    op >> a;
    UID=encryptDecrypt(a);
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
  fstream op1("../Data/ID_List.bin",ios::out|ios::app|ios::binary);
  if(!op1)
  {
      cout << "\nFile Not Found!";
      cout << "\nError Code 100";
      cout << "\nProgram Aborting";
      exit(EXIT_FAILURE);
  }
  string enc_usrn, enc_pass;
  enc_usrn = encryptDecrypt(USER_ID);
  enc_pass = encryptDecrypt(PASSWORD);
  op1 << enc_usrn << "\t" << enc_pass << "\t" << type << "\n";
  op1.close();
}
void ListUsers()
{
  string UID,PWD,a;
  int t;
  fstream login("../Data/ID_List.bin",ios::in|ios::binary);
  if(!login)
    {
      cout << "\nFile Not Found!";
      cout << "\nError Code 100";
      cout << "\nProgram Aborting";
      exit(EXIT_FAILURE);
    }
  else
    {
      cout << "\n List of users registered:\n";
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
}

int main()
{
  while(1)
    {
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
