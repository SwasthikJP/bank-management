#include<iostream>
using namespace std;

class Node							// Node class for the Accounts
{
    public:	
    Node *left;
    Node *right;
    int acc;
    float balance;
    char type;
    int password;

    Node() // Default Constructor
    {
        left=0;
        right=0;
        acc=0;
        balance=0;
        type=0;
        password=0;
    }


    Node(int a, Node *l=0,Node *r=0,float b=0,char t=0,int pass=0) // Parametrized Constructor

    {
        left=l;
        right=r;
        acc=a;
        balance=b;
        type=t;
        password=pass;
    }
};

// Class Binary Search Tree for Accounts
class BST
{
public:

	bool isEmpty(Node *root) 
	{
		return root == NULL;
	}
	
	
	Node* insert(Node *root,int a,float b, char t,int pass)			// Method to insert Accounts to the BST

	{
		if (root == 0)
		{
			 root = new Node(a,0,0,b,t,pass);

		}
		else if (a < root->acc)
		{
			root->left = insert(root->left, a,b,t,pass);

		}
		else root->right = insert(root->right, a,b,t,pass);

		return root;	
	}
	
	void inorder(Node *n)			// Method to display data/Accounts from the BST in the Ascending order
	{
		if (n != 0)
		{
			inorder(n->left);
			cout << n->acc<<"\t\t"<<n->balance<<"\t    "<<n->type<<"\t\t"<<"\t  "<<n->password<<endl;

			inorder(n->right);
		}
	}
	
	
	Node* minNode(Node *n)			//Finding the minimum Node/Account
	{
		Node *current = n;
		if (!current->left == 0)
		{
			return	minNode(current->left);
		}
		
		else
		return current;
	}
	
	bool remove(Node *root, int a, Node *prev)  	// Method to delete account/Node from the binary search tree
	{
		if (root == 0)  // Node doesn't exist
		return false;
		
		else if (a < root->acc)
		{
			return remove(root->left, a, root);
		}
		
		else if (a>root->acc)
		{
			return remove(root->right, a, root);
		}
		
		else	// Node found
	    {
			if ((root->left == 0) && (root->right == 0)) // Node is a leaf
			{
				if (a < prev->acc)
				prev->left = 0;
	            
				else
	            prev->right = 0;
			}
			
			// Node having one child
			else if (root->left == 0)  		// Node having only right child
			{
			    if (a>prev->acc)
	                prev->right=root->right;
	            else
	                prev->left=root->right;
				return true;
			}
			else if (root->right == 0) 		// Node having only left child
			{
			    if (a>prev->acc)
			        prev->right=root->left;
			    else
	                prev->left=root->right;
				return true;
			}
			// Node having two children
			else
			{
				Node *temp;
				temp = minNode(root->right);
				int v = temp->acc;
				remove(root->right, v, root);
				root->acc = v;
				return true;
			}
			return true;
		}
	}
	
	// Method to search a particular account from the user
	Node* searchNode(Node *root, int a)
	{
	    if (root->acc==a)
	    {
	        return root;
	    }
	    else if (a<root->acc)
	    {
	       if (root->left==0)
	       return 0;
	       else
	       return searchNode(root->left,a);
	    }
	    else if (a>root->acc)
	    {
	       if (root->right==0)
	       return 0;
	       else
	       return searchNode(root->right,a);
	    }
	    else return 0;
	}
	  
};









