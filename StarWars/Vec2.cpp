#include "Vec2.h"

Vec2::Vec2(int v) : x(v), y(v) {}

Vec2::Vec2(int x, int y) : x(x), y(y) {}

Vec2::Vec2(const Vec2& o) : x(o.x), y(o.x) {}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
    return { this->x + rhs.x, this->y + rhs.y };
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
    return { this->x - rhs.x, this->y - rhs.y };
}

Vec2 Vec2::operator*(const Vec2& rhs) const
{
    return { this->x * rhs.x, this->y * rhs.y };
}

Vec2 Vec2::operator/(const Vec2& rhs) const
{
    return { this->x / rhs.x, this->y / rhs.y };
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Vec2& Vec2::operator*=(const Vec2& rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;
    return *this;
}

Vec2& Vec2::operator/=(const Vec2& rhs)
{
    this->x /= rhs.x;
    this->y /= rhs.y;
    return *this;
}

bool Vec2::operator==(const Vec2& rhs) const
{
    return this->x == rhs.x && this->y == rhs.y;
}

bool Vec2::operator!=(const Vec2& rhs) const
{
    return this->x != rhs.x || this->y != rhs.y;
}

std::istream& operator>>(std::istream& is, Vec2& self)
{
    return is >> self.x >> self.y;
}

std::ostream& operator<<(std::ostream& os, const Vec2& self)
{
    return os << '[' << self.x << ',' << self.y << ']';
}

int Vec2::dot(const Vec2& rhs) const
{
    return this->x * rhs.x + this->y * rhs.y;
}

int Vec2::cross(const Vec2& rhs) const
{
    return this->x * rhs.y - this->y * rhs.x;
}

int Vec2::norm() const
{
    return hypot(this->x, this->y);
}

void Vec2::normalize()
{
    *this /= norm();
}

int Vec2::area() const
{
    return x * y;
}

Vec2 Vec2::LEFT()
{
    return { -1, 0 };
}

Vec2 Vec2::RIGHT()
{
    return { 1, 0 };
}

Vec2 Vec2::UP()
{
    return { 0, -1 };
}

Vec2 Vec2::DOWN()
{
    return { 0, 1 };
}

void Vec2::setX(const int x)
{
    this->x = x;
}

void Vec2::setY(const int y)
{
    this->y = y;
}

int Vec2::getX()
{
    return this->x;
}

int Vec2::getY()
{
    return this->y;
}
