#ifndef BOX_H
#define BOH_H
#include "Headers.h"
#include "Shape3D-7.h"

class Box: public Shape3D
{
private:
	float length;
	float width;

public:
	Box(float length, float width, float height);
	~Box();

	void setLength(float length);
	float getLength() const;

	void setWidth(float width);
	float getWidth() const;

	float baseArea() const;

	string toString() const;

};


#endif // !BOX_H

