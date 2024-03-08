#include <iostream>
#include "Shape3DHandler-1.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ShapeHandler shapeHandler1;
	cout << "\n\n0:\n";

	shapeHandler1.addBox(5.2f, 8.2f, 10.2f);
	shapeHandler1.addCylinder(4.2f, 88.1f, "Vertical");
	shapeHandler1.addCylinder(1.2f, 88.1f, "Vertical");
	shapeHandler1.addCylinder(33.2f, 88.1f, "Vertical");
	cout << "\n\n1:\n";
	shapeHandler1.showAll();

	cout << "\n\n2:\n";

	ShapeHandler shapeHandler2(shapeHandler1);
	shapeHandler2.showAll();

	cout << "\n\n3:\n";

	ShapeHandler shapeHandler3;
	shapeHandler3.addBox(99.1f, 99.2f, 99.6f);
	shapeHandler3.addCylinder(4.2f, 88.1f, "Vertical");
	shapeHandler3.showAll();

	cout << endl << endl;
	cout << "///////////////////" << endl;
	shapeHandler3 = shapeHandler1;
	shapeHandler3.showAll();
	cout << shapeHandler3.nrOfCylindersOriented("Vertical") << endl;
	cout << shapeHandler3.CAP << endl;


	return 0;
}