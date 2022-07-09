#include <iostream>
#include <iomanip>
#include<windows.h>
using namespace std;
COORD line = {0,0};
void pos(int x, int y)		
{	
	// line.X=x;						
	// line.Y=y;
	// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),line);
}
// Class Node for the Users
class Node_User
{
    public:
    Node_User *left;
    Node_User *right;
    int acc;
    string name;
    // string cnic;
    string phone;
    string age;
    string email;
    string bdate;

    Node_User() // Default Constructor
    {
        left=0;
        right=0;
        acc=0;
        name='\0';
        // cnic='\0';
        phone='\0';
        age='\0';
        email='\0';
        bdate='\0';
    }
    // Parametrized Constructor
    // Node_User(int a, Node_User *l=0,Node_User *r=0,string na=0,string nic=0,string ph=0,string age=0,string em=0,string b_d=0)
    Node_User(int a, Node_User *l=0,Node_User *r=0,string na=0,string ph=0,string age=0,string em=0,string b_d=0)

    {
        left=l;
        right=r;
        acc=a;
        name=na;
        // cnic=nic;
        phone=ph;
        this->age=age;
        email=em;
        bdate=b_d;
    }
};


// Binary Search Tree Class For User
class BST_User
{
	public:

	bool isEmpty(Node_User *root) const
	{
		return root == NULL;
	}
    
    //Method to inset user personal information into the Binary Search Tree for users
	// Node_User* insert(Node_User *root,int a,string na,string nic,string ph,string age,string em,string b_d)
	Node_User* insert(Node_User *root,int a,string na,string ph,string age,string em,string b_d)

	{
		if (root == 0)
		{
			//  root = new Node_User(a,0,0,na,nic,ph,age,em,b_d);
			 root = new Node_User(a,0,0,na,ph,age,em,b_d);

		}
		else if (a < root->acc)
		{
			// root->left = insert (root->left,a,na,nic,ph,age,em,b_d);
			root->left = insert (root->left,a,na,ph,age,em,b_d);

		}
		// else root->right = insert(root->right,a,na,nic,ph,age,em,b_d);
		else root->right = insert(root->right,a,na,ph,age,em,b_d);

		return root;
	}
	
	// Method to display All the Users/Nodes in the Ascending order from the BST
	void inorder(Node_User *n)
	{
	
		if (n != 0)
		{
			inorder(n->left);
			// cout<<n->acc<<"\t\t"<<n->cnic<<"\t\t"<<n->phone<<"\t\t"<<n->age<<"\t\t"<<n->email<<"\t\t"<<n->bdate<<"\t\t"<<n->name<<endl;
			cout<<n->acc<<"\t\t"<<"\t\t"<<n->phone<<"\t\t"<<n->age<<"\t\t"<<n->email<<"\t\t"<<n->bdate<<"\t\t"<<n->name<<endl;
			
			inorder(n->right);
		}
	}
	
	// Method to search a Node form the BST for Users
	bool searchNode(Node_User *root, int a)
	{
	
	    if (root->acc==a)
	    {
	        // cout<<root->acc<<"\t\t"<<root->cnic<<"\t\t"<<root->phone<<"\t"<<root->age<<"\t\t"<<root->email<<"\t\t"<<root->bdate<<"\t\t"<<root->name<<endl;
	        cout<<root->acc<<"\t\t"<<"\t\t"<<root->phone<<"\t"<<root->age<<"\t\t"<<root->email<<"\t\t"<<root->bdate<<"\t\t"<<root->name<<endl;

			return true;
	    }
	    else if (a<root->acc)
	    {
	        if (root->left==0)
	           return false;
	        else
	        return searchNode(root->left,a);
	    }
	    else if (a>root->acc)
	    {
	        if (root->right==0)
	            return false;
	     	else
	    		return searchNode(root->right,a);
	    }
	    else return false;
	}
	
	// Method to remove the Node from the BST for Users
	bool remove(Node_User *root, int a, Node_User *prev)
	{
		if (root == 0) // Node doesn't exist
			return false;
		else if (a < root->acc)
		{
			return remove(root->left, a, root);
		}
		else if (a>root->acc)
		{
			return remove(root->right, a, root);
		}
		// Node Found
		else
	    {
			if ((root->left == 0) && (root->right == 0)) // Leaf Node
			{
				if (a < prev->acc)
	                prev->left = 0;
				else
	                prev->right = 0;
	
			}
			// Node having one child
			else if (root->left == 0) // Node having only right child
			{
				 if (a>prev->acc)
	                prev->right=root->right;
	             else
	                prev->left=root->right;
	            return true;
			}
			else if (root->right == 0) // Node having only left child
			{
			    if (a>prev->acc)
			        prev->right=root->left;
			    else
	                prev->left=root->right;
				return true;
			}
			else
			{
				Node_User *temp;
				temp = minNode(root->right);
				int v = temp->acc;
				remove(root->right, v, root);
				root->acc = v;
				return true;
			}
			return true;
		}
	}
	
	// Method to find the minimum node for BST of Users
	Node_User* minNode(Node_User *n)
	{
		Node_User *current = n;
		if (!current->left == 0)
		{
			return	minNode(current->left);	
		}	
		else
		return current;
	}
	
};










