#ifndef SHAPEHANDLER_H
#define SHAPEHANDLER_H
#include "Headers.h"
#include "Shape3D-7.h"
#include "Box-7.h"
#include "Cylinder-7.h"

class ShapeHandler
{
public:
	static const int CAP = 10;
private:
	Shape3D* shapes[CAP];
	int nrOf;

public:
	ShapeHandler();
	ShapeHandler(const ShapeHandler& other);
	void operator=(const ShapeHandler& other);
	~ShapeHandler();

	bool addCylinder(float radius, float height, string orientation);
	bool addBox(float width, float length, float height);

	int nrOfCylindersOriented(string orientation) const;

	void showAll() const;
};
#endif