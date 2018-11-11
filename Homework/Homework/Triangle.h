/*
 * Triangle.h
 *
 *  Created on: Oct 27, 2018
 *      Author: gtucpp
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include<iostream>
#include"Circle.h"
#include"Rectangle.h"
using namespace std;

class Triangle {
private:

	int LofTri;		//Length of Triangle
	int Lengt1_X, Lengt1_Y, Lengt2_X, Lengt2_Y, Lengt3_X, Lengt3_Y;		//Polygon parameters of Small Triangle
	static int TotalArea;
	static int TotalPerim;

public:

	Triangle();
	Triangle(const int, const int, const int, const int, const int, const int);

	void setShape(int);

	int getShape()const;

	int getLeng1_X()const;
	int getLeng1_Y()const;
	int getLeng2_X()const;
	int getLeng2_Y()const;
	int getLeng3_X()const;
	int getLeng3_Y()const;

	void Draw();	//Draws Main Container.
	
	int getPerim()const; //Perimeter of the Container Triangle
	double getArea()const;	//Area of the Container Triangle

	Triangle operator++(int);
	Triangle operator++();
	Triangle operator--(int);	
	Triangle operator--();

	Triangle operator+(double);
	Triangle operator-(double);

	/*friend bool operator==(const Triangle&, const Rectangle&);
	friend bool operator==(const Triangle&, const Triangle&);
	friend bool operator==(const Triangle&, const Circle&);

	friend bool operator!=(const Triangle&, const Rectangle&);
	friend bool operator!=(const Triangle&, const Triangle&);
	friend bool operator!=(const Triangle&, const Circle&);*/

	friend ostream& operator<<(ostream&, Triangle&);

	static int Total_Area();
	static int Total_Perim();

};

#endif /* TRIANGLE_H_ */
