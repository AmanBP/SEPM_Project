#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "../dependencies/TextTable.h"

using namespace std;
void makemenuheader(string a)
{
	TextTable t('-','|',' ');
	t.add(a);
	t.endOfRow();
	cout << t;
}
void printratetable(int ratedatamatrix[3][4])
{
    int i,j;

		/*
			A table that I wanted but couldnt make. F's in the chat.
			╔═════════════╦═══════╦══════════╦══════════════╗
			║ Some String 	  ║ false   ║             ║                  ║
			╠═════════════╬═══════╬══════════╬══════════════╣
			║                 ║         ║             ║         true     ║
		*/

	TextTable t('-','|','+');
	string tspan[5] = {"Fee Type\\Time Span","Monthly","3 Months","6 Months","12 Months"};
	string type[3] = {"Membership Fees","Gym Trainer Fees","Dietician Fees"};
	for(int i=0;i<5;i++)
        t.add(tspan[i]);
	t.endOfRow();

    for(i=0;i<3;i++)
    {
        t.add(type[i]);
        for(j=0;j<4;j++)
            t.add(to_string(ratedatamatrix[i][j]));
        t.endOfRow();
    }
	cout << "\nRates are as follows:\n";
    cout << t;
}

void CRates()
{
	A6:
	fstream fin;
	fin.open("../Data/rates.txt",ios::in);
	if(!fin)
	{
		cout << "\nFile not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
	}
	else
	{
		char b='y';
		int ratedatamatrix[3][4];
		while(b=='y'||b=='Y')
		{
			system("CLS");
			int i,j;
			for(i=0;i<3;i++)
				for(j=0;j<4;j++)
					fin >> ratedatamatrix[i][j];
			printratetable(ratedatamatrix);
			cout << "\n\n1.Membership Fees\n2.Gym Trainer Fees\n3.Dietician Rate";
			cout << "\nWhich Rate would you like to change? :";
			int ch,a;
			cin >> ch;
			int rownum = ch-1,colnum;
			switch(ch)
			{
				case 1:
					B1:
					cout << "\nYou have choosen to edit Gym Membership Fees.";
					cout << "\n1.Monthly\n2.3 Months\n3.6 Months\n4.Annually\nWhich Time Span would you like to edit?";
					cin >> a;
					colnum = a-1;
					switch(a)
					{
						case 1:
							cout << "\n\nCurrent MONTHLY Membership Fees is : " << ratedatamatrix[rownum][colnum];
							cout << "\nEnter new MONTHLY Membership Fees : ";
							cin >> ratedatamatrix[rownum][colnum];
							break;
						case 2:
							cout << "\n\nCurrent 3-MONTH Membership Fees is : " << ratedatamatrix[rownum][colnum];
							cout << "\nEnter new 3-MONTH Membership Fees : ";
							cin >> ratedatamatrix[rownum][colnum];
							break;
						case 3:
							cout << "\n\nCurrent 6-MONTH Membership Fees is : " << ratedatamatrix[rownum][colnum];
							cout << "\nEnter new 6-MONTH Membership Fees : ";
							cin >> ratedatamatrix[rownum][colnum];
							break;
						case 4:
							cout << "\n\nCurrent 12-MONTH Membership Fees is : " << ratedatamatrix[rownum][colnum];
							cout << "\nEnter new 12-MONTH Membership Fees : ";
							cin >> ratedatamatrix[rownum][colnum];
							break;
						default:
							cout << "\nSorry! The option you chose isnt in the list above.\nPlease Retry: ";
							goto B1;
							break;
					}	
					break;
				case 2:
					B2:
					cout << "\nYou have choosen to edit Gym Trainer Rate.";
					cout << "\n1.Monthly\n2.3 Months\n3.6 Months\n4.Annually\nWhich Time Span would you like to edit?";
					cin >> a;
					colnum = a-1;
					switch(a)
					{
						case 1:
                            cout << "\n\nCurrent MONTHLY Gym Trainer Fees is : " << ratedatamatrix[rownum][colnum];
                            cout << "\nEnter new MONTHLY Gym Trainer Fees : ";
                            cin >> ratedatamatrix[rownum][colnum];
                            break;
						case 2:
                            cout << "\n\nCurrent 3-MONTH Gym Trainer Fees is : " << ratedatamatrix[rownum][colnum];
                            cout << "\nEnter new 3-MONTH Gym Trainer Fees : ";
                            cin >> ratedatamatrix[rownum][colnum];
                            break;
						case 3:
                            cout << "\n\nCurrent 6-MONTH Gym Trainer Fees is : " << ratedatamatrix[rownum][colnum];
                            cout << "\nEnter new 6-MONTH Gym Trainer Fees : ";
                            cin >> ratedatamatrix[rownum][colnum];
                            break;
						case 4:
                            cout << "\n\nCurrent 12-MONTH Gym Trainer Fees is : " << ratedatamatrix[rownum][colnum];
                            cout << "\nEnter new 12-MONTH Gym Trainer Fees : ";
                            cin >> ratedatamatrix[rownum][colnum];
                            break;
						default:
							cout << "\nSorry! The option you chose isnt in the list above.\nPlease Retry: ";
                            goto B2;
							break;
					}
					break;
				case 3:
					B3:
                    cout << "\nYou have choosen to edit Dietician Rate.";
                    cout << "\n1.Monthly\n2.3 Months\n3.6 Months\n4.Annually\nWhich Time Span would you like to edit?";
					cin >> a;
					colnum = a-1;
					switch(a)
					{
						case 1:
								cout << "\n\nCurrent MONTHLY Dietician Fees is : " << ratedatamatrix[rownum][colnum];
								cout << "\nEnter new MONTHLY Dietician Fees : ";
								cin >> ratedatamatrix[rownum][colnum];
								break;
						case 2:
								cout << "\n\nCurrent 3-MONTH Dietician Fees is : " << ratedatamatrix[rownum][colnum];
								cout << "\nEnter new 3-MONTH Dietician Fees : ";
								cin >> ratedatamatrix[rownum][colnum];
								break;
						case 3:
								cout << "\n\nCurrent 6-MONTH Dietician Fees is : " << ratedatamatrix[rownum][colnum];
								cout << "\nEnter new 6-MONTH Dietician Fees : ";
								cin >> ratedatamatrix[rownum][colnum];
								break; 
						case 4:
								cout << "\n\nCurrent 12-MONTH Dietician Fees is : " << ratedatamatrix[rownum][colnum];
								cout << "\nEnter new 12-MONTH Dietician Fees : ";
								cin >> ratedatamatrix[rownum][colnum];
								break;
						default:
								cout << "\nSorry! The option you chose isnt in the list above.\nPlease Retry: ";
								goto B3;
								break;
					}
					break;
				default:
					cout << "\nWrong Choice Entered!!";
					break;
			}
			label1:
			fin.close();
			fin.open("../Data/rates.txt",ios::out);
			cout <<"\nWriting data to file.\n";
			for(i=0;i<3;i++)
				for(j=0;j<4;j++)
					fin << ratedatamatrix[i][j] << " ";
			fin.close();
			cout << "\nChange another rate?(y/n):";
			cin >> b;
		}
	}
	return;
}

void VRates()
{
	int i,j;
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
		int filevalue, ratedatamatrix[3][4];
		for(i=0;i<3;i++)
			for(j=0;j<4;j++)
				fin >> ratedatamatrix[i][j];
		fin.close();
		printratetable(ratedatamatrix);
		cout << "To return to menu : ";
		system("Pause");
		return;
	}
}

void RateHandler()
{
	while(true)
	{
		system("CLS");
		makemenuheader("          Rates Menu          ");
		cout << "1. View Rates";
		cout << "\n2. Change Rates";
		cout << "\n3. Back";
		cout << "\n:";
		int choice;
		cin >> choice;
		switch(choice)
		{
			case 1:
					VRates();
					break;

			case 2:
					CRates();
					break;

			case 3:
					return;
					break;
			
			default:
					cout << "\nWrong Option selected, Please Try Again\n";
					system("PAUSE");
					break;
		}
	}
}
