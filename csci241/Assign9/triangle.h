#ifndef TRIANGLE_H
#define TRIANGLE_H

/****************************************************************
   PROGRAM:    triangle.h

   CONTENTS:   triangle ethod definitions
****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "shape.h"

using namespace std;

class Triangle : public Shape	//class triangle, derivative of class Shape
{
public:
        Triangle(const string& , int, int);	//triangle constructor

        virtual void print() const;		//print method
        virtual double get_area() const;	//area calculator

private:
        int height;				//height and width for triangle
        int base;				// area calculation
};
#endif
