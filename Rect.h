#pragma once
#include "Shape.h"

class Rect :public Shape { //사각형
protected:
	virtual void draw() { cout << "Rectangle" << endl; }//순수가상함수 오버라이딩
};