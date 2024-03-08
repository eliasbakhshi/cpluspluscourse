#ifndef CYLINDER_H
#define CYLINDER_h
#include "Headers.h"
#include "Shape3D-7.h"


class Cylinder: public Shape3D
{
private:
	float radius;
	string orientation;

public:
	Cylinder(float radius, float height, string orientation = "Vertical");
	~Cylinder();

	void setRadius(float radius);
	float getRadius() const;


	float baseArea() const;
	string getOrientation() const;

	string toString() const;

};


#endif
