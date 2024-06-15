/*
 * @Date: 2024-02-25 21:52:24
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/TestRepo/24-02-25/triangle_jugdge.cpp
 * @Description: 计算几何-通过叉积判断某点是否在某个三角形 mesh 内
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
};

// cross product of two vectors
// P1P2 X P1P3
double crossProduct(const Point& p1, const Point& p2, const Point& p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool isInTriangle(const Point& p1, const Point& p2, const Point& p3, const Point& p) {
	double c1 = crossProduct(p1, p2, p);
	double c2 = crossProduct(p2, p3, p);
	double c3 = crossProduct(p3, p1, p);
	return (c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0);
}

int main() { return 0; }