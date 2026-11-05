#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Point {
protected:
	int x;
	int y;
public:
	Point() { //базовый
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y) { //с параметрами 
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}

	Point(const Point& p) {// копирования
		printf("Point(const Point& p)\n");
		x = p.x;
		y = p.y;
	}
	virtual ~Point() { //деструктор
		printf("%d %d\n", x, y);
		printf("~Point\n");
	}

	void move(int x1, int y1) {
		printf("Point move(int x1, int y1)\n");
		this->x += x1;
		this->y += y1;
		return;
	}
	void reset() {
		printf("reset()\n");
		x = 0;
		y = 0;
	}
};



class ColoredPoint : public Point {
protected:
	char color;
public:
	ColoredPoint() : Point() {
		printf("ColoredPoint()\n");
		color = 'b';
	}
	ColoredPoint(int x, int y, char c) : Point(x,y) {
		printf("ColoredPoint(int x, int y, char c)\n");
		this->x = x;
		this->y = y;
		color = c;
	}
	ColoredPoint(const ColoredPoint& p) /* : Point(p) */{
		printf("ColoredPoint(const ColoredPoint& p)\n");
		x = p.x;
		y = p.y;
		color = p.color;
	}
	~ColoredPoint() {
		printf("%d %d %c\n", x, y, color);
		printf("~ColoredPoint\n");
	}

	void reset() {
		printf("creset()\n");
		Point::reset();      //ресет точек при обьявлении
		color = 'b';
	}

};

class Line {
protected:
	Point* p1;
	Point* p2;
public:
	Line() {
		printf("Line()\n");
		p1 = new Point();
		p2 = new Point();
	}
	Line(Point* p1, Point* p2) {
		printf("Line(Point* p1, Point* p2)\n");
		this->p1 = p1;
		this->p2 = p2;
	}

	Line(int x1, int y1, int x2, int y2) {
		printf("Line(int x1, int y1, int x2, int y2)\n");
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);
	}

	Line(Point& p1, Point& p2) {
		printf("Line(Point& p1, Point& p2)\n");
		this->p1 = new Point(p1);
		this->p2 = new Point(p2);
	}

	Line(const Line& line) {
		printf("Line(const Line& line)\n");
		p1 = new Point(*(line.p1));
		p2 = new Point(*(line.p2));
	}
	virtual ~Line() {
		delete p1;
		delete p2;
		printf("~Line\n");
	}
};

class ColorLine : public Line {
protected:
	string color;
public:
	ColorLine() {}
	~ColorLine() { printf("~ColorLine\n"); }

};

class Triangle {
protected:
	Point p1;
	Point p2;
	Point p3;
public:
	Triangle() { printf("Triangle()\n"); }
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : p1(x1, y1), p2(x2, y2), p3(x3, y3) {
		printf("Triangle(int x1, int y1, int x2, int y2, int x3, int y3 )\n");
	}
	~Triangle() { printf("~Triangle\n"); }
	void reset();
};

void Triangle::reset() {
	printf("Triangle::reset()\n");
	p1.reset();
	p2.reset();
	p3.reset();
}

int main() {
	//экспереминтируйте и создавайте обьекты
	return 0;
}