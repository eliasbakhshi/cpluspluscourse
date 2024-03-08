#include "Cylinder-7.h"

Cylinder::Cylinder(float radius, float height, string orientation):radius(radius), Shape3D(height)
{
	cout << "Cylinder" << endl;

	if (orientation != "Vertical")
	{
		this->orientation = orientation;
	} else {
		this->orientation = "Vertical";
	}
}

Cylinder::~Cylinder()
{
	cout << "Destroying Cylinder" << endl;
}

void Cylinder::setRadius(float radius)
{
	this->radius = radius;
}

float Cylinder::getRadius() const
{
	return this->radius;
}

float Cylinder::baseArea() const
{
	return this->radius * this->radius * 3.14f;
}

string Cylinder::getOrientation() const
{
	return this->orientation;
}

string Cylinder::toString() const
{
	return "Cylinder:\nRadius: " + to_string(this->radius) + "\n" + Shape3D::toString() + "\nOrientation: " + this->orientation;
}


