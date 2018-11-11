#include "pch.h"
#include <iostream>
#include "ShapeElem.h"
#define sqrt3 1.732050
#define PI 3.14159265
using namespace std;

enum Shape { circle, rectangle, triangle };

ShapeElem::ShapeElem() {}
ShapeElem::ShapeElem(Circle& Cir) {

	shape = &Cir;
	Shp = circle;
}
ShapeElem::ShapeElem(Rectangle& Rect) {

	shape = &Rect;
	Shp = rectangle;
}
ShapeElem::ShapeElem(Triangle& Tri) {

	shape = &Tri;
	Shp = triangle;
}

void* ShapeElem::getShape()const {

	return shape;
}

double ShapeElem::getPerim(const Circle& Cir) {

	return Cir.Total_Perim();
}
int ShapeElem::getPerim(const Rectangle& Rect) {

	return Rect.Total_Perim();
}
int ShapeElem::getPerim(const Triangle& Tri) {

	return Tri.Total_Perim();
}

double ShapeElem::getArea(const Circle& Cir) {

	return Cir.Total_Area();
}
int ShapeElem::getArea(const Rectangle& Rect) {

	return Rect.Total_Area();
}
double ShapeElem::getArea(const Triangle& Tri) {

	return Tri.Total_Area();
}

ostream& operator<<(ostream &stream, ShapeElem& ShpElem) {

	if (ShpElem.Shp == circle) {

		void* shp = ShpElem.shape;

		Circle* Cir = static_cast<Circle*>(shp);

		stream << "<circle cx=\"" << Cir->getCX() << "\"" << " cy=\"" << Cir->getCY() << "\"" << " r=\"" << Cir->getShape() << "\"" << " fill=\"green\"/>" << endl;

	}
		
	else if (ShpElem.Shp == rectangle) {

		void* shp = ShpElem.shape;

		Rectangle* Rect = static_cast<Rectangle*>(shp);

		stream << "<rect x=\"" << Rect->getX() << "\"" << " y=\"" << Rect->getY() << "\"" << " width=\"" << Rect->getWidth() << "\"" << " height=\"" << Rect->getHeight() << "\""" fill=\"green\" stroke=\"black\"/>" << endl;

	}
		
	else if (ShpElem.Shp == triangle) {

		void* shp = ShpElem.shape;

		Triangle* Tri = static_cast<Triangle*>(shp);

		/*Tri->Lengt1_X = Tri->LofTri / 2;
		Tri->Lengt1_Y = 0;
		Tri->Lengt2_X = 0;
		Tri->Lengt2_Y = (int)(Tri->LofTri*sqrt3 / 2);
		Tri->Lengt3_X = Tri->LofTri;
		Tri->Lengt3_Y = (int)(Tri->LofTri*sqrt3 / 2);*/

		stream << "<polygon points=\"" << Tri->getLeng1_X() << " " << Tri->getLeng1_Y() << ", " << Tri->getLeng2_X() << " " << Tri->getLeng2_Y() << ", " << Tri->getLeng3_X() << " " << Tri->getLeng3_Y() << "\"" << " fill=\"green\"/>" << endl;
		
	}

	return stream;
}
