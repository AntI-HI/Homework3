#include "pch.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include "Triangle.h"
#include "ComposedShape.h"
#define sqrt3 1.732050
#define PI 3.14159265
using namespace std;

Triangle::Triangle(){}

Triangle::Triangle(const int leng1_X, const int leng1_Y, const int leng2_X, const int leng2_Y, const int leng3_X, const int leng3_Y) {

	Lengt1_X = leng1_X;
	Lengt1_Y = leng1_Y;
	Lengt2_X = leng2_X;
	Lengt2_Y = leng2_Y;
	Lengt3_X = leng3_X;
	Lengt3_Y = leng3_Y;

	TotalArea += getArea();
	TotalPerim += getPerim();
}

void Triangle::setShape(int MCTriangle) {

	LofTri = MCTriangle;
}

int Triangle::getShape()const {

	return LofTri;
}

int Triangle::getLeng1_X()const {

	return Lengt1_X;
}

int Triangle::getLeng1_Y()const {

	return Lengt1_Y;
}

int Triangle::getLeng2_X()const {

	return Lengt2_X;
}

int Triangle::getLeng2_Y()const {

	return Lengt2_Y;
}

int Triangle::getLeng3_X()const {

	return Lengt3_X;
}

int Triangle::getLeng3_Y()const {

	return Lengt3_Y;
}

double Triangle::getArea()const {

	return (LofTri * LofTri * sqrt3)/4.0;

}

int Triangle::getPerim()const {

	return 3 * LofTri;
}

Triangle Triangle::operator++(int x) {

	Triangle temp(*this);

	Lengt1_X++;
	Lengt1_Y++;
	Lengt2_X++;
	Lengt2_Y++;
	Lengt3_X++;
	Lengt3_Y++;

	return temp;
}

Triangle Triangle::operator++() {

	Triangle temp(*this);

	temp.Lengt1_X = ++Lengt1_X;
	temp.Lengt1_Y = ++Lengt1_Y;
	temp.Lengt2_X = ++Lengt2_X;
	temp.Lengt2_Y = ++Lengt2_Y;
	temp.Lengt3_X = ++Lengt3_X;
	temp.Lengt3_Y = ++Lengt3_Y;

	return temp;

}
Triangle Triangle::operator--(int x) {

	Triangle temp(*this);

	Lengt1_X--;
	Lengt1_Y--;
	Lengt2_X--;
	Lengt2_Y--;
	Lengt3_X--;
	Lengt3_Y--;

	return temp;
}
Triangle Triangle::operator--() {

	/*Triangle temp(*this);

	temp.getLeng1_X = --Lengt1_X;
	temp.getLeng1_Y = --Lengt1_Y;
	temp.getLeng2_X = --Lengt2_X;
	temp.getLeng2_Y = --Lengt2_Y;
	temp.getLeng3_X = --Lengt3_X;
	temp.getLeng3_Y = --Lengt3_Y;

	return temp;*/

	--Lengt1_X;
	--Lengt1_Y;
	--Lengt2_X;
	--Lengt2_Y;
	--Lengt3_X;
	--Lengt3_Y;

	return *this;
}

Triangle Triangle::operator+(double Number) {

	Triangle temp(*this);

	temp.LofTri = (int)(static_cast<double>(LofTri) + Number);

	return temp;

}
Triangle Triangle::operator-(double Number) {

	Triangle temp(*this);

	temp.LofTri = (int)(static_cast<double>(LofTri) - Number);

	return temp;
}

/*bool operator==(const Triangle& tri, const Rectangle& rect) {

	return tri.getArea() == rect.getArea();
}
bool operator==(const Triangle& tri1, const Triangle& tri2) {

	return tri1.getArea() == tri2.getArea();
}
bool operator==(const Triangle& tri, const Circle& cir) {

	return tri.getArea() == cir.getArea();
}

bool operator!=(const Triangle& tri, const Rectangle& rect) {

	return !(operator==(tri, rect));
}
bool operator!=(const Triangle& tri1, const Triangle& tri2) {

	return !(operator==(tri1, tri2));
}
bool operator!=(const Triangle& tri, const Circle& cir) {

	return !(operator==(tri, cir));
}*/

int Triangle::Total_Area() {

	return TotalArea;
}
int Triangle::Total_Perim() {

	return TotalPerim;
}

ostream& operator<<(ostream& stream, Triangle& Tri) {

	Tri.Lengt1_X = Tri.LofTri / 2;
	Tri.Lengt1_Y = 0;
	Tri.Lengt2_X = 0;
	Tri.Lengt2_Y = (int)(Tri.LofTri*sqrt3 / 2);
	Tri.Lengt3_X = Tri.LofTri;
	Tri.Lengt3_Y = (int)(Tri.LofTri*sqrt3 / 2);

	stream << "<polygon points=\"" << Tri.Lengt1_X << " " << Tri.Lengt1_Y << ", " << Tri.Lengt2_X << " " << Tri.Lengt2_Y << ", " << Tri.Lengt3_X << " " << Tri.Lengt3_Y << "\"" << " fill=\"green\"/>" << endl;

	return stream;
}

void Triangle::Draw() {

	fstream F;
	F.open("Shape.svg", ios::out | ios::in | ios::app);
	F.setf(ios::left);

	Lengt1_X = LofTri / 2;
	Lengt1_Y = 0;
	Lengt2_X = 0;
	Lengt2_Y = (int)(LofTri*sqrt3 / 2);
	Lengt3_X = LofTri;
	Lengt3_Y = (int)(LofTri*sqrt3 / 2);

	F << "<polygon points=\"" << Lengt1_X << " " << Lengt1_Y << ", " << Lengt2_X << " " << Lengt2_Y << ", " << Lengt3_X << " " << Lengt3_Y << "\"" << " fill=\"green\"/>" << endl;

}

int Triangle::TotalArea = 0;
int Triangle::TotalPerim = 0;
