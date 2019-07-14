#pragma once
#include "Shape.h"

class Circle :public Shape { //원
protected:
	virtual void draw() { cout << "Circle" << endl; }//순수가상함수 오버라이딩
};