#ifndef SHAPE3D_H
#define SHAPE3D_H
#include "Headers.h"


class Shape3D
{
private:
	float height;

public:
	Shape3D(float height = 0.0f);
	virtual ~Shape3D();

	void setHeight(float height);
	float getHeight() const;

	virtual float baseArea() const = 0; // pure virtual function
	// Shape3D becomes an Abstract Class as a consequence
	// A class that contains a pure virtual function is known as an abstact class
	// We cannot create objects of an abstract class
	// However we can derive classes from them, and use their member variables and member functions
	// except pure virtual functions, they forces us to define its usage in the derived class


	virtual string toString() const;
	float volume() const;
};

#endif
