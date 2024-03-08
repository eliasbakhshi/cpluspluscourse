#include "Shape3DHandler-1.h"

ShapeHandler::ShapeHandler():shapes{nullptr}, nrOf(0)
{

}

ShapeHandler::ShapeHandler(const ShapeHandler& other): shapes{nullptr}, nrOf(other.nrOf)
{
	for (int i = 0; i < this->nrOf; i++)
	{
		Box* boxPtr = dynamic_cast<Box*>(other.shapes[i]); // for this to be valid, it means that the object pointed to, is of the derived class(box)
		if (boxPtr != nullptr)
		{
			shapes[i] = new Box(*boxPtr);
		}
		else
		{
			Cylinder* cylinderPtr = dynamic_cast<Cylinder*>(other.shapes[i]);
			if (cylinderPtr != nullptr)
			{
				shapes[i] = new Cylinder(*cylinderPtr);
			}
		}
	}
}

void ShapeHandler::operator=(const ShapeHandler& other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->nrOf; i++)
		{
			delete this->shapes[i];
		}

		this->nrOf = other.nrOf;
		for (int i = 0; i < this->nrOf; i++)
		{
			Box* boxPtr = dynamic_cast<Box*>(other.shapes[i]); // for this to be valid, it means that the object pointed to, is of the derived class(box)
			if (boxPtr != nullptr)
			{
				shapes[i] = new Box(*boxPtr);
			}
			else
			{
				Cylinder* cylinderPtr = dynamic_cast<Cylinder*>(other.shapes[i]);
				if (cylinderPtr != nullptr)
				{
					shapes[i] = new Cylinder(*cylinderPtr);
				}
			}
		}
	}
}

ShapeHandler::~ShapeHandler()
{
	for (int i = 0; i < this->nrOf; i++)
	{
		delete this->shapes[i];
	}
}

bool ShapeHandler::addCylinder(float radius, float height, string orientation)
{
	bool didAdd = false;

	if (this->nrOf < CAP)
	{
		this->shapes[nrOf] = new Cylinder(radius, height, orientation);
		this->nrOf++;
		didAdd = true;
	}
	return didAdd;
}

bool ShapeHandler::addBox(float width, float length, float height)
{
	bool didAdd = false;

	if (this->nrOf < CAP)
	{
		this->shapes[nrOf] = new Box(width, length, height);
		this->nrOf++;
		didAdd = true;
	}
	return didAdd;
}

int ShapeHandler::nrOfCylindersOriented(string orientation) const
{
	int counter = 0;

	for (int i = 0; i < this->nrOf; i++)
	{
		Cylinder* cylinderPtr = dynamic_cast<Cylinder*>(this->shapes[i]);
		if (cylinderPtr != nullptr)
		{
			if (cylinderPtr->getOrientation() == orientation)
			{
				counter++;
			}
		}
	}
	return counter;
}

void ShapeHandler::showAll() const
{
	for (int i = 0; i < this->nrOf; i++)
	{
		cout << this->shapes[i]->toString() << endl;
	}
}
