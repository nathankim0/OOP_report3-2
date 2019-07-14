#pragma once
#include "Shape.h"

class Triangle :public Shape { //삼각형
protected:
	virtual void draw() { cout << "Triangle" << endl; }//순수가상함수 오버라이딩
};