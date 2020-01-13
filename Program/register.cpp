#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <conio.h>
using namespace std;

void DD(string a, string b, int c);
string encryptDecrypt(string toEncrypt);


void Register()
{
  string PASSWORD,USER_ID;
  int type;
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
  cout << "\n\n\nEnter a user type:\n1.Admin\n2.Owner\n3.Accountant\n4.Receptionist\n5.Gym Staff\n6.Gym User\t:";
  cin >> type;
  enc_pass = encryptDecrypt(PASSWORD);
  DD(USER_ID,enc_pass,type);
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
  op1 << enc_usrn << "\t" << enc_pass << "\t" << type << "\n";
  op1.close();
  cout << "\nClearing screen and returning to menu, ";
  system("PAUSE");
}
