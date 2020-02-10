#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void VRates()
{
	fstream fin("../Data/rates.txt",ios::in);
	if(!fin)
	{
		cout << "\nFile not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("CLS");
		int mr,qr,hyr,yr;
		int drmr,gtrmr,drqr,gtrqr,gtrhyr,drhyr,dryr,gtryr;
		cout << "\nCurrent Rates are as follows:";
		cout << "\n   Type\\Time span\t\tMonthly\t\t3months\t\t6months\t\t12months";
		fin >> mr >> qr >> hyr >> yr >> gtrmr >> gtrqr >> gtrhyr >> gtryr >> drmr >> drqr >> drhyr >> dryr;
		cout << "\n   Membership Fees \t\t" << mr << "\t\t" <<  qr << "\t\t" << hyr << "\t\t" << yr;
		cout << "\n   Gym Trainer Fees\t\t" << gtrmr << "\t\t" << gtrqr << "\t\t" << gtrhyr << "\t\t" << gtryr;
		cout << "\n   Dietician Fees  \t\t" << drmr << "\t\t" << drqr << "\t\t" << drhyr << "\t\t" << dryr << endl;
		fin.close();
		cout << "To return to menu : ";
		system("Pause");
		return;
	}
}
