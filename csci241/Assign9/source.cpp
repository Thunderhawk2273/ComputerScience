/*********************************************************************
   PROGRAM:    Application 9
   PROGRAMMER: William Freriks

   FUNCTION:   This program builds classes of colored shapes
		and prints out their dimensions.
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

//header files
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;


int main()
{
// need Shape* because of object addresses
	vector<Shape*> shapes;


// creating the shapes and putting them into the vector
	shapes.push_back(new Circle("red", 15));
	shapes.push_back(new Rectangle("blue", 12, 13));
	shapes.push_back(new Triangle("yellow", 24, 13));
	shapes.push_back(new Circle("magenta", 23));
	shapes.push_back(new Rectangle("cyan", 5, 15));
	shapes.push_back(new Triangle("gold", 3, 45));

//printing all shapes
	cout << "Printing all shapes...\n\n";

	for(unsigned int i = 0; i < shapes.size(); i++)
		shapes[i] -> print();


	cout << endl;
	cout << "Printing only triangles...\n\n";

//printing only triangles by using dynamic_cast to weed through vector data
	for(unsigned int y = 0; y < shapes.size(); y++)
	{
		Triangle *castPointer = dynamic_cast<Triangle *>(shapes[y]);

		if( castPointer != 0 )
		{
			shapes[y] -> print();
		}
	}


//time to delete data and free up space
	for(unsigned int a = 0; a < shapes.size(); a++)
	{
	Shape *ptr;

	ptr = shapes.back();

	shapes.pop_back();

	delete ptr;
	}


	cout << "End of file\n";
	return 0;
}
