#include<iostream>
#include<fstream>
using namespace std;
class node_emp{
	public:
		node_emp *left;
		node_emp *right;
		// string name,job_type,join_date,post,grade;
		string name,join_date,post,grade;

		int age,salary,pin,id;
		node_emp()
		{
			left=NULL;
			right=NULL;
			name='\0';
			// job_type='\0';
			join_date='\t';
			post='\t';
			age=0;
			salary=0;
			id='\0';
			grade='\0';
			pin=0;
		}
};
class BST_employee{
	public:
		// node_emp *insert_emp(node_emp *head,int salary,string name,string job_type,string join_date,string post,int age,int i_d,string grade,int pin)
		node_emp *insert_emp(node_emp *head,int salary,string name,string join_date,string post,int age,int i_d,string grade,int pin)

		{
			if(head==NULL)
			{
				head=new node_emp;
				head->left=NULL;
				head->right=NULL;
				head->salary=salary;
				head->name=name;
				head->age=age;
				head->post=post;
				// head->job_type=job_type;
				head->join_date=join_date;
				head->id=i_d;
				head->grade=grade;
				head->pin=pin;
			}
			else if(i_d < head->id)
			{
				// head->left=insert_emp(head->left,salary,name,job_type,join_date,post,age,i_d,grade,pin);
				head->left=insert_emp(head->left,salary,name,join_date,post,age,i_d,grade,pin);

			}
			else if(i_d > head->id)
			{
				// head->right=insert_emp(head->right,salary,name,job_type,join_date,post,age,i_d,grade,pin);
				head->right=insert_emp(head->right,salary,name,join_date,post,age,i_d,grade,pin);

			}
			return head;
		}
		node_emp *search(node_emp *head,int i_d)
		{
			if (head->id==i_d)
	    	{
	        	return head;
	    	}
	    	else if (i_d<head->id)
	    	{
	    	   	if (head->left==0)
	    	  		return 0;
	   		    else
	    	   		return search(head->left,i_d);
	   		}
	    	else if (i_d>head->id)
	    	{
	    	   	if (head->right==0)
	    	   		return 0;
	    	   	else
	    	   		return search(head->right,i_d);
	    	}
	    	else return 0;
		}
		node_emp *minimum(node_emp *temp)
		{
			if(temp==NULL)
			{
				return NULL;
			}
			else if(temp->left==NULL)
			{
				return temp;
			}
			else {
				return minimum(temp->left);
			}
		}
		node_emp *maximum(node_emp *temp)
		{
			if(temp==NULL)
			{
				return NULL;
			}
			else if(temp->right==NULL)
			{
				return temp;
			}
			else {
				return minimum(temp->right);
			}
		}
		void inorder(node_emp *head)
		{
			if(head!=NULL)
			{
				inorder(head->left);
				// cout<<head->id<<"\t   "<<head->name<<"\t   "<<head->age<<"\t   "<<head->post<<"\t   "<<head->grade<<"\t   "<<head->salary<<"\t   "<<head->job_type<<"\t\t   "<<head->join_date<<"\t   "<<head->pin<<endl;
				cout<<head->id<<"\t   "<<head->name<<"\t   "<<head->age<<"\t   "<<head->post<<"\t   "<<head->grade<<"\t   "<<head->salary<<"\t\t   "<<head->join_date<<"\t   "<<head->pin<<endl;

				inorder(head->right);
			}
		}
		void inorder_file(node_emp *head)
		{
			if(head!=NULL)
			{
				ofstream emp_file;
				emp_file.open("Employee.txt",ios::app|ios::out);
				// emp_file<<head->id<<"\t\t"<<head->name<<"\t\t"<<head->age<<"\t\t"<<head->post<<"\t\t"<<head->grade<<"\t\t"<<head->salary<<"\t\t"<<head->job_type<<"\t\t"<<head->join_date<<"\t\t"<<head->pin<<endl;
				emp_file<<head->id<<"\t\t"<<head->name<<"\t\t"<<head->age<<"\t\t"<<head->post<<"\t\t"<<head->grade<<"\t\t"<<head->salary<<"\t\t"<<"\t\t"<<head->join_date<<"\t\t"<<head->pin<<endl;

				emp_file.close();
				inorder(head->left);
				inorder(head->right);
				
			}
		}
		bool remove_emp(node_emp *head,int i_d,node_emp *prev)
		{
			if (head == 0)  // Node doesn't exist
				return false;
		
		else if (i_d < head->id)
		{
			return remove_emp(head->left, i_d, head);
		}
		
		else if (i_d > head->id)
		{
			return remove_emp(head->right, i_d, head);
		}
		
		else	// Node found
	    {
			if ((head->left == 0) && (head->right == 0)) // Node is a leaf
			{
				if (i_d < prev->id)
				prev->left = 0;
	            
				else
	            prev->right = 0;
			}
			
			// Node having one child
			else if (head->left == 0)  		// Node having only right child
			{
			    if (i_d>prev->id)
	                prev->right=head->right;
	            else
	                prev->left=head->right;
				return true;
			}
			else if (head->right == 0) 		// Node having only left child
			{
			    if (i_d>prev->id)
			        prev->right=head->left;
			    else
	                prev->left=head->right;
				return true;
			}
			// Node having two children
			else
			{
				node_emp *temp;
				temp = minimum(head->right);
				int v = temp->id;
				remove_emp(head->right, v, head);
				head->id = v;
				return true;
			}
			return true;
		}
		}
};
