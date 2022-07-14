#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include <stdio.h>
#include<fstream>
#include<windows.h>
#include <iomanip>
#include "Accounts.h"
#include "User.h"
#include "Employee.h"
#include "validators.h"
using namespace std;

/*COORD line = {0,0};
void pos(int x, int y)		
{	
	line.X=x;						
	line.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),line);
}*/

class Bank
{
    public:
    Node *head= NULL;
    Node_User *head_user=NULL;
    BST accounts; 
    BST_User users;
    node_emp *head_emp=NULL;
    BST_employee bemp;
    
    int generate_account()		//Generating Random Numbers
    {
        int rand_no,check=0;
        srand(time(0));
        
        while(check!=-1)		//Re-Generate until unique Account No. is obtained..
        {
            rand_no= ((rand()%10000)+1);
            Node *temp=accounts.searchNode(head,rand_no);
            if(!temp)		
			{
				return rand_no;	//returns if account doesn't exist..
        	}
    	}
	}
	
    fstream account_file;
    fstream user_file;
    fstream emp_file1;
    
	void open_file()		//Opens both accounts and users file
    {
        account_file.open("account.txt",ios::in | ios::out| ios::app);
        user_file.open("user.txt",ios::in|ios::out| ios:: app);
        emp_file1.open("Employee.txt",ios::in|ios::out|ios::app);
    }
    
    void close_file()		//Closes both accounts and users file
    {
        account_file.close();
        user_file.close();
        emp_file1.close();
    }
    
    void display_information()			//Displays Accounts and Personal User Information
    {
        char choice='0';
        cout<<"1-Accounts Information\t2-Users Information"<<endl;
        cin>>choice;
        if (choice=='1')
        {
           //Accounts Information
            cout<<"Account No  || Balance  ||  Type ||  Currency  || Password"<<endl<<endl;
            accounts.inorder(head);
        }
        else if (choice=='2')
        {
           // Personal User Information
            cout<<"Acc No"<<"\t\t"<<"\t\t"<<"Phone"<<"\t\t\t"<<"Age"<<"\t\t"<<"Email"<<"\t\t"<<"Birth Date"<<"\t\t"<<"Name"<<endl<<endl;

            users.inorder(head_user);
        }
        else
        cout<<"Invalid Input"<<endl;
        system("pause");
    }

    // This method opens the new account and add it to both the BST and user and Accounts File
    void add_account()
    {
        int ba;// balance
        char ty;// type
        int pa;// Password
        int day,month,year;
        cout<<"---Add Account---"<<endl<<endl;
        a=generate_account(); // Call the method to generate unique account number
        cout<<"Account no is:"<<a<<endl;
        cout<<"Enter Password(4-digit number):";
        pa=getInput();
        // cin>>pa;

        // This check makes sure the password is a 4 digit number
        if (pa/1000<10 && pa/1000>=1)
            pass=pa;
            else
        {
            cout<<"Password must be a 4 digit number"<<endl;
            system("pause");
            return;
        }

       
        do{
        cout<<"Enter Full Name:";
        cin.ignore();
        getline(cin,na);
        if(na.length()<3){
       cout<<"Name should be greater than 2 characters"<<endl;
        }
        }while(na.length()<3);

        do{
        cout<<"Enter Phone number of format (03xxxxxxxxxx):";
        cin>>ph;

         if(!isMobnum(ph)){
         cout<<"Enter valid mobile number"<<endl;
         }

        }while(!isMobnum(ph));

        do{
        cout<<"Enter Age: ";
        cin>>age;
        if(stoi(age)<11){
         cout<<"Age must be greater than 10"<<endl;
        }
        }while(stoi(age)<11);

        do{
        cout<<"Enter email:";
        cin>>em;
        if(!isEmail(em)){
            cout<<"Enter valid email"<<endl;
        }
        }while(!isEmail(em));


       do{
        cout<<"Enter Date Of Birth of format (DD MM YYYY):";
        // cin>>b_d;
        cin>>day>>month>>year;
         if(!isValidDate(day,month,year)){
            cout<<"Enter valid date of birth"<<endl;
         }
       }while(!isValidDate(day,month,year));
        b_d=to_string(day)+"/"+to_string(month)+"/"+to_string(year);

       do{
        cout<<"Enter Balance:";
        cin>>ba;
        if (ba<100 || ba>10000){
           cout<<"Out of range balance (100-10000)"<<endl;
       }
       }while(ba<100 || ba>10000);
        b=ba;

        cout<<"Enter Type of Account(Enter s for Savings, c for Current and l for loan):";
        cin>>ty;

           do{
        //This check makes sure that the type of account is valid i.e. current, savings or loan
        if(!(ty=='s'||ty=='S'||ty=='C'||ty=='c'||ty=='L'||ty=='l'))
        {	
            cout<<"Invalid Account Type input"<<endl;
        }
           }while(!(ty=='s'||ty=='S'||ty=='C'||ty=='c'||ty=='L'||ty=='l'));
         t=ty;
     
		fstream account_file;
		fstream user_file;
		account_file.open("account.txt",ios::app|ios::out);
		user_file.open("user.txt",ios::app|ios::out);
        //Writing to the Account File
        if (account_file.is_open())
        {
           account_file.seekg(account_file.tellp());
           account_file<<"\n"<<a<<" "<<t<<" "<<b<<" "<<pass;

           account_file.seekg(account_file.tellp());
        }
        else
        cout<<"---Sorry, Could not open Accounts File---"<<endl<<endl;

        // Writing to User File
        if (user_file.is_open())
        {
           user_file.seekg(user_file.tellp());
         user_file<<"\n"<<a<<" "<<ph<<" "<<age<<" "<<em<<" "<<b_d<<" "<<na;

           user_file.seekg(user_file.tellp());
        }
        else
        cout<<"---Sorry, Could not open Users File---"<<endl<<endl;
        user_file.close();
        account_file.close();

        // Inserting to the Accounts BST
		if (head==0)
		{
		    // head=accounts.insert(0,a,b,t,cur,pass);
		    head=accounts.insert(0,a,b,t,pass);

		}
        else
        {
            accounts.insert(head,a,b,t,pass);

        }

        // Inserting to the User BST
		if (head_user==0)
		{
		    head_user=users.insert(0,a,na,ph,age,em,b_d);

		}
        else
		{
		    users.insert(head_user,a,na,ph,age,em,b_d);

		}
        system("pause");
    }
    
    
    //Accounts File Attributes
    int a; 
    float b; 
    char t; 
    int pass; 

    //Users File Attributes
    string na; 
    string ph; 
    string em; 
    string b_d; 
    string age;
    
    //This method updates the Account File
    void update_file(int account,int ba)
    {
        ifstream upd_acc("account.txt");
        ofstream temp_acc("temp_acc.txt");
        while (upd_acc.good())
        {

            upd_acc>>a>>t>>b>>pass;

            if (account!=a)
            {
                temp_acc<<"\n"<<a<<" "<<t<<" "<<b<<" "<<pass;

            }
            else
                temp_acc<<"\n"<<a<<" "<<t<<" "<<ba<<" "<<pass;

        }

        upd_acc.close();
        account_file.close();
        temp_acc.close();

        //Remove the Account File
        if( remove( "account.txt" ) != 0 )
        perror( "Error updating Accounts file" );

        // Rename to Account File
        int result=(rename("temp_acc.txt", "account.txt"));
        if ( result != 0 )
        perror( "Error renaming Accounts file" );

        account_file.open("account.txt",ios::in|ios::out|ios::app);
    }

    // Delete record from the User and the Account File
    void deleteFromFile(int del_a)
    {
        ifstream del_acc("account.txt");
        ifstream del_user("user.txt");
        ofstream temp_acc("temp_acc.txt");
        ofstream temp_user("temp_user.txt");

        while (del_acc.good())
        {
            del_acc>>a>>t>>b>>pass;

            if (a!=del_a)
            {
                temp_acc<<"\n"<<a<<" "<<t<<" "<<b<<" "<<" "<<pass;

            }
        }

        while (del_user.good())
        {
            del_user>>a>>ph>>em>>b_d;

            getline(del_user,na);
             if (a!=del_a)
             {
              
                 temp_user<<"\n"<<a<<" "<<" "<<ph<<" "<<age<<" "<<em<<" "<<b_d<<" "<<na;

             }
        }

        del_acc.close();
        del_user.close();
        account_file.close();
        user_file.close();
        temp_acc.close();
        temp_user.close();

         //remove account.txt;
		if( remove( "account.txt" ) != 0 )
		perror( "Error deleting Accounts file" );

         //remove user.txt;
		if( remove( "user.txt" ) != 0 )
		perror( "Error deleting User file" );

        //Renaming to account file
        int result=(rename("temp_acc.txt", "account.txt"));
		if ( result != 0)
		perror( "Error renaming Accounts file" );

        //Renaming to User File
        result=(rename("temp_user.txt", "user.txt"));
		if ( result != 0 )
		perror( "Error renaming User file" );

	    //open_file();
    }

    //Method to delete Account
    void delete_account(int account)
    {
        // Delete from BST
        bool check1= accounts.remove(head, account, 0); // deleting account
        bool check2=users.remove(head_user,account,0); // deleting user

		if (check1 && check2)
		{
		    cout << "Account Deleted Successfully" << endl;
		    deleteFromFile(account);// Calling method to delete from File
		}
		
        else
    	cout << "Not Found" << endl;
        system("pause");
    }

    // Method to check the login Account and password
    bool check_account(int account,int passcode)
    {

        Node *temp= accounts.searchNode(head, account);
        if (temp)
        {
			if (temp->password==passcode)
			return true;
        }
        return false;
    }

    bool check_accountNumber(int account){
         Node *temp= accounts.searchNode(head, account);
        if (temp)
        {
			return true;
        }
        return false;
    }

    //Method to Check The Balance
    void checkBalance(int account)
    {
        Node *temp= accounts.searchNode(head, account);

        cout<<"-------BALANCE-------"<<endl;
        cout<<"-------"<<temp->balance<<" "<<"-------"<<endl;

        system("pause");
    }

    // Method to withdraw money
    void withdraw(int account)
    {
        Node *temp=accounts.searchNode(head,account);
        int money;
        int ba;
    
        cout<<"-----WithDraw Money------"<<endl;
        cout<<"Enter the amount of Money to withdraw"<<endl;
        cin>>ba;
        // This check makes sure the money is greater than 0
        if (ba>0)
            money=ba;
        else
        {
            cout<<"Invalid Balance input"<<endl;
            system("pause");
            return;
        }

        // This check makes sure the type of account must be current to withdraw money
        // if  (temp->type=='c'|| temp->type=='C')
        // {
            if (money>temp->balance)  // withdraw amount shouldn't be greater than the amount in account
            {
                cout<<"Current Balance is not enough"<<endl;
              
                cout<<"Your Account balance is"<<temp->balance<<" "<<endl;

            }
            else
            {
                temp->balance=temp->balance-money;
                cout<<"Amount withdrawn is:"<<money<<endl;
                cout<<"Remaining Balance in the Account is: Rs."<<temp->balance<<" "<<endl;

                update_file(account,temp->balance);
            }
        // }
        // else
        // {
        //     cout<<"-------------------INVALID-----------------------"<<endl;
        //     cout<<"Account Type should be Current to withdraw balance"<<endl;
        //     cout<<"Your Account type is:"<<temp->type<<endl;
        // }
        system("pause");
    }

    //Method to deposit amount to the account
    void deposit(int account)
    {
        Node *temp=accounts.searchNode(head,account);
        int money;
        int balance;
        cout<<"-----Deposit Money------"<<endl;
        cout<<"Enter the amount of Money to deposit"<<endl;
        cin>>balance;
    
        if (balance>0)  //value should be greater than 0
        {
        	money=balance;	
		}
        
        else
        {
            cout<<"Invalid Balance input"<<endl;
            system("pause");
            return;
        }

        // This check makes sure the type of account must be current to withdraw money
        if  (temp->type=='c'||temp->type=='s'|| temp->type=='C'||temp->type=='S')
        {
            temp->balance=temp->balance + money;
            cout<<"Amount Deposit is:"<< money<< endl;
            cout<<"New Balance in the Account is: Rs."<<temp->balance<<" "<<endl;

            update_file(account,temp->balance);

        }
        else
        {
            cout<<"-------------------INVALID-----------------------"<<endl;
            cout<<"Account Type should be Current or Savings to deposit balance"<<endl;
            cout<<"Your Account type is:"<<temp->type<<endl;
        }
        system("pause");
    }

    void transfer(int account){
        int recieveAcc,flag=0;
 Node *rNode;
         cout<<"-----Transfer Money------"<<endl;

do{
      cout<<"Enter reciever account no: ";
            cin>>recieveAcc;
            if(recieveAcc==account){
                  cout<<"Accounts are same"<<endl;
            
             system("pause");
             return;
            }
       rNode=accounts.searchNode(head,recieveAcc);

        if(!rNode){
            cout<<"Account not found"<<endl;
            // cout<<"Enter any key to retry, 1 to exit";
            flag=1;
             system("pause");
        }

}while(!rNode);

if(flag==1){
    return;
}

 Node *temp=accounts.searchNode(head,account);
        int money;
        int ba;
    
    do{
      
        cout<<"Enter the amount to transer"<<endl;
        cin>>ba;
        // This check makes sure the money is greater than 0
        if (ba>0)
            money=ba;
        else
        {
            cout<<"Invalid Balance input"<<endl;
            system("pause");
            return;
        }

        // This check makes sure the type of account must be current to withdraw money
        // if  (temp->type=='c'|| temp->type=='C')
        // {
            if (money>temp->balance)  // withdraw amount shouldn't be greater than the amount in account
            {
                cout<<"Current Balance is not enough"<<endl;
              
                cout<<"Your Account balance is"<<temp->balance<<" "<<endl;
            }
    }while(money>temp->balance);

  system("pause");
    //sender acc
                temp->balance=temp->balance-money;
                cout<<"Amount withdrawn from acc no. "<<account<<" is: Rs. "<<money<<endl;
                cout<<"Remaining Balance in the Account is:"<<temp->balance<<" "<<endl;
                update_file(account,temp->balance);
  system("pause");
    //reciever acc
            rNode->balance=rNode->balance + money;
            cout<<"Amount Deposited on acc no. "<<recieveAcc<<" is: Rs. "<< money<< endl;
            cout<<"New Balance in the Account is:"<<rNode->balance<<" "<<endl;

            update_file(recieveAcc,rNode->balance);

  system("pause");
          
    }

    //This method search a particular user/Account
    void search_account(int account)
    {
        char choice='0';
        cout<<"-----INQUIRY-----"<<endl;
        cout<<"1-Accounts Inquiry\t2-User Personal Information Inquiry"<<endl;
        cin>>choice;

        if (choice=='1')
        {
           //Accounts Information
            Node* check1= accounts.searchNode(head, account);			// search from accounts Information
            if (!check1)
            {
                cout<<"----Not Found----"<<endl;
            }
            else
            {
                cout<<"Account No  || Balance  ||  Type ||  Password"<<endl<<endl;

                cout << check1->acc <<"\t\t"<<check1->balance<<"\t    "<<check1->type<<"\t\t"<<"\t  "<<check1->password<<endl;

            }
        }
        
        else if (choice=='2')
        {
           // Personal User Information
            cout<<"Acc No"<<"\t\t"<<"\t\t"<<"Phone"<<"\t\t"<<"Age"<<"\t\t"<<"Email"<<"\t\t"<<"Birth Date"<<"\t\t"<<"Name"<<endl<<endl;

            bool check2=users.searchNode(head_user,account);// Search from Users Information
            
            if (!check2)
            {
            	cout<<"----Not Found----"<<endl;
			}   
        }
        else
        cout<<"Invalid Input"<<endl;
        system("pause");
    }

    void readFromFile()							  // This method reads from the Accounts File to BST for Account
    {
        if (account_file.is_open())
        {
            while(account_file.good())							// reaches the end of the file
            {
               account_file>>a>>t>>b>>pass;

               if (head==0)
               {
                  head=accounts.insert(0,a,b,t,pass);

               }
               else
                {
                    accounts.insert(head,a,b,t,pass);

                }
            }
        }
        else
            cout<<"---Sorry, Could not open File---"<<endl<<endl;
    }

    void readFromFileUser()			  // This method reads from the Users File to BST for Account
    {
       int a=0;
       string na;
       string ph;
       string age;
       string em;
       string b_d;
       
       if (user_file.is_open())
        {
            while(user_file.good())					// reaches the end of the file
            {
                user_file>>a>>ph>>age>>em>>b_d>>na;

                if (head_user==0)
                {
                    head_user=users.insert(0,a,na,ph,age,em,b_d);

                }
                else
                {
                   users.insert(head_user,a,na,ph,age,em,b_d);

                }
            }
        }
        else
            cout<<"---Sorry, Could not open File---"<<endl<<endl;
    }
    void read_from_employee_file()
    {
    	string nam,j_d,pst,grad;

		int ag,sal,pin_e,i_d;
		if (emp_file1.is_open())
        {
            while(emp_file1.good())					// reaches the end of the file
            {
               emp_file1>>i_d>>nam>>ag>>grad>>j_d>>pst>>sal>>pin_e;

                getline(emp_file1,na);
                if (head_emp==NULL)
                {
                   head_emp=bemp.insert_emp(NULL,sal,nam,j_d,pst,ag,i_d,grad,pin_e);

                }
                else
                {
                    bemp.insert_emp(head_emp,sal,nam,j_d,pst,ag,i_d,grad,pin_e);

                }
            }
        }
        else
        {
            cout<<"---Sorry, Could not open File---"<<endl<<endl;
        }
	}
	
	//Employee Attributes
	
	string namee;
	string jj_dd;
	string pstt;
	string gradd;
    
	
	int agee,sall,pinn,idd,day,month,year;
	int e;
    void add_employee()
    {
    	
    	string nam,j_d,pst,grad;
        int tpass;

		int ag,sal,pin_e,i_d;
   
 do{
nam.erase();
        cout<<"Enter Full Name:";
        // cin.ignore();
        // getline(cin,nam);
        cin>>nam;
        if(nam.length()<3){
       cout<<"Name should be greater than 2 characters"<<endl;
        }
        }while(nam.length()<3);

 do{
        cout<<"Enter Age: ";
        cin>>ag;
        if(ag<18){
         cout<<"Age must be greater than 18"<<endl;
        }
        }while(ag<18);



         do{
       cout<<"Enter Degree: ";
        cin.ignore();
        getline(cin,grad);
        if(grad.length()<2){
       cout<<"Enter valid degree"<<endl;
        }
        }while(grad.length()<2);

    	
    	// cout<<"Enter Join Date : ";
    	// cin>>j_d;


do{
        cout<<"Enter Join Date in format (DD MM YYYY):";
        // cin>>b_d;
        cin>>day>>month>>year;
         if(!isValidDate(day,month,year)){
            cout<<"Enter valid date"<<endl;
         }
       }while(!isValidDate(day,month,year));
        j_d=to_string(day)+"/"+to_string(month)+"/"+to_string(year);


    	// cout<<"Enter Post : ";
    	// cin>>pst;

         do{
        cout<<"Enter Post: ";
        cin.ignore();
        getline(cin,pst);
        if(pst.length()<3){
       cout<<"Enter valid post"<<endl;
        }
        }while(pst.length()<3);


        
    	// cout<<"Enter Salary : ";
    	// cin>>sal;

 do{
       cout<<"Enter Salary : ";
        // cin.ignore();
       cin>>sal;
        if(sal<5000){
       cout<<"Enter valid salary greater than 5000"<<endl;
        }
        }while(sal<5000);

    	// cout<<"Enter 4-Digit Pin : ";
    	// cin>>pin_e;

       do{
      cout<<"Enter 4-Digit Pin : ";
        // cin.ignore();
       tpass=getInput();

 if (!(tpass/1000<10 && tpass/1000>=1))
            cout<<"Password must be a 4 digit number"<<endl;
        

        }while(!(tpass/1000<10 && tpass/1000>=1));

        pin_e=tpass;


    	cout<<"Generating Identification...!!"<<endl<<"Please Wait..."<<endl;
    	i_d=generate_account();
    	Sleep(50);
		cout<<"Your Generated Id is : "<<i_d<<endl;
    	system("PAUSE");
    	//entering into a tree
    	if(head_emp==NULL)
    	{
    		head_emp=bemp.insert_emp(NULL,sal,nam,j_d,pst,ag,i_d,grad,pin_e);

		}
		else
		{
			bemp.insert_emp(head_emp,sal,nam,j_d,pst,ag,i_d,grad,pin_e);

		}
    	
    	//writing to a file
    	
    	ofstream emp_file;
    	emp_file.open("Employee.txt",ios::app | ios::out);
    	emp_file<<i_d<<"\t"<<nam<<"\t"<<ag<<"\t"<<grad<<"\t"<<j_d<<"\t"<<pst<<"\t"<<sal<<"\t"<<pin_e<<endl;

    	emp_file.close();
	}
	void show_all_employee()
	{
		cout<<"ID\t   Name\t\t   Age\t   Post\t   Grade   Salary\t   Job-type\t   Join-Date\t   Pin"<<endl;
		bemp.inorder(head_emp);
		system("PAUSE");
	}
	void search_employe()
	{
		int i_d,pin_e;
		cout<<"Enter id : ";
		cin>>i_d;

		node_emp *tem=bemp.search(head_emp,i_d);
		fflush(stdin);

			cout<<"Id"<<"\t\t"<<"Name"<<"\t\t"<<"Age"<<"\t\t"<<"Post"<<"\t\t"<<"Grade"<<"\t\t"<<"Salary"<<"\t"<<"Join-Date"<<"\t\t"<<"Pin\n";

			cout<<tem->id<<"\t\t"<<tem->name<<"\t\t"<<tem->age<<"\t\t"<<tem->post<<"\t\t"<<tem->grade<<"\t\t"<<tem->salary<<"\t\t"<<tem->join_date<<"\t\t"<<tem->pin<<endl;


		system("pause");
	}
	
	
	  void deleteFromEmpFile(int del_emp)
    {
        ifstream del_emp1("Employee.txt");
        ofstream temp_emp("temp_emp.txt");

        while (del_emp1.good())
        {
            del_emp1>>idd>>namee>>agee>>gradd>>jj_dd>>pstt>>sall>>pinn;

            if (idd!=del_emp)
            {
                temp_emp<<"\n"<<idd<<" "<<namee<<" "<<agee<<" "<<gradd<<" "<<jj_dd<<" "<<pstt<<" "<<sall<<" "<<pinn;

            }
        }


        del_emp1.close();
        emp_file1.close();
        temp_emp.close();

         //remove account.txt;
		if( remove( "Employee.txt" ) != 0 )
		perror( "Error deleting Accounts file" );

        //Renaming to account file
        int result=(rename("temp_emp.txt", "Employee.txt"));
		if ( result != 0)
		perror( "Error renaming Accounts file" );

	    //open_file();
    }
	
	 void delete_employee(int account)
    {
        // Delete from BST
        bool check1= bemp.remove_emp(head_emp, account, 0); // deleting employee
       
		if (check1)
		{
		    cout << "Account Deleted Successfully" << endl;
		    deleteFromEmpFile(account);// Calling method to delete from File
		}
		
        else
    	cout << "Not Found" << endl;
        system("pause");
    }
    
    
  
	
	

};

