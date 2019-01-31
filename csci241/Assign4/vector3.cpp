//*****************************************************************
// FILE:      Vector3.cpp
// AUTHOR:    William Freriks
// LOGON ID:  Z1698749
// DUE DATE:  3/20/15
//
// PURPOSE:   Contains the C++ specific code for the Player.h file
//*****************************************************************


#include <iostream>
#include <iomanip>
#include <fstream>
#include "vector3.h"


//*****************************************************
//Constructor: Vector3::Vector3()
//
//Input:a default constructor
//
//Purpose:To create an object and set the array elements
//		to zero
//*****************************************************
Vector3::Vector3(){
	array[0]=0;
	array[1]=0;
	array[2]=0;
}


//*****************************************************
//Constructor: Vector3::Vector3(double x, double y, double z)
//
//Input: three double variables
//
//Purpose:To creat an object and set the array elements
//		equal to the input variables
//*****************************************************
Vector3::Vector3(double x, double y, double z){
	array[0]=x;
	array[1]=y;
	array[2]=z;
}


//***********************************************************
//Overload: ostream &operator<< (ostream& output, const Vector3& obj)
//
//Input(2): an outputStream reference to a variable, and a
//		const Vector3 reference to an object
//
//Purpose: To output the vector's elements in a specific way
//**********************************************************
ostream &operator<< (ostream& output, const Vector3& obj){

output << "(" <<obj.array[0] << ", " << obj.array[1] << ", " << obj.array[2] << ")";
			//^ What will be put into output
return output;
}



//***********************************************************
//Overload: Vector3 Vector3::operator+(const Vector3& obj) const
//
//Input: a const Vector3 reference to an object
//
//Purpose: to add two Vector3 objects into a temp obj
//**********************************************************
Vector3 Vector3::operator+(const Vector3& obj) const{

	Vector3 standin;	//Temporary object

        standin.array[0] = array[0] + obj.array[0];
	standin.array[1] = array[1] + obj.array[1];
	standin.array[2] = array[2] + obj.array[2];
				//Adding the two objects and placing those
				// values into the temporary object
return standin;			//Returning the Temp Obj
}


//***********************************************************
//Overload: Vector3 Vector3::operator-(const Vector3& obj) const
//
//Input: A const Vector3 object reference
//
//Purpose: To subtract two Vector3 obj's and put them into
//		a temporary obj
//**********************************************************
Vector3 Vector3::operator-(const Vector3& obj) const{
				//Repeat from above, different arithmitic
	Vector3 standin;

	standin.array[0] = array[0] - obj.array[0];
        standin.array[1] = array[1] - obj.array[1];
        standin.array[2] = array[2] - obj.array[2];

return standin;
}


//***********************************************************
//Overload: Vector3 Vector3::operator*(const float k) const
//
//Input: A float const named k
//
//Purpose: To multiply a vector obj and float const together
//**********************************************************
float Vector3::operator*(const Vector3& obj) const{

        Vector3 standin;

        standin.array[0] = array[0] * obj.array[0];
        standin.array[1] = array[1] * obj.array[1];
        standin.array[2] = array[2] * obj.array[2];
				// Adding the vector elements to have one scalar product
return standin.array[0] + standin.array[1] + standin.array[2];
}


//***********************************************************
//Overload: Vector3 Vector3::operator*(const float k) const
//
//Input: A float const named k
//
//Purpose: To multiply a vector obj and float const together
//**********************************************************
Vector3 Vector3::operator*(const float k) const{

	Vector3 standin;	//Repeat of addition overload

        standin.array[0] = array[0] * k;
        standin.array[1] = array[1] * k;
        standin.array[2] = array[2] * k;

return standin;
}



//***********************************************************
//Overload: Vector3 operator*(double k, const Vector3& obj)
//
//Input(2): a double named k, and a const Vector3 ref to an
//		obj
//
//Purpose:To create a temporary obj and multiply a const k
//		and a vector obj together
//**********************************************************
Vector3 operator*(double k, const Vector3& obj) {

        Vector3 standin;
				//Repeat of the above multiplication
        standin.array[0] = obj.array[0] * k;
        standin.array[1] = obj.array[1] * k;
        standin.array[2] = obj.array[2] * k;

return standin;
}


//***********************************************************
//Overload: float Vector3::operator[](const int & sub) const
//
//Input: An integer const reference named sub
//
//Purpose:To return the array subscripts' data
//**********************************************************
float Vector3::operator[](const int & sub) const{

return array[sub];
}


//*****************************************************
//Overload: float & Vector3::operator[](int sub)
//
//Input:an integer named sub
//
//Purpose:To return the array subscripts' data
//*****************************************************
float & Vector3::operator[](int sub) {

return array[sub];
}


//*************************************************************
//Overload: bool Vector3::operator==(const Vector3& obj) const
//
//Input:a Vector const reference to an object
//
//Purpose: To overload the == operator to compare two Vector3
//		objects
//*************************************************************
bool Vector3::operator==(const Vector3& obj) const{

	if (array[0] != obj.array[0])
		return 0;

        if (array[1] != obj.array[1])
                return 0;

        if (array[2] != obj.array[2])
                return 0;
				//Basically, if it doesn't work, return false

return 1;
				//If it does, return true
}

