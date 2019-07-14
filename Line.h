#pragma once
#include "Shape.h"

class Line :public Shape { //선
protected:
	virtual void draw() { cout << "Line" << endl; } //순수가상함수 오버라이딩
};