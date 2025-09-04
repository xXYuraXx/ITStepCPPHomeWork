#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Point
{
protected:
	double x;
	double y;
public:
	Point() : x{ 0 }, y{ 0 } {}
	Point(double c) : x{ c }, y{ c } {}
	Point(double x, double y) : x{ x }, y{ y } {}

	static double distance_between_points(const Point& p1, const Point& p2) {
		return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
	}

	string to_string() const {
		return "( " + std::to_string(x) + "; " + std::to_string(y) + " )";
	}

	void Print() const {
		cout << this->to_string() << endl;
	}

	Point& operator--() {
		x--;
		y--;
		return *this;
	}

	Point& operator--(int) {
		x--;
		y--;
		return *this;
	}

	Point& operator++() {
		x++;
		y++;
		return *this;
	}

	Point& operator++(int) {
		x++;
		y++;
		return *this;
	}

	friend bool operator>(const Point& p1, const Point& p2) {
		double d1 = Point::distance_between_points(p1, Point(0, 0));
		double d2 = Point::distance_between_points(p2, Point(0, 0));
		return d1 > d2;
	}

	friend bool operator<(const Point& p1, const Point& p2) {
		double d1 = Point::distance_between_points(p1, Point(0, 0));
		double d2 = Point::distance_between_points(p2, Point(0, 0));
		return d1 < d2;
	}

	Point& operator!() {
		Point tmp(x, y);
		tmp = -x;
		tmp = -y;
		return tmp;
	}
};


void cout_points(const Point& p1, const Point& p2) {
	cout << "p1" << p1.to_string() << " | p2" << p2.to_string() << " |" << endl;
}

int main()
{
	Point p1(5), p2(4);
	cout_points(p1, p2);
	cout << "p1 > p2: " << (p1 > p2) << endl;
	cout << "p1 < p2: " << (p1 < p2) << endl;
	cout << "p1--" << endl;
	p1--;
	cout_points(p1, p2);
	cout << "p1 > p2: " << (p1 > p2) << endl;
	cout << "++p2" << endl;
	++p2;
	cout_points(p1, p2);
	cout << "p1 < p2: " << (p1 < p2) << endl;
	cout << "!p2 " << (!p2).to_string() << endl;
	cout << "p1 < !p2: " << (p1 < !p2) << endl;
	
	
}