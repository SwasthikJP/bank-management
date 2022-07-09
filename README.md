# BankManagementSystem
The Bank Management System is a C++ console based application program that manages customer’s account in the Bank.The system provides access to the user to view account and user information, create or deactivate account, withdraw/deposit money into the account. The System has an admin that registers or deletes the user and has information about all the user’s and employees.


Problem Statement: 
The issue with the common bank management systems and other management systems is that they are generally inefficient. These management system uses arrays or linked list to store data. In arrays, when the index of the data to be searched is not known, it has the complexity of O (n) and thus it is very inefficient. Insertion and deletion operation are also very inefficient. Furthermore, in arrays, we need to know the size of array beforehand and there are high chances of memory loss especially in management systems when we do not have any idea about the size of the data. Linked lists resolves the issue of memory allocation but the search operation has still the complexity of O (n).

Problem Solution:
The solution to the problem is to use such a data structure that has faster insertion, deletion and search operation and there is no memory wastage issue. The choice of selection is Binary Search Tree (BST) having complexity of O (log n) for insertion, deletion and Search operation in the average case. BST uses linked list and hence there is no memory wastage. We are opting Binary Search Tree (BST) because the code is short and simpler to write, easier to understand and hence easier to debug.
"# bank-management" 
