#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

void VRates();
void EnterFunds(string uid);


void Fees(string uid)
{
    int choice = 0;
    while(true)
    {
        system("CLS");
        cout << setw(80) << setfill('-') <<"-\n";
        cout << "|" << setw(39) << setfill(' ') <<"Fees Menu";
        cout << setw(40) << setfill(' ') << "|\n";
        cout << setw(79) << setfill('-') <<"-";
        cout << "\n1. Get Rates";
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