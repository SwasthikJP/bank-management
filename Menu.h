#include <iostream>
#include <fstream> // For files
#include <string>
#include <stdio.h>
#include<windows.h>
#include "Bank.h"

using namespace std;
/*COORD line = {0,0};
void pos(int x, int y)		
{	
	line.X=x;						
	line.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),line);
}*/

// Class Menu

class Menu
{
    public:
    Bank bank;// object of the Bank Class

    // This calls the method to load the files and the BST
    void load_file()
    {
    	bank.open_file();
	    bank.readFromFile();
	    bank.readFromFileUser();
	    bank.read_from_employee_file();
    }

    // This calls the method to close files
    void unload_file()
    {
        bank.close_file();
    }

    //Menu Method for existing account
    void existing_account(int account,int passcode)
    {
        system("cls");
        char choice='a';//Initialized with some random character

        while(choice!='0')
        {
            system("cls");
            // pos(70,1);
            cout<<"---------------------------------------------"<<endl;
            // pos(70,2);
			cout<<"---------------------------------------------"<<endl;
            // pos(70,3);
			cout<<"                   USER                      "<<endl;
            // pos(70,4);
			cout<<"---------------------------------------------"<<endl;
            pos(70,5);
			cout<<"---------------------------------------------"<<endl;
            // pos(62,7);
			cout<<"1-Display Information"<<endl;
			pos(62,9);
			cout<<"2-Check Balance"<<endl;
			pos(62,11);
			cout<<"3-Withdraw Amount"<<endl;
			pos(62,13);
			cout<<"4-Deposit Amount"<<endl;
			pos(62,15);
			cout<<"5-Delete Account"<<endl;
			pos(62,17);
			cout<<"6-back"<<endl;
			pos(62,19);
			cout<<"Enter Choice:  ";
			pos(75,19);
            cin>>choice;
            switch(choice)
            {
                case '1':
                {
                    cout<<"Display Information"<<endl;
                    bank.search_account(account);
                    break;
                }
                case '2':
                {
                    cout<<"Check Balance"<<endl;
                    bank.checkBalance(account);
                    break;
                }
                case '3':
                {
                    cout<<"Withdraw Amount"<<endl;
                    bank.withdraw(account);
                    break;
                }
                case '4':
                {
                    cout<<"Deposit Amount"<<endl;
                    bank.deposit(account);
                    break;
                }
                case '5':
                {
                    char input;
                    cout<<"Delete Account"<<endl;
                    cout<<"Are you sure you want to delete account?\n1-Yes\t\t2-No"<<endl;
                    cin>>input;
                    if(input=='1')
                    {
                        bank.delete_account(account);
                        choice='0';
                    }
                    else if (input=='2')
                    {
                        cout<<"Cancelled!"<<endl;
                    }
                    else
                        cout<<"Invalid input"<<endl;
                    break;
                }
                case '6':
                {
                    cout<<"Back"<<endl;
                    choice='0';
                    system("cls");
                    break;
                }
                default:
                    cout<<"Invalid Input..Try Again"<<endl;
            }
        }
    }

    // method to login into existing account through password and account no
    void login_account()
    {
    	system("CLS");
        int account;
        int passcode;
        bool check;
        // pos(70,1);
        cout<<"---------------------------------------------"<<endl;
        // pos(70,2);
		cout<<"---------------------------------------------"<<endl;
        // pos(70,3);
		cout<<"             LOGIN INT0 ACCOUNT              "<<endl;
        // pos(70,4);
		cout<<"---------------------------------------------"<<endl;
        // pos(70,5);
		cout<<"---------------------------------------------"<<endl;
        // pos(62,7);
        cout<<"Enter Account no:"<<endl;
        pos(81,7);
        cin>>account;
        pos(62,9);
        cout<<"Enter Password:"<<endl;
        pos(76,9);
        cin>>passcode;
        
        check= bank.check_account(account,passcode); // calls method to confirm login
        
        if (check)
        {
        	existing_account(account,passcode);
		}     
        else
        {
          cout<<"Incorrect Account or Password.."<<endl;
          system("pause");
        }
    }

    void admin_Login(){
        system("CLS");
        int account;
        int passcode;
        bool check;
       
        cout<<"Enter Account no:"<<endl;
        cin>>account;
        pos(62,9);
        // cout<<"Enter Password:";
        // pos(76,9);
        // cin>>passcode;
        
        check= bank.check_accountNumber(account); // calls method to confirm login
        
        if (check)
        {
        	existing_account(account,passcode);
		}     
        else
        {
          cout<<"Incorrect Account or Password.."<<endl;
          system("pause");
        }
    }

    //Menu for User's Side
    void user()
    {
        char choice='a';// initialized with some random character
        while (choice!='0')
        {
			system("cls");
			// pos(70,1);
			// cout<<"---------------------------------------------"<<endl;
			// pos(70,2);
			// cout<<"---------------------------------------------"<<endl;
			// pos(70,3);
			cout<<"                   USER                      "<<endl;
			// pos(70,4);
			cout<<"---------------------------------------------"<<endl;
			// pos(70,5);
			cout<<"---------------------------------------------"<<endl;
			// pos(62,7);
			cout<<"1-Create an Account"<<endl;
			pos(62,9);
			cout<<"2-Existing Account"<<endl;
			pos(62,11);
			cout<<"3-Back"<<endl;
			pos(62,13);
			cout<<"4-Exit"<<endl;
			pos(62,15);
			cout<<"Enter Choice : ";
			pos(79,15);
			cin>>choice;
			
			switch(choice)
			{
				case '1':
				{
					system("CLS");
					// pos(70,1);
				    cout<<"---------------------------------------------"<<endl;
				    // pos(70,2);
					cout<<"---------------------------------------------"<<endl;
				    // pos(70,3);
					cout<<"               CREATE ACCOUNT                "<<endl;
				    // pos(70,4);
					cout<<"---------------------------------------------"<<endl;
				    // pos(70,5);
					cout<<"---------------------------------------------"<<endl;
				    bank.add_account();
				    break;
				}
				case '2':
				{
					system("CLS");
					// pos(70,1);
				    cout<<"---------------------------------------------"<<endl;
				    // pos(70,2);
					cout<<"---------------------------------------------"<<endl;
				    // pos(70,3);
					cout<<"               EXISTING ACCOUNT              "<<endl;
				    // pos(70,4);
					cout<<"---------------------------------------------"<<endl;
				    // pos(70,5);
					cout<<"---------------------------------------------"<<endl<<endl<<endl;
				    login_account();
				    break;
				}
				case '3':
				{
				    cout<<"Back"<<endl;
				    choice='0';
				    system("cls");
				    break;
				}
				case '4':
				{
				    exit(1);
				}
				default:
				{
				 cout<<"Invalid Input..Try Again"<<endl;
				 system("pause");
				}
			}
        }
    }

    // Menu for Admin's side
    void admin()
    {
        int account;
        int choice=99; //inialized with some random character
        while(choice!=0)
        {
            system("cls");
            // pos(70,0);
            cout<<"---------------------------------------------"<<endl;
            // pos(70,1);
			cout<<"---------------------------------------------"<<endl;
            // pos(70,2);
			cout<<"                  ADMIN                      "<<endl;
            // pos(70,3);
			cout<<"---------------------------------------------"<<endl;
            // pos(70,4);
			cout<<"---------------------------------------------"<<endl;
			// pos(62,6);
            cout<<"1-Customer"<<endl;
            pos(62,8);
			cout<<"2-Employee"<<endl;
			pos(62,10);
			cout<<"3-Back"<<endl;
			pos(62,12);
			cout<<"4-Exit"<<endl;
			
			cout<<"Enter Choice : ";
			pos(78,22);
            cin>>choice;
            switch(choice)
            {
                ////
                 case 1:
                 {
                  int ch1=99;
                  while(ch1!=0){
                system("CLS");
                	pos(70,0);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"         CUSTOMER DETAILS        "<<endl;
                    pos(70,3);
					cout<<"---------------------------------------------"<<endl;
                   	pos(70,4);
				    cout<<"---------------------------------------------"<<endl;

                     cout<<"1-Open new account"<<endl;
			        cout<<"2-Open existing account"<<endl;
			         cout<<"3-Search account"<<endl;
		           	cout<<"4-Display All accounts"<<endl;
		           	cout<<"5-Back"<<endl;
		           	cout<<"6-Exit"<<endl;
                    cout<<"Enter choice:";
                    cin>>ch1;

                    switch(ch1){
case 1:
                {
                	system("CLS");
                	pos(70,0);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"               REGISTER ACCOUNT              "<<endl;
                    pos(70,3);
					cout<<"---------------------------------------------"<<endl;
                   	pos(70,4);
				    cout<<"---------------------------------------------"<<endl;
                    bank.add_account();
                    break;
                }
                case 2:
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"               OPEN EXISTING ACCOUNT                "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    pos(62,7);
				
                    admin_Login();
                    break;
                }
                case 3:
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"               SEARCH ACCOUNT                "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    pos(62,7);
					cout<<"Enter the Account No to Search:";
                    pos(93,7);
					cin>>account;
                    bank.search_account(account);
                    break;
                }
                case 4:
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"       DISPLAY ALL THE ACCOUNTS/USER INFO    "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    bank.display_information();
                    break;
                }
                case 5:
                {
                    cout<<"Back"<<endl;
                    ch1=0;
                    system("cls");
                    break;
                }
                case 6:
                {
                   exit(1);
                }
                default:
                    {
                     cout<<"Invalid Input..Try Again"<<endl;
                     system("pause");
                    }
                    }
                     

                  }
                 }


                break;

                case 2:
                {
                int ch2=99;
                  while(ch2!=0){
                system("CLS");
                	pos(70,0);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"         EMPLOYEE DETAILS        "<<endl;
                    pos(70,3);
					cout<<"---------------------------------------------"<<endl;
                   	pos(70,4);
				    cout<<"---------------------------------------------"<<endl;

                    cout<<"1-Add new employee"<<endl;
			        cout<<"2-Remove an employee"<<endl;
			         cout<<"3-Search employee"<<endl;
		           	cout<<"4-Display all employees "<<endl;
		           	cout<<"5-Back"<<endl;
		           	cout<<"6-Exit"<<endl;
                    cout<<"Enter choice:";
                    cin>>ch2;

                    switch(ch2){

                case 1:
                 {
                	system("CLS");
                	  cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
					cout<<"           ADD EMPLOYEE               "<<endl;
                     cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
                   bank.add_employee();
                    break;
                }
                case 2:
                 {
                	system("CLS");
                	  cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
					cout<<"           DELETE EMPLOYEE               "<<endl;
                      cout<<"---------------------------------------------"<<endl;
                    pos(70,1);
					cout<<"---------------------------------------------"<<endl;
                cout<<"Enter Account Number: ";
                cin>>account;
                    bank.delete_employee(account);
                    break;
                }
                case 3:
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"            SEARCH EMPLOYEE                   "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    bank.search_employe();
                    break;
                }
                case 4:
                {
                	system("CLS");
                	pos(70,1);
                    cout<<"---------------------------------------------"<<endl;
                    pos(70,2);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,3);
					cout<<"           SHOW ALL EMPLOYEES                "<<endl;
                    pos(70,4);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,5);
					cout<<"---------------------------------------------"<<endl;
                    bank.show_all_employee();
                    break;
                }

                 case 5:
                {
                    cout<<"Back"<<endl;
                    ch2=0;
                    system("cls");
                    break;
                }
                case 6:
                {
                   exit(1);
                }

                default:
                    {
                     cout<<"Invalid Input..Try Again"<<endl;
                     system("pause");
                    }
                    }
                  }
                }
                break;


                case 3:
                {
                    cout<<"Back"<<endl;
                    choice=0;
                    system("cls");
                    break;
                }
                case 4:
                {
                   exit(1);
                }
                 default:
                    {
                     cout<<"Invalid Input..Try Again"<<endl;
                     system("pause");
                    }


                

            }
        }
    }
    
    void employee()
    {
    	system("CLS");
    	int choice;
    	pos(70,1);
    	cout<<"---------------------------------------------"<<endl;
        pos(70,2);
		cout<<"---------------------------------------------"<<endl;
        pos(70,3);
		cout<<"                  EMPLOYEE                   "<<endl;
        pos(70,4);
		cout<<"---------------------------------------------"<<endl;
        pos(70,5);
		cout<<"---------------------------------------------"<<endl;
        pos(62,7);
		cout<<"1. Add Employee";
		pos(62,9);
		cout<<"2. Search Employee";
		pos(62,11);
		cout<<"3. Delete Employee";
		pos(62,13);
		cout<<"4. Back";
        pos(62,15);
		cout<<"Enter Choice : ";
		pos(78,17);
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    		{
    			system("CLS");
    			pos(70,1);
    			cout<<"---------------------------------------------"<<endl;
            	pos(70,2);
				cout<<"---------------------------------------------"<<endl;
               	pos(70,3);
				cout<<"              REGISTER EMPLOYEE              "<<endl;
                pos(70,4);
				cout<<"---------------------------------------------"<<endl;
                pos(70,5);
				cout<<"---------------------------------------------"<<endl;
    			bank.add_employee();
    			break;
    		}
    		case 2:
    			bank.search_employe();
    			break;
    		case 3:
    			int account;
    			cout<<"Enter Account Number: ";
    			cin>>account;
    			bank.delete_employee(account);
    			break;
    		case 4:
    			menu();
    			break;
    		default:
    			cout<<"Wrong Entrance"<<endl;
    		
    	}
    	employee();
	}

    //Main Menu
    void menu()
    {
		system("cls");
        int pass_admin=1234;
        int pass;
        char choice='a';// Initialized with some random character
        while(choice!='0')
        {
        	// pos(70,5);
            // cout<<"---------------------------------------------"<<endl;
            // pos(70,6);
			cout<<"---------------------------------------------"<<endl;
            // pos(70,7);
			cout<<"                MAIN MENU                    "<<endl;
            // pos(70,8);
			cout<<"---------------------------------------------"<<endl;
            // pos(70,9);
			cout<<"---------------------------------------------"<<endl;
            // pos(62,12);
			cout<<"1-Admin"<<endl;
			pos(62,14);
			cout<<"2-Customer"<<endl;
			pos(62,16);
			// cout<<"3-Employee"<<endl;
			// pos(62,18);
			cout<<"3-Exit"<<endl;
			pos(62,20);
			cout<<"Enter Choice : ";
            cin>>choice;
            switch(choice)
            {
                case '1':
                {
                	pos(62,22);
                    cout<<"Enter the Password: "<<endl;
                    pos(83,22);
                    cin>>pass;
                    if(pass==pass_admin)
                    admin();
                    else
                    {
                       cout<<"----ERROR\nAccess Denied---"<<endl;
                       system("pause");
                       system("cls");
                    }
                    break;
                }
                case '2':
                {
                    user();
                    break;
                }
                // case '3':
                // {
                //     employee();
                //     break;
                // }
                case '3':
                {
                	system("CLS");
                	pos(70,20);
                	cout<<"---------------------------------------------"<<endl;
                    pos(70,21);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,22);
					cout<<"              HOPE TO SEE YOU SOON           "<<endl;
                	pos(70,23);
					cout<<"---------------------------------------------"<<endl;
                    pos(70,24);
					cout<<"---------------------------------------------"<<endl;
                    choice='0';
                    exit(0);
                    break;	
				}
                default:
                    cout<<"Invalid Input..Try Again"<<endl;
            }
        }

    }
};
