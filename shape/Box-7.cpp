#include "Box-7.h"

Box::Box(float length, float width, float height):length(length), width(width), Shape3D(height)
{
	cout << "Box" << endl;
}

Box::~Box()
{
	cout << "Dostrying Box" << endl;
}

void Box::setLength(float length)
{
	this->length = length;
}

float Box::getLength() const
{
	return this->length;
}

void Box::setWidth(float width)
{
	this->width = width;
}

float Box::getWidth() const
{
	return this->width;
}

float Box::baseArea() const
{
	return this->length * this->width;
}

string Box::toString() const
{
	return "Box:\nLength: " + to_string(this->length) + "\nWidth: " + to_string(this->width) + "\n" + Shape3D::toString();
}


