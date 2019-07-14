#pragma once
#include <iostream>
using namespace std;

class UI {
public:
	static void print() {
		cout << "그래픽 에디터입니다.\n";
	}
	static int choice0() {
		cout << "1:삽입, 2:삭제, 3:모두 그리기, 4:종료 >> ";
		int a;
		cin >> a;
		return a;
	}
	static int choice1() {
		cout << "1:선, 2:원, 3:사각형, 4:삼각형 >> ";
		int b;
		cin >> b;
		return b;
	}
	static int choice2() {
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		int c;
		cin >> c;
		return c;
	}
};