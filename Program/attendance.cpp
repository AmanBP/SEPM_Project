#include "../dependencies/sqlite3.h"
#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

std::string encryptDecrypt(string toEncrypt);
void makemenuheader(string a);

string getString(char x) 
{ 
    string s(1, x);  
    return s;    
}

string getproperdate(string a)
{
    string properdate("");
    int i,j,k=0;
    char bad_chars[] = {'-','_','\\','/'};
    for(i=0; i< a.size();i++)
    {
        int found = 0;
        for(j=0;j<4;j++)
        {    
            if(a[i] == bad_chars[j])
            {
                found =1;
                break;
            }
        }    
        if(!found)
            properdate += a[i];
    }
    return properdate;
}

void createdatetable(string a)
{
    string properdate = getproperdate(a);
    int i,rc;
    char *zErrMsg = 0;
    sqlite3 *db;
    string sqlcommand;
    string part1("CREATE TABLE date_");
    string part2("(ID VARCHAR(100),pora CHARACTER(1));");
    rc = sqlite3_open("../Data/attendance.db", &db);
    if(rc)
        fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
    else
        fprintf(stdout, "\nOpened database successfully");
    sqlcommand = part1 + properdate + part2;
    char p[sqlcommand.length()];
    for (i = 0; i <sizeof(p)+1; i++)
        p[i] = sqlcommand[i];
    rc = sqlite3_exec(db, p, 0, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "\nSQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
        fprintf(stdout, "\nDate Entry Created Sussessfully\n");
    sqlite3_close(db);
}

void insertdatetable(string a,string name,char PorA)
{
    int i,rc;
    string properdate = getproperdate(a);
    char *zErrMsg = 0;
    sqlite3 *db;
    string sqlcommand;
    string part1( "INSERT INTO date_");
    string part2( "(ID,pora) VALUES('");
    string part3( "','");
    string part4( "');");
    rc = sqlite3_open("../Data/attendance.db", &db);
    if(rc)
        fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
    else
        fprintf(stdout, "\nOpened database successfully");
    sqlcommand = part1 + properdate + part2 + name + part3 + getString(PorA) + part4;
    char p[sqlcommand.length()];
    for (i = 0; i < sizeof(p)+1; i++)
        p[i] = sqlcommand[i];
    rc = sqlite3_exec(db, p, 0, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "\nSQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
        fprintf(stdout, "\nAttendance has been logged");
    sqlite3_close(db);
}

bool checkiftableexists(string date)
{
    bool res;
    date = getproperdate(date);
    string part1("SELECT count(*) FROM sqlite_master WHERE type='table' AND name='date_");
    string part3("'");
    string command;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int i,rc,output;
    command = part1 + date + part3;
    char p[command.length()];
    for (i = 0; i < sizeof(p)+1; i++)
        p[i] = command[i];
    rc = sqlite3_open("../Data/attendance.db", &db);
    if(rc)
        fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
    else
        fprintf(stdout, "\nOpened database successfully");
    sqlite3_prepare(db, p, sizeof(p), &stmt, NULL);
    bool done = false;
    while (!done) 
    {
        switch (sqlite3_step (stmt)) 
        {
            case SQLITE_ROW:
                output = sqlite3_column_int(stmt,0);
                break;

            case SQLITE_DONE:
                done = true;
                break;

            default:
                cout << "\nFailed.";
                break;
        }
    }
    if(output == 0)
        return false;
    else
        return true;
}
void getattendanceofdate(string a)
{
    string properdate = getproperdate(a);
    int i,rc;
    sqlite3_stmt *stmt;
    sqlite3 *db;
    bool done = false;
    const unsigned char *text, *id;
    string sqlcommand;
    string part1("SELECT * FROM date_");
    sqlcommand = part1 + properdate;
    cout << endl << "\nHere are the attendances of " << a << ":\n";
    char p[sqlcommand.length()];
    for (i = 0; i < sizeof(p)+1; i++)
        p[i] = sqlcommand[i];
    rc = sqlite3_open("../Data/attendance.db", &db);
    if(rc)
        fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
    else
        fprintf(stdout, "\nOpened database successfully\n");;
    sqlite3_prepare(db, p, sizeof(p), &stmt, NULL);
    while (!done) {
        switch (sqlite3_step (stmt)) {
        case SQLITE_ROW:
            id = sqlite3_column_text(stmt,0);
            text  = sqlite3_column_text(stmt, 1);
            printf ("%s was %s \n", id, text);
            break;

        case SQLITE_DONE:
            done = true;
            break;

        default:
            cout << "\nFailed.";
            break;
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void AttendanceHandler()
{
    string date,a,b,c,uname;
    int choice;
    char PorA;  
    while(true)
    {
        topattendance:
        system("CLS");
        makemenuheader("          Attendance Menu          ");
		cout << "1. Create Entry of a date";
        cout << "\n2. Insert attendance into a date";
        cout << "\n3. View Attendance of a date";
        cout << "\n4. Check if date entry exists";
        cout << "\n5. Back";
        cout << "\nEnter a choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                    cout << "\nPlease enter a date in (DD MM YYYY format, braces allowed are ('_','-','\\','/')):";
                    cin >> date;
                    cout << "\nCreating an Entry for :" << date;
                    createdatetable(date);
                    cout << "\n";
                    system("PAUSE");
                    break;

            case 2: 
                    cout << "\nPlease enter a date to enter attendance into:";
                    cin >> date;
                    bool exist;
                    exist = checkiftableexists(date);
                    if(exist)
                    {
                        cout << "\nDate Entry found";
                    }
                    else
                    {
                        cout << "\nDate Entry not found, want to create an entry?(y/n)";
                        char choose;
                        cin >> choose;
                        if(choose == 'y' || choose == 'Y')
                            createdatetable(date);
                        else                        
                        {   
                            cout << "\nReturning to attendance menu.";
                            system("PAUSE");
                            break;
                        }
                    }
                    cout << "\nPlease enter number of entries to be entered: ";
                    int num_entries;
                    cin >> num_entries;
                    for(int i = 0;i<num_entries;i++)
                    {   
                        tryagainuname:
                        int flag = 0;
                        fstream login("../Data/ID_List.txt",ios::in|ios::binary);
                        if(!login)
	                    {
	                        cout << "\nFile Not Found!";
                            cout << "\nError Code 100";
	                        cout << "\nProgram Aborting";
	                        exit(EXIT_FAILURE);
	                    }
                        else
                        {
                            cout << "\nEnter Username for Entry " << i+1 <<": ";
                            cin >> uname;
                            while(login >> a >> b >> c)
		                    {
                                if(login.eof())
			                        break;
                                if(uname.compare(encryptDecrypt(a))==0)
                                {
                                    flag = 1;
                                    break;
                                }
                            }
                            if(flag == 1)
                            {
                                cout << "\nUsername was found in database, Please enter Present(P) or Absent(A):";
                                unamecheck:
                                cin >> PorA;
                                if(PorA =='P' || PorA =='A')
                                {
                                    insertdatetable(date,uname,PorA);
                                    cout << "\nData has been entered.";
                                }
                                else
                                {
                                    cout << "\nP or A ONLY!\n";
                                    goto unamecheck;
                                }                    
                            }
                            else
                            {
                                cout << "\nUsername not found, Please Try Again!";
                                login.close();
                                goto tryagainuname;                                    
                            }
                        }
                    }
                    cout << endl;
                    system("PAUSE");
                    break;

            case 3: 
                    cout << "\nPlease enter a date to print all attendance of that date (DD MM YYYY format, braces allowed are ('_','-','\\','/')):";
                    cin >> date;
                    getattendanceofdate(date);
                    system("PAUSE");
                    break;
            
            case 4:
                    cout << "\nEnter a Date to check: ";
                    cin >> date;
                    if(checkiftableexists(date))
                        cout << "\n" << date << " entry found\n"; 
                    else
                        cout << "\n" << date << " entry does'nt exist\n";
                    system("PAUSE");
                    break;
            
            case 5:
                    return;
            default:
                    cout << "\nWrong choice entered!!";
                    system("PAUSE");
                    break;
        }
   }
}