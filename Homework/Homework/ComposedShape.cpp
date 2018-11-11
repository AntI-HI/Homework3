#include "pch.h"
#include "ComposedShape.h"
#include "ShapeElem.h"
#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#define sqrt3 1.732050
#define PI 3.14159265
using namespace std;

enum Shape { circle, rectangle, triangle };

ComposedShape::ComposedShape(const Rectangle& Rec, char SShape) {

	cout << "Please enter the small shape (R, C, T): ";
	cin >> SShape;	//Small Shape
	modifySShape(SShape);
	optimalFit(Rec, SShape);
	Draw(SShape);
}
ComposedShape::ComposedShape(const Circle& Cir, char SShape) {

	cout << "Please enter the small shape (R, C, T): ";
	cin >> SShape;	//Small Shape
	modifySShape(SShape);
	optimalFit(Cir, SShape);
	Draw(SShape);
}
ComposedShape::ComposedShape(const Triangle& Tri, char SShape) {

	cout << "Please enter the small shape (R, C, T): ";
	cin >> SShape;	//Small Shape
	modifySShape(SShape);
	optimalFit(Tri, SShape);
	Draw(SShape);
}

void ComposedShape::optimalFit(const Circle& Circ, char SShape) {

	if (SShape == 'c') {
		   
		int Count1, Count2, cx, cy, s = 1;
		double Angle, param;
		int newRad = Circ.getShape();		
		newRad++;		//To solve the fitting of 1/2 radius ratio circle.

		param = (double)Radius / (newRad - Radius);

		Angle = 2 * asin(param)*180.0 / PI;
		Count1 = (int)360.0 / Angle;
		Count2 = (int)(newRad / Radius);

		for (int j = 0; j <= Count2; j++) {

			for (int i = 0; i < Count1; i++) {

				cx = (int)(newRad - (newRad - s * Radius)*sin((i + 1)*Angle*PI / 180.0));
				cy = (int)(newRad - (newRad - s * Radius)*cos((i + 1)*Angle*PI / 180.0));

				Circle newCirc(cx, cy, Radius);

				ShElem = ShapeElem(newCirc);
				SetofShp.push_back(ShElem);

				SetofCirc.push_back(newCirc);

			}

			s += 2;
			param = (double)Radius / (newRad - s * Radius);

			Angle = 2 * asin(param)*180.0 / PI;
			Count1 = (int)360.0 / Angle;

		}

	}

	if (SShape == 'r') {

		int count1, count2, width, length;
		int s = 1;			//counter
		int rect_x;
		int rect_y;
		double pow1;
		double pow2;

		count2 = 2 * Circ.getShape() / HofRect;

		pow1 = pow(Circ.getShape(), 2);
		length = sqrt(pow1 - pow(WofRect / 2, 2));
		pow2 = pow(Circ.getShape() - (Circ.getShape() - length + s * HofRect), 2);
		
		width = sqrt(pow1 - pow2);
		count1 = 2 * width / WofRect;

		for (int i = 0; i < count2; i++) {

			pow1 = pow(Circ.getShape(), 2);
			pow2 = pow(Circ.getShape() - (Circ.getShape() - length + s * HofRect), 2);
			length = sqrt(pow1 - pow(WofRect / 2, 2));
			width = sqrt(pow1 - pow2);
			count1 = 2 * width / WofRect;

			for (int j = -count1 / 2; j < count1 / 2; j++) {
				
				rect_x = (int)(Circ.getShape() + j * WofRect);
				rect_y = (int)((Circ.getShape() - length) + i * HofRect);

				Rectangle newRect(rect_x, rect_y, WofRect, HofRect);
				
				ShElem = ShapeElem(newRect);
				SetofShp.push_back(ShElem);

				SetofRect.push_back(newRect);

				//file << "<rect x=\"" << (int)(Circ.getShape() + j * WofRect) << "\"" << " y=\"" << (int)((Circ.getShape() - length) + i * HofRect) << "\"" << " width=\"" << WofRect << "\"" << " height=\"" << HofRect << "\""" fill=\"red\" stroke=\"black\"/>" << endl;
			}

			s++;
		}

	}

	if (SShape == 't') {

		int count1, count2, condition;
		int Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y;
		int s = 1;			//counter
		double pow1;
		double pow2;

		count2 = 2 * Circ.getShape() / (LofTri*sqrt3 / 2);

		for (int i = 1; i < count2 / 2; i++) {		//First Half Straight side.

			pow1 = pow(Circ.getShape(), 2);
			pow2 = pow(Circ.getShape() - s * LofTri*sqrt3 / 2, 2);
			count1 = sqrt((double)(pow1 - pow2)) / (LofTri / 2.0);

			for (int j = -count1; j < count1; j += 2) {
				
				Leng1_X = (int)(Circ.getShape()) + (j*LofTri / 2.0);
				Leng1_Y = (int)((i + 1)*LofTri*sqrt3 / 2.0);
				Leng2_X = (int)(Circ.getShape() + (j + 1)*LofTri / 2.0);
				Leng2_Y = (int)((i)*LofTri*sqrt3 / 2.0);
				Leng3_X = (int)(Circ.getShape() + (j + 2)*LofTri / 2.0);
				Leng3_Y = (int)((i + 1)*LofTri*sqrt3 / 2.0);

				Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

				ShElem = ShapeElem(newTri);
				SetofShp.push_back(ShElem);

				SetofTri.push_back(newTri);

				//file << "<polygon points=\"" << (int)(Circ.getShape())+(j*LofTri / 2.0) << " " << (int)((i + 1)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 1)*LofTri / 2.0) << " " << (int)((i)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 2)*LofTri / 2.0) << " " << (int)((i + 1)*LofTri*sqrt3 / 2.0) << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;
			}
			s++;
		}
		s = 0;
		for (int i = 1; i < count2 / 2; i++) {		//First Half Reverse side.

			pow1 = pow(Circ.getShape(), 2);
			pow2 = pow(Circ.getShape() - s * LofTri*sqrt3 / 2, 2);
			count1 = sqrt((double)(pow1 - pow2)) / (LofTri / 2.0);
			condition = count1 % 2;

			for (int j = -count1; j < count1; j += 2) {

				if (condition == 1) {

					Leng1_X = (int)(Circ.getShape()) + ((j + 1)*LofTri / 2.0 - LofTri / 2);
					Leng1_Y = (int)((i)*LofTri*sqrt3 / 2.0);
					Leng2_X = (int)(Circ.getShape() + (j + 2)*LofTri / 2.0 - LofTri / 2.0);
					Leng2_Y = (int)((i + 1)*LofTri*sqrt3 / 2.0);
					Leng3_X = (int)(Circ.getShape() + (j + 3)*LofTri / 2.0 - LofTri / 2);
					Leng3_Y = (int)((i)*LofTri*sqrt3 / 2.0);

					Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

					ShElem = ShapeElem(newTri);
					SetofShp.push_back(ShElem);

					SetofTri.push_back(newTri);

					//file << "<polygon points=\"" << (int)(Circ.getShape())+((j + 1)*LofTri / 2.0 - LofTri / 2) << " " << (int)((i)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 2)*LofTri / 2.0 - LofTri / 2) << " " << (int)((i + 1)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 3)*LofTri / 2.0 - LofTri / 2) << " " << (int)((i)*LofTri*sqrt3 / 2.0) << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;
				}
				else {

					Leng1_X = (int)(Circ.getShape()) + ((j + 1)*LofTri / 2.0);
					Leng1_Y = (int)((i)*LofTri*sqrt3 / 2.0);
					Leng2_X = (int)(Circ.getShape() + (j + 2)*LofTri / 2.0);
					Leng2_Y = (int)((i + 1)*LofTri*sqrt3 / 2.0);
					Leng3_X = (int)(Circ.getShape() + (j + 3)*LofTri / 2.0);
					Leng3_Y = (int)((i)*LofTri*sqrt3 / 2.0);

					Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

					ShElem = ShapeElem(newTri);
					SetofShp.push_back(ShElem);

					SetofTri.push_back(newTri);

					//file << "<polygon points=\"" << (int)(Circ.getShape())+((j + 1)*LofTri / 2.0) << " " << (int)((i)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 2)*LofTri / 2.0) << " " << (int)((i + 1)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 3)*LofTri / 2.0) << " " << (int)((i)*LofTri*sqrt3 / 2.0) << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;
				}

			}
			s++;

		}

		s = 0;
		for (int i = 1; i <= count2 / 2; i++) {		//Second Half Reverse Side

			pow1 = pow(Circ.getShape(), 2);
			pow2 = pow(Circ.getShape() - s * LofTri*sqrt3 / 2, 2);
			count1 = sqrt((double)(pow1 - pow2)) / (LofTri / 2.0);

			for (int j = -count1; j < count1; j += 2) {

				Leng1_X = (int)(Circ.getShape()) + (j*LofTri / 2.0);
				Leng1_Y = (int)(2 * Circ.getShape() - (i + 1)*LofTri*sqrt3 / 2.0);
				Leng2_X = (int)(Circ.getShape() + (j + 1)*LofTri / 2.0);
				Leng2_Y = (int)(2 * Circ.getShape() - (i)*LofTri*sqrt3 / 2.0);
				Leng3_X = (int)(Circ.getShape() + (j + 2)*LofTri / 2.0);
				Leng3_Y = (int)(2 * Circ.getShape() - (i + 1)*LofTri*sqrt3 / 2.0);

				Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

				ShElem = ShapeElem(newTri);
				SetofShp.push_back(ShElem);

				SetofTri.push_back(newTri);

				//file << "<polygon points=\"" << (int)(Circ.getShape())+(j*LofTri / 2.0) << " " << (int)(2 * Circ.getShape() - (i + 1)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 1)*LofTri / 2.0) << " " << (int)(2 * Circ.getShape() - (i)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 2)*LofTri / 2.0) << " " << (int)(2 * Circ.getShape() - (i + 1)*LofTri*sqrt3 / 2.0) << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;
			}
			s++;
		}

		s = 0;
		for (int i = 1; i <= count2 / 2; i++) {		//Second Half Straight Side

			pow1 = pow(Circ.getShape(), 2);
			pow2 = pow(Circ.getShape() - s * LofTri*sqrt3 / 2, 2);
			count1 = sqrt((double)(pow1 - pow2)) / (LofTri / 2.0);

			for (int j = -count1; j < count1; j += 2) {

				Leng1_X = (int)(Circ.getShape()) + ((j + 1)*LofTri / 2.0);
				Leng1_Y = (int)(2 * Circ.getShape() - (i)*LofTri*sqrt3 / 2.0);
				Leng2_X = (int)(Circ.getShape() + (j + 2)*LofTri / 2.0);
				Leng2_Y = (int)(2 * Circ.getShape() - (i + 1)*LofTri*sqrt3 / 2.0);
				Leng3_X = (int)(Circ.getShape() + (j + 3)*LofTri / 2.0);
				Leng3_Y = (int)(2 * Circ.getShape() - (i)*LofTri*sqrt3 / 2.0);

				Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

				ShElem = ShapeElem(newTri);

				SetofTri.push_back(newTri);

				//file << "<polygon points=\"" << (int)(Circ.getShape())+((j + 1)*LofTri / 2.0) << " " << (int)(2 * Circ.getShape() - (i)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 2)*LofTri / 2.0) << " " << (int)(2 * Circ.getShape() - (i + 1)*LofTri*sqrt3 / 2.0) << ", " << (int)(Circ.getShape() + (j + 3)*LofTri / 2.0) << " " << (int)(2 * Circ.getShape() - (i)*LofTri*sqrt3 / 2.0) << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;
			}
			s++;
		}

	}

}	

void ComposedShape::optimalFit(const Triangle& Tria, char SShape) {

	if (SShape == 'c') {

		int count, cx, cy;

			count = ((Tria.getShape() - 2 * sqrt3*Radius) / Radius) / 2 + 1;	//Main Counter

			for (int i = 0; i < count; i++) {

				cy = (int)(2 * Radius + (i)*Radius*sqrt3);

				for (int j = -i; j <= +i; j += 2) {

					cx = (int)(Tria.getShape() / 2 + (j)*Radius);

					Circle newCirc(cx, cy, Radius);

					ShElem = ShapeElem(newCirc);
					SetofShp.push_back(ShElem);

					SetofCirc.push_back(newCirc);

					//file << "<circle cx=\"" << cx << "\"" << " cy=\"" << cy << "\"" << " r=\"" << Radius << "\"" << " fill=\"red\" stroke=\"black\"/> " << endl;
				}

			}
			
	}	
	if (SShape == 'r') {

		int count;
		int rect_x, rect_y;

		count = (Tria.getShape()*sqrt3 / 2 - WofRect) / HofRect;

		for (int i = 1; i <= count; i++) {

			for (int j = -i; j < i; j += 2) {

				rect_x = (int)(Tria.getShape() / 2 + j * WofRect / 2);
				rect_y = WofRect + (i - 1)*HofRect;

				Rectangle newRect(rect_x, rect_y, WofRect, HofRect);

				ShElem = ShapeElem(newRect);
				SetofShp.push_back(ShElem);

				SetofRect.push_back(newRect);

				//file << "<rect x=\"" << (int)(Tria.getShape() / 2 + j * WofRect / 2) << "\"" << " y=\"" << WofRect + (i - 1)*HofRect << "\"" << " width=\"" << WofRect << "\"" << " height=\"" << HofRect << "\""" fill=\"red\" stroke=\"black\"/>" << endl;
			}
		}

	}
	if (SShape == 't') {

		int count;
		int Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y;

		count = (Tria.getShape() *sqrt3 / 2) / (LofTri*sqrt3 / 2);

		for (int i = 0; i < count; i++) {

			for (int j = -i; j <= i; j += 2) {

				Leng1_X = (int)(Tria.getShape() / 2) + (j*LofTri / 2);
				Leng1_Y = (int)(i*LofTri*sqrt3 / 2);
				Leng2_X = (int)(Tria.getShape() / 2 + (j - 1)*LofTri / 2);
				Leng2_Y = (int)((i + 1)*LofTri*sqrt3 / 2);
				Leng3_X = (int)(Tria.getShape() / 2 + (j + 1)*LofTri / 2);
				Leng3_Y = (int)((i + 1)*LofTri*sqrt3 / 2);

				Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

				ShElem = ShapeElem(newTri);
				SetofShp.push_back(ShElem);

				SetofTri.push_back(newTri);

				//file << "<polygon points=\"" << (int)(Tria.getShape() / 2) + (j*LofTri / 2) << " " << (int)(i*LofTri*sqrt3 / 2) << ", " << (int)(Tria.getShape() / 2 + (j - 1)*LofTri / 2) << " " << (int)((i + 1)*LofTri*sqrt3 / 2) << ", " << (int)(Tria.getShape() / 2 + (j + 1)*LofTri / 2) << " " << (int)((i + 1)*LofTri*sqrt3 / 2) << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;
			}
		}

		count = (Tria.getShape() *sqrt3 / 2 - LofTri * sqrt3 / 2) / (LofTri*sqrt3 / 2);
		for (int i = 1; i <= count; i++) {

			for (int j = -i; j < i; j += 2) {

				Leng1_X = (int)(Tria.getShape() / 2) + (j*LofTri / 2);
				Leng1_Y = (int)(i*LofTri*sqrt3 / 2);
				Leng2_X = (int)(Tria.getShape() / 2 + (j + 1)*LofTri / 2);
				Leng2_Y = (int)((i + 1)*LofTri*sqrt3 / 2);
				Leng3_X = (int)(Tria.getShape() / 2 + (j + 2)*LofTri / 2);
				Leng3_Y = (int)((i)*LofTri*sqrt3 / 2);

				Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

				ShElem = ShapeElem(newTri);
				SetofShp.push_back(ShElem);

				SetofTri.push_back(newTri);

				//file << "<polygon points=\"" << (int)(Tria.getShape() / 2) + (j*LofTri / 2) << " " << (int)(i*LofTri*sqrt3 / 2) << ", " << (int)(Tria.getShape() / 2 + (j + 1)*LofTri / 2) << " " << (int)((i + 1)*LofTri*sqrt3 / 2) << ", " << (int)(Tria.getShape() / 2 + (j + 2)*LofTri / 2) << " " << (int)((i)*LofTri*sqrt3 / 2) << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;
			}
		}

	}

}

void ComposedShape::optimalFit(const Rectangle& Rect, char SShape) {	

	if (SShape == 'c') {

		int count1, count2;

		count1 = Rect.getWidth() / (2 * Radius);
		count2 = Rect.getHeight() / (2 * Radius);

		if (count1 == 0 || count2 == 0) {
			cout << "You Entered wrong values. Please try again..";
			exit(1);
		}
		else {

			int cy = 1, s = 1;
			int cx;
			for (int i = 1; i <= count2; i++) {

				for (int i = 1; i <= count1; i++) {

					cx = (int)(2 * i - 1)*Radius;
					cy = (2 * s - 1)*Radius;

					Circle newCirc(cx, cy, Radius);

					ShElem = ShapeElem(newCirc);
					SetofShp.push_back(ShElem);

					SetofCirc.push_back(newCirc);

					//file << "<circle cx=\"" << (2 * i - 1)*Radius << "\"" << " cy=\"" << cy << "\"" << " r=\"" << Radius << "\"" << " fill=\"green\" stroke=\"black\"/>" << endl;
				}
				s++;
				
			}

		}

		
	}
	if (SShape == 'r') {

		int count1, count2;

		count1 = Rect.getWidth() / WofRect;
		count2 = Rect.getHeight() / HofRect;

		if (count1 == 0 || count2 == 0) {
			cout << "You Entered wrong values. Please try again..";
			exit(1);
		}
		else {
			int s = 0;
			int rect_x, rect_y;

			for (int i = 1; i <= count2; i++) {

				for (int i = 1; i <= count1; i++) {

					rect_x = (i - 1)*WofRect;
					rect_y = s * HofRect;

					Rectangle newRect(rect_x, rect_y, WofRect, HofRect);

					ShElem = ShapeElem(newRect);
					SetofShp.push_back(ShElem);

					SetofRect.push_back(newRect);

					//file << "<rect x=\"" << (i - 1)*WofRect << "\"" << " y=\"" << s * HofRect << "\"" << " width=\"" << WofRect << "\"" << " height=\"" << HofRect << "\""" fill=\"green\" stroke=\"black\"/>" << endl;
				}
				s++;
				
			}

		}

	}
	if (SShape == 't') {

		int count1, count2;
		int Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y;

		count1 = Rect.getWidth() / (LofTri);
		count2 = Rect.getHeight() / (LofTri*sqrt3 / 2);

		if (count1 == 0 || count2 == 0) {
			cout << "You Entered wrong values. Please try again..";
			exit(1);
		}
		else {

			int s = 0;
			for (int i = 1; i <= count2; i++) {

				for (int i = 1; i <= count1; i++) {

					Leng1_X = (int)(2 * i - 1)*(LofTri / 2);
					Leng1_Y = s * (int)(LofTri*sqrt3 / 2);
					Leng2_X = (i - 1)*LofTri;
					Leng2_Y = (s + 1)*(int)(LofTri*sqrt3 / 2);
					Leng3_X = i * LofTri;
					Leng3_Y = (s + 1)*(int)(LofTri*sqrt3 / 2);

					Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

					ShElem = ShapeElem(newTri);
					SetofShp.push_back(ShElem);

					SetofTri.push_back(newTri);

					//file << "<polygon points=\"" << (2 * i - 1)*(LofTri / 2) << " " << s * (int)(LofTri*sqrt3 / 2) << ", " << (i - 1)*LofTri << " " << (s + 1)*(int)(LofTri*sqrt3 / 2) << ", " << i * LofTri << " " << (s + 1)*(int)(LofTri*sqrt3 / 2) << "\"" << " fill=\"green\" stroke=\"black\"/>" << endl;
				}
				s++;

			}

		}
		count1 = (Rect.getWidth() - (LofTri / 2)) / (LofTri);
		count2 = Rect.getHeight() / (LofTri*sqrt3 / 2);

		int s = 0;
		for (int i = 1; i <= count2; i++) {

			for (int i = 1; i <= count1; i++) {

				Leng1_X = (int)((2 * i - 1)*(LofTri / 2.0));
				Leng1_Y = (int)(s*LofTri*sqrt3 / 2.0);
				Leng2_X = (i)*LofTri;
				Leng2_Y = (int)((s + 1)*LofTri*sqrt3 / 2.0);
				Leng3_X = (int)(i * LofTri + LofTri / 2.0);
				Leng3_Y = (int)(s*LofTri*sqrt3 / 2.0);

				Triangle newTri(Leng1_X, Leng1_Y, Leng2_X, Leng2_Y, Leng3_X, Leng3_Y);

				ShElem = ShapeElem(newTri);
				SetofShp.push_back(ShElem);

				SetofTri.push_back(newTri);

				//file << "<polygon points=\"" << (2 * i - 1)*(LofTri / 2) << " " << (int)(s*LofTri*sqrt3 / 2) << ", " << (i)*LofTri << " " << (int)((s + 1)*LofTri*sqrt3 / 2) << ", " << i * LofTri + LofTri / 2 << " " << (int)((s)*LofTri*sqrt3 / 2) << "\"" << " fill=\"green\" stroke=\"black\"/>" << endl;
			}
			s++;
		}

		
	}

}

void ComposedShape::Draw(const char SShape) {

	fstream F;
	F.open("Shape.svg", ios::out | ios::in | ios::app);
	F.setf(ios::left);

	if (SShape == 'c') {

		unsigned int size = SetofCirc.size();

		for (unsigned int i = 0; i < size; i++) {

			F << "<circle cx=\"" << SetofCirc[i].getCX() << "\"" << " cy=\"" << SetofCirc[i].getCY() << "\"" << " r=\"" << Radius << "\"" << " fill=\"red\" stroke=\"black\"/> " << endl;
		}

		F << "</svg>" << endl;
	}

	else if (SShape == 'r') {

		unsigned int size = SetofRect.size();

		for (unsigned i = 0; i < size; i++) {

			F << "<rect x=\"" << SetofRect[i].getX() << "\"" << " y=\"" << SetofRect[i].getY() << "\"" << " width=\"" << WofRect << "\"" << " height=\"" << HofRect << "\""" fill=\"red\" stroke=\"black\"/>" << endl;
		}

		F << "</svg>" << endl;
	}

	else if (SShape == 't') {

		unsigned int size = SetofTri.size();

		for (unsigned int i = 0; i < size; i++) {

			F << "<polygon points=\"" << SetofTri[i].getLeng1_X() << " " << SetofTri[i].getLeng1_Y() << ", " << SetofTri[i].getLeng2_X() << " " << SetofTri[i].getLeng2_Y() << ", " << SetofTri[i].getLeng3_X() << " " << SetofTri[i].getLeng3_Y() << "\"" << " fill=\"red\" stroke=\"black\"/>" << endl;

		}

		F << "</svg>" << endl;
	}

}

void ComposedShape::modifySShape(const char SShape) {

	switch (SShape) {		//Attributes of Small Shape

	case 'c':
		cout << "Please enter the radius: ";
		cin >> Radius;

		break;
	case 'r':
		cout << "Please enter the widht of rectangle: ";
		cin >> WofRect;
		cout << "Please enter the height of rectangle: ";
		cin >> HofRect;

		break;
	case 't':
		cout << "Please enter the lenght of triangle: ";
		cin >> LofTri;

		break;
	}

}


ComposedShape& ComposedShape::operator+=(Circle& Cir) {

	SetofCirc.push_back(Cir);

	return *this;
}
ComposedShape& ComposedShape::operator+=(Rectangle& Rect) {

	SetofRect.push_back(Rect);

	return *this;
}
ComposedShape& ComposedShape::operator+=(Triangle& Tri) {

	SetofTri.push_back(Tri);

	return *this;
}

ShapeElem& ComposedShape::operator[](unsigned int i) {

	if (i >= SetofShp.size()) {

		cout << "Out of vector!!" << endl;
		return SetofShp[0];
	}

	return SetofShp[i];

}

ostream& operator<<(ostream& stream, const ShapeElem& ShpElem){

	if (ShpElem.Shp == circle) {

		void* shp = ShpElem.getShape();

		Circle* Cir = static_cast<Circle*>(shp);

		stream << "<circle cx=\"" << Cir->getCX() << "\"" << " cy=\"" << Cir->getCY() << "\"" << " r=\"" << Cir->getShape() << "\"" << " fill=\"green\"/>" << endl;

	}

	else if (ShpElem.Shp == rectangle) {

		void* shp = ShpElem.getShape();

		Rectangle* Rect = static_cast<Rectangle*>(shp);

		stream << "<rect x=\"" << Rect->getX() << "\"" << " y=\"" << Rect->getY() << "\"" << " width=\"" << Rect->getWidth() << "\"" << " height=\"" << Rect->getHeight() << "\""" fill=\"green\" stroke=\"black\"/>" << endl;

	}

	else if (ShpElem.Shp == triangle) {

		void* shp = ShpElem.getShape();

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