#pragma once

#include "includes.h"

#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2;

std::istream& operator>>(std::istream&, Vec2&);
std::ostream& operator<<(std::ostream&, const Vec2&);

class Vec2 {
public:
    Vec2() = default;
    Vec2(const Vec2&);
    Vec2(int);
    Vec2(int, int);
    Vec2 operator+(const Vec2&) const;
    Vec2 operator-(const Vec2&) const;
    Vec2 operator*(const Vec2&) const;
    Vec2 operator/(const Vec2&) const;
    Vec2& operator+=(const Vec2&);
    Vec2& operator-=(const Vec2&);
    Vec2& operator*=(const Vec2&);
    Vec2& operator/=(const Vec2&);
    bool operator==(const Vec2&) const;
    bool operator!=(const Vec2&) const;
    friend std::istream& operator>>(std::istream&, Vec2&);
    friend std::ostream& operator<<(std::ostream&, const Vec2&);
    int dot(const Vec2&) const;
    int cross(const Vec2&) const;
    int norm() const;
    void normalize();
    int area() const;
    static Vec2 LEFT();
    static Vec2 RIGHT();
    static Vec2 UP();
    static Vec2 DOWN();
    void setX(const int);
    void setY(const int);
    int getX();
    int getY();

private:
    int x;
    int y;
};

#endif