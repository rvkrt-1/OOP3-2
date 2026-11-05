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

int main() {
	//экспереминтируйте и создавайте обьекты
	return 0;
}