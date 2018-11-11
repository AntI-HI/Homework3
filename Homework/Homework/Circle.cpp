#include "pch.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include "Circle.h"
#include "ComposedShape.h"
#define sqrt3 1.732050
#define PI 3.14159265
using namespace std;

Circle::Circle(){}

Circle::Circle(int CX, int CY, int Rad) {

	cx = CX;
	cy = CY;
	Radius = Rad;

	TotalArea += getArea();
	TotalPerim += getPerim();
}

void Circle::setShape(int Rad) {

	Radius = Rad;
}

int Circle::getShape()const {

	return Radius;
}

int Circle::getCX()const {

	return cx;
}

int Circle::getCY()const {

	return cy;
}

double Circle::getPerim()const {

	return 2 * PI * Radius;

}

double Circle::getArea()const {

	return PI * Radius * Radius;

}

Circle Circle::operator++(int) {

	Circle temp(*this);

	cx++;
	cy++;

	return temp;
}
Circle Circle::operator++() {

	++cx;
	++cy;

	return *this;
}
Circle Circle::operator--(int) {

	Circle temp(*this);

	cx--;
	cy--;

	return temp;
}
Circle Circle::operator--() {

	--cx;
	--cy;

	return *this;
}

Circle Circle::operator+(double Number) {

	Circle temp(*this);

	temp.Radius = (int)(static_cast<double>(Radius) + Number);

	return temp;

}
Circle Circle::operator-(double Number) {

	Circle temp(*this);

	temp.Radius = (int)(static_cast<double>(Radius) - Number);

	return temp;
}

/*bool operator==(const Circle& cir, const Rectangle& rect) {

	return cir.getArea() == rect.getArea();
}
bool operator==(const Circle& cir, const Triangle& tri) {

	return cir.getArea() == tri.getArea();
}
bool operator==(const Circle& cir1, const Circle& cir2) {

	return cir1.getArea() == cir2.getArea();
}

bool operator!=(const Circle& cir, const Rectangle& rect) {

	return !(operator==(cir, rect));
}
bool operator!=(const Circle& cir, const Triangle& tri) {

	return !(operator==(cir, tri));
}
bool operator!=(const Circle& cir1, const Circle& cir2) {

	return !(operator==(cir1, cir2));
}*/

ostream& operator<<(ostream& stream, const Circle& Cir) {

	stream << "<circle cx=\"" << Cir.cx << "\"" << " cy=\"" << Cir.cy << "\"" << " r=\"" << Cir.Radius << "\"" << " fill=\"green\"/>" << endl;

	return stream;
}

int Circle::Total_Area() {

	return TotalArea;
}

int Circle::Total_Perim() {

	return TotalPerim;
}

void Circle::Draw() {

	fstream F;
	F.open("Shape.svg", ios::out | ios::in | ios::app);
	F.setf(ios::left);

	cx = Radius;
	cy = Radius;

	F << "<circle cx=\"" << cx << "\"" << " cy=\"" << cy << "\"" << " r=\"" << Radius << "\"" << " fill=\"green\"/>" << endl;

}

int Circle::TotalArea = 0;
int Circle::TotalPerim = 0;