#ifndef ASSIGNMENT5
#define ASSIGNMENT5


#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//Forward Declaration of binTree
class binTree;

//Definition of Node
class Node {
    public:

	friend class binTree;

	Node(int value){
		left = NULL;
		data = value;
		right = NULL;
	}

    private:
	int data;
	Node* left;
	Node* right;

};


class binTree {
    public:
        binTree();				// default constructor
        virtual void insert( int );		// inserts a node in tree
        unsigned height() const;		//returns height of tree
        unsigned size() const;			//returns size of tree
        void inorder( void(*)(int) );		//inorder traversal of tree
        void preorder( void(*)(int) );		//preorder traversal
        void postorder( void(*)(int) );		//postorder traversal

    protected:
        Node* root;				// root of tree

    private:
        void insert( Node*&, int );		// private verson of insert()
        unsigned height( Node* ) const;		// private verson of height()
        unsigned size( Node* ) const;		// private version of size()
	void inorder( Node*, void(*)(int) );	// private version of inorder()
	void preorder( Node*, void(*)(int) );	// private version of preorder()
	void postorder( Node*, void(*)(int) );	// private version of postorder()
};


//PUBLIC VERSIONS
binTree::binTree(){
	root = 0;
}


void binTree::insert( int value ){
	insert(root, value);
}


unsigned binTree::height() const{
	return height(root);
}


unsigned binTree::size() const{
	return size(root);
}


void binTree::inorder( void(*function)(int) ){
	inorder(root, function);
}


void binTree::preorder( void(*function)(int) ){
	preorder(root, function);
}


void binTree::postorder( void(*function)(int) ){
	postorder(root, function);
}


//PRIVATE FUNCTIONS

/***************************************************
Function: void binTree::insert( Node*& ptr, int val)

Arguments: a Node pointer reference, and an integer

Purpose: to insert a node into the binary tree
***************************************************/
void binTree::insert( Node*& ptr, int val){

	if( ptr == 0 )
		ptr = new Node( val );

	else {
		if( height(ptr->left) > height(ptr->right) )
			insert( ptr->right, val );
		else
			insert( ptr->left, val);
	}
}


/***************************************************
Function: unsigned binTree::height( Node* ptr) const

Arguments: a Node pointer

Purpose: to find the height of the tree
***************************************************/
unsigned binTree::height( Node* ptr) const{

	if (ptr == 0)
		return 0;

	else
		return 1+max(height(ptr->left), height(ptr->right));
}

/***************************************************
Function: unsigned binTree::size( Node* ptr) const

Arguments: a Node pointer

Purpose: to find the size of the binary tree
***************************************************/
unsigned binTree::size( Node* ptr) const{
	if (ptr == 0)
		return 0;

	else
		return 1+size(ptr->left)+size(ptr->right);

}

/***************************************************
Function: void binTree::inorder(Node* ptr, void(*function)(int))

Arguments: a Node pointer, and a pointer to a function (int)

Purpose: to find the integers in the order of "inorder"
***************************************************/
void binTree::inorder(Node* ptr, void(*function)(int)){

	if (ptr != NULL){
		inorder(ptr->left, function);
		function(ptr->data);
		inorder(ptr->right, function);
	}
}

/***************************************************
Function: void binTree::preorder(Node* ptr, void(*function)(int))

Arguments: a Node pointer, and a pointer to a function (int)

Purpose: to find things in the order of preorder
***************************************************/
void binTree::preorder(Node* ptr, void(*function)(int)){

        if (ptr != NULL){
                function(ptr->data);
                preorder(ptr->left, function);
                preorder(ptr->right, function);
        }
}

/***************************************************
Function: void binTree::postorder(Node* ptr, void(*function)(int))

Arguments: a Node pointer, and a pointer to a function (int)

Purpose: to get integers in post order
***************************************************/
void binTree::postorder(Node* ptr, void(*function)(int)){

        if (ptr != NULL){
                postorder(ptr->left, function);
                postorder(ptr->right, function);
                function(ptr->data);
        }
}


#endif
