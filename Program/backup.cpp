#include <windows.h>
#include <string>
#include <shlobj.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

static int CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg, LPARAM lParam, LPARAM lpData)
{

    if(uMsg == BFFM_INITIALIZED)
    {
         string tmp = (const char *) lpData;
         cout << "path: " << tmp <<  endl;
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
        //get the name of the folder and put it in path
        SHGetPathFromIDList ( pidl, path );

        //free memory used
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
    cout << "\nPlease choose a location to backup the data.\n";
    system("PAUSE");
    string path = BrowseFolder();
    cout << "\nCopying files\n";
    string p= "copy \"../Data/\" \"" + path + "\"";
    const char *command = p.c_str(); 
    system(command);
    cout << "\n Backups are at : " << path;
    cout << "\nReturning to menu\n";
    system("PAUSE");
}