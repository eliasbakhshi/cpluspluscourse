#include "Shape3D-7.h"

Shape3D::Shape3D(float height):height(height)
{
	cout << "Shape3D" << endl;
}

Shape3D::~Shape3D()
{
	cout << "Destroying Shape3D" << endl;
}

void Shape3D::setHeight(float height)
{
	this->height = height;
}

float Shape3D::getHeight() const
{
	return this->height;
}

string Shape3D::toString() const
{
	return "Height: " + to_string(this->height);
}

float Shape3D::volume() const
{
	return this->baseArea() * this->getHeight();
}