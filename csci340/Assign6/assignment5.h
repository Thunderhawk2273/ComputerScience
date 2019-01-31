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


#endif
