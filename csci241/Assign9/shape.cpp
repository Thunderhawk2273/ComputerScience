#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "shape.h"

using namespace std;



/****************************************************************
   CONSTRUCTOR:	Shape::Shape(const string& Colour)

   ARGUMENTS:	a const string reference

   RETURNS:	nothing

   PURPOSE:	to set the color of the shape object
****************************************************************/
Shape::Shape(const string& Colour)
{
        color = Colour;
}



/****************************************************************
   CONSTRUCTOR:	Shape::~Shape()

   ARGUMENTS:	none

   RETURNS:	nothing

   PURPOSE:	Destructor
****************************************************************/
Shape::~Shape()
{
}



/****************************************************************
   CONSTRUCTOR:	void Shape::print() const

   ARGUMENTS:	none

   RETURNS:	nothing

   PURPOSE:	prints out the color of the shape object
****************************************************************/
void Shape::print() const
{
        cout << color;
}


