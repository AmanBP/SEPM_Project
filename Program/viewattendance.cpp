#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

void ViewAttendance()
{
	fstream fin("../Data/Attendance.txt",ios::in|ios::binary);
	if(!fin)
	{
		cout << "/nAttendance file not found.";
		cout << "/nExiting Program";
		exit(EXIT_FAILURE);
	}
	cout << "/nAttendance:";
	cout 
}
