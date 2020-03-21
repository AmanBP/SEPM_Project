#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

void VRates();
void EnterFunds(string uid);
void makemenuheader(string a);

void Fees(string uid)
{
    int choice = 0;
    while(true)
    {
        system("CLS");
        makemenuheader("          Fees Menu          ");
		cout << "1. Get Rates";
        cout << "\n2. Recieve Payment";
        cout << "\n3. Go Back";
        cout << "\n:";
        cin >> choice;
        switch(choice)
        {
            case 1:
                VRates();
                break;

            case 2:
                EnterFunds(uid);
                break;
            
            case 3:
                return;
                break;

            default:
                cout << "\nWrong Choice";
                system("PAUSE");
                break;
        }
    }
}