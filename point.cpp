/*
* Name: Adam Aberbach
* Id: 900225980
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Point.h"
using namespace std;

point center(point *c, int n) {
	point center;
	double sumX = 0;
	double sumY = 0;
	for (int i = 0; i < n; i++)
	{
		sumX += (c + i)->getXvalue();	// find sum of x values in array
		sumY += (c + i)->getYvalue();	// find sum of y values in array
	}
	center.setXvalue(sumX / n);	// set x value of center to average of x values
	center.setYvalue(sumY / n);	// set y value of center to average of y values
	return center;
}

void closeCluster(point* c1, point* c2, int n1, int n2, point p) {
	point center1 = center(c1, n1); // find both centers
	point center2 = center(c2, n2);

	// Display coordinates of two centers

	/*cout << "The center of cluster A is ";
	center1.displayCoordinates();
	cout << endl;
	cout << "The center of cluster B is ";
	center2.displayCoordinates();
	cout << endl;*/
	
	// find both distances from centers
	float distance1 = center1.distance(p); 
	float distance2 = center2.distance(p);

	if (distance1 < distance2)	// find smallest distance
		cout << "The point belongs to cluster 1" << endl;
	else
		cout << "The point belongs to cluster 2" << endl;
}

int main()
{
	int m;
	int n1, n2;
	cout << "Please enter the number of points in clusters A and B respectively: ";
	cin >> n1 >> n2;
	cout << "Please enter the number of random points: ";
	cin >> m;

	// Declare 2 dynamic point arrays and pointer to point
	point* clusterA = new point[n1];
	point* clusterB = new point[n2];
	point* randomP = new point;

	srand(time(0)); // seed time
	
	for (int i = 0; i < n1; i++) {
		(clusterA + i)->setXvalue((rand() % 19) + 70.0);	// random x value: 70.0 < x < 90.0
		(clusterA + i)->setYvalue((rand() % 19) + 70.0);	// random y value: 70.0 < y < 90.0
	}

	for (int i = 0; i < n2; i++) {
		(clusterB + i)->setXvalue((rand() % 19) + 20.0);	// random x value: 20.0 < x < 40.0
		(clusterB + i)->setYvalue((rand() % 19) + 20.0);	// random y value: 20.0 < y < 40.0
	}

	for (int i = 0; i < m; i++) {
		randomP->setXvalue((rand() % 94) + 5.0);	// random x value: 5.0 < x < 100.0
		randomP->setYvalue((rand() % 94) + 5.0);	// random y value: 5.0 < y < 100.0

		// function called with 2 dynamic point arrays, their sizes ,and value of pointer to point
		closeCluster(clusterA, clusterB, n1, n2, *randomP);
	}

	return 0;
}
