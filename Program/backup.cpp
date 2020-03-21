#include <windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void makemenuheader(string a);

static int CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg, LPARAM lParam, LPARAM lpData)
{

    if(uMsg == BFFM_INITIALIZED)
    {
         string tmp = (const char *) lpData;
        SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
    }
    return 0;
}

string BrowseFolder()
{
    TCHAR path[MAX_PATH];
    const char * path_param;

    BROWSEINFO bi = { 0 };
    bi.lpszTitle  = ("Browse for folder...");
    bi.ulFlags    = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
    bi.lpfn       = BrowseCallbackProc;
    bi.lParam     = (LPARAM) path_param;

    LPITEMIDLIST pidl = SHBrowseForFolder ( &bi );

    if ( pidl != 0 )
    {
        SHGetPathFromIDList ( pidl, path );
        IMalloc * imalloc = 0;
        if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
        {
            imalloc->Free ( pidl );
            imalloc->Release ( );
        }
        return path;
    }
    return "";
}

void Backup()
{
    system("CLS");
    makemenuheader ("                                BACKUP                             ");
    cout << "Please choose a location in the pop-up window to backup the data.\n";
    system("PAUSE");
    string path = BrowseFolder();
    cout << "\nCopying files\n";
    string p= "copy \"../Data/\" \"" + path + "\"";
    const char *command = p.c_str(); 
    system(command);
    cout << "\nBackups are at : " << path;
    cout << "\nReturning to menu\n";
    system("PAUSE");
}