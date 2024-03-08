//#include <iostream>
//#include "Shape3D-7.h"
//#include "Cylinder-7.h"
//#include "Box-7.h"
//
//using namespace std;
//
//int main() {
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//	Shape3D* shapes[6]{ nullptr };
//	shapes[0] = new Box(5.2f, 2.1f, 7.1f);
//	shapes[1] = new Box(2.2f, 5.1f, 3.1f);
//	shapes[2] = new Cylinder(2.2f, 5.1f, "Vertical");
//	shapes[3] = new Cylinder(3.3f, 5.5f, "Horizontal");
//	shapes[4] = new Cylinder(7.2f, 9.1f, "Vertical");
//	shapes[5] = new Cylinder(1.2f, 32.1f, "Vertical");
//
//	// show only cylinders
//	cout << "\nAll cylinders" << endl;
//	Cylinder* cylPtr = nullptr;
//	int counter = 0;
//	for (int i = 0; i < 6; i++) {
//		cylPtr = dynamic_cast<Cylinder*>(shapes[i]);
//		if (cylPtr != nullptr) {
//			cout << cylPtr->toString() << endl;
//			cout << "volume : " + to_string(cylPtr->volume()) << endl;
//			cout << "baseArea : " + to_string(cylPtr->baseArea()) << endl;
//			counter++;
//		}
//	}
//	cout << "counter:" << counter << endl;
//
//	// sum length of all boxes
//	Box* boxPtr = nullptr;
//	float totLength = 0.0f;
//	for (int i = 0; i < 6; i++) {
//		boxPtr = dynamic_cast<Box*>(shapes[i]);
//		if (boxPtr != nullptr) {
//			totLength += boxPtr->getLength();
//			cout << boxPtr->toString() << endl;
//			cout << "volume : " + to_string(boxPtr->volume()) << endl;
//			cout << "baseArea : " + to_string(boxPtr->baseArea()) << endl;
//		}
//	}
//	cout << "Total Length:" << totLength << endl;
//
//	for (int i = 0; i < 5; i++) {
//		delete shapes[i];
//	}
//	delete cylPtr, boxPtr;
//
//
//	return 0;
//}