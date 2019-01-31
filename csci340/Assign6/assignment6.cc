#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

//PUBLIC FUNCTIONS
void insert( int ){
	insert( Node*&, int );
}


bool search( int ){
	search( Node*&, int );
}


bool remove( int ){
	remove( Node*&, int );
}


void printLeftLeaves(){
	printLeftLeaves(Node*);
}


void sumAncestors(int, int&){
	sumAncestors( Node *, int, int& );
}


//PRIVATE FUNCTIONS
/***************************************************
Function: void insert( Node*&, int )

Arguments:

Purpose:
***************************************************/
void BST::insert( Node*& n, int value ){

	if(n == NULL){
		n = new Node;
		n->right = NULL;
		n->left = NULL;
		n->data = value;
	}

	else if (n->data < value)
		insert(n->right, value);

	else if (n->data > value)
		insert(n->left, value);

}

/***************************************************
Function: bool search( Node*&, int )

Arguments:

Purpose:
***************************************************/
bool search( Node*& n, int value){



}

/***************************************************
Function: bool remove( Node*&, int )

Arguments:

Purpose:
***************************************************/
bool remove( Node*& n, int value){
	if (n == NULL){
		cout << "Node does not exist.";
		return false;
	}

	else if (n->data > value)
		remove(n->left, x);

	else if (n->data < value)
		remove(n->right, x);


	else {


		if (n->left != NULL && n->right != NULL){
			ptr = ptr->right;
			val = ptr->right;
		}

		else if (n->left == NULL && n->right == NULL){
			remove
	
		}
	}

}

/***************************************************
Function: void printLeftLeaves(Node*)

Arguments:

Purpose:
***************************************************/
void printLeftLeaves(Node* n){

	if(n != NULL){
		if(n->left != NULL && n->left->left == NULL && n->left->right == NULL)
		cout << n->left->data << " ";
	}

	else
		printLeftLeaves(n->left);

	printLeftLeaves(n->right);
}

/***************************************************
Function: bool sumAncestors(Node*, int, int&)

Arguments:

Purpose:
***************************************************/
bool sumAncestors(Node*, int, int&){



}
