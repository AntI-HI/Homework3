#include "pch.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include "Rectangle.h"
#include "ComposedShape.h"
#define sqrt3 1.732050
#define PI 3.14159265
using namespace std;

Rectangle::Rectangle(){}

Rectangle::Rectangle(const int RECT_X, const int RECT_Y, const int WofRect, const int HofRect) {

	rect_x = RECT_X;
	rect_y = RECT_Y;
	Width = WofRect;
	Height = HofRect;

	TotalArea += getArea();
	TotalPerim += getPerim();	
}

int Rectangle::getX()const {

	return rect_x;
}

int Rectangle::getY()const {

	return rect_y;
}

void Rectangle::setShape(int MCWid, int MCHei) {

	Width = MCWid;
	Height = MCHei;
}

int Rectangle::getWidth()const {

	return Width;
}

int Rectangle::getHeight()const {

	return Height;
}

int Rectangle::getPerim()const {

	return 2 * (Height + Width);

}

int Rectangle::getArea()const {

	return Height * Width;

}

Rectangle Rectangle::operator++(int x) {

	Rectangle temp(*this);

	rect_x++;
	rect_y++;

	return temp;
}

Rectangle Rectangle::operator++() {

	Rectangle temp(*this);

	temp.rect_x = ++rect_x;
	temp.rect_y = ++rect_y;

	return temp;

}
Rectangle Rectangle::operator--(int x) {

	Rectangle temp(*this);

	rect_x--;
	rect_y--;

	return temp;
}
Rectangle Rectangle::operator--() {

	/*Rectangle temp(*this);

	temp.rect_x = ++rect_x;
	temp.rect_y = ++rect_y;

	return temp;*/

	rect_x++;
	rect_y++;

	return *this;
}

Rectangle Rectangle::operator+(double Number) {

	Rectangle temp(*this);

	temp.Width = (int)(Width + Number);
	temp.Height = (int)(Height + Number);

	return temp;

}
Rectangle Rectangle::operator-(double Number) {

	Rectangle temp(*this);

	temp.Width = (int)(static_cast<double>(Width) - Number);
	temp.Height = (int)(static_cast<double>(Height) - Number);

	return temp;

}

/*bool Rectangle::operator==(const Rectangle& rect2) {

	Rectangle rect1(*this);

	return rect1.getArea() == rect2.getArea();
}
bool Rectangle::operator==(const Triangle& tri) {

	Rectangle rect(*this);

	return rect.getArea() == tri.getArea();
}
bool Rectangle::operator==(const Circle& cir) {

	Rectangle rect(*this);

	return rect.getArea() == cir.getArea();
}

bool Rectangle::operator!=(const Rectangle& rect2) {

	Rectangle rect1(*this);

	return !(operator==(rect2));
}
bool Rectangle::operator!=(const Triangle& tri) {

	Rectangle rect(*this);

	return !(operator==(tri));
}
bool Rectangle::operator!=(const Circle& cir) {

	Rectangle rect(*this);

	return !(operator==(cir));
}*/

ostream& operator<<(ostream& stream, Rectangle& Rect) {		//Friend function

	stream << "<rect x=\"" << Rect.rect_x << "\"" << " y=\"" << Rect.rect_y << "\"" << " width=\"" << Rect.Width << "\"" << " height=\"" << Rect.Height << "\""" fill=\"green\" stroke=\"black\"/>" << endl;

	return stream;

}

int Rectangle::Total_Area() {

	return TotalArea;
}
int Rectangle::Total_Perim() {

	return TotalPerim;
}

void Rectangle::Draw() {

	fstream F;
	F.open("Shape.svg", ios::out | ios::in | ios::app);
	F.setf(ios::left);

	rect_x = 0;
	rect_y = 0;

	F << "<rect x=\"" << rect_x << "\"" << " y=\"" << rect_y << "\"" << " width=\"" << Width << "\"" << " height=\"" << Height << "\""" fill=\"green\" stroke=\"black\"/>" << endl;

}

int Rectangle::TotalPerim = 0;
int Rectangle::TotalArea = 0;

