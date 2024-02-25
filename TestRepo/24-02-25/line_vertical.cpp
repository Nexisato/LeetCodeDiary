/*
 * @Date: 2024-02-25 22:06:14
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/TestRepo/24-02-25/line_vertical.cpp
 * @Description: 计算经过某点且与某条直线垂直直线
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct coff{
    double a, b, c;
    coff(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

void getCoefficients(const Point& p1, const Point& p2, double& a, double& b, double& c) {
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = p2.x * p1.y - p1.x * p2.y;
}

coff getVertical(const Point& p, double a, double b, double c) {
    double a_ver = -b;
    double b_ver = a;
    double c_ver = a * p.y - b * p.x;
    return coff(a_ver, b_ver, c_ver);
}


double dist(const Point& p, double a, double b, double c) {
    return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
}