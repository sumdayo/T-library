#pragma once
#include <cmath>

static double eps = 1e-10;

double add(double a, double b) {return (abs(a + b) < eps * (abs(a) + abs(b)) ? 0.0 : a + b);}

struct P {
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator + (P p) {return P(add(x, p.x), add(y, p.y));}
    P operator - (P p) {return P(add(x, -p.x), add(y, -p.y));}
    P operator * (double d) {return P(x * d, y * d);}

    // dot -> 内積
    double dot(P p) {return add(x * p.x, y * p.y);}
    // det -> 外積
    double det(P p) {return add(x * p.y, -y * p.x);}

    double norm2() {return x * x + y * y;} // 長さの二乗
    double norm() {return sqrt(norm2());} // 長さ
};
