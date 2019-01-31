/****************************************************************
   PROGRAM:    triangle.cpp

   CONTENTS:   the method code for the triangle method definitions

   NEEDS:      triangle.h, shape.h
****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "shape.h"
#include "triangle.h"

using namespace std;

/****************************************************************
   CONSTRUCTOR:	Triangle::Triangle(const string& colour, int Height, int Base) : Shape(colour)

   ARGUMENTS:	a const string reference to the color, an integer for height, and
		an integer for the base; called Shape constructor to set the color

   RETURNS:	nothing

   PURPOSE:	to set up the triangle object's specs
****************************************************************/
Triangle::Triangle(const string& colour, int Height, int Base) : Shape(colour)
{
        height = Height;
        base = Base;
}


/****************************************************************
   FUNCTION:    void Triangle::print() const

   ARGUMENTS:   none

   RETURNS:     nothing

   PURPOSE:     prints the triangle object specs
****************************************************************/
void Triangle::print() const
{
        Shape::print();		// call Shape::print() for the obj's color

        cout << " triangle, height " << height
        << ", base " << base <<  ", area "
        << get_area() << endl;
}


/****************************************************************
   FUNCTION:    double Triangle::get_area() const

   ARGUMENTS:   none

   RETURNS:     the area for a triangle

   PURPOSE:     to calculate the area of a triangle
****************************************************************/
double Triangle::get_area() const
{
        return (base*height)/2.00;
}
