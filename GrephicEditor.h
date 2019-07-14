#pragma once
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
#include "Triangle.h"
#include "Shape.h"
#include "UI.h"

class GraphicEditor {
	Shape* pStart; //처음 객체 가리킴
	Shape* pLast; //마지막 객체 가리킴
	Shape* p;
	Shape *q;
	int cnt;
public:
	GraphicEditor() { pStart = NULL; cnt = 0; }
	void figure(int receive) { //그리기 함수
		if (receive == 1) {
			if (cnt == 0) { //처음 그릴때
				pStart = new Line(); //처음 부분에 선 생성 pStart는 line 가리킴
				pLast = pStart;
			}
			else { //처음 그리는게 아닐때
				pLast = pLast->add(new Line()); //선 객체생성
			}
			cnt++; //그릴때마다 cnt 1씩증가
		}
		//이하 동일
		else if (receive == 2) {
			if (cnt == 0) {
				pStart = new Circle();
				pLast = pStart;
			}
			else {
				pLast = pLast->add(new Circle());
			}
			cnt++;
		}
		else if (receive == 3) {
			if (cnt == 0) {
				pStart = new Rect();
				pLast = pStart;
			}
			else {
				pLast = pLast->add(new Rect());
			}
			cnt++;
		}
		else if (receive == 4) {
			if (cnt == 0) {
				pStart = new Triangle();
				pLast = pStart;
			}
			else {
				pLast = pLast->add(new Triangle());
			}
			cnt++;
		}
		else cout << "잘못 입력하였습니다.\n";
	}
	void del(int receive) {  //삭제함수
		p = pStart;
		q = pStart;
		if (receive < cnt) { //삭제하려는 번호의 도형이 입력한 개수보다 작아야됨
			for (int i = 0; i<receive; i++) {  //삭제하려는 번호만큼 돌림
				p = q; //p가 처음 객체 가리킴
				q = q->getNext();  //q에 다음 도형 주소 저장
			}
			if (receive == 0) pStart = p->getNext(); //처음 도형을 삭제할때는 pStart가 다음도형 가리킴
			else p->setNext(q);  //처음 이외의 도형을 삭제할때는 p객체를 q next연결

			cnt--; //도형개수 1 줄임

			if (cnt == 1) pLast = pStart; //도형 한개 남아있으면 pLast에 pStart주소 저장
		}
		else cout << "잘못 입력하였습니다.\n" << endl;
	}
	void show() {
		p = pStart; //처음부터
		for (int i = 0; i < cnt; i++) { //도형 방문
			cout << i << ": ";
			p->paint(); //출력
			p = p->getNext(); //다음 도형으로
		}
	}
	void first() { //main에서 처음에 불러올 함수
		UI::print();
		while (1) {
			int select = UI::choice0(); //함수호출하고 선택값 select에 저장
			if (select == 1) figure(UI::choice1()); //도형그리기
			else if (select == 2) del(UI::choice2()); //삭제
			else if (select == 3) show(); //그린 함수 출력
			else if (select == 4) break; //종료
			else cout << "잘못 입력하였습니다.\n";
		}
	}
};
