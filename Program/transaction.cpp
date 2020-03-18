#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

string gettime()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string str(buffer);
    return str;
}

void EnterFunds(string uid)
{
    fstream fout;
    fout.open("../Data/transactions.txt",ios::out|ios::app);
    if(!fout)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    double bal;
    long long int amount;
    regetamount:
    cout << "\nEnter the amount you wish to add(no decimal value):";
    cin >> amount;
    ifstream fin;
    fin.open("../Data/funds.txt",ios::in);
    if(!fin)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    fin >> bal;
    fin.close();
    if(amount<0)
    {
        cout << "\nAmount cannot be negative.";
        goto regetamount;
    }
    bal += amount;
    printf("\nNew Balance is: Rs %.1lf",bal);
    cout << "\nWriting logs";
    ofstream f;
    f.open("../Data/funds.txt");
    if(!f)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    f << bal;
    f.close();
    fout << uid << " has added:  Rs " << amount << "\nNew Balance is:  Rs " << bal;
    fout << "\nTimestamp: " << gettime();
    cout << "\n";
    system("PAUSE");
    fout.close();
}

void TakeFunds(string uid)
{
    fstream fout;
    fout.open("../Data/transactions.txt",ios::out|ios::app|ios::binary);
    if(!fout)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    double bal;
    long long int amount;
    regetamount:
    cout << "\nEnter the amount you wish to deduct(no decimal value):";
    cin >> amount;
    ifstream fin;
    fin.open("../Data/funds.txt",ios::in);
    if(!fin)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    fin >> bal;
    fin.close();
    if(amount<0)
    {
        cout << "\nAmount cannot be negative.";
        goto regetamount;
    }
    if(amount > bal)
    {
        cout << "\nAmount exceeds current balance.";
        goto regetamount;
    }
    bal -= (float)amount;
    printf("\nNew Balance is: Rs %.1lf",bal);
    cout << "\nWriting logs";
    ofstream f;
    f.open("../Data/funds.txt");
    if(!f)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    f << bal;
    f.close();
    fout << uid << " has deducted: Rs " << amount << "\nNew Balance is:  Rs " << bal;
    fout << "\nTimestamp: " << gettime();
    cout << "\n";
    system("PAUSE");
    fout.close();
}

void ViewFunds(string uid)
{
    fstream fin,fout;
    fin.open("../Data/funds.txt",ios::in|ios::binary);
    fout.open("../Data/transactions.txt",ios::out|ios::app|ios::binary);
    if(!fin || !fout)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    double bal;
    fin >> bal;
    cout << "\nCurrently available funds are:  Rs " << bal;
    cout << "\nWriting logs";
    fout << uid << " has accessed balance.";
    fout << "\nTimestamp: " << gettime();
    cout << "\n";
    system("PAUSE");
    fin.close();
    fout.close();
}

void TransLogs(string uid)
{
    fstream fin;
    fin.open("../Data/transactions.txt",ios::in|ios::binary);
    if(!fin)
    {
        cout << "\nFile Not Found!";
		cout << "\nError Code 100";
		cout << "\nProgram Aborting";
		exit(EXIT_FAILURE);
    }
    string line;
    cout << "\nTransaction Logs untill now are:\n\n";
    while(getline(fin,line))
    {
        cout << line << "\n";
        if(fin.eof())
            break;
    }
    fin.close();
    system("PAUSE");
}

void Trans(string uid)
{
    int choice = 0;
    while(true)
    {
        system("CLS");
        cout << "\n-----------------------Transaction Menu--------------";
        cout << "\n1. Enter Funds";
        cout << "\n2. Take Funds";
        cout << "\n3. Check Transaction Logs";
        cout << "\n4. View Current Funds";
        cout << "\n5. Back to Previous Menu";
        cout << "\n:";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                    EnterFunds(uid);
                    break;
            case 2:
                    TakeFunds(uid);
                    break;
            case 3:
                    TransLogs(uid);
                    break;
            case 4:
                    ViewFunds(uid);
                    break;
            case 5:
                    return;
            default:
                    cout << "\nPlease choose a valid option:\n";
                    system("PAUSE");
                    break;
        }
    }
}