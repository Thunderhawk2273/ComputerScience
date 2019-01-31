/****************************************************************
   FILE:  circle.cpp

   CONTENTS:holds method definitions for circle class

   NEEDS: circle.h, shape.h
****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "shape.h"
#include "circle.h"

using namespace std;


/****************************************************************
   CONSTRUCTOR: Circle::Circle(const string& colour, int rad) : Shape(colour)

   ARGUMENTS:   a const string reference to the color, and an integer
			for a radius

   RETURNS:     nothing

   PURPOSE:     to set the color and to set the radius
****************************************************************/
Circle::Circle(const string& colour, int rad) : Shape(colour)
{
        radius = rad;
}


/****************************************************************
   FUNCTION:    void Circle::print() const

   ARGUMENTS:   none

   RETURNS:     nothing

   PURPOSE:     to print out the specs for the circle object
****************************************************************/
void Circle::print() const
{
        Shape::print();

        cout << " circle, radius " << radius
                        << ", area " << get_area() << endl;
}


/****************************************************************
   FUNCTION:    double Circle::get_area() const

   ARGUMENTS:   none

   RETURNS:     the area of a circle

   PURPOSE:     to calculate the area of a circle
****************************************************************/
double Circle::get_area() const
{
        return radius*3.1415;
}

