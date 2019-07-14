#pragma once
#include <iostream>
using namespace std;

class Shape { //추상클래스
	Shape* next;
protected:
	virtual void draw() = 0; //순수가상함수
public:
	Shape() { next = NULL; } //생성자
	virtual ~Shape() { } //가상소멸자
	void paint() { draw(); } //show함수에서 사용
	Shape* add(Shape* p) { this->next = p; return p; } //해당객체의 next에 p 대입, p리턴
	Shape* getNext() { return next; } //next 리턴
	void setNext(Shape *p) { this->next = p->next; }//해당객체의 next에 p의 next 대입
};
