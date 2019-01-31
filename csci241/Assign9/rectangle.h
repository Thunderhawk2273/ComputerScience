#ifndef RECTANGLE_H
#define RECTANGLE_H
/****************************************************************
   PROGRAM:    rectangle.h

   CONTENTS:   rectangle method definitions
****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
#include "shape.h"

using namespace std;

class Rectangle : public Shape	//class rectangle, derivative of class Shape
{
public:
        Rectangle(const string& , int, int);	//rectangle constructor

        virtual void print() const;		//print method
        virtual double get_area() const;	//area calculator

private:
        int height;				//height and width for rectangles
        int width;
};
#endif

