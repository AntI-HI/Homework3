#ifndef SHAPEELEM_H_
#define SHAPEELEM_H_
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

class ShapeElem{

private:

	void* shape;	
	
public:

	enum Shape { circle, rectangle, triangle };
	Shape Shp;

	ShapeElem();
	ShapeElem(Circle& Cir);
	ShapeElem(Rectangle& Rect);
	ShapeElem(Triangle& Tri);

	void* getShape()const;

	double getPerim(const Circle&);
	int getPerim(const Rectangle&);
	int getPerim(const Triangle&);

	double getArea(const Circle&);
	int getArea(const Rectangle&);
	double getArea(const Triangle&);

	friend ostream& operator<<(ostream& stream, ShapeElem& ShpElem);
	
};

#endif