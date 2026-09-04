#pragma once
#include <cmath>
#include <vector>
#include <algorithm>

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
    double dot(P p) const {return add(x * p.x, y * p.y);}
    // det -> 外積
    double det(P p) const {return add(x * p.y, -y * p.x);}

    double norm2() const {return x * x + y * y;} // 長さの二乗
    double norm() const {return sqrt(norm2());} // 長さ
    
    // ---偏角に関する関数---
    // 偏角[0,2π)の上半分(0)/下半分(1)。0は正のx軸を含む[0,π)
    int arg_half() { return (y > 0 || (y == 0 && x > 0)) ? 0 : 1; }

    // 同じ偏角か
    bool same_arg(P p) { return arg_half() == p.arg_half() && det(p) == 0; }

    // なす角
    long double angle(P p) { return std:: atan2(std::fabs(det(p)), dot(p)); }

    // 偏角の昇順
    static bool arg_less(P a, P b) {
        int ha = a.arg_half(), hb = b.arg_half();
        return ha != hb ? ha < hb : a.det(b) > 0;
    }

    static void arg_sort(std:: vector<P>& v) {
        std:: sort(v.begin(), v.end(), arg_less);
    }
};

