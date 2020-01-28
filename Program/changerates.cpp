#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

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
		while(b=='y'||b=='Y')
		{
			system("CLS");
			int mr,qr,hyr,yr;
			int drmr,gtrmr,drqr,gtrqr,gtrhyr,drhyr,dryr,gtryr;
			cout << "\nCurrent Rates are as follows:";
			cout << "\n   Type\\Time span\t\tMonthly\t\t3months\t\t6months\t\t12months";
			fin >> mr >> qr >> hyr >> yr >> gtrmr >> gtrqr >> gtrhyr >> gtryr >> drmr >> drqr >> drhyr >> dryr;
			cout << "\n   Membership Fees \t\t" << mr << "\t\t" <<  qr << "\t\t" << hyr << "\t\t" << yr;
			cout << "\n   Gym Trainer Fees\t\t" << gtrmr << "\t\t" << gtrqr << "\t\t" << gtrhyr << "\t\t" << gtryr;
			cout << "\n   Dietician Fees  \t\t" << drmr << "\t\t" << drqr << "\t\t" << drhyr << "\t\t" << dryr;
			cout << "\n\n1.Membership Fees\n2.Gym Trainer Fees\n3.Dietician Rate:";
			cout << "\nWhich Rate would you like to change?";
			int ch,a;
			cin >> ch;
			switch(ch)
			{
				case 1:
					B1:
					cout << "\nYou have choosen to edit Gym Membership Fees.";
					cout << "\n1.Monthly\n2.3 Months\n3.6 Months\n4.Annually\nWhich Time Span would you like to edit?";
					cin >> a;
					switch(a)
					{
						case 1:
							cout << "\n\nCurrent MONTHLY Membership Fees is : " << mr;
							cout << "\nEnter new MONTHLY Membership Fees : ";
							cin >> mr;
							break;
						case 2:
							cout << "\n\nCurrent 3-MONTH Membership Fees is : " << qr;
							cout << "\nEnter new 3-MONTH Membership Fees : ";
							cin >> qr;
							break;
						case 3:
							cout << "\n\nCurrent 6-MONTH Membership Fees is : " << hyr;
							cout << "\nEnter new 6-MONTH Membership Fees : ";
							cin >> hyr;
							break;
						case 4:
							cout << "\n\nCurrent 12-MONTH Membership Fees is : " << yr;
							cout << "\nEnter new 12-MONTH Membership Fees : ";
							cin >> yr;
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
					switch(a)
					{
						case 1:
                            cout << "\n\nCurrent MONTHLY Gym Trainer Fees is : " << gtrmr;
                            cout << "\nEnter new MONTHLY Gym Trainer Fees : ";
                            cin >> gtrmr;
                            break;
						case 2:
                            cout << "\n\nCurrent 3-MONTH Gym Trainer Fees is : " << gtrqr;
                            cout << "\nEnter new 3-MONTH Gym Trainer Fees : ";
                            cin >> gtrqr;
                            break;
						case 3:
                            cout << "\n\nCurrent 6-MONTH Gym Trainer Fees is : " << gtrhyr;
                            cout << "\nEnter new 6-MONTH Gym Trainer Fees : ";
                            cin >> gtrhyr;
                            break;
						case 4:
                            cout << "\n\nCurrent 12-MONTH Gym Trainer Fees is : " << gtryr;
                            cout << "\nEnter new 12-MONTH Gym Trainer Fees : ";
                            cin >> gtryr;
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
					switch(a)
					{
						case 1:
								cout << "\n\nCurrent MONTHLY Dietician Fees is : " << drmr;
								cout << "\nEnter new MONTHLY Dietician Fees : ";
								cin >> drmr;
								break;
						case 2:
								cout << "\n\nCurrent 3-MONTH Dietician Fees is : " << drqr;
								cout << "\nEnter new 3-MONTH Dietician Fees : ";
								cin >> drqr;
								break;
						case 3:
								cout << "\n\nCurrent 6-MONTH Dietician Fees is : " << drhyr;
								cout << "\nEnter new 6-MONTH Dietician Fees : ";
								cin >> drhyr;
								break; 
						case 4:
								cout << "\n\nCurrent 12-MONTH Dietician Fees is : " << dryr;
								cout << "\nEnter new 12-MONTH Dietician Fees : ";
								cin >> dryr;
								break;
						default:
								cout << "\nSorry! The option you chose isnt in the list above.\nPlease Retry: ";
								goto B3;
								break;
					}
					break;
			}
			fin.close();
			fin.open("../Data/rates.txt",ios::out);
			cout <<"\nWriting data to file.\n";
			fin << mr << " " << qr << " "  << hyr << " "  << yr << " "  << drmr << " "  << gtrmr << " "  << drqr << " "  << gtrqr << " "  << gtrhyr << " "  << drhyr << " "  << dryr << " "  << gtryr;
			fin.close();
			cout << "\nChange another rate?(Y/N///y/n):";
			cin >> b;
		}
	}
	return;
}
