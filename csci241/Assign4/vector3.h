#ifndef VECTOR3_H
#define VECTOR3_H

//*****************************************************************
// FILE:      Vector3.h
// AUTHOR:    William Freriks
// LOGON ID:  Z1698749
// DUE DATE:  3/20/15
//
// PURPOSE:   Contains the declarations for the Vector3 class.
//*****************************************************************
#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;



class Vector3
{

private:
        float array[3];		//Vector element array


public:
        Vector3();					//Default constructor
	Vector3(double, double, double);		//Vector constructor

							// OPERATOR CONSTRUCTS
							//Arithmitic overloads
	Vector3 operator+(const Vector3& ) const;
	Vector3 operator-(const Vector3& ) const;
							//Multiplication overloads
	float operator*(const Vector3& ) const;
        Vector3 operator*(const float) const;
	friend Vector3 operator*(double, const Vector3& );
							//Bracer overloads
	float operator [] (const int &) const;
	float & operator [] ( int);
							//Compare overload
	bool operator==(const Vector3&) const;

							//Output overload
	friend ostream &operator<< (ostream& , const Vector3& );
};


#endif
