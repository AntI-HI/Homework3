/*
 * Circle.h
 *
 *  Created on: Oct 27, 2018
 *      Author: gtucpp
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include<iostream>
#include"Rectangle.h"
#include"Triangle.h"
using namespace std;

class Circle {

private:

	int Radius;	
	int cx;		//Center of x coordinate 
	int cy;		//Center of y coordinate 
	static int TotalArea;
	static int TotalPerim;

public:

	Circle();
	Circle(int, int, int);

	void setShape(int);

	int getShape()const;

	int getCX()const;
	int getCY()const;

	void Draw();	//Draws Main Container.

	double getPerim()const; //Perimeter of the Container Circle
	double getArea()const;	//Area of the Container Circle

	Circle operator++(int);
	Circle operator++();
	Circle operator--(int);
	Circle operator--();

	Circle operator+(double);
	Circle operator-(double);

	/*friend bool operator==(const Circle&, const Rectangle&);
	friend bool operator==(const Circle&, const Triangle&);
	friend bool operator==(const Circle&, const Circle&);

	friend bool operator!=(const Circle&, const Rectangle&);
	friend bool operator!=(const Circle&, const Triangle&);
	friend bool operator!=(const Circle&, const Circle&);*/

	friend ostream& operator<<(ostream &, const Circle &);

	static int Total_Area();
	static int Total_Perim();

};

#endif /* CIRCLE_H_ */
