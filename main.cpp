#include <iostream>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include "Menu.h"
using namespace std;

//Note: 
// the password for admin panel is 1234. 
// use full screen for better view

void loading()
{
	int i;
	char a=254;
	pos(70,26);
	cout<<"Loading please wait............!\n";
	pos(70,27);
	for(i=0;i<=35;i++)
	{
		cout<<a;
		Sleep(15);	
	}
	cout<<endl;
}
int main()
{
	//system("PAUSE");
	system("COLOR 1F");
	pos(75,20);
    cout<<"---------------------------------------------"<<endl;
    pos(75,21);
    cout<<"---------------------------------------------"<<endl;
    pos(75,22);
	cout<<"         BANK DATA MANAGEMENT SYSTEM         "<<endl;
	pos(75,23);   
    cout<<"---------------------------------------------"<<endl;
    pos(75,24);
	cout<<"---------------------------------------------"<<endl<<endl<<endl;
	Menu m;
	loading();
    m.load_file();
    m.menu();
    m.unload_file();
    return 0;
}
