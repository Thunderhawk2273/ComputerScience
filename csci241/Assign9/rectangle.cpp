/****************************************************************
   PROGRAM:    rectangle.cpp

   CONTENTS:   the method code for the rectangle class methods

   NEEDS:      reactangle.h, shape.h
****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "shape.h"
#include "rectangle.h"

using namespace std;


/****************************************************************
   CONSTRUCTOR:	Rectangle::Rectangle(const string& colour, int Height, int Width) : Shape(colour)

   ARGUMENTS:	a const string reference for color, an integer for height,
			and an integer for width

   RETURNS:	nothing

   PURPOSE:	to set up the rectangle object with its specs
****************************************************************/
Rectangle::Rectangle(const string& colour, int Height, int Width) : Shape(colour)
{
        height = Height;
        width = Width;
}


/****************************************************************
   FUNCTION:    void Rectangle::print() const

   ARGUMENTS:   none

   RETURNS:     nothing

   PURPOSE:     to print out the specs of the reactangle object
****************************************************************/
void Rectangle::print() const
{
        Shape::print();

        cout << " rectangle, height " << height
        << ", width " << width <<  ", area "
        << get_area() << endl;
}


/****************************************************************
   FUNCTION:    double Rectangle::get_area() const

   ARGUMENTS:   none

   RETURNS:     the area of the rectangle

   PURPOSE:     to calculate the area of the rectangle
****************************************************************/
double Rectangle::get_area() const
{
        return height*width;
}
