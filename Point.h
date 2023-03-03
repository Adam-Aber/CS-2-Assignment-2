/*
* Name: Adam Aberbach
* Id: 900225980
*/

#include <iostream>
#include <cmath>
using namespace std;

class point
{
private:
	// Data members x and y
	float x;
	float y;
public:
	// Default Constructor, sets X = Y = 0
	point() {
		x = 0;
		y = 0;
	}
	// Constructor. Initializes both X and Y.
	point(float a, float b) {
		x = a;
		y = b;
	}
	// Set X value
	void setXvalue(float v) {
		x = v;
	}
	// Set Y value
	void setYvalue(float v) {
		y = v;
	}
	// Get X value
	float getXvalue() {
		return x;
	}
	// Get Y value
	float getYvalue() {
		return y;
	}
	// Display point as (X , Y)
	void displayCoordinates() {
		cout << "the point (" << getXvalue() << " , " << getYvalue() << " )";
	}
	// distance between current point object and another point p
	float distance(point p) {
		return sqrt(pow(getXvalue() - p.getXvalue(), 2) + pow(getYvalue() - p.getYvalue(), 2)); // distance formula
	}
};

