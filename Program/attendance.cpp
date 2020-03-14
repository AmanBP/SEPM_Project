#include "../headers/sqlite3.h"
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string getString(char x) 
{ 
    string s(1, x);  
    return s;    
}

template <typename T>
std::string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
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
    string part2("(ID INT,pora CHARACTER(1));");
    rc = sqlite3_open("../Data/attendance.db", &db);
    if(rc)
        fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
    else
        fprintf(stdout, "\nOpened database successfully");
    sqlcommand = part1 + properdate + part2;
    char p[sqlcommand.length()];
    for (i = 0; i < sizeof(p); i++)
        p[i] = sqlcommand[i];
    cout << endl << p;
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

void insertdatetable(string a,int ID,char PorA)
{
    int i,rc;
    string properdate = getproperdate(a);
    char *zErrMsg = 0;
    sqlite3 *db;
    string sqlcommand;
    string part1( "INSERT INTO date_");
    string part2( "(ID,pora) VALUES(");
    string part3( ",'" );
    string part4( "');" );
    rc = sqlite3_open("../Data/attendance.db", &db);
    if(rc)
        fprintf(stderr, "\nCan't open database: %s\n", sqlite3_errmsg(db));
    else
        fprintf(stdout, "\nOpened database successfully");
    sqlcommand = part1 + properdate + part2 + NumberToString(ID) + part3 + getString(PorA) + part4;
    char p[sqlcommand.length()];
    for (i = 0; i < sizeof(p); i++)
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

void getattendanceofdate(string a)
{
    string properdate = getproperdate(a);
    int i,rc;
    sqlite3_stmt *stmt;
    sqlite3 *db;
    bool done = false;
    const unsigned char* text;
    long long int id;
    string sqlcommand;
    string part1("SELECT * FROM date_");
    sqlcommand = part1 + properdate;
    cout << endl << "\nHere are the attendances of " << a << ":\n";
    char p[sqlcommand.length()];
    for (i = 0; i < sizeof(p); i++)
        p[i] = sqlcommand[i];
    sqlite3_open("../Data/attendance.db",&db);
    sqlite3_prepare(db, p, sizeof(p), &stmt, NULL);
    while (!done) {
        switch (sqlite3_step (stmt)) {
        case SQLITE_ROW:
            id = sqlite3_column_int(stmt,0);
            text  = sqlite3_column_text(stmt, 1);
            printf ("ID: %lld was %s \n", id, text);
            break;

        case SQLITE_DONE:
            done = true;
            break;

        default:
            fprintf(stderr, "Failed.\n");
            break;
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}