/*
 * Rectangle.h
 *
 *  Created on: Oct 27, 2018
 *      Author: gtucpp
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include<iostream>
#include"Triangle.h"
#include"Circle.h"
using namespace std;

class Rectangle {
private:
	
	int Width;			//Width Rectangle
	int Height;			//Height Rectangle
	int rect_x;			//Initial value of x coordinate Rectangle
	int rect_y;			//Initial value of y coordinat Rectangle
	static int TotalArea;
	static int TotalPerim;

public:

	Rectangle();
	Rectangle(const int, const int, const int, const int);

	void setShape(int, int);

	int getWidth()const;
	int getHeight()const;


	int getX()const;
	int getY()const;

	void Draw(); //Draws Main Container.

	int getPerim()const; //Perimeter of the Container Rectangle
	int getArea()const;	//Area of the Container Rectangle

	Rectangle operator++(int);
	Rectangle operator++();
	Rectangle operator--(int);
	Rectangle operator--();

	Rectangle operator+(double);
	Rectangle operator-(double);

	/*bool operator==(const Rectangle&);
	bool operator==(const Triangle&);
	bool operator==(const Circle&);

	bool operator!=(const Rectangle&);
	bool operator!=(const Triangle&);
	bool operator!=(const Circle&);*/

	friend ostream& operator<<(ostream&, Rectangle&);

	static int Total_Area();
	static int Total_Perim();

};


#endif /* RECTANGLE_H_ */
