/*
 * @Date: 2024-02-25 21:53:47
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/TestRepo/24-02-25/line_distance.cpp
 * @Description: 获取平面上的直线，以及某一点到该直线的距离
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
};

void getCoefficients(const Point& p1, const Point& p2, double& a, double& b, double& c) {
	a = p2.y - p1.y;
	b = p1.x - p2.x;
	c = p2.x * p1.y - p1.x * p2.y;
}

double dist(const Point& p, double a, double b, double c) { return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b); }

int main() {
	Point P1(1, 1);
	Point P2(2, 2);
	double a, b, c;
	getCoefficients(P1, P2, a, b, c);
	// define a group of points
	vector<Point> points = {{3, 2}, {3, 3}, {5, 7}, {2, 1}, {3, 2}};
	sort(points.begin(), points.end(),
	     [&](const Point& p1, const Point& p2) { return dist(p1, a, b, c) < dist(p2, a, b, c); });
	for (auto&& p : points) {
		cout << p.x << " " << p.y << endl;
	}
	return 0;
}