#ifndef SHAPE_H
#define SHAPE_H

/****************************************************************
   PROGRAM:    shape.h

   CONTENTS:   shape method definitions
****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


class Shape
{
public:
	Shape(const string&);	//shape constructor - sets color to obj

	virtual ~Shape();		//Destructor
	virtual void print() const;		//print method
	virtual double get_area() const = 0;	//pure virtual method get_area

private:
	string color;		//object's color

};
#endif
