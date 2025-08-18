#pragma once

#include <atcoder/all>
using namespace atcoder;

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <chrono>
#include <random>

const long long p1 = 1234325531;
const long long p2 = 2147483647;

struct Mints {
    long long d1, d2;
    Mints(long long val = 0): d1(val), d2(val) {}
    Mints(long long d1, long long d2): d1(d1), d2(d2) {}

    Mints operator+(const Mints& a) const {
        return Mints((d1 + a.d1) % p1, (d2 + a.d2) % p2);
    }
    Mints operator*(const Mints& a) const {
        return Mints((d1 * a.d1) % p1, (d2 * a.d2) % p2); // 2つの区間をマージ
    }
    bool operator==(const Mints& a) const {
        return (d1 == a.d1 && d2 == a.d2);
    }
};

struct D {
    Mints h, c;
    D() {}
    D(Mints h, Mints c): h(h), c(c) {}
};

D op(D a, D b) {return D(a.h+b.h*a.c, a.c*b.c);}

D e() {return D(0, 1);} // (ハッシュの値(0), 定数の値(1))

long long x = (long long)rand() % p1;