#include "assignment5.h"




//------------------------------------------------
// Do not modify this section of code
//------------------------------------------------
const int MAX_SIZE = 1000;
const int MAX_COUNT = 20;
const int WIDTH = 5;
const int ROW_SIZE = 5;
int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}
//--------------------------------------------
// End
//--------------------------------------------

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




//-------------------------------------------
// Do not modify this section of code
//-------------------------------------------
//#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);    
    for (int i=1; i<=MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );
    //mcount = rcount = 0;
    //for_each( v.begin(), v.end(), display );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
//---------------------------------
// End
//--------------------------------
