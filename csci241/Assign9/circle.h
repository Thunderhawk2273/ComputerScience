#ifndef CIRCLE_H
#define CIRCLE_H

/****************************************************************
   PROGRAM:    circle.h

   CONTENTS:   method definitions for the circle objects
****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Circle : public Shape	//class circle, derivitive of class Shape
{
public:
        Circle(const string&, int);	//Constructor

        virtual void print() const;	//print method
        virtual double get_area() const;//area calculator

private:
        int radius;			//circles need radius to calculate area
};
#endif
